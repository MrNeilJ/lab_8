#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "inputCheck.hpp"
#include "sorting.hpp"
#include "menuMaker.hpp"

int main() {
	// Create a welcome screen for the user to see
	std::cout << "****************************************" << std::endl;
	std::cout << "*     NUMBER SORT / SEARCH PROGRAM     *" << std::endl;
	std::cout << "****************************************" << std::endl;
	std::cout << "Welcome to the Linear Search Program! In here" << std::endl;
	std::cout << "you can search through multiple lists and see" << std::endl;
	std::cout << "if the number you are looking for exists." 	 << std::endl;

	// Ask the user for input on what value they want to look for
	std::cout << "\nWhat number would you like to search for?: ";
	// Save that value in a int variable
	int numSearch = getInt();

	//Create an array of all files that will be read
	std::string fileSets[4] = {"controlSet.txt", "set1.txt", "set2.txt", "set3.txt"};

	/*********************************************
	 * SEARCH MENU
	 *********************************************/
	menuMaker searchMenu(	"What kind of search would you like to use?",
							"Linear Search",
						 	"Sort the files using Quick Sort",
							"Binary Search (utilizing Quick Sort method)",
							"Quit");

	int searchResponse = -1;

	do {
		searchMenu.prompt();
		searchResponse = searchMenu.getResponse();


		if (searchResponse == 1) {
			/*********************************************
			 * LINEAR SEARCH
			 *********************************************/
			bool found = false;

			for (int i = 0; i < 4; i++) {

				found = linearSearch(fileSets[i], numSearch);

				std::cout << fileSets[i] << ": target value " << "\"" << numSearch << "\"";

				if (found) {
					std::cout << " found." << std::endl;
				} else {
					std::cout << " not found." << std::endl;
				}
			}
		} else if (searchResponse == 2 || searchResponse == 3) {
			/*********************************************
			 * QUICK SORT
			 *********************************************/
			std::ifstream inFile;
			std::vector<int> groupNum;
			int temp;

			for (int i = 0; i < 4; i++) {
				inFile.open(fileSets[i]);

				if (inFile.fail()) {
					std::cout << "Could not open file, an error has occurred." << std::endl;
					exit(1);
				} else {
					while (inFile >> temp) {
						groupNum.push_back(temp);
					}
					inFile.close();

					quickSort(groupNum, 0, (groupNum.size() - 1));

					//Ask the user where they would like to store the updated array / vector
					std::cout << "File sorted, where would you like to save the updated information?" << std::endl;
					std::cout << "FileName: ";
					std::string updatedFile = getString();

					std::ofstream outFile;
					outFile.open(updatedFile);
					if (outFile.fail()) {
						std::cout << "Could not open file, and error has occurred" << std::endl;
						exit(1);
					} else {
						for (int i = 0; i < groupNum.size(); i++) {
							outFile << groupNum.at(i);
							outFile << " ";
						}
						std::cout << "Successfully wrote updated array from file" << fileSets[i] << " to new file."
								  << std::endl;
					}

				}
			}
			/*********************************************
			 * BINARY SEARCH
			 *********************************************/
			 if (searchResponse == 3) {

			 }

		}
		else if (searchResponse == 4) {
			std::cout << "Thank you, have a great day!" << std::endl;
		}
		else {
			std::cout << "Not valid input, try again." << std::endl;
		}
	} while (searchResponse != 4);

	
	return 0;
}