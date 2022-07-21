#pragma once
#include "api.h"

/*
	General Event:
		Base Class for Game Event and UI Event(To be implemented) and System Event
		----------------------------------------------------------
		Also Helps with Events class so that there are general stuff
		that happen when an event is dispatched
*/
class INPUT_API GeneralEvent {
public:
	(void)(EventFunc());
protected:
	virtual void operator()() = 0;
};

