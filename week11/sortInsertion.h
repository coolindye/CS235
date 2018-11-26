/***********************************************************************
 * Module:
 *    Week 11, Sort Insertion
 *    Brother Helfrich, CS 235
 * Author:
 *    Garrett, Aiden, Ian
 * Summary:
 *    This program will implement the Insertion Sort
 ************************************************************************/

#ifndef SORT_INSERTION_H
#define SORT_INSERTION_H

#include <cassert>


 /***********************************************************************
  * BINARY SEARCH
  *    Input:
  *       array[] - array to be searched
  *       search - value trying to be found
  *       iBegin - index of the start of array to be searched
  *       iEnd - inded of the end of array being searched
  *    
  *    Output:
  *       int - index of array that the search value is found at or the 
  *             closest value less than the search value in the array
  ************************************************************************/
template <class T>
int binarySearch(T array[], T search, int iBegin, int iEnd)
{

	int iMiddle = (iEnd + iBegin) / 2;

	if (iBegin > iEnd)
		return iBegin;

	// If the element is present at the middle, return iMiddle
	if (array[iMiddle] == search)
		return iMiddle;

	// If search value is larger than iMiddle, it is in the right subarray
	if (search > array[iMiddle])
		return binarySearch(array, search, iMiddle + 1, iEnd);

	// Else it is in the left subarray 
	else
		return binarySearch(array, search, iBegin, iMiddle - 1);
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

		//Get value of index just below the insert value so that the shifting is done correctly
		iInsert--;

		for (iShift = iPivot; iShift < iInsert; iShift++)
		{
			array[iShift] = array[iShift + 1];
		}
		array[iShift] = valuePivot;
	}
}

#endif // SORT_INSERTION_H
