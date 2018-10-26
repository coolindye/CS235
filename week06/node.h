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
//using namespace std;

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
        T data;
        Node *pNext;
        Node *pPrev;
		// constructors and destructors
		Node()           : data(NULL), pNext(NULL), pPrev(NULL) {}
		Node(const T & t): data(t),  pNext(NULL), pPrev(NULL) {}
	};


    template<class T>
    Node<T> * copy(const Node<T>* pSource) throw(const char *)
    {
        Node <T> *copySource = new Node<T>(pSource->data);
        Node<T> * nodeTemp = copySource;

        while (pSource->pNext)
        {
            pSource = pSource->pNext;
            nodeTemp->pNext = new Node<T>(pSource->data);
            nodeTemp->pNext->pPrev = nodeTemp;
            nodeTemp = nodeTemp->pNext;
        }

        return copySource;
    }
    template<class T>
    Node<T> * insert(Node<T> pNode, const T & t) throw(const char *)
    {

    }
    template<class T>
    Node<T> * find(Node<T>* pHead, const T & t)
    {
    }
    template<class T>
    std::ostream & operator<<(std::ostream & out, Node<T>* t)
    {
        // TODO: insert return statement here
    }
    template<class T>
    void freeData(Node<T>*& head)
    {
    }
    template<class T>
    Node<T> *remove(const Node<T>* pNode)
    {
    }
}; // namespace custom

#endif // set_H