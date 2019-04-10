#include "stdafx.h"
#include "originator.h"
#include "singleton.h"
Iwarrior * Originator::Create_Memento() {
	Iwarrior*p  =  new Iwarrior();
	p = Singleton_player::GetInstance().get_character();
	return p;
}
void Originator::Set_Memento(Iwarrior *wa) {
	Singleton_player::GetInstance().init_character(wa);
}