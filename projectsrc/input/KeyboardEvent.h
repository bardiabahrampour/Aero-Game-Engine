#pragma once
#include "Event.h"
#include <vector>
#include "GeneralEvent.h"

enum class KeyboardEventTypes : uint8_t {
	Pressed  = GLFW_PRESS,
	Released = GLFW_RELEASE,
	Repeated = GLFW_REPEAT,
};

enum class KeyboardKeyTypes : uint16_t {
	Key_Unknown = GLFW_KEY_UNKNOWN,
	Key_Space = GLFW_KEY_SPACE,
	Key_Apostrophe = GLFW_KEY_APOSTROPHE,
	Key_Comma = GLFW_KEY_COMMA,
	Key_Minus = GLFW_KEY_MINUS,
	Key_Period = GLFW_KEY_PERIOD,
	Key_Slash = GLFW_KEY_SLASH,
	Key_0 = GLFW_KEY_0,
	Key_1 = GLFW_KEY_1,
	Key_2 = GLFW_KEY_2,
	Key_3 = GLFW_KEY_3,
	Key_4 = GLFW_KEY_4,
	Key_5 = GLFW_KEY_5,
	Key_6 = GLFW_KEY_6,
	Key_7 = GLFW_KEY_7,
	Key_8 = GLFW_KEY_8,
	Key_9 = GLFW_KEY_9,
	Key_Semicolon = GLFW_KEY_SEMICOLON,
	Key_Equal = GLFW_KEY_EQUAL,
	Key_A = GLFW_KEY_A,
	Key_B = GLFW_KEY_B,
	Key_C = GLFW_KEY_C,
	Key_D = GLFW_KEY_D,
	Key_E = GLFW_KEY_E,
	Key_F = GLFW_KEY_F,
	Key_G = GLFW_KEY_G,
	Key_H = GLFW_KEY_H,
	Key_I = GLFW_KEY_I,
	Key_J = GLFW_KEY_J,
	Key_K = GLFW_KEY_K,
	Key_L = GLFW_KEY_L,
	Key_M = GLFW_KEY_M,
	Key_N = GLFW_KEY_N,
	Key_O = GLFW_KEY_O,
	Key_P = GLFW_KEY_P,
	Key_Q = GLFW_KEY_Q,
	Key_R = GLFW_KEY_R,
	Key_S = GLFW_KEY_S,
	Key_T = GLFW_KEY_T,
	Key_U = GLFW_KEY_U,
	Key_V = GLFW_KEY_V,
	Key_W = GLFW_KEY_W,
	Key_X = GLFW_KEY_X,
	Key_Y = GLFW_KEY_Y,
	Key_Z = GLFW_KEY_Z,
	Key_Left_Bracket = GLFW_KEY_LEFT_BRACKET,
	Key_Backslash = GLFW_KEY_BACKSLASH,
	Key_Right_Bracket = GLFW_KEY_RIGHT_BRACKET,
	Key_Grave_Accent = GLFW_KEY_GRAVE_ACCENT, /* ` */
	Key_Esc = GLFW_KEY_ESCAPE,
	Key_Enter = GLFW_KEY_ENTER,
	Key_Tab = GLFW_KEY_TAB,
	Key_Backspace = GLFW_KEY_BACKSPACE,
	Key_Insert = GLFW_KEY_INSERT,
	Key_Delete = GLFW_KEY_DELETE,
	Key_Right = GLFW_KEY_RIGHT,
	Key_Left = GLFW_KEY_LEFT,
	Key_Down = GLFW_KEY_DOWN,
	Key_Up = GLFW_KEY_UP,
	Key_Page_Up = GLFW_KEY_PAGE_UP,
	Key_Page_Down = GLFW_KEY_PAGE_DOWN,
	Key_Home = GLFW_KEY_HOME,
	Key_End = GLFW_KEY_END,
	Key_CapsLock = GLFW_KEY_CAPS_LOCK,
	Key_ScrollLock = GLFW_KEY_SCROLL_LOCK,
	Key_NumLock = GLFW_KEY_NUM_LOCK,
	Key_PrintScr = GLFW_KEY_PRINT_SCREEN,
	Key_Pause = GLFW_KEY_PAUSE,
	Key_F1 = GLFW_KEY_F1,
	Key_F2 = GLFW_KEY_F2,
	Key_F3 = GLFW_KEY_F3,
	Key_F4 = GLFW_KEY_F4,
	Key_F5 = GLFW_KEY_F5,
	Key_F6 = GLFW_KEY_F6,
	Key_F7 = GLFW_KEY_F7,
	Key_F8 = GLFW_KEY_F8,

};

class KeyboardKey {
	KeyboardKeyTypes   type;
	KeyboardEventTypes evt_type;
public:
	void SetKeyType(KeyboardKeyTypes type);
};

class INPUT_API KeyboardEvents {
	std::map<KeyboardKey, GeneralEvent> event_bindings;
public:
	void SetUp();
};

