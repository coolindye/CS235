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
    Node<T> * find(Node<T>* pHead, const T & t)
    {
    }

    template<class T>
    void freeData(Node<T> * head) throw (const char *)
    {
		try
		{
			if (head->pPrev != NULL)
			{
				throw ("Cannot delete without head of list.");
	
			}
			if (head->pNext == NULL)
				delete head;
			else
				freeData(head->pNext);
		}
		catch (exception e)
		{
			cout << "ERROR: Can not insert due to - " << e << endl;
		}
    }
    template<class T>
    Node<T> *remove(const Node<T>* pNode)
    {
    }

	template <class T>
	Node <T> * copy(const Node <T> * pNode) throw (const char *)
	{
		try
		{
			if (pNode != NULL)
			{
				cout << pNode->data << " ";
				display(pNode->pNext);
			}
			else
				return;
		}
		catch (exception e)
		{
			cout << "ERROR: Can not display due to - " << e << endl;
		}
	}

	template <class T>
	Node <T> * insert(Node <T> * pNode, const T & t) throw (const char *)
	{
		try
		{
			Node <T> * newNode = new Node(t);
			newNode->pNext = pNode;
			newNode->pPrev = pNode->pPrev;
			pNode->pPrev = newNode;
			return newNode;
		}
		catch (exception e)
		{
			cout << "ERROR: Can not insert due to - " << e << endl;
		}
	}

	template <class T>
	Node <T> * insert(Node <T> * pNode, const T & t, const bool after) throw (const char *)
	{
		try
		{
			if (after)
			{
				Node <T> * newNode = new Node(t);
				pNode->pNext->pPrev = newNode;
				newNode->pNext = pNode->pNext;
				newNode->pPrev = pNode;
				pNode->pNext = newNode;
				return newNode;
			}
			else
			{
				return insert(pNode, t);
			}
		}
		catch (exception e)
		{
			cout << "ERROR: Can not insert due to - " << e << endl;
		}
	}

	template <class T>
	void display(const Node <T> * pNode) throw (const char *)
	{
		try
		{
			if (pNode != NULL)
			{
				cout << pNode->data << " ";
				display(pNode->pNext);
			}
			else
				return;
		}
		catch (exception e)
		{
			cout << "ERROR: Can not display due to - " << e << endl;
		}
	}

	template <class T>
	ostream & operator <<(ostream& out, const Node <T> * pNode) throw (const char *)
	{
		try
		{
			display(pNode);
		}
		catch (exception e)
		{
			cout << "ERROR: Insertion operator not working due to - " << e << endl;
		}
	}
}; // namespace custom

#endif // set_H