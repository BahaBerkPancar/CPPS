#include <iostream>

int main(int ac, char **av)
{
	int i;
	if(ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else if (*av){
		for (int j = 1; j < ac; j++){
			for (i = 0; av[j][i] != '\0'; i++){
				if (av[j][i] >= 'a' && av[j][i] <= 'z')
					std::cout << (char)(av[j][i] - 32);
				else
					std::cout << (char)av[j][i];
			}
		}
		std::cout << std::endl;
	}
}