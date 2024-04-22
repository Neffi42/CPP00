#include "Sed.hpp"

bool	parsing(int ac, char **av, std::ifstream &in) {
	if (ac != 4)
	{
		std::cerr << "Usage: ./sedisforlosers <filename> <toSearch> <toReplace>" << std::endl;
		return false;
	}
	in.open(av[1]);
	if (!in.good())
	{
		std::cerr << "Error: " << av[1] << " failed to open" << std::endl;
		return false;
	}
	return true;
}

int main(int ac, char **av) {
	std::ifstream in;

	if (!parsing(ac, av, in))
		return 1;
	in.close();

	Sed sed(av[1], av[2], av[3]);

	sed.copyFile();
}
