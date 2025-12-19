#include "Replace.hpp"

Replace::Replace(std::string first_string, std::string replace)
{
	this->first_string = first_string;
	this->replace_string = replace;
}

Replace::~Replace()
{}

void Replace::open_file(std::string file_name)
{
	input.open(file_name);
	if(!input.is_open())
    {
		std::cout << "Can't open " << file_name << std::endl;
        exit(0);
    }
	output.open(file_name + ".replace");
	if(!output.is_open())
    {
		std::cout << "Can't open " << file_name + ".replace" << std::endl;
        input.close();
        exit(0);
    }
}

void Replace::replace_strings()
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
void Replace::close_file()
{
	input.close();
	output.close();
}
