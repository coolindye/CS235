/***********************************************************************
 * Header:
 *    INSERTION SORT
 * Summary:
 *    This will contain just the prototype for insertionSortTest(). You may
 *    want to put other class definitions here as well.
 * Author
 *    <your names here>
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
	assert (array != NULL);
	try
	{
		Node <T> * n = NULL;
		for (int i = 0; i < num; i++)
		{
			if (i == 0)
			{
				n = insert(n, array[i]);
			}

			else if (array[i] < n->data)
			{
				n = insert(n, array[i]);
			}

			else
			{
				Node <T> *ne = findGreater(n, array[i]);
				insert(ne, array[i], (ne->data < array[i]));
			}
		}

		if (n != NULL)
		{
			int i = 1;
			array[0] = n->data;
			
			while (n->pNext)
			{
				n = n->pNext;
				array[i] = n->data;
				i++;
			}
		}
	}
	catch (const bad_alloc & e)
	{
		cout << "ERROR: Can not find due to - " << e.what() << endl;
	}
}

#endif // INSERTION_SORT_H

