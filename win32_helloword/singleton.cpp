#include "stdafx.h"
#include "singleton.h"
using namespace std;
Singleton_player& Singleton_player::GetInstance()
{
	static Singleton_player instance;
	return instance;
}
string Singleton_player::Name() {
	return name;
}
void Singleton_player::doSomething(Iequipment * equip) {
	//MessageBox(NULL, L"您点击了第二个按钮。", L"提示", MB_OK | MB_ICONINFORMATION);
	for (int i = 0; i < NUM_ATTRI; i++)
		under_affect(i, equip->get_info(i));
}
int Singleton_player::get_info(int attribute) {
		return p->get_info(attribute);
	}
void Singleton_player::under_affect(int attribute,int value) {
	p->update_info(attribute, value);
	InvalidateRect(hwnd, NULL, TRUE);//发出重绘消息
	};
void Singleton_player::init_character(int character) {
		switch (character)
		{
		case soldier: {
			p = new Soldier();
			break;
		}
		case assassin: {
			p = new Assassin();
			break;
		}
		case tank: {
			p = new Tank();
			break;
		}
		default:
			break;
		}

}
void Singleton_player::init_character(Iwarrior *wa) {
	p = wa;
}
Iwarrior * Singleton_player::get_character() {
	return p;
	}
Context * Singleton_player::get_context() {
	return context;
}
void Singleton_player::set_context(int choice) {
	switch (choice)
	{
	case 1:
		context->set_strategy(strategy1);
		break;
	case 2:
		context->set_strategy(strategy2);
		break;
	case 3:
		context->set_strategy(strategy3);
		break;
	default:
		break;
	}
}
	