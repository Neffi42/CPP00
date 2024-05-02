#include "Dog.hpp"
#include "Cat.hpp"

#define NB_ANIMALS 10

int main() {
	Animal *animals[NB_ANIMALS];

	for (int i = 0; i < NB_ANIMALS; i++) {
		if (i < NB_ANIMALS / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < NB_ANIMALS; i++)
		delete animals[i];

	return 0;
}
