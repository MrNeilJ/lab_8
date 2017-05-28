/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.26.2017
 *
 * Description: This is the main function for the application
 * where we are able to search / sort through a set of numbers
 * that come from an external file(s).
**************************************************************/

#include <iostream>
#include <fstream>
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

	int searchResponse;

	do {
		searchMenu.prompt();
		searchResponse = searchMenu.getResponse();




		if (searchResponse == 1) {
			/*********************************************
			 * LINEAR SEARCH
			 *********************************************/
			// Ask the user for input on what value they want to look for
			std::cout << "\nWhat number would you like to search for?: ";
			// Save that value in a int variable
			int numSearch = getInt();


			bool found;

			for (int i = 0; i < 4; i++) {

				found = linearSearch(fileSets[i], numSearch);

				std::cout << fileSets[i] << ": target value " << "\"" << numSearch << "\"";

				if (found) {
					std::cout << " found." << std::endl;
				} else {
					std::cout << " not found." << std::endl;
				}
			}
		}
		else if (searchResponse == 2 || searchResponse == 3) {
			/*********************************************
			 * QUICK SORT
			 *********************************************/
			std::ifstream inFile;
			std::vector<int> groupNum;
			std::string updatedFileSets[4];
			int temp;

			// Open up each file for the different number sets
			for (int i = 0; i < 4; i++) {
				inFile.open(fileSets[i]);
				// Check to see if you can open the file
				if (inFile.fail()) {
					std::cout << "Could not open file, an error has occurred." << std::endl;
					exit(1);
				}
				// Otherwise, read the number that is in the file into a usable vector for later
				else {
					while (inFile >> temp) {
						groupNum.push_back(temp);
					}
					// Close the file
					inFile.close();

					// Run the quickSort method
					quickSort(groupNum, 0, (groupNum.size() - 1));

					//Ask the user where they would like to store the updated array / vector
					std::cout << "File sorted, where would you like to save the updated information?" << std::endl;
					std::cout << "FileName: ";
					std::string updatedFile = getString();

					// Output the information to an external file
					std::ofstream outFile;
					outFile.open(updatedFile);

					// Check to see if we were able to successfully open the file
					if (outFile.fail()) {
						std::cout << "Could not open file, and error has occurred" << std::endl;
						exit(1);
					}
					// Otherwise write the vector array to the external file
					else {
						for (int j = 0; j < groupNum.size(); j++) {
							outFile << groupNum.at(j);
							outFile << " ";
						}
						std::cout << "Successfully wrote updated array from file" << fileSets[i] << " to new file."
								  << std::endl;
						updatedFileSets[i] = updatedFile;
					}

				}
			}
			// Clear the vector out so it can be reused for the next file
			groupNum.clear();
			/*********************************************
			 * BINARY SEARCH
			 *********************************************/
			if (searchResponse == 3) {
				// Ask the user for input on what value they want to look for
				std::cout << "\nWhat number would you like to search for?: ";
				// Save that value in a int variable
				int numSearch = getInt();

				bool found;

				for (int i = 0; i < 4; i++) {
					inFile.open(updatedFileSets[i]);

					// Check to see if we could successfully open the file
					if (inFile.fail()) {
						std::cout << "Could not open file, an error has occurred." << std::endl;
						exit(1);
					}
					// Otherwise begin reading the file into a vector
					else {
						while (inFile >> temp) {
							groupNum.push_back(temp);
						}
						// Close the file
						inFile.close();

						// Run the binarySearch algorithm and return true or false to if the item was found
						found = binarySearch(groupNum, numSearch, 0, groupNum.size() - 1);

						// Print out the results of if we found it or not
						std::cout << updatedFileSets[i] << ": target value " << "\"" << numSearch << "\"";

						if (found) {
							std::cout << " found." << std::endl;
						} else {
							std::cout << " not found." << std::endl;
						}
					}
				}
			}
		}
		// User has selected to leave the application, close accordingly
		else if (searchResponse == 4) {
			std::cout << "Thank you, have a great day!" << std::endl;
		}
		// Not a valid input, let the user know
		else {
			std::cout << "Not valid input, try again." << std::endl;
		}
	} while (searchResponse != 4);


	return 0;
}