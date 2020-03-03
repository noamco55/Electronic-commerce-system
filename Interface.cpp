#include "Interface.h"
#include<ctime>
#include"Adress.h"
#include"Buyer_Seller.h"
#include"Feedback.h"
#include"Product.h"
#include"Order.h"


//-------------------------------------------------------------------//
void startSystem(System& theSystem)
{
	int choise = 0;

	cout << "Welcome to: " << theSystem.getName() << endl << endl;

	while (choise != 17)
	{
		printMenu();

		cin >> choise;

		switch(choise)
		{
			case 1:
				menu_Add_User(theSystem, choise);
				break;
			
			case 2:
				menu_Add_User(theSystem, choise);
				break;

			case 3:
				menu_Add_User(theSystem, choise);
				break;

			case 4:
				menu_Add_New_Product(theSystem);
				break;

			case 5:
				menu_Add_Feedback(theSystem);
				break;

			case 6:
				menu_Add_Product_To_Cart(theSystem);
				break;

			case 7:
				menu_Create_New_Order(theSystem);
				break;

			case 8:
				menu_Pay_For_Order(theSystem);
				break;

			case 9:
				theSystem.showAllBuyers();
				break;

			case 10:
				theSystem.showAllSellers();
				break;

			case 11:
				theSystem.showAllSellers_Buyers();
				break;

			case 12:
				menu_Display_All_Products_Named_X(theSystem);
				break;

			case 13:
				menu_add_Seller_Or_Buyer_With_Operator(theSystem, choise);
				break;

			case 14:
				menu_add_Seller_Or_Buyer_With_Operator(theSystem, choise);
				break;

			case 15:
				menu_Compare_Two_Buyers(theSystem);
				break;

			case 16:
				menu_Print_Order_Feedback_Product_With_Operator(theSystem);
				break;

			case 17:
				menu_Save_and_Exit(theSystem);
				break;
				
			default:
				cout << "invalid input!" << endl;
				break;
		}

	}
}
//-------------------------------------------------------------------//
void printMenu()
{
	cout << endl << "Menu:" << endl << "please enter the nubmer of the function you want to make" <<
		endl << "1) Add new Buyer" << endl << "2) Add new seller" <<
		endl << "3) Add new Buyer_Seller" <<
		endl << "4) Add item to seller" << endl << "5) Add feedback to seller" <<
		endl << "6) Add item to buyer's cart" <<
		endl << "7) make an order" << endl << "8) pay for an order" <<
		endl << "9) display all buyers" << endl << "10) display all sellers" <<
		endl << "11) display all sellers_buyers"<<
		endl << "12) display all product whith certain name" <<
		endl << "13) check operator += for Buyer" << endl << "14) check operator += for Seller" <<
		endl << "15) compare two buyers with > operator" <<
		endl << "16) print orders, feedbacks and products with << operator" <<
		endl << "17) exit" << endl << endl;
}
//-------------------------------------------------------------------//


//-------------------------------------------------------------------//
void menu_Add_User(System & theSystem, int flag)
{
	cleanBuffer();

	string password, country, city, street, tempName;
	int houseNumber;
	bool validUserName;

	cout << endl << "enter User's name" << endl;
	
	getline(cin, tempName);
	const string name(tempName);

	validUserName = theSystem.checkValidUserName(name, flag);
	if (validUserName)
	{

		cout << "enter User's password" << endl;
		getline(cin, password);

		cout << "enter User's country" << endl;
		getline(cin, country);

		cout << "enter User's city" << endl;
		getline(cin, city);

		cout << "enter User's street" << endl;
		getline(cin, street);

		cout << "enter User's house number" << endl;
		cin >> houseNumber;

		Adress adress(country, city, street, houseNumber);

		if (flag == 1)
			theSystem.addBuyer(name, password, adress);
		else if (flag == 2)
			theSystem.addSeller(name, password, adress);
		else if (flag == 3)
			theSystem.addBuyer_Seller(name, password, adress);

		cout << endl << "user added successfully" << endl;
	}

	else
		cout << "user name already exist in the system" << endl;
	
}
//-------------------------------------------------------------------//
void menu_Add_New_Product(System & theSystem)
{
	cleanBuffer();

	cout << endl << "to add a new product please log in to seller user" << endl;
	
	User* TempSeller = sellerLogIn(theSystem);

	Seller * seller = dynamic_cast<Seller*>(TempSeller);

	if (seller != nullptr)
	{
		int categoryNumber;
		double price;
		string productName;

		cleanBuffer();

		cout << "please enter product name" << endl;
		getline(cin, productName);

		cout << "enter product category:  \n1) kids \n2) electicity \n3) office \n4) clothing \n";
		cin >> categoryNumber;
		categoryNumber--;

		cout << "please enter product price" << endl;
		cin >> price;

		if (price < 0)
		{
			cout << "price cannot be negative, product did not added" << endl;
			return;
		}


		seller->addProductToSeller(productName, categoryNumber, price);

		cout << endl << "product name: " << productName << " added to seller: " << seller->getName() << endl;
	}

	else
	{
		cout << "seller log-in information invalid" << endl;
	}

}
//-------------------------------------------------------------------//
void menu_Add_Feedback(System & theSystem)
{
	cout << endl << "to add a new feedback please log in to buyer user" << endl;

	cleanBuffer();

	User * tempBuyer = (buyerLogIn(theSystem));

	Buyer * buyer = dynamic_cast<Buyer*>(tempBuyer);


	if (buyer != nullptr)
	{
		int sellerNumber;
		
		cout << endl << "please choose the seller that you want to give feedback to:" << endl;
		
		int sellersAmount = theSystem.getCurrentAmountOfUsers();

		for (int i = 0; i < sellersAmount; i++)
		{
			Seller* tempSeller = dynamic_cast<Seller*>(theSystem.m_userArr[i]);
			
			if (tempSeller != nullptr)
			{
				cout << endl << (i + 1) << ") " << "name: " << tempSeller->getName();
			}
		}

		cout << endl << endl << "choose the seller's number: " << endl;
		cleanBuffer();
		sellerNumber = (getchar() - '0');
		
		if (sellerNumber > 0 && sellerNumber <= sellersAmount)
		{
			cout << "enter your feedback" << endl;
			cleanBuffer();

			string tempTxt;
			getline(cin, tempTxt);
			const string txt_feedback(tempTxt);

			time_t now = time(0);

			const string date(ctime(&now));

			Feedback* feedback = new Feedback(buyer, date, txt_feedback);

			theSystem.addFeedback(buyer, feedback, (sellerNumber - 1));

			cout << endl << "feedback added successfully" << endl;
		}
		else
		{
			cout << "invalid seller number" << endl;
			cleanBuffer();
		}
	}

	else
	{
		cout << "buyer log-in information invalid" << endl;
	}
}
//-------------------------------------------------------------------//
void menu_Add_Product_To_Cart(System & theSystem)
{
	cleanBuffer();
	
	cout << "to add product to the cart, please log-in to buyer" << endl;

	User * tempBuyer = (buyerLogIn(theSystem));

	Buyer * buyer = dynamic_cast<Buyer*>(tempBuyer);


	if (buyer != nullptr)
	{
		cleanBuffer();
		cout << endl << "enter product name" << endl;
		string productName;
		getline(cin, productName);

		bool printed = theSystem.showAllProductNamed_X(productName, theSystem.m_currentAmountOfUsers);

		if (printed == 1)
		{
			int sellerNumber, productNumber;

			cout << endl << "please enter the seller number" << endl;
			cin >> sellerNumber;

			Seller * seller = dynamic_cast<Seller*>(theSystem.m_userArr[sellerNumber - 1]);
		

			if (seller)
			{

				cout << "please enter the product number" << endl;
				cin >> productNumber;

				buyer->addProductToCart(seller->m_productArr[productNumber - 1]);

				cout << endl << "product added successfully" << endl;
			}
		}

		else
			cout << endl << "no item match that name" << endl;
	}
	
	else
	{
		cout << "buyer log-in information invalid" << endl;
	}
}
//-------------------------------------------------------------------//
void menu_Create_New_Order(System & theSystem)
{
	cleanBuffer();
	cout << "to create a new order please log-in to buyer" << endl;
	
	User * tempBuyer = (buyerLogIn(theSystem));

	Buyer * buyer = dynamic_cast<Buyer*>(tempBuyer);


	if (buyer != nullptr)
	{
		if (buyer->m_cart.size() == 0)
		{
			cout << endl << "cart is empty" << endl;
			return;
		}


		int finalOrder_Size = 0, i = 0, j = 0, toOrder = 0;
		int originalCartSize = buyer->m_cart.size();
		double price = 0;

		Array<Product*> tempProductArr;
		vector<Product*> tempCart;
		tempCart.reserve(originalCartSize);
		tempCart = buyer->getCart();

		while (i < originalCartSize)
		{
			cout << "item # " << (i + 1) << " is: \n";
			tempCart[i]->printProduct();
			cout << "to order this product press 1, otherwise press 0 \n";
			cin >> toOrder;

			if (toOrder == 1)
			{
				tempProductArr += tempCart[i];

				j++;
				finalOrder_Size++;

				price = price + tempCart[i]->getPrice();

				tempCart[i] = nullptr;
			}
			i++;
		}

		if (finalOrder_Size == 0)
		{
			cout << endl << "illigal order" << endl;
			return;
		}

		if (originalCartSize - finalOrder_Size != 0)
		{
			vector<Product*> newCart;
			newCart.reserve(originalCartSize - finalOrder_Size); // the size of the original cart - the size of the final
			//order is the size of the cart afterorder

			updateProductList(tempCart, newCart, originalCartSize, (originalCartSize - finalOrder_Size)); // get newCart ready to be m_buyer->m_cart
			buyer->setCart(newCart);
			buyer->m_cart.resize(originalCartSize - finalOrder_Size);
		}


		/*else
		{
			delete[] buyer->m_cart;
			buyer->m_cartSize = 0;
			buyer->m_cart = nullptr;
		}*/

		Order order(buyer, tempProductArr, finalOrder_Size, price);
		buyer->addOrderToList(order);
		cout << endl << "order added successfully" << endl;

	}
	else
		cout << "to many orders have started, please finish one to add another one" << endl;
}
//-------------------------------------------------------------------//
void menu_Pay_For_Order(System & theSystem)
{
	cleanBuffer();
	cout << "to pay for an order please log-in to buyer" << endl;
	
	User * tempBuyer = (buyerLogIn(theSystem));

	Buyer * buyer = dynamic_cast<Buyer*>(tempBuyer);


	if (buyer != nullptr) {
		cout << "please choose the order number to pay for from the following:" << endl;

		for (int i = 0; i < buyer->getnumberOfOrders(); i++)
		{
			cout << endl << "order # " << (i + 1) << " is: ";
			buyer->m_orderArr[i].printOrder();
		}

		int orderNum;
		cout << endl << "please choose the order number:" << endl;
		cin >> orderNum;
		orderNum--;

		cout << "paying for order #" << (orderNum + 1) << ": ";
		buyer->m_orderArr[orderNum].printOrder();

		buyer->payForOrder(orderNum);

		cout << endl << "order comleted successfully, thanks for buying!" << endl;
	}
	else
		cout << "buyer log-in information invalid" << endl;

}
//-------------------------------------------------------------------//
void menu_Display_All_Products_Named_X(System & theSystem)
{
	cleanBuffer();


	string productName;
	cout << "enter product name" << endl;

	getline(cin, productName);

		bool printed = theSystem.showAllProductNamed_X(productName, theSystem.m_currentAmountOfUsers);

		if (printed == 0)
			cout << "no item match that name" << endl;

	else
	{
		cout << "product name is to long" << endl;
	}
	cout << endl;
}
//-------------------------------------------------------------------//
void menu_add_Seller_Or_Buyer_With_Operator(System & theSystem, int flag)
{
	cleanBuffer();

	string password, country, city, street;
	int houseNumber;
	bool validUserName;

	cout << endl << "enter User's name" << endl;
	string tempName;
	getline(cin, tempName);
	const string name(tempName);

	validUserName = theSystem.checkValidUserName(name, flag);

	if (validUserName == false)
	{
		cout << "enter User's password" << endl;
		getline(cin, password);

		cout << "enter User's country" << endl;
		getline(cin, country);

		cout << "enter User's city" << endl;
		getline(cin, city);

		cout << "enter User's street" << endl;
		getline(cin, street);

		cout << "enter User's house number" << endl;
		cin >> houseNumber;

		Adress adress(country, city, street, houseNumber);

		if (flag == 13)
		{
			Buyer* newBuyer = new Buyer(name, password, adress);
			theSystem += newBuyer;
		}

		else
		{
			Seller* newSeller = new Seller(name, password, adress, &theSystem);
			theSystem += newSeller;
		}


		cout << endl << "user added successfully" << endl;
	}

	else
		cout << "user name already exist in the system" << endl;
}
//-------------------------------------------------------------------//
void menu_Compare_Two_Buyers(System & theSystem)
{
	cout << endl << "to compare, log into two buyers" << endl;

	cleanBuffer();

	User * tempBuyer = (buyerLogIn(theSystem));

	Buyer * buyer1 = dynamic_cast<Buyer*>(tempBuyer);

	tempBuyer = (buyerLogIn(theSystem));

	Buyer * buyer2 = dynamic_cast<Buyer*>(tempBuyer);

	if (buyer1 != nullptr && buyer2 != nullptr)
	{
		if (*buyer1 > *buyer2)
			cout << buyer1->getName() << " has the more expensive cart" << endl;

		else if(*buyer2 > *buyer1)
			cout << buyer2->getName() << " has the more expensive cart" << endl;

		else
			cout  << "the carts cost the same amount of money" << endl;

	}

	else
	{
		cout << "at list one buyer log-in information invalid" << endl;
	}
}
//-------------------------------------------------------------------//
void menu_Print_Order_Feedback_Product_With_Operator(System & theSystem)
{
	cleanBuffer();
	cout << "to print the orders please log-in to buyer" << endl;

	User * tempBuyer = (buyerLogIn(theSystem));
	Buyer * buyer = dynamic_cast<Buyer*>(tempBuyer);

	if (buyer != nullptr)
	{
		for (int i = 0; i < buyer->getnumberOfOrders(); i++)
		{
			cout << "order #" << (i + 1) << endl;
			cout << buyer->m_orderArr[i]; 
		}
	}


	cleanBuffer();

	cout << endl << "to print the products and feedbacks please log in to seller user" << endl;

	User* TempSeller = sellerLogIn(theSystem);
	Seller * seller = dynamic_cast<Seller*>(TempSeller);

	if (seller != nullptr)
	{
		cout << "feedbacks:" << endl;

		int feedbackArrSize = seller->m_feedbackArr.size();

		for (int i = 0; i < feedbackArrSize; i++)
			cout << *(seller->m_feedbackArr[i]);

		cout << "products:" << endl;

		int productArrSize = seller->m_productArr.size();
		for (int i = 0; i < productArrSize; i++)
			cout << *(seller->m_productArr[i]);

	}
}
//-------------------------------------------------------------------//
void menu_Save_and_Exit(System & theSystem)
{
	ofstream outFile("system.txt", ios::trunc);

	vector<User*>::iterator itr = theSystem.m_userArr.begin();
	vector<User*>::iterator itrEnd = theSystem.m_userArr.end();
	
	outFile << theSystem.m_userArr.size() << "\n";

	for (; itr != itrEnd; ++itr) 
	{
		outFile << (*itr)->getUserType() << "\n" << (*itr)->getName()
			<< "\n" << (*itr)->getPassword() << "\n" << (*itr)->getAdress() << "\n";
	}
	outFile.close();
}
//-------------------------------------------------------------------//


//-------------------------------------------------------------------//
User * sellerLogIn(System & theSystem)
{
	string name, password;

	cout << endl << "enter user's name:" << endl;
	cin >> name;

	cout << "enter password:" << endl;
	cin >> password;

	cout << endl;

	return theSystem.findUser(name, password, int(SELLER));
}
//-------------------------------------------------------------------//
User * buyerLogIn(System & theSystem)
{
	string name, password;
	cout << endl << "enter user's name:" << endl;
	cin >> name;

	cout << "enter password:" << endl;
	cin >> password;

	cout << endl;

	return theSystem.findUser(name, password,int(BUYER));
}
//-------------------------------------------------------------------//

//-------------------------------------------------------------------//
void updateProductList(vector<Product*> source, vector<Product*> destenation, int sourceSize, int desSize)
{
	destenation.reserve(desSize);

	for (int i = 0; i < sourceSize; i++)
	{
		if (source[i] != nullptr)
		{
			destenation.push_back(source[i]);
		}
	}
}
//-------------------------------------------------------------------//
void cleanBuffer()
{
	int c;
	do
	{
		c = getchar();
	} while (c != EOF && c != '\n');
}
//-------------------------------------------------------------------//

