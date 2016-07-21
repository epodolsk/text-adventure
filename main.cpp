/*********************************************************************  
** Program Filename: main.cpp
** Author: Eric Podolsky   
** Date: 5 June 2016
** Description: Interface file for the Demon Quest game
** Input: N/A
** Output: N/A
*********************************************************************/

#include <iostream>
#include "Game.hpp"

int main() {
	Game g1;
	char yn;
	std::cout << "For grader: Would you like to know how to beat the game (y/n)? " << std::endl;
	std::cin >> yn;
	checkYN(yn);
	if(yn == 'y' || yn == 'Y') {
		std::cout << "Steps to victory: " << std::endl;
		std::cout << "1. Take the candle from the living room" << std::endl;
		std::cout << "2. Use it in the hallway to light it" << std::endl;
		std::cout << "3. Take the demon disintegrator from the garage" << std::endl;
		std::cout << "4. Take the mini steam turbine from the guest room" << std::endl;
		std::cout << "5. Use the lit candle in the bathroom to generate steam" << std::endl;
		std::cout << "6. Combine the demon disintegrator and the steam turbine" << std::endl;
		std::cout << "7. Use the resulting item in the bathroom" << std::endl;
		std::cout << "8. Use the activated demon disintegrator in a cursed room to win" << std::endl << std::endl;
	}
	std::cout << "Start the game? (y/n) " << std::endl;
	std::cin >> yn;
	checkYN(yn);
	if(yn=='y' || yn == 'Y') {
		g1.Play();
	}
	else {
		std::cout << "Exiting..." << std::endl;
	}
	return 0;
}
