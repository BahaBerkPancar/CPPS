#include "phonebook.hpp"

void print_table(void)
{
	std::cout  << "[3J[H[2J";
	std::cout << "=============================================" << std::endl;
	std::cout << "   WELCOME TO YOUR PHONEBOOK" << std::endl;
	std::cout << "=============================================" << std::endl;
	std::cout << "Commands:" << std::endl;
	std::cout << "  * ADD    -> Add a new contact" << std::endl;
	std::cout << "  * SEARCH -> View your contacts" << std::endl;
	std::cout << "  * EXIT   -> Exit phonebook" << std::endl;
	std::cout << "=============================================" << std::endl;
}

void get_contact_info(std::string *contact)
{
	std::cout << "\n---  ADD NEW CONTACT  ---" << std::endl;
	std::cout << "First Name   : "; std::cin >> contact[0];
	std::cout << "Last Name    : "; std::cin >> contact[1];
	std::cout << "Nickname     : "; std::cin >> contact[2];
	std::cout << "Phone Number : "; std::cin >> contact[3];
	std::cout << "Dark Secret  : "; std::cin >> contact[4];
}
void	print_search(phonebook *book, int total_contact)
{
	int 	j = 0;
	std::cout << "\n==============  CONTACT LIST  ===============" << std::endl;
	std::cout << "| Index |"
			  << std::setw(10) << "First Name" << " |"
			  << std::setw(10) << "Last Name"  << " |"
			  << std::setw(10) << "Nickname"   << " |"
			  << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	for(int i = 0; i < total_contact; i++){
		std::cout << "|   " << i << "   |";
		book[i].SEARCH_CONTACT();
	}
	std::cout << "=============================================" << std::endl;
	std::cout << "Write Index For Information" << std::endl;
	std::cin >> j;
	if(j < 8)
		book[j].DISPLAY_CONTACT();
	else
	{
		std::cout << "Index must be in range of 0 to 7" <<  std::endl;
		print_table();
	}
}

int main(){
	phonebook book[8];
	std::string input, contact[5];
	int total_contact = 0, count = 0;

	print_table();
	while(1)
	{
		if (!(std::cin >> input)) { 
			std::cout << "\n Exiting..." << std::endl;
			break;
		}
		if(input == "ADD"){
			if(count == 8)
				count = 0;
			get_contact_info(contact);
			book[count].ADD_CONTACT(contact[0], contact[1], contact[2], contact[3], contact[4]);
			count++;
			print_table();
			std::cout << "[" << contact[0] << "] Has been saved into your contacts." << std::endl;
		}
		else if(input == "SEARCH"){
			if (total_contact == 0) {
				std::cout << "\n📭 No contacts saved yet!" << std::endl;
			} else
				print_search(book, total_contact);
		}
		else if(input == "EXIT")
		{
			std::cout << "\n Exiting..." << std::endl;
			exit(0);
		}
		else
		{
			print_table();
			std::cout << "WRONG INPUT" << std::endl;
		}
		if(total_contact != 8)
			total_contact = count;
	}
	return(0);
}
