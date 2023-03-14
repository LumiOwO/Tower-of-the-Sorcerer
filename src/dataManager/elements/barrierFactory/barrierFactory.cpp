#include "barrierFactory.h"
#include "../../../resourceManager/resourceManager.h"

// barriers
Barrier* BarrierFactory::getground(int x, int y)
{
	Barrier* ret = new Barrier(Cell::ID::GROUND, Cell::BARRIER, true);
	ret->setPhoto(ResourceManager::ground);
	ret->setPosition(x, y);
	return ret;
}

Barrier* BarrierFactory::getbrick_wall(int x, int y)
{
	Barrier* ret = new Barrier(Cell::ID::BRICK_WALL, Cell::BARRIER, false);
	ret->setPhoto(ResourceManager::brick_wall);
	ret->setPosition(x, y);
	return ret;
}

Barrier* BarrierFactory::getstar(int x, int y)
{
	Barrier* ret = new Barrier(Cell::ID::STAR, Cell::BARRIER, false);
	ret->setPhotos(ResourceManager::star);
	ret->setPosition(x, y);
	return ret;
}

Barrier* BarrierFactory::getlava(int x, int y)
{
	Barrier* ret = new Barrier(Cell::ID::LAVA, Cell::BARRIER, false);
	ret->setPhotos(ResourceManager::lava);
	ret->setPosition(x, y);
	return ret;
}


Barrier* BarrierFactory::getstone_left(int x, int y)
{
	Barrier* ret = new Barrier(Cell::ID::STONE_LEFT, Cell::BARRIER, false);
	ret->setPhotos(ResourceManager::stone_left);
	ret->setPosition(x, y);
	return ret;
}

Barrier* BarrierFactory::getstone_right(int x, int y)
{
	Barrier* ret = new Barrier(Cell::ID::STONE_RIGHT, Cell::BARRIER, false);
	ret->setPhotos(ResourceManager::stone_right);
	ret->setPosition(x, y);
	return ret;
}


Barrier* BarrierFactory::getdragon_nw(int x, int y)
{
	Barrier* ret = new Barrier(Cell::ID::DRAGON_NW, Cell::BARRIER, false);
	ret->setPhotos(ResourceManager::dragon_nw);
	ret->setPosition(x, y);
	return ret;
}

Barrier* BarrierFactory::getdragon_n(int x, int y)
{
	Barrier* ret = new Barrier(Cell::ID::DRAGON_N, Cell::BARRIER, false);
	ret->setPhotos(ResourceManager::dragon_n);
	ret->setPosition(x, y);
	return ret;
}

Barrier* BarrierFactory::getdragon_ne(int x, int y)
{
	Barrier* ret = new Barrier(Cell::ID::DRAGON_NE, Cell::BARRIER, false);
	ret->setPhotos(ResourceManager::dragon_ne);
	ret->setPosition(x, y);
	return ret;
}

Barrier* BarrierFactory::getdragon_w(int x, int y)
{
	Barrier* ret = new Barrier(Cell::ID::DRAGON_W, Cell::BARRIER, false);
	ret->setPhotos(ResourceManager::dragon_w);
	ret->setPosition(x, y);
	return ret;
}

Barrier* BarrierFactory::getdragon_m(int x, int y)
{
	Barrier* ret = new Barrier(Cell::ID::DRAGON_M, Cell::BARRIER, false);
	ret->setPhotos(ResourceManager::dragon_m);
	ret->setPosition(x, y);
	return ret;
}

Barrier* BarrierFactory::getdragon_e(int x, int y)
{
	Barrier* ret = new Barrier(Cell::ID::DRAGON_E, Cell::BARRIER, false);
	ret->setPhotos(ResourceManager::dragon_e);
	ret->setPosition(x, y);
	return ret;
}

Barrier* BarrierFactory::getdragon_sw(int x, int y)
{
	Barrier* ret = new Barrier(Cell::ID::DRAGON_SW, Cell::BARRIER, false);
	ret->setPhotos(ResourceManager::dragon_sw);
	ret->setPosition(x, y);
	return ret;
}

Barrier* BarrierFactory::getdragon_se(int x, int y)
{
	Barrier* ret = new Barrier(Cell::ID::DRAGON_SE, Cell::BARRIER, false);
	ret->setPhotos(ResourceManager::dragon_se);
	ret->setPosition(x, y);
	return ret;
}


// doors
Door* BarrierFactory::getauto_door(int x, int y)
{
	Door* ret = new Door(Cell::ID::AUTO_DOOR, Cell::DOOR, false);
	ret->setPhotos(ResourceManager::auto_door);
	ret->setPosition(x, y);
	return ret;
}

Door* BarrierFactory::getred_door(int x, int y)
{
	Door* ret = new Door(Cell::ID::RED_DOOR, Cell::DOOR, false);
	ret->setPhotos(ResourceManager::red_door);
	ret->setPosition(x, y);
	return ret;
}

Door* BarrierFactory::getblue_door(int x, int y)
{
	Door* ret = new Door(Cell::ID::BLUE_DOOR, Cell::DOOR, false);
	ret->setPhotos(ResourceManager::blue_door);
	ret->setPosition(x, y);
	return ret;
}

Door* BarrierFactory::getyellow_door(int x, int y)
{
	Door* ret = new Door(Cell::ID::YELLOW_DOOR, Cell::DOOR, false);
	ret->setPhotos(ResourceManager::yellow_door);
	ret->setPosition(x, y);
	return ret;
}
