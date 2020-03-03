#include "Buyer_Seller.h"



Buyer_Seller::Buyer_Seller(const string & name, const string & password, const Adress & adress, System* system)
	:User(name, password, adress), Buyer(name, password, adress), Seller(name, password, adress, system)
{
	m_type = (eUserType)EBUYER_SELLSER;
}


Buyer_Seller::~Buyer_Seller()
{
}

void Buyer_Seller::show() const
{
	Buyer::show();
	Seller::show();
}
