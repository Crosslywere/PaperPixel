#include <PaperPixel/PaperPixel.h>
#include <iostream>

class Game : public pp::Application
{
public:
	Game() : Application()
	{
		SetTitle("My Game");
		SetIcon("res/textures/sandbox.png");
	}
	~Game()
	{
	}
protected:
	void OnCreate() override
	{
		float verts[] = {
			0.0f, 0.5f,
			0.5f, -.5f,
			-.5f, -.5f
		};
		va = new pp::VertexArray();
		va->Bind();
		vb = new pp::VertexBuffer(verts, sizeof(verts));
		vb->Bind();
		pp::VertexBufferLayout layout;
		layout.Push<float>(2);
		va->SetBufferAndLayout(*vb, layout);
	}
	void OnUpdate(float delta) override
	{
	}
	void OnRender(pp::Renderer renderer) override
	{
		renderer.DrawArrays(3);
	}
private:
	pp::VertexArray* va;
	pp::VertexBuffer* vb;
};

int main()
{
	Game game;
	if (game.IsCreated())
		game.Run();
	return 0;
}
