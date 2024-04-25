#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap {
private:
	std::string name;
	unsigned int hp;
	unsigned int energy;
	unsigned int damage;
	bool checkHp() const;
	bool checkEnergy() const;
public:
	ClapTrap(const std::string &name);
	~ClapTrap();
	ClapTrap(const ClapTrap &other);
	ClapTrap &operator=(const ClapTrap &other);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void status() const;
};

#endif
