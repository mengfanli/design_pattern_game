#include "stdafx.h"
#include "care_taker.h"
Memento_Manager::~Memento_Manager()
{
	for (int i = 0; i < m_character_list.size(); i++) {
		delete m_character_list.at(i);
	}
}
void Memento_Manager::backup() {
	if (m_character_list.size() <= 3)
		m_character_list.push_back(m_poriginator->Create_Memento());
	else
	{
		static int index = 0;
		if (m_character_list[index % 3] != NULL)
			delete m_character_list[index % 3];
		m_character_list[(index++)%3] = m_poriginator->Create_Memento();
	}
}
void Memento_Manager::undo_jump(int key) {
	m_poriginator->Set_Memento(m_character_list[key-1]);
}
int Memento_Manager::get_bknumber() {
	return m_character_list.size();
}

Memento_Manager * Memento_Manager::get_instance() {
	return instance;
}
Memento_Manager * Memento_Manager::instance = new Memento_Manager();
