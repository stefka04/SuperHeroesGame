#include "User.h"
#include <exception>
#include <cstring>
#pragma warning(disable: 4996)
bool User::checkIfContains(bool (*pred) (char symbol), const MyString& newPassword)
{
	size_t size = newPassword.length();
	for (size_t i = 0; i < size; ++i)
	{
		if (pred(newPassword[i]))
		{
			return true;
		}
	}
	return false;
}

bool User::isUpper(char symbol)
{
	return symbol >= 'A' && symbol <= 'Z';
}

bool User::isLower(char symbol)
{
	return symbol >= 'a' && symbol <= 'z';
}

bool User::isNumber(char symbol)
{
	return symbol >= '0' && symbol <= '9';
}

User::User(const char* username, const MyString& firstName, const MyString& secondName, const MyString& email,
	       const MyString& password, UserType type)
{
	if (!username)
	{
		throw "Nullptr!";
	}
	this->firstName = firstName;
	this->secondName = secondName;
	setPassword(password);
	this->email = email;
	setUsername(username);
	this->type = type;
}

void User::setPassword(const MyString& newPassword)
{
	if (! (checkIfContains(isUpper, newPassword)  && checkIfContains(isLower, newPassword)
		   && checkIfContains(isNumber, newPassword)))
	{
		throw std::exception("Invalid password!");
    }
	else
	{
		password = newPassword;
	}
}

void User::setUsername(const char* username)
{
	size_t size = strlen(username);
	if (!username || size > MAX_USERNAME_SIZE)
	{
		throw std::exception("Invalid username!");
	}
	for (size_t i = 0; i < size; i++)
	{
		if (!isLower(username[i]))
		{
			throw std::exception("Invalid username!");   
		}
	}
	strcpy(this->username, username);
}


void User::setUserType(UserType type)
{
	this->type = type;
}

const MyString& User::getFirstName() const
{
	return firstName;
}

const MyString& User::getSecondName() const
{
	return secondName;
}

const MyString& User::getEmail() const
{
	return email;
}

const MyString& User::getPassword() const
{
	return password;
}

const char* User::getUsername() const
{
	return username;
}

UserType User::getUserType() const
{
	return type;
}


