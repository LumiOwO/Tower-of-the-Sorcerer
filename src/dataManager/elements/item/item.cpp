#include "item.h"
#include "../../dataManager.h"

Item::Item(ID id):
	Cell(id, Type::ITEM)
{

}

Item::~Item()
{

}

void Item::effect(DataManager *dataManager)
{
	Hero *hero = dataManager->getHero();

	// items
	if (getCellID() == ID::RED_KEY)
		dataManager->addKeys(1, 0, 0);
	else if (getCellID() == ID::BLUE_KEY)
		dataManager->addKeys(0, 1, 0);
	else if (getCellID() == ID::YELLOW_KEY)
		dataManager->addKeys(0, 0, 1);
	else if (getCellID() == ID::SUPER_KEY)
		dataManager->addKeys(1, 1, 1);

	else if (getCellID() == ID::RED_POTION)
		hero->setHealth(hero->getHealth() + 200);
	else if (getCellID() == ID::BLUE_POTION)
		hero->setHealth(hero->getHealth() + 500);
	else if (getCellID() == ID::SUPER_POTION)
		hero->setHealth(hero->getHealth() * 2);

	else if (getCellID() == ID::RED_CRYSTAL)
		hero->setAttack(hero->getAttack() + 3);
	else if (getCellID() == ID::BLUE_CRYSTAL)
		hero->setDefence(hero->getDefence() + 3);

	else if (getCellID() == ID::SWORD_PRIMARY)
		hero->setAttack(hero->getAttack() + 10);
	else if (getCellID() == ID::SWORD_MEDIUM)
		hero->setAttack(hero->getAttack() + 70); 
	else if (getCellID() == ID::SWORD_SUPER)
		hero->setAttack(hero->getAttack() + 150);

	else if (getCellID() == ID::SHIELD_PRIMARY)
		hero->setDefence(hero->getDefence() + 10); 
	else if (getCellID() == ID::SHIELD_MEDIUM)
		hero->setDefence(hero->getDefence() + 70);
	else if (getCellID() == ID::SHIELD_SUPER)
		hero->setDefence(hero->getDefence() + 150);


	else if (getCellID() == ID::COIN)
		hero->setMoney(hero->getMoney() + 300);
	else if (getCellID() == ID::LEVEL_UP)
		hero->levelUP(3);

	// special
	else if (getCellID() == ID::CROSS)
	{
		hero->setAttack(hero->getAttack() * 4 / 3);
		hero->setDefence(hero->getDefence() * 4 / 3);
		hero->setHealth(hero->getHealth() * 4 / 3);
	}
	else if (getCellID() == ID::FIRE_WAND)
		hero->setAttack(hero->getAttack() * 5 / 3);
	else if (getCellID() == ID::ICE_WAND)
		hero->setDefence(hero->getDefence() * 5 / 3);
	else if (getCellID() == ID::EARTH_WAND)
		hero->setHealth(hero->getHealth() * 5 / 3);

	// stairs
	else if (getCellID() == ID::UPSTAIRS)
		dataManager->goUpStairs();
	else if (getCellID() == ID::DOWNSTAIRS)
		dataManager->goDownStairs();
}