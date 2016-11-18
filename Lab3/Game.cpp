#include "stdafx.h"
#include "Game.h"
#include "FiveCardDraw.h"

shared_ptr<Game> Game::instance(){
	if (games == NULL) {
		throw instance_not_available;
	}
	else {
		shared_ptr<Game> gamesCopy = games;
		return gamesCopy;
	}
}

void Game::start_game(const string s)
{
	if (games != NULL) {
		throw game_already_started;
	}
	else if (s != "FiveCardDraw") {
		throw unknown_game;
	}
	else {
		games = make_shared<FiveCardDraw>(FiveCardDraw());
	}
}

void Game::stop_game()
{
	if (games == NULL) {
		throw no_game_in_progress;
	}
	else {
		games = NULL;
	}
}

shared_ptr<Player> Game::add_player(const string padd)

{
	if (find_player(padd) == 0) {
		//player doesn't exist, sso we add.
		//make a regular pointer first and then the shared pointer off of the regular


		Player * newp2 = new Player(padd);
		shared_ptr<Player> sharedP = shared_ptr<Player>(newp2);
		//newplayer = new Player (padd);
		players.push_back(sharedP);
		return sharedP;
	}
	else {
		//they do exist, throw an exception
		//make enumeration
		throw;
		//already_playing;
	}
	return shared_ptr<Player>();
}

shared_ptr<Player> Game::find_player(const string pfind)
{
	for (unsigned int i = 0; i < players.size(); i++) {
		//might need string compare
		if ((*players[i]).playerName == pfind) {
			return players[i];
		}
	}
	//address for any singular pointer
	return 0;

}
Game::~Game() {
	cout << "Game has been deleted " << endl;
}
/*int Game::before_turn(Player &) {
	cout << "Game class before turn has been called " << endl;
	return 0;
}
int Game::turn(Player &) {
	cout << "Game class turn has been called " << endl;
	return 0;
}
int Game::after_turn(Player &) {
	cout << "Game class after turn has been called " << endl;
	return 0;
}
int Game::before_round() {
	cout << "Game class before round has been called " << endl;
	return 0;
}
int Game::round() {
	cout << "Game class round has been called " << endl;
	return 0;
}
int Game::after_round() {
	cout << "Game after round has been called " << endl;
	return 0;
}*/
