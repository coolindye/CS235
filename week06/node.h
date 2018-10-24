/***********************************************************************
 * Header:
 *    node
 * Summary:
 *    This class contains the notion of an node
 * Author
 *    Garrett Smith & Aiden Reid
 ************************************************************************/

#ifndef node_H
#define node_H

#include <cassert>
#include <iostream>
using namespace std;

// a little helper macro to write debug code
#ifdef NDEBUG
#define Debug(statement)
#else
#define Debug(statement) statement
#endif // !NDEBUG

namespace custom
{

	/****************************************************
	 * node
	 * A class that holds stuff as part of a linked list
	 ***************************************************/
	template <class T>
	class Node
	{
	public:
		// constructors and destructors
		Node():            data(NULL) pNext(NULL) pPrev(NULL) {};
		Node(const T & t): data(num) pNext(NULL) pPrev(NULL)  {};
		
		T data;              
		Node *pNext;               
		Node *pPrev;
	};
}; // namespace custom

#endif // set_H