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
#define Debug
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
        Node() : data(T()), pNext(NULL), pPrev(NULL) {}
        Node(const T & t) : data(t), pNext(NULL), pPrev(NULL) {}
    };

    template<class T>
    Node<T> * find(Node<T>* pHead, const T & t) throw (const char *)
    {
		try
		{
			if (pHead->data == t)
			{
				return pHead;
			}
			else
			{
				if (pHead->pNext != NULL) return find(pHead->pNext, t);
			}

			return NULL;
		}
		catch (const bad_alloc & e)
		{
			cout << "ERROR: Can not find due to - " << e.what() << endl;
		}
    }

    template<class T>
    void freeData(Node<T> * &head) throw (const char *)
    {
        try
        {
			if (head->pNext == NULL)
			{
				head = NULL;
			}
			else
			{
				freeData(head->pNext);
				head = NULL;
			}
        }
        catch (const bad_alloc & e)
        {
            cout << "ERROR: Can not insert due to - " << e.what() << endl;
        }
    }
    template<class T>
    Node<T> *remove(const Node<T>* pNode) throw (const char *)
    {
        try
        {
            Node <T> * temp;
			if (pNode->pPrev != NULL)
				pNode->pPrev->pNext = pNode->pNext;
			if (pNode->pNext != NULL)
				pNode->pNext->pPrev = pNode->pPrev;

            if (pNode->pPrev != NULL)
            {
                temp = pNode->pPrev;
            }
            else
            {
                temp = pNode->pNext;
            }

            pNode = NULL;
            return temp;
        }
        catch (const bad_alloc & e)
        {
            cout << "ERROR: Can not insert due to - " << e.what() << endl;
        }
    }

    template <class T>
    Node <T> * copy(const Node <T> * pNode) throw (const char *)
    {
        try
        {
            if (pNode != NULL)
            {
                Node <T> *copyNode = new Node<T>(pNode->data);
                Node<T> * nodeTemp = copyNode;

                while (pNode->pNext)
                {
                    pNode = pNode->pNext;
                    nodeTemp->pNext = new Node<T>(pNode->data);
                    nodeTemp->pNext->pPrev = nodeTemp;
                    nodeTemp = nodeTemp->pNext;
                }

                return copyNode;
            }
            else
                return 0;
        }
        catch (std::bad_alloc & e)
        {
            cout << "ERROR: Can not display due to - " << e.what() << endl;
        }
    }

    template <class T>
    Node <T> * insert(Node <T> * pNode, const T & t) throw (const char *)
    {
        try
        {
            if (pNode != NULL)
            {
                Node <T> * newNode = new Node <T>(t);
				if (pNode->pPrev != NULL)
					pNode->pPrev->pNext = newNode;
                newNode->pNext = pNode;
                newNode->pPrev = pNode->pPrev;

                pNode->pPrev = newNode;
                return newNode;
            }
            else
            {
                Node <T> * newNode = new Node <T>(t);
                return newNode;
            }
        }
        catch (const bad_alloc & e)
        {
            cout << "ERROR: Can not insert due to - " << e.what() << endl;
        }
    }

    template <class T>
    Node <T> *insert(Node <T> * pNode, const T & t, const bool after) throw (const char *)
    {
        try
        {
            if (after && pNode != NULL)
            {
                Node <T> * newNode = new Node <T>(t);
                if (pNode->pNext != NULL)
                    pNode->pNext->pPrev = newNode;
                newNode->pNext = pNode->pNext;
                newNode->pPrev = pNode;
                pNode->pNext = newNode;
                return newNode;
            }
            else if (!after && pNode != NULL)
            {
				insert(pNode, t);
            }
            else
            {
                Node <T> * newNode = new Node <T>(t);
                return newNode;
            }
        }
        catch (const bad_alloc & e)
        {
            cout << "ERROR: Can not insert due to - " << e.what() << endl;
        }
    }

    template <class T>
    ostream & operator <<(ostream & out, const Node <T> * pNode) throw (const char *)
    {
        try
        {
			if (pNode != NULL)
			{
				out << pNode->data;
				if (pNode->pNext != NULL)
					out << ", " << pNode->pNext;
			}
			return out;
        }
        catch (const bad_alloc & e)
        {
            cout << "ERROR: Insertion operator not working due to - " << e.what() << endl;
        }
    }
}; // namespace custom

#endif // set_H