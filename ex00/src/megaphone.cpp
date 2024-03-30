 #include <iostream>
 #include <string.h>

int main(int argc, char const *argv[])
{
	std::string s = "";

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	for (int i = 1; i < argc; i++)
	{
		s = argv[i];
		transform(s.begin(), s.end(), s.begin(), ::toupper);
		std::cout << s << std::endl;
	}
	return 0;
}
