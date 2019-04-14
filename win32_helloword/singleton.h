#pragma once
#include <iostream>
#include "Resource.h"
#include "warrior.h"
#include "concrete_character.h"
#include "product_equipment.h"
#include "context_strategy.h"
#include "concrete_strategy.h"
//enum attribute_type {hp,att,def};
extern enum attribute_type{ hp, att, def, coins, exper, NUM_ATTRI };
extern enum character_type {soldier,assassin,tank};
extern HWND hwnd_main;
// 单例
class Singleton_player  
{
public:
	static Singleton_player& GetInstance();
	std::string Name();
	//此接口dosomething考虑设计为策略模式
	void doSomething(Iequipment * equip);
	int get_info(int attribute);
	void under_affect(int attribute, int value);
	void init_character(int character);
	void init_character(Iwarrior *wa);
	Iwarrior * get_character();
	Context * get_context();
	void set_context(int choice);
private:
	Singleton_player() {}  // 构造函数（被保护）
	Singleton_player(Singleton_player const &);  // 无需实现
	Singleton_player& operator = (const Singleton_player &);  // 无需实现
	std::string name;
	Iwarrior *p;
	Istrategy * strategy1 = new ConcreteStrategy1();
	Istrategy * strategy2 = new ConcreteStrategy2();
	Istrategy * strategy3 = new ConcreteStrategy3();
	Context *context = new Context(strategy2);
};
