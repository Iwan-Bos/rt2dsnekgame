/**

    @file      hud.h
    @brief     header file for hud.cpp
    @author    Iwan Bos
    @date      8.12.2022
    @copyright © Iwan Bos, 2022. All right reserved.

**/

#ifndef HUD_H
#define HUD_H

#include <rt2d/entity.h>

class Hud : public Entity
{
 // ---------------------------------- public ----------------------------------
public:
	/// @brief Fruit object constructor
	Hud();
	/// @brief Fruit object deconstructor
	virtual ~Hud();

 // ---------------------------------- private ---------------------------------
private:
 /**
     @brief gets called every frame
     @param deltaTime - The time that's passed since the last update.
 **/
	virtual void update(float deltaTime);
};

#endif // !HUD_H

