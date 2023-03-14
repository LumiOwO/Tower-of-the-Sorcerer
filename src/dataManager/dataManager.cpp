#include "dataManager.h"
#include "../resourceManager/resourceManager.h"
#include "../game/game.h"

#include <fstream>
using namespace std;

DataManager::DataManager(Game *game)
{
	this->game = game;
	// init game
	initGameData();
}

DataManager::~DataManager()
{
	delete hero;
	for (Node<Map*> *p = maps.begin(); p; p = p->getNext())
		delete p->getValue();
	maps.clear();
}

Map* DataManager::getMap()
{
	return maps[towerLevel];
}

Hero* DataManager::getHero()
{
	return hero;
}

int DataManager::getTowerLevel()
{
	return towerLevel;
}

int DataManager::getHighestLevel()
{
	return highestLevel;
}

int DataManager::getRedKeys()
{
	return redKeys;
}

int DataManager::getBlueKeys()
{
	return blueKeys;
}

int DataManager::getYellowKeys()
{
	return yellowKeys;
}

LinkedList<Cell*> DataManager::getAnimeCells()
{
	return maps[towerLevel]->getAnimeCells();
}

LinkedList<Cell*> DataManager::getEnemies()
{
	return maps[towerLevel]->getEnemies();
}

Door* DataManager::getOpeningDoor()
{
	return maps[towerLevel]->getOpeningDoor();
}

Cell* DataManager::getCellAt(int x, int y)
{
	return maps[towerLevel]->getCellAt(x, y);
}

void DataManager::setMaps(LinkedList<Map*> maps)
{
	// clear the current map
	for (Node<Map*> *p = this->maps.begin(); p; p = p->getNext())
		delete p->getValue();
	this->maps.clear();

	// copy the content in the map pointer
	for (Node<Map*> *p = maps.begin(); p; p = p->getNext())
	{
		// push a copy of map into the container
		this->maps.push_back(Map::copyMap(p->getValue()));
	}
}

void DataManager::initGameData()
{
	// free memory of hero
	if (hero)
		delete hero;
	// init hero
	hero = new Hero();
	hero->setPosition(HERO_INITX, HERO_INITY);
	// init keys
	redKeys = blueKeys = yellowKeys = 0;
	// init towerlevel
	towerLevel = 0;
	// init highet level
	highestLevel = 0;
}

void DataManager::saveGameData()
{
	// save maps
	// construct the title of the save map
	string SavedMapTitle_prefix = "./res/save/map_";
	Map *nowMap;
	int cnt = 0;
	// begin to save each map
	for (Node<Map*> *p = maps.begin(); p; p = p->getNext())
	{
		nowMap = p->getValue();
		nowMap->saveMap(SavedMapTitle_prefix + to_string(cnt++));
	}

	// update the saved map in the resource
	for (Node<Map*> *p = ResourceManager::Saved_Maps.begin(); p; p = p->getNext())
		delete p->getValue();
	ResourceManager::Saved_Maps.clear();
	// copy the content in the map pointer
	for (Node<Map*> *p = maps.begin(); p; p = p->getNext())
	{
		// push a copy of map into the container
		ResourceManager::Saved_Maps.push_back(Map::copyMap(p->getValue()));
	}

	// save the info of hero
	saveHeroInfo();
	// print status
	game->printStatus("游戏进度已保存");
}

void DataManager::saveHeroInfo()
{
	// open a file to write
	ofstream *out = new ofstream("./res/save/info", ios::binary);
	// get list of data
	int infoList[] = {
		hero->getLevel(),
		hero->getHealth(),
		hero->getAttack(),
		hero->getDefence(),
		hero->getMoney(),
		hero->getExp(),
		hero->getCurrentX(),
		hero->getCurrentY(),
		towerLevel,
		highestLevel,
		redKeys,
		blueKeys,
		yellowKeys
	};
	int size = sizeof(infoList) / sizeof(int);
	// write each data
	for (int i = 0; i < size; i++)
		out->write((const char *)&infoList[i], sizeof(int));
	// close the file
	out->close();
}

void DataManager::loadHeroInfo()
{
	// set hero direction
	hero->setDirection(Hero::DOWN);
	// open the save file to read
	ifstream *in = new ifstream("./res/save/info", ios::binary);
	// state a buffer
	int buffer;
	// read level
	in->read((char*)&buffer, sizeof(int));
	hero->setLevel(buffer);

	// read health
	in->read((char*)&buffer, sizeof(int));
	hero->setHealth(buffer);

	// read attack
	in->read((char*)&buffer, sizeof(int));
	hero->setAttack(buffer);

	// read defence
	in->read((char*)&buffer, sizeof(int));
	hero->setDefence(buffer);

	// read money
	in->read((char*)&buffer, sizeof(int));
	hero->setMoney(buffer);

	// read exp
	in->read((char*)&buffer, sizeof(int));
	hero->setExp(buffer);

	// read position
	in->read((char*)&buffer, sizeof(int));
	int x = buffer;
	in->read((char*)&buffer, sizeof(int));
	int y = buffer;
	hero->setPosition(x, y);

	// read towerlevel
	in->read((char*)&buffer, sizeof(int));
	towerLevel = buffer;

	// read highest level
	in->read((char*)&buffer, sizeof(int));
	highestLevel = buffer;

	// read redkeys
	in->read((char*)&buffer, sizeof(int));
	redKeys = buffer;

	// read bluekeys
	in->read((char*)&buffer, sizeof(int));
	blueKeys = buffer;

	// read yellowkeys
	in->read((char*)&buffer, sizeof(int));
	yellowKeys = buffer;

	// close the file
	in->close();
}

void DataManager::moveHero(Hero::Direction direction)
{
	// compute the new position
	int x = hero->getCurrentX();
	int y = hero->getCurrentY();
	if (direction == Hero::UP)
		y--;
	else if (direction == Hero::DOWN)
		y++;
	else if (direction == Hero::LEFT)
		x--;
	else if (direction == Hero::RIGHT)
		x++;
	// interact with the destination cell
	// if out of bound or hero cannot move, don't change position
	if(!hero->canMove())
		;
	else if (!inBound(x, y))
	{
		// modify the photo of hero
		hero->setIndex(direction + 4);
	}
	else
	{
		// modify the photo of hero
		hero->setIndex(direction + 4);

		Cell *nowCell = getMap()->getCellAt(x, y);
		if (nowCell->getCellType() == Cell::ENEMY)
		{
			Enemy *enemy = (Enemy*)nowCell;
			if (hero->canDefeat(enemy))
			{
				// if can defeat the enemy
				// start a timer to fight with the enemy
				hero->setPosition(x, y);
				hero->setFightState(Hero::WILL_FIGHT);
				Timer *timer = new Timer(FIGHT_CLK, Game::handleFight);
				timer->start();
				game->printStatus("攻击敌人");
			}
		}
		else if (nowCell->getCellType() == Cell::BARRIER)
		{
			Barrier *barrier = (Barrier*)nowCell;
			// if the barrier can pass, go to the cell
			if (barrier->canPassIt())
				hero->setPosition(x, y);
		}
		else if (nowCell->getCellType() == Cell::DOOR)
		{
			Door *door = (Door*)nowCell;
			// try to open the door using keys
			door->tryToOpen(redKeys, blueKeys, yellowKeys);
			if (door->canPassIt())
			{
				// if the door is opened, start a timer to open the door
				Timer *timer = new Timer(DOOR_CLK, Game::handleDoorOpen);
				timer->start();
				game->updateInfo();
				// ensure the hero not moving while open the door
				hero->setWaiting(true);
				game->printStatus("门已被成功打开");
			}
		}
		else if (nowCell->getCellType() == Cell::ITEM)
		{
			Item *item = (Item*)nowCell;
			// move hero position
			hero->setPosition(x, y);
			// get effect for hero
			item->effect(this);
			// get the current map
			Map *map = getMap();
			// if the item is not stairs
			// remove the item in the map
			if (item->getCellID() == Cell::ID::UPSTAIRS)
				game->printStatus("进入下一层地图");
			else if (item->getCellID() == Cell::ID::DOWNSTAIRS)
				game->printStatus("进入上一层地图");
			else
			{
				map->removeItem(item);
				game->printStatus("获得道具");
			}
			// update view
			game->updateInfo();
			game->drawCell(map->getCellAt(x, y));
		}
	}
}

void DataManager::stopHero()
{
	// if the hero is moving
	// modify the photo of hero
	int index = hero->getIndex();
	if(index >= 4)
		hero->setIndex(index - 4);
}

bool DataManager::inBound(int x, int y)
{
	return (x >= 0 && x < Map::getMatrixWidth()) 
		&& (y >= 0 && y < Map::getMatrixWidth());
}

void DataManager::HeroBeginFight()
{
	// get map
	Map *map = maps[towerLevel];
	// get the enemy
	Enemy *enemy = (Enemy*)map->getCellAt(hero->getCurrentX(), hero->getCurrentY());
	// attack the enemy
	hero->attackEnemy(enemy);
	// adjust the fight state
	hero->setFightState(Hero::FIGHTING);
}

void DataManager::HeroStopFight()
{
	// get map
	Map *map = maps[towerLevel];
	// get the enemy
	Enemy *enemy = (Enemy*)map->getCellAt(hero->getCurrentX(), hero->getCurrentY());
	// if enemy is not dead, continue to fight
	if(!enemy->dead())
		hero->setFightState(Hero::WILL_FIGHT);
	// else, remove the enemy and stop fight
	else
	{
		// get extra damage from the enemy
		hero->getExtraDamageFrom(enemy);
		// get reward from the enemy
		hero->getRewardFrom(enemy);
		// update hero fight state
		hero->setFightState(Hero::NO_FIGHT);
		// if defeat the dragon, win the game
		if (enemy->getCellID() == Cell::ID::DRAGON)
			Game::openWinUI(nullptr, nullptr);
		// remove the enemy in the map
		map->removeEnemy(enemy);
	}
}

void DataManager::removeDoor(Door *door)
{
	// remove the door in the door list
	maps[towerLevel]->removeDoor(door);
	// make the hero can move again
	hero->setWaiting(false);
}

void DataManager::addKeys(int red, int blue, int yellow)
{
	redKeys += red;
	blueKeys += blue;
	yellowKeys += yellow;
}

void DataManager::goUpStairs()
{
	// go to next level
	towerLevel++;
	// update highest level
	if (towerLevel > highestLevel)
		highestLevel = towerLevel;
	// get current map
	Map *map = getMap();
	// get the downstair in current map
	Cell *down = map->getDownStair();
	// set hero position
	// if can find downstair, set the position to it
	if (down != nullptr)
		hero->setPosition(down);
	// else, it's on the init map, set the init position
	else
		hero->setPosition(HERO_INITX, HERO_INITY);
	// set hero direction
	hero->setDirection(Hero::DOWN);
	// redraw the map
	game->drawScene(map);
	// update the bgm
	ResourceManager::playBGM(towerLevel);
}

void DataManager::goDownStairs()
{
	// go to previous level
	towerLevel--;
	// get current map
	Map *map = getMap();
	// get the upstair in current map
	Cell *up = map->getUpStair();
	// set hero position
	hero->setPosition(up);
	// set hero direction
	hero->setDirection(Hero::DOWN);
	// redraw the map
	game->drawScene(map);
	// update the bgm
	ResourceManager::playBGM(towerLevel);
}

void DataManager::transportTo(int dst)
{
	towerLevel = dst - 1;
	goUpStairs();
}

TalkingUI* DataManager::talkToNPC()
{
	TalkingUI* ret = nullptr;
	// get hero position
	int x = hero->getCurrentX();
	int y = hero->getCurrentY();
	Hero::Direction direction = hero->getDirection();
	// find the cell in front of the hero
	if (direction == Hero::UP)
		y--;
	else if (direction == Hero::DOWN)
		y++;
	else if (direction == Hero::LEFT)
		x--;
	else if (direction == Hero::RIGHT)
		x++;
	// check if it's in bound
	if (inBound(x, y))
	{
		// check whether it's an NPC
		Cell *cell = getMap()->getCellAt(x, y);
		if (cell->getCellType() == Cell::NPC)
		{
			NPC *npc = (NPC*)cell;
			ret = npc->getTalkingUI();
			hero->setWaiting(true);
		}
	}
	return ret;
}

void DataManager::stopTalking()
{
	hero->setWaiting(false);
}

void DataManager::transaction(TradeButton::Currency currency, TradeButton::Goods goods, int cost, int gain)
{
	// check if the hero can afford the goods
	bool canAfford;
	if (currency == TradeButton::MONEY)
	{
		int left = hero->getMoney() - cost;
		canAfford = (left >= 0);
		if (canAfford)
			hero->setMoney(left);
	}
	else if (currency == TradeButton::EXP)
	{
		int left = hero->getExp() - cost;
		canAfford = (left >= 0);
		if (canAfford)
			hero->setExp(left);
	}
	else if (currency == TradeButton::RED)
	{
		int left = redKeys - cost;
		canAfford = (left >= 0);
		if (canAfford)
			redKeys = left;
	}
	else if (currency == TradeButton::BLUE)
	{
		int left = blueKeys - cost;
		canAfford = (left >= 0);
		if (canAfford)
			blueKeys = left;
	}
	else if (currency == TradeButton::YELLOW)
	{
		int left = yellowKeys - cost;
		canAfford = (left >= 0);
		if (canAfford)
			yellowKeys = left;
	}

	// if can afford, get the goods
	if (canAfford)
	{
		if (goods == TradeButton::HEALTH)
			hero->setHealth(hero->getHealth() + gain);
		else if (goods == TradeButton::ATTACK)
			hero->setAttack(hero->getAttack() + gain);
		else if (goods == TradeButton::DEFENCE)
			hero->setDefence(hero->getDefence() + gain);
		else if (goods == TradeButton::LEVEL)
			hero->levelUP(gain);
		else if (goods == TradeButton::REDKEY)
			redKeys += gain;
		else if (goods == TradeButton::BLUEKEY)
			blueKeys += gain;
		else if (goods == TradeButton::YELLOWKEY)
			yellowKeys += gain;
		else if (goods == TradeButton::COIN)
			hero->setMoney(hero->getMoney() + gain);

	}
}