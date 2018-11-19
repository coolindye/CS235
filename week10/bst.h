/***********************************************************************
 * Component:
 *    Assignment 09, Binary Search Tree (BST)
 *    Brother Kirby, CS 235
 * Author:
 *    Garrett/Aiden/Ian
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

		/*****************************************************
		* Classs: BNode
		* Description: Node container for Binary Tree
		*****************************************************/
		class BNode
		{
		public:
			T data;
			BNode* pLeft;
			BNode* pRight;
			BNode* pParent;
			bool isRed;

			// BNode constructors
			BNode() : data(NULL), pLeft(NULL), pRight(NULL), pParent(NULL), isRed(true){}
			BNode(T value) : data(value), pLeft(NULL), pRight(NULL), pParent(NULL), isRed(true) {}
			BNode(T value, BNode* parent) : data(value), pLeft(NULL), pRight(NULL), pParent(parent), isRed(true) {}

			// BNode destructor; explicitly calls T destructor because it can't assume it will be called
			// during the balancing process
			~BNode()
			{
				data.~T();
				pLeft = NULL;
				pRight = NULL;
				pParent = NULL;
				isRed = NULL;
			}
		};

		/*****************************************************
		* Class: iterator
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

			//Constructors
			iterator() : p(NULL) {}
			iterator(BNode* p) : p(p) {}
			iterator(iterator & rhs) : p(rhs.p) {}

			//Assignment operators, can be assigned to an iterator or BNode*
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

			// Incrementing can be done without a stack, you just need to make
			// sure that you always check the right child first. if...else 
			// logic will work, but a series of if statements would not

			// prefix increment
			iterator & operator ++ ()
			{
				// do nothing if we have nothing
				if (p == NULL)
					return *this;

				// if there is a right BNode go to it and go to the farthest left node
				// By the structure of a Binary Tree, this will always be the closest
				// valued node that is greater than the current
				else if (p->pRight != NULL)
				{
					p = p->pRight;

					while (p->pLeft != NULL) 
						p = p->pLeft;
				}

				// If the right node is NULL then check what type of child it is
				else if (isLeftBNode(p))
				{
					//The next greatest node for a left child is always it's parent
					p = p->pParent;
				}
				else if (isRightBNode(p))
				{
					// The next greatest node for a right child is always the parent
					// of the first ancestor that is a left child
					while (isRightBNode(p))
					{
						p = p->pParent;
					}
					p = p->pParent;
				}
				else
				{
					p = NULL;
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

				// if there is a right BNode go to it and go to the farthest left node
				// By the structure of a Binary Tree, this will always be the closest
				// valued node that is greater than the current
				else if (p->pRight != NULL)
				{
					p = p->pRight;

					while (p->pLeft != NULL)
						p = p->pLeft;
				}

				// If the right node is NULL then check what type of child it is
				else if (isLeftBNode(p))
				{
					//The next greatest node for a left child is always it's parent
					p = p->pParent;
				}
				else if (isRightBNode(p))
				{
					// The next greatest node for a right child is always the parent
					// of the first ancestor that is a left child
					while (isRightBNode(p))
					{
						p = p->pParent;
					}
					p = p->pParent;
				}
				else
				{
					p = NULL;
				}

				return tmp;
			}

			//prefix decrement
			iterator & operator -- ()
			{
				// do nothing if we have nothing
				if (p == NULL)
					return *this;

				// if there is a Left BNode go to it and go to the farthest Right node
				// By the structure of a Binary Tree, this will always be the closest
				// valued node that is less than the current
				else if (p->pLeft != NULL)
				{
					p = p->pLeft;

					while (p->pRight != NULL)
						p = p->pRight;
				}

				// If the Left node is NULL then check what type of child it is
				else if (isRightBNode(p))
				{
					//The next smallest node for a right child is always it's parent
					p = p->pParent;
				}
				else if (isLeftBNode(p))
				{
					// The next smalles node for a left child is always the parent
					// of the first ancestor that is a right child
					while (isLeftBNode(p))
					{
						p = p->pParent;
					}
					p = p->pParent;
				}
				else
				{
					p = NULL;
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

				// if there is a Left BNode go to it and go to the farthest Right node
				// By the structure of a Binary Tree, this will always be the closest
				// valued node that is less than the current
				else if (p->pLeft != NULL)
				{
					p = p->pLeft;

					while (p->pRight != NULL)
						p = p->pRight;
				}

				// If the Left node is NULL then check what type of child it is
				else if (isRightBNode(p))
				{
					//The next smallest node for a right child is always it's parent
					p = p->pParent;
				}
				else if (isLeftBNode(p))
				{
					// The next smalles node for a left child is always the parent
					// of the first ancestor that is a right child
					while (isLeftBNode(p))
					{
						p = p->pParent;
					}
					p = p->pParent;
				}
				else
				{
					p = NULL;
				}

				return tmp;
			}
		};

		//Binary Search Tree Constructors/destructors
		BST() : root(NULL), numElements(0) {}
		BST(BST<T> & rhs) throw (const char *);
		BST<T> & operator = (const BST<T> &  rhs);
		~BST() { clear(); }

		//bst functions defined inline in BST definition
		int size() const { return numElements; }
		bool empty() { return (numElements == 0 ? true : false); }

		//bst functions defined below
		void clear();
		void insert(T t);
		void erase(iterator & it);

		// bnode getter function
		// Assignment requires this, violates the concept of data hiding
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
		void privateClear(BNode*& root);
		void privateErase(BNode*& root);
		void privateInsert(T t, BNode*& root);

		//private functions validating node placement
		void validateTree();
		void validateBNode(BNode*& root);
		bool isValidBNode(BNode* root);
		void rotateRight(BNode* rotateBNode);
		void rotateLeft(BNode* rotateBNode);

		//private node helper functions
		BNode* privateCopyBTree(const BNode* root) throw (const char *);
		BNode* privateFind(T t, BNode* root);
		bool isRightChild(BNode* root);
		bool isLeftChild(BNode* root);

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
	* Description: deletes the BST 
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
		privateClear(root);
		numElements = 0;
	}

	/*****************************************************
	* Function: PRIVATE CLEAR
	* Description: deletes all elements of the bst
	*  recursively
	*
	* Input:
	*  Bnode *& - a node within the BST
	*
	* Output:
	*  void
	*****************************************************/
	template<class T>
	void BST<T>::privateClear(BNode *& root)
	{
		try
		{
			if (root == NULL) return;
			if (root->pLeft != NULL)
			{
				root->pLeft->pParent = nullptr;
				privateClear(root->pLeft);
			}
			if (root->pRight != NULL)
			{
				root->pRight->pParent = nullptr;
				privateClear(root->pRight);
			}

			// This section is so that the calling of this method 
			// on any BNode ensures the deletion of every BNode in
			// the tree, ancestor or descendent
			if (root->pParent != NULL)
			{
				privateClear(root->pParent);
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
	* Description: Takes the passed T value and adds it to
	*  the tree. Inserts every value in a node colored red
	*  to limit the validation errors that can occur. 
	*  Validates tree after insertion to confirm that it 
	*  is balanced according to red-black rules.
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
	*  by checking each node on it's way down to see if the
	*  data passed is more or less than the data in the 
	*  node being checked
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
		// No nodes in tree, add new root with data given
		if (root == NULL)
		{
			root = new BNode(t);
		}
		// Try to move data to left child if it is less than
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
		// Try to move data to right child if it is more than
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
	* Description: Gets a node from the passed iterator
	*  and removes it from the tree. Validates tree after
	*  removal of node for balancing.
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
	* Description: Erases the node from the input, private
	*  method to allow for hiding implementation details
	*  from client. 
	*
	* Input:
	*  Bnode - reference to node from the iterator from
	*          the erase function
	*
	* Output:
	*  void
	*****************************************************/
	template<class T>
	void BST<T>::privateErase(BNode*& root)
	{
		// if the tree has not been created return with no changes
		if (root == NULL) return;

		/**************************************************
		* Three possibilities for removal of a node. 
		* 1. With no children you just need to remove the 
		* node.
		* 2. With one child you need to move the child to 
		* the spot where the node being removed is.
		* 3. With two children you need to find the smallest
		* child in the right subtree and move it up to the
		* place of the removed node.
		**************************************************/

		//no child
		if (root->pLeft == NULL && root->pRight == NULL)
		{
			//Check for root node
			if (root->pParent != NULL)
			{
				//Is it a left child
				if (root->pParent->pLeft == root)
				{
					root->pParent->pLeft = nullptr;
					root->pParent = nullptr;
				}
				//No need to check 2 cases
				else
				{
					root->pParent->pRight = nullptr;
					root->pParent = nullptr;
				}
			}
			//delete node
			root->~BNode();
		}

		// one child
		else if (root->pLeft == NULL && root->pRight != NULL 
					|| root->pLeft != NULL && root->pRight == NULL)
		{
			// Check if root node
			if (root->pParent != NULL)
			{ 
				// is the child of root a left child?
				if (root->pLeft != NULL)
				{
					// is root a left child
					if (isLeftChild(root))
					{
						root->pParent->pLeft = root->pLeft;
					}
					// is root a right child
					else
					{
						root->pParent->pRight = root->pLeft;
					}
					root->pLeft->pParent = root->pParent;
				}
				// is the child of root a left child?
				else
				{
					// is root a left child
					if (isLeftChild(root))
					{
						root->pParent->pLeft = root->pRight;
					}
					// is root a right child
					else
					{
						root->pParent->pRight = root->pRight;
					}
					root->pRight->pParent = root->pParent;
				}
			}
			//Delete Node
			root->~BNode();
		}

		//two children
		else if (root->pLeft != NULL && root->pRight != NULL)
		{
			// create new node because we don't know what node
			// needs to be moved and need to have data moved
			BNode* b = root->pRight;

			// Find the smallest node in the right subtree
			// by going left until NULL
			if (b->pLeft != NULL)
			{
				while (b->pLeft != NULL) b = b->pLeft;
			}

			// Move nodes connected to found node up
			if (b->pRight != NULL) 
				b->pRight->pParent = b->pParent;

			// Connect found node's parent to lower node
			if (isLeftChild(b))
				b->pParent->pLeft = b->pRight;
			else
				b->pParent->pRight = b->pRight;

			// Move data to root and delete the found node 
			root->data = b->data;
			b->~BNode();
		}
	}

	/*****************************************************
	* Function: ROTATE RIGHT
	* Description: Rotates the current node to the right.
	*  Keeps tree balanced while doing so. Assumes node is
	*  not null and has a left child
	*
	*  Example:
	*
	*  Rotate-> 12                 8*
	*       +---+---+          +---+---+
	*       8       13   -->   4       12*
	*    +--+--+                    +--+--+
	*    4     9                    9*     13
	*
	* Input:
	*  Bnode - node you want to rotate right
	*
	* Output:
	*  void
	*****************************************************/
	template<class T>
	void BST<T>::rotateRight(BNode* rotateBNode)
	{
		rotateBNode->pLeft->pParent = rotateBNode->pParent;

		// If root node, skip these steps to avoid 
		// dereferencing nullptr
		if (rotateBNode->pParent != NULL)
		{
			if (rotateBNode->pParent->pLeft == rotateBNode)
				rotateBNode->pParent->pLeft = rotateBNode->pLeft;
			else
				rotateBNode->pParent->pRight = rotateBNode->pLeft;
		}
		rotateBNode->pParent = rotateBNode->pLeft;
		rotateBNode->pLeft = rotateBNode->pLeft->pRight;

		// check to avoid dereferencing a null pointer 
		// after previous changes
		if (rotateBNode->pLeft != NULL) rotateBNode->pLeft->pParent = rotateBNode;
		rotateBNode->pParent->pRight = rotateBNode;
		rotateBNode = rotateBNode->pParent;
	}

	/*****************************************************
	* Function: ROTATE LEFT
	* Description: Rotates the current node to the left.
	*  Keeps tree balanced while doing so. Assumes node is
	*  not null and has a right child
	*
	*  Example:
	*
	*  Rotate-> 8                       12*
    *       +---+---+               +---+---+
    *       4       12     -->      8*      13
    *            +--+--+         +--+--+  
    *            9     13        4     9*  
	*
	* Input:
	*  Bnode - node you want to rotate left
	*
	* Output:
	*  void
	*****************************************************/
	template<class T>
	void BST<T>::rotateLeft(BNode* rotateBNode)
	{
		rotateBNode->pRight->pParent = rotateBNode->pParent;

		// If root node, skip these steps to avoid 
		// dereferencing nullptr
		if (rotateBNode->pParent != NULL)
		{
			if (rotateBNode->pParent->pLeft == rotateBNode)
				rotateBNode->pParent->pLeft = rotateBNode->pRight;
			else
				rotateBNode->pParent->pRight = rotateBNode->pRight;
		}
		rotateBNode->pParent = rotateBNode->pRight;
		rotateBNode->pRight = rotateBNode->pRight->pLeft;

		// check to avoid dereferencing a null pointer 
		// after previous changes
		if (rotateBNode->pRight != NULL) rotateBNode->pRight->pParent = rotateBNode;
		rotateBNode->pParent->pLeft = rotateBNode;
		rotateBNode = rotateBNode->pParent;
	}

	/*****************************************************
	* Function: validateTree
	* Description: Makes the entire current BST balanced
	*  following the logic of red-black balancing.
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
		// Use iterator to loop through tree making
		// sure that the tree is balanced
		iterator it(begin().p);
		for (it; it != end(); it)
		{
			//If node is valid then advance
			if (isValidBNode(it.p))
			{
				it++;
			}

			//No need to check validity twice
			else
			{
				validateBNode(it.p);

				// Resets the iterator in cases of  
				// validation causing iterator to change 
				it = begin();
			}
		}

	}

	/*****************************************************
	* Function: validateBNode
	* Description: validates the specific node for 
	*   red-black rules. Assumes the node in question is 
	*   in violation. DO NOT PASS VALID NODES TO THIS
	*
	* Input:
	*  Bnode *& - the node that is being validated
	*
	* Output:
	*  void
	*****************************************************/
	template<class T>
	void BST<T>::validateBNode(BNode*& root)
	{
		//BNode is root. change color to black
		if (root->pParent == NULL)
		{
			root->isRed = false;
			return;
		}

		//Parent is a left child
		if (isLeftChild(root->pParent))
		{
			// The uncle node is essential to knowing what we need to do
			// to fix validation
			BNode* uncle = root->pParent->pParent->pRight;

			//uncle is black
			if (uncle == NULL || !uncle->isRed)
			{
				// Line occurs, rotate grandparent right and change colors
				// of parent and grand parent
				if (isLeftChild(root))
				{
					root->pParent->isRed = false;
					root->pParent->pParent->isRed = true;
					rotateRight(root->pParent->pParent);
				}
				// Corner occurs, rotate parent left
				else
				{
					rotateLeft(root->pParent);
				}
			}
			// Uncle is red, just change colors
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
				// Line occurs, rotate grandparent left and change colors
				// of parent and grandparent
				if (isRightChild(root))
				{
					root->pParent->isRed = false;
					root->pParent->pParent->isRed = true;
					rotateLeft(root->pParent->pParent);
				}
				//Corner occurs rotate parent right
				else
				{
					rotateRight(root->pParent);
				}
			}
			//Uncle is red, just change colors
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
	* Description: checks if passed node is following the
	*  red - black rules for balancing. There are only two
	*  invalid conditions.
	*  1. BST root node is red
	*  2. Node is red and so is it's parent node
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
		// If there are no nodes, just return
		if (root == NULL) 
			return true;

		// If passed node is the root of the BST
		if (root->pParent == NULL)
		{
			//BST root cannot be red
			if (root->isRed)
				return false;
			else if (!root->isRed)
				return true;
		}
		else if (root->pParent != NULL && root->isRed)
		{
			// If the parent of a red node is also red, 
			// that is the only other time a node is invalid
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
	*  bool - it is/ or it isn't a right child
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
	*  bool - it is/ or it isn't a left child
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
	* Description: returns an iterator to a node that
	*  has the value passed. Returns an iterator to NULL
	*  if it isn't found
	*
	* Input:
	*  T - the data value being looked for
	*
	* Output:
	*  iterator - iterator pointing to the node with 
	*             containing the data being looked for
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
	* Description: Private method for find that allows for
	*  the hiding of the implementation of find from the 
	*  client. Uses a recursive function. Due to the 
	*  red-black balancing of the tree, the time complexity
	*  of finding a value is always O(log(n))
	*
	* Input:
	*  T - data item to be found
	*  Bnode* - root node of bst
	*
	* Output:
	*  iterator - iterator pointing to the node that
	*             contains the data being looked for
	*****************************************************/
	template<class T>
	typename BST<T>::BNode* BST<T>::privateFind(T t, BNode* root)
	{
		// This follows the same pattern and code as the insert function

		// Since every node is instantiated with all default nodes by 
		// default, every leaf will have null pointer children so we
		// do not need to explicitly return a NULL value.
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

		//We do return a NULL value here for safety but it is not necessary
		root = NULL;
		return root;
	}

	/*****************************************************
	* Function: begin
	* Description: returns an iterator to the 
	*  first/smallest valued node in the BST
	*
	* Input:
	*  n/a
	*
	* Output:
	*  iterator - iterator to the first item in tree
	*****************************************************/
	template<class T>
	typename BST<T>::iterator BST<T>::begin()
	{
		// Check for NULL root value
		if (this->root == NULL)
		{
			iterator temp(NULL);
			return temp;
		}


		BNode* temp = root;

		// Smallest valued node will always be in the farthest left node
		while (temp->pLeft != NULL) 
			temp = temp->pLeft;
		iterator tempI(temp);
		return (tempI);
	}

	/*****************************************************
	* Function: rbegin
	* Description: returns an iterator to the largest 
	*  valued node of the BST
	*
	* Input:
	*  n/a
	*
	* Output:
	*  iterator - iterator to last item in tree
	*****************************************************/
	template<class T>
	typename BST<T>::iterator BST<T>::rbegin()
	{
		// Check for NULL root value
		if (this->root == NULL)
		{
			iterator temp(NULL);
			return temp;
		}

		BNode* temp = root;

		// Smallest valued node will always be in the farthest right node
		while (temp->pRight != NULL) temp = temp->pRight;
		iterator tempI(temp);
		return (tempI);
	}
} // namespace custom

#endif // BST_H