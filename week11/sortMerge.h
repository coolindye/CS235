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
    int size1;
    int size2;

    //Determine each size of the two source arrays
    if (num % 2 == 0)
        size1 = size2 = num / 2;
    else
    {
        size1 = num / 2 + 1;
        size2 = num / 2;
    }
    //dynamically allocating each array
    T *source1 = new T[size1];
    T *source2 = new T[size2];

    //filling first array with first half of source numbers
    for (int i = 0; i < size1; i++)
        source1[i] = array[i];

    //filling second array with first half of source numbers
    for (int i = 0, iEnd = size1; i < size1 && iEnd < num; i++)
    {
        source2[i] = array[iEnd];
        iEnd++;
    }

    T source;
    int sourceIndex;

    //sorting the first array
    for (int iBegin = 0; iBegin < size1; iBegin++)
    {
        //source is the first number
        source = source1[iBegin];

        //checking to see if other elements in array are smaller
        for (int i = iBegin + 1; i < size1; i++)
        {
            if (source1[i] < source)
            {
                source = source1[i];
                sourceIndex = i;
            }
        }
        source1[sourceIndex] = source1[iBegin];
        source1[iBegin] = source;
    }

    //new variables used for second sorting
    T smallest2;
    int sourceIndex2;

    //sorting the second array
    for (int iBegin2 = 0; iBegin2 < size2; iBegin2++)
    {
        //source is the first number
        smallest2 = source2[iBegin2];

        //checking to see if other elements in array are smaller
        for (int i = iBegin2 + 1; i < size2; i++)
        {
            if (source2[i] < smallest2)
            {
                smallest2 = source2[i];
                sourceIndex2 = i;
            }
        }
        source2[sourceIndex2] = source2[iBegin2];
        source2[iBegin2] = smallest2;
    }

    merge(array, source1, size1, source2, size2);


}


#endif // SORT_MERGE_H
