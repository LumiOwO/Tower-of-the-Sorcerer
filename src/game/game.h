#ifndef _GAME_H_
#define _GAME_H_

#include <FL/Fl.H>

#include "../dataManager/dataManager.h"
#include "../viewManager/viewManager.h"
#include "../timer/timer.h"

// refresh time
#define ANIME_CLK		0.5
#define DOOR_CLK		0.05
#define FIGHT_CLK		0.2
#define STATUS_CLK		2

class Game
{
public:
	enum GameState {
		MAIN_MENU, PLAYING
	};
private:
	GameState state;
	// members
	ViewManager *viewManager;
	DataManager *dataManager;

	Timer *Anime_Timer;
	Timer *Status_Timer;
public:
	// constructor and destructor
	Game();
	~Game();
	// get the state of the game
	GameState getState();
	
	// control functions
	// start the game
	int start();
	// show the main menu
	void showMainMenu();
	// start a new game
	void newGame();
	// load the saved game
	void loadGame();
	// hero movement control
	void moveHero(int keyCode);
	void stopHero();
	// update info panel
	void updateInfo();
	// draw one cell
	void drawCell(Cell *cell);
	// draw the map
	void drawScene(Map *map);
	// print the status
	void printStatus(string message);
	// anime control
	void startAnime();
	void stopAnime();
	// interact with npc
	void talkToNPC();
	void stopTalking();
	
	// function to handle the timer event
	static void handleAnime(void *data);
	static void handleFight(void *data);
	static void handleDoorOpen(void *data);
	static void handleStatus(void *data);

	// interacts with UI
	// transport
	void transportTo(int dst);
	// get the highest level of the hero
	int getHighestLevel();
	// get the hero
	Hero *getHero();
	// get the enemies in the current map
	LinkedList<Cell*> getEnemies();
	// get the main window
	ViewManager *getMainWindow();

	// static method to deal with button callback
	static void transaction(Fl_Widget *widget, void *data);
	static void startNewGame(Fl_Widget *widget, void *data);
	static void startLoadGame(Fl_Widget *widget, void *data);
	static void musicControl(Fl_Widget *widget, void *data);
	static void saveGame(Fl_Widget *widget, void *data);
	static void goMainMenu(Fl_Widget *widget, void *data);
	static void openHelpDoc(Fl_Widget *widget, void *data);
	static void openTransportUI(Fl_Widget *widget, void *data);
	static void openMonsterBook(Fl_Widget *widget, void *data);
	static void openWinUI(Fl_Widget *widget, void *data);

private:
	void initGame();
	void showGivenUI(Fl_Widget *ui);
	void hideGivenUI(Fl_Widget *ui);
};

#endif