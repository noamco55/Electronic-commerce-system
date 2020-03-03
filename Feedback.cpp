#include "Feedback.h"

#include"Buyer.h"

Feedback::Feedback(const Buyer * buyer, const string &date, const string & feedback):m_date(date)
{
	setBuyer(buyer);
	setFeedback(feedback);
}
//-------------------------------------------------------------------//
Feedback::Feedback(const Feedback & other):m_date(other.m_date)
{
	this->setBuyer(other.m_buyer);
	//this->setDate(other.m_date);
	this->setFeedback(other.m_feedback);
}
//-------------------------------------------------------------------//
Feedback::Feedback(Feedback && other):m_buyer(other.m_buyer), m_date(other.m_date)
{
	std::move(std::begin(other.m_feedback), std::end(other.m_feedback), &m_feedback[0]);


}
//-------------------------------------------------------------------//
bool Feedback::setBuyer(const Buyer * buyer)
{
	if (buyer != nullptr)
	{
		m_buyer = buyer;
		return true;
	}
	return false;
}
//-------------------------------------------------------------------//
void Feedback::setFeedback(const string & feedback)
{
	m_feedback = feedback;
}
//-------------------------------------------------------------------//
const Buyer * Feedback::getBuyer()
{
	return m_buyer;
}
//-------------------------------------------------------------------//
const string & Feedback::getDateArr()
{
	return m_date;
}
//-------------------------------------------------------------------//
const string & Feedback::getFeedback()
{
	return m_feedback;
}
//-------------------------------------------------------------------//
void Feedback::printFeedback()
{
	cout << "buyer name: " << m_buyer->getName() <<endl <<
		"feedback occurred on: " << m_date << endl
	 << "the feedback is:  " << m_feedback << endl << endl;
}

//-------------------------------------------------------------------//

ostream & operator<<(ostream & os, const Feedback & feedback)
{
	os << "buyer name: " << feedback.m_buyer->getName() << endl <<
		"feedback occurred on: " << feedback.m_date << endl
	<< "the feedback is:  " << feedback.m_feedback << endl << endl;

	return os;
}