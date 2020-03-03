#include "Order.h"

#include"Buyer.h"

//-------------------------------------------------------------------//
Order::Order()
{
	m_buyer = nullptr;
	m_finalOrder_Size = 0;
	m_price = 0;
}
//-------------------------------------------------------------------//
Order::Order(Buyer * buyer, Array<Product*> finalOrder, int finalOrder_Size, double price):m_finalOrder_Arr(finalOrder)
{
	//m_finalOrder_Arr = finalOrder;
	setBuyer(buyer);
	setFinalOrderSize(finalOrder_Size);
	setPrice(price);
}
//-------------------------------------------------------------------//
Order::Order(const Order & other)
{
	m_buyer = other.m_buyer;
	m_finalOrder_Arr = copyProductList(other.m_finalOrder_Arr.getArr(), other.m_finalOrder_Size);
	m_finalOrder_Size = other.m_finalOrder_Size;
	m_price = other.m_price;
}
//-------------------------------------------------------------------//
Order::~Order()
{
//	delete[] m_finalOrder_Arr;
}
//-------------------------------------------------------------------//


//-------------------------------------------------------------------//
bool Order::setBuyer(const Buyer * buyer)
{
	if (buyer != nullptr)
	{
		m_buyer = buyer;
		return true;
	}
	return false;
}
//-------------------------------------------------------------------//
bool Order::setPrice(double price)
{
	if (price >= 0)
	{
		m_price = price;
		return true;
	}
	return false;
}
//-------------------------------------------------------------------//
bool Order::setFinalOrderSize(int size)
{
	if (size >= 0)
	{
		m_finalOrder_Size = size;
		return true;
	}
	return false;
}
//-------------------------------------------------------------------//

//-------------------------------------------------------------------//
const Buyer * Order::getBuyer() const
{
	return m_buyer;
}
//-------------------------------------------------------------------//
Product ** Order::getFinalOrder() const
{
	return m_finalOrder_Arr.getArr();
}
//-------------------------------------------------------------------//
unsigned int Order::getFinalOrderSize() const
{
	return m_finalOrder_Size;
}
//-------------------------------------------------------------------//
double Order::getPrice() const
{
	return m_price;
}
//-------------------------------------------------------------------//


//-------------------------------------------------------------------//
Array<Product*> Order::copyProductList(Product ** source, int size)
{
	Array<Product*> destenation;

	for (int i = 0; i < size; i++)
		destenation += source[i];

	return destenation;
}
//-------------------------------------------------------------------//
void Order::printOrder() const
{
	cout  << endl << "items in order are: ";
	for (unsigned int i = 0; i < m_finalOrder_Size; i++)
		cout << m_finalOrder_Arr.getArr()[i]->getName() << ", ";
		
	cout << endl;

	cout << "total number of items in order: " << m_finalOrder_Size << endl <<
		"order cost is: " << m_price << endl;
}


