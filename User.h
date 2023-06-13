#pragma once
#include "MyStringSSO.h"
#include <fstream> 
#include "Constants.h"
#include "EnumClasses.h"
class User 
{
protected:
	char username[MAX_USERNAME_SIZE + 1];
	MyString firstName;  
	MyString secondName;
	MyString email;
	MyString password;
	UserType type; 
	bool isLoggedIn = false;
public:
	static bool checkIfContains(bool (*pred) (char symbol), const MyString& newPassword);
	static bool isUpper(char symbol);
	static bool isLower(char symbol);
	static bool isNumber(char symbol);

	User(const char* username, const MyString& firstName, const MyString& secondName, 
		 const MyString& email, const MyString& password, UserType type);
	void setPassword(const MyString& newPassword);       
	void setUsername(const char* username);

	void setLoggInStatus(bool isLggedIn);

	const MyString& getFirstName() const;
	const MyString& getSecondName() const;
	const MyString& getEmail() const;
	const MyString& getPassword() const;     
	const char* getUsername() const;
	const UserType& getUserType() const;
	bool getIsLoggedIn() const;

	virtual User* clone() const = 0;
    virtual void readFromFile(std::ifstream& in) = 0;
    virtual void writeToFile(std::ofstream& out) const = 0; 

	virtual ~User() = default;
};

