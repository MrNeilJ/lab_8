/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.30.2017
 *
 * Description: This is a group of functions that I utilize
 * to ensure that information is correctly inputted without
 * giving wrong types of values that could cause the application
 * to loop, be damaged, or segfault.
**************************************************************/

#ifndef PROJECT_2_INPUTCHECK_HPP
#define PROJECT_2_INPUTCHECK_HPP

#include <string>

// String validators
std::string getString();		// Returns a string characters (can include spaces)
std::string getWord();			// Returns a single word and has the option to clear the istream

// Char validators
char getCharacter();					// Returns a single character
char getCharacter(int);

// Number validators
int getInt();					// Confirms user input was an int and returns that value
float getFloat();				// Confirms user input was a float and returns that value

// String manipulators
void lowerCase(std::string);    // Sets all letters in a string to lowercase values
void capitalize(std::string);	// Sets the first letter in a string to uppercase

#endif //PROJECT_2_INPUTCHECK_HPP
