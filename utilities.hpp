/*********************************************************************  
** Program Filename: utilities.hpp
** Author: Eric Podolsky   
** Date: 1 May 2016
** Description: A set of utility functions
** Input: N/A
** Output: N/A
*********************************************************************/

#ifndef PODOLSKE_UTILITIES_HPP
#define PODOSLKE_UTILTIIES_HPP


#include <iostream>
#include <string>

using std::string;

//DECLARATIONS

//INPUT VALIDATION FUNCTIONS
void checkType(int& i);
void checkType(char& c);
void checkPositive(int& i);
void checkPositive(double& i);
void checkGreaterThan(int& i, const int j);
void checkRange(int& i, const int bound1, const int bound2);
void checkYN(char& c);

//DYNAMIC MEMORY MANAGEMENT
/*********************************************************************  
** Function: resizeArray(T*&, const int, int&)
** Description: Doubles the capacity of a dynamic array
** Parameters: arr - the pointer to the start of the array
               numElements - the number of elements in the array
			   arraySize - the current size of the array
** Pre-Conditions: 
** Post-Conditions: arraySize is doubled, arr points to an array with
                    double the capacity
*********************************************************************/ 
template <typename T>
void resizeArray(T*& arr, const size_t numElements, size_t& arraySize) {
	T* new_array = new T[arraySize*2];
	for(int i = 0; i < numElements; ++i) {
		new_array[i] = arr[i];
	}

	delete [] arr;

	arr = new_array;

	arraySize = arraySize * 2;
}

#endif