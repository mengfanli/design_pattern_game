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
	int	size = wsprintf(szText, TEXT("%s%d%s"), L"����С�ֽ���Ѫ��", m_att_v, L" �Ƿ񹥻���");
	int ret = MessageBox(NULL, szText, TEXT("CHOOSE"), MB_YESNO | MB_ICONQUESTION);
	if (ret == IDYES)
	{
		//ȷ�ϴ�� ��Ϣ����
		Singleton_player::GetInstance().get_context()->do_attack();
		//Singleton_player::GetInstance().under_affect(hp, -m_att_v);
		//Singleton_player::GetInstance().under_affect(coins, m_att_v);
		//Singleton_player::GetInstance().under_affect(exper, m_att_v);
		//InvalidateRect(hwnd, NULL, TRUE);//�����ػ���Ϣ
	}
}
Senior::Senior() {
	m_task = "I will help U.";
}
void Senior::mission(){
	TCHAR szText[256];
	int	size = wsprintf(szText, TEXT("%s%d%s"), L"�������߽���Ѫ��", m_att_v, L" �Ƿ���ܣ�");
	int ret = MessageBox(NULL, szText, TEXT("CHOOSE"), MB_YESNO | MB_ICONQUESTION);
	if (ret == IDYES)
	{
		//ȷ�ϴ�� ��Ϣ����
		Singleton_player::GetInstance().under_affect(hp, m_att_v);
		InvalidateRect(hwnd_main, NULL, TRUE);//�����ػ���Ϣ
	}
}
