#ifndef __Interface_H
#define __Interface_H

#include"System.h"
#include<fstream>

class Product;
class Interface
{ };
	
	void startSystem(System& theSystem);
	void printMenu();

	// function that take informatin from user and send it to the methods in the classes 
	void menu_Add_User(System& theSystem, int flag);
	void menu_Add_New_Product(System& theSystem);
	void menu_Add_Feedback(System& theSystem);
	void menu_Add_Product_To_Cart(System& theSystem);
	void menu_Create_New_Order(System& theSystem);
	void menu_Pay_For_Order(System& theSystem);
	void menu_Display_All_Products_Named_X(System& theSystem);
	void menu_add_Seller_Or_Buyer_With_Operator(System& theSystem, int flag);
	void menu_Compare_Two_Buyers(System& theSystem);
	void menu_Print_Order_Feedback_Product_With_Operator(System& theSystem);
	void menu_Save_and_Exit(System& theSystem);

	//getting name and password from user to find seller/buyer in system
	User* sellerLogIn(System& theSystem);
	User* buyerLogIn(System& theSystem);

	//copy product list without nulls
	void updateProductList(vector<Product*> source, vector<Product*> destenation, int sourceSize, int desSize);
	
	//cleaning buffer
	void cleanBuffer();


#endif // !__Interface_H