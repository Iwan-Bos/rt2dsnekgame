/**

    @file      snake.cpp
    @brief     the head of the snake
    @author    Iwan Bos
    @date      6.12.2022
    @copyright © Iwan Bos, 2022. All right reserved.

**/

#include "snake.h"
#include "snakebody.h"

// --------------------------------- Functions ---------------------------------

void Snake::Controls(float deltaTime)
{
	// decide the speed of snake.
	speed = Boost();

	// get the current rotation of the snake head.
	currentRotation = fmod(this->rotation.z * 180 / PI, 180);

	/* ###### Controls ######
				W
		Q	   -90      E
				^
				|
	-180        |
	A   <-------+------->0	D
	 180        |
				|
				v
		Z		90		 C
				S

	Boost = J
	*/

	if (speed != 500)
	{
		// ------------------------------ 4-way movement -----------------------------
		/* Up			*/if (input()->getKey(KeyCode::W)) {this->rotation.z = -90 * DEG_TO_RAD;}
		/* Right		*/if (input()->getKey(KeyCode::D)) {this->rotation.z = 0 * DEG_TO_RAD;}
		/* Left			*/if (input()->getKey(KeyCode::A)) {this->rotation.z = 180 * DEG_TO_RAD -.0000001;}
		/* Down			*/if (input()->getKey(KeyCode::S)) {this->rotation.z = 90 * DEG_TO_RAD;}

		// -------------------------- 4-way diagonal movment -------------------------
		/* Up Right		*/if (input()->getKey(KeyCode::E)) {this->rotation.z = -45 * DEG_TO_RAD;}
		/* Down Right	*/if (input()->getKey(KeyCode::C)) {this->rotation.z = 45 * DEG_TO_RAD;}
		/* Down Left	*/if (input()->getKey(KeyCode::Z)) {this->rotation.z = 135 * DEG_TO_RAD;}
		/* Up Left		*/if (input()->getKey(KeyCode::Q)) {this->rotation.z = -135 * DEG_TO_RAD;}
	}
}

void Snake::Move(float deltaTime) 
{
	/* moves in the current facing direction */
	this->position.x += (cos(0.017453277777 * currentRotation)) * speed * deltaTime;
	this->position.y += (sin(0.017453277777 * currentRotation)) * speed * deltaTime;
}

float Snake::Boost()
{
	/* when pressing J. */
	if (input()->getKey(KeyCode::J))
	{
		/* set speed to 500. */
		return 500.0f;
	}
	/* and otherwise to 150. */
	return 300.0f;
}

void Snake::update(float deltaTime)
{
	/* 
	changes direction of the snake. 
	boosting is also controlled here.
	*/
	Controls(deltaTime);

	/* moves the snake forward in the facing direction. */
	Move(deltaTime);
}

void Snake::AddSegment()
{
	SnakeBody* segment = new SnakeBody();
	segment->position = Point2(rand() % SWIDTH, rand() % SHEIGHT);
}

// ---------------------- Construct & Deconstructing magic ---------------------
Snake::Snake() : Entity()
{
	this->addSprite("assets/start/snekhead.tga");
}

Snake::~Snake()
{
}