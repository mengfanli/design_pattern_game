#include "stdafx.h"
#include "stdlib.h"
#include <string>
#include "concrete_observer.h"
Concrete_Observer_button::Concrete_Observer_button(int s) {
	button_enable = FALSE;
	button_key = s;
	strcpy_s(button_name, 6,"Empty");
}
void Concrete_Observer_button::update() {
	button_enable = TRUE;
	char bt_showname[10] = "backup_";
	static int bks =0 ;
	bt_showname[6]=  char('0'+button_key+(bks/3)*3%6);
	bks += 1;
	strcpy_s(button_name, 8, bt_showname);
}
void Concrete_Observer_button::Show_button() {
	int num = MultiByteToWideChar(0, 0, button_name, -1, NULL, 0);
	wchar_t *wbn = new wchar_t[num];
	MultiByteToWideChar(0, 0, button_name, -1, wbn, num);
	int BT_ID = button_key+3020-1;
	CreateWindow(L"Button", /*L"Empty"*/wbn, WS_VISIBLE|WS_DISABLED<<button_enable*5 | WS_CHILD | BS_PUSHBUTTON,
		35, 10+(button_key-1)*70, 120, 60, hwnd_bk, (HMENU)/*3019+button_key*/BT_ID/*IDB_BKU1*/, hInst, NULL);
}