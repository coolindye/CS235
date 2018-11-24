/***********************************************************************
 * Module:
 *    Week 11, Sort Insertion
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name>
 * Summary:
 *    This program will implement the Insertion Sort
 ************************************************************************/

#ifndef SORT_INSERTION_H
#define SORT_INSERTION_H

#include <cassert>


template <class T>
int binarySearch(T array[], T search, int iBegin, int iEnd)
{

	int iMiddle = (iEnd + iBegin) / 2;

	if (iBegin > iEnd)
		return iBegin;

	// If the element is present at the middle, return iMiddle
	if (array[iMiddle] == search)
		return iMiddle;

	// If element is smaller than mid, then  
	// it can only be present in left subarray 
	if (search > array[iMiddle])
		return binarySearch(array, search, iMiddle + 1, iEnd);

	// Else the element can only be present 
	// in right subarray 
	else
		return binarySearch(array, search, iBegin, iMiddle - 1);


	// We reach here when element is not  
	// present in array 
	return -1;
}

/*****************************************************
 * SORT INSERTION
 * Perform the insertion sort
 ****************************************************/
template <class T>
void sortInsertion(T array[], int num)
{
	for (int iPivot = num - 2; iPivot >= 0; iPivot--)
	{
		T valuePivot = array[iPivot];
		int iShift;
		int iInsert = binarySearch(array, valuePivot, iPivot + 1, num - 1);
		iInsert--;
		for (iShift = iPivot; iShift < iInsert; iShift++)
		{
			array[iShift] = array[iShift + 1];
		}
		array[iShift] = valuePivot;
	}
}

#endif // SORT_INSERTION_H
