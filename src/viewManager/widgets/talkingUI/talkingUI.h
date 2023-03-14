#ifndef _TALKING_UI_H_
#define _TALKING_UI_H_

#include "../../../linkedlist/linkedlist.h"
#include "../tradeButton/tradeButton.h"
#include "../textDisplay/textDisplay.h"

#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <iostream>
using namespace std;

#define TITLESIZE			25

#define UI_X				355
#define UI_Y				110
#define UI_WIDTH			550
#define UI_HEIGHT			500
#define UI_MARGIN			10

#define NAMEBOX_HEIGHT		80
#define WORDSBOX_HEIGHT		200

#define BUTTON_WIDTH		400
#define BUTTON_HEIGHT		50
#define BUTTON_INTERVAL		10

class TalkingUI: public Fl_Group
{
private:
	Fl_Box* nameBox;
	TextDisplay* wordsBox;
	LinkedList<TradeButton*> buttons;
public:
	TalkingUI(LinkedList<TradeButton*> buttons);
	~TalkingUI();

	// update the text in the talking UI
	void updateText(string name, string words);
};
#endif