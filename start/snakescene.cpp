/**
 * This class describes SnakeScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "snakescene.h"
#include "snake.h"

// --------------------------------- functions ---------------------------------
void SnakeScene::update(float deltaTime)
{
	/* Escape stops the scene */
	if (input()->getKeyUp(KeyCode::Escape)) {
		this->stop();
	}

	/* check how close the snake is, when close enough: collect fruit, add score & add a snake segment. */
	if (CheckFruitProximity())
	{
		/* remove the fruit and spawn a new one. */
		FruitCollect();

		/* add snake segment */
		this->addChild(this->AddSegment());

		/* add score */
		score++;
	}
	// ----------------------------------- TODO: ----------------------------------
	// ------------------------------- display score ------------------------------
}

void SnakeScene::FruitCollect()
{
	/* remove fruit from memory */
	this->removeChild(fruit);
	delete fruit;

	/* add fruit to scene (and memory) */
	fruit = new Fruit();
	this->addChild(fruit);

	/* randomize the location of the newly spawned fruit */
	fruit->position = Point2(rand() % SWIDTH, rand() % SHEIGHT);
}

char SnakeScene::CheckFruitProximity()
{
	/* "renaming" for simplicity's sake */
	Point3 snekpos = snake->position;
	Point3 fruitpos = fruit->position;
	
	/* pytagorasexceptspelledcorrectly */
	/* this can be done more efficiently, but I don't wanna think about that yet */
	float distance = hypotf(fruitpos.x - snekpos.x, fruitpos.y - snekpos.y);

	/* 
	snekhead.tga = 64 x 64px
	snekbody.tga = 64 x 64px
	*/
	if (distance <= 64)
	{
		return 1;
	}
	return 0;
}

Entity* SnakeScene::AddSegment()
{
	SnakeBody* segment;

	if (segments.size() != 0)
	{
		segment = new SnakeBody(segments[segments.size() - 1]);
	}
	else
	{
		segment = new SnakeBody(snake);
	}

	/* add segment to segment list. */
	segments.push_back(segment);

	/* pass the segment on to add it to the scene as a child. */
	return segment;
}

// -------------------- constructor and deconstructor magic --------------------

SnakeScene::SnakeScene() : Scene()
{
	// start the timer.
	t.start();

	// makes the randomisation seed change with time.
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

	/* set the positions */
	snake->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	hud->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	fruit->position = Point2(rand() % SWIDTH, rand() % SHEIGHT);

	/* set the scale */
	hud->scale = Point3(1.25f, 1.41f, 1.0f);

	// create the scene 'tree'
	// add hud & snake to this Scene as a child.
	this->addChild(snake); 
	this->addChild(hud);
	this->addChild(fruit);
}

SnakeScene::~SnakeScene()
{
	// deconstruct and delete the Tree
	this->removeChild(snake);
	this->removeChild(hud);
	this->removeChild(fruit);

	// delete hud & snake from the heap (there was a 'new' in the constructor)
	delete snake;
	delete hud;
	delete fruit;
}
