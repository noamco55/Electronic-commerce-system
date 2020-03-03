#include "User.h"



//-------------------------------------------------------------------//
User::User(const string & name, const string & password,const Adress & adress):m_adress(adress)
{
	setName(name);
	setPassword(password);
}
//-------------------------------------------------------------------//
User::~User()
{
}
//-------------------------------------------------------------------//
void User::setName(const string & name)
{
		m_name = name;

}
//-------------------------------------------------------------------//
void User::setPassword(const string & password)
{
	m_password = password;
}
//-------------------------------------------------------------------//
bool User::setAdress(const Adress & adress)
{
	m_adress.setCountry(adress.getCountry());	
	m_adress.setCity(adress.getCity());
	m_adress.setStreet(adress.getStreet());
	if (m_adress.setHouseNumber(adress.getHouseNumber() == 0)) { return false; }
	return true;
}
//-------------------------------------------------------------------//


//-------------------------------------------------------------------//
const string & User::getName() const
{
	return m_name;
}
//-------------------------------------------------------------------//
const string & User::getPassword() const
{
	return m_password;
}
//-------------------------------------------------------------------//
const Adress& User::getAdress() const
{
	return m_adress;
}
//-------------------------------------------------------------------//
eUserType User::getUserType() const
{
	return m_type;
}
//-------------------------------------------------------------------//
void User::show() const
{
	cout << endl << eUserTypeSTR[m_type] <<  " name: " << m_name << endl;

	cout << "password: " << m_password << endl;

	cout << "adress: "; m_adress.printAdress();
}
//-------------------------------------------------------------------//