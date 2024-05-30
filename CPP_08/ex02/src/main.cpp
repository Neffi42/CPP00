#include "MutantStack.hpp"
#include <iostream>

int main() {
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
