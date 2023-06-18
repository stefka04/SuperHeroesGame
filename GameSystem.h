#pragma once
#include "User.h"
#include "Administrator.h"
#include "Player.h"
#include "Marketplace.h"
class GameSystem      
{
	User** users;
	size_t countOfUsers = 0;
	size_t capacity;
	Marketplace* market;  
	MyVector<unsigned> loggedIndexes;
	size_t indexOfCurrentUser = 0;
	static GameSystem* instance;

	GameSystem();

	void freeUsers();
	void resizeUsers();
	void readUsersFromFile(std::ifstream& in);
	void readLeaderBoardFile(MyVector<MyString>& usernames, MyVector<long>& moneyArr) const;
	void saveToFile(std::ofstream& out);
	void addUser(User* newUser);

	bool checkIfUserLoggedBefore(size_t index) const;
	template <typename T>
	static void swap(T& item1, T& item2);
	static void sortByMoney(MyVector<MyString>& usernames, MyVector<long>& moneyArr);
public:
	GameSystem(const GameSystem& other) = delete;
	GameSystem& operator= (const GameSystem& other) = delete;
	
	void periodEnd();
	void setIndexOfCurrentUser(const char* username, const MyString& password);

	size_t getIndexOfCurrentUser() const;
	size_t getIndexOfUserByUsername(const char* username) const;
	const User& getUserAtIndex(int index) const;
	size_t getCountOfPlayersLogged() const;
	bool checkIsUsernameTaken(const char* username) const;
	bool checkIsSuperHeroTaken(const char* supername) const;

	void addPlayer(const char* username, const MyString& firstName, const MyString& secondName,        
		           const MyString& email, const MyString& password);
	void addAdministrator(const char* username, const MyString& firstName, const MyString& secondName,
		const MyString& email, const MyString& password);

	void deleteUser(const char* username);

	void showPlayers() const;
	void showAdministrators() const;
	void showLeaderBoard() const;
	void showMarket() const;

	void showBalance() const;

	void buySuperHero(const char* supername);

	void addSuperHeroToTheMarket(const SuperHero& newHeroe);
	void addAlreadyBoughtHeroToTheMarket(const char* supername);

	void attack(const char* username, const char* attackingHeroName, const char* opponentHeroName);
	void attack(const char* attackingHeroName);
	void changeAttackingMode(const char* superHeroName, AttackingMode mode);

	void logOut();

	static GameSystem* getInstance();
	static void freeInstance();
	~GameSystem();
};

