#pragma once
#include "User.h"
#include "Superhero.h"
#include "Marketplace.h"
#include "MyVector.hpp"

class Player : public User
{
	unsigned long money; 
	MyVector <SuperHero> superHeroes;
	unsigned countOfMoves;

	static long convertStringToNum(const char* str);
	void compareHeroesByPoints(Player& opponent, size_t indexOfOpponentHero, MyVector<SuperHero>& superheroes, size_t indexOfAttackingHero);
public:
	Player(); 
	Player(const char* username, const MyString& firstName, const MyString& secondName, const MyString& email, 
		   const MyString& password);
	User* clone() const override;
	void setMoney(long money);
	long getMoney() const;
	size_t getCountOfSuperHeroes() const;
	size_t getIndexOfHeroByName(const char* superHeroName) const;
	unsigned getCountOfMoves() const;
	void incrementCountOfMoves();
	bool canMakeMove() const;
	const SuperHero& getSuperHeroAtIndex(size_t index) const;
	SuperHero& getSuperHeroAtIndex(size_t index);

	bool haveSuperHero(const char* superHeroName) const;
	MyVector <SuperHero>&  getSuperHeroes();

	void attack(Player& opponent, const char* attackingHeroName, const char* opponentHeroName);
	void changeAttackPossition(const char* superHeroName, const AttackingMode& mode);

	void showBalance() const;

	void addSuperHero(const SuperHero& newHero);
	void removeSuperHero(const char* nickname);

	void printSuperHeroes() const;
	void printShortInfoForSuperHeroes() const;

	void readFromFile(std::ifstream& in) override;
	void writeToFile(std::ofstream& out) const override;
};

