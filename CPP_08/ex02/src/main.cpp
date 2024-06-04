#include "MutantStack.hpp"
#include <deque>
#include <iostream>
#include <vector>

int main() {
	std::deque<int> myDeque(3,100);
	std::vector<int> myVector(2,200);

	MutantStack<int> first;
	MutantStack<int> second(myDeque);

	MutantStack<int, std::vector<int> > third;
	MutantStack<int, std::vector<int> > fourth(myVector);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';

	MutantStack<int> stack;
	stack.push(0);
	stack.push(1);
	stack.push(2);
	stack.push(3);
	stack.push(4);
	stack.push(5);

	std::cout << "size " << stack.size() << std::endl;
	stack.pop();
	std::cout << "size " << stack.size() << std::endl;

	MutantStack<int>::iterator it = stack.begin();
	while (it != stack.end()) {
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << std::endl;

	it = stack.end();
	do
	{
		it--;
		std::cout << *it << std::endl;
	} while (it != stack.begin());

	MutantStack<int> copy(stack);
	std::cout << "copy size " << copy.size() << std::endl;
	stack.push(5);
	std::cout << "copy size " << copy.size() << std::endl;
	std::cout << "size " << stack.size() << std::endl;

	return 0;
}
