#include "System.h"

#include<fstream>
#include"Buyer_Seller.h"
#include"Adress.h"
#include"Product.h"


//-------------------------------------------------------------------//
System::System(const string & name, ifstream& in)
{
	string str_userType, userName, password, country, city, street,  str_housenum, str_numOfUsers;
	char del = '\n';

	getline(in, str_numOfUsers, del);
	int numOfUsers = FromStringToInt(str_numOfUsers);
	
	setName(name);
	m_userArr.reserve(numOfUsers);
	m_currentAmountOfUsers = 0;
	m_currentAmountOfBuyers = 0;
	m_currentAmountOfSellers = 0;

	for (int i = 0; i < numOfUsers; i++)
	{
		getline(in, str_userType, del);
		getline(in, userName, del);
		getline(in, password, del);
		getline(in, country, del);
		getline(in, city, del);
		getline(in, street, del);
		getline(in, str_housenum, del);
		
		int userType = FromStringToInt(str_userType);
		int houseNum = FromStringToInt(str_housenum);

		Adress address(country, city, street, houseNum);

		if (userType == 0)
		{
			Buyer* buyer = new Buyer(userName, password, address);
			m_userArr.push_back(buyer);

			m_currentAmountOfBuyers++;
			m_currentAmountOfUsers++;
		}

		else if (userType == 1)
		{
			Seller* seller = new Seller(userName, password, address, this);
			m_userArr.push_back(seller);

			m_currentAmountOfSellers++;
			m_currentAmountOfUsers++;
		}

		else
		{
			Buyer_Seller* bs = new Buyer_Seller(userName, password, address, this);
			m_userArr.push_back(bs);

			m_currentAmountOfBuyers++;
			m_currentAmountOfSellers++;
			m_currentAmountOfUsers++;
		}

	}
}
//-------------------------------------------------------------------//
System::~System()
{
	vector<User*>::iterator itr = m_userArr.begin();
	vector<User*>::iterator itrEnd = m_userArr.end();


	for (; itr != itrEnd; ++itr)
	{
		delete *(itr);
	}

}
//-------------------------------------------------------------------//


//-------------------------------------------------------------------//
void System::setName(const string & name)
{
	m_name = name;
}
//-------------------------------------------------------------------//
const string & System::getName() const
{
	return m_name;
}
//-------------------------------------------------------------------//
int System::getCurrentAmountOfSellers() const
{
	return m_currentAmountOfSellers;
}
//-------------------------------------------------------------------//
int System::getCurrentAmountOfBuyers() const
{
	return m_currentAmountOfBuyers;
}
//-------------------------------------------------------------------//
int System::getCurrentAmountOfUsers() const
{
	return m_currentAmountOfUsers;
}
//-------------------------------------------------------------------//


//-------------------------------------------------------------------//
void System::addBuyer(const string & name, const string & password, Adress & adress)
{
	Buyer* newBuyer = new Buyer(name, password, adress);

	m_currentAmountOfBuyers++;
	m_currentAmountOfUsers++;
	m_userArr.push_back(newBuyer);
}
//-------------------------------------------------------------------//
void System::addSeller(const string & name, const string & password, Adress & adress)
{
	Seller* newSeller = new Seller(name, password, adress, this);

	m_currentAmountOfSellers++;
	m_currentAmountOfUsers++;
	m_userArr.push_back(newSeller);
}
//-------------------------------------------------------------------//
void System::addBuyer_Seller(const string & name, const string & password, Adress & adress)
{
	Buyer_Seller* newBuyer_Seller = new Buyer_Seller(name, password, adress, this);

	m_currentAmountOfUsers++;
	m_currentAmountOfSellers++;
	m_currentAmountOfBuyers++;

	m_userArr.push_back(newBuyer_Seller);
}

//-------------------------------------------------------------------//
void System::addFeedback(Buyer * buyer, Feedback * feedback, int index)
{
	Seller* tempSeller;
	tempSeller = dynamic_cast<Seller*>(m_userArr[index]);
	if (!tempSeller)
		tempSeller = dynamic_cast<Buyer_Seller*>(m_userArr[index]);
	if (tempSeller)
		buyer->addFeedbackToSeller(tempSeller, feedback);
}
//-------------------------------------------------------------------//




//-------------------------------------------------------------------//
User * System::findUser(const string & name, const string & password, int flag)
{
	for (int i = 0; i < m_currentAmountOfUsers; i++)
	{
		if ( name == m_userArr[i]->m_name   &&   password == m_userArr[i]->m_password)
		{
			return m_userArr[i];
		}
	}

	return nullptr;
}
//-------------------------------------------------------------------//
bool System::checkValidUserName(const string & name, int flag)
{
	for (int i = 0; i < m_currentAmountOfUsers; i++)
	{
		if (name == m_userArr[i]->m_name   &&   flag == (int)m_userArr[i]->m_type + 1)
			return false;
	}
	return true;
}

//-------------------------------------------------------------------//
void System::showAllSellers() const
{
	for (int i = 0, j = 0; i < m_currentAmountOfUsers; i++)
	{
		if (m_userArr[i]->m_type == (int)SELLER)
		{
			cout << endl << (j + 1) << ")";
			m_userArr[i]->show();
			j++;
		}
	}
	cout << endl;
}
//-------------------------------------------------------------------//
void System::showAllBuyers() const
{
	for (int i = 0, j = 0; i < m_currentAmountOfUsers; i++)
	{
		if (m_userArr[i]->m_type == (int)BUYER  )
		{
			cout << endl << (j + 1) << ")";
			m_userArr[i]->show();
			j++;
		}
	}
	cout << endl;
}
//-------------------------------------------------------------------//
void System::showAllSellers_Buyers() const
{
	for (int i = 0, j = 0; i < m_currentAmountOfUsers; i++)
	{
		if (m_userArr[i]->m_type == (int)SELLER_BUYER)
		{
			cout << endl << (j + 1) << ")";
			m_userArr[i]->show();
			j++;
		}
	}
	cout << endl;
}
//-------------------------------------------------------------------//


//-------------------------------------------------------------------//
bool System::showAllProductNamed_X(const string & productName, int usersAmount) const
{
	Product* ProductToPrint = nullptr;
	bool didntPrint = 1;
	Seller* tempSeller;

	for (int i = 0; i < usersAmount; i++)
	{
		tempSeller = dynamic_cast<Seller*>(m_userArr[i]);
		if(!tempSeller)
			tempSeller = dynamic_cast<Buyer_Seller*>(m_userArr[i]);

		if (tempSeller)
		{
			int productArrSize = tempSeller->m_productArr.size();

			for (int j = 0; j < productArrSize; j++)
			{
				ProductToPrint = tempSeller->findProductByName(productName, productArrSize, j);

				if (ProductToPrint == nullptr)
				{
					;
				}
				else
				{
					cout << endl << "seller #" << (i + 1) << " name: " << this->m_userArr[i]->getName() <<
						" product #" << (j + 1) << endl;

					ProductToPrint->printProduct();
					didntPrint = 0;
				}
			}
		}
	}
	if (didntPrint == 1) 
	{
		return false;
	}
	return true;
}
//-------------------------------------------------------------------//



//-------------------------------------------------------------------//
void System::operator+=(Buyer * newBuyer)
{
	m_currentAmountOfBuyers++;
	m_currentAmountOfUsers++;
	m_userArr.push_back(newBuyer);
}
//-------------------------------------------------------------------//
void System::operator+=(Seller * newSeller)
{
	m_currentAmountOfSellers++;
	m_currentAmountOfUsers++;
	m_userArr.push_back(newSeller);
}
//-------------------------------------------------------------------//
int System::FromStringToInt(string & string)
{
	int num = 0;
	int sizeOfstring = string.size();
	for (int i = 0; i < sizeOfstring; i++)
		num = num * 10 + (string[i] - '0');
	return num;
}