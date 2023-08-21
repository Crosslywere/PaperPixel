#pragma once
#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include "../PaperPixelCore.h"

namespace pp
{

class PP_API VertexBuffer
{
public:
	VertexBuffer();
	/**
	 * @brief
	 * VertexBuffer constructor that takes an array of data
	 * and the size of the data in bytes.
	 * 
	 * @param data - An array of vertex data.
	 * @param size - The size of the data in bytes.
	 */
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();
	void Bind() const;
	void Unbind() const;
private:
	unsigned int m_RendererID;
};

}

#endif // VERTEX_BUFFER_H