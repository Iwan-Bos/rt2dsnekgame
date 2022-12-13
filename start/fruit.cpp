/**

    @file      fruit.cpp
    @brief     
    @author    Iwan Bos
    @date      8.12.2022
    @copyright © Iwan Bos, 2022. All right reserved.

**/

#include "fruit.h"

// --------------------------------- functions ---------------------------------

void Fruit::update(float deltaTime)
{

}

// --------------------- constructor & deconstructor magic ---------------------

Fruit::Fruit()
{
	this->addSprite("assets/start/fruit.tga");
}

Fruit::~Fruit()
{
}
