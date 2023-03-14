#include "infoPanel.h"
#include "../../../resourceManager/resourceManager.h"

InfoPanel::InfoPanel():
	Fl_Group(0, INFOPANEL_Y, INFOPANEL_WIDTH, INFOPANEL_HEIGHT)
{
	// init values
	tower_level = hero_level = hero_health = hero_attack = hero_defence 
		= hero_money = hero_exp = redKeys = blueKeys = yellowKeys = 0;

	// style
	this->box(FL_NO_BOX);
	// begin to add widgets
	this->begin();

	// titleBox
	titleBox = new Fl_Box(
		0,
		INFOPANEL_Y,
		INFOPANEL_WIDTH,
		LINE_HEIGHT
	);
	// style
	titleBox->box(FL_NO_BOX);
	titleBox->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
	// font
	titleBox->labelfont(ResourceManager::HeiTi);
	titleBox->labelcolor(FL_WHITE);
	titleBox->labelsize(TEXT_SIZE);

	// labels for hero info
	const char* labels[] = {
		"等级","生命","攻击","防御","金币","经验"
	};
	// get number of labels
	int num = sizeof(labels) / sizeof(labels[0]);
	for (int i = 0; i < num; i++)
	{
		Fl_Box *box = new Fl_Box(
			MARGIN,
			INFOPANEL_Y + (i+2) * LINE_HEIGHT,
			INFOPANEL_WIDTH / 3 - MARGIN,
			LINE_HEIGHT
		);
		// style
		box->box(FL_NO_BOX);
		box->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
		// text and font
		box->label(labels[i]);
		box->labelfont(ResourceManager::HeiTi);
		box->labelcolor(FL_WHITE);
		box->labelsize(TEXT_SIZE);
		// add label to the group
		this->add(box);
	}
	// to reduce the code, 
	// use an array to modify each box
	Fl_Box** boxes[] = {
		&levelBox, &healthBox, &attackBox, &defenceBox, &moneyBox, &expBox
	};
	for (int i = 0; i < num; i++)
	{
		Fl_Box *box = new Fl_Box(
			INFOPANEL_WIDTH / 3,
			INFOPANEL_Y + (i + 2) * LINE_HEIGHT,
			INFOPANEL_WIDTH / 3 * 2 - MARGIN,
			LINE_HEIGHT
		);
		// style
		box->box(FL_NO_BOX);
		box->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE);
		// font
		box->labelfont(ResourceManager::HeiTi);
		box->labelcolor(FL_WHITE);
		box->labelsize(TEXT_SIZE);
		// add label to the group
		this->add(box);
		// modify the box in the array
		*boxes[i] = box;
	}

	// key images boxes
	Fl_Image* keyImages[] = {
		ResourceManager::RedKeyTrans,
		ResourceManager::BlueKeyTrans,
		ResourceManager::YellowKeyTrans
	};
	int keyNum = sizeof(keyImages) / sizeof(keyImages[0]);
	// add key images
	for (int i = 0; i < keyNum; i++)
	{
		Fl_Box *box = new Fl_Box(
			INFOPANEL_WIDTH / keyNum * i,
			INFOPANEL_Y + (num + 3) * LINE_HEIGHT,
			INFOPANEL_WIDTH / keyNum,
			LINE_HEIGHT
		);
		// style
		box->box(FL_NO_BOX);
		// image
		box->image(keyImages[i]);
		// add label to the group
		this->add(box);
	}

	// to reduce the code, 
	// use an array to modify each keybox
	Fl_Box** keyBoxes[] = {
		&redKeysBox, &blueKeysBox, &yellowKeysBox
	};
	for (int i = 0; i < keyNum; i++)
	{
		Fl_Box *box = new Fl_Box(
			INFOPANEL_WIDTH / keyNum * i,
			INFOPANEL_Y + (num + 4) * LINE_HEIGHT,
			INFOPANEL_WIDTH / keyNum,
			LINE_HEIGHT
		);
		// style
		box->box(FL_NO_BOX);
		box->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
		// font
		box->labelfont(ResourceManager::HeiTi);
		box->labelcolor(FL_WHITE);
		box->labelsize(TEXT_SIZE);
		// add label to the group
		this->add(box);
		// modify the box in the array
		*keyBoxes[i] = box;
	}

	// finish add widgets
	this->end();

	// initial the label of value boxes
	updateValueTexts();

	// when first create, it should not be shown
	this->hide();
}

InfoPanel::~InfoPanel()
{
	this->clear();
}

void InfoPanel::updateTowerLevel(int towerLevel)
{
	this->tower_level = towerLevel;
}

void InfoPanel::updateHeroInfo(Hero *hero)
{
	hero_level = hero->getLevel();
	hero_health = hero->getHealth();
	hero_attack = hero->getAttack();
	hero_defence = hero->getDefence();
	hero_money = hero->getMoney();
	hero_exp = hero->getExp();
}

void InfoPanel::updateKeys(int red, int blue, int yellow)
{
	redKeys = red;
	blueKeys = blue;
	yellowKeys = yellow;
}

void InfoPanel::updateValueTexts()
{
	// set title
	string title = "魔塔第 " + to_string(tower_level) + " 层";
	titleBox->copy_label(title.c_str());
	// set values
	levelBox->copy_label(to_string(hero_level).data());
	healthBox->copy_label(to_string(hero_health).data());
	attackBox->copy_label(to_string(hero_attack).data());
	defenceBox->copy_label(to_string(hero_defence).data());
	moneyBox->copy_label(to_string(hero_money).data());
	expBox->copy_label(to_string(hero_exp).data());
	redKeysBox->copy_label(to_string(redKeys).data());
	blueKeysBox->copy_label(to_string(blueKeys).data());
	yellowKeysBox->copy_label(to_string(yellowKeys).data());

	// redraw all texts
	titleBox->redraw();
	levelBox->redraw();
	healthBox->redraw();
	attackBox->redraw();
	defenceBox->redraw();
	moneyBox->redraw();
	expBox->redraw();
	redKeysBox->redraw();
	blueKeysBox->redraw();
	yellowKeysBox->redraw();
}