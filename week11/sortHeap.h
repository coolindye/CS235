/***********************************************************************
 * Module:
 *    Week 11, Sort Heap
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name>
 * Summary:
 *    This program will implement the Heap Sort
 ************************************************************************/

#ifndef SORT_HEAP_H
#define SORT_HEAP_H
using namespace std;

template <class T>
void trickleHeap(T arr[], int root, int l) {
	int largest = l;
	int left = 2*l + 1;
	int right = 2*l + 2;

	if (left  < root && arr[left]  > arr[largest])
		largest = left;
	if (right < root && arr[right] > arr[largest])\
		largest = right;
	if (largest != l) {
		swap(arr[l], arr[largest]);
		trickleHeap(arr, root, largest);
	}

}

/*****************************************************
 * SORT HEAP
 * Perform the heap sort
 ****************************************************/
template <class T>
void sortHeap(T arr[], int num) {
   for (int i = num / 2 - 1; i >= 0; i--)
   	trickleHeap(arr, num, i);
   for (int i = num - 1; i >= 0; i--) {
   	swap(arr[0], arr[i]);
   	trickleHeap(arr, i, 0);
   }
}


#endif // SORT_HEAP_H
