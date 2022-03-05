#include "Cards.h"
#include "headercompiler.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

Cards::Cards()
{
	instances++;
}
Cards::Cards(cardType _cardo, cardNumber _number)
{
	m_cardo = _cardo;
	m_number = _number;
	instances++;
	//this will get the card constructor
}

Cards::Cards(const Cards& _cards)
{
	//std::cout << "Card copy called" << std::endl;
	m_cardo = _cards.GetType();
	m_number = _cards.GetNumber();
}
int Cards::instances = 70;
Cards::~Cards()
{
	//std::cout << "~Card Destructor"<<std::endl;
}
Cards::cardNumber Cards::GetNumber() const {
	return m_number;
}
void Cards::DisplayNumber() const {
	switch (m_number) {
	case Cards::EIGHT:
		cout << "8";
		break;
	case Cards::NINE:
		cout << "9";
		break;
	case Cards::TEN:
		cout << "10";
		break;
	case Cards::JACK:
		cout << "Jack";
		break;
	case Cards::QUEEN:
		cout << "Queen";
		break;
	case Cards::KING:
		cout << "King";
		break;
	case Cards::ACE:
		cout << "Ace";
		break;
	}
}
Cards::cardType Cards::GetType() const {
	return m_cardo;
}
void Cards::DisplayType() const {
	switch (m_cardo) {
	case Cards::SPADES:
		cout << "SPADES";
		break;
	case Cards::HEARTS:
		cout << "HEARTS";
		break;
	case Cards::CLUBS:
		cout << "CLUBS";
		break;
	case Cards::DIAMONDS:
		cout << "DIAMONDS";
		break;
	}
}
void Cards::SetCard(Cards::cardType _type) {
	m_cardo = _type;
}
