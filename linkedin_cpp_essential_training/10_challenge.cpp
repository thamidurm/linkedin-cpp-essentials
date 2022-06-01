#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include <exception>

class E : public std::exception
{
	const char* msg = nullptr;
	E();
public:
	E(const char* s) noexcept(true) : msg(s) {}
	const char* what() const noexcept(true) { return msg; }

};
enum Suit {
	Clubs = 'c', Diamonds = 'd', Hearts = 'h', Spades = 's'
};
enum Rank {
	Ace = 'A', Two = 2, Three, Four, Five, Six, Seven, Eight, Nine,
	Ten = 'T', Jack = 'J', Queen = 'Q', King = 'K'
};

constexpr int Suits = 4;
constexpr int Ranks = 13;
constexpr int CardsPerDeck = Suits * Ranks;
constexpr Suit suits[Suits] = { Clubs, Diamonds, Hearts, Spades };
constexpr Rank ranks[Ranks] = { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine,
	Ten, Jack, Queen, King };

class Card {
public:
	Card(Suit suit, Rank rank) : m_Suit(suit), m_Rank(rank) {

	}

	Rank rank() const {
		return m_Rank;
	}

	Suit suit() const {
		return m_Suit;
	}
private:
	Rank m_Rank;
	Suit m_Suit;
};

class Deck {
public:
	void newDeck(int n);
	void newDeck();

	void shuffleDeck();
	const Card& dealCard();
	int remaining();
	const std::vector<Card>& deck() const;
	std::vector<Card>& deck();
	int deckSize();

private:
	std::vector<Card> m_Cards;
	int m_decks;
};

void Deck::newDeck(int n)
{	
	m_decks = n;
	m_Cards.clear();
	for (int i = 0; i < m_decks; ++i)
	{
		for (auto suit : suits)
		{
			for (auto rank : ranks)
			{
				m_Cards.push_back(Card(suit, rank));
			}
		}
	}
	shuffleDeck();
}

int Deck::deckSize()
{
	return m_decks * CardsPerDeck;
}

void Deck::newDeck()
{
	newDeck(1);
}

void Deck::shuffleDeck()
{
	std::random_device r;
	std::seed_seq seed{ r(), r(), r(), r(), r(), r(), r(), r() };
	std::mt19937 eng(seed);
	std::shuffle(m_Cards.begin(), m_Cards.end(), eng);
}

std::vector<Card>& Deck::deck()
{
	return m_Cards;
}
const std::vector<Card>& Deck::deck() const
{
	return m_Cards;
}

int Deck::remaining() 
{
	return m_Cards.size();
}

const Card& Deck::dealCard() 
{

	if (!m_Cards.size())
	{
		throw E("Deck: Deck out of cards");
	}
	Card& card = m_Cards.back();
	m_Cards.pop_back();
	return card;
}

std::ostream& operator<<(std::ostream& ostream, const Card& card) {
	char rank = card.rank();
	
	if (2 <= card.rank() && card.rank() <= 9)
		rank = '0' + card.rank();

	ostream << rank << (char)card.suit();
	return ostream;
}

std::ostream& operator<<(std::ostream& ostream, const Deck& deck) {
	for (auto card : deck.deck())
		ostream << card << ' ';
	return ostream;
}

int main() {

	Deck deck;
	deck.newDeck(1);
	std::cout << (const Deck)deck << std::endl;
	std::cout << std::endl;
	for(int i = 0; i < 53; ++i)
	deck.dealCard();
	std::cout << (const Deck)deck << std::endl;
}