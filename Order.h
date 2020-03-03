#ifndef __Order_H
#define __Order_H

#include"Product.h"
#include "Array.h"

class Buyer;
class Product;

class Order
{
public:
	Order();	
	Order(Buyer * buyer, Array<Product*> finalOrder, int finalOrder_Size, double price);
	Order(const Order & other);
	~Order();
	

	bool setBuyer(const Buyer* buyer);
	bool setPrice(double price);
	bool setFinalOrderSize(int size);


	const Buyer* getBuyer() const;
	unsigned int getFinalOrderSize() const;
	double getPrice() const;


	//create new product list and copy from source
	Array<Product*> copyProductList(Product** source, int size);

	// print order information
	void printOrder() const;

	friend ostream& operator<<(ostream& os, const Order& order)
	{
		os << endl << "items in order are: ";
		for (unsigned int i = 0; i < order.m_finalOrder_Size; i++)
			cout << order.m_finalOrder_Arr.getArr()[i]->getName() << ", ";

		os << endl;

		os << "total number of items in order: " << order.m_finalOrder_Size << endl <<
			"order cost is: " << order.m_price << endl;
		return os;
	}


	friend class Buyer;
	
private:
	Product** getFinalOrder() const;

private:
	Array<Product*> m_finalOrder_Arr;
	unsigned int m_finalOrder_Size;

	const Buyer* m_buyer;

	double m_price;

};
#endif // !__Order_H
