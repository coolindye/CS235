/***********************************************************************
 * Module:
 *    Week 11, Sort Binary
 *    Brother Helfrich, CS 235
 * Author:
 *    <your name>
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

	for (i = 0; i < num; i++)
	{
		tree.insert(array[i]);
	}

	i = 0;
	for (it = tree.begin(); it != tree.end(); it++)
		array[i++] = *it;
}


#endif // SORT_BINARY_H
