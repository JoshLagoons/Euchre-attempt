#pragma once
#include <string>
class Cards
{
public:
	enum cardType {SPADES, HEARTS, CLUBS, DIAMONDS};
	enum cardNumber{EIGHT = 1, NINE, TEN, QUEEN, KING, ACE, JACK};

	//structors
	Cards();
	Cards(cardType _cardo, cardNumber _number);
	Cards(const Cards& _cards);
	~Cards();

	//function numbers
	cardNumber GetNumber() const;
	void DisplayNumber() const;
	cardType GetType() const;
	void DisplayType() const;
	void SetCard(Cards::cardType _type);

	static int instances;

private:
	cardType m_cardo;
	cardNumber m_number;

};

