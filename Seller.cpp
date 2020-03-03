#include "Seller.h"

#include"Product.h"
#include"Feedback.h"

Seller::Seller(const string & name, const string & password,const Adress & adress, System* system)
	:User(name, password, adress)
{
	setSystem(system);

	m_productArr.reserve(SET_SIZE);

	m_feedbackArr.reserve(SET_SIZE);

	m_type = (eUserType)SELLER_ENUM;
}

//--------------------------------------------------------------------//
Seller::~Seller()
{
	vector<Feedback*>::iterator itr = m_feedbackArr.begin();
	vector<Feedback*>::iterator itrEnd = m_feedbackArr.end();

	for (; itr != itrEnd; ++itr)
	{
		delete (*itr);
	}

	vector<Product*>::iterator itr1 =m_productArr.begin();
	vector<Product*>::iterator itrEnd1 = m_productArr.end();

	for (; itr1 != itrEnd1; ++itr1)
	{
		delete (*itr1);
	}
}
//--------------------------------------------------------------------//


//-------------------------------------------------------------------//
bool Seller::setSystem(const System * system)
{
	if (system != nullptr)
	{
		m_system = system;
		return true;
	}
	return false;
	
}
//--------------------------------------------------------------------//


//-------------------------------------------------------------------//
void Seller::addProductToSeller(const string & productName, int categoryNumber, double price)
{
	Product* newProduct = new Product(this, categoryNumber, productName, price);

	m_productArr.push_back(newProduct);
}
//-------------------------------------------------------------------//
void Seller::addFeedbackToList(Feedback * newFeedback)
{
	m_feedbackArr.push_back(newFeedback);
}
//-------------------------------------------------------------------//
Product * Seller::findProductByName(const string & productName, int numberOfProduct, int indexToCheck)
{
		if (this->m_productArr[indexToCheck]->getName() == productName)
		{
			return this->m_productArr[indexToCheck];
		}
	
	return nullptr;
}
//-------------------------------------------------------------------//
void Seller::show() const
{
	if (m_type == SELLER)
	{
		User::show();
	}
	cout << "seller's prodoucts are:\n";

	int productArrSize = m_productArr.size();
	for (int i = 0; i < productArrSize; i++)
		m_productArr[i]->printProduct();

	cout << endl << "your feedbacks are:\n" << endl;

	int feedbackArrSize = m_feedbackArr.size();

	for (int i = 0; i < feedbackArrSize; i++)
	{
		cout << i + 1 << ")  ";
		m_feedbackArr[i]->printFeedback();
	}
	cout << endl;


}