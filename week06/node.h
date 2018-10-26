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
		Node(const T & t): data(num)  pNext(NULL) pPrev(NULL)  {};
		
        copy(const Node <T> *pSource)      throw (const char *);
        insert(Node <T> pNode, const T &t) throw (const char *);
        find(Nade <T> *pHead, const T &t);
        ostream & operator << (ostream & out, Node <T> *t);
        void freeData(Node <T> * & head);
        remove(const Node<T> *pNode);

		T data;              
		Node *pNext;               
		Node *pPrev;
	};


    template<class T>
    Node<T>::copy(const Node<T>* pSource) throw(const char *)
    {

    }
    template<class T>
    Node<T>::insert(Node<T> pNode, const T & t) throw(const char *)
    {

    }
    template<class T>
    Node<T>::find(Nade<T>* pHead, const T & t)
    {
    }
    template<class T>
    ostream & Node<T>::operator<<(ostream & out, Node<T>* t)
    {
        // TODO: insert return statement here
    }
    template<class T>
    void Node<T>::freeData(Node<T>*& head)
    {
    }
    template<class T>
    Node<T>::remove(const Node<T>* pNode)
    {
    }
}; // namespace custom

#endif // set_H