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
using namespace std;
enum game_errors {instance_not_available, game_already_started, unknown_game, no_game_in_progress};


class Game {
public:
	Game() = default;
	~Game();
	//how to define instance not available
	static shared_ptr<Game> instance();
	static void start_game(const string);
	static void stop_game();
	shared_ptr<Player> add_player(const string);
	shared_ptr<Player> find_player(const string);
	virtual int before_turn(Player &);
	virtual int turn(Player &);
	virtual int after_turn(Player &);
	virtual int before_round();
	virtual int round();
	virtual int after_round();

protected:
	static std::shared_ptr<Game> games;
	Deck mainDeck;
	std::vector<shared_ptr<Player>> players;



};