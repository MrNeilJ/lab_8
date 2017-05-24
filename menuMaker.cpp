/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.16.2017
 *
 * Description: This file hosts a reusable function that can be
 * used to create menu options that can be up to 4 questions.
 * It takes input from the user about the initial question,
 * and then it takes in the options the user would be provided
 * with.  It will then print out the menu in an easy to read
 * format and pull a response from the user which can be used
 * later by the user to see what their response was.
**************************************************************/

#include "menuMaker.hpp"
#include <limits>
#include "inputCheck.hpp"

/**************************************************************
 *                  menuMaker::menuMaker
 * Description: Constructor function that saves the initial
 * question and first question variables.
**************************************************************/
menuMaker::menuMaker(std::string userQues) {
	initQues = userQues;
}

/**************************************************************
 *                  menuMaker::menuMaker
 * Description: Constructor function that saves the initial
 * question and first question variables.
**************************************************************/
menuMaker::menuMaker(std::string userQues, std::string quesOne) {
    menuOne = quesOne;
	initQues = userQues;
}

/**************************************************************
 *                  menuMaker::menuMaker
 * Description: Constructor function that saves the initial
 * question and first two question variables.
**************************************************************/
menuMaker::menuMaker(std::string userQues, std::string quesOne, std::string quesTwo) {
    menuOne = quesOne;
    menuTwo = quesTwo;
	initQues = userQues;
}

/**************************************************************
 *                  menuMaker::menuMaker
 * Description: Constructor function that saves the initial
 * question and first three question variables.
**************************************************************/
menuMaker::menuMaker(std::string userQues, std::string quesOne, std::string quesTwo, std::string quesThree) {
    menuOne     = quesOne;
    menuTwo     = quesTwo;
    menuThree   = quesThree;
	initQues 	= userQues;
}

/**************************************************************
 *                  menuMaker::menuMaker
 * Description: Constructor function that saves the initial
 * question and first four question variables.
**************************************************************/
menuMaker::menuMaker(std::string userQues, std::string quesOne, std::string quesTwo,
                     std::string quesThree, std::string quesFour) {
    menuOne     = quesOne;
    menuTwo     = quesTwo;
    menuThree   = quesThree;
    menuFour    = quesFour;
	initQues 	= userQues;
}

/**************************************************************
 *                  menuMaker::menuMaker
 * Description: Constructor function that saves the initial
 * question and first five question variables.
**************************************************************/
menuMaker::menuMaker(std::string userQues, std::string quesOne, std::string quesTwo, std::string quesThree,
					 std::string quesFour, std::string quesFive) {
	menuOne     = quesOne;
	menuTwo     = quesTwo;
	menuThree   = quesThree;
	menuFour    = quesFour;
	menuFive    = quesFive;
	initQues 	= userQues;
}

/**************************************************************
 *                  menuMaker::menuMaker
 * Description: Constructor function that saves the initial
 * question and first six question variables.
**************************************************************/
menuMaker::menuMaker(std::string userQues, std::string quesOne, std::string quesTwo, std::string quesThree,
					 std::string quesFour, std::string quesFive, std::string quesSix) {
	menuOne     = quesOne;
	menuTwo     = quesTwo;
	menuThree   = quesThree;
	menuFour    = quesFour;
	menuFive    = quesFive;
	menuSix		= quesSix;
	initQues 	= userQues;
}

/**************************************************************
 *                  menuMaker::prompt
 * Description: Member function that prints out the initial question
 * and the options for the user to see in an easy to read format.
 * It then asks the user for a numerical response.
**************************************************************/
void menuMaker::prompt() {
	int userResponse;

	do {
		int count = 1;

		std::cout << initQues << std::endl;

		if (!(menuOne == "")) {
			std::cout << "1) " << menuOne << std::endl;
			count++;
		}
		if (!(menuTwo == "")) {
			std::cout << "2) " << menuTwo << std::endl;
			count++;
		}
		if (!(menuThree == "")) {
			std::cout << "3) " << menuThree << std::endl;
			count++;
		}
		if (!(menuFour == "")) {
			std::cout << "4) " << menuFour << std::endl;
			count++;
		}
		if (!(menuFive == "")) {
			std::cout << "5) " << menuFive << std::endl;
			count++;
		}
		if (!(menuSix == "")) {
			std::cout << "6) " << menuSix<< std::endl;
			count++;
		}

		std::cout << "\nUser Choice: ";

		userResponse = getInt();

		if (userResponse < 0 || userResponse > getMenuSize()) {
			std::cout << "Does not match menu specifications, try again" << std::endl;
		}



	} while (userResponse < 0 || userResponse > getMenuSize());

	response = userResponse;

}

/**************************************************************
 *                  menuMaker::menuMaker
 * Description: Returns the users input from the prompt.
**************************************************************/
int menuMaker::getResponse() {
	return response;
}

/**************************************************************
 *                  menuMaker::menuMaker
 * Description: Returns the integer value of how many menu
 * items there are.
**************************************************************/
int menuMaker::getMenuSize() {
	int count = 01;
	if (!(menuOne == "")) {
		count++;
	}
	if (!(menuTwo == "")) {
		count++;
	}
	if (!(menuThree == "")) {
		count++;
	}
	if (!(menuFour == "")) {
		count++;
	}
	if (!(menuFive == "")) {
		count++;
	}
	if (!(menuSix == "")) {
		count++;
	}
	return count;
}

/**************************************************************
 *                  menuMaker::prompt
 * Description: Member function that prints out the initial question
 * and the options for the user to see in an easy to read format.
 * It then asks the user for a numerical response.
**************************************************************/
void menuMaker::prompt(int x) {
	int userResponse = 0;

	do {
		std::cout << initQues << std::endl;
		std::cout << "\nUser Choice: ";

		userResponse = getInt();
		response = userResponse;

		if (userResponse < x) {
			std::cout << "Number is too low, please try again!\n" << std::endl;
		}

	} while(userResponse < x);
}


