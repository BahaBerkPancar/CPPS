#include "replace.hpp"

replace::replace(std::string first_string, std::string replace)
{
	this->first_string = first_string;
	this->replace_string = replace;
}

replace::~replace()
{}

void replace::open_file(std::string file_name)
{
	input.open(file_name);
	if(!input.is_open())
		std::cout << "i cant open " << file_name << std::endl;
	output.open(file_name + ".replace");
	if(!output.is_open())
		std::cout << "i cant open " << file_name + ".replace" << std::endl;
}

void replace::replace_strings()
{
    std::string buffer;

    while (std::getline(input, buffer))
    {
        std::string result;
        size_t pos = 0;
        size_t found;

        while ((found = buffer.find(first_string, pos)) != std::string::npos)
        {
            result += buffer.substr(pos, found - pos);
            result += replace_string;
            pos = found + first_string.length();
        }
        result += buffer.substr(pos);
        output << result << '\n';
    }
}
void replace::close_file()
{
	input.close();
	output.close();
}
