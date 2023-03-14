#ifndef _TRANSPORTPANEL_H_
#define _TRANSPORTPANEL_H_

#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Int_Input.H>
#include <FL/Fl_Button.H>

#define TRANS_TEXTSIZE		23

#define TRANS_X				355
#define TRANS_Y				200
#define TRANS_WIDTH			550
#define TRANS_HEIGHT		300

#define TRANS_TITLEH		100

#define TRANS_INPUTX		450
#define TRANS_INPUTY		320
#define TRANS_INPUTW		360
#define TRANS_INPUTH		50

#define TRANS_BUTTONX		580
#define TRANS_BUTTONY		425
#define TRANS_BUTTONW		100
#define TRANS_BUTTONH		50
#define TRANS_BTN_TEXTSIZE	20

class TransportPanel: public Fl_Group
{
private:
	Fl_Box *title;
	Fl_Int_Input *input;
	Fl_Button *confirm;
public:
	TransportPanel();
	~TransportPanel();

	// callback for confirm button
	static void transport(Fl_Widget *widget, void *data);

	// @override event handler
	int handle(int event);
};

#endif