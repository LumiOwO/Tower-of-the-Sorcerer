#include "enemyFactory.h"
#include "../../../resourceManager/resourceManager.h"

// enemy
Enemy* EnemyFactory::getgreen_slime(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::GREEN_SLIME,
		Cell::ENEMY,
		50, 20, 1, 1, 1,
		"绿色史莱姆"
	);
	ret->setPhotos(ResourceManager::green_slime);
	ret->setPosition(x, y);
	return ret;
}

Enemy* EnemyFactory::getred_slime(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::RED_SLIME,
		Cell::ENEMY,
		70, 15, 2, 2, 2,
		"红色史莱姆"
	);
	ret->setPhotos(ResourceManager::red_slime);
	ret->setPosition(x, y);
	return ret;
}

Enemy* EnemyFactory::getghost_slime(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::GHOST_SLIME,
		Cell::ENEMY,
		200, 35, 10, 5, 5,
		"幽灵史莱姆"
	);
	ret->setPhotos(ResourceManager::ghost_slime);
	ret->setPosition(x, y);
	return ret;
}

Enemy* EnemyFactory::getbig_slime(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::BIG_SLIME,
		Cell::ENEMY,
		700, 250, 125, 32, 30,
		"大史莱姆"
	);
	ret->setPhotos(ResourceManager::big_slime);
	ret->setPosition(x, y);
	return ret;
}


Enemy* EnemyFactory::getsmall_bat(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::SMALL_BAT,
		Cell::ENEMY,
		100, 20, 5, 3, 3,
		"小蝙蝠"
	);
	ret->setPhotos(ResourceManager::small_bat);
	ret->setPosition(x, y);
	return ret;
}

Enemy* EnemyFactory::getbig_bat(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::BIG_BAT,
		Cell::ENEMY,
		150, 65, 30, 10, 8,
		"大蝙蝠"
	);
	ret->setPhotos(ResourceManager::big_bat);
	ret->setPosition(x, y);
	return ret;
}

Enemy* EnemyFactory::getred_bat(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::RED_BAT,
		Cell::ENEMY,
		550, 160, 90, 25, 20,
		"吸血蝙蝠"
	);
	ret->setPhotos(ResourceManager::red_bat);
	ret->setPosition(x, y);
	return ret;
}


Enemy* EnemyFactory::getskeleton(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::SKELETON,
		Cell::ENEMY,
		110, 25, 5, 5, 4,
		"骷髅怪"
	);
	ret->setPhotos(ResourceManager::skeleton);
	ret->setPosition(x, y);
	return ret;
}

Enemy* EnemyFactory::getskeleton_warrior(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::SKELETON_WARRIOR,
		Cell::ENEMY,
		150, 40, 20, 8, 6,
		"骷髅战士"
	);
	ret->setPhotos(ResourceManager::skeleton_warrior);
	ret->setPosition(x, y);
	return ret;
}

Enemy* EnemyFactory::getskeleton_captain(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::SKELETON_CAPTAIN,
		Cell::ENEMY,
		400, 90, 50, 15, 12,
		"骷髅队长"
	);
	ret->setPhotos(ResourceManager::skeleton_captain);
	ret->setPosition(x, y);
	return ret;
}

Enemy* EnemyFactory::getskeleton_armored(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::SKELETON_ARMORED,
		Cell::ENEMY,
		2500, 900, 850, 84, 75,
		"骷髅骑士"
	);
	ret->setPhotos(ResourceManager::skeleton_armored);
	ret->setPosition(x, y);
	return ret;
}


Enemy* EnemyFactory::getorc(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::ORC,
		Cell::ENEMY,
		300, 75, 45, 13, 10,
		"兽人"
	);
	ret->setPhotos(ResourceManager::orc);
	ret->setPosition(x, y);
	return ret;
}

Enemy* EnemyFactory::getorc_warrior(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::ORC_WARRIOR,
		Cell::ENEMY,
		900, 450, 330, 50, 50,
		"兽人战士"
	);
	ret->setPhotos(ResourceManager::orc_warrior);
	ret->setPosition(x, y);
	return ret;
}


Enemy* EnemyFactory::getwizard(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::WIZARD,
		Cell::ENEMY,
		125, 50, 25, 10, 7,
		"巫师"
	);
	ret->setPhotos(ResourceManager::wizard);
	ret->setPosition(x, y);
	return ret;
}

Enemy* EnemyFactory::getred_wizard(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::RED_WIZARD,
		Cell::ENEMY,
		100, 200, 110, 30, 25,
		"血色巫师"
	);
	ret->setPhotos(ResourceManager::red_wizard);
	ret->setPosition(x, y);
	return ret;
}


Enemy* EnemyFactory::getmage(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::MAGE,
		Cell::ENEMY,
		250, 120, 70, 20, 17,
		"神秘法师",
		"与之战斗结束后，你的生命值会立刻减少100点"
	);
	ret->setPhotos(ResourceManager::mage);
	ret->setPosition(x, y);
	return ret;
}

Enemy* EnemyFactory::getred_mage(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::RED_MAGE,
		Cell::ENEMY,
		500, 400, 260, 47, 45,
		"神秘主教",
		"与之战斗结束后，你的生命值会立刻减少300点"
	);
	ret->setPhotos(ResourceManager::red_mage);
	ret->setPosition(x, y);
	return ret;
}


Enemy* EnemyFactory::gethead_monster(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::HEAD_MONSTER,
		Cell::ENEMY,
		500, 115, 65, 15, 15,
		"石头怪"
	);
	ret->setPhotos(ResourceManager::head_monster);
	ret->setPosition(x, y);
	return ret;
}


Enemy* EnemyFactory::getdual_blade(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::DUAL_BLADE,
		Cell::ENEMY,
		1200, 620, 520, 65, 75,
		"双刃战士"
	);
	ret->setPhotos(ResourceManager::dual_blade);
	ret->setPosition(x, y);
	return ret;
}


Enemy* EnemyFactory::getgolden_guard(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::GOLDEN_GUARD,
		Cell::ENEMY,
		450, 150, 90, 22, 19,
		"黄金守卫"
	);
	ret->setPhotos(ResourceManager::golden_guard);
	ret->setPosition(x, y);
	return ret;
}

Enemy* EnemyFactory::getblue_guard(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::BLUE_GUARD,
		Cell::ENEMY,
		1250, 500, 400, 55, 55,
		"蓝色守卫"
	);
	ret->setPhotos(ResourceManager::blue_guard);
	ret->setPosition(x, y);
	return ret;
}

Enemy* EnemyFactory::getred_guard(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::RED_GUARD,
		Cell::ENEMY,
		1500, 560, 460, 60, 60,
		"红色守卫"
	);
	ret->setPhotos(ResourceManager::red_guard);
	ret->setPosition(x, y);
	return ret;
}


Enemy* EnemyFactory::getred_knight(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::RED_KNIGHT,
		Cell::ENEMY,
		900, 750, 650, 77, 70,
		"红莲骑士"
	);
	ret->setPhotos(ResourceManager::red_knight);
	ret->setPosition(x, y);
	return ret;
}

Enemy* EnemyFactory::getyellow_knight(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::YELLOW_KNIGHT,
		Cell::ENEMY,
		850, 350, 200, 45, 40,
		"黄金骑士"
	);
	ret->setPhotos(ResourceManager::yellow_knight);
	ret->setPosition(x, y);
	return ret;
}

Enemy* EnemyFactory::getblue_knight(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::BLUE_KNIGHT,
		Cell::ENEMY,
		1300, 300, 150, 40, 35,
		"蓝色骑士",
		"与之战斗结束后，你会立刻丢失1/4的生命值"
	);
	ret->setPhotos(ResourceManager::blue_knight);
	ret->setPosition(x, y);
	return ret;
}

Enemy* EnemyFactory::getarmored_knight(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::ARMORED_KNIGHT,
		Cell::ENEMY,
		2000, 680, 590, 70, 65,
		"武装骑士"
	);
	ret->setPhotos(ResourceManager::armored_knight);
	ret->setPosition(x, y);
	return ret;
}

Enemy* EnemyFactory::getghost_knight(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::GHOST_KNIGHT,
		Cell::ENEMY,
		1600, 1306, 1200, 117, 100,
		"幽灵骑士"
	);
	ret->setPhotos(ResourceManager::ghost_knight);
	ret->setPosition(x, y);
	return ret;
}

Enemy* EnemyFactory::getghost_knight_captain(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::GHOST_KNIGHT_CAPTAIN,
		Cell::ENEMY,
		2000, 1106, 973, 106, 93,
		"幽灵法师",
		"与之战斗结束后，你会立刻丢失1/3的生命值"
	);
	ret->setPhotos(ResourceManager::ghost_knight_captain);
	ret->setPosition(x, y);
	return ret;
}


Enemy* EnemyFactory::getgreen_ghost(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::GREEN_GHOST,
		Cell::ENEMY,
		3100, 1150, 1050, 92, 80,
		"影子战士"
	);
	ret->setPhotos(ResourceManager::green_ghost);
	ret->setPosition(x, y);
	return ret;
}


Enemy* EnemyFactory::getred_lord(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::RED_LORD,
		Cell::ENEMY,
		15000, 1000, 1000, 100, 100,
		"血色魔王"
	);
	ret->setPhotos(ResourceManager::red_lord);
	ret->setPosition(x, y);
	return ret;
}

Enemy* EnemyFactory::getghost_lord(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::GHOST_LORD,
		Cell::ENEMY,
		30000, 1700, 1500, 250, 220,
		"冥灵魔王"
	);
	ret->setPhotos(ResourceManager::ghost_lord);
	ret->setPosition(x, y);
	return ret;
}

Enemy* EnemyFactory::getdragon(int x, int y)
{
	Enemy* ret = new Enemy(
		Cell::ID::DRAGON,
		Cell::ENEMY,
		99999, 9999, 5000, 0, 0,
		"嗜血魔龙"
	);
	ret->setPhotos(ResourceManager::dragon);
	ret->setPosition(x, y);
	return ret;
}
