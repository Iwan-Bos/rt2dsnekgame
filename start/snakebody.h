/**

    @file      snakebody.h
    @brief     header for snakebody.cpp
    @author    Iwan Bos
    @date      6.12.2022
    @copyright © Iwan Bos, 2022. All right reserved.

**/

#ifndef SNAKEBODY_H
#define SNAKEBODY_H

#include "snake.h"

/**
    @class   SnakeBody
    @brief   The trail of snake parts following the head.
**/
class SnakeBody : public Snake
{
// ----------------------------------- public ----------------------------------
public:
	/// @brief SnakeBody object constructor
	SnakeBody();

	/// @brief SnakeBody object destructor 
	virtual ~SnakeBody();

// ---------------------------------- private ----------------------------------
private:

};

#endif // !SNAKEBODY_H
