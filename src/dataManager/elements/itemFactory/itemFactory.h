#ifndef _ITEMFACTORY_H_
#define _ITEMFACTORY_H_

#include "../item/item.h"

// static class
class ItemFactory
{
private:
	// make a private constructor 
	// to forbid others to create instance
	ItemFactory() {}
public:
	// items
	static Item* getred_key(int x, int y);
	static Item* getblue_key(int x, int y);
	static Item* getyellow_key(int x, int y);
	static Item* getsuper_key(int x, int y);

	static Item* getred_potion(int x, int y);
	static Item* getblue_potion(int x, int y);
	static Item* getsuper_potion(int x, int y);

	static Item* getred_crystal(int x, int y);
	static Item* getblue_crystal(int x, int y);

	static Item* getsword_primary(int x, int y);
	static Item* getsword_medium(int x, int y);
	static Item* getsword_super(int x, int y);

	static Item* getshield_primary(int x, int y);
	static Item* getshield_medium(int x, int y);
	static Item* getshield_super(int x, int y);

	static Item* getcoin(int x, int y);
	static Item* getlevel_up(int x, int y);

	// stairs
	static Stair* getupstairs(int x, int y);
	static Stair* getdownstairs(int x, int y);

	// special
	static Item* getcross(int x, int y);
	static Item* getfire_wand(int x, int y);
	static Item* getice_wand(int x, int y);
	static Item* getearth_wand(int x, int y);

};

#endif
