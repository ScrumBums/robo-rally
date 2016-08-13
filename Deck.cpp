//  Deck Implementation File

#include "Deck.h"


//*************************************************************
//  Game Loop
void Deck::loadDeck(std::string spriteSheet, std::string cardList, sf::Vector2f pos, DeckType type) {
	std::string fullFilename = LIST_HEADER + cardList;
	std::fstream inFile(fullFilename.c_str());
	if (!inFile)
		std::cout << "Error Opening " << cardList << "\n\t\tTerminating Program\n", exit(EXIT_FAILURE);

	std::string buffer, cardText;
	std::stringstream ss;
	int cardQty;

	while (std::getline(inFile, buffer)) {
		ss << buffer;
		ss >> cardQty;
		std::getline(ss, cardText);

		if(type == DeckType::program)
			deck.push_back(ProgramCard(spriteSheet, pos, cardText, cardQty));
		else if (type == DeckType::option)
			deck.push_back(OptionCard(spriteSheet, pos, cardText, cardQty));
		ss.str("");
		ss.clear();
	}
	inFile.close();
}