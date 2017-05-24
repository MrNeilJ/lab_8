/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.16.2017
 *
 * Description: This file hosts the header of a reusable function
 * that can be used to create menu options that can be up to 4
 * questions. It takes input from the user about the initial question,
 * and then it takes in the options the user would be provided
 * with.  It will then print out the menu in an easy to read
 * format and pull a response from the user which can be used
 * later by the user to see what their response was.
**************************************************************/

#ifndef PROJECT_1_TRY_TWO_MENUMAKER_HPP
#define PROJECT_1_TRY_TWO_MENUMAKER_HPP

#include <string>
#include <iostream>

class menuMaker {
private:
	std::string menuOne     = "";
    std::string menuTwo     = "";
    std::string menuThree   = "";
    std::string menuFour    = "";
    std::string menuFive    = "";
	std::string menuSix		= "";
    std::string initQues    = "";

	int response;

public:
	// Constructors
	menuMaker(std::string userQues);
    menuMaker(std::string initQuest, std::string quesOne);
    menuMaker(std::string initQuest, std::string quesOne, std::string quesTwo);
    menuMaker(std::string initQuest, std::string quesOne, std::string quesTwo, std::string quesThree);
    menuMaker(std::string initQuest, std::string quesOne, std::string quesTwo,
              std::string quesThree, std::string quesFour);
	menuMaker(std::string initQuest, std::string quesOne, std::string quesTwo,
              std::string quesThree, std::string quesFour, std::string quesFive);

	menuMaker(std::string initQuest, std::string quesOne, std::string quesTwo,
			  std::string quesThree, std::string quesFour, std::string quesFive, std::string quesSix);

	// Prints and asks the user for a response
    void prompt();

	// Returns user response value
	int getResponse();

	// Returns the size of the menu (number of questions set).
	int getMenuSize();

	void prompt(int x);
};


#endif //PROJECT_1_TRY_TWO_MENUMAKER_HPP
