#pragma once
#include "Graphics/renderEngine/GLLoader.h"
#include "Graphics/renderEngine/GLTextureLoader.h"
#include "Graphics/renderEngine/GLMainRenderer.h"
#include "Graphics/renderEngine/GLEntityRenderer.h"
#include "Graphics/Display/Display.h"
using namespace Duno::Graphics;

/* A standered duno game setup, no rendering */
class DunoGame
{
public:
	DunoGame(const char* name);
	/* Starts the main game loop */
	void startMainGameLoop();
	~DunoGame();
protected:
	/* Called on each fram */
	virtual void onRender() {};
	/* Called when the game has been deleted */
	virtual void onCleanUp() {};

	/* Stores some cross render data */
	Display* display;
	DunoCamera* mainCamera;
};

/* An OpenGL duno game setup */
class GLDunoGame : public DunoGame
{
public:
	GLDunoGame();
	/* Returns a renderer at index */
	GLRenderer* getRenderer(unsigned int index) { return renderer->getRenderer(index); };
	/* Adds a renderer to render to the scene */
	void addRenderer(GLRenderer* renderer) { this->renderer->addRenderer(renderer); }
	/* Updates the renderers projection matrix */
	void updateProjectionMatrix() { renderer->updateProjectionMatrix(); }

	GLLoader* getLoader() { return loader; }
	GLTextureLoader* getTextureLoader() { return textureLoader; }
private:
	virtual void onRender();
	virtual void onCleanUp();

	GLMainRenderer* renderer;
	GLLoader* loader;
	GLTextureLoader* textureLoader;
};