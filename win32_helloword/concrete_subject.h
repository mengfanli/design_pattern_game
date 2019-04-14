#pragma once
#include <vector>
#include "subject.h"
class Concrete_Subject: public Subject{
public:
	virtual void attach(Observer* observer) override;
	virtual void detach() override;
	virtual void notify() override;
private:
	std::vector<Observer *> m_observers;
};
