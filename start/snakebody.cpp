/**

    @file      snakebody.cpp
    @brief     the segments that follow the snakehead.
    @author    Iwan Bos
    @date      6.12.2022
    @copyright © Iwan Bos, 2022. All right reserved.

**/

#include "snakebody.h"

// ---------------------- Contructor & Deconstructor Magic ---------------------
SnakeBody::SnakeBody(Entity* _leader)
{
	this->addSprite("assets/start/snekbody.tga");
	waitDuration = 0.2;
	speed = 300;
	
	/* initial position and rotation of snakebody */
	this->position = _leader->position;
	this->rotation.z = _leader->rotation.z;
	
	/* make and start a timer for the wait duration */
	t = new Timer();
	t->start();
}

SnakeBody::~SnakeBody()
{
}


// --------------------------------- Functions ---------------------------------
void SnakeBody::update(float deltaTime)
{
	if (t->seconds() >= waitDuration)
	{
		Move(deltaTime);
		t->pause();
	}
}

void SnakeBody::Move(float deltaTime)
{
	/* moves in the current facing direction */
	this->position.x += (cos(this->rotation.z)) * speed * deltaTime;
	this->position.y += (sin(this->rotation.z)) * speed * deltaTime;
}