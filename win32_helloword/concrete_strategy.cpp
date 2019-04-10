#include "stdafx.h"
#include "concrete_strategy.h"
#include "singleton.h"
#include "flyweight_factory.h"
void ConcreteStrategy1::do_attack() {
	//技能1攻击实现	
	//吃我无敌铁拳
	Strange *p = StrangeFactory::getStrange("M");
	int m_att_v = p->getatt();
		Singleton_player::GetInstance().under_affect(hp, -m_att_v);
		Singleton_player::GetInstance().under_affect(coins, m_att_v*2);
		Singleton_player::GetInstance().under_affect(exper, m_att_v);
}
void ConcreteStrategy1::show_info() {
	//技能1防御实现	
	//铁拳防御
}
void ConcreteStrategy2::do_attack() {
	Strange *p = StrangeFactory::getStrange("M");
	int m_att_v = p->getatt();
		Singleton_player::GetInstance().under_affect(hp, -m_att_v);
		Singleton_player::GetInstance().under_affect(coins, m_att_v);
		Singleton_player::GetInstance().under_affect(exper, m_att_v*2);
	//技能2攻击实现	
}
void ConcreteStrategy2::show_info() {
	//技能2防御实现	
}
void ConcreteStrategy3::do_attack() {
	Strange *p = StrangeFactory::getStrange("M");
	int m_att_v = p->getatt();
		Singleton_player::GetInstance().under_affect(hp, -m_att_v*2);
		Singleton_player::GetInstance().under_affect(coins, m_att_v);
		Singleton_player::GetInstance().under_affect(exper, m_att_v);
	//技能3攻击实现	
}
void ConcreteStrategy3::show_info() {

}
