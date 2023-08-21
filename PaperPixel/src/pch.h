#pragma once
#ifndef PCH_H
#define PCH_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <stb_image.h>

// Debugging stuff
#include "PaperPixelCore.h"
PP_API bool GLCallHasErrors(const char* expr, const char* file, unsigned int line);

#if defined(PP_WINDOWS)
#	define DEBUG_BREAK __debugbreak()
#else
#	define DEBUG_BREAK
#endif

#ifdef PP_DEBUG
#	define GLAssert(gl_expr) if (GLCallHasErrors(#gl_expr, __FILE__, (unsigned)__LINE__)) DEBUG_BREAK
#	define GLCall(gl_expr) while (glGetError() == GL_NO_ERROR); gl_expr; GLAssert(gl_expr)
#else
	// Defining GLAssert so that debug errors can still be seen in Release configuration
#	define GLAssert(gl_expr) GLCallHasErrors(#gl_expr, __FILE__, (unsigned)__LINE__)
#	define GLCall(gl_expr) gl_expr; GLAssert(gl_expr)
#endif

#endif // PCH_H