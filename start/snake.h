/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file snake.h
 *
 * @brief description of Snake behavior.
 */

#ifndef MYENTITY_H
#define MYENTITY_H
#define PI 3.14159265358979323846

#include <rt2d/entity.h>

/// @brief The Snake class is the Entity implementation.
class Snake : public Entity
{
public:
	/// @brief Constructor
	Snake();
	/// @brief Destructor
	virtual ~Snake();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	float currentRotation;
	float speed;

private:
	/* add your private declarations */
	void Move(float deltaTime);
	void Controls(float deltaTime);
};

#endif /* MYENTITY_H */
