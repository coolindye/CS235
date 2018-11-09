/***********************************************************************
 * Header:
 *    BNode
 * Summary:
 *    This class contains the notion of an BNode and the non-member
 *    functions that allow them to act as a linked list
 * Author
 *    Garrett Smith, Aiden Reid, Ian Stubbs
 ************************************************************************/

#ifndef bnode_H
#define bnode_H

#include <cassert>
#include <iostream>
using namespace std;

// a little helper macro to write debug code
#ifdef NDEBUG
#define Debug
#else
#define Debug(statement) statement
#endif // !NDEBUG

	/****************************************************
	 * BNode
	 * A class that holds stuff as part of a linked list
	 * All variable are public as well as constructors
	 ***************************************************/
	template <class T>
	class BNode
	{
	public:
		T data;
		BNode *pLeft;
		BNode *pRight;
		BNode *pParent;

		// constructors
		BNode() : data(T()), pLeft(NULL), pRight(NULL), pParent(NULL) {}
		BNode(const T & t) : data(t), pLeft(NULL), pRight(NULL), pParent(NULL) {}
	};

	/*****************************************************
	* Function: DELETE BTREE
	* Description: Release all the memory contained in a
	*  given linked-list
	*
	* Input:
	*  BNode * &pHead - Reference to pointer to start
	*                  of linked List
	*
	* Output:
	*  void - all BNodes in list have been set to NULL
	*****************************************************/
	template<class T>
	int sizeBTree(BNode<T> * head) throw (const char *)
	{
		try
		{
			int size = 0;
			if (head->pLeft != NULL)
			{
				return size + sizeBTree(head->pLeft);
			}
			else if (head->pRight != NULL)
			{
				return size + sizeBTree(head->pRight);
			}
			else 
			{
				return 1;
			}
		}
		catch (const bad_alloc & e)
		{
			cout << "Unable to allocate a node" << endl;
		}
	}

	/*****************************************************
	* Function: DELETE BTREE
	* Description: Release all the memory contained in a
	*  given linked-list
	*
	* Input:
	*  BNode * &pHead - Reference to pointer to start
	*                  of linked List
	*
	* Output:
	*  void - all BNodes in list have been set to NULL
	*****************************************************/
	template<class T>
	void deleteBTree(BNode<T> * &head) throw (const char *)
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
	*  a BNode as a parameter and returns a newly created
	*  linked-list containing a copy of all the BNodes
	*  below the list represented by the parameter.
	*
	* Input:
	*  const BNode *pBNode - pointer to start of Linked List
	*
	* Output:
	*  BNode * - pointer to start of new list
	*****************************************************/
	template <class T>
	BNode <T> * copyBTree(const BNode <T> * head) throw (const char *)
	{
		try
		{
			/*try
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
			}*/
		}
		catch (std::bad_alloc & e)
		{
			cout << "Unable to allocate a node" << endl;
		}
	}

	/*****************************************************
	* Function: ADD LEFT
	* Description: Insert a new BNode into the current
	*  Binary Tree. The new BNode will be inserted to the
	*  left of the current node
	*
	* Input:
	*  BNode *pBNode - pointer to BNode at which a new BNode
	*                is to be inserted
	*  const T & t - value being placed in new BNode
	*
	* Output:
	*  BNode * - pointer to new BNode
	*****************************************************/
	template <class T>
	void addLeft(BNode <T> * treeNode, const T & t) throw (const char *)
	{
		try
		{
			if (treeNode != NULL)
			{
				BNode <T> * newNode = new BNode <T>(t);
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
	* Description: Insert a new BNode into the current
	*  Binary Tree. The new BNode will be inserted to the
	*  left of the current node
	*
	* Input:
	*  BNode *pBNode - pointer to BNode at which a new BNode
	*                is to be inserted
	*  const T & t - value being placed in new BNode
	*
	* Output:
	*  BNode * - pointer to new BNode
	*****************************************************/
	template <class T>
	void addLeft(BNode <T> * treeNode, BNode <T> * newNode) throw (const char *)
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
	* Description: Insert a new BNode into the current
	*  Binary Tree. The new BNode will be inserted to the
	*  left of the current node
	*
	* Input:
	*  BNode *pBNode - pointer to BNode at which a new BNode
	*                is to be inserted
	*  const T & t - value being placed in new BNode
	*
	* Output:
	*  BNode * - pointer to new BNode
	*****************************************************/
	template <class T>
	void addRight(BNode <T> * treeNode, const T & t) throw (const char *)
	{
		try
		{
			if (treeNode != NULL)
			{
				BNode <T> * newNode = new BNode <T>(t);
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
	* Description: Insert a new BNode into the current
	*  Binary Tree. The new BNode will be inserted to the
	*  left of the current node
	*
	* Input:
	*  BNode *pBNode - pointer to BNode at which a new BNode
	*                is to be inserted
	*  const T & t - value being placed in new BNode
	*
	* Output:
	*  BNode * - pointer to new BNode
	*****************************************************/
	template <class T>
	void addRight(BNode <T> * treeNode, BNode <T> * newNode) throw (const char *)
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
	*  BNode *pBNode - pointer to start of linked-list
	*
	* Output:
	*  ostream - output stream value
	*****************************************************/
	template <class T>
	ostream & operator <<(ostream & out, const BNode <T> * pBNode) throw (const char *)
	{
		try
		{
			if (pBNode != nullptr)
			{
				out << pBNode->data;
				if (pBNode->pNext != nullptr)
					out << ", " << pBNode->pNext;
			}
			return out;
		}
		catch (const bad_alloc & e)
		{
			cout << "ERROR: Insertion operator not working due to - " << e.what() << endl;
		}
	}

#endif // BNode_H