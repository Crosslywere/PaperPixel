#pragma once
#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H

#include "../PaperPixelCore.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

namespace pp
{

class PP_API VertexArray
{
public:
	VertexArray();
	~VertexArray();
	void Bind() const;
	void Unbind() const;
	void SetBufferAndLayout(const VertexBuffer& vertexBuffer, const VertexBufferLayout& layout);
private:
	unsigned int m_RendererID;
};

}

#endif // VERTEX_ARRAY_H