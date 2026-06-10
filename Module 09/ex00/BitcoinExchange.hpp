#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange
{
public:
    BitcoinExchange();
    ~BitcoinExchange();

    bool loadDatabase(const std::string &path);
    void processInput(const std::string &path) const;

private:
    std::map<std::string, double> _db;

    bool isValidDate(const std::string &date) const;
    bool parseLine(const std::string &line, std::string &date, std::string &value) const;
    double getRateForDate(const std::string &date) const;
};

#endif // BITCOINEXCHANGE_HPP
