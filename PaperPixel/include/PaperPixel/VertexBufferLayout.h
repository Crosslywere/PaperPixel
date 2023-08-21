#pragma once
#ifndef VERTEX_BUFFER_LAYOUT_H
#define VERTEX_BUFFER_LAYOUT_H

#include "../PaperPixelCore.h"
#include <vector>

namespace pp
{

struct VertexElement
{
	unsigned int Type;
	unsigned int Count;
	bool Normalize;
};

struct PP_API VertexBufferLayout
{
	template<typename T>
	void Push(unsigned int count, bool normalize = false);
	template<>
	void Push<float>(unsigned int count, bool normalize);
	const std::vector<VertexElement>& GetElements() const;
	unsigned int GetStride() const;
private:
	std::vector<VertexElement> m_Elements;
	unsigned int m_Stride = 0;
};

}

#endif // VERTEX_BUFFER_LAYOUT_H