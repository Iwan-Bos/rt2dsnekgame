/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file snake.h
 *
 * @brief description of Snake behavior.
 */

#ifndef MYENTITY_H
#define MYENTITY_H

#include <rt2d/entity.h>
#include <rt2d/vectorx.h>

/// @brief The Snake class is the Entity implementation.
class Snake : public Entity
{
public:
	/// @brief Constructor
	Snake();
	/// @brief Destructor
	virtual ~Snake();

	/// <summary>
	/// Update function, gets called every frame.
	/// </summary>
	/// <param name="deltaTime"></param>
	virtual void update(float deltaTime);
	float currentRotation;
	float speed;

private:
	/// <summary>
	/// Ik weet niet wat koen deed hier
	/// </summary>
	/// <param name="deltaTime"></param>
	void WtfKoen(float deltaTime);

	/// <summary>
	/// Function in which the controls are recieved and converted to directions to face.
	/// </summary>
	/// <param name="deltaTime"></param>
	void Controls(float deltaTime);
};

#endif /* MYENTITY_H */
