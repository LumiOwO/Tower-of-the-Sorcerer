#include "transportPanel.h"
#include "../../../resourceManager/resourceManager.h"
#include "../../../game/game.h"

#include <string>
using namespace std;

#define KEY_ENTER		65293
#define KEY_ENTER_MINI	65421

TransportPanel::TransportPanel() :
	Fl_Group(TRANS_X, TRANS_Y, TRANS_WIDTH, TRANS_HEIGHT)
{
	// set the group style
	this->box(FL_FLAT_BOX);
	this->color(ResourceManager::BackgroundColor);

	// title
	title = new Fl_Box(
		TRANS_X,
		TRANS_Y,
		TRANS_WIDTH,
		TRANS_TITLEH,
		" 请输入想要去的楼层(不能前往未到达的楼层):"
	);
	// set style
	title->box(FL_NO_BOX);
	title->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
	// set font
	title->labelsize(TRANS_TEXTSIZE);
	title->labelfont(ResourceManager::HeiTi);
	title->labelcolor(FL_WHITE);

	// input
	input = new Fl_Int_Input(
		TRANS_INPUTX,
		TRANS_INPUTY,
		TRANS_INPUTW,
		TRANS_INPUTH
	);
	// set font
	input->textsize(TRANS_TEXTSIZE);
	input->textfont(ResourceManager::HeiTi);

	// button
	confirm = new Fl_Button(
		TRANS_BUTTONX,
		TRANS_BUTTONY,
		TRANS_BUTTONW,
		TRANS_BUTTONH,
		"确定"
	);
	// set style
	confirm->box(FL_FLAT_BOX);
	confirm->color(ResourceManager::GREEN);
	confirm->clear_visible_focus();
	// set font
	confirm->labelsize(TRANS_BTN_TEXTSIZE);
	confirm->labelfont(ResourceManager::HeiTi);
	confirm->labelcolor(FL_WHITE);
	// set callback and when the button is clicked, callback will do
	confirm->callback(transport, this);

	// begin to add widget
	this->begin();
		this->add(title);
		this->add(input);
		this->add(confirm);
	this->end();

	// focus the input
	Fl::focus(input);
}

TransportPanel::~TransportPanel()
{
	delete title;
	delete input;
	delete confirm;
}

void TransportPanel::transport(Fl_Widget *widget, void *data)
{
	// get the game
	Game *game = ResourceManager::game;
	// get the panel
	TransportPanel *panel = (TransportPanel*)data;
	// get the input value
	string valueStr = panel->input->value();

	// close the UI
	Game::openTransportUI(nullptr, nullptr);

	int value;
	// if the int is too large, do nothing
	if (valueStr.empty() || valueStr.length() > 2 ||
		(value = stoi(valueStr)) > game->getHighestLevel())
	{
		game->printStatus("您尚未到达过输入的层数，无法传送");
	}
	else
	{
		game->printStatus("传送至输入的层数");
		game->transportTo(value);
		game->updateInfo();
	}
}

int TransportPanel::handle(int event)
{
	int ret;
	if (event == FL_KEYDOWN && 
		(Fl::event_key() == KEY_ENTER || Fl::event_key() == KEY_ENTER_MINI))
	{
		transport(nullptr, this);
		ret = 1;
	}
	else
		ret = Fl_Group::handle(event);
	return ret;
}