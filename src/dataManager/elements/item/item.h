#ifndef _ITEM_H_
#define _ITEM_H_

#include "../cell/cell.h"

class DataManager;
class Item : public Cell
{
public:
	Item(ID id);
	~Item();
	// give effect to change data
	void effect(DataManager *dataManager);
};

typedef Item Stair;

#endif