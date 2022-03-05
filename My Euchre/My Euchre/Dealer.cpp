#include "Dealer.h"
#include "headercompiler.h"
#include <algorithm>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

Dealer::Dealer()
{

}
Dealer::Dealer(Deck* _deck, int _player, bool _thedealer)
	:Hands(_player, _thedealer), UsingDeck(_deck, _thedealer)
{
	theDealer = _thedealer;
}
Dealer::Dealer(const Dealer& _dealer) : Hands(_dealer)
{

}
Dealer::~Dealer()
{

}
void Dealer::DealtheCards(Hands& _hands, int _cardstodeal)
{
	if (theDealer)
	{
		for (int i = 0; i < _cardstodeal; i++)
		{
			_hands.AddCards(deck->Deal());
		}
	}
}
void Dealer::ShuffleDeck()
{
	if (theDealer)
	{
		srand(unsigned(time(0)));
		random_shuffle(deck->GetDeck().begin(), deck->GetDeck().end());
	}
}
void Dealer::FreeDeckCardMemory()
{
	deck->FreeCardsMemory();
}
void Dealer::FreeDeckMemory()
{
	delete deck;
	deck = 0;
}
void Dealer::DisplayDeck() const
{
	deck->DisplayDeck();
}
Cards& Dealer::TopCardCopy()
{
	return  *deck->GetDeck().front();
}
bool Dealer::TrumpTHreshold(Cards::cardType _trump)
{
	int threshold = 0;
	srand(unsigned(time(0)));
	switch (_trump)
	{
	case Cards::DIAMONDS:
		threshold = m_DiamondsTrump();
		break;
	case Cards::HEARTS:
		threshold = m_HeartsTrump();
		break;
	case Cards::CLUBS:
		threshold = m_ClubsTrump();
		break;
	case Cards::SPADES:
		threshold = m_SpadesTrump();
		break;

	}
	if (threshold == 10)
	{
		if (rand() % 2 == 1)
		{
			return true;
		}
		else {
			return false;
		}
	}
	else if (threshold > 10)
	{
		return true;
	}
	return false;

}
int Dealer::m_DiamondsTrump()
{
	int threshold = 0;
	for (size_t i = 0; i < hand.size(); i++)
	{
		switch (hand[i]->GetType())
		{
		case Cards::DIAMONDS:
			threshold += 2;
			break;
		case Cards::HEARTS:
			threshold += 1;
			break;
		default:
			break;
		}
	}
	return threshold;
}
int Dealer::m_HeartsTrump()
{
	int threshold = 0;
	for (size_t i = 0; i < hand.size(); i++)
	{
		switch (hand[i]->GetType())
		{
		case Cards::HEARTS:
			threshold += 2;
			break;
		case Cards::DIAMONDS:
			threshold += 1;
			break;
		default:
			break;
		}
	}
	return threshold;
}
int Dealer::m_SpadesTrump()
{
	int threshold = 0;
	for (size_t i = 0; i < hand.size(); i++)
	{
		switch (hand[i]->GetType())
		{
		case Cards::SPADES:
			threshold += 2;
			break;
		case Cards::CLUBS:
			threshold += 1;
			break;
		default:
			break;
		}
	}
	return threshold;
}
int Dealer::m_ClubsTrump()
{
	int threshold = 0;
	for (size_t i = 0; i < hand.size(); i++)
	{
		switch (hand[i]->GetType())
		{
		case Cards::CLUBS:
			threshold += 2;
			break;
		case Cards::SPADES:
			threshold += 1;
			break;
		default:
			break;
		}
	}
	return threshold;
}
Cards::cardType Dealer::FavoredType()
{
	int threshHold = m_SpadesTrump();
	Cards::cardType type = Cards::SPADES;

	if (threshHold < m_DiamondsTrump())
	{
		threshHold = m_DiamondsTrump();
		type = Cards::DIAMONDS;
	}
	if (threshHold < m_HeartsTrump())
	{
		threshHold = m_HeartsTrump();
		type = Cards::HEARTS;
	}
	if (threshHold < m_ClubsTrump())
	{
		threshHold = m_ClubsTrump();
		type = Cards::CLUBS;
	}
	return type;

}

