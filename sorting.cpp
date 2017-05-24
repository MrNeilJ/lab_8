//
// Created by Neil on 5/23/2017.
//

#include "sorting.hpp"
#include <vector>

bool linearSearch(std::string fileName,int userSearch) {
	std::ifstream inFile;
	inFile.open(fileName);

	if(inFile.fail()) {
		std::cout << "Could not open file, an error has occurred." << std::endl;
		exit(1);
	}
	else {
		int fileInt;
		while (inFile >> fileInt) {
			if (fileInt == userSearch) {
				inFile.close();
				return true;
			}
		}
		inFile.close();
		return false;
	}
}

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