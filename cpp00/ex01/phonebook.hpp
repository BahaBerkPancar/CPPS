#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>   // for setw
# include <string>

class phonebook
{
    private:
        std::string name;
        std::string surname;
        std::string nickname;
        std::string number;
        std::string secret;

        std::string formatField(std::string str) const {
            if (str.length() > 10)
                return str.substr(0, 9) + ".";
            else
                return str;
        }

    public:
        void DISPLAY_CONTACT() const;
        void ADD_CONTACT(std::string name, std::string surname, std::string nickname, std::string number, std::string secret);
        void SEARCH_CONTACT() const;
};

inline void phonebook::ADD_CONTACT(std::string name, std::string surname, std::string nickname, std::string number, std::string secret)
{
    this->name = name;
    this->surname = surname;
    this->nickname = nickname;
    this->number = number;
    this->secret = secret;
}

inline void phonebook::SEARCH_CONTACT() const
{
    std::cout 
        << std::setw(10) << formatField(name)    << " |"
        << std::setw(10) << formatField(surname) << " |"
        << std::setw(10) << formatField(nickname)<< " |"
        << std::endl;
}

inline void phonebook::DISPLAY_CONTACT() const
{
    std::cout << "\n--- CONTACT DETAILS ---\n";
    std::cout << "First Name   : " << name << std::endl;
    std::cout << "Last Name    : " << surname << std::endl;
    std::cout << "Nickname     : " << nickname << std::endl;
    std::cout << "Phone Number : " << number << std::endl;
    std::cout << "Dark Secret  : " << secret << std::endl;
}

#endif
