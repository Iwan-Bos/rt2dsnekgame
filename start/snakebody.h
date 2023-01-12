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
	SnakeBody(Entity* _leader);

	/// @brief SnakeBody object destructor 
	virtual ~SnakeBody();

	virtual void update(float deltaTime);

// ---------------------------------- private ----------------------------------
private:
	/// @brief list of waypoints
	std::vector<Point3>waypoints;

	/// @brief timer for waitDuration.
	Timer* t;

	/// @brief the snake segment leading this one.
	Entity* leader;
	
	/// @brief speed of the snakebody
	float speed;
	/// @brief the time to wait before moving
	float waitDuration;

	/// @brief movement of the SnakeBody
	void Move(float deltaTime);
};

#endif // !SNAKEBODY_H
