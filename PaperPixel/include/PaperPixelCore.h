#pragma once
#ifndef PAPER_PIXEL_CORE_H
#define PAPER_PIXEL_CORE_H

#ifdef PP_WINDOWS
#	ifdef PP_BUILD_DLL
#		define PP_API __declspec(dllexport)
#	else
#		define PP_API __declspec(dllimport)
#	endif
#else // Not Windows platform
#	ifdef PP_BUILD_DLL
#		define PP_API __attribute__((visibility("default")))
#	else
#		define PP_API
#	endif
#endif // PP_WINDOWS

// Forward declaration
struct GLFWwindow;

#endif // PAPER_PIXEL_CORE_H