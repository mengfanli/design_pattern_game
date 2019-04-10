#pragma once
#include <vector>
#include "warrior.h"
#include "originator.h"
class Memento_Manager
{
public:
	Memento_Manager();
	~Memento_Manager();
	void backup();
	void undo_jump(int key);

private:
	Originator *m_poriginator;
	std::vector<Iwarrior*> m_character_list;
};

//Memento_Manager::Memento_Manager()
//{
//}


