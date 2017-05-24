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

#include <iostream>
#include <limits>
#include "inputCheck.hpp"


/**************************************************************
 *  STRING VALIDATORS
**************************************************************/
/**************************************************************
 *                  getString()
 *	Retrieves input from the user, allows for spaces in the
 *	string to allow for the most accurate answer.
**************************************************************/
std::string getString() {
	std::string tempString;
	std::getline(std::cin, tempString);
	return tempString;
}

/**************************************************************
 *                  getWord()
 *	Retrieves input from the user, allows for only a single
 *	word to be stored, and clears any information after the
 *	initial word to ensure it doesn't damage other input calls
**************************************************************/
std::string getWord() {
	std::string tempWord;
	std::getline(std::cin, tempWord);
	return tempWord;
}


/**************************************************************
 *  CHAR VALIDATORS
**************************************************************/
/**************************************************************
 *                  getChar()
 *	Retrieves input from the user, allows only for a single
 *	letter for input, good for (Y/N) types of responses.
**************************************************************/
char getCharacter() {
	char tempChar = getchar();

	// Clear the error for the cin stream
	std::cin.clear();

	// Remove whatever is stored in the buffer up to the newline symbol at the end of the input buffer
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return  tempChar;
}

/**************************************************************
 *                  getChar()
 *	Retrieves input from the user, allows only for a single
 *	letter for input, good for (Y/N) types of responses.
**************************************************************/
char getCharacter(int clear) {
	int tempChar;
	if (clear == 1) {
		tempChar = getchar();

		// Clear the error for the cin stream
		std::cin.clear();

		// Remove whatever is stored in the buffer up to the newline symbol at the end of the input buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return tempChar;
	}
	else {
		tempChar = getchar();
		// Clear the error for the cin stream
		std::cin.clear();

		// Remove whatever is stored in the buffer up to the newline symbol at the end of the input buffer
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return  tempChar;

	}

}


/**************************************************************
 *  NUMBER VALIDATORS
**************************************************************/
/**************************************************************
 *                  getInt()
 *	Retrieves input from the user, allows the user to type in
 *	an int value, if it receives a char value it will reprompt
**************************************************************/
int getInt() {
	int tempInt;

	do {

		if (!std::cin) {
			// Clear the error for the cin stream
			std::cin.clear();

			// Remove whatever is stored in the buffer up to the newline symbol at the end of the input buffer
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "I'm sorry, that was an invalid response, please try your response again." << std::endl;
		}

		std::cin >> tempInt;


	} while (!std::cin);

	// Clear the error for the cin stream
	std::cin.clear();

	// Remove whatever is stored in the buffer up to the newline symbol at the end of the input buffer
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return tempInt;
}

/**************************************************************
 *                  getFloat()
 *	Retrieves input from the user, allows the user to type in
 *	a float value, if it receives a char value it will reprompt
**************************************************************/
float getFloat() {
	float tempFloat;

	do {

		if (!std::cin) {
			// Clear the error for the cin stream
			std::cin.clear();

			// Remove whatever is stored in the buffer up to the newline symbol at the end of the input buffer
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			std::cout << "I'm sorry, that was an invalid response, please try your response again." << std::endl;
		}

		std::cin >> tempFloat;

	} while (!std::cin);

	// Clear the error for the cin stream
	std::cin.clear();

	// Remove whatever is stored in the buffer up to the newline symbol at the end of the input buffer
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return tempFloat;
}

/**************************************************************
 *  STRING MANIPULATORS
**************************************************************/
/**************************************************************
 *                  lowerCase()
 *	Takes in a string value and modifies it so that each letter
 *	in the string is lower case.
**************************************************************/
void lowerCase(std::string &userString) {
	for (int i = 0; i < userString.length(); i++) {
		tolower(userString[i]);
	}
}

/**************************************************************
 *                  capitalize()
 *	Takes in a string value and sets all letters to lowercase
 *	and then capitalizes the first letter.
**************************************************************/
void capitalize(std::string userString) {
	for (int i = 0; i < userString.length(); i++) {
		tolower(userString[i]);
	}
	toupper(userString[0]);
}


