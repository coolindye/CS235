/***********************************************************************
 * Component:
 *    Assignment 09, Binary Search Tree (BST)
 *    Brother <your instructor name here>, CS 235
 * Author:
 *    <your name here>
 * Summary:
 *    Create a binary search tree
 ************************************************************************/

#ifndef BST_H
#define BST_H
using namespace std;

namespace custom
{
	template <class T>
	class BST
	{
	public:
		class node
		{
		public:
			T data;
			node* pLeft;
			node* pRight;
			node* pParent;
			bool isRed;

			node() : data(NULL), pLeft(NULL), pRight(NULL), pParent(NULL) {}
			node(T value) : data(value), pLeft(NULL), pRight(NULL), pParent(NULL), isRed(true) {}
			node(T value, node* parent) : data(value), pLeft(NULL), pRight(NULL), pParent(parent), isRed(true) {}
		};

		class iterator
		{
		private:
			node* p;

			//Check if node is a right node
			bool isRightNode(node* nodeR)
			{
				if (nodeR->pParent != NULL)
					return( nodeR == nodeR->pParent->pRight );
				return false;
			}
			//Check if node is a left node
			bool isLeftNode(node* nodeL)
			{
				if (nodeL->pParent != NULL)
					return(nodeL == nodeL->pParent->pLeft);
				return false;
			}

		public:
			iterator() : p(NULL) {}
			iterator(node* p) : p(p) {}
			iterator(iterator & rhs) : p(rhs.p) {}
			iterator & operator = (const iterator & rhs) 
			{ 
				p = rhs.p;
				return *this;
			}
			iterator & operator = (const node* p)
			{
				this->p = p;
				return *this;
			}

			bool operator == (const iterator & rhs) { return (p == rhs.p); }
			bool operator != (const iterator & rhs) { return (p != rhs.p); }
			node* getNode() { return p; }
			const T & operator * () const { return p->data; }


			//prefix increment
			iterator & operator ++ ()
			{
				// do nothing if we have nothing
				if (p == NULL)
					return *this;

				// if there is a right node, take it and do magic
				else if (p->pRight != NULL)
				{
					p = p->pRight;
					while (p->pLeft != NULL) p = p->pLeft;
				}
				// if there is a parent node, take it if left node and do magic if right node
				else if (p->pParent != NULL)
				{
					if (isLeftNode(p)) p = p->pParent;

					else
					{
						while (isRightNode(p))
						{
							p = p->pParent;
							if (p->pParent == NULL)
							{
								p = NULL;
								break;
							}
							else if (isLeftNode(p))
							{
								p = p->pParent;
								break;
							}
						}
					}
				}
				
				return *this;
			}

			// postfix increment
			iterator operator ++ (int postfix)
			{
				iterator tmp(*this);

				// do nothing if we have nothing
				if (p == NULL)
					return *this;

				// if there is a right node, take it and do magic
				else if (p->pRight != NULL)
				{
					p = p->pRight;
					while (p->pLeft != NULL) p = p->pLeft;
				}
				// if there is a parent node, take it if left node and do magic if right node
				else if (p->pParent != NULL)
				{
					if (isLeftNode(p)) p = p->pParent;
					else
					{
						while (isRightNode(p))
						{
							p = p->pParent;
							if (p->pParent == NULL)
							{
								p = NULL;
								break;
							}
							else if (isLeftNode(p))
							{
								p = p->pParent;
								break;
							}
						}
					}

				}

				return tmp;
			}

			//prefix decrement
			iterator & operator -- ()
			{
				// do nothing if we have nothing
				if (p == NULL)
					return *this;

				// if there is a right node, take it and do magic
				else if (p->pLeft != NULL)
				{
					p = p->pLeft;
					while (p->pRight != NULL) p = p->pRight;
				}
				// if there is a parent node, take it if left node and do magic if right node
				else if (p->pParent != NULL)
				{
					if (isRightNode(p)) p = p->pParent;

					else
					{
						while (isLeftNode(p))
						{
							p = p->pParent;
							if (p->pParent == NULL)
							{
								p = NULL;
								break;
							}
							else if (isRightNode(p))
							{
								p = p->pParent;
								break;
							}
						}
					}
				}

				return *this;
			}

			// postfix decrement
			iterator operator -- (int postfix)
			{
				iterator tmp(*this);

				// do nothing if we have nothing
				if (p == NULL)
					return *this;

				// if there is a right node, take it and do magic
				else if (p->pLeft != NULL)
				{
					p = p->pLeft;
					while (p->pRight != NULL) p = p->pRight;
				}
				// if there is a parent node, take it if left node and do magic if right node
				else if (p->pParent != NULL)
				{
					if (isRightNode(p)) p = p->pParent;

					else
					{
						while (isLeftNode(p))
						{
							p = p->pParent;
							if (p->pParent == NULL)
							{
								p = NULL;
								break;
							}
							else if (isRightNode(p))
							{
								p = p->pParent;
								break;
							}
						}
					}
				}

				return tmp;
			}
		};

		BST() : root(NULL), numElements(0) {}
		BST(BST<T> & rhs) throw (const char *);
		BST<T> & operator = (const BST<T> &  rhs);
		~BST() { clear(); }

		int size() const { return numElements; }
		bool empty() { return (numElements == 0 ? true : false); }

		void clear();
		void insert(T t);
		void erase(iterator & it);
		iterator find(T t);

		iterator begin();
		iterator end() 
		{
			iterator temp(NULL);
			return temp; 
		}
		iterator rbegin();
		iterator rend() 
		{ 
			iterator temp(NULL);
			return temp; 
		}

	private:
		node* root;
		int numElements;

		void privateDeleteBTree(node*& root);
		void privateErase(node*& root);
		node* privateCopyBTree(const node* root) throw (const char *);
		void privateInsert(T t, node*& root);
		node* privateFind(T t, node* root);

	};



	/**************************************************
	 * BST ITERATOR :: DECREMENT PREFIX
	 *     advance by one.
	 * Author:      Br. Helfrich
	 * Performance: O(log n) though O(1) in the common case
	 *************************************************
	template <class T>
	typename BST <T> :: iterator & BST <T> :: iterator :: operator -- ()
	{
	   // do nothing if we have nothing
	   if (NULL == pNode)
		  return *this;

	   // if there is a left node, take it
	   if (NULL != pNode->pLeft)
	   {
		  // go left
		  pNode = pNode->pLeft;

		  // jig right - there might be more right-most children
		  while (pNode->pRight)
			 pNode = pNode->pRight;
		  return *this;
	   }

	   // there are no left children, the right are done
	   assert(NULL == pNode->pLeft);
	   BNode * pSave = pNode;

	   // go up
	   pNode = pNode->pParent;

	   // if the parent is the NULL, we are done!
	   if (NULL == pNode)
		  return *this;

	   // if we are the right-child, got to the parent.
	   if (pSave == pNode->pRight)
		  return *this;

	   // we are the left-child, go up as long as we are the left child!
	   while (NULL != pNode && pSave == pNode->pLeft)
	   {
		  pSave = pNode;
		  pNode = pNode->pParent;
	   }

	   return *this;
	}*/

	/******************************************************
	*
	*
	*
	*********************************************************/
	template<class T>
	BST<T>::BST(BST<T>& rhs) throw(const char *)
	{
		this->numElements = rhs.numElements;
		this->root = privateCopyBTree(rhs.root);
	}

	/******************************************************
	*
	*
	*
	*********************************************************/
	template<class T>
	BST<T> & BST<T>::operator=(const BST<T>& rhs)
	{
		this->numElements = rhs.numElements;
		this->root = privateCopyBTree(rhs.root);

		return *this;
	}

	/******************************************************
	*
	*
	*
	*********************************************************/
	template<class T>
	void BST<T>::clear()
	{
		privateDeleteBTree(this->root);
		this->numElements = 0;
	}

	/******************************************************
	*
	*
	*
	*********************************************************/
	template<class T>
	void BST<T>::privateDeleteBTree(node *& root)
	{
		try
		{
			if (root == NULL) return;
			if (root->pLeft != NULL)
			{
				root->pLeft->pParent = nullptr;
				privateDeleteBTree(root->pLeft);
				root->pLeft = nullptr;
			}
			if (root->pRight != NULL)
			{
				root->pRight->pParent = nullptr;
				privateDeleteBTree(root->pRight);
				root->pRight = nullptr;
			}

			// This section is so that the calling of this method 
			// on any node ensures the deletion of every node in
			// the tree, ancestor or descendent
			if (root->pParent != NULL)
			{
				if (root->pParent->pLeft == root)
				{
					root->pParent->pLeft = nullptr;
					privateDeleteBTree(root->pParent);
					root->pParent = nullptr;
				}
				if (root->pParent->pRight == root)
				{
					root->pParent->pRight = nullptr;
					privateDeleteBTree(root->pParent);
					root->pParent = nullptr;
				}
			}
			root = NULL;
		}
		catch (const bad_alloc & e)
		{
			cout << "Unable to allocate a node" << endl;
		}
	}

	/*****************************************************
	* Function: COPY BTREE
	* Description: Copy a Binary Tree. Takes a pointer to
	*  a BNode as a parameter and returns a newly created
	*  Binary Tree containing a copy of all the BNodes
	*  below the BNode represented by the parameter.
	*
	* Input:
	*  const BNode *head - pointer to start of Binary Tree
	*
	* Output:
	*  BNode * - pointer to start of new list
	*****************************************************/
	template<class T>
	typename BST<T>::node* BST<T>::privateCopyBTree(const node * root) throw(const char *)
	{
		try
		{
			//Only copy from the node provided down, allows for the creation of subtrees with this method
			if (root != NULL)
			{
				BST<T>::node* newNode = new BST<T>::node(root->data);
				if (root->pLeft != NULL)
				{
					newNode->pLeft = privateCopyBTree(root->pLeft);

					// Not strictly necessary because of root->pLeft check
					if (newNode->pLeft != NULL)
						newNode->pLeft->pParent = newNode;
				}
				if (root->pRight != NULL)
				{
					newNode->pRight = privateCopyBTree(root->pRight);

					// Same as above comment, this if statement is just to make
					// sure there are no assignment issues in the last line
					// that could cause a crash
					if (newNode->pRight != NULL)
						newNode->pRight->pParent = newNode;
				}

				return newNode;
			}

			return NULL;

		}
		catch (std::bad_alloc & e)
		{
			cout << "Unable to allocate a node" << endl;
		}
	}

	/******************************************************
	*
	*
	*
	*********************************************************/
	template<class T>
	void BST<T>::insert(T t)
	{
		privateInsert(t, this->root);
		numElements++;
	}

	/******************************************************
	*
	*
	*
	*********************************************************/
	template<class T>
	void BST<T>::privateInsert(T t, node*& root)
	{
		if (root == NULL)
		{
			root = new node(t);
		}
		else if (t < root->data)
		{
			if (root->pLeft != NULL)
			{
				privateInsert(t, root->pLeft);
			}
			else
			{
				root->pLeft = new node(t, root);
			}
		}
		else if (t > root->data)
		{
			if (root->pRight != NULL)
			{
				privateInsert(t, root->pRight);
			}
			else
			{
				root->pRight = new node(t, root);
			}
		}
	}

	/******************************************************
	*
	*
	*
	*********************************************************/
	template<class T>
	void BST<T>::erase(iterator & it)
	{
		node* root = it.getNode();
		privateErase(root);
	}


	/******************************************************
	*
	*
	*
	*********************************************************/
	template<class T>
	void BST<T>::privateErase(node*& root)
	{
		if (root == NULL) return;
		//no child
		if (root->pLeft == NULL && root->pRight == NULL)
		{
			if (root->pParent != NULL)
			{
				if (root->pParent->pLeft == root)
				{
					root->pParent->pLeft = nullptr;
					root->pParent = nullptr;
				}
				if (root->pParent->pRight == root)
				{
					root->pParent->pRight = nullptr;
					root->pParent = nullptr;
				}
			}
			root->data = NULL;
		}
		//one child
		else if (root->pLeft == NULL && root->pRight != NULL 
					|| root->pLeft != NULL && root->pRight == NULL)
		{
			if (root->pParent != NULL)
			{ 
				if (root->pLeft != NULL)
				{
					if (root == root->pParent->pLeft)
					{
						root->pParent->pLeft = root->pLeft;
					}
					if (root == root->pParent->pRight)
					{
						root->pParent->pRight = root->pLeft;
					}
					root->pLeft->pParent = root->pParent;
					root->pParent = NULL;
					root->pLeft = NULL;
				}
				if (root->pRight != NULL)
				{
					if (root == root->pParent->pLeft)
					{
						root->pParent->pLeft = root->pRight;
					}
					if (root == root->pParent->pRight)
					{
						root->pParent->pRight = root->pRight;
					}
					root->pRight->pParent = root->pParent;
					root->pParent = NULL;
					root->pRight = NULL;
				}
			}
			root->data = NULL;
		}
		//two children
		else if (root->pLeft != NULL && root->pRight != NULL)
		{
			node* b = root->pRight;
			while (b->pLeft != NULL) b = b->pLeft;
			if (b->pRight != NULL)
			{
				b->pParent->pLeft = b->pRight;
				b->pRight->pParent = b->pParent;
			}
			else
			{
				b->pParent->pLeft = NULL;
			}
			b->pRight = root->pRight;
			root->pRight->pParent = b;
			b->pLeft = root->pLeft;
			root->pLeft->pParent = b;
			b->pParent = root->pParent;
			if (root->pParent != NULL)
			{
				if (root == root->pParent->pLeft)
				{
					root->pParent->pLeft = b;
				}
				if (root == root->pParent->pRight)
				{
					root->pParent->pRight = b;
				}
				root->pParent = NULL;
				root->pLeft = NULL;
				root->pRight = NULL;
				root->data = NULL;

			}
			else
			{
				root->pParent = b->pParent;
				root->pLeft = b->pLeft;
				root->pRight = b->pRight;
				root->data = b->data;
			}

		}
	}

	/******************************************************
	*
	*
	*
	*********************************************************/
	template<class T>
	typename BST<T>::iterator BST<T>::find(T t)
	{
		node* temp = privateFind( t, this->root);
		iterator tempI(temp);
		return tempI;
	}

	/******************************************************
	*
	*
	*
	*********************************************************/
	template<class T>
	typename BST<T>::node* BST<T>::privateFind(T t, node* root)
	{
		iterator temp();
		if (root == NULL || t == root->data)
		{
			return root;
		}
		else if (t < root->data)
		{
			return privateFind(t, root->pLeft);
		}
		else if (t > root->data)
		{
			return privateFind(t, root->pRight);
		}
		return root;
	}

	/******************************************************
	*
	*
	*
	*********************************************************/
	template<class T>
	typename BST<T>::iterator BST<T>::begin()
	{
		if (this->root == NULL)
		{
			iterator temp(NULL);
			return temp;
		}

		node* temp = root;
		while (temp->pLeft != NULL) temp = temp->pLeft;
		iterator tempI(temp);
		return (tempI);
	}

	/******************************************************
	*
	*
	*
	*********************************************************/
	template<class T>
	typename BST<T>::iterator BST<T>::rbegin()
	{
		if (this->root == NULL)
		{
			iterator temp(NULL);
			return temp;
		}

		node* temp = root;
		while (temp->pRight != NULL) temp = temp->pRight;
		iterator tempI(temp);
		return (tempI);
	}
} // namespace custom

#endif // BST_H
