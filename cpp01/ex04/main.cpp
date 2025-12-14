#include "Replace.hpp"

int main(int ac, char *av[])
{
	if(ac != 4)
	{
		std::cout << "./ex04 <file_name> <string> <new_string>" << std::endl;
		exit(0);
	}
	Replace replace(av[2], av[3]);
	replace.open_file(av[1]);
	replace.replace_strings();
	replace.close_file();
	return(0);
}