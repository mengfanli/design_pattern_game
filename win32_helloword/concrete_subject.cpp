#include "stdafx.h"
#include "concrete_subject.h"
void Concrete_Subject::attach(Observer *observer) {
	m_observers.push_back(observer);
}
void Concrete_Subject::detach() {
	m_observers.pop_back();
}
void Concrete_Subject::notify() {
	for (auto obser : m_observers)
		obser->update();
}
