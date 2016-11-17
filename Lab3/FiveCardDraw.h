#pragma once
#include <iostream>
#include <memory>
#include "Deck.h"
#include "Player.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Game.h"
using namespace std;

//how to derive public inheritance
class FiveCardDraw : public Game {
public:
	FiveCardDraw();
	virtual int before_turn(Player);
protected:
	size_t dealer;
	Deck drawdeck;


};