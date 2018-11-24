/***********************************************************************
 * Module:
 *    Week 11, Sort Merge
 *    Brother Helfrich, CS 235
 * Author:
 *    <author>
 * Summary:
 *    This program will implement the Merge Sort
 ************************************************************************/

#ifndef SORT_MERGE_H
#define SORT_MERGE_H

template <class T>
void merge(T destination [], T source1[], int size1, T source2[], int size2)
{
	int i1 = 0, i2 = 0;

	for (int iDestination = 0; iDestination < (size1 + size2); iDestination++)
	{
		if (i1 < size1 && (i2 == size2 || source1[i1] < source2[i2]))
			destination[iDestination] = source1[i1++];
		else
			destination[iDestination] = source2[i2++];
	}
}
/*****************************************************
 * SORT MERGE
 * Perform the merge sort
 ****************************************************/
template <class T>
void sortMerge(T array[], int num)
{
}


#endif // SORT_MERGE_H
