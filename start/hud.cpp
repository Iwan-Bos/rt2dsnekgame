/**

    @file      hud.cpp
    @brief     the top layer of sprites
    @author    Iwan Bos
    @date      8.12.2022
    @copyright © Iwan Bos, 2022. All right reserved.

**/

#include "hud.h"

// --------------------------------- functions ---------------------------------

void Hud::update(float deltaTime)
{

}

// --------------------- constructor & deconstructor magic ---------------------

Hud::Hud()
{
	this->addSprite("assets/start/border.tga");
}

Hud::~Hud()
{
}
