/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.26.2017
 *
 * Description: This is the sorting file for the various features
 * inside of the main function.  In hear we are hosting the ability
 * to perform a linear / quick sort / binary search functionality.
**************************************************************/

#include "sorting.hpp"

/**************************************************************
 *                  linearSearch()
 * Method that allows the user to search a file and see if
 * it conatins the number that you are looking for.
**************************************************************/
bool linearSearch(std::string fileName,int userSearch) {
	std::ifstream inFile;
	inFile.open(fileName);

	// Check to see if the file has been successfully opened, if not safely exit.
	if(inFile.fail()) {
		std::cout << "Could not open file, an error has occurred." << std::endl;
		exit(1);
	}
	// Otherwise read from the file number by number, checking it against the search item
	else {
		int fileInt;
		while (inFile >> fileInt) {
			// If found return true
			if (fileInt == userSearch) {
				inFile.close();
				return true;
			}
		}
		// Otherwise close the file and return false
		inFile.close();
		return false;
	}
}

/**************************************************************
 *                  quickSort()
 * Metod that allows the user to organize an array using the
 * quickSort sorting method, much more efficient than bubble sort
 *
 * Referenced website below for building of the algorithm:
 * http://www.algolist.net/Algorithms/Sorting/Quicksort
**************************************************************/
void quickSort(std::vector<int> arr, int left, int right) {
	int i = left;
	int j = right;
	int tmp;
	int pivot = arr.at((left + right) / 2);

	while (i <= j) {
		while (arr.at(i) < pivot) {
			i++;
		}
		while (arr.at(j) > pivot) {
			j--;
		}
		if (i <= j) {
			tmp = arr.at(i);
			arr.at(i) = arr.at(j);
			arr.at(j) = tmp;
			i++;
			j--;
		}
	}

	if (left < j) {
		quickSort(arr, left, j);
	}
	if (i < right) {
		quickSort(arr, i ,right);
	}

}

/**************************************************************
 *                  binarySearch()
 *  This search allows us to quickly search by splitting an already
 *  sorted menu in half and only searching half at a time, making
 *  the overall runtime significantly shorter.
 *
 * Referenced website below for building of the algorithm:
 * http://www.algolist.net/Algorithms/Binary_search
**************************************************************/
bool binarySearch(std::vector<int> arr, int value, int left, int right) {
	while (left <= right) {
		int middle = (left + right) / 2;
		if (arr.at(middle) == value) {
			return true;
		}
		else if (arr.at(middle) > value) {
			right = middle - 1;
		}
		else {
			left = middle + 1;
		}
	}
	return false;
}