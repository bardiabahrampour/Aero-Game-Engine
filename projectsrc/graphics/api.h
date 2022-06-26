#pragma once

#ifdef GRAPHICS_EXPORTS
#define GRAHPICS_API __declspec(dllexport)
#else
#define GRAPHICS_API __declspec(dllimport)
#endif

#define _API __declspec(dllexport)