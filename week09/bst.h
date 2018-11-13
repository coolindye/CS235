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

namespace custom
{

    //template <class T>
    //class BNode
    //{
    //public:
    //    T data;
    //    BNode * pLeft;
    //    BNode * pRight;
    //    BNode * pParent;
    //    bool isRed;

    //    BNode() : pLeft(NULL), pRight(NULL), pParent(NULL) {}
    //    BNode(T value) : data(value), pLeft(NULL), pRight(NULL), pParent(NULL), isRed(true) {}
    //    

    //private:
    //    //verifyRB(int depth);
    //    //verifyBST();
    //    //balance();
    //};


    template <class T>
    class BST
    {
    public:



        static class BNode
        {
        public:
            T data;
            BNode * pLeft;
            BNode * pRight;
            BNode * pParent;
            bool isRed;

            BNode() : pLeft(NULL), pRight(NULL), pParent(NULL) {}
            BNode(T value) : data(value), pLeft(NULL), pRight(NULL), pParent(NULL), isRed(true) {}


        private:
            //verifyRB(int depth);
            //verifyBST();
            //balance();
        };



        BST() : root(NULL) {}
        BST(BST<T> & rhs) throw (const char *);
        ~BST() { /*deleteBTree(root);*/ }

        BST & operator = (const BST <T> & rhs);

        int size() const { return numElements; }
        bool empty() { return (numElements == 0 ? true : false); }
    private:
        BNode *root = NULL;
        int numElements;

        //void deleteBTree(BNode * & pNode);
        BNode * copyBTree(const BNode * head) throw (const char *);

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
    this->root = copyBTree(rhs.root);
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
    this->root = copyBTree(rhs.root);

    return *this;
}

/******************************************************
*
*
*
*********************************************************
template<class T>
void BST<T>::deleteBTree(BNode *& pNode)
{
    try
    {
        if (head->pLeft != NULL)
        {
            head->pLeft->pParent = nullptr;
            deleteBTree(head->pLeft);
            head->pLeft = nullptr;
        }
        if (head->pRight != NULL)
        {
            head->pRight->pParent = nullptr;
            deleteBTree(head->pRight);
            head->pRight = nullptr;
        }

        // This section is so that the calling of this method 
        // on any BNode ensures the deletion of every BNode in
        // the tree, ancestor or descendent
        if (head->pParent != NULL)
        {
            if (head->pParent->pLeft == head)
            {
                head->pParent->pLeft = nullptr;
                deleteBTree(head->pParent);
                head->pParent = nullptr;
            }
            if (head->pParent->pRight == head)
            {
                head->pParent->pRight = nullptr;
                deleteBTree(head->pParent);
                head->pParent = nullptr;
            }
        }
        head = NULL;
    }
    catch (const bad_alloc & e)
    {
        cout << "Unable to allocate a node" << endl;
    }
}*/

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
template <class T>
BST<T>::BNode * BST<T>::copyBTree(const BST<T>::BNode * head) throw(const char *)
{
    try
    {
        //Only copy from the node provided down, allows for the creation of subtrees with this method
        if (head != NULL)
        {
            BNode <T> * newNode = new BNode <T>(head->data);
            if (head->pLeft != NULL)
            {
                newNode->pLeft = copyBTree(head->pLeft);

                // Not strictly necessary because of head->pLeft check
                if (newNode->pLeft != NULL)
                    newNode->pLeft->pParent = newNode;
            }
            if (head->pRight != NULL)
            {
                newNode->pRight = copyBTree(head->pRight);

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

} // namespace custom

#endif // BST_H
