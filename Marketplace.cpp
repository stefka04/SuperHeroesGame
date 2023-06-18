#include "Marketplace.h"

size_t Marketplace:: getIndexOfHeroByName(const char* superHeroName) const
{
	size_t countOfSuperHeroes = allSuperHeroes.getSize();
	for (size_t i = 0; i < countOfSuperHeroes; i++)
	{
		if (strcmp(allSuperHeroes[i].getSupername(), superHeroName) == 0)
		{
			return i;
		}
	}
	throw std::invalid_argument("Not excisting superHeroe!");
}

const MyVector<SuperHero>& Marketplace::getAllHeroes()
{
	return allSuperHeroes;
}

const size_t Marketplace::getCountOfHeroes() const
{
	return allSuperHeroes.getSize();
}

const SuperHero& Marketplace:: getSuperHeroAtIndex(size_t index) const
{
	if (index > getCountOfHeroes())
	{
		throw std::invalid_argument("Error! Not valid index!");
	}
	return allSuperHeroes[index];
}
void Marketplace::addSuperHero(const SuperHero& newHeroe)
{
	allSuperHeroes.pushBack(newHeroe);
}

void Marketplace::removeSuperHero(const char* nickname)
{
	size_t index = getIndexOfHeroByName(nickname);
	allSuperHeroes.popAt(index);
}

void Marketplace::print() const
{
	size_t countOfSuperHeroes = allSuperHeroes.getSize();
	for (size_t i = 0; i < countOfSuperHeroes; i++)
	{
		std::cout << i + 1 << ". ";
		allSuperHeroes[i].printSuperHero();
	}
}

void Marketplace::writeToFile(std::ofstream& out) const
{
	size_t size = allSuperHeroes.getSize();
	out << size << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		allSuperHeroes[i].writeToFile(out);
		if (i + 1 != size)
		{
			out << std::endl;
		}
	}
}

void Marketplace::readFromFile(std::ifstream& in)
{
	size_t size = 0;
	in >> size;
	in.ignore();
	for (size_t i = 0; i < size; i++)
	{
		SuperHero newHeroe;
		newHeroe.readFromFile(in);
		allSuperHeroes.pushBack(newHeroe);
	}
}