#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::loadDatabase(const std::string &path)
{
    std::ifstream file(path.c_str());
    if (!file.is_open())
        return false;

    std::string line;
    // Expect header first line, skip if present
    if (!std::getline(file, line))
        return false;

    if (line.find("date") == std::string::npos)
        ; // first line may already be data

    if (line.find(',') != std::string::npos && line.find("date") != std::string::npos)
        ; // header, continue reading rest
    else
    {
        // if header not present, process this line as data
        std::istringstream ss(line);
        std::string date;
        std::string rate;
        if (std::getline(ss, date, ',') && std::getline(ss, rate))
        {
            double r = atof(rate.c_str());
            _db[date] = r;
        }
    }

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        std::istringstream ss(line);
        std::string date;
        std::string rate;
        if (!std::getline(ss, date, ','))
            continue;
        if (!std::getline(ss, rate))
            continue;
        double r = atof(rate.c_str());
        _db[date] = r;
    }

    return !_db.empty();
}


bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.size(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }
    int year = std::atoi(date.substr(0,4).c_str());
    int month = std::atoi(date.substr(5,2).c_str());
    int day = std::atoi(date.substr(8,2).c_str());
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    (void)year;
    return true;
}

bool BitcoinExchange::parseLine(const std::string &line, std::string &date, std::string &value) const
{
    std::size_t sep = line.find('|');
    if (sep == std::string::npos)
        return false;
    date = line.substr(0, sep);
    value = line.substr(sep + 1);
    // trim
    while (!date.empty() && std::isspace(date[0])) date.erase(date.begin());
    while (!date.empty() && std::isspace(date[date.size()-1])) date.erase(date.size()-1,1);
    while (!value.empty() && std::isspace(value[0])) value.erase(value.begin());
    while (!value.empty() && std::isspace(value[value.size()-1])) value.erase(value.size()-1,1);
    return true;
}

double BitcoinExchange::getRateForDate(const std::string &date) const
{
    std::map<std::string,double>::const_iterator it = _db.lower_bound(date);
    if (it == _db.end())
    {
        if (_db.empty())
            return 0.0;
        // return last element
        return _db.rbegin()->second;
    }
    if (it->first == date)
        return it->second;
    // if lower_bound gives first >= date, we need previous (lower)
    if (it == _db.begin())
        return it->second;
    --it;
    return it->second;
}


void BitcoinExchange::processInput(const std::string &path) const
{
    std::ifstream file(path.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    if (!std::getline(file, line))
        return;
    // skip header if matches
    if (line.find("date") != std::string::npos && line.find("value") != std::string::npos)
    {
        // header skipped
    }
    else
    {
        // process first line as data
        std::string date, value;
        if (parseLine(line, date, value))
        {
            if (!isValidDate(date))
            {
                std::cout << "Error: bad input => " << date << std::endl;
            }
            else
            {
                double val = atof(value.c_str());
                if (value.empty() || (value.size() == 1 && value[0] == '\0'))
                    std::cout << "Error: bad input => " << date << std::endl;
                else if (val < 0)
                    std::cout << "Error: not a positive number." << std::endl;
                else if (val > 1000)
                    std::cout << "Error: too large a number." << std::endl;
                else
                {
                    double rate = getRateForDate(date);
                    std::cout << date << " => " << value << " = " << (val * rate) << std::endl;
                }
            }
        }
        else
        {
            std::cout << "Error: bad input => " << line << std::endl;
        }
    }

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        std::string date, value;
        if (!parseLine(line, date, value))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!isValidDate(date))
        {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        // parse value
        bool badnum = false;
        for (size_t i = 0; i < value.size(); ++i)
        {
            if (!(std::isdigit(value[i]) || value[i] == '.' || value[i] == '+' || value[i] == '-'))
            {
                badnum = true; break;
            }
        }
        if (badnum || value.empty())
        {
            std::cout << "Error: bad input => " << value << std::endl;
            continue;
        }
        double val = atof(value.c_str());
        if (val < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        if (val > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        double rate = getRateForDate(date);
        std::cout << date << " => " << value << " = " << (val * rate) << std::endl;
    }
}
