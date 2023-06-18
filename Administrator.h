#pragma once
#include "User.h"
#include "Player.h"
#include "SuperHero.h"
#include "EnumClasses.h"
class Administrator: public User
{
public:
	Administrator();
	Administrator(const char* username, const MyString& firstName, const MyString& secondName, const MyString& email,
		const MyString& password);

	User* clone() const override;
	void readFromFile(std::ifstream& in) override;
	void writeToFile(std::ofstream& out) const override;

};

