#include "pch.h"
#include "GameEvent.h"

/*
	Game Events are all derived from this base class
	so if there are no event functions implemented(the base function)
	then we log the error as undefined game event.
*/
void GameEvent::operator()() {
	OutputDebugStringA("Game Event Function is not impelmented!\n");
	return;
}