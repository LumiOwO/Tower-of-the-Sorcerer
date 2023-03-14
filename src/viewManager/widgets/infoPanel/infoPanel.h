#ifndef _INFOPANEL_H_
#define _INFOPANEL_H_

#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>

#include "../../../dataManager/elements/hero/hero.h"

// widget parameters
#define INFOPANEL_Y			25
#define INFOPANEL_WIDTH		212
#define INFOPANEL_HEIGHT	671
#define LINE_HEIGHT			50
#define KEYBOX_WIDTH		100

#define TEXT_SIZE			30
#define MARGIN				5

class InfoPanel : public Fl_Group
{
private:
	// values to display
	int tower_level;
	int hero_level;
	int hero_health;
	int hero_attack;
	int hero_defence;
	int hero_money;
	int hero_exp;
	int redKeys;
	int blueKeys;
	int yellowKeys;
	// boxes to display the values
	Fl_Box* titleBox;
	Fl_Box* levelBox;
	Fl_Box* healthBox;
	Fl_Box* attackBox;
	Fl_Box* defenceBox;
	Fl_Box* moneyBox;
	Fl_Box* expBox;
	Fl_Box* redKeysBox;
	Fl_Box* blueKeysBox;
	Fl_Box* yellowKeysBox;
public:
	// constructor and destructor
	InfoPanel();
	~InfoPanel();
	// update value
	void updateTowerLevel(int towerLevel);
	void updateHeroInfo(Hero *hero);
	void updateKeys(int red, int blue, int yellow);
	// redraw value label
	void updateValueTexts();
};

#endif
