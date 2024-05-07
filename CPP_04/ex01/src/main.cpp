#include "Dog.hpp"
#include "Cat.hpp"

#define NB_ANIMALS 10

int main() {
	{
		Animal *animals[NB_ANIMALS];

		for (int i = 0; i < NB_ANIMALS; i++) {
			if (i < NB_ANIMALS / 2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}

		std::cout << std::endl;

		for (int i = 0; i < NB_ANIMALS; i++) {
			delete animals[i];
		}

		std::cout << std::endl;
	}
	{
		Dog *a = new Dog();
		Dog *b = new Dog();

		for (int i = 0; i < 5; i++) {
			a->setIdea("Lol", i);
		}
		for (int i = 0; i < 5; i++) {
			std::cout << a->getIdea(i) << std::endl;
		}

		*b = *a;
		delete a;

		for (int i = 0; i < 5; i++) {
			std::cout << b->getIdea(i) << std::endl;
		}

		delete b;
	}
	return 0;
}
