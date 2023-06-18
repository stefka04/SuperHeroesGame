#pragma once
#include "SuperHero.h"
#include "MyVector.hpp"
class Marketplace
{
	MyVector<SuperHero> allSuperHeroes;

public:
	Marketplace() = default;
	const MyVector<SuperHero>& getAllHeroes();
	const size_t getCountOfHeroes() const;
	const SuperHero& getSuperHeroAtIndex(size_t index) const;
	size_t getIndexOfHeroByName(const char* superHeroName) const;
	void addSuperHero(const SuperHero& newHero);
	void removeSuperHero(const char* nickname);

	void print() const;
	void writeToFile(std::ofstream& out) const;
	void readFromFile(std::ifstream& in);
};

