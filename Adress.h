#ifndef __Adress_H
#define __Adress_H

#include"System.h"

class Adress
{
public:
	Adress(const string & country, const string & city, const string & street, int houseNumber);
	Adress(const Adress & other);
	Adress(Adress&& other);
	Adress() = delete;


	void setCountry(const string & country);
	void setCity(const string & city);
	void setStreet(const string & street);
	bool setHouseNumber(int houseNumber);


	const string &  getCountry() const;
	const string &  getCity() const;
	const string &  getStreet() const;
	int getHouseNumber() const;
	

	 // printing all of the adress
	void printAdress() const;
	friend ostream & operator<<(ostream & out, const Adress adress);


private:

	string m_country;
	string m_city;
	string m_street;
	int m_houseNumber;
};

#endif // !__Adress_H