#include "npcFactory.h"
#include "../../../viewManager/widgets/talkingUI/talkingUI.h"
#include "../../../resourceManager/resourceManager.h"
#include "../../../game/game.h"

NPC* NPCFactory::getfairy(int x, int y)
{
	// set the name of the NPC
	string name = "仙子";
	// set the words of the NPC
	string words = "勇士，欢迎来到魔塔！请打倒24层的魔龙获得胜利！\n"
		"　　进入魔塔之前，让我来给你进行一些指导吧！\n"
		"　　右下角书本按钮可以打开怪物图鉴，获得当前楼层剩余怪物的属性信息。"
		"右下角电梯按钮可以打开传送面板，但是只能传送到你到达过的楼层喔！\n"
		"　　你的操作信息会显示在窗口下方的状态栏里。"
		"如果仍不清楚的话可以点击右上角的问号打开帮助面板！\n"
		"　　按Esc键或者再次按空格键可以关掉对话面板。";
	// insert the buttons into a new UI
	TalkingUI *ui = new TalkingUI(
		LinkedList<TradeButton*>({

			})
	);
	// get a new NPC
	NPC *ret = new NPC(Cell::ID::FAIRY, ui, name, words);
	// update the text of the UI
	ui->updateText(ret->getName(), ret->getWords());
	// set cell info
	ret->setPhotos(ResourceManager::fairy);
	ret->setPosition(x, y);
	return ret;
}

NPC* NPCFactory::getprincess(int x, int y)
{
	// set the name of the NPC
	string name = "公主";
	// set the words of the NPC
	string words = "勇士，感谢你来救我！这里的神秘药水可以使你的生命值翻倍，快喝了它去击败恶龙吧！";
	// insert the buttons into a new UI
	TalkingUI *ui = new TalkingUI(
		LinkedList<TradeButton*>({

			})
	);
	// get a new NPC
	NPC *ret = new NPC(Cell::ID::PRINCESS, ui, name, words);
	// update the text of the UI
	ui->updateText(ret->getName(), ret->getWords());
	// set cell info
	ret->setPhotos(ResourceManager::princess);
	ret->setPosition(x, y);
	return ret;
}

NPC* NPCFactory::getold_man_level5(int x, int y)
{
	// set the name of the NPC
	string name = "老人";
	// set the words of the NPC
	string words = "这位兄弟，你目前还很弱啊，让我来帮你变强一点吧！";
	// insert the buttons into a new UI
	TalkingUI *ui = new TalkingUI(
		LinkedList<TradeButton*>({
			new TradeButton(
				TradeButton::EXP, TradeButton::LEVEL,
				100, 1,
				Game::transaction),
			new TradeButton(
				TradeButton::EXP, TradeButton::ATTACK,
				30, 5,
				Game::transaction),
			new TradeButton(
				TradeButton::EXP, TradeButton::DEFENCE,
				30, 5,
				Game::transaction),
			})
	);
	// get a new NPC
	NPC *ret = new NPC(Cell::ID::OLD_MAN_LEVEL5, ui, name, words);
	// update the text of the UI
	ui->updateText(ret->getName(), ret->getWords());
	// set cell info
	ret->setPhotos(ResourceManager::old_man);
	ret->setPosition(x, y);
	return ret;
}

NPC* NPCFactory::getold_man_level13(int x, int y)
{
	// set the name of the NPC
	string name = "老人";
	// set the words of the NPC
	string words = "用更多的经验可以获得更好的奖励！不要让我失望！";
	// insert the buttons into a new UI
	TalkingUI *ui = new TalkingUI(
		LinkedList<TradeButton*>({
			new TradeButton(
				TradeButton::EXP, TradeButton::LEVEL,
				270, 3,
				Game::transaction),
			new TradeButton(
				TradeButton::EXP, TradeButton::ATTACK,
				95, 17,
				Game::transaction),
			new TradeButton(
				TradeButton::EXP, TradeButton::DEFENCE,
				95, 17,
				Game::transaction),
			})
	);
	// get a new NPC
	NPC *ret = new NPC(Cell::ID::OLD_MAN_LEVEL13, ui, name, words);
	// update the text of the UI
	ui->updateText(ret->getName(), ret->getWords());
	// set cell info
	ret->setPhotos(ResourceManager::old_man);
	ret->setPosition(x, y);
	return ret;
}

NPC* NPCFactory::getstone_level3(int x, int y)
{
	// set the name of the NPC
	string name = "石像";
	// set the words of the NPC
	string words = "看什么看，快给钱！";
	// insert the buttons into a new UI
	TalkingUI *ui = new TalkingUI(
		LinkedList<TradeButton*>({
			new TradeButton(
				TradeButton::MONEY, TradeButton::HEALTH,
				25, 800,
				Game::transaction),
			new TradeButton(
				TradeButton::MONEY, TradeButton::ATTACK,
				25, 4,
				Game::transaction),
			new TradeButton(
				TradeButton::MONEY, TradeButton::DEFENCE,
				25, 4,
				Game::transaction),
			})
	);
	// get a new NPC
	NPC *ret = new NPC(Cell::ID::STONE_LEVEL3, ui, name, words);
	// update the text of the UI
	ui->updateText(ret->getName(), ret->getWords());
	// set cell info
	ret->setPhotos(ResourceManager::stone);
	ret->setPosition(x, y);
	return ret;
}

NPC* NPCFactory::getstone_level11(int x, int y)
{
	// set the name of the NPC
	string name = "石像";
	// set the words of the NPC
	string words = "呐，现在给你打个折，别让我失望！";
	// insert the buttons into a new UI
	TalkingUI *ui = new TalkingUI(
		LinkedList<TradeButton*>({
			new TradeButton(
				TradeButton::MONEY, TradeButton::HEALTH,
				100, 4000,
				Game::transaction),
			new TradeButton(
				TradeButton::MONEY, TradeButton::ATTACK,
				100, 20,
				Game::transaction),
			new TradeButton(
				TradeButton::MONEY, TradeButton::DEFENCE,
				100, 20,
				Game::transaction),
			})
	);
	// get a new NPC
	NPC *ret = new NPC(Cell::ID::STONE_LEVEL11, ui, name, words);
	// update the text of the UI
	ui->updateText(ret->getName(), ret->getWords());
	// set cell info
	ret->setPhotos(ResourceManager::stone);
	ret->setPosition(x, y);
	return ret;
}

NPC* NPCFactory::getkey_seller(int x, int y)
{
	// set the name of the NPC
	string name = "钥匙商人";
	// set the words of the NPC
	string words = "客官，在魔塔被困了吧，来买点钥匙呀！";
	// insert the buttons into a new UI
	TalkingUI *ui = new TalkingUI(
		LinkedList<TradeButton*>({
			new TradeButton(
				TradeButton::MONEY, TradeButton::YELLOWKEY,
				10, 1,
				Game::transaction),
			new TradeButton(
				TradeButton::MONEY, TradeButton::BLUEKEY,
				50, 1,
				Game::transaction),
			new TradeButton(
				TradeButton::MONEY, TradeButton::REDKEY,
				100, 1,
				Game::transaction),
			})
	);
	// get a new NPC
	NPC *ret = new NPC(Cell::ID::KEY_SELLER, ui, name, words);
	// update the text of the UI
	ui->updateText(ret->getName(), ret->getWords());
	// set cell info
	ret->setPhotos(ResourceManager::merchant);
	ret->setPosition(x, y);
	return ret;
}

NPC* NPCFactory::getkey_buyer(int x, int y)
{
	// set the name of the NPC
	string name = "钥匙回收商人";
	// set the words of the NPC
	string words = "没钱了吧勇士？卖点钥匙给我吧！";
	// insert the buttons into a new UI
	TalkingUI *ui = new TalkingUI(
		LinkedList<TradeButton*>({
			new TradeButton(
				TradeButton::YELLOW, TradeButton::COIN,
				1, 7,
				Game::transaction),
			new TradeButton(
				TradeButton::BLUE, TradeButton::COIN,
				1, 35,
				Game::transaction),
			new TradeButton(
				TradeButton::RED, TradeButton::COIN,
				1, 70,
				Game::transaction),
			})
	);
	// get a new NPC
	NPC *ret = new NPC(Cell::ID::KEY_BUYER, ui, name, words);
	// update the text of the UI
	ui->updateText(ret->getName(), ret->getWords());
	// set cell info
	ret->setPhotos(ResourceManager::merchant);
	ret->setPosition(x, y);
	return ret;
}

