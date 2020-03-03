#ifndef __User_H
#define __User_H

#include"System.h"
#include"Adress.h"


class Adress;

enum eUserType { BUYER, SELLER, SELLER_BUYER };
static const string eUserTypeSTR[] = { "Buyer", "Seller" , "Seller_Buyer" };

class User
{
protected:
	User(const string & name, const string & password, const Adress & adress);
	

private:
	User();
	User(const User& user);

public:
	virtual ~User();
	void setName(const string & name);
	void setPassword(const string & password);
	bool setAdress(const Adress & adress);


	const string &   getName() const;
	const string &   getPassword() const;
	const Adress& getAdress() const;
	eUserType getUserType() const;

	virtual void show() const = 0;

	friend class System;
	friend void menu_Add_User(System& theSystem, int flag);
	
protected:
	string m_name;
	string m_password;
	Adress m_adress;
	eUserType m_type;
};

#endif // !__User_H
