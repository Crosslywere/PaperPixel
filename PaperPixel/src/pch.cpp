#include "pch.h"

bool GLCallHasErrors(const char* expr, const char* file, unsigned int line)
{
	while (unsigned int errorCode = glGetError() != GL_NO_ERROR)
	{
		std::cout << "Failed OpenGL call " << expr << " -> " << file
			<< "(" << line << ") Error Code: " << errorCode << std::endl;
		return true;
	}
	return false;
}