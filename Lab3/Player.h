#pragma once
#include <iostream>
#include <string>
#include "Hand.h"

struct Player {
	Player(string name);
	string playerName;
	Hand playerHand;
	unsigned int handsLost;
	unsigned int handsWon;

};

ostream &operator <<(ostream &out, const Player &p);