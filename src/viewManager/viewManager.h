#ifndef _VIEWMANAGER_H_
#define _VIEWMANAGER_H_

// Graph_lib
#include "Graph_lib/Window.h"

#include "widgets/widgets.h"
#include "../dataManager/elements/elements.h"

#include <iostream>
using namespace std;

// window parameters
#define WIN_X					150
#define WIN_Y					80
#define WIN_WIDTH				1260
#define WIN_HEIGHT				720
#define GAME_TITLE				"魔塔"

// button parameters
#define GAMEBUTTON_X			480
#define GAMEBUTTON_Y			400
#define GAMEBUTTON_WIDTH		300
#define GAMEBUTTON_HEIGHT		80
#define GAMEBUTTON_INTERVAL		50

#define SMALLBUTTON_X			1210
#define SMALLBUTTON_Y			25
#define SMALLBUTTON_WIDTH		50
#define SMALLBUTTON_HEIGHT		50

#define FUNCBUTTON_X			1210
#define FUNCBUTTON_Y			643
#define FUNCBUTTON_WIDTH		50
#define FUNCBUTTON_HEIGHT		50

// key code
#define KEY_W					119
#define KEY_A					97
#define KEY_S					115
#define KEY_D					100
#define KEY_SPACE				32
#define KEY_UP					65362
#define KEY_DOWN				65364
#define KEY_LEFT				65361
#define KEY_RIGHT				65363
#define KEY_ESC					65307

// declare the Game class
// in order to avoid references to each other
class Game;

// use window in the Graph_lib namespace
class ViewManager : public Graph_lib::Window
{
private:
	// let the viewManager know the game
	Game *game;
	// window widgets
	MenuBar *menuBar;
	StatusBar *statusBar;
	ControlButton *musicButton;
	ControlButton *helpButton;
	// main menu widgets
	MainMenu *mainMenu;
	ControlButton *newGameButton;
	ControlButton *loadGameButton;
	// game widgets
	Scene *scene;
	InfoPanel *infoPanel;
	TalkingUI *talkingUI;
	ControlButton *saveButton;
	ControlButton *homeButton;
	ControlButton *transportButton;
	ControlButton *bookButton;

	// signal to know whether a UI is showing
	bool UIShowing;
public:
	// constructor and destructor
	ViewManager(Game *game);
	~ViewManager();
	// show the main menu
	void showMainMenu();
	// start the game
	void startPlaying();
	// draw the game map
	void drawScene(Map *map);
	// draw a certain cell
	void drawCell(Cell *cell);
	// draw the hero
	void drawHero(Hero *hero);
	// update info panel
	void updateHeroInfo(Hero *hero);
	void updateTowerLevel(int towerLevel);
	void updateKeys(int red, int blue, int yellow);
	// print current status
	void printStatus(string message);
	// talking UI interact
	bool isTalking();
	void showTalkingUI(TalkingUI *ui);
	void removeTalkingUI();
	// check whether UI is showing
	bool isUIShowing();
	// set UI showing status
	void setUIShowing(bool showing);

	// @override
	// event handler
	int handle(int event);
};

#endif