#include "stdafx.h"
#include "concrete_equip_factory.h"
//extern enum attribute_type{ hp, att, def, coins, exper, NUM_ATTRI };
Iequipment * Equipfactory1::Createequip() {
	Iequipment *p = new Equipment1();
	if (is_coins_enough(abs(p->get_info(coins)))) 
	{
		return p;
	}
	return NULL;
}
Iequipment * Equipfactory2::Createequip() {
	Iequipment *p = new Equipment2();
	if (is_coins_enough(abs(p->get_info(coins))))
	{
		return p;
	}
	return NULL;
}
Iequipment *Equipfactory3::Createequip() {
	Iequipment *p = new Equipment3();
	if (is_coins_enough(abs(p->get_info(coins))))
	{
		return p;
	}
	return NULL;
}