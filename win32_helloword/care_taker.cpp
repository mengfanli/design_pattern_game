#include "stdafx.h"
#include "care_taker.h"
Memento_Manager::~Memento_Manager()
{
	for (int i = 0; i < m_character_list.size(); i++) {
		delete m_character_list.at(i);
	}
}
void Memento_Manager::backup() {
	m_character_list.push_back(m_poriginator->Create_Memento());
}
void Memento_Manager::undo_jump(int key) {
	m_poriginator->Set_Memento(m_character_list[key]);
}
