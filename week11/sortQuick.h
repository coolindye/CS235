/***********************************************************************
 * Module:
 *    Week 11, Sort Quick
 *    Brother Helfrich, CS 235
 * Author:
 *    Garrett, Aiden, Ian
 * Summary:
 *    This program will implement the Quick Sort
 ************************************************************************/

#ifndef SORT_QUICK_H
#define SORT_QUICK_H

template <class T>
void quickSort(T array[], int iLeft, int iRight)
{
	int l = iLeft, r = iRight;
	T tmp;
	T pivot = array[(iLeft + iRight) / 2];

	// Partition the array into more manageable subarrays for recursion
	// if no partitioning happens you will end up in an infinite recursive loop
	while (l <= r)
	{
		while (array[l] < pivot)
			l++;
		while (array[r] > pivot)
			r--;
		if (l <= r)
		{
			tmp = array[l];
			array[l] = array[r];
			array[r] = tmp;
			l++;
			r--;
		}
	}

	// Recursive code that continues to sort each subarray until there is one element
	if (iLeft < r)
		quickSort(array, iLeft, r);
	if (l < iRight)
		quickSort(array, l, iRight);
}

 /*****************************************************
  * SORT QUICK
  * Perform the quick sort
  ****************************************************/
template <class T>
void sortQuick(T array[], int num)
{
	quickSort(array, 0, num-1);
}


#endif // SORT_QUICK_H
