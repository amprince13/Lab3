#include "stdafx.h"
#include "Player.h"
#include <fstream>
#include <sstream>
 

Player::Player(string input)
	:handsWon(0), handsLost(0), playerHand()
{
	playerName = input;
	ifstream ifs;
	ifs.open(input + ".txt");
	if (ifs.is_open()) {
		string line, word;
		while (getline(ifs, line)) {
			istringstream iss(line);
			if (iss >> word) {
				playerName = word;
			}
			if (iss >> word) {
				handsWon = stoi(word);
			}
			if (iss >> word) {
				handsLost = stoi(word);
			}
		}
	}
}

ostream &operator <<(ostream &out, const Player &p) {
	out << "Name: " << p.playerName << " Games won: " << p.handsWon << " Games Lost: " << p.handsLost;
	return out;
}

