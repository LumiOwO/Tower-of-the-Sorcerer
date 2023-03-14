#ifndef _HERO_H_
#define _HERO_H_

#include "../character/character.h"

// hero status
#define INIT_HEALTH			1000
#define INIT_ATTACK			10
#define INIT_DEFENCE		10
#define INIT_MONEY			0
#define INIT_EXP			0

class Hero: public Character
{
public:
	// enum for the direction
	enum Direction {
		UP, DOWN, LEFT, RIGHT
	};
	// enum for the fight state
	enum FightState {
		NO_FIGHT, WILL_FIGHT, FIGHTING
	};
private:
	// state of hero
	FightState fightState;
	bool waiting;
	// previous position
	int previousX;
	int previousY;
public:
	// constructor and destructor
	Hero();
	~Hero();
	// getters
	int getPreviousX();
	int getPreviousY();
	FightState getFightState();
	// setters
	void setFightState(FightState fightState);
	void setWaiting(bool waiting);
	// set the direction of the hero
	void setDirection(Direction direction);
	// get the direction of the hero
	Direction getDirection();
	// return whether the hero can react to the keyboard
	bool canMove();
	// @override the setter in class character
	void setPosition(int x, int y);
	void setPosition(Cell *cell);
};

#endif