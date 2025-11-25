#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal{
	protected:
		std::string type;

	public:
		Animal();
		Animal(std::string type);
		virtual ~Animal();
		Animal& operator=(const Animal &other);
		virtual void makeSound() const;
		std::string getType() const;
		void setType(std::string type);

};

# endif