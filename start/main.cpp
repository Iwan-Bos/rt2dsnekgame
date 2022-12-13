/**

    @file      main.cpp
    @brief     Snake without grid system and additional movement options.
    @section   

	@author    Iwan Bos
    @date      6.12.2022
    @copyright © Iwan Bos, 2022. All right reserved.

**/

#include <rt2d/core.h>

#include "snakescene.h"

/**
    @brief  main entry point
    @retval  - 
**/
int main( void )
{
	// @brief Core instance
	Core core;

	// Scene01
	SnakeScene* canvas = new SnakeScene(); // create Scene on the heap
	while(canvas->isRunning()) { // check status of Scene every frame
		core.run(canvas); // update and render the current scene
		core.showFrameRate(5); // show framerate in output every n seconds
	}
	//core.cleanup(); // cleanup ResourceManager (Textures + Meshes, but not Shaders)
	delete canvas; // delete Scene and everything in it from the heap to make space for next Scene

	// No need to explicitly clean up the core.
	// As a local var, core will go out of scope and destroy Renderer->ResourceManager.
	// ResourceManager destructor also deletes Shaders.

	return 0;
}
