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
		class BNode
		{
		public:
			T data;
			BNode* pLeft;
			BNode* pRight;
			BNode* pParent;
			bool isRed;

			BNode() : data(NULL), pLeft(NULL), pRight(NULL), pParent(NULL), isRed(true){}
			BNode(T value) : data(value), pLeft(NULL), pRight(NULL), pParent(NULL), isRed(true) {}
			BNode(T value, BNode* parent) : data(value), pLeft(NULL), pRight(NULL), pParent(parent), isRed(true) {}
		};

		/*****************************************************
		* Classs: iterator
		* Description: the iterator class for the bst
		*****************************************************/
		class iterator
		{
			friend class BST;
		private:
			BNode* p;

			//Check if BNode is a right BNode
			bool isRightBNode(BNode* BNodeR)
			{
				if (BNodeR->pParent != NULL)
					return( BNodeR == BNodeR->pParent->pRight );
				return false;
			}
			//Check if BNode is a left BNode
			bool isLeftBNode(BNode* BNodeL)
			{
				if (BNodeL->pParent != NULL)
					return(BNodeL == BNodeL->pParent->pLeft);
				return false;
			}

		public:
			iterator() : p(NULL) {}
			iterator(BNode* p) : p(p) {}
			iterator(iterator & rhs) : p(rhs.p) {}
			iterator & operator = (const iterator & rhs) 
			{ 
				p = rhs.p;
				return *this;
			}
			iterator & operator = (const BNode* p)
			{
				this->p = p;
				return *this;
			}

			bool operator == (const iterator & rhs) { return (p == rhs.p); }
			bool operator != (const iterator & rhs) { return (p != rhs.p); }
			const T & operator * () const { return p->data; }

			//prefix increment
			iterator & operator ++ ()
			{
				// do nothing if we have nothing
				if (p == NULL)
					return *this;

				// if there is a right BNode, take it and do magic
				else if (p->pRight != NULL)
				{
					p = p->pRight;
					while (p->pLeft != NULL) p = p->pLeft;
				}
				// if there is a parent BNode, take it if left BNode and do magic if right BNode
				else if (p->pParent != NULL)
				{
					if (isLeftBNode(p)) 
						p = p->pParent;
					else
					{
						while (isRightBNode(p))
						{
							p = p->pParent;
							if (p->pParent == NULL)
							{
								p = NULL;
								break;
							}
							else if (isLeftBNode(p))
							{
								p = p->pParent;
								break;
							}
						}
					}
				}
				else
					p = NULL;

				return *this;
			}

			// postfix increment
			iterator operator ++ (int postfix)
			{
				iterator tmp(*this);

				// do nothing if we have nothing
				if (p == NULL)
					return *this;

				// if there is a right BNode, take it and do magic
				else if (p->pRight != NULL)
				{
					p = p->pRight;
					while (p->pLeft != NULL) p = p->pLeft;
				}
				// if there is a parent BNode, take it if left BNode and do magic if right BNode
				else if (p->pParent != NULL)
				{
					if (isLeftBNode(p)) p = p->pParent;
					else
					{
						while (isRightBNode(p))
						{
							p = p->pParent;
							if (p->pParent == NULL)
							{
								p = NULL;
								break;
							}
							else if (isLeftBNode(p))
							{
								p = p->pParent;
								break;
							}
						}
					}

				}
				else
					p = NULL;
				return tmp;
			}

			//prefix decrement
			iterator & operator -- ()
			{
				// do nothing if we have nothing
				if (p == NULL)
					return *this;

				// if there is a right BNode, take it and do magic
				else if (p->pLeft != NULL)
				{
					p = p->pLeft;
					while (p->pRight != NULL) p = p->pRight;
				}
				// if there is a parent BNode, take it if left BNode and do magic if right BNode
				else if (p->pParent != NULL)
				{
					if (isRightBNode(p)) p = p->pParent;

					else
					{
						while (isLeftBNode(p))
						{
							p = p->pParent;
							if (p->pParent == NULL)
							{
								p = NULL;
								break;
							}
							else if (isRightBNode(p))
							{
								p = p->pParent;
								break;
							}
						}
					}
				}
				else
					p = NULL;
				return *this;
			}

			// postfix decrement
			iterator operator -- (int postfix)
			{
				iterator tmp(*this);

				// do nothing if we have nothing
				if (p == NULL)
					return *this;

				// if there is a right BNode, take it and do magic
				else if (p->pLeft != NULL)
				{
					p = p->pLeft;
					while (p->pRight != NULL) p = p->pRight;
				}
				// if there is a parent BNode, take it if left BNode and do magic if right BNode
				else if (p->pParent != NULL)
				{
					if (isRightBNode(p)) p = p->pParent;

					else
					{
						while (isLeftBNode(p))
						{
							p = p->pParent;
							if (p->pParent == NULL)
							{
								p = NULL;
								break;
							}
							else if (isRightBNode(p))
							{
								p = p->pParent;
								break;
							}
						}
					}
				}
				else
					p = NULL;
				return tmp;
			}
		};

		//Binary Search Tree Constructors/destructors
		BST() : root(NULL), numElements(0) {}
		BST(BST<T> & rhs) throw (const char *);
		BST<T> & operator = (const BST<T> &  rhs);
		~BST() { clear(); }

		//bst functions defined on the spot
		int size() const { return numElements; }
		bool empty() { return (numElements == 0 ? true : false); }

		//bst functions defined below
		void clear();
		void insert(T t);
		void erase(iterator & it);

		//bnode function
		BNode* getRoot() { return root; }

		//iterator functions
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
		//root node, how many elements are in the tree
		BNode* root;
		int numElements;

		//private functions managing the tree
		void privateDeleteBTree(BNode*& root);
		void privateErase(BNode*& root);
		void privateInsert(T t, BNode*& root);
		void rotateRight(BNode* rotateBNode);
		void rotateLeft(BNode* rotateBNode);
		void validateTree();
		void validateBNode(BNode*& root);

		//private functions validating node placement
		bool isValidBNode(BNode* root);
		bool isRightChild(BNode* root);
		bool isLeftChild(BNode* root);

		//private node helper functions
		BNode* privateCopyBTree(const BNode* root) throw (const char *);
		BNode* privateFind(T t, BNode* root);

	};

	/*****************************************************
	* Function: BST copy constructor
	* Description: copies one bst to make a new one 
	*
	* Input:
	*  bst<T>& - reference to an existing bst 
	*
	* Output:
	*  n/a
	*****************************************************/
	template<class T>
	BST<T>::BST(BST<T>& rhs) throw(const char *)
	{
		this->numElements = rhs.numElements;
		this->root = privateCopyBTree(rhs.root);
	}

	/*****************************************************
	* Function: assignment operator
	* Description: change this bst to be the same as
	*  a different bst
	*
	* Input:
	*  bst<T>& - reference to an existing bst 
	*
	* Output:
	*  bst<T>& - return a dereference of itself
	*****************************************************/
	template<class T>
	BST<T> & BST<T>::operator=(const BST<T>& rhs)
	{
		this->numElements = rhs.numElements;
		this->root = privateCopyBTree(rhs.root);

		return *this;
	}

	/*****************************************************
	* Function: COPY BTREE
	* Description: Copy a Binary Tree. Takes a pointer to
	*  a BBNode as a parameter and returns a newly created
	*  Binary Tree containing a copy of all the BBNodes
	*  below the BBNode represented by the parameter.
	*
	* Input:
	*  const BBNode *head - pointer to start of Binary Tree
	*
	* Output:
	*  BBNode * - pointer to start of new list
	*****************************************************/
	template<class T>
	typename BST<T>::BNode* BST<T>::privateCopyBTree(const BNode * root) throw(const char *)
	{
		try
		{
			//Only copy from the BNode provided down, allows for the creation of subtrees with this method
			if (root != NULL)
			{
				BST<T>::BNode* newBNode = new BST<T>::BNode(root->data);
				if (root->pLeft != NULL)
				{
					newBNode->pLeft = privateCopyBTree(root->pLeft);

					// Not strictly necessary because of root->pLeft check
					if (newBNode->pLeft != NULL)
						newBNode->pLeft->pParent = newBNode;
				}
				if (root->pRight != NULL)
				{
					newBNode->pRight = privateCopyBTree(root->pRight);

					// Same as above comment, this if statement is just to make
					// sure there are no assignment issues in the last line
					// that could cause a crash
					if (newBNode->pRight != NULL)
						newBNode->pRight->pParent = newBNode;
				}

				return newBNode;
			}

			return NULL;

		}
		catch (std::bad_alloc & e)
		{
			cout << "Unable to allocate a BNode" << endl;
		}
	}

	/*****************************************************
	* Function: clear
	* Description: delets the bst nodes attatched to the 
	*  root
	*
	* Input:
	*  n/a
	*
	* Output:
	*  void
	*****************************************************/
	template<class T>
	void BST<T>::clear()
	{
		privateDeleteBTree(this->root);
		this->numElements = 0;
	}

	/*****************************************************
	* Function: privateDeleteBTree
	* Description: deletes all elements of the bst
	*  recursively
	*
	* Input:
	*  Bnode *& -  basically just give it a node
	*
	* Output:
	*  void
	*****************************************************/
	template<class T>
	void BST<T>::privateDeleteBTree(BNode *& root)
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
			// on any BNode ensures the deletion of every BNode in
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
			cout << "Unable to allocate a BNode" << endl;
		}
	}

	/*****************************************************
	* Function: insert
	* Description: put in a data 't' somewhere in the tree
	*  in such a manner that it is sorted and order is
	*  "preserved" so to speak
	*
	* Input:
	*  T - template data type
	*
	* Output:
	*  void
	*****************************************************/
	template<class T>
	void BST<T>::insert(T t)
	{
		privateInsert(t, this->root);
		numElements++;
		validateTree();
	}

	/*****************************************************
	* Function: privateInsert
	* Description: does the real insertion recursively
	*  by checking each node on it's way down
	*
	* Input:
	*  T, Bnode - data to add, and the node to check adding
	*             it to
	*
	* Output:
	*  void
	*****************************************************/
	template<class T>
	void BST<T>::privateInsert(T t, BNode*& root)
	{
		if (root == NULL)
		{
			root = new BNode(t);
		}
		else if (t < root->data)
		{
			if (root->pLeft != NULL)
			{
				privateInsert(t, root->pLeft);
			}
			else
			{
				root->pLeft = new BNode(t, root);
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
				root->pRight = new BNode(t, root);
			}
		}
	}

	/*****************************************************
	* Function: erase
	* Description: gets a node from the iterator and erases it
	*
	* Input:
	*  iterator - iterator to a node on the bst
	*
	* Output:
	*  void
	*****************************************************/
	template<class T>
	void BST<T>::erase(iterator & it)
	{
		BNode* root = it.p;
		privateErase(root);
		validateTree();
	}

	/*****************************************************
	* Function: privateErase
	* Description: erases the node from the input
	*
	* Input:
	*  Bnode - node from the iterator from the erase function
	*
	* Output:
	*  void
	*****************************************************/
	template<class T>
	void BST<T>::privateErase(BNode*& root)
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
			BNode* b = root->pRight;
			if (b->pLeft != NULL)
			{
				while (b->pLeft != NULL) b = b->pLeft;
			}
			if (b->pRight != NULL) b->pRight->pParent = b->pParent;
			if (isLeftChild(b))
				b->pParent->pLeft = b->pRight;
			if (isRightChild(b))
				b->pParent->pRight = b->pRight;
			root->data = b->data;
		}
	}


	/*****************************************************
	* Function: rotateRight
	* Description: XXXXXXXXXXXXXXXXX
	*  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
	*
	* Input:
	*  Bnode - node you want to rotate right from
	*
	* Output:
	*  void
	*****************************************************/
	template<class T>
	void BST<T>::rotateRight(BNode* rotateBNode)
	{
		rotateBNode->pLeft->pParent = rotateBNode->pParent;
		if (rotateBNode->pParent != NULL)
		{
			if (rotateBNode->pParent->pLeft == rotateBNode)
				rotateBNode->pParent->pLeft = rotateBNode->pLeft;
			else
				rotateBNode->pParent->pRight = rotateBNode->pLeft;
		}
		rotateBNode->pParent = rotateBNode->pLeft;
		rotateBNode->pLeft = rotateBNode->pLeft->pRight;
		if (rotateBNode->pLeft != NULL) rotateBNode->pLeft->pParent = rotateBNode;
		rotateBNode->pParent->pRight = rotateBNode;
		rotateBNode = rotateBNode->pParent;
	}

	/*****************************************************
	* Function: rotate left
	* Description: XXXXXXXXXXXXXXXXX
	*  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
	*
	* Input:
	*  Bnode - node you want to rotate left from
	*
	* Output:
	*  void
	*****************************************************/
	template<class T>
	void BST<T>::rotateLeft(BNode* rotateBNode)
	{
		rotateBNode->pRight->pParent = rotateBNode->pParent;
		if (rotateBNode->pParent != NULL)
		{
			if (rotateBNode->pParent->pLeft == rotateBNode)
				rotateBNode->pParent->pLeft = rotateBNode->pRight;
			else
				rotateBNode->pParent->pRight = rotateBNode->pRight;
		}
		rotateBNode->pParent = rotateBNode->pRight;
		rotateBNode->pRight = rotateBNode->pRight->pLeft;
		if (rotateBNode->pRight != NULL) rotateBNode->pRight->pParent = rotateBNode;
		rotateBNode->pParent->pLeft = rotateBNode;
		rotateBNode = rotateBNode->pParent;
	}

	/*****************************************************
	* Function: validateTree
	* Description: keeps the rules from black
	*  and red implemented
	*
	* Input:
	*  n/a
	*
	* Output:
	*  void
	*****************************************************/
	template<class T>
	void BST<T>::validateTree()
	{
		iterator it(begin().p);
		for (it; it != end(); it)
		{
			if (isValidBNode(it.p))
			{
				it++;
			}
			else
			{
				validateBNode(it.p);
				it = begin();
			}
		}

	}

	/*****************************************************
	* Function: validateBNode
	* Description: validates the specific node
	*  for black and red rules
	*
	* Input:
	*  Bnode *& - 
	*
	* Output:
	*  void
	*****************************************************/
	template<class T>
	void BST<T>::validateBNode(BNode*& root)
	{
		//BNode is root
		if (root->pParent == NULL)
		{
			root->isRed = false;
			return;
		}

		//Parent is a left child
		if (isLeftChild(root->pParent))
		{
			BNode* uncle = root->pParent->pParent->pRight;

			//uncle is black
			if (uncle == NULL || !uncle->isRed)
			{
				//Line occurs
				if (isLeftChild(root))
				{
					root->pParent->isRed = false;
					root->pParent->pParent->isRed = true;
					rotateRight(root->pParent->pParent);
				}
				//Diamond or triangle occurs
				else
				{
					rotateLeft(root->pParent);
				}
			}
			//Uncle is red
			else
			{
				root->pParent->isRed = false;
				root->pParent->pParent->isRed = true;
				root->pParent->pParent->pRight->isRed = false;
			}
		}
		//Parent is right child
		else
		{
			BNode* uncle = root->pParent->pParent->pLeft;

			//uncle is black
			if (uncle == NULL || !uncle->isRed)
			{
				//Line occurs
				if (isRightChild(root))
				{
					root->pParent->isRed = false;
					root->pParent->pParent->isRed = true;
					rotateLeft(root->pParent->pParent);
				}
				//Diamond or triangle occurs
				else
				{
					rotateRight(root->pParent);
				}
			}
			//Uncle is red
			else
			{
				root->pParent->isRed = false;
				root->pParent->pParent->isRed = true;
				root->pParent->pParent->pLeft->isRed = false;
			}
		}
	}

	/*****************************************************
	* Function: isValidBNode
	* Description: checks if red nodes follow red rules
	*
	* Input:
	*  Bnode - the node you want to check the validity
	*
	* Output:
	*  bool - true/false complies/doesn't comply
	*****************************************************/
	template<class T>
	bool BST<T>::isValidBNode(BNode* root)
	{
		if (root == NULL) 
			return true;
		if (root->pParent == NULL)
		{
			if (root->isRed)
				return false;
			else if (!root->isRed)
				return true;
		}
		else if (root->pParent != NULL && root->isRed)
		{
			if (root->pParent->isRed)
				return false;
			else
				return true;
		}
		else if (root->pParent != NULL && !root->isRed)
		{
			return true;
		}
	}

	/*****************************************************
	* Function: isRightChild
	* Description: checks if this node is the right child
	*  of a parent node
	*
	* Input:
	*  Bnode - node you want to check
	*
	* Output:
	*  bool - it is/ or it isn't
	*****************************************************/
	template<class T>
	bool BST<T>::isRightChild(BNode* root)
	{
		if (root == NULL)
			return false;
		else if (root->pParent != NULL)
		{
			return root->pParent->pRight == root;
		}
		return false;
	}

	/*****************************************************
	* Function: isLeftChild
	* Description: checks if this node is the left child
	*  of a parent node
	*
	* Input:
	*  Bnode - node you want to check
	*
	* Output:
	*  bool - it is/ or it isn't
	*****************************************************/
	template<class T>
	bool BST<T>::isLeftChild(BNode* root)
	{
		if (root == NULL)
			return false;
		else if (root->pParent != NULL)
		{
			return root->pParent->pLeft == root;
		}
		return false;
	}

	/*****************************************************
	* Function: find
	* Description: returns the iterator for a node that
	*  has the value of t
	*
	* Input:
	*  T - t
	*
	* Output:
	*  iterator - iterator to the node with data t
	*****************************************************/
	template<class T>
	typename BST<T>::iterator BST<T>::find(T t)
	{
		BNode* temp = privateFind( t, this->root);
		iterator tempI(temp);
		return tempI;
	}

	/*****************************************************
	* Function: privateFind
	* Description: returns the node with data t searching 
	*  from the main root of the bst, until we get 
	*
	* Input:
	*  T, Bnode - data t, and the main root of bst
	*
	* Output:
	*  Bnode - node with data = t, or null
	*****************************************************/
	template<class T>
	typename BST<T>::BNode* BST<T>::privateFind(T t, BNode* root)
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

	/*****************************************************
	* Function: begin
	* Description: returns an iterator for the main
	*  root of the bst
	*
	* Input:
	*  n/a
	*
	* Output:
	*  iterator - iterator to the root
	*****************************************************/
	template<class T>
	typename BST<T>::iterator BST<T>::begin()
	{
		if (this->root == NULL)
		{
			iterator temp(NULL);
			return temp;
		}

		BNode* temp = root;
		while (temp->pLeft != NULL) temp = temp->pLeft;
		iterator tempI(temp);
		return (tempI);
	}


	//is this the reverse begin?
	/*****************************************************
	* Function: rbegin
	* Description: returns a reverse iterator for the main
	*  root of the bst
	*
	* Input:
	*  n/a
	*
	* Output:
	*  iterator - 
	*****************************************************/
	template<class T>
	typename BST<T>::iterator BST<T>::rbegin()
	{
		if (this->root == NULL)
		{
			iterator temp(NULL);
			return temp;
		}

		BNode* temp = root;
		while (temp->pRight != NULL) temp = temp->pRight;
		iterator tempI(temp);
		return (tempI);
	}
} // namespace custom

#endif // BST_H

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
	   if (NULL == pBNode)
		  return *this;

	   // if there is a left BNode, take it
	   if (NULL != pBNode->pLeft)
	   {
		  // go left
		  pBNode = pBNode->pLeft;

		  // jig right - there might be more right-most children
		  while (pBNode->pRight)
			 pBNode = pBNode->pRight;
		  return *this;
	   }

	   // there are no left children, the right are done
	   assert(NULL == pBNode->pLeft);
	   BBNode * pSave = pBNode;

	   // go up
	   pBNode = pBNode->pParent;

	   // if the parent is the NULL, we are done!
	   if (NULL == pBNode)
		  return *this;

	   // if we are the right-child, got to the parent.
	   if (pSave == pBNode->pRight)
		  return *this;

	   // we are the left-child, go up as long as we are the left child!
	   while (NULL != pBNode && pSave == pBNode->pLeft)
	   {
		  pSave = pBNode;
		  pBNode = pBNode->pParent;
	   }

	   return *this;
	}*/
