/**

    @file      snakescene.h
    @brief     header file for snakescene.cpp
    @author    Iwan Bos
    @date      6.12.2022
    @copyright © Iwan Bos, 2022. All right reserved.

**/

#ifndef SNAKESCENE_H
#define SNAKESCENE_H

#include <rt2d/scene.h>
#include "snakescene.h"
#include "hud.h"
#include "snake.h"
#include "fruit.h"

/**
    @class   SnakeScene
    @brief   The SnakeScene class is the Scene implementation.
**/
class SnakeScene : public Scene
{
 // ---------------------------------- public ----------------------------------
public:
	/// @brief Constructor
	SnakeScene();
	/// @brief Destructor
	virtual ~SnakeScene();
	
	/**
		@brief sends the place of turning and direction to every segment.
	**/
	void AddTurnData(int _rotation);

 // ---------------------------------- private ---------------------------------
private:
	/// @brief the hud layer
	Hud* hud;
	/// @brief the snake head
	Snake* snake;
	/// @brief fruit collectable, default nullptr
	Fruit* fruit = nullptr;
	/// @brief timer
	Timer* t;
	/// @brief list of segments
	std::vector<SnakeBody*> segments;

	/// @brief turns true on turn
	char turned;
	/// @brief char to only start the timer once per segment check.
	char startTimerOnce;
	/// @brief the length and score of the player
	int score = 0;

	 /**
		 @brief update function, called once a frame.
		 @param deltaTime - The time that's passed since the last update.
	 **/
	virtual void update(float deltaTime);
	 /**
		 @brief called when fruit is collected by the snake
	 **/
	void FruitCollect();
	 /**
		 @brief  checks if the snake is close enough to collect the fruit, returns 1 if it collides.
		 @retval char - 1 for true, 0 for false.
	 **/
	char CheckFruitProximity();
	 /**
		 @brief  calculates the distance in pixels the head is away from each segment, returns 1 if it collides.
		 @retval char - 1 for true, 0 for false.
	 **/
	char CheckSegmentProximity();
	 /**
		 @brief  returns 1 when the snakehead is touching the border.
		 @retval char - 1 for true, 0 for false.
	 **/
	char Bonk();
	 /**
		 @brief  adds a segment to the snake.
		 @param  _rotation - the rotation of the leader in radians
		 @retval Entity*   - an Entity pointer.
	 **/
	Entity* AddSegment(Point3 _rotation);
};

#endif /* SNAKESCENE_H */
