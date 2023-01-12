/**

	@file      snake.h
	@brief     header for snake.cpp
	@author    Iwan Bos
	@date      6.12.2022
	@copyright © Iwan Bos, 2022. All right reserved.

**/

#ifndef SNAKE_H
#define SNAKE_H

#include <rt2d/entity.h>
#include "snakebody.h"

/// @brief The Snake class is the Entity implementation.
class Snake : public Entity
{
 // ---------------------------------- public ----------------------------------
public:
	/// @brief Constructor
	Snake();
	/// @brief Destructor
	virtual ~Snake();

	/**
		 @brief Update function, gets called every frame.
		 @param deltaTime - The time that's passed since the last update.
	**/
	virtual void update(float deltaTime);

 // ---------------------------------- private ---------------------------------
private:
	/// @brief speed of the snakehead
	float speed;
	/// @brief a bool that turns true when the snake turns
	char turned;
	

	/**
		 @brief moves the snake head forward in the facing direction.
		 @param deltaTime - The time that's passed since the last update.
	**/
	void Move(float deltaTime);
	/**
		 @brief controls are recieved and converted to directions to face.
		 @param deltaTime - The time that's passed since the last update.
	**/
	void Controls(float deltaTime);
};

#endif /* SNAKE_H */
