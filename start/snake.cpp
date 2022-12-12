/**

    @file      snake.cpp
    @brief     
    @author    Iwan Bos
    @date      6.12.2022
    @copyright © Iwan Bos, 2022. All right reserved.

**/

#include "snake.h"

// --------------------------------- Variables ---------------------------------
	float speed = 100;

// --------------------------------- Functions ---------------------------------

void Snake::Controls(float deltaTime)
{
	// get the current rotation of the snake head.
	currentRotation = this->rotation.z * 180 / PI;
	currentRotation = fmod(currentRotation, 180);

/*
	       -90
		    ^
		    |
-180        |
   <--------+------->0
 180        |
		    |
		    v
		    90
 */
 // ---------------------- W, D A, & S for 4-way movement ----------------------
	if (input()->getKey(KeyCode::W)) { this->rotation.z = -90 * DEG_TO_RAD; }
	if (input()->getKey(KeyCode::D)) { this->rotation.z = 0 * DEG_TO_RAD; }
	if (input()->getKey(KeyCode::A)) { this->rotation.z = 180 * DEG_TO_RAD - .0000001; }
	if (input()->getKey(KeyCode::S)) { this->rotation.z = 90 * DEG_TO_RAD; }

 // ------------- Up, Right, Down & Left for 4-way diagonal movment ------------
	if (input()->getKey(KeyCode::Up)) { this->rotation.z = -45 * DEG_TO_RAD; }
	if (input()->getKey(KeyCode::Right)) { this->rotation.z = 45 * DEG_TO_RAD; }
	if (input()->getKey(KeyCode::Down)) { this->rotation.z = 135 * DEG_TO_RAD; }
	if (input()->getKey(KeyCode::Left)) { this->rotation.z = -135 * DEG_TO_RAD; }
}

void Snake::Move(float deltaTime) 
{
	// moves in the current facing direction
	this->position.x += (cos(0.017453277777 * currentRotation)) * speed * deltaTime;
	this->position.y += (sin(0.017453277777 * currentRotation)) * speed * deltaTime;
}

void Snake::update(float deltaTime)
{
	Controls(deltaTime);
	Move(deltaTime);
}

// ---------------------- Construct & Deconstructing magic ---------------------
Snake::Snake() : Entity()
{
	this->addSprite("assets/start/snekhead.tga");
}

Snake::~Snake()
{
}