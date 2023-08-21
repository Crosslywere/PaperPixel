#include "pch.h"
#include <PaperPixel/VertexBufferLayout.h>

namespace pp
{

template<typename T>
void VertexBufferLayout::Push(unsigned int count, bool normalized)
{
	static_assert(false);
}

template<>
void VertexBufferLayout::Push<float>(unsigned int count, bool normalized)
{
	m_Elements.push_back({ GL_FLOAT, count, normalized });
	m_Stride += count * sizeof(float);
}

const std::vector<VertexElement>& VertexBufferLayout::GetElements() const
{
	return m_Elements;
}

unsigned int VertexBufferLayout::GetStride() const
{
	return m_Stride;
}

}
