/**

    @file      fruit.h
    @brief     header file for fruit.cpp
    @author    Iwan Bos
    @date      8.12.2022
    @copyright © Iwan Bos, 2022. All right reserved.

**/

#ifndef FRUIT_H
#define FRUIT_H

#include <rt2d/entity.h>

class Fruit : public Entity
{
 // ---------------------------------- public ----------------------------------
public:
	/// @brief Fruit object constructor
	Fruit();
	/// @brief Fruit object deconstructor
	virtual ~Fruit();

 // ---------------------------------- private ---------------------------------
private:
 /**
     @brief gets called every frame
     @param deltaTime - 
 **/
	virtual void update(float deltaTime);
};

#endif // !HUD_H

