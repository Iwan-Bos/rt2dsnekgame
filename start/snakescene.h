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
		 @brief update function, called once a frame.
		 @param deltaTime - The time that's passed since the last update.
	 **/
	virtual void update(float deltaTime);
	 /**
		 @brief called when fruit is collected by the snake
	 **/
	void FruitCollect();
	 /**
		 @brief check if the snake is close enough to collect the fruit.
	 **/
	char CheckFruitProximity();

	/**
		@brief  adds a segment to the snake.
		@retval Entity* - an Entity pointer.
	**/
	Entity* AddSegment();


	/// @brief list of segments
	std::vector<SnakeBody*> segments;

 // ---------------------------------- private ---------------------------------
private:
	/// @brief the hud layer
	Hud* hud;
	/// @brief the snake head
	Snake* snake;
	/// @brief fruit collectable, default nullptr
	Fruit* fruit = nullptr;
	/// @brief timer
	Timer t;

	/// @brief the length and score of the player
	int score = 0;
};

#endif /* SNAKESCENE_H */
