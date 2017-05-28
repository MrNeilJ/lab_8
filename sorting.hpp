/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.26.2017
 *
 * Description: This is the sorting header file for the various features
 * inside of the main function.  In hear we are hosting the ability
 * to perform a linear / quick sort / binary search functionality.
**************************************************************/

#ifndef LAB_8_SORTING_HPP
#define LAB_8_SORTING_HPP

#include <iostream>
#include <fstream>
#include <vector>


bool linearSearch(std::string,int);
void quickSort(std::vector<int>, int, int);
bool binarySearch(std::vector<int>, int, int, int);



#endif //LAB_8_SORTING_HPP