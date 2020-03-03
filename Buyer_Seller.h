#ifndef __Buyer_Seller_H
#define __Buyer_Seller_H

#include "Buyer.h"
#include "Seller.h"

const int EBUYER_SELLSER = 2;

class Buyer_Seller: public Buyer , public Seller
{
public:
	Buyer_Seller(const string & name, const string & password, const Adress & adress, System* system);
	virtual ~Buyer_Seller();

	virtual void show() const override;

private:
	Buyer_Seller();

};


#endif // !__Buyer_Seller.h
