#include "Administrator.h"
#include <sstream>
Administrator::Administrator()
{
	type = UserType::Administrator;
}
Administrator::Administrator(const char* username, const MyString& firstName, const MyString& secondName, const MyString& email, 
	const MyString& password) : User(username, firstName, secondName, email, password, UserType::Administrator) 
{
}

User* Administrator::clone() const
{
    User* newObj = new Administrator(*this);
	return newObj;
}

void Administrator::readFromFile(std::ifstream& in) 
{
	char buff[MAX_BUFF_SIZE];
	in.getline(buff, MAX_BUFF_SIZE);
	std::stringstream str(buff);

	str.getline(username, MAX_USERNAME_SIZE, ',');
	str.getline(buff, MAX_BUFF_SIZE, ',');
	firstName = MyString(buff);
	str.getline(buff, MAX_BUFF_SIZE, ',');
	secondName = MyString(buff);
	str.getline(buff, MAX_BUFF_SIZE, ',');
	email = MyString(buff);
	str.getline(buff, MAX_BUFF_SIZE, ',');
	password = MyString(buff);
	str.getline(buff, MAX_BUFF_SIZE, ',');

}

void Administrator::writeToFile(std::ofstream& out) const
{
	out << "Administrator" << std::endl;

	out << username << ",";
	out << firstName << ",";
	out << secondName << ",";
	out << email << ",";
	out << password;
}

