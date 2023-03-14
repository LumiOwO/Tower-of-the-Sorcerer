#include "map.h"
#include "../barrierFactory/barrierFactory.h"
#include "../enemyFactory/enemyFactory.h"
#include "../itemFactory/itemFactory.h"
#include "../npcFactory/npcFactory.h"
#include <fstream>

Map::Map(string filename)
{
	if (filename.length() > 0)
		loadMap(filename);
}

Map::~Map()
{

}

Cell* Map::getCellAt(int i, int j)
{
	return matrix[i][j];
}

LinkedList<Cell*> Map::getAnimeCells()
{
	return animeCells;
}

LinkedList<Cell*> Map::getEnemies()
{
	return enemies;
}

Door* Map::getOpeningDoor()
{
	Door *door = nullptr;
	for (Node<Cell*> *p = doors.begin(); p; p = p->getNext())
	{
		door = (Door*)p->getValue();
		if (door->canPassIt())
			break;
	}
	return door;
}

int Map::getMatrixWidth()
{
	return MATRIX_WIDTH;
}

Cell* Map::getUpStair()
{
	Cell *ret = nullptr;
	// find the upstair and return
	for (int i = 0; i < MATRIX_WIDTH; i++)
		for (int j = 0; j < MATRIX_WIDTH; j++)
			if (matrix[i][j]->getCellID() == Cell::ID::UPSTAIRS)
			{
				ret = matrix[i][j];
				break;
			}
	return ret;
}

Cell* Map::getDownStair()
{
	Cell *ret = nullptr;
	// find the downstair and return
	for (int i = 0; i < MATRIX_WIDTH; i++)
		for (int j = 0; j < MATRIX_WIDTH; j++)
			if (matrix[i][j]->getCellID() == Cell::ID::DOWNSTAIRS)
			{
				ret = matrix[i][j];
				break;
			}
	return ret;
}

void Map::loadMap(string filename)
{
	// open the file to read
	ifstream in(filename, ios::binary);
	// notice the matrix in file is the transpose matrix
	// of the matrix in the window
	for (int j = 0; j < MATRIX_WIDTH; j++)
		for (int i = 0; i < MATRIX_WIDTH; i++)
		{
			// buffer to read the id of current cell
			Cell::ID id;
			// read the id of current cell
			in.read((char*)&id, sizeof(id));
			// choose what cell to put into the matrix by its id
			matrix[i][j] = getNewCellByID(id, i, j);
		}
	in.close();
}

void Map::saveMap(string filename)
{
	// open the file to write
	ofstream out(filename, ios::binary);
	// notice the matrix in file is the transpose matrix
	// of the matrix in the window
	for (int j = 0; j < MATRIX_WIDTH; j++)
		for (int i = 0; i < MATRIX_WIDTH; i++)
		{
			// get the id of the cell
			Cell::ID id = getCellAt(i, j)->getCellID();
			// write the id into the file
			out.write((const char*)&id, sizeof(id));
		}
	out.close();
}

void Map::removeEnemy(Enemy *enemy)
{
	// get enemy position
	int x = enemy->getCurrentX();
	int y = enemy->getCurrentY();
	// remove the enemy in the linked list
	animeCells.remove(enemy);
	enemies.remove(enemy);
	// remove the enemy in the map
	matrix[x][y] = BarrierFactory::getground(x, y);
	// free the memory
	delete enemy;
}

void Map::removeDoor(Door *door)
{
	// get door position
	int x = door->getCurrentX();
	int y = door->getCurrentY();
	// remove the door in the linked list
	doors.remove(door);
	// remove the door in the map
	matrix[x][y] = BarrierFactory::getground(x, y);
	// free the memory
	delete door;
}

void Map::removeItem(Item *item)
{
	// get item position
	int x = item->getCurrentX();
	int y = item->getCurrentY();
	matrix[x][y] = BarrierFactory::getground(x, y);
	// free the memory
	delete item;
}

Map* Map::copyMap(Map *map)
{
	Map *ret = new Map();
	for (int i = 0; i < MATRIX_WIDTH; i++)
		for (int j = 0; j < MATRIX_WIDTH; j++)
		{
			// get the id of cell
			Cell::ID id = map->getCellAt(i, j)->getCellID();
			// get a new cell by id
			ret->matrix[i][j] = ret->getNewCellByID(id, i, j);
		}
	return ret;
}

Cell* Map::getNewCellByID(Cell::ID id, int x, int y)
{
	Cell *ret = nullptr;
	// barrier
	if (id == Cell::ID::GROUND)
	{
		ret = BarrierFactory::getground(x, y);
	}
	else if (id == Cell::ID::BRICK_WALL)
	{
		ret = BarrierFactory::getbrick_wall(x, y);
	}
	else if (id == Cell::ID::STAR)
	{
		ret = BarrierFactory::getstar(x, y);
		animeCells.push_back(ret);
	}
	else if (id == Cell::ID::LAVA)
	{
		ret = BarrierFactory::getlava(x, y);
		animeCells.push_back(ret);
	}

	else if (id == Cell::ID::STONE_LEFT)
	{
		ret = BarrierFactory::getstone_left(x, y);
		animeCells.push_back(ret);
	}
	else if (id == Cell::ID::STONE_RIGHT)
	{
		ret = BarrierFactory::getstone_right(x, y);
		animeCells.push_back(ret);
	}

	else if (id == Cell::ID::DRAGON_NW)
	{
		ret = BarrierFactory::getdragon_nw(x, y);
		animeCells.push_back(ret);
	}
	else if (id == Cell::ID::DRAGON_N)
	{
		ret = BarrierFactory::getdragon_n(x, y);
		animeCells.push_back(ret);
	}
	else if (id == Cell::ID::DRAGON_NE)
	{
		ret = BarrierFactory::getdragon_ne(x, y);
		animeCells.push_back(ret);
	}
	else if (id == Cell::ID::DRAGON_W)
	{
		ret = BarrierFactory::getdragon_w(x, y);
		animeCells.push_back(ret);
	}
	else if (id == Cell::ID::DRAGON_M)
	{
		ret = BarrierFactory::getdragon_m(x, y);
		animeCells.push_back(ret);
	}
	else if (id == Cell::ID::DRAGON_E)
	{
		ret = BarrierFactory::getdragon_e(x, y);
		animeCells.push_back(ret);
	}
	else if (id == Cell::ID::DRAGON_SW)
	{
		ret = BarrierFactory::getdragon_sw(x, y);
		animeCells.push_back(ret);
	}
	else if (id == Cell::ID::DRAGON_SE)
	{
		ret = BarrierFactory::getdragon_se(x, y);
		animeCells.push_back(ret);
	}
	// doors
	else if (id == Cell::ID::AUTO_DOOR)
	{
		ret = BarrierFactory::getauto_door(x, y);
		doors.push_back(ret);
	}
	else if (id == Cell::ID::RED_DOOR)
	{
		ret = BarrierFactory::getred_door(x, y);
		doors.push_back(ret);
	}
	else if (id == Cell::ID::BLUE_DOOR)
	{
		ret = BarrierFactory::getblue_door(x, y);
		doors.push_back(ret);
	}
	else if (id == Cell::ID::YELLOW_DOOR)
	{
		ret = BarrierFactory::getyellow_door(x, y);
		doors.push_back(ret);
	}
	// items
	else if (id == Cell::ID::RED_KEY)
	{
		ret = ItemFactory::getred_key(x, y);
	}
	else if (id == Cell::ID::BLUE_KEY)
	{
		ret = ItemFactory::getblue_key(x, y);
	}
	else if (id == Cell::ID::YELLOW_KEY)
	{
		ret = ItemFactory::getyellow_key(x, y);
	}
	else if (id == Cell::ID::SUPER_KEY)
	{
		ret = ItemFactory::getsuper_key(x, y);
	}

	else if (id == Cell::ID::RED_POTION)
	{
		ret = ItemFactory::getred_potion(x, y);
	}
	else if (id == Cell::ID::BLUE_POTION)
	{
		ret = ItemFactory::getblue_potion(x, y);
	}
	else if (id == Cell::ID::SUPER_POTION)
	{
		ret = ItemFactory::getsuper_potion(x, y);
	}

	else if (id == Cell::ID::RED_CRYSTAL)
	{
		ret = ItemFactory::getred_crystal(x, y);
	}
	else if (id == Cell::ID::BLUE_CRYSTAL)
	{
		ret = ItemFactory::getblue_crystal(x, y);
	}

	else if (id == Cell::ID::SWORD_PRIMARY)
	{
		ret = ItemFactory::getsword_primary(x, y);
	}
	else if (id == Cell::ID::SWORD_MEDIUM)
	{
		ret = ItemFactory::getsword_medium(x, y);
	}
	else if (id == Cell::ID::SWORD_SUPER)
	{
		ret = ItemFactory::getsword_super(x, y);
	}

	else if (id == Cell::ID::SHIELD_PRIMARY)
	{
		ret = ItemFactory::getshield_primary(x, y);
	}
	else if (id == Cell::ID::SHIELD_MEDIUM)
	{
		ret = ItemFactory::getshield_medium(x, y);
	}
	else if (id == Cell::ID::SHIELD_SUPER)
	{
		ret = ItemFactory::getshield_super(x, y);
	}

	else if (id == Cell::ID::COIN)
	{
		ret = ItemFactory::getcoin(x, y);
	}
	else if (id == Cell::ID::LEVEL_UP)
	{
		ret = ItemFactory::getlevel_up(x, y);
	}
	// stairs
	else if (id == Cell::ID::UPSTAIRS)
	{
		ret = ItemFactory::getupstairs(x, y);
	}
	else if (id == Cell::ID::DOWNSTAIRS)
	{
		ret = ItemFactory::getdownstairs(x, y);
	}
	// special
	else if (id == Cell::ID::CROSS)
	{
		ret = ItemFactory::getcross(x, y);
	}
	else if (id == Cell::ID::FIRE_WAND)
	{
		ret = ItemFactory::getfire_wand(x, y);
	}
	else if (id == Cell::ID::ICE_WAND)
	{
		ret = ItemFactory::getice_wand(x, y);
	}
	else if (id == Cell::ID::EARTH_WAND)
	{
		ret = ItemFactory::getearth_wand(x, y);
	}
	// enemy
	else if (id == Cell::ID::GREEN_SLIME)
	{
		ret = EnemyFactory::getgreen_slime(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}
	else if (id == Cell::ID::RED_SLIME)
	{
		ret = EnemyFactory::getred_slime(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}
	else if (id == Cell::ID::GHOST_SLIME)
	{
		ret = EnemyFactory::getghost_slime(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}
	else if (id == Cell::ID::BIG_SLIME)
	{
		ret = EnemyFactory::getbig_slime(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}

	else if (id == Cell::ID::SMALL_BAT)
	{
		ret = EnemyFactory::getsmall_bat(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}
	else if (id == Cell::ID::BIG_BAT)
	{
		ret = EnemyFactory::getbig_bat(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}
	else if (id == Cell::ID::RED_BAT)
	{
		ret = EnemyFactory::getred_bat(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}

	else if (id == Cell::ID::SKELETON)
	{
		ret = EnemyFactory::getskeleton(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}
	else if (id == Cell::ID::SKELETON_WARRIOR)
	{
		ret = EnemyFactory::getskeleton_warrior(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}
	else if (id == Cell::ID::SKELETON_CAPTAIN)
	{
		ret = EnemyFactory::getskeleton_captain(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}
	else if (id == Cell::ID::SKELETON_ARMORED)
	{
		ret = EnemyFactory::getskeleton_armored(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}

	else if (id == Cell::ID::ORC)
	{
		ret = EnemyFactory::getorc(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}
	else if (id == Cell::ID::ORC_WARRIOR)
	{
		ret = EnemyFactory::getorc_warrior(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}

	else if (id == Cell::ID::WIZARD)
	{
		ret = EnemyFactory::getwizard(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}
	else if (id == Cell::ID::RED_WIZARD)
	{
		ret = EnemyFactory::getred_wizard(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}

	else if (id == Cell::ID::MAGE)
	{
		ret = EnemyFactory::getmage(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}
	else if (id == Cell::ID::RED_MAGE)
	{
		ret = EnemyFactory::getred_mage(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}

	else if (id == Cell::ID::HEAD_MONSTER)
	{
		ret = EnemyFactory::gethead_monster(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}

	else if (id == Cell::ID::DUAL_BLADE)
	{
		ret = EnemyFactory::getdual_blade(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}

	else if (id == Cell::ID::GOLDEN_GUARD)
	{
		ret = EnemyFactory::getgolden_guard(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}
	else if (id == Cell::ID::BLUE_GUARD)
	{
		ret = EnemyFactory::getblue_guard(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}
	else if (id == Cell::ID::RED_GUARD)
	{
		ret = EnemyFactory::getred_guard(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}

	else if (id == Cell::ID::RED_KNIGHT)
	{
		ret = EnemyFactory::getred_knight(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}
	else if (id == Cell::ID::YELLOW_KNIGHT)
	{
		ret = EnemyFactory::getyellow_knight(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}
	else if (id == Cell::ID::BLUE_KNIGHT)
	{
		ret = EnemyFactory::getblue_knight(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}
	else if (id == Cell::ID::ARMORED_KNIGHT)
	{
		ret = EnemyFactory::getarmored_knight(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}
	else if (id == Cell::ID::GHOST_KNIGHT)
	{
		ret = EnemyFactory::getghost_knight(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}
	else if (id == Cell::ID::GHOST_KNIGHT_CAPTAIN)
	{
		ret = EnemyFactory::getghost_knight_captain(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}

	else if (id == Cell::ID::GREEN_GHOST)
	{
		ret = EnemyFactory::getgreen_ghost(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}

	else if (id == Cell::ID::RED_LORD)
	{
		ret = EnemyFactory::getred_lord(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}
	else if (id == Cell::ID::GHOST_LORD)
	{
		ret = EnemyFactory::getghost_lord(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}
	else if (id == Cell::ID::DRAGON)
	{
		ret = EnemyFactory::getdragon(x, y);
		animeCells.push_back(ret);
		enemies.push_back(ret);
	}
	// NPC
	else if (id == Cell::ID::FAIRY)
	{
		ret = NPCFactory::getfairy(x, y);
		animeCells.push_back(ret);
	}
	else if (id == Cell::ID::PRINCESS)
	{
		ret = NPCFactory::getprincess(x, y);
		animeCells.push_back(ret);
	}
	else if (id == Cell::ID::OLD_MAN_LEVEL5)
	{
		ret = NPCFactory::getold_man_level5(x, y);
		animeCells.push_back(ret);
	}
	else if (id == Cell::ID::OLD_MAN_LEVEL13)
	{
		ret = NPCFactory::getold_man_level13(x, y);
		animeCells.push_back(ret);
	}
	else if (id == Cell::ID::STONE_LEVEL3)
	{
		ret = NPCFactory::getstone_level3(x, y);
		animeCells.push_back(ret);
	}
	else if (id == Cell::ID::STONE_LEVEL11)
	{
		ret = NPCFactory::getstone_level11(x, y);
		animeCells.push_back(ret);
	}
	else if (id == Cell::ID::KEY_SELLER)
	{
		ret = NPCFactory::getkey_seller(x, y);
		animeCells.push_back(ret);
	}
	else if (id == Cell::ID::KEY_BUYER)
	{
		ret = NPCFactory::getkey_buyer(x, y);
		animeCells.push_back(ret);
	}

	return ret;
}