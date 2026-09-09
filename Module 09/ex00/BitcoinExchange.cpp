#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cctype>
#include <cstdlib>

static void trim(std::string &text)
{
    while (!text.empty() && std::isspace(static_cast<unsigned char>(text[0])))
        text.erase(0, 1);
    while (!text.empty() && std::isspace(static_cast<unsigned char>(text[text.size() - 1])))
        text.erase(text.size() - 1, 1);
}

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
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        std::istringstream ss(line);
        std::string date;
        std::string rate;
        if (!std::getline(ss, date, ',') || !std::getline(ss, rate))
            continue;
        trim(date);
        trim(rate);
        double parsedRate;
        if (!isValidDate(date) || !parseValue(rate, parsedRate))
            continue;
        _db[date] = parsedRate;
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
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }
    int year = std::atoi(date.substr(0,4).c_str());
    int month = std::atoi(date.substr(5,2).c_str());
    int day = std::atoi(date.substr(8,2).c_str());
    if (month < 1 || month > 12)
        return false;
    if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    if (leap)
        daysInMonth[1] = 29;
    if (day > daysInMonth[month - 1])
        return false;
    return true;
}

bool BitcoinExchange::parseLine(const std::string &line, std::string &date, std::string &value) const
{
    std::size_t sep = line.find('|');
    if (sep == std::string::npos)
        return false;
    date = line.substr(0, sep);
    value = line.substr(sep + 1);
    trim(date);
    trim(value);
    return true;
}

bool BitcoinExchange::parseValue(const std::string &text, double &value) const
{
    if (text.empty())
        return false;
    std::istringstream stream(text);
    char extra;
    if (!(stream >> value) || (stream >> extra))
        return false;
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
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;
        if (line == "date | value")
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
        double val;
        if (!parseValue(value, val))
        {
            std::cout << "Error: bad input => " << value << std::endl;
            continue;
        }
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
