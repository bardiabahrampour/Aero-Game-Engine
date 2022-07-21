#include "pch.h"
#include "KeyboardEvent.h"
#include <ini.h>

void KeyboardKey::SetKeyType(KeyboardKeyTypes type) {
	this->type = type;
}

void KeyboardEvents::SetUp(){
	mINI::INIFile file("input.ini");
	mINI::INIStructure ini;
	if (!file.read(ini)) {
		throw std::exception("Failed to open input file");
	}

}