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

	//hud = new Hud(); <<<<<<<<<<<<<<<<< HUD HERE AND STFFFFFFFFFFFFFFFFF

	snake->position = Point2(SWIDTH/2, SHEIGHT/2);

	// create the scene 'tree'
	// add snake to this Scene as a child.
	this->addChild(snake);
}

/// @brief SnakeScene object destructor
SnakeScene::~SnakeScene()
{
	// deconstruct and delete the Tree
	this->removeChild(snake);

	// delete snake from the heap (there was a 'new' in the constructor)
	delete snake;
}