#include "npc.h"

NPC::NPC(ID id, TalkingUI *ui, string name, string words):
	Cell(id, Type::NPC), talkingUI(ui), name(name), words(words)
{

}

NPC::~NPC()
{

}

TalkingUI* NPC::getTalkingUI()
{
	return talkingUI;
}

string NPC::getName()
{
	return " " + name;
}

string NPC::getWords()
{
	return "　　" + words;
}