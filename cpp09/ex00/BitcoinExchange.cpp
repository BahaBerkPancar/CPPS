#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& filename) {
	loadExchangeRates(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	exchangeRates = other.exchangeRates;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) 
		exchangeRates = other.exchangeRates;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

void BitcoinExchange::loadExchangeRates(const std::string& filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Not able open exchange rates file: " + filename);
	std::string tmp;
	std::getline(file, tmp);
	while (std::getline(file, tmp)) {
		std::istringstream ss(tmp);
		std::string date;
		std::string rateStr;
		if (std::getline(ss, date, ',') && std::getline(ss, rateStr)) {
			double rate = std::atof(rateStr.c_str());
			exchangeRates[date] = rate;
		}
	}
	file.close();
}

bool BitcoinExchange::isLeapYear(int year) const {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool BitcoinExchange::Valid_date_checks(const std::string& date) const{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12 || day < 1 || year <= 0 || year > 9999 || day > 31)
		return false;
	int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && isLeapYear(year))
		daysInMonth[1] = 29;
	if (day > daysInMonth[month - 1])
		return false;
	return true;
}

double BitcoinExchange::getExchangeRate(const std::string& date) const {
	std::map<std::string, double>::const_iterator it = exchangeRates.find(date);
	if (it != exchangeRates.end())
		return it->second;
	it = exchangeRates.lower_bound(date);
	if (it == exchangeRates.begin())
		throw std::runtime_error("No exchange rate available for date: " + date);
	--it;
	return it->second;
}

void errorMessage(const std::string& msg) {
	std::cerr << "Error: " << msg << std::endl;
}

void BitcoinExchange::processInputFile(const std::string& filename) const
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Not able open input file: " + filename);
	std::string tmp;
	std::getline(file, tmp);
	while (std::getline(file, tmp)) {
		if(tmp.empty())
			continue;
		if(tmp == "date | value")
			continue;
		if(tmp.find('|') == std::string::npos) {
			errorMessage("bad input => " + tmp);
			continue;
		}
		std::istringstream ss(tmp);
		std::string date;
		std::string valueStr;
		if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
			date = date.substr(0, date.find_last_not_of(" ") + 1);
			valueStr = valueStr.substr(valueStr.find_first_not_of(" "), valueStr.find_last_not_of(" ") - valueStr.find_first_not_of(" ") + 1);
			if (!Valid_date_checks(date)) {
				errorMessage("invalid date => " + date);
				continue;
			}
			if(valueStr.empty() || (valueStr.find_first_not_of(" 0123456789.-") != std::string::npos)) {
				errorMessage("invalid value => " + valueStr);
				continue;
			}
			if (valueStr.find('-') != std::string::npos && valueStr.find('-') != 0) {
				errorMessage("invalid value => " + valueStr);
				continue;
			}
			double value = std::atof(valueStr.c_str());
			if (value < 0) {
				errorMessage("not a positive number.");
				continue;
			}
			if (value >= 1000) {
				errorMessage("too large a number.");
				continue;
			}
			try {
				double rate = getExchangeRate(date);
				double result = rate * value;
				std::cout << date << " => " << value << " = " << result << std::endl;
			} catch (const std::exception& e) {
				errorMessage(e.what());
			}
		}
	}
	file.close();
}
