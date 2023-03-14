#include "hero.h"
#include "../../../resourceManager/resourceManager.h"

Hero::Hero():
	Character(
		ID::HERO,
		Type::HERO,
		INIT_HEALTH,
		INIT_ATTACK,
		INIT_DEFENCE,
		INIT_MONEY,
		INIT_EXP
	)
{
	// init the info
	this->fightState = FightState::NO_FIGHT;
	this->waiting = false;
	// init the photos
	this->setPhotos(ResourceManager::HeroPhotos);
	// set the init direction
	this->setDirection(DOWN);
}

Hero::~Hero()
{

}

int Hero::getPreviousX()
{
	return previousX;
}

int Hero::getPreviousY()
{
	return previousY;
}

Hero::FightState Hero::getFightState()
{
	return fightState;
}

void Hero::setFightState(FightState fightState)
{
	this->fightState = fightState;
}

void Hero::setWaiting(bool waiting)
{
	this->waiting = waiting;
}

void Hero::setDirection(Direction direction)
{
	this->setIndex(direction);
}

Hero::Direction Hero::getDirection()
{
	int index = getIndex();
	index = index > 4 ? index - 4 : index;
	return (Direction)index;
}

bool Hero::canMove()
{
	return fightState == NO_FIGHT && !waiting;
}

void Hero::setPosition(int x, int y)
{
	// update previous position
	previousX = getCurrentX();
	previousY = getCurrentY();
	// update current position
	Character::setPosition(x, y);
}

void Hero::setPosition(Cell *cell)
{
	// update previous position
	previousX = getCurrentX();
	previousY = getCurrentY();
	// update current position
	Character::setPosition(cell);
}
