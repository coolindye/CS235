/***********************************************************************
 * Header:
 *    node
 * Summary:
 *    This class contains the notion of an node and the non-member
 *    functions that allow them to act as a linked list
 * Author
 *    Garrett Smith, Aiden Reid, Ian Stubbs
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
     * Node
     * A class that holds stuff as part of a linked list
	 * All variable are public as well as constructors
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

	/*****************************************************
    * Function: FIND
    * Description: ind the Node corresponding to a given 
	*  passed value from a given linked-list. 
    *               
	* Input:
	*  Node *pHead - Pointer to start of Linked List
	*  const T & t - reference to value trying to be found
	*  
	* Output:
	*  Node * - pointer to node found, NULL otherwise
    *****************************************************/
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

	/*****************************************************
	* Function: FIND GREATER
	* Description: Searches a linked list of nodes to find
	*  the first node that has a value greater than the 
	*  value given, returns last node in list if nothing
	*  is found.
	*
	* Input:
	*  Node *pHead - pointer to start of Linked List
	*  const T & t - reference to value being compared
	*
	* Output:
	*  Node * - pointer to node found, last value in the
	*           list otherwise
	*****************************************************/
	template<class T>
	Node<T> * findGreater(Node<T>* pHead, const T & t) throw (const char *)
	{
		try
		{
			if (pHead->data > t) return pHead;

			else if (pHead->pNext != NULL) return findGreater(pHead->pNext, t);

			return pHead;
;
		}
		catch (const bad_alloc & e)
		{
			cout << "ERROR: Can not find due to - " << e.what() << endl;
		}
	}

	/*****************************************************
	* Function: FREE DATA
	* Description: Release all the memory contained in a
	*  given linked-list
	*
	* Input:
	*  Node * &pHead - Reference to pointer to start 
	*                  of linked List
	*
	* Output:
	*  void - all nodes in list have been set to NULL
	*****************************************************/
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

	/*****************************************************
	* Function: REMOVE
	* Description: Removes a given node from the 
	*  linked list it is attached to. It returns a pointer
	*  to the previous node in the list if such a node 
	*  exists. Otherwise, it returns a pointer to the next
	*  node.
	*
	* Input:
	*  Node *pNode - Node to be removed
	*
	* Output:
	*  Node * - Pointer to node before or after removed
	*           Node
	*****************************************************/
    template<class T>
    Node<T> *remove(Node<T>* pNode) throw (const char *)
    {
        try
        {
            Node <T> * temp;

			//Handles most cases but removing the first element or last element in the list
            if (pNode->pPrev != NULL)
            {
				pNode->pPrev->pNext = pNode->pNext;
                temp = pNode->pPrev;
				if (pNode->pNext != NULL)
				{
					pNode->pNext->pPrev = pNode->pPrev;
					temp = pNode->pNext;
				}
				return temp;
            }

			//Handles removing the first element but not the last element in the list
            else if (pNode->pNext != NULL)
            {
				pNode->pNext->pPrev = pNode->pPrev;
                return temp = pNode->pNext;
            }

			//Handles removing the last element in the list
			else
			{
				return NULL;
			}
        }
        catch (const bad_alloc & e)
        {
            cout << "ERROR: Can not insert due to - " << e.what() << endl;
        }
    }

	/*****************************************************
	* Function: COPY
	* Description: Copy a linked-list. Takes a pointer to
	*  a Node as a parameter and returns a newly created 
	*  linked-list containing a copy of all the nodes 
	*  below the list represented by the parameter.
	*
	* Input:
	*  const Node *pNode - pointer to start of Linked List
	*
	* Output:
	*  Node * - pointer to start of new list 
	*****************************************************/
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

	/*****************************************************
	* Function: INSERT
	* Description: Insert a new Node into the current 
	*  linked-list. The new node will be inserted before 
	*  the reference node.
	*
	* Input:
	*  Node *pNode - pointer to Node at which a new node
	*                is to be inserted
	*  const T & t - value being placed in new node
	*
	* Output:
	*  Node * - pointer to new node
	*****************************************************/
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

	/*****************************************************
	* Function: INSERT
	* Description: Insert a new Node into the current
	*  linked-list. The new node will be inserted before
	*  the reference node if the after value is false. It
	*  will be inserted after the reference node if the 
	*  after value is false.
	*
	* Input:
	*  Node *pNode - pointer to Node at which a new node
	*                is to be inserted
	*  const T & t - value being placed in new node
	*  const bool after - determines whether new Node is 
	*                     inserted before or after pNode
	*
	* Output:
	*  Node * - pointer to new node
	*****************************************************/
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

	/*****************************************************
	* Function: INSERTION OPERATOR OVERLOAD
	* Description: Give the behavior of how a linked-list
	*  communicates with output streams, specifically how
	*  the << operator is handled. Displays content of the
	*  list.
	*
	* Input:
	*  ostream & out - reference to ostream variable 
	*  Node *pNode - pointer to start of linked-list
	*
	* Output:
	*  ostream - output stream value
	*****************************************************/
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