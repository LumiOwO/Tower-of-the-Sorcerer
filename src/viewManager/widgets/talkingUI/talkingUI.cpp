#include "talkingUI.h"
#include "../../../resourceManager/resourceManager.h"
#include "../../../game/game.h"

TalkingUI::TalkingUI(LinkedList<TradeButton*> buttons):
	Fl_Group(UI_X, UI_Y, UI_WIDTH, UI_HEIGHT),
	buttons(buttons)
{
	// begin to add widgets
	this->begin();
	// set style 
	this->box(FL_FLAT_BOX);
	this->color(ResourceManager::BackgroundColor);

	// add name box
	nameBox = new Fl_Box(
		UI_X,
		UI_Y,
		UI_WIDTH,
		NAMEBOX_HEIGHT
	);
	// set style
	nameBox->box(FL_NO_BOX);
	nameBox->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
	// set text font
	nameBox->labelsize(TITLESIZE);
	nameBox->labelcolor(FL_WHITE);
	nameBox->labelfont(ResourceManager::HeiTi);
	// add to the group
	this->add(nameBox);

	// add words box
	wordsBox = new TextDisplay(
		UI_X + UI_MARGIN,
		UI_Y + NAMEBOX_HEIGHT,
		UI_WIDTH - 2* UI_MARGIN,
		WORDSBOX_HEIGHT
	);
	// set color
	wordsBox->color(ResourceManager::BackgroundColor);
	// add to the group
	this->add(wordsBox);

	// add buttons
	int margin = (UI_WIDTH - BUTTON_WIDTH) / 2;
	int cnt = 0;
	for (Node<TradeButton*> *p = buttons.begin(); p; p = p->getNext())
	{
		TradeButton *button = p->getValue();
		button->resize(
			UI_X + margin,
			UI_Y + NAMEBOX_HEIGHT + WORDSBOX_HEIGHT + (cnt++) * (BUTTON_INTERVAL + BUTTON_HEIGHT),
			BUTTON_WIDTH,
			BUTTON_HEIGHT
		);
		this->add(button);
	}

	// finish adding widgets
	this->end();
	// when first create, it should not be shown
	this->hide();
}

TalkingUI::~TalkingUI()
{
	buttons.clear();
	delete nameBox;
	delete wordsBox;
}

void TalkingUI::updateText(string name, string words)
{
	nameBox->copy_label(name.data());
	wordsBox->setText(words.data());
}
