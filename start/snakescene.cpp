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

	// removing the fruit and adding score.
	// done with a keybind since collision is not a thing yet. 
	// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ #### TEMPORARY ####
	if (input()->getKeyUp(KeyCode::Space)) { FruitCollect(); }
}

void SnakeScene::FruitCollect()
{
	// remove fruit
	this->removeChild(fruit);
	delete fruit;

	// add score
	score++;

	// print score
	// ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ #### TEMPORARY ####
	std::cout << score << std::endl;


	// spawn new fruit
	SpawnFruit();
}

void SnakeScene::SpawnFruit()
{
	// adding fruit to scene
	fruit = new Fruit();
	this->addChild(fruit);

	// random location for fruit
	fruit->position = Point2(rand() % SWIDTH, rand() % SHEIGHT);
}

// -------------------- constructor and deconstructor magic --------------------

/// @brief SnakeScene object constructor
SnakeScene::SnakeScene() : Scene()
{
	// start the timer.
	t.start();

	// makes the randomisation seed change with time;
	srand(time(NULL));

	// create a single instance of Snake in the middle of the screen.
	// the Sprite is added in Constructor of Snake.
	snake = new Snake();

	// create a single instance of Hud in the middle of the screen.
	// the hud elements are added in Constructor of Hud.
	hud = new Hud();

	// create a new fruit instance at a random location.
	// this is the only for the first fruit.
	fruit = new Fruit();

	hud->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	snake->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	fruit->position = Point2(rand() % SWIDTH, rand() % SHEIGHT);

	// create the scene 'tree'
	// add hud & snake to this Scene as a child.
	this->addChild(hud);
	this->addChild(snake); 
	this->addChild(fruit);
}

/// @brief SnakeScene object destructor
SnakeScene::~SnakeScene()
{
	// deconstruct and delete the Tree
	this->removeChild(hud);
	this->removeChild(snake);
	this->removeChild(fruit);

	// delete hud & snake from the heap (there was a 'new' in the constructor)
	delete hud;
	delete snake;
	delete fruit;
}