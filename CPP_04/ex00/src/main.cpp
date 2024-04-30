#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
	{
		Animal *meta = new Animal();
		Animal *dog = new Dog();
		Animal *cat = new Cat();


		std::cout << dog->getType() << std::endl;
		std::cout << cat->getType() << std::endl;
		dog->makeSound();
		cat->makeSound();
		meta->makeSound();

		delete meta;
		delete dog;
		delete cat;
	}
	{
		WrongAnimal *wcat = new WrongCat();

		std::cout << wcat->getType() << std::endl;
		wcat->makeSound();
		delete wcat;
	}
	return 0;
}
