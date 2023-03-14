#ifndef _NPCFACTORY_H_
#define _NPCFACTORY_H_

#include "../npc/npc.h"

// static class
class NPCFactory
{
private:
	// make a private constructor 
	// to forbid others to create instance
	NPCFactory() {}
public:
	static NPC* getfairy(int x, int y);
	static NPC* getprincess(int x, int y);
	static NPC* getold_man_level5(int x, int y);
	static NPC* getold_man_level13(int x, int y);
	static NPC* getstone_level3(int x, int y);
	static NPC* getstone_level11(int x, int y);
	static NPC* getkey_seller(int x, int y);
	static NPC* getkey_buyer(int x, int y);
};

#endif