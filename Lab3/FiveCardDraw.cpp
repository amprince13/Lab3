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
	cout << p.playerName << " " << p.playerHand << " Which the indicies of cards would you like to discard " << endl;
	vector <int> indicies;
	int i;
	bool check = true;
	while (cin >> i) {
		if (i <= p.playerHand.size() && i >= 0) {
			indicies.push_back(i);
		}
		else { 
			check = false; 
			cout << "Please enter valid card indices" << endl;
			before_turn(p);
		}
	}
	sort(indicies.begin(), indicies.end());
	for (size_t i = indicies.size()-1; i >= 0; --i) {
		discardDeck.add_card(p.playerHand[i]);
		p.playerHand.remove_card(i);
	}
	return 0;
}
int FiveCardDraw::turn(Player &p) {
	bool hasShuffled = false;
	if (5 - p.playerHand.size() > (mainDeck.size() + discardDeck.size())) {
		return -1;
	}
	if (p.playerHand.size() == 5) {
		return 0;
	}
	else {
		for (int i = 0; i < 5- p.playerHand.size(); ++i) {
			if (mainDeck.size() != 0) {
				p.playerHand << mainDeck;
			}
			else {
				if (hasShuffled == false) {
					discardDeck.shuffle();
					hasShuffled = true;
				}
				p.playerHand << discardDeck;
			}
		}
	}
	return 0;
}
int FiveCardDraw::after_turn(Player &p) {
	cout << p.playerName << " " << p.playerHand << endl;
	return 0;
}
int FiveCardDraw::before_round() {
	return 0;
}
int FiveCardDraw::round() {
	return 0;
}
int FiveCardDraw::after_round() {
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