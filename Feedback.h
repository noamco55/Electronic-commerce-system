#ifndef __Feedback_H
#define __Feedback_H

#include"System.h"

const int DATE_ARR_SIZE = 3;
const int DAY = 0;
const int MONTH = 1;
const int YEAR = 2;
const int FEEDBACK_MAX_LEN = 201;

class Buyer;

class Feedback
{
public:

	Feedback(const Buyer * buyer, const string & date, const string & feedback);
	Feedback(const Feedback & other);
	Feedback(Feedback&& other);
	Feedback() = delete;

	bool setBuyer(const Buyer* buyer);
	//void setDate(const string & date);
	void setFeedback(const string & feedback);
	
	const Buyer* getBuyer();
	const string & getDateArr();
	const string & getFeedback();

	
	// printing Feedback to the screen
	void printFeedback(); 

	friend ostream& operator<<(ostream& os, const Feedback& feedback);


private:
	const Buyer* m_buyer;
	const string m_date;
	string m_feedback;
};

#endif // !__Feedback_H
