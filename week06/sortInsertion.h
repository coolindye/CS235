/***********************************************************************
 * Header:
 *    INSERTION SORT
 * Summary:
 *    This will contain just the prototype for insertionSortTest(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Garrett Smith, Ian Stubbs, Aiden Reid
 ************************************************************************/

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "node.h"
using namespace std;
using namespace custom;
/***********************************************
 * INSERTION SORT
 * Sort the items in the array
 **********************************************/
template <class T>
void sortInsertion(T array[], int num) throw (const char *)
{
	try
	{
		if (num <= 1) return;

		Node <T> * n = NULL;

		for (int i = 0; i < num; i++)
		{
			//First run, add 2 elements for findGreater method 
			if (i == 0)
			{
				n = insert(n, array[i]);
				i++;
				(array[i] < n->data ? n = insert(n, array[i]) : insert(n, array[i], true));
			}

			//Smallest elements added at beginning
			else if (array[i] < n->data)
			{
				n = insert(n, array[i]);
			}

			//Find the first node that is greater than value and add value in front
			else
			{
				Node <T> *temp = findGreater(n->pNext, array[i]);
				(array[i] < temp->data ? insert(temp, array[i]) : insert(temp, array[i], true));
			}
		}
		
		//Add values back to array in sorted order
		for (int i = 0; i < num; i++)
		{
			array[i] = n->data;
			n = n->pNext;
		}
	}

	catch (const bad_alloc & e)
	{
		cout << "ERROR: Can not find due to - " << e.what() << endl;
	}
}

#endif // INSERTION_SORT_H

