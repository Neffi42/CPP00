#include "Sed.hpp"

Sed::Sed(std::string name, std::string find, std::string replace) {
	this->_name = name;
	this->_find = find;
	this->_replace = replace;
	this->_in.open(name);
	this->_out.open(name + ".replace", std::ofstream::out | std::ofstream::trunc);
}

Sed::~Sed() {
	this->_in.close();
	this->_out.close();
}

void Sed::copyFile() {
	std::string	line;

	while (!this->_in.eof())
	{
		getline(this->_in, line);
		if (this->_find != this->_replace)
			this->replaceAll(line);
		this->_out << line << std::endl;
	}
}

void Sed::replaceAll(std::string &line) {
	std::size_t needle = line.find(this->_find);

	while (needle != std::string::npos)
	{
		line.erase(needle, this->_find.length());
		line.insert(needle, this->_replace);
		needle = line.find(this->_find, needle + this->_replace.length());
	}
}