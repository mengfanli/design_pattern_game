#pragma once
#include "observer.h"
class Subject
{
public:
	virtual	void attach(Observer* observer) = 0;
	virtual void detach() = 0;
	virtual void notify() = 0;
};
