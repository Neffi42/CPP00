#include "Sed.hpp"

Sed::Sed(const std::string &name, const std::string &find, const std::string &replace) {
	this->find = find;
	this->replace = replace;
	this->in.open(name);
	this->out.open(std::strcat((char *)name.c_str(), ".replace"), std::ofstream::out | std::ofstream::trunc);
}

Sed::~Sed() {
	this->in.close();
	this->out.close();
}

void Sed::copyFile() {
	std::string	line;

	while (!this->in.eof())
	{
		getline(this->in, line);
		if (this->find != this->replace)
			this->replaceAll(line);
		this->out << line << std::endl;
	}
}

void Sed::replaceAll(std::string &line) {
	std::size_t needle = line.find(this->find);

	while (needle != std::string::npos)
	{
		line.erase(needle, this->find.length());
		line.insert(needle, this->replace);
		needle = line.find(this->find, needle + this->replace.length());
	}
}
