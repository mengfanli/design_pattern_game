#pragma once
#include "observer.h"
extern HWND hwnd_bk;
extern HINSTANCE hInst;								// current instance
class Concrete_Observer_button : public Observer {
public:
	Concrete_Observer_button(int s);
	void Show_button();
	virtual void update();
private:
	bool button_enable;
	int button_key;
	char button_name[10];
};
class Concrete_Observer_button2 : public Observer {
public:
	virtual void update();
private:
	char button_name[10];
};
class Concrete_Observer_button3 : public Observer {
public:
	virtual void update();
private:
	char button_name[10];
};
