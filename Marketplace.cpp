#include "Marketplace.h"

size_t Marketplace:: getIndexOfHeroeByName(const char* superHeroeName) const
{
	size_t countOfSuperHeroes = allSuperHeroes.getSize();
	for (size_t i = 0; i < countOfSuperHeroes; i++)
	{
		if (strcmp(allSuperHeroes[i].getSupername(), superHeroeName) == 0)
		{
			return i;
		}
	}
	throw std::invalid_argument("Not excisting superHeroe!");
}

void Marketplace::addSuperHeroe(const SuperHeroe& newHeroe)
{
	allSuperHeroes.pushBack(newHeroe);
}

void Marketplace::removeSuperHeroe(const char* nickname)
{
	size_t index = getIndexOfHeroeByName(nickname);
	allSuperHeroes.popAt(index);
}

void Marketplace::print() const
{
	size_t countOfSuperHeroes = allSuperHeroes.getSize();
	for (size_t i = 0; i < countOfSuperHeroes; i++)
	{
		std::cout << i + 1 << ". ";
		allSuperHeroes[i].printSuperHeroe();
	}
}

void Marketplace::writeToFile(std::ofstream& out) const
{
	size_t size = allSuperHeroes.getSize();
	out << size << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		allSuperHeroes[i].writeToFile(out);
	}
}

void Marketplace::readFromFile(std::ifstream& in)
{
	size_t size = 0;
	in >> size;
	for (size_t i = 0; i < size; i++)
	{
		SuperHeroe newHeroe;
		newHeroe.readFromFile(in);
		allSuperHeroes.pushBack(newHeroe);
	}
}