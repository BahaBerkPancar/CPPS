#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal{

	private:
		Brain *brain;
	public:
		Cat();
		~Cat();
		Cat& operator=(Cat& other);
};


#endif