/*********************************************************************  
** Program Filename: Hallway.hpp
** Author: Eric Podolsky   
** Date: 5 June 2016
** Description: Header file for the Hallway class
** Input: N/A
** Output: Console
*********************************************************************/

#ifndef PODOLSKE_HALLWAY_HPP
#define PODOLSKE_HALLWAY_HPP

#include "Space.hpp"

class Hallway: public Space {
public:
	Hallway();
	Item use(Item it);
private:
};

#endif