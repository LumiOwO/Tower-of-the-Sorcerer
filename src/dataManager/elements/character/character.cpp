#include "character.h"

Character::Character(
	ID id,
	Type type,
	int health,
	int attack,
	int defence,
	int money,
	int exp,
	string name,
	string expression,
	int level
):
	Cell(id, type),
	health(health),
	attack(attack),
	defence(defence),
	money(money),
	exp(exp),
	name(name),
	expression(expression),
	level(level)
{

}

Character::~Character()
{

}

bool Character::canDefeat(Character *enemy) const
{
	bool ret;
	// compute the damage to the enemy in each fight
	int damageToEnemy = this->attack - enemy->defence;
	// if cannot damage the enemy, then cannot defeat it
	if (damageToEnemy <= 0)
		ret = false;
	else
	{
		// compute how many times you need to kill the enemy
		int fightTimes = enemy->health / damageToEnemy;
		// round up the fightTimes
		if (enemy->health % damageToEnemy != 0)
			fightTimes ++;
		// compute the damage to this character in each fight
		int damageToMe = enemy->attack - this->defence;
		if (damageToMe < 0)
			damageToMe = 0;
		// compute the total damage this character take
		int loseHealth = fightTimes * damageToMe;
		// judge whether the character will die
		if (loseHealth < this->health)
			ret = true;
		else
			ret = false;
	}
	return ret;
}

void Character::attackEnemy(Character* enemy)
{
	// before this function, it's ensured that
	// this character can defeat the enemy
	int damageToEnemy = this->attack - enemy->defence;
	int damageToMe = enemy->attack - this->defence;
	if (damageToMe < 0)
		damageToMe = 0;
	// begin to fight
	enemy->health -= damageToEnemy;
	if (enemy->health < 0)
		enemy->health = 0;
	// can defeat enemy, so the remain health > 0
	this->health -= damageToMe;
}

void Character::getRewardFrom(Character *enemy)
{
	this->money += enemy->money;
	this->exp += enemy->money;
}

void Character::getExtraDamageFrom(Character *enemy)
{
	// get extra damage from special enemy
	if (enemy->getCellID() == Cell::ID::MAGE)
		this->health -= 100;
	else if (enemy->getCellID() == Cell::ID::RED_MAGE)
		this->health -= 300;
	else if (enemy->getCellID() == Cell::ID::BLUE_KNIGHT)
		this->health -= this->health / 4;
	else if (enemy->getCellID() == Cell::ID::GHOST_KNIGHT_CAPTAIN)
		this->health -= this->health / 3;

	// ensure this character will not die
	if (this->health <= 0)
		this->health = 1;
}

bool Character::dead()
{
	return health == 0;
}

bool Character::canDamage(Character *enemy)
{
	return this->attack > enemy->defence;
}

int Character::getDamageTo(Character *enemy)
{
	int totalDamage = 0;
	if (enemy->canDamage(this))
	{
		int damageToEnemy = this->attack - enemy->defence;
		if (damageToEnemy < 0)
			damageToEnemy = 0;
		int damageToMe = enemy->attack - this->defence;

		// compute after how many times you will die
		int fightTimes = this->health / damageToMe;
		// round up the fightTimes
		if (this->health % damageToMe != 0)
			fightTimes++;
		// compute the damage 
		totalDamage = fightTimes * damageToEnemy;
	}
	
	return totalDamage;
}

void Character::levelUP(int levels)
{
	level += levels;
	health += 1000 * levels;
	attack += 10 * levels;
	defence += 10 * levels;
}

int Character::getLevel()
{
	return level;
}

int Character::getHealth()
{
	return health;
}

int Character::getAttack()
{
	return attack;
}

int Character::getDefence()
{
	return defence;
}

int Character::getMoney()
{
	return money;
}

int Character::getExp()
{
	return exp;
}

string Character::getName()
{
	return name;
}

string Character::getExpression()
{
	return expression;
}

void Character::setLevel(int level)
{
	this->level = level;
}

void Character::setHealth(int health)
{
	this->health = health;
}

void Character::setAttack(int attack)
{
	this->attack = attack;
}

void Character::setDefence(int defence)
{
	this->defence = defence;
}

void Character::setMoney(int money)
{
	this->money = money;
}

void Character::setExp(int exp)
{
	this->exp = exp;
}
