#ifndef __Product_H
#define __Product_H

#include"System.h"
#include"Seller.h"

static int serialGenerator = 100000;

enum eCategory { KIDS, ELECTRICITY, OFFICE, CLOTHING };
static const string eCategorySTR[] = { "kids", "electicity", "office", "clothing" };

class Product
{
public:
	
	Product(const Seller * seller, int category, const string & name, double price);
	Product(const Product & other);
	Product(Product&& other);
	
	Product() = delete; //no default c'tor
	
	
	bool setCategory(int category);
	void setName(const string & name);
	bool setPrice(double price);


	const Seller* getSeller();
	eCategory getCategory();
	const string & getName() const;
	double getPrice();
	unsigned int getSerialNumber();

	// printing product to the screen
	void printProduct() const;

	friend ostream& operator<<(ostream& os, const Product& product);

private:
	const Seller* const m_seller;
	eCategory m_category;
	string m_name;
	double m_price;
	unsigned int m_serialNumber;
};



#endif // !__Product_H