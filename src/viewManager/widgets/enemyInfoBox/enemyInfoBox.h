#ifndef _ENEMYINFOBOX_H_
#define _ENEMYINFOBOX_H_

#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>

#include "../../../dataManager/elements/character/character.h"

#define PHOTO_WIDTH			76
#define PHOTO_HEIGHT		61
#define PHOTO_START_DX		25

#define TEXT_START_DX		126

#define TEXTBOX_TEXTSIZE	20

class EnemyInfoBox: public Fl_Group
{
private:
	// photo of the enemy
	Fl_Box *photoBox;
	// name and expression
	Fl_Box *nameBox;
	// enemy info
	Fl_Box *healthBox;
	Fl_Box *attackBox;
	Fl_Box *defenceBox;
	Fl_Box *damageBox;
	Fl_Box *moneyBox;
	Fl_Box *expBox;
public:
	EnemyInfoBox(int x, int y, int w, int h, Enemy *enemy);
	~EnemyInfoBox();

};

#endif