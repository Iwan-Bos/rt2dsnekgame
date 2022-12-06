/**

    @file      snakescene.h
    @brief     header for snakescene.cpp
    @author    Iwan Bos
    @date      6.12.2022
    @copyright © Iwan Bos, 2022. All right reserved.

**/

#ifndef MYSCENE_H
#define MYSCENE_H

#include <rt2d/scene.h>
#include "snakescene.h"
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
	/// @brief the snake head
	Snake* snake;
	Timer t;
};

#endif /* SCENE00_H */
