#pragma once
#include "Hands.h"
#include "UsingDeck.h"

class Dealer: public UsingDeck, public Hands
{
public: 
	Dealer();
	Dealer(const Dealer& _dealer);
	Dealer(Deck* _deck, int _player, bool _thedealer);
	~Dealer();

	//Usingdeck virtual methods
	virtual void DealtheCards(Hands& _hands, int _cardstodeal);
	virtual void ShuffleDeck();
	virtual Cards& TopCardCopy();
	virtual void FreeDeckCardMemory();
	virtual void FreeDeckMemory();
	virtual void DisplayDeck() const;

	//bool functions
	bool TrumpTHreshold(Cards::cardType _trump);
	Cards::cardType FavoredType();

private:
	int m_SpadesTrump();
	int m_DiamondsTrump();
	int m_HeartsTrump();
	int m_ClubsTrump();
};

