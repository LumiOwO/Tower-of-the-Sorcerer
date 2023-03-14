#ifndef _HELPPANEL_H_
#define _HELPPANEL_H_

#include "../textDisplay/textDisplay.h"

#define HELP_X				430
#define HELP_Y				120
#define HELP_WIDTH			400
#define HELP_HEIGHT			500

class HelpPanel: public TextDisplay
{
public:
	HelpPanel();
	~HelpPanel();

};

#endif