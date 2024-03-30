 #include <iostream>
 #include <string.h>

using namespace std;

int main(int argc, char const *argv[])
{
	string s = "";

	if (argc == 1)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
	for (int i = 1; i < argc; i++)
	{
		s = argv[i];
		transform(s.begin(), s.end(), s.begin(), ::toupper);
		cout << s << endl;
	}
	return 0;
}
