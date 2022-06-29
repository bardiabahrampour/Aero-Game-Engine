#pragma once
#include <GLFW/glfw3.h>
#include <cstdint>
#include <vector>
#include "api.h"

enum class INPUT_API EventType {
	Pressed  = GLFW_PRESS,
	Released = GLFW_RELEASE,
	Repeated = GLFW_REPEAT,
};

class INPUT_API Event {
	EventType type;
public:
	EventType GetEventType();
};

