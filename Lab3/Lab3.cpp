// Lab2DeckHands.cpp : Defines the entry point for the console application.
// Author: Daniel Finn 434967
// Contact: dmfinn@wustl.edu
// Description: Contains the main method for taking in a deck of cards, dealing 9 hands, and ranking them

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include "Card.h"
#include <string>
#include <vector>
#include <fstream>
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include <algorithm>
using namespace std;



int verifyParams(int argc, char * argv[], int &l) {
	if (argc == 1) {
		std::cout << "Usage: " << "Lab2DeckHands.cpp" << " file_name.txt  -shuffle (optional)" << std::endl;
		throw NO_COMMANDS_GIVEN;
	}
	if (argc > 3 || argc < 2) {
		std::cout << "Usage: " << "Lab2DeckHands.cpp" << " file_name.txt  -shuffle (optional)" << std::endl;
		throw TOO_MANY_COMMANDS;
	}
	if (argc == 3) {
		string p = argv[1];
		string p2 = argv[2];
		if (p == "-shuffle") {
			l = 2;
			return 0;
		}
		if (p2 == "-shuffle") {
			l = 1;
			return 0;
		}
		std::cout << "Usage: " << "Lab2DeckHands.cpp" << " file_name.txt  -shuffle (optional)" << std::endl;
		throw NO_SHUFFLE_FLAG;
	}
	string p = argv[1];
	if (argc == 2 && p == "-shuffle") {
		std::cout << "Usage: " << "Lab2DeckHands.cpp" << " file_name.txt  -shuffle (optional)" << std::endl;
		throw NO_FILE_NAME;
	}
	return 0;
}



int main(int argc, char* argv[])
{
	int fileLoc = 1;
	try {
		int v = verifyParams(argc, argv, fileLoc); // fileLoc is passed as a reference and will return where the filename is
	}
	catch (Error_Codes &e) { return e; };
	try {
		Deck d = Deck(argv[fileLoc]);
		if (argc == 3) { // if length is 3 we know that -shuffle has been passed, otherwise verifyParams would throw error
			d.shuffle();
		}
		vector<Hand> hands;	// Declare our vector of hands and generate the hands
		for (int i = 0; i < 9; i++) {
			Hand h = Hand();
			hands.push_back(h);
		}
		if (d.size() < 45) { // make sure we have enough cards to populate each hand
			std::cout << "Error: the input file must contain at least 45 valid cards" << std::endl;
			throw DECK_TOO_SMALL;
		}
		d.print(); // print out the whole deck before we deal it
		std::cout << std::endl;
		for (int i = 0; i < 5; i = i++) {
			for (int j = 0; j < 9; j++) {
				hands[j] << d;
			}
		}

		std::cout << "Printing Unsorted Hands: \n" << std::endl;
		for (int i = 0; i < 9; i++) {
			std::cout << "Hand " << i << " : " << hands[i] << std::endl;
		}

		std::sort(hands.begin(), hands.end());

		std::cout << "\n Printing hands sorted by card values: (low -> high) \n" << std::endl;
		for (int i = 0; i < 9; i++) {
			std::cout << "Hand " << i << " : " << hands[i] << " : " << hands[i].getRank() << std::endl;
		}

		std::sort(hands.begin(), hands.end(), poker_rank);

		std::cout << "\n Printing hands sorted by hand ranks: (high -> low) \n" << std::endl;
		for (int i = 0; i < 9; i++) {
			std::cout << "Hand " << i << " : " << hands[i] << " : " << hands[i].getRank() << std::endl;
		}
		Player A("Austin");
		cout << A << endl;

		return 0;

	}
	catch (Error_Codes &e) {
		return e;
	}


}

