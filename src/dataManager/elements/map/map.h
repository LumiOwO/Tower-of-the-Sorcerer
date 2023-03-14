#ifndef _MAP_H_
#define _MAP_H_

#define MATRIX_WIDTH	11

#include "../character/character.h"
#include "../barrier/barrier.h"
#include "../item/item.h"
#include "../../../linkedlist/linkedlist.h"

class Map
{
private:
	Cell* matrix[MATRIX_WIDTH][MATRIX_WIDTH];
	LinkedList<Cell*> animeCells;
	LinkedList<Cell*> doors;
	LinkedList<Cell*> enemies;
public:
	// constructor and destructor
	Map(string filename = "");
	~Map();
	// getters
	Cell* getCellAt(int i, int j);
	LinkedList<Cell*> getAnimeCells();
	LinkedList<Cell*> getEnemies();
	Door* getOpeningDoor();
	static int getMatrixWidth();
	// get the stairs in current map
	Cell *getUpStair();
	Cell *getDownStair();
	// load map from file
	void loadMap(string filename);
	// save map to file
	void saveMap(string filename);
	// remove the dead enemy and make the cell be ground 
	void removeEnemy(Enemy *enemy);
	// remove the opened door and make the cell be ground
	void removeDoor(Door *door);
	// remove the item and make the cell be ground
	void removeItem(Item *item);

	// copy the input map and return
	static Map* copyMap(Map *map);
	// choose what new cell to return by its id
	Cell *getNewCellByID(Cell::ID id, int x, int y);
	
};

#endif
