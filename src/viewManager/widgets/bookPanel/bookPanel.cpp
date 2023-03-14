#include "bookPanel.h"
#include "../../../resourceManager/resourceManager.h"
#include "../../../game/game.h"

BookPanel::BookPanel(LinkedList<Cell*> enemies):
	Fl_Group(BOOK_X, BOOK_Y, BOOK_WIDTH, BOOK_HEIGHT),
	enemies(enemies), nowPage(0)
{
	// set the group style
	this->box(FL_FLAT_BOX);
	this->color(ResourceManager::BackgroundColor);

	// prevPage button
	prevPage = new Fl_Button(
		BOOK_BUTTONX,
		BOOK_BUTTONY,
		BOOK_BUTTONW,
		BOOK_BUTTONH,
		"上一页"
	);
	// set style
	prevPage->box(FL_FLAT_BOX);
	prevPage->color(ResourceManager::GREEN);
	prevPage->clear_visible_focus();
	// set font
	prevPage->labelsize(BOOK_BTN_TEXTSIZE);
	prevPage->labelfont(ResourceManager::HeiTi);
	prevPage->labelcolor(FL_WHITE);
	// set callback
	prevPage->callback(goPrevPage, this);

	// nextPage button
	nextPage = new Fl_Button(
		BOOK_BUTTONX + BOOK_BUTTONW + BOOK_BTN_INTERVAL,
		BOOK_BUTTONY,
		BOOK_BUTTONW,
		BOOK_BUTTONH,
		"下一页"
	);
	// set style
	nextPage->box(FL_FLAT_BOX);
	nextPage->color(ResourceManager::GREEN);
	nextPage->clear_visible_focus();
	// set font
	nextPage->labelsize(BOOK_BTN_TEXTSIZE);
	nextPage->labelfont(ResourceManager::HeiTi);
	nextPage->labelcolor(FL_WHITE);
	// set callback
	nextPage->callback(goNextPage, this);

	// begin to add widget
	this->begin();
		this->add(prevPage);
		this->add(nextPage);
	this->end();
	// update display boxes
	updateBoxes();
}

BookPanel::~BookPanel()
{
	for (int i = 0; i < DISPLAY_NUM; i++)
		if (boxes[i])
			delete boxes[i];
	delete nextPage;
	delete prevPage;
}

void BookPanel::updateBoxes()
{
	// free memory
	for(int i=0; i< DISPLAY_NUM; i++)
		if (boxes[i] != nullptr)
		{
			// remove the box from the panel
			this->remove(boxes[i]);
			delete boxes[i];
			boxes[i] = nullptr;
		}

	// get the start number
	int start = nowPage * DISPLAY_NUM;
	// get the start node
	Node<Cell*> *p = enemies.begin();
	for (int i = 0; i < start; i++)
		p = p->getNext();

	// start to add box
	for(int i = 0; p && i < DISPLAY_NUM; i++, p = p->getNext())
	{
		EnemyInfoBox *box = new EnemyInfoBox(
			BOOK_X,
			BOOK_Y + i * ENEMYBOX_H,
			BOOK_WIDTH,
			ENEMYBOX_H,
			(Enemy*)p->getValue()
		);
		// add box to the panel
		this->add(box);
		boxes[i] = box;
	}
}

void BookPanel::goNextPage(Fl_Widget *widget, void *data)
{
	// get the panel
	BookPanel *panel = (BookPanel*)data;
	// if next page has enemies, go to next page
	if (panel->enemies.size() > DISPLAY_NUM * (panel->nowPage + 1))
	{
		panel->nowPage++;
		panel->updateBoxes();
		panel->redraw();
		ResourceManager::game->printStatus("下一页");
	}
}

void BookPanel::goPrevPage(Fl_Widget *widget, void *data)
{
	// get the panel
	BookPanel *panel = (BookPanel*)data;
	// if it's not first page, go previous page
	if (panel->nowPage > 0)
	{
		panel->nowPage--;
		panel->updateBoxes();
		panel->redraw();
		ResourceManager::game->printStatus("上一页");
	}
}