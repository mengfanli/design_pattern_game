#include "stdafx.h"
#include "concrete_strategy.h"
#include "singleton.h"
#include "flyweight_factory.h"
void ConcreteStrategy1::do_attack() {
	//����1����ʵ��	
	//�����޵���ȭ
	Strange *p = StrangeFactory::getStrange("M");
	int m_att_v = p->getatt();
		Singleton_player::GetInstance().under_affect(hp, -m_att_v);
		Singleton_player::GetInstance().under_affect(coins, m_att_v*2);
		Singleton_player::GetInstance().under_affect(exper, m_att_v);
}
void ConcreteStrategy1::show_info() {
	//����1����ʵ��	
	//��ȭ����
}
void ConcreteStrategy2::do_attack() {
	Strange *p = StrangeFactory::getStrange("M");
	int m_att_v = p->getatt();
		Singleton_player::GetInstance().under_affect(hp, -m_att_v);
		Singleton_player::GetInstance().under_affect(coins, m_att_v);
		Singleton_player::GetInstance().under_affect(exper, m_att_v*2);
	//����2����ʵ��	
}
void ConcreteStrategy2::show_info() {
	//����2����ʵ��	
}
void ConcreteStrategy3::do_attack() {
	Strange *p = StrangeFactory::getStrange("M");
	int m_att_v = p->getatt();
		Singleton_player::GetInstance().under_affect(hp, -m_att_v*2);
		Singleton_player::GetInstance().under_affect(coins, m_att_v);
		Singleton_player::GetInstance().under_affect(exper, m_att_v);
	//����3����ʵ��	
}
void ConcreteStrategy3::show_info() {

}
