/*********************************************************************  
** Program Filename: Room.hpp
** Author: Eric Podolsky   
** Date: 5 June 2016
** Description: Header file for the Room class
** Input: N/A
** Output: Console
*********************************************************************/

#ifndef PODOLSKE_ROOM_HPP
#define PODOLSKE_ROOM_HPP

#include "Space.hpp"

class Room: public Space {
public:
	Room();
	Item use(Item it);
private:
};

#endif