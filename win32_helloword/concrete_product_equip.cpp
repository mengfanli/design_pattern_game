#include "stdafx.h"
#include "concrete_equip_factory.h"
std::string Equipment1::Name() {
		return "����";
	}
Equipment1:: Equipment1() :Iequipment(0, 0, 10,-10, 0) {}

std::string Equipment2::Name() {
	return "����";
}
Equipment2::Equipment2() :Iequipment(0, 10, 0, -10, 0) {}

std::string Equipment3::Name() {
	return "�챦ʯ";
}
Equipment3::Equipment3() :Iequipment(50, 0, 0, -10, 0) {}

