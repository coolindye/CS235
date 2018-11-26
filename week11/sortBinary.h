/***********************************************************************
 * Module:
 *    Week 11, Sort Binary
 *    Brother Helfrich, CS 235
 * Author:
 *    Garrett, Aiden, Ian
 * Summary:
 *    This program will implement the Binary Tree Sort
 ************************************************************************/

#ifndef SORT_BINARY_H
#define SORT_BINARY_H

#include "bst.h"
#include <cassert>
using namespace custom;

/*****************************************************
 * SORT BINARY
 * Perform the binary tree sort
 ****************************************************/
template <class T>
void sortBinary(T array[], int num)
{
	BST <T> tree;
	typename BST <T>::iterator it;
	int i;

	//This sort just adds every element to a binary tree
	for (i = 0; i < num; i++)
	{
		tree.insert(array[i]);
	}

	//Due to the properties of a Binary Tree, the elements are sorted as they are inserted
	i = 0;
	for (it = tree.begin(); it != tree.end(); it++)
		array[i++] = *it;
}


#endif // SORT_BINARY_H
