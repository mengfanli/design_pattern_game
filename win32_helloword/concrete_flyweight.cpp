#include "stdafx.h"
#include "concrete_flyweight.h"
#include "singleton.h"
//extern HWND hwnd;
//extern enum attribute_type{ hp, att, def, coins, exper, NUM_ATTRI };
Monster::Monster(){
	m_task = "I will kill U.";
}
void Monster::mission() {
	TCHAR szText[256];
	int	size = wsprintf(szText, TEXT("%s%d%s"), L"遇到小怪将掉血：", m_att_v, L" 是否攻击？");
	int ret = MessageBox(NULL, szText, TEXT("CHOOSE"), MB_YESNO | MB_ICONQUESTION);
	if (ret == IDYES)
	{
		//确认打怪 信息更新
		Singleton_player::GetInstance().get_context()->do_attack();
		//Singleton_player::GetInstance().under_affect(hp, -m_att_v);
		//Singleton_player::GetInstance().under_affect(coins, m_att_v);
		//Singleton_player::GetInstance().under_affect(exper, m_att_v);
		//InvalidateRect(hwnd, NULL, TRUE);//发出重绘消息
	}
}
Senior::Senior() {
	m_task = "I will help U.";
}
void Senior::mission(){
	TCHAR szText[256];
	int	size = wsprintf(szText, TEXT("%s%d%s"), L"遇到长者将回血：", m_att_v, L" 是否接受？");
	int ret = MessageBox(NULL, szText, TEXT("CHOOSE"), MB_YESNO | MB_ICONQUESTION);
	if (ret == IDYES)
	{
		//确认打怪 信息更新
		Singleton_player::GetInstance().under_affect(hp, m_att_v);
		InvalidateRect(hwnd, NULL, TRUE);//发出重绘消息
	}
}
