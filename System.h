#ifndef __System_H
#define __System_H

const int SET_SIZE = 10;

#include <iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;

#pragma warning(disable: 4996)

class User;
class Seller;
class Buyer;
class Adress;
class Feedback;
class Buyer_Seller;

class System
{
public:
	System(const string & name, ifstream& in);
	virtual~System();

private:
	System(const System& other); // no copy c'tor
	System();

public:

	void setName(const string & name);

	const string & getName()  const;
	int getCurrentAmountOfSellers() const;
	int getCurrentAmountOfBuyers() const;
	int getCurrentAmountOfUsers() const;

	// add new buyer\ seller\ feedback user to array is the  system
	void addBuyer(const string & name, const string & password, Adress & adress);
	void addSeller(const string & name, const string & password, Adress & adress);
	void addBuyer_Seller(const string & name, const string & password, Adress & adress);
	virtual void addFeedback(Buyer* buyer, Feedback * feedback, int index);


	User* findUser(const string & name, const string & password, int flag);
	bool checkValidUserName(const string & name, int flag);

	// printing all sellers\ buyers to the screen
	void showAllSellers() const; 
	void showAllBuyers() const;
	void showAllSellers_Buyers() const;

	// printing all product with specific name to the screen
	bool showAllProductNamed_X(const string & productName, int usersAmount) const;

	int FromStringToInt(string & string);

public:
	void operator+=(Buyer* buyer);
	void operator+=(Seller* seller);

public:
	friend void menu_Add_Product_To_Cart(System & theSystem);
	friend void menu_Add_Feedback(System & theSystem);
	friend void menu_Display_All_Products_Named_X(System & theSystem);
	friend void menu_Save_and_Exit(System & theSystem);
private:

	string m_name;

	vector<User*> m_userArr; // list of all buyers and sellers and both
	
	int m_currentAmountOfUsers;
	int m_currentAmountOfSellers;
	int m_currentAmountOfBuyers;
};
#endif // !__System_H
