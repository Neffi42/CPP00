 #include <iostream>
 #include <string>

int main(int argc, char const *argv[])
{
	std::string s;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; i++)
	{
		s = argv[i];
		for (size_t j = 0; j < s.size(); j++)
			s[j] = toupper(s[j]);
		std::cout << s;
	}
	std::cout << std::endl;
	return 0;
}
