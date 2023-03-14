#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include <string>
using namespace std;

#include "../cell/cell.h"

class Character: public Cell
{
private:
	// character status
	int health;
	int attack;
	int defence;
	int money;
	int exp;
	string name;
	string expression;
	int level;
public:
	// constructor and destructor
	Character(
		ID id,
		Type type,
		int health, 
		int attack, 
		int defence, 
		int money, 
		int exp, 
		string name = "", 
		string expression = "",
		int level = 1
	);
	virtual ~Character();

	// judge whether this character can defeat the input character
	// this function not change the value of this character
	bool canDefeat(Character *enemy) const;
	// attack the input enemy and change the value of this character
	void attackEnemy(Character *enemy);
	// get reward from the enemy
	void getRewardFrom(Character *enemy);
	// get extra damage from the enemy
	void getExtraDamageFrom(Character *enemy);
	// judge whether this character is dead
	bool dead();
	// judge whether this character can deal damage to the enemy
	bool canDamage(Character *enemy);
	// compute and return the damage to the enemy
	int getDamageTo(Character *enemy);
	// level up
	void levelUP(int levels);

	// getters
	int getLevel();
	int getHealth();
	int getAttack();
	int getDefence();
	int getMoney();
	int getExp();
	string getName();
	string getExpression();
	// setters
	void setLevel(int level);
	void setHealth(int health);
	void setAttack(int attack);
	void setDefence(int defence);
	void setMoney(int money);
	void setExp(int exp);
};
// rename for the enemy
typedef Character Enemy;

#endif