#pragma once
#include "product_equipment.h"
#include "singleton.h"

//�����ӿ�
class Afactory
{
public:
	//�õ������жϡ�
	bool is_coins_enough(int need);
	virtual Iequipment * Createequip() = 0;
};
