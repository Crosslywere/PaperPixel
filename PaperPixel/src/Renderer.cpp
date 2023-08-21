#include "pch.h"
#include <PaperPixel/Renderer.h>

namespace pp
{

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::DrawArrays(int count)
{
	GLCall(glDrawArrays(GL_TRIANGLES, 0, count));
}

}