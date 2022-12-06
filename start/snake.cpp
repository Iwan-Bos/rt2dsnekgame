/*****************************************************************//**
 * \file   snake.cpp
 * \brief  Class in which the head of the snake is moved
 * 
 * \author iwanb
 * \date   December 2022
 *********************************************************************/

#include "snake.h"

// Variables
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
Point3 velocity = Point3();
Point3 acceleration = Point3();
float timer = .0f;
int amp = 100.0f;
float freq = .05f;
float anchorY = SHEIGHT /2;
//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

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
	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	speed = 100 * deltaTime;
	currentRotation = this->rotation.z * 180 / PI;
	currentRotation = fmod(currentRotation, 180);
	//+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
	
	// ##################################
	//   W, D A, & S for 4-way movement
	// ##################################
	if (input()->getKey(KeyCode::W)) { this->rotation.z = -90 * DEG_TO_RAD; } // Up
	if (input()->getKey(KeyCode::D)) { this->rotation.z = 0 * DEG_TO_RAD; } // Right
	if (input()->getKey(KeyCode::A)) { this->rotation.z = 180 * DEG_TO_RAD - .0000001; } // Left
	if (input()->getKey(KeyCode::S)) { this->rotation.z = 90 * DEG_TO_RAD; } // Downs

	// #####################################################
	//   Up, Right, Down & Left for 4-way diagonal movment
	// #####################################################
	if (input()->getKey(KeyCode::Up)) { this->rotation.z = -45 * DEG_TO_RAD; } // UpRight
	if (input()->getKey(KeyCode::Right)) { this->rotation.z = 45 * DEG_TO_RAD; } // DownRight
	if (input()->getKey(KeyCode::Down)) { this->rotation.z = 135 * DEG_TO_RAD; } // DownLeft
	if (input()->getKey(KeyCode::Left)) { this->rotation.z = -135 * DEG_TO_RAD; } // UpLeft
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
