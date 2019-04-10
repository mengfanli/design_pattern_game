#include "stdafx.h"
#include "concrete_character.h"
using namespace std;
string Soldier::Name() {
	return "Soldier";
}
Soldier::Soldier() {
	NAME = "Soldier";
	ATT = 10;
	DEF =10;
	HP = 10;
}

string Assassin::Name() {
		return "Assassin";
	}
Assassin::Assassin() {
	NAME = "Assassin";
	ATT = 10;
	DEF =10;
	HP = 20;
}

string Tank::Name() {
	return "Tank";
}
Tank::Tank() {
	NAME = "Tank";
	ATT = 10;
	DEF =10;
	HP = 20;
}
