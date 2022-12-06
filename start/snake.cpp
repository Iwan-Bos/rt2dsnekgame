/*****************************************************************//**
 * \file   snake.cpp
 * \brief  Class in which the head of the snake is moved
 * 
 * \author iwanb
 * \date   December 2022
 *********************************************************************/

#include "snake.h"

// Variables
Point3 velocity = Point3();
Point3 acceleration = Point3();
float timer = .0f;
int amp = 100.0f;
float freq = .05f;
float anchorY = SHEIGHT /2;


Snake::Snake() : Entity()
{
	this->addSprite("assets/snekhead.tga");
	//this->sprite()->color = RGBAColor(255, 133, 211);
}

Snake::~Snake()
{
}

void Snake::Controls(float deltaTime)
{
	// Local variables
	speed = 100 * deltaTime;
	currentRotation = this->rotation.z * 180 / PI;
	currentRotation = fmod(currentRotation, 180);

	// ###########################
	//   WASD for 4-way movement
	// ###########################
	//if (input()->getKey(KeyCode::W)) { VectorX_t<t>::rotateDeg(); }
	if (input()->getKey(KeyCode::D)) { this->rotation.z = 0; }
	if (input()->getKey(KeyCode::A)) { this->rotation.z = PI - 0.0001; }
	if (input()->getKey(KeyCode::S)) { this->rotation.z = PI / 2; }

	// ###################################
	//   UIJK for 4-way diagonal movment
	// ###################################
	if (input()->getKey(KeyCode::Up)) { this->rotation.z = -PI / 4; } // UpRight
	if (input()->getKey(KeyCode::Right)) { this->rotation.z = PI / 4; } // DownRight
	if (input()->getKey(KeyCode::Down)) { this->rotation.z = PI / 4 * 3; } // DownLeft
	if (input()->getKey(KeyCode::Left)) { this->rotation.z = -PI / 4 * 3; } // UpLeft
}

void Snake::WtfKoen(float deltaTime) 
{
	// Koen wtf is dit
	this->position.x += (cos(0.017453277777 * currentRotation)) * speed;
	this->position.y += (sin(0.017453277777 * currentRotation)) * speed;
}

void Snake::update(float deltaTime)
{
	Controls(deltaTime);
	WtfKoen(deltaTime);
}
