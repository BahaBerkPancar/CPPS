#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
	if (argc != 2)
		return (std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl, 1);

	try {
		BitcoinExchange btcExchange("data.csv");
		btcExchange.processInputFile(argv[1]);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}
