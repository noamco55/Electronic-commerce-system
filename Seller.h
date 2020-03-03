#ifndef __Seller_H
#define __Seller_H

const int SELLER_ENUM = 1;

#include"System.h"
#include"Adress.h"
#include"User.h"

class Feedback;
class Product;
class User;

class Seller: virtual public User
{

public:
	Seller(const string & name, const string & password, const Adress & adress, System* system);


	virtual~Seller();

private:
	Seller(const Seller & other);
	Seller(const User & user, System* system);
	Seller();

public:
	
	bool setSystem(const System* system);


	// adding new product/ feedback to sellers product list
	void addProductToSeller(const string & productName, int categoryNumber, double price);
	void addFeedbackToList(Feedback * newFeedback);

	// checking if a spesiffic product in the product list match a name we send to the func
	Product* findProductByName(const string & productName, int numberOfProduct, int indexToCheck);

	// printing seller's details to the screen
	virtual void show() const override;

public:
	friend void menu_Print_Order_Feedback_Product_With_Operator(System & theSystem);
	friend void menu_Add_Product_To_Cart(System & theSystem);
	friend class System;

protected:
	vector<Product*> m_productArr;
	vector<Feedback*> m_feedbackArr;
	const System * m_system;
};
#endif // !__Seller_H