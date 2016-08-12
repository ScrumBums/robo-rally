#ifndef DECK_H
#define DECK_H

#include <vector>
#include <string>
#include <fstream>
#include "ProgramCard.h"
#include "OptionCard.h"

enum DeckType { program = 0, option = 1 };
const std::string LIST_HEADER = "resources/lists/";

class Deck : public Object  {
	std::vector<Card> deck;
	
public:
	Deck(std::string spriteSheet, std::string cardList, sf::Vector2f pos, DeckType type)
		: Object(spriteSheet, pos, sf::Vector2i(0, 0), CARD_SOURCE_SIZE) { loadDeck(spriteSheet, cardList, pos, type); }
	~Deck() { unloadDeck(); }
	void deal() {};
	void shuffle() {};

private:
	void loadDeck(std::string spriteSheet, std::string cardList, sf::Vector2f pos, DeckType type);
	void unloadDeck() { deck.clear(); }
};

#endif // DECK_H
