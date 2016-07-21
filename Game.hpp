/*********************************************************************  
** Program Filename: Game.hpp
** Author: Eric Podolsky   
** Date: 5 June 2016
** Description: Header file for the Game class
** Input: Console
** Output: Console
*********************************************************************/

#include "Cursed.hpp"
#include "Hallway.hpp"
#include "Bathroom.hpp"
#include "Room.hpp"

#include <iostream>
using std::cout;
using std::cin;

class Game {
public:
	Game();
	~Game();
	void Play();

private:
	//helper functions
	void Setup();
	void Info();
	bool Move(char direction);
	bool isNull(Space* ptr);
	void Curse(Space* room);
	void Damage();
	void Input();
	void addToInventory(size_t index);
	bool useItem();
	bool combineItems();
	bool InventoryMenu();
	
	void destructor_helper(Space* curr);
	
	//player stats and inventory
	static const size_t INV_SIZE = 3;
	Item inventory[INV_SIZE];
	size_t num_inv;
	Space* current;
	int health;
	bool victory;
	int time_left;
};