#pragma once
#include "../PaperPixelCore.h"

namespace pp
{

class PP_API Renderer
{
public:
	Renderer();
	~Renderer();
public:
	void DrawArrays(int count);
};

}