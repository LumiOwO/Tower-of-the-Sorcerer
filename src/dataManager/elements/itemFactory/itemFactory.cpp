#include "itemFactory.h"
#include "../../../resourceManager/resourceManager.h"

// items
Item* ItemFactory::getred_key(int x, int y)
{
	Item* ret = new Item(Cell::ID::RED_KEY);
	ret->setPhoto(ResourceManager::red_key);
	ret->setPosition(x, y);
	return ret;
}

Item* ItemFactory::getblue_key(int x, int y)
{
	Item* ret = new Item(Cell::ID::BLUE_KEY);
	ret->setPhoto(ResourceManager::blue_key);
	ret->setPosition(x, y);
	return ret;
}

Item* ItemFactory::getyellow_key(int x, int y)
{
	Item* ret = new Item(Cell::ID::YELLOW_KEY);
	ret->setPhoto(ResourceManager::yellow_key);
	ret->setPosition(x, y);
	return ret;
}

Item* ItemFactory::getsuper_key(int x, int y)
{
	Item* ret = new Item(Cell::ID::SUPER_KEY);
	ret->setPhoto(ResourceManager::super_key);
	ret->setPosition(x, y);
	return ret;
}


Item* ItemFactory::getred_potion(int x, int y)
{
	Item* ret = new Item(Cell::ID::RED_POTION);
	ret->setPhoto(ResourceManager::red_potion);
	ret->setPosition(x, y);
	return ret;
}

Item* ItemFactory::getblue_potion(int x, int y)
{
	Item* ret = new Item(Cell::ID::BLUE_POTION);
	ret->setPhoto(ResourceManager::blue_potion);
	ret->setPosition(x, y);
	return ret;
}

Item* ItemFactory::getsuper_potion(int x, int y)
{
	Item* ret = new Item(Cell::ID::SUPER_POTION);
	ret->setPhoto(ResourceManager::super_potion);
	ret->setPosition(x, y);
	return ret;
}


Item* ItemFactory::getred_crystal(int x, int y)
{
	Item* ret = new Item(Cell::ID::RED_CRYSTAL);
	ret->setPhoto(ResourceManager::red_crystal);
	ret->setPosition(x, y);
	return ret;
}

Item* ItemFactory::getblue_crystal(int x, int y)
{
	Item* ret = new Item(Cell::ID::BLUE_CRYSTAL);
	ret->setPhoto(ResourceManager::blue_crystal);
	ret->setPosition(x, y);
	return ret;
}


Item* ItemFactory::getsword_primary(int x, int y)
{
	Item* ret = new Item(Cell::ID::SWORD_PRIMARY);
	ret->setPhoto(ResourceManager::sword_primary);
	ret->setPosition(x, y);
	return ret;
}

Item* ItemFactory::getsword_medium(int x, int y)
{
	Item* ret = new Item(Cell::ID::SWORD_MEDIUM);
	ret->setPhoto(ResourceManager::sword_medium);
	ret->setPosition(x, y);
	return ret;
}

Item* ItemFactory::getsword_super(int x, int y)
{
	Item* ret = new Item(Cell::ID::SWORD_SUPER);
	ret->setPhoto(ResourceManager::sword_super);
	ret->setPosition(x, y);
	return ret;
}


Item* ItemFactory::getshield_primary(int x, int y)
{
	Item* ret = new Item(Cell::ID::SHIELD_PRIMARY);
	ret->setPhoto(ResourceManager::shield_primary);
	ret->setPosition(x, y);
	return ret;
}

Item* ItemFactory::getshield_medium(int x, int y)
{
	Item* ret = new Item(Cell::ID::SHIELD_MEDIUM);
	ret->setPhoto(ResourceManager::shield_medium);
	ret->setPosition(x, y);
	return ret;
}

Item* ItemFactory::getshield_super(int x, int y)
{
	Item* ret = new Item(Cell::ID::SHIELD_SUPER);
	ret->setPhoto(ResourceManager::shield_super);
	ret->setPosition(x, y);
	return ret;
}


Item* ItemFactory::getcoin(int x, int y)
{
	Item* ret = new Item(Cell::ID::COIN);
	ret->setPhoto(ResourceManager::coin);
	ret->setPosition(x, y);
	return ret;
}

Item* ItemFactory::getlevel_up(int x, int y)
{
	Item* ret = new Item(Cell::ID::LEVEL_UP);
	ret->setPhoto(ResourceManager::level_up);
	ret->setPosition(x, y);
	return ret;
}


// stairs
Stair* ItemFactory::getupstairs(int x, int y)
{
	Stair* ret = new Stair(Cell::ID::UPSTAIRS);
	ret->setPhoto(ResourceManager::upstairs);
	ret->setPosition(x, y);
	return ret;
}

Stair* ItemFactory::getdownstairs(int x, int y)
{
	Stair* ret = new Stair(Cell::ID::DOWNSTAIRS);
	ret->setPhoto(ResourceManager::downstairs);
	ret->setPosition(x, y);
	return ret;
}

Item* ItemFactory::getcross(int x, int y)
{
	Item* ret = new Item(Cell::ID::CROSS);
	ret->setPhoto(ResourceManager::cross);
	ret->setPosition(x, y);
	return ret;
}

Item* ItemFactory::getfire_wand(int x, int y) 
{
	Item* ret = new Item(Cell::ID::FIRE_WAND);
	ret->setPhoto(ResourceManager::fire_wand);
	ret->setPosition(x, y);
	return ret;
}

Item* ItemFactory::getice_wand(int x, int y) 
{
	Item* ret = new Item(Cell::ID::ICE_WAND);
	ret->setPhoto(ResourceManager::ice_wand);
	ret->setPosition(x, y);
	return ret;
}

Item* ItemFactory::getearth_wand(int x, int y) 
{
	Item* ret = new Item(Cell::ID::EARTH_WAND);
	ret->setPhoto(ResourceManager::earth_wand);
	ret->setPosition(x, y);
	return ret;
}
