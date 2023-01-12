/**

    @file      snake.cpp
    @brief     the head of the snake
    @author    Iwan Bos
    @date      6.12.2022
    @copyright © Iwan Bos, 2022. All right reserved.

**/

#include "snake.h"
#include "snakebody.h"

// ---------------------- Construct & Deconstructing magic ---------------------
Snake::Snake() : Entity()
{
	this->addSprite("assets/start/snekhead.tga");

	speed = 300;
	turned = 0;
}

Snake::~Snake()
{
}

// --------------------------------- Functions ---------------------------------

void Snake::Controls(float deltaTime)
{
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

	turned = 0;
		
	// ------------------------------ 4-way movement -----------------------------
	/* Up			*/if (input()->getKey(KeyCode::W)) { this->rotation.z = -90 * DEG_TO_RAD; turned = 1;}
	/* Right		*/if (input()->getKey(KeyCode::D)) { this->rotation.z = 0 * DEG_TO_RAD; turned = 1;}
	/* Left			*/if (input()->getKey(KeyCode::A)) { this->rotation.z = 180 * DEG_TO_RAD - .0000001; turned = 1;}
	/* Down			*/if (input()->getKey(KeyCode::S)) { this->rotation.z = 90 * DEG_TO_RAD; turned = 1;}

	// -------------------------- 4-way diagonal movment -------------------------
	/* Up Right		*/if (input()->getKey(KeyCode::E)) { this->rotation.z = -45 * DEG_TO_RAD; turned = 1;}
	/* Down Right	*/if (input()->getKey(KeyCode::C)) { this->rotation.z = 45 * DEG_TO_RAD; turned = 1;}
	/* Down Left	*/if (input()->getKey(KeyCode::Z)) { this->rotation.z = 135 * DEG_TO_RAD; turned = 1;}
	/* Up Left		*/if (input()->getKey(KeyCode::Q)) { this->rotation.z = -135 * DEG_TO_RAD; turned = 1;}
}

void Snake::Move(float deltaTime) 
{
	/* uses cosine and sine functions to decide the velocity. */
	this->position.x += (cos(this->rotation.z)) * speed * deltaTime;
	this->position.y += (sin(this->rotation.z)) * speed * deltaTime;
}

void Snake::update(float deltaTime)
{
	Controls(deltaTime);
	Move(deltaTime);
}
