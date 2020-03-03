#ifndef __Buyer_H
#define __Buyer__H

const int BUYER_ENUM = 0;

#include"System.h"
#include"Adress.h"
#include"Order.h"


class User;
class Product;
class Seller;


class Buyer: virtual public User
{
public:
	Buyer(const string & name, const string & password, const Adress & adress);
	virtual~Buyer();

private:
	Buyer(const Buyer & other);
	Buyer();
	Buyer(const User& user);


public:
	bool setCart(vector<Product*> Cart); // taking a cart and conecting it to buyer, cart may be nullptr

	int getCartSize() const;
	vector<Product*> getCart() const;
	int getnumberOfOrders() const;

	// adding the chosen productto Buyer cart
	void addProductToCart(Product * newProduct); 

	// adding Feedback from Buyer to Seller
	void addFeedbackToSeller(Seller * seller, Feedback * feedback);

	//adding order to buyers list
	void addOrderToList(const Order & order);

	//paying for order from the order list, delete the order and add sellers to sellers i can give feedback to
	void payForOrder(int orderNumber);
	
	// printing Buyer detail to the screen
	virtual void show() const override;

	//checking if i bought from
	bool findPrevSeller(const Seller* seller) const;


	friend class System;
	friend void menu_Create_New_Order(System & theSystem);
	friend void menu_Pay_For_Order(System & theSystem);
	friend void menu_Print_Order_Feedback_Product_With_Operator(System & theSystem);

public:
	bool operator>(const Buyer & other) const;




protected:
	vector<Product*> m_cart; 
	vector<Order> m_orderArr;
	vector<const Seller*> m_listOfPrevSellers;
};

#endif // !__Buyer_H