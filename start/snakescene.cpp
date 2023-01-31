/**
 * This class describes SnakeScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "snakescene.h"
#include "snake.h"

// -------------------- constructor and deconstructor magic --------------------

SnakeScene::SnakeScene() : Scene()
{
	// construct timer.
	t = new Timer();

	// makes the randomisation seed change with time.
	srand(time(NULL));

	// create a single instance of Snake in the middle of the screen.
	// the Sprite is added in Constructor of Snake.
	snake = new Snake();

	// create a single instance of Hud in the middle of the screen.
	// the hud elements are added in Constructor of Hud.
	hud = new Hud();

	// create a new fruit instance at a random location.
	fruit = new Fruit();

	/* 
		set the positions for snake and hud to the center
		fruit gets a random location.
	*/
	snake->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	hud->position = Point2(SWIDTH / 2, SHEIGHT / 2);
	fruit->position = Point2(rand() % SWIDTH, rand() % SHEIGHT);

	// set the scale.
	hud->scale = Point3(1.25f, 1.41f, 1.0f);

	// create the scene 'tree'
	// add hud & snake to this Scene as a child.
	this->addChild(snake); 
	this->addChild(hud);
	this->addChild(fruit);
}

SnakeScene::~SnakeScene()
{
	// deconstruct and delete the Tree.
	this->removeChild(snake);
	this->removeChild(hud);
	this->removeChild(fruit);

	// delete hud & snake from the heap (there was a 'new' in the constructor)
	delete snake;
	delete hud;
	delete fruit;
}

// --------------------------------- functions ---------------------------------
void SnakeScene::update(float deltaTime)
{
	// Escape stops the scene, or when snake collides with a segment.
	if (input()->getKeyUp(KeyCode::Escape) 
		|| CheckSegmentProximity() 
		|| Bonk())
	{
		this->stop();
	}

	// when snake close enough: collect fruit, add score & add a snake segment.
	if (CheckFruitProximity())
	{
		// remove the fruit and spawn a new one.
		FruitCollect();

		// add snake segment
		this->addChild(this->AddSegment(snake->rotation));

		// add score
		score++;
	}
	// ----------------------------------- TODO: ----------------------------------
	// ------------------------------- display score ------------------------------

	// restrict input to once per 0.2 seconds
	if (!turned)
	{
		/*
			!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
			!! known issue, pressing the same direction twice will disengage the snakehead from it's trail entirely !!
			!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		*/
		// ------------------------------ 4-way movement -----------------------------
		if (input()->getKeyDown(KeyCode::W)) { snake->rotation.z = -90 * DEG_TO_RAD; AddTurnData(-90); turned = 1;}
		if (input()->getKeyDown(KeyCode::D)) { snake->rotation.z = 0 * DEG_TO_RAD; AddTurnData(0); turned = 1;}
		if (input()->getKeyDown(KeyCode::A)) { snake->rotation.z = 180 * DEG_TO_RAD - .0000001; AddTurnData(180); turned = 1;}
		if (input()->getKeyDown(KeyCode::S)) { snake->rotation.z = 90 * DEG_TO_RAD; AddTurnData(90); turned = 1;}

		//--------------------------- 4-way diagonal movment -------------------------
		if (input()->getKeyDown(KeyCode::E)) { snake->rotation.z = -45 * DEG_TO_RAD; AddTurnData(-45); turned = 1;}
		if (input()->getKeyDown(KeyCode::C)) { snake->rotation.z = 45 * DEG_TO_RAD; AddTurnData(45); turned = 1;}
		if (input()->getKeyDown(KeyCode::Z)) { snake->rotation.z = 135 * DEG_TO_RAD; AddTurnData(135); turned = 1;}
		if (input()->getKeyDown(KeyCode::Q)) { snake->rotation.z = -135 * DEG_TO_RAD; AddTurnData(-135); turned = 1;}
	}

	// when input recieved, do not allow inputs to be processed for 0.2 secs.
	if (startTimerOnce && turned)
	{
		// start timer.
		t->start();

		// don't start the timer every passthrough.
		startTimerOnce = 0;
	}

	// when vvv seconds have passed.
	if (t->seconds() >= 0.185f)
	{
		// allow processing inputs again.
		turned = 0;

		// stop the timer.
		t->stop();

		// allow timer to be started again.
		startTimerOnce = 1;
	}
}

void SnakeScene::FruitCollect()
{
	// remove fruit from memory
	this->removeChild(fruit);
	delete fruit;

	// add fruit to scene (and memory)
	fruit = new Fruit();
	this->addChild(fruit);

	// randomize the location of the newly spawned fruit
	fruit->position = Point2(rand() % SWIDTH, rand() % SHEIGHT);
}

char SnakeScene::CheckFruitProximity()
{	
	// calculates the distance in pixels the fruit is away from the snakehead.
	float distance = hypotf(fruit->position.x - snake->position.x, fruit->position.y - snake->position.y);

	/* 
	snekhead.tga = 64 x 64px
	snekbody.tga = 64 x 64px
	*/
	if (distance < 64)
	{
		return 1;
	}
	return 0;
}

char SnakeScene::CheckSegmentProximity()
{
	// do this for every segment.
	for (SnakeBody* _segment : segments)
	{
		// calculates the distance in pixels the head is away from each segment.
		float distance = hypotf(snake->position.x - _segment->position.x, snake->position.y - _segment->position.y);

		// when too close.
		if (distance < 15)
		{
			return 1;
		}
	}
	return 0;
}

char SnakeScene::Bonk()
{
	// + && - on the x axis
	if (snake->position.x >= SWIDTH || snake->position.x <= 0)
	{
		return 1;
	}

	// + && - on the y axis
	if (snake->position.y >= SHEIGHT || snake->position.y <= 0)
	{
		return 1;
	}
	return 0;
}

Entity* SnakeScene::AddSegment(Point3 _rotation)
{
	// change the segment's scope to include this function (kinda).
	SnakeBody* segment;

	// when the list has something in it.
	if (segments.size() != 0)
	{
		// leader is segment ahead. (with the index of this segment)
		segment = new SnakeBody(segments[segments.size() - 1], segments.size());

		// give the segment the rotationData list of the leader segment.
		segment->rotationData = segments[segments.size() - 1]->rotationData;
	}
	else // when the list is empty.
	{
		// leader is snake head. (with the index 0)
		segment = new SnakeBody(snake, 0);
	}

	// position segment behind leader
	segment->position -= Point2(55, 55) * Point2(cos(segment->rotation.z), sin(segment->rotation.z));

	// add segment to segment list.
	segments.push_back(segment);

	// pass the segment on to add it to the scene as a child.
	return segment;
}

void SnakeScene::AddTurnData(int _rotation)
{
	// loop through every segment and add the turn data to their lists.
	for (SnakeBody* snekSegment : segments)
	{
		// add the _rotation as direction.
		snekSegment->rotationData.push_back(_rotation);
	}
}
