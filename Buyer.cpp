#include "Buyer.h"

#include"Feedback.h"
#include"Product.h"
#include"Seller.h"

//-------------------------------------------------------------------//
Buyer::Buyer(const string & name, const string & password, const Adress & adress)
	:User(name, password, adress)
{
	m_cart.reserve(SET_SIZE);
	m_listOfPrevSellers.reserve(SET_SIZE);
	m_orderArr.reserve(SET_SIZE);
	m_type = (eUserType)BUYER_ENUM;
}
//-------------------------------------------------------------------//
Buyer::~Buyer()
{
	m_cart.clear();
	m_listOfPrevSellers.clear();
	m_orderArr.clear();
}
//-------------------------------------------------------------------//

bool Buyer::setCart(vector<Product*> Cart)
{
	if (Cart.empty() == true)
	{
		return false;
	}
	
	if (m_cart.empty() == true)
	{
		m_cart = Cart;
		return true;
	}
	else
	{
		m_cart.clear();
		m_cart = Cart;
		return true;
	}
}
//-------------------------------------------------------------------//


//-------------------------------------------------------------------//
int Buyer::getCartSize() const
{
	return m_cart.size();
}
//-------------------------------------------------------------------//
vector<Product*> Buyer::getCart() const
{
	return m_cart;
}
//-------------------------------------------------------------------//
int Buyer::getnumberOfOrders() const
{
	return m_orderArr.size();
}
//-------------------------------------------------------------------//


//-------------------------------------------------------------------//
void Buyer::addProductToCart(Product * newProduct)
{
	m_cart.push_back(newProduct);
}
//-------------------------------------------------------------------//
void Buyer::addFeedbackToSeller(Seller * seller, Feedback * feedback)
{
	vector<const Seller*>::const_iterator itr = m_listOfPrevSellers.begin();
	vector<const Seller*>::const_iterator endItr = m_listOfPrevSellers.end();


	for ( ; itr != endItr; ++itr)
	{
		if (seller == *itr)
		{
			seller->addFeedbackToList(feedback);
			return;
		}
	}
	cout << "can't add feedback, " << m_name << " is not a client of " << seller->getName() << endl;
}
//-------------------------------------------------------------------//
void Buyer::addOrderToList(const Order & order)
{
	m_orderArr.push_back(order);
}
//-------------------------------------------------------------------//
void Buyer::payForOrder(int orderNumber)
{
	const Seller* sellerToAdd;


	for (unsigned int j = 0; j < m_orderArr[orderNumber].m_finalOrder_Size; j++)
	{
		sellerToAdd = m_orderArr[orderNumber].m_finalOrder_Arr.getArr()[j]->getSeller();

		if (findPrevSeller(sellerToAdd) == 0 )
		{
			m_listOfPrevSellers.push_back(sellerToAdd);
		}
	}
	
	delete[] m_orderArr[orderNumber].m_finalOrder_Arr.getArr();

	int numberOfOrders = m_orderArr.size();

	for (int i = orderNumber; i < (numberOfOrders - 1); i++)
		m_orderArr[i] = m_orderArr[i + 1];

	numberOfOrders--;
}
//-------------------------------------------------------------------//
void Buyer::show() const
{
	User::show();

	cout << "the products in cart are: " << endl;

	int cartSize = m_cart.size();

	for (int i = 0; i < cartSize; i++)
		m_cart[i]->printProduct();


	cout << "list of previous sellers: ";

	vector<const Seller*>::const_iterator itr = m_listOfPrevSellers.begin();
	vector<const Seller*>::const_iterator endItr = m_listOfPrevSellers.end();

	for (; itr != endItr; ++itr)
		cout << endl<< (*itr)->getName();


	cout << endl;
}
//-------------------------------------------------------------------//
bool Buyer::findPrevSeller(const Seller * seller) const
{
	vector<const Seller*>::const_iterator itr = m_listOfPrevSellers.begin();
	vector<const Seller*>::const_iterator endItr = m_listOfPrevSellers.end();

	for (; itr != endItr; ++itr)
	{
		if (seller == *itr)
			return true;
	}
	return false;
}
//-------------------------------------------------------------------//


bool Buyer::operator>(const Buyer & other) const
{
	double sumOfCart1 = 0, sumOfCart2 = 0;

	int cartSize1 = this->m_cart.size();
	int cartSize2 = other.m_cart.size();

	for (int i = 0; i < cartSize1; i++)
		sumOfCart1 += m_cart[i]->getPrice();

	for (int i = 0; i < cartSize2; i++)
		sumOfCart2 += other.m_cart[i]->getPrice();

	if (sumOfCart1 > sumOfCart2)
		return true;
	
	else
		return false;

}
//-------------------------------------------------------------------//
