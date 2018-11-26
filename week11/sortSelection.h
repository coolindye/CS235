/***********************************************************************
 * Module:
 *    Week 11, Sort Select
 *    Brother Helfrich, CS 235
 * Author:
 *    Garrett, Aiden, Ian
 * Summary:
 *    This program will implement the Selection Sort
 ************************************************************************/

#ifndef SORT_SELECTION_H
#define SORT_SELECTION_H

/*****************************************************
 * SORT SELECTION
 * Perform the selection sort
 ****************************************************/
template <class T>
void sortSelection(T array[], int num)
{
	int iPivot, iCheck, iLargest;
	for (iPivot = num - 1; iPivot > 0; iPivot--)
	{
		iLargest = 0;
		for (iCheck = 0; iCheck < iPivot; iCheck++)
		{
			if (array[iLargest] < array[iCheck])
			{
				iLargest = iCheck;
			}
		}
		if (array[iLargest] > array[iPivot])
		{
			T temp = array[iLargest];
			array[iLargest] = array[iPivot];
			array[iPivot] = temp;
		}
	}
}


#endif // SORT_SELECTION_H
