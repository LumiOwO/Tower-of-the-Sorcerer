#ifndef _BOOKPANEL_H_
#define _BOOKPANEL_H_

#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>

#include "../../../linkedlist/linkedlist.h"
#include "../../../dataManager/elements/character/character.h"
#include "../enemyInfoBox/enemyInfoBox.h"

#define BOOK_X				262
#define BOOK_Y				110
#define BOOK_WIDTH			736
#define BOOK_HEIGHT			500

#define BOOK_BUTTONX		312
#define BOOK_BUTTONY		540
#define BOOK_BUTTONW		100
#define BOOK_BUTTONH		50
#define BOOK_BTN_TEXTSIZE	20
#define BOOK_BTN_INTERVAL	436

#define ENEMYBOX_H			135
#define DISPLAY_NUM			3

class BookPanel: public Fl_Group
{
private:
	EnemyInfoBox* boxes[DISPLAY_NUM];
	Fl_Button* nextPage;
	Fl_Button* prevPage;
	// list of enemies
	LinkedList<Cell*> enemies;
	// current showing page
	int nowPage;
public:
	BookPanel(LinkedList<Cell*> enemies);
	~BookPanel();
private:
	// update showing boxes
	void updateBoxes();
	// callback for buttons
	static void goNextPage(Fl_Widget *widget, void *data);
	static void goPrevPage(Fl_Widget *widget, void *data);
};

#endif