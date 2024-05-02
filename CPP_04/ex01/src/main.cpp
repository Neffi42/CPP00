#include "Dog.hpp"
#include "Cat.hpp"

#define N_ANIMALS 10

int main() {
	{
		const Animal *lotsOfAnimals[N_ANIMALS];

		for (int i = 0; i < N_ANIMALS; i++) {
			if (i < N_ANIMALS / 2)
				lotsOfAnimals[i] = new Dog();
			else
				lotsOfAnimals[i] = new Cat();
		}
		std::cout << lotsOfAnimals[0]->getType() << std::endl;
		std::cout << lotsOfAnimals[5]->getType() << std::endl;
		for (int i = 0; i < N_ANIMALS; i++)
			delete lotsOfAnimals[i];
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Dog class using copy constructor:\n" << std::endl;
		Dog *dogA = new Dog;
		Dog *dogB = new Dog(*dogA);

		delete dogA;
		delete dogB;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Dog class using assignment operator overload:\n" << std::endl;
		Dog *dogA = new Dog;
		Dog *dogB = new Dog;

		*dogA = *dogB;
		delete dogA;
		delete dogB;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Cat class using copy constructor:\n" << std::endl;
		Cat *catA = new Cat;
		Cat *catB = new Cat(*catA);

		delete catA;
		delete catB;
	}
	std::cout << "-------------------------------------\n";
	{
		std::cout << "Check deep copy of Cat class using assignment operator overload:\n" << std::endl;
		Cat *catA = new Cat;
		Cat *catB = new Cat;

		*catA = *catB;
		delete catA;
		delete catB;
	}
	return (0);
}
