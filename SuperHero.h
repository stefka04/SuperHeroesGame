#pragma once
#include "EnumClasses.h"
#include "MyStringSSO.h"
#include "Constants.h"
#include <fstream>
class SuperHero
{
private:
	char supername[MAX_USERNAME_SIZE + 1];
	AttackingMode mode;
	StrengthTypes strengthType;
	unsigned strengthPoints;
	long price;
	MyString firstName;  
	MyString secondName;
	
	static long convertStringToNum(const char* str);
public:
	SuperHero();
	SuperHero(const MyString& firstName, const MyString& secondName, const char* supername,  
		      long price, StrengthTypes strengthType, unsigned strengthPoints);

	void setAttackingMode(const AttackingMode& mode);
	void setStrengthPoints(unsigned points);

	const char* getSupername() const;
	const AttackingMode& getAttackingMode() const;
	const StrengthTypes& getStrengthType() const;
	unsigned getStrengthPoints() const;
	long getPrice() const;
	const MyString& getFirstName() const;
	const MyString& getSecondName() const;

	void readFromFile(std::ifstream& in);
	void writeToFile(std::ofstream& out) const;

	void printSuperHero() const;
	void printShortInfo() const;
};

