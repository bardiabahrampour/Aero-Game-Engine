#pragma once
#include "GeneralEvent.h"

class GameEvent : protected GeneralEvent{
public:
	//Game Event Funciton
	virtual void operator()();
};

