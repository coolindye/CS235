/***********************************************************************
 * Header:
 *    bnode
 * Summary:
 *    This class contains the notion of an bnode and the non-member
 *    functions that allow them to act as a linked list
 * Author
 *    Garrett Smith, Aiden Reid, Ian Stubbs
 ************************************************************************/

#ifndef BNODE_H
#define BNODE_H

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
	 * bnode
	 * A class that holds stuff as part of a linked list
	 * All variable are public as well as constructors
	 ***************************************************/
	template <class T>
	class bnode
	{
	public:
		T data;
		bnode *pLeft;
		bnode *pRight;
		bnode *pParent;

		// constructors
		bnode() : data(T()), pLeft(NULL), pRight(NULL), pRight(NULL) {}
		bnode(const T & t) : data(t), pLeft(NULL), pRight(NULL), pRight(NULL) {}
	};

	/*****************************************************
	* Function: DELETE BTREE
	* Description: Release all the memory contained in a
	*  given linked-list
	*
	* Input:
	*  bnode * &pHead - Reference to pointer to start
	*                  of linked List
	*
	* Output:
	*  void - all bnodes in list have been set to NULL
	*****************************************************/
	template<class T>
	void deleteBTree(bnode<T> * &head) throw (const char *)
	{
		try
		{
			if (head->pLeft != NULL)
			{
				head->pLeft->pParent = nullptr;
				deleteBTree(head->pLeft);
				head->pLeft = nullptr;
			}
			else if (head->pRight != NULL)
			{
				head->pRight->pParent = nullptr;
				deleteBTree(head->pRight);
				head->pRight = nullptr;
			}
			else if (head->pParent != NULL)
			{
				if (head->pParent->pLeft == head)
				{
					head->pParent->pLeft = nullptr;
					deleteBTree(head->pParent);
					head->pParent = nullptr;
				}
				else if (head->pParent->pRight == head)
				{
					head->pParent->pRight = nullptr;
					deleteBTree(head->pParent);
					head->pParent = nullptr;
				}
			}

			delete head->data;
		}
		catch (const bad_alloc & e)
		{
			cout << "Unable to allocate a node" << endl;
		}
	}

	/*****************************************************
	* Function: COPY BTREE
	* Description: Copy a linked-list. Takes a pointer to
	*  a bnode as a parameter and returns a newly created
	*  linked-list containing a copy of all the bnodes
	*  below the list represented by the parameter.
	*
	* Input:
	*  const bnode *pbnode - pointer to start of Linked List
	*
	* Output:
	*  bnode * - pointer to start of new list
	*****************************************************/
	template <class T>
	bnode <T> * copyBTree(const bnode <T> * treeNode) throw (const char *)
	{
		try
		{
			try
			{
				if (head->pLeft != NULL)
				{
					head->pLeft->pParent = nullptr;
					deleteBTree(head->pLeft);
					head->pLeft = nullptr;
				}
				else if (head->pRight != NULL)
				{
					head->pRight->pParent = nullptr;
					deleteBTree(head->pRight);
					head->pRight = nullptr;
				}
				else if (head->pParent != NULL)
				{
					if (head->pParent->pLeft == head)
					{
						head->pParent->pLeft = nullptr;
						deleteBTree(head->pParent);
						head->pParent = nullptr;
					}
					else if (head->pParent->pRight == head)
					{
						head->pParent->pRight = nullptr;
						deleteBTree(head->pParent);
						head->pParent = nullptr;
					}
				}

				delete head->data;
				return head;
			}
			catch (const bad_alloc & e)
			{
				cout << "Unable to allocate a node" << endl;
			}
		}
		catch (std::bad_alloc & e)
		{
			cout << "Unable to allocate a node" << endl;
		}
	}

	/*****************************************************
	* Function: ADD LEFT
	* Description: Insert a new bnode into the current
	*  Binary Tree. The new bnode will be inserted to the
	*  left of the current node
	*
	* Input:
	*  bnode *pbnode - pointer to bnode at which a new bnode
	*                is to be inserted
	*  const T & t - value being placed in new bnode
	*
	* Output:
	*  bnode * - pointer to new bnode
	*****************************************************/
	template <class T>
	void addLeft(bnode <T> * treeNode, const T & t) throw (const char *)
	{
		try
		{
			if (treeNode != NULL)
			{
				bnode <T> * newNode = new bnode <T>(t);
				treeNode->pLeft = newNode;
				newNode->pParent = treeNode;
			}
			else
			{
				return;
			}
		}
		catch (const bad_alloc & e)
		{
			cout << "Unable to allocate a node" << endl;
		}
	}

	/*****************************************************
	* Function: ADD LEFT
	* Description: Insert a new bnode into the current
	*  Binary Tree. The new bnode will be inserted to the
	*  left of the current node
	*
	* Input:
	*  bnode *pbnode - pointer to bnode at which a new bnode
	*                is to be inserted
	*  const T & t - value being placed in new bnode
	*
	* Output:
	*  bnode * - pointer to new bnode
	*****************************************************/
	template <class T>
	void addLeft(bnode <T> * treeNode, bnode <T> * newNode) throw (const char *)
	{
		try
		{
			if (treeNode != NULL)
			{
				treeNode->pLeft = newNode;
				newNode->pParent = treeNode;
			}
			else
			{
				return;
			}
		}
		catch (const bad_alloc & e)
		{
			cout << "Unable to allocate a node" << endl;
		}
	}

	/*****************************************************
	* Function: ADD RIGHT
	* Description: Insert a new bnode into the current
	*  Binary Tree. The new bnode will be inserted to the
	*  left of the current node
	*
	* Input:
	*  bnode *pbnode - pointer to bnode at which a new bnode
	*                is to be inserted
	*  const T & t - value being placed in new bnode
	*
	* Output:
	*  bnode * - pointer to new bnode
	*****************************************************/
	template <class T>
	void addRight(bnode <T> * treeNode, const T & t) throw (const char *)
	{
		try
		{
			if (treeNode != NULL)
			{
				bnode <T> * newNode = new bnode <T>(t);
				treeNode->pRight = newNode;
				newNode->pParent = treeNode;
			}
			else
			{
				return;
			}
		}
		catch (const bad_alloc & e)
		{
			cout << "Unable to allocate a node" << endl;
		}
	}

	/*****************************************************
	* Function: ADD RIGHT
	* Description: Insert a new bnode into the current
	*  Binary Tree. The new bnode will be inserted to the
	*  left of the current node
	*
	* Input:
	*  bnode *pbnode - pointer to bnode at which a new bnode
	*                is to be inserted
	*  const T & t - value being placed in new bnode
	*
	* Output:
	*  bnode * - pointer to new bnode
	*****************************************************/
	template <class T>
	void addRight(bnode <T> * treeNode, bnode <T> * newNode) throw (const char *)
	{
		try
		{
			if (treeNode != NULL)
			{
				treeNode->pRight = newNode;
				newNode->pParent = treeNode;
			}
			else
			{
				return;
			}
		}
		catch (const bad_alloc & e)
		{
			cout << "Unable to allocate a node" << endl;
		}
	}

	/*****************************************************
	* Function: INSERTION OPERATOR OVERLOAD
	* Description: Give the behavior of how a Binary Tree
	*  communicates with output streams, specifically how
	*  the << operator is handled. Displays content of the
	*  list.
	*
	* Input:
	*  ostream & out - reference to ostream variable
	*  bnode *pbnode - pointer to start of linked-list
	*
	* Output:
	*  ostream - output stream value
	*****************************************************/
	template <class T>
	ostream & operator <<(ostream & out, const bnode <T> * pbnode) throw (const char *)
	{
		try
		{
			if (pbnode != NULL)
			{
				out << pbnode->data;
				if (pbnode->pNext != NULL)
					out << ", " << pbnode->pNext;
			}
			return out;
		}
		catch (const bad_alloc & e)
		{
			cout << "ERROR: Insertion operator not working due to - " << e.what() << endl;
		}
	}
}; // namespace custom

#endif // BNODE_H