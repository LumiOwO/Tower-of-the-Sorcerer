#include "enemyInfoBox.h"
#include "../../../resourceManager/resourceManager.h"
#include "../../../game/game.h"
#include <string>
using namespace std;

EnemyInfoBox::EnemyInfoBox(int x, int y, int w, int h, Enemy *enemy):
	Fl_Group(x, y, w, h)
{
	// compute the parameters for the widgets
	int TEXTBOX_HEIGHT = h / 3;
	int PHOTO_START_DY = (h - PHOTO_HEIGHT) / 2;
	int TEXTBOX_WIDTH = (w - TEXT_START_DX) / 3;
	// set style
	this->box(FL_NO_BOX);
	
	// begin adding widgets
	this->begin();

	// photoBox
	photoBox = new Fl_Box(
		x + PHOTO_START_DX,
		y + PHOTO_START_DY,
		PHOTO_WIDTH,
		PHOTO_HEIGHT
	);
	photoBox->box(FL_NO_BOX);
	photoBox->image(enemy->getPhoto());

	// nameBox
	nameBox = new Fl_Box(
		x + TEXT_START_DX,
		y,
		TEXTBOX_WIDTH * 3,
		TEXTBOX_HEIGHT
	);
	// set label text
	string name = enemy->getName() + "      " + enemy->getExpression();
	nameBox->copy_label(name.data());
	// set style
	nameBox->box(FL_NO_BOX);
	nameBox->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
	// set font
	nameBox->labelfont(ResourceManager::HeiTi);
	nameBox->labelcolor(FL_WHITE);
	nameBox->labelsize(TEXTBOX_TEXTSIZE);
	this->add(nameBox);

	// compute damage to hero
	Hero *hero = ResourceManager::game->getHero();
	// pointers to boxes used in loop
	Fl_Box** boxList[] = {
		&healthBox,
		&attackBox,
		&defenceBox,
		&damageBox,
		&moneyBox,
		&expBox
	};
	// text to display in each box
	string labelList[] = {
		"生命：",
		"攻击：",
		"防御：",
		"对你的伤害：",
		"金钱：",
		"经验："
	};
	string valueList[] = {
		to_string(enemy->getHealth()),
		to_string(enemy->getAttack()),
		to_string(enemy->getDefence()),
		to_string(enemy->getDamageTo(hero)),
		to_string(enemy->getMoney()),
		to_string(enemy->getExp())
	};
	int size = sizeof(boxList) / sizeof(boxList[0]);
	// deal with special case
	if (enemy->getCellID() == Cell::ID::DRAGON)
	{
		for (int i = 0; i < size; i++)
			valueList[i] = "???";
	}
	else if (!hero->canDamage(enemy))
		valueList[3] = "???";

	// add info boxes
	for (int i = 0; i < size; i++)
	{
		int line = i / 3;
		int column = i % 3;
		Fl_Box *box = new Fl_Box(
			x + TEXT_START_DX + column * TEXTBOX_WIDTH,
			y + (line + 1) * TEXTBOX_HEIGHT,
			TEXTBOX_WIDTH,
			TEXTBOX_HEIGHT
		);
		// set label text
		box->copy_label((labelList[i] + valueList[i]).data());
		// set style
		box->box(FL_NO_BOX);
		box->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
		// set font
		box->labelfont(ResourceManager::HeiTi);
		box->labelcolor(FL_WHITE);
		box->labelsize(TEXTBOX_TEXTSIZE);
		
		// add to the group
		*boxList[i] = box;
		this->add(box);
	}
	// finish adding widgets
	this->end();
}

EnemyInfoBox::~EnemyInfoBox()
{
	delete photoBox;
	delete nameBox;
	delete healthBox;
	delete attackBox;
	delete defenceBox;
	delete damageBox;
	delete moneyBox;
	delete expBox;
}
