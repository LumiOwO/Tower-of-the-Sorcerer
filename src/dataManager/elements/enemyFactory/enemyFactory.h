#ifndef _ENEMYFACTORY_H_
#define _ENEMYFACTORY_H_

#include "../character/character.h"

// static class
class EnemyFactory
{
private:
	// make a private constructor 
	// to forbid others to create instance
	EnemyFactory() {}
public:
	// enemy
	static Enemy* getgreen_slime(int x, int y);
	static Enemy* getred_slime(int x, int y);
	static Enemy* getghost_slime(int x, int y);
	static Enemy* getbig_slime(int x, int y);

	static Enemy* getsmall_bat(int x, int y);
	static Enemy* getbig_bat(int x, int y);
	static Enemy* getred_bat(int x, int y);

	static Enemy* getskeleton(int x, int y);
	static Enemy* getskeleton_warrior(int x, int y);
	static Enemy* getskeleton_captain(int x, int y);
	static Enemy* getskeleton_armored(int x, int y);

	static Enemy* getorc(int x, int y);
	static Enemy* getorc_warrior(int x, int y);

	static Enemy* getwizard(int x, int y);
	static Enemy* getred_wizard(int x, int y);

	static Enemy* getmage(int x, int y);
	static Enemy* getred_mage(int x, int y);

	static Enemy* gethead_monster(int x, int y);

	static Enemy* getdual_blade(int x, int y);

	static Enemy* getgolden_guard(int x, int y);
	static Enemy* getblue_guard(int x, int y);
	static Enemy* getred_guard(int x, int y);

	static Enemy* getred_knight(int x, int y);
	static Enemy* getyellow_knight(int x, int y);
	static Enemy* getblue_knight(int x, int y);
	static Enemy* getarmored_knight(int x, int y);
	static Enemy* getghost_knight(int x, int y);
	static Enemy* getghost_knight_captain(int x, int y);

	static Enemy* getgreen_ghost(int x, int y);

	static Enemy* getred_lord(int x, int y);
	static Enemy* getghost_lord(int x, int y);
	static Enemy* getdragon(int x, int y);
};

#endif