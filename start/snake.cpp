/**

    @file      snake.cpp
    @brief     the head of the snake
    @author    Iwan Bos
    @date      6.12.2022
    @copyright © Iwan Bos, 2022. All right reserved.

**/

#include "snake.h"
#include "snakebody.h"
#include "snakescene.h"

// ---------------------- Construct & Deconstructing magic ---------------------
Snake::Snake() : Entity()
{
	this->addSprite("assets/start/snekhead.tga");
	speed = 300;
}

Snake::~Snake()
{
}

// --------------------------------- Functions ---------------------------------

void Snake::update(float deltaTime)
{
	// moves snake,
	// uses cosine and sine functions to decide the velocity.
	this->position.x += (cos(this->rotation.z)) * speed * deltaTime;
	this->position.y += (sin(this->rotation.z)) * speed * deltaTime;
}
