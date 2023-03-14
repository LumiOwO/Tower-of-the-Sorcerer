#ifndef _CELL_H_
#define _CELL_H_

#include <FL/Fl_Image.H>

#include "../../../linkedlist/linkedlist.h"

class Cell
{
public:
	// c++ 11 standard enum
	// declare a enum to represent the id of each node
	// each id is a int type
	// definition of the enum is after the Cell class
	enum class ID: int;
	enum Type {
		BARRIER, ENEMY, DOOR, ITEM, HERO, NPC
	};
private:
	// identification
	ID id;
	Type type;
	// photos
	LinkedList<Fl_Image*> photos;
	int index;
	bool viewedAllPhotos;
	// position
	int currentX;
	int currentY;
public:
	// constructor and destructor
	Cell(ID id, Type type);
	virtual ~Cell();

	// set the photos
	void setPhoto(Fl_Image* photo);
	void setPhotos(LinkedList<Fl_Image*> photos);
	// return the current photo of the cell
	Fl_Image* getPhoto();
	// judge whether all the photos have shown
	bool shownAllPhotos();
	// return the id of the cell
	ID getCellID();
	// return the type of the cell
	Type getCellType();
	// change the photo of the cell
	void changePhoto();
	// set the index of photos
	void setIndex(int index);
	// get the index of photos
	int getIndex();
	// judge whether the photo is the last one
	bool isFinalPhoto();
	// get position
	int getCurrentX();
	int getCurrentY();
	// set position
	virtual void setPosition(int x, int y);
	virtual void setPosition(Cell *cell);
};

// definition of the enum
enum class Cell::ID : int
{
	// barrier
	GROUND,
	BRICK_WALL,
	STAR,
	LAVA,

	STONE_LEFT,
	STONE_RIGHT,

	DRAGON_NW,
	DRAGON_N,
	DRAGON_NE,
	DRAGON_W,
	DRAGON_M,
	DRAGON_E,
	DRAGON_SW,
	DRAGON_SE,

	// doors
	AUTO_DOOR,
	RED_DOOR,
	BLUE_DOOR,
	YELLOW_DOOR,

	// items
	RED_KEY,
	BLUE_KEY,
	YELLOW_KEY,
	SUPER_KEY,

	RED_POTION,
	BLUE_POTION,
	SUPER_POTION,

	RED_CRYSTAL,
	BLUE_CRYSTAL,

	SWORD_PRIMARY,
	SWORD_MEDIUM,
	SWORD_SUPER,

	SHIELD_PRIMARY,
	SHIELD_MEDIUM,
	SHIELD_SUPER,

	COIN,
	LEVEL_UP,

	// stairs
	UPSTAIRS,
	DOWNSTAIRS,

	// enemy
	GREEN_SLIME,
	RED_SLIME,
	GHOST_SLIME,
	BIG_SLIME,

	SMALL_BAT,
	BIG_BAT,
	RED_BAT,

	SKELETON,
	SKELETON_WARRIOR,
	SKELETON_CAPTAIN,
	SKELETON_ARMORED,

	ORC,
	ORC_WARRIOR,

	WIZARD,
	RED_WIZARD,

	MAGE,
	RED_MAGE,

	HEAD_MONSTER,

	DUAL_BLADE,

	GOLDEN_GUARD,
	BLUE_GUARD,
	RED_GUARD,

	RED_KNIGHT,
	YELLOW_KNIGHT,
	BLUE_KNIGHT,
	ARMORED_KNIGHT,
	GHOST_KNIGHT,
	GHOST_KNIGHT_CAPTAIN,

	GREEN_GHOST,

	RED_LORD,
	GHOST_LORD,
	DRAGON,

	// NPC
	FAIRY,
	PRINCESS,
	OLD_MAN_LEVEL5,
	OLD_MAN_LEVEL13,
	STONE_LEVEL3,
	STONE_LEVEL11,
	KEY_SELLER,
	KEY_BUYER,

	// hero
	HERO,

	// special
	CROSS,
	FIRE_WAND,
	ICE_WAND,
	EARTH_WAND,
};

#endif