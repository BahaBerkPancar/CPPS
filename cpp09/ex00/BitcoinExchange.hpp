#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

class BitcoinExchange {
private:
	std::map<std::string, double> exchangeRates;

	void loadExchangeRates(const std::string& filename);
	bool isLeapYear(int year) const;
	double getExchangeRate(const std::string& date) const;
public:
	BitcoinExchange(const std::string& filename);
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	void processInputFile(const std::string& filename) const;
	bool Valid_date_checks(const std::string& date) const;
	~BitcoinExchange();

};

#endif
