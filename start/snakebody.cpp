/**

    @file      snakebody.cpp
    @brief     the segments that follow the snakehead.
    @author    Iwan Bos
    @date      6.12.2022
    @copyright © Iwan Bos, 2022. All right reserved.

**/

#include "snakebody.h"

// ---------------------- Contructor & Deconstructor Magic ---------------------
SnakeBody::SnakeBody(Entity* _leader,int _index)
{
	this->addSprite("assets/start/snekbody.tga");
	waitDuration = 0.185f;
	speed = 300;
	
	// initial position and rotation of snakebody.
	this->position = _leader->position;
	this->rotation.z = _leader->rotation.z;
	
	// make and start a timer for the wait duration.
	t = new Timer();

	// global vars.
	rotationData;
	index = _index;
	leader = _leader;
	leaderCurrentRotation = leader->rotation.z;
	timerInactive = 1;
}

SnakeBody::~SnakeBody()
{
}

// --------------------------------- Functions ---------------------------------

void SnakeBody::update(float deltaTime)
{
	// moves snakebody in the current facing direction.
	this->position.x += cos(this->rotation.z) * speed * deltaTime;
	this->position.y += sin(this->rotation.z) * speed * deltaTime;

	/*
		save the rotation of the leader segment.
		continuously check for a change in that number.
		on change:
		leader turned.
		leader's current rotation = what it turned to.
	*/
	//jumps in once when the snake turns && when the timer has started to loop through.
	if (leaderCurrentRotation != leader->rotation.z||!timerInactive)
	{
		//start timer when previous statement returned true for the first check.
		if (timerInactive)
		{
			// start the timer once in $waitDuration seconds.
			t->start();

			timerInactive = 0;
		}

		// when the list of rotation has somethin in it.
		if (!rotationData.empty())
		{
			// when the timer reaches $waitDuration seconds.
			if (t->seconds() >= waitDuration)
			{
				// after $waitDuration seconds
				if (t->seconds() >= waitDuration)
				{
					// stop the timer & set char to 0, for the next turn point.
					t->stop();
					timerInactive = 1;

					// take the first element in the rotationData and turn in that direction.
					this->rotation.z = this->rotationData[0] * DEG_TO_RAD;

					// then delete that element and restart this loop.
					this->rotationData.erase(rotationData.begin());
				}
			}
		}
		// update the rotation tracking thing.
		leaderCurrentRotation = leader->rotation.z;
	}
}