#include "stdafx.h"
#include <iostream>
#include <memory>
#include "Deck.h"
#include "Card.h"
#include "Player.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "FiveCardDraw.h"
using namespace std;

int FiveCardDraw::before_turn(Player &p) {
	cout << p.playerName << " " << p.playerHand << " Which cards would you like to discard " << endl;
	return 0;
}
FiveCardDraw::FiveCardDraw() {
	dealer = 0;
	mainDeck = Deck();
	discardDeck = Deck();
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			Card c = Card(Suit(i), Rank(j));
			mainDeck.add_card(c);
		}
	}
}