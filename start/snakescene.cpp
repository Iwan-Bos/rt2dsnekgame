/**
 * This class describes SnakeScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "snakescene.h"

// --------------------------------- functions ---------------------------------
void SnakeScene::update(float deltaTime)
{
	// Escape key stops the Scene
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}
}

// -------------------- constructor and deconstructor magic --------------------

/// @brief SnakeScene object constructor
SnakeScene::SnakeScene() : Scene()
{
	// start the timer.
	t.start();

	// create a single instance of Snake in the middle of the screen.
	// the Sprite is added in Constructor of Snake.
	snake = new Snake();

	// create a single instance of Hud in the middle of the screen.
	// the hud elements are added in Constructor of Hud.
	hud = new Hud();

	snake->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	hud->position = Point2(SWIDTH / 2, SHEIGHT / 2);

	// create the scene 'tree'
	// add hud & snake to this Scene as a child.
	this->addChild(hud);
	this->addChild(snake);
}

/// @brief SnakeScene object destructor
SnakeScene::~SnakeScene()
{
	// deconstruct and delete the Tree
	this->removeChild(snake);
	this->removeChild(hud);

	// delete hud & snake from the heap (there was a 'new' in the constructor)
	delete snake;
	delete hud;
}