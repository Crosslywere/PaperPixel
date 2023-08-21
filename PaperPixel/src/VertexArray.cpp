#include "pch.h"
#include <PaperPixel/VertexArray.h>

namespace pp
{

VertexArray::VertexArray()
{
	GLCall(glGenVertexArrays(1, &m_RendererID));
	GLCall(glBindVertexArray(m_RendererID));
}

VertexArray::~VertexArray()
{
	GLCall(glDeleteVertexArrays(1, &m_RendererID));
}

void VertexArray::Bind() const
{
	GLCall(glBindVertexArray(m_RendererID));
}

void VertexArray::Unbind() const
{
	GLCall(glBindVertexArray(0));
}

void VertexArray::SetBufferAndLayout(const VertexBuffer& vertexBuffer, const VertexBufferLayout& layout)
{
	Bind();
	vertexBuffer.Bind();
	auto& elements = layout.GetElements();
	for (int i = 0; i < elements.size(); i++)
	{
		auto& elem = elements[i];
		GLCall(glEnableVertexAttribArray(i));
		glVertexAttribPointer(i, elem.Count, elem.Count, elem.Normalize ? GL_TRUE : GL_FALSE, layout.GetStride(), (void*)0);
	}
}

}