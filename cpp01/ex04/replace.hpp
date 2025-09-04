#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <string>
#include <iostream>
#include <fstream>

class replace {
	private:
		std::string first_string;
		std::ifstream input;
		std::ofstream output;
	public:
		std::string buffer;
		std::string replace_string;
		replace(std::string first_string, std::string replace);
		~replace();
		void open_file(std::string file_name);
		void replace_strings();
		void close_file();
};


#endif
