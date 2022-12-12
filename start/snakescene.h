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
		 @param deltaTime - 
	**/
	virtual void update(float deltaTime);

 // ---------------------------------- private ---------------------------------
private:
	/// @brief the hud layer
	Hud* hud;
	/// @brief the snake head
	Snake* snake;
	Timer t;
};

#endif /* SNAKESCENE_H */
