/**

    @file      snakebody.h
    @brief     header for snakebody.cpp
    @author    Iwan Bos
    @date      6.12.2022
    @copyright © Iwan Bos, 2022. All right reserved.

**/

#ifndef SNAKEBODY_H
#define SNAKEBODY_H

#include "rt2d/entity.h"

/**
    @class   SnakeBody
    @brief   The trail of snake parts following the head.
**/
class SnakeBody : public Entity
{
// ----------------------------------- public ----------------------------------
public:
	/// @brief SnakeBody object constructor
	SnakeBody(Entity* _leader, int _index);

	/// @brief SnakeBody object destructor 
	virtual ~SnakeBody();

	virtual void update(float deltaTime);

	/// @brief a list of the degrees the head turned to.
	std::vector<int> rotationData;

// ---------------------------------- private ----------------------------------
private:
	/// @brief timer for segment turn delay.
	Timer* t;

	/// @brief the snake segment leading this one.
	Entity* leader;
	
	/// @brief speed of the snakebody
	float speed;
	/// @brief the time to wait before moving
	float waitDuration;
	/// @brief the current rotation of the segment leading this one.
	float leaderCurrentRotation;
	/// @brief the index of the segment (in the segments list).
	int index;
	/// @brief char to only start the timer once per segment check.
	char timerInactive;
};

#endif // !SNAKEBODY_H
