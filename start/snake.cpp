/**
 * This class describes Snake behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "snake.h"

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
	speed = 100 * deltaTime;
	currentRotation = this->rotation.z * 180 / PI;
	currentRotation = fmod(currentRotation, 180);

	// ###########################
	//   WASD for 4-way movement
	// ###########################
	if (input()->getKey(KeyCode::W)) {
		this->rotation.z = -PI / 2; // UP
	}
	if (input()->getKey(KeyCode::A)) {
		this->rotation.z = PI - 0.0001; // LEFT
	}
	if (input()->getKey(KeyCode::S)) {
		this->rotation.z = PI / 2; // DOWN
	}
	if (input()->getKey(KeyCode::D)) {
		this->rotation.z = 0; // RIGHT
	}

	// ###################################
	//   UIJK for 4-way diagonal movment
	// ###################################
	if (input()->getKey(KeyCode::Up)) {
		this->rotation.z = -PI / 4; // North East
	}
	if (input()->getKey(KeyCode::Left)) {
		this->rotation.z = -PI / 4 * 3; // North West
	}
	if (input()->getKey(KeyCode::Right)) {
		this->rotation.z = PI / 4; // South East
	}
	if (input()->getKey(KeyCode::Down)) {
		this->rotation.z = PI / 4 * 3; // South West
	}
}

void Snake::Move(float deltaTime) 
{
	// Koen wtf is dit
	this->position.x += (cos(0.017453277777 * currentRotation)) * speed;
	this->position.y += (sin(0.017453277777 * currentRotation)) * speed;
}

void Snake::update(float deltaTime)
{
	Controls(deltaTime);
	Move(deltaTime);
}
