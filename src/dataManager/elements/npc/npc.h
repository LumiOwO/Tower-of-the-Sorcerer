#ifndef _NPC_H_
#define _NPC_H_

#include "../cell/cell.h"

#include <string>
using namespace std;

class TalkingUI;
class NPC: public Cell
{
private:
	TalkingUI *talkingUI;
	string name;
	string words;
public:
	NPC(ID id, TalkingUI *ui, string name, string words);
	~NPC();

	// get the UI
	TalkingUI* getTalkingUI();
	// get the name of NPC
	string getName();
	// get the words of NPC
	string getWords();
};

#endif