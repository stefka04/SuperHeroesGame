#pragma once
#include "SuperHeroe.h"
#include "MyVector.hpp"
class Marketplace
{
	MyVector<SuperHeroe> allSuperHeroes;

	size_t getIndexOfHeroeByName(const char* superHeroeName) const;
public:
	Marketplace() = default;
	
	void addSuperHeroe(const SuperHeroe& newHeroe);
	void removeSuperHeroe(const char* nickname);

	void print() const;
	void writeToFile(std::ofstream& out) const;
	void readFromFile(std::ifstream& in);
};

