#include "game/game.h"

int main()
{
	// begin a new game
	Game *game = new Game();
	// enter the main loop to start the game 
	int value = game->start();
	// free the memory
	delete game;

	return value;
}