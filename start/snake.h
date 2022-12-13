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
	/// @brief current rotation of the snakehead
	float currentRotation;
	/// @brief speed of the snakehead
	float speed;

	/**
		 @brief Ik weet niet wat koen deed hier
		 @param deltaTime - The time that's passed since the last update.
	**/
	void Move(float deltaTime);
	/**
		 @brief Controls are recieved and converted to directions to face.
		 @param deltaTime - The time that's passed since the last update.
	**/
	void Controls(float deltaTime);
	 /**
		 @brief  decides the speed of the snake.
		 @retval float - the speed the snake should go.
	 **/
	float Boost();
	 /**
		 @brief adds a segment to the snake.
	 **/
	void AddBodyPart();
};

#endif /* SNAKE_H */
