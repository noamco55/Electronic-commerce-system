#include "Adress.h"


Adress::Adress(const string & country, const string & city, const string & street, int houseNumber)
{
	setCountry(country);
	setCity(city);
	setStreet(street);
	setHouseNumber(houseNumber);
}
//----------------------------------------------------------------------//
Adress::Adress(const Adress & other)
{
	setCountry(other.m_country);
	setCity(other.m_city);
	setStreet(other.m_street);
	setHouseNumber(other.m_houseNumber);
}
//----------------------------------------------------------------------//
Adress::Adress(Adress && other)
{
	std::move(std::begin(other.m_country), std::end(other.m_country), &m_country[0]);
	std::move(std::begin(other.m_city), std::end(other.m_city), &m_city[0]);
	std::move(std::begin(other.m_street), std::end(other.m_street), &m_street[0]);
	m_houseNumber = other.m_houseNumber;
}
//----------------------------------------------------------------------//
void Adress::setCountry(const string & country)
{
	m_country = country;
}
//----------------------------------------------------------------------//
void Adress::setCity(const string & city)
{
	m_city = city;
}
//----------------------------------------------------------------------//
void Adress::setStreet(const string & street)
{
	m_street = street;
}
//----------------------------------------------------------------------//
bool Adress::setHouseNumber(int houseNumber)
{
	if (houseNumber > 0)
	{
		m_houseNumber = houseNumber;
		return true;
	}
	else
	{
		return false;
	}
}
//----------------------------------------------------------------------//
const string &  Adress::getCountry() const
{
	return m_country;
}
//----------------------------------------------------------------------//
const string &  Adress::getCity() const
{
	return m_city;
}
//----------------------------------------------------------------------//
 const string &  Adress::getStreet() const
{
	return m_street;
}
//----------------------------------------------------------------------//
int Adress::getHouseNumber() const
{
	return m_houseNumber;
}
//----------------------------------------------------------------------//
void Adress::printAdress() const
{
	cout << "you live at\n" << getCountry() << ", " << getCity() << ", " << getStreet()
		<< " steet, house number " << getHouseNumber() << endl;
}
//----------------------------------------------------------------------//
ostream & operator<<(ostream & out, const Adress adress)
{
	out << adress.getCountry() << "\n" << adress.getCity() << "\n"
		<< adress.getStreet() << "\n" << adress.getHouseNumber();
	return out;
}