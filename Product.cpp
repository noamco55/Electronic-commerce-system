#include "Product.h"


Product::Product(const Seller * seller, int category, const string & name, double price):m_seller(seller)
{
	setCategory(category);
	setName(name);
	setPrice(price);

	m_serialNumber = serialGenerator++;
}
//-------------------------------------------------------------------//
Product::Product(const Product & other):m_seller(other.m_seller)
{
	this->setCategory(other.m_category);
	this->setName(other.m_name);
	this->setPrice(other.m_price);

	m_serialNumber = serialGenerator++;
}
//-------------------------------------------------------------------//
Product::Product(Product && other): m_seller(other.m_seller)
{
	m_category = other.m_category;
	m_price = m_price;
	m_serialNumber = m_serialNumber;
	std::move( std::begin(other.m_name), std::end(other.m_name), &m_name[0] ); // put into known issues

}
//-------------------------------------------------------------------//
bool Product::setCategory(int category)
{
		if(category >= 0 && category <= 4)
		{
			m_category = (eCategory)category;
			return true;
		}
		else
		{
			return false;
		}
	
}
//-------------------------------------------------------------------//
void Product::setName(const string & name)
{
	m_name = name;
}
//-------------------------------------------------------------------//
bool Product::setPrice(double price)
{
		if (price >= 0)
		{
			m_price = price;
			return true;
		}
		return false;
}
//-------------------------------------------------------------------//
const Seller * Product::getSeller()
{
	return m_seller;
}
//-------------------------------------------------------------------//
eCategory Product::getCategory()
{
	return m_category;
}
//-------------------------------------------------------------------//
const string & Product::getName() const
{
	return m_name;
}
//-------------------------------------------------------------------//
double Product::getPrice()
{
	return m_price;
}
//-------------------------------------------------------------------//
unsigned int Product::getSerialNumber()
{
	return m_serialNumber;
}
//-------------------------------------------------------------------//
void Product::printProduct() const
{
	cout << "prouduct name : " << m_name << ",   category: " << eCategorySTR[m_category] << ",   cost: " << m_price
		<< ",   serial number: " << m_serialNumber <<",   seller is: " << m_seller->getName() << endl;
}

//-------------------------------------------------------------------//
ostream & operator<<(ostream & os, const Product& product)
{
	os << "prouduct name : " << product.m_name << ",   category: " << eCategorySTR[product.m_category] << ",   cost: " << product.m_price
		<< ",   serial number: " << product.m_serialNumber << ",   seller is: " << product.m_seller->getName() << endl;
	return os;
}