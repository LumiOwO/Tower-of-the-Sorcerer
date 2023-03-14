#ifndef _DATAMANAGER_H_
#define _DATAMANAGER_H_

#include "elements/elements.h"
#include "../viewManager/widgets/widgets.h"

// hero init position
#define HERO_INITX			5
#define HERO_INITY			10

// declare the Game class
// in order to avoid references to each other
class Game;

class DataManager
{
private:
	// pointer to game
	Game *game;
	// game info 
	// tower level
	int towerLevel;
	// the highest level hero has entered
	int highestLevel;
	// maps
	LinkedList<Map*> maps;
	// hero
	Hero *hero;
	// keys
	int redKeys;
	int blueKeys;
	int yellowKeys;
public:
	// constructor and destructor
	DataManager(Game *game);
	~DataManager();
	// getters
	Map* getMap();
	Hero* getHero();
	int getTowerLevel();
	int getHighestLevel();
	int getRedKeys();
	int getBlueKeys();
	int getYellowKeys();
	// return the anime cells in the map
	LinkedList<Cell*> getAnimeCells();
	// return the enemies in the map
	LinkedList<Cell*> getEnemies();
	// return the door that is going to open
	Door* getOpeningDoor();
	// return the cell at (x, y)
	Cell* getCellAt(int x, int y);
	// setters
	void setMaps(LinkedList<Map*> maps);

	// init game data
	void initGameData();
	// save game data
	void saveGameData();
	// save the info of hero
	void saveHeroInfo();
	// load data
	void loadHeroInfo();

	// hero movement control
	void moveHero(Hero::Direction direction);
	void stopHero();
	// judge whether the new position is in the map
	bool inBound(int x, int y);
	// control the hero to fight with enemy
	void HeroBeginFight();
	void HeroStopFight();
	// open the given door and modify relevant data
	void removeDoor(Door *door);

	// item effects
	void addKeys(int red, int blue, int yellow);
	// map change
	void goUpStairs();
	void goDownStairs();
	void transportTo(int dst);

	// npc interact
	TalkingUI* talkToNPC();
	void stopTalking();
	// button callback
	void transaction(TradeButton::Currency currency, TradeButton::Goods goods, int cost, int gain);
};

#endif