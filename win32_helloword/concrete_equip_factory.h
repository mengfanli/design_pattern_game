#pragma once
#include "equip_factory.h"
#include "concrete_product_equip.h"
class Equipfactory1 : public Afactory
{	
public:
	Iequipment * Createequip();
};
class Equipfactory2 : public Afactory
{	
public:
	Iequipment * Createequip();
};
class Equipfactory3 : public Afactory
{	
public:
	Iequipment * Createequip();
};
