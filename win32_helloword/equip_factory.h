#pragma once
#include "product_equipment.h"
#include "singleton.h"

//工厂接口
class Afactory
{
public:
	//用到单例判断。
	bool is_coins_enough(int need);
	virtual Iequipment * Createequip() = 0;
};
