/***********************************************************************
 * Header:
 *    LIST
 * Summary:
 *    This will contain just the prototype for list().
 * Author
 *    Garrett Smith, Aiden Reid, Ian Stubbs
 ************************************************************************/

#ifndef LIST_H
#define LIST_H

#include <cassert>
#include <iostream>
using namespace std;

namespace custom
{

/****************************************************
* list
* A class that holds stuff as part of a linked list
***************************************************/
template <class T>
class list
{
private:

    struct Node {
        T data;
        Node *next;
        Node *prev;
    };

    Node *pHead;
    Node *pTail;
    int num;

public:
    list()
    {
        pHead = pTail = NULL;
        num = 0;
    }
    list(const list & rhs) throw (const char *);
   ~list() { clear(); };
   list & operator = (const list & rhs) throw (const char *);



    // the various iterator interfaces
    class iterator;
    class reverse_iterator;

    
    /**********************************************
     * node : operator << overload
     * outputs the contents of the Node
     **********************************************/
    friend ostream &operator << (ostream &out, Node &v)
    {
        out << "{ ";
        out << v.data << " ";
        out << "}";
        return out;
    }

    //linked list functions
    int  size()  const { return num; }
    bool empty() const { return (num == 0) ? true : false; }
    void clear();

    void push_back(T t) throw (const char *);
    void push_front(T t) throw (const char *);
    void pop_back();
    void pop_front();

    T & back()        throw (const char *);
    T & front()       throw (const char *);
    T & back()  const throw (const char *);
    T & front() const throw (const char *);

    //iterator functions
    iterator find(T t) const    throw (const char *);
    iterator begin() { return iterator(pHead); }
    iterator end() { return iterator(NULL); }
    iterator erase(iterator it) throw (const char *)
    {
        try
        {
            /*
            Node * temp = it.p->next;
            it.p->next = it.p->next->next;
            if (temp == pTail) pTail = it.p;
            delete temp;
            */

            Node *tempNext = it.p->next;
            it.p->prev = tempNext;
            if (tempNext == pTail)
                pTail = it.p;
            delete tempNext;
            num--;
            return it;
        }
        catch (const bad_alloc & e)
        {
            cout << "ERROR: Can not insert due to - " << e.what() << endl;
        }
        return iterator();
    }
    iterator insert(iterator it, T &t)             throw (const char *)
    {
        try
        {
            Node *newNode = new Node; //(t, (*it).next);

            //if (it == t->pTail) t->pTail = newNode;
            //(*it).next = newNode;
            return it;
        }
        catch (const bad_alloc & e)
        {
            cout << "ERROR: Can not insert due to - " << e.what() << endl;
        }
    }

    reverse_iterator rbegin() { return reverse_iterator(pTail); }
    reverse_iterator rend() { return reverse_iterator(pHead->prev); }

};

/**********************************************
 * list : iterator
 * handles the iterator for the linked list
 **********************************************/
template <class T>
class list <T> :: iterator
{
    friend class list <T>;
private:
    Node *p;
public:
    // constructors, destructors, and assignment operator
    iterator() : p(nullptr) {}
    iterator(Node *p) : p(p) {}
    iterator(const iterator & rhs) : p(rhs.p) {}


    iterator & operator = (const iterator & rhs)
    {
        this->p = rhs.p;
        return *this;
    }

    iterator & operator = (const Node * p)
    {
        this->p = p;
        return this;
    }

    // equals, not equals operator
    bool operator != (const T *p) const { return (this->p != p); }
    bool operator == (const T *p) const { return (this->p == p); }

    // equals, not equals operators for iterators
    bool operator != (const iterator & rhs) const { return p != rhs.p; }
    bool operator == (const iterator & rhs) const { return p == rhs.p; }

    // less than and greater than
    bool operator < (const T *p) const { return (this->p < p); }
    bool operator > (const T *p) const { return (this->p > p); }

    // less than or greater than
    bool operator < (const iterator & rhs) const { return p < rhs.p; }
    bool operator > (const iterator & rhs) const { return p > rhs.p; }

    // dereference operator
    T & operator * () { return p->data; }

    //Addition
    iterator & operator + (int val)
    {
        for (int i = 0; i < val > 0; i++)
            p++;
        return *this;
    }

    // prefix increment
    iterator & operator ++ ()
    {
        if (p->next) p = p->next;
        return *this;
    }

    // postfix increment
    iterator operator ++ (int postfix)
    {
        iterator tmp(*this);
        if (p->next) p = p->next;
        return tmp;
    }


    // prefix decrement
    iterator & operator -- ()
    {
        if (p->prev) p = p->prev;
        return *this;
    }

    // postfix decrement
    iterator operator -- (int postfix)
    {
        iterator tmp(*this);
        if (p->prev) p = p->prev;
        return tmp;
    }

};

/**************************************************
* LIST REVERSE_ITERATOR
* An reverse_iterator through list
*************************************************/
template <class T>
class list <T> ::reverse_iterator
{
private:
    Node *p;
public:
    // constructors, destructors, and assignment operator
    reverse_iterator() : p(NULL) {}
    reverse_iterator(Node *p) : p(p) {}
    reverse_iterator(const reverse_iterator & rhs) : p(rhs.p) {}


    reverse_iterator & operator = (const reverse_iterator & rhs)
    {
        this->p = rhs.p;
        return *this;
    }

    reverse_iterator & operator = (const T p)
    {
        *this->p = p;
        return *this;
    }

    // equals, not equals operator
    bool operator != (const T *p) const { return (this->p != p); }
    bool operator == (const T *p) const { return (this->p == p); }

    // equals, not equals operators for reverse_iterators
    bool operator != (const reverse_iterator & rhs) const { return p != rhs.p; }
    bool operator == (const reverse_iterator & rhs) const { return p == rhs.p; }

    // less than and greater than
    bool operator < (const T *p) const { return (this->p > p); }
    bool operator > (const T *p) const { return (this->p < p); }

    // less than or greater than
    bool operator < (const reverse_iterator & rhs) const { return p > rhs.p; }
    bool operator > (const reverse_iterator & rhs) const { return p < rhs.p; }

    // dereference operator
    Node & operator * () { return *p; }

    //Addition
    reverse_iterator & operator + (int val)
    {
        for (int i = 0; i < val > 0; i++)
            p--;
        return *this;
    }

    // prefix increment
    reverse_iterator & operator ++ ()
    {
        p--;
        return *this;
    }

    // postfix increment
    reverse_iterator operator ++ (int postfix)
    {
        reverse_iterator tmp(*this);
        p--;
        return tmp;
    }

    // prefix decrement
    reverse_iterator & operator -- ()
    {
        p++;
        return *this;
    }

    // postfix decrement
    reverse_iterator operator -- (int postfix)
    {
        reverse_iterator tmp(*this);
        p++;
        return tmp;
    }
};

/*******************************************
* list :: Assignment
 *******************************************/
template <class T>
list <T> & list <T> :: operator = (const list <T> & rhs) throw (const char *)
{

    num = rhs.num;
    pHead = rhs.pHead;
    pTail = rhs.pTail;
    //cout  << "does this even run" << endl;

    return *this;
}

/*******************************************
 * list :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
list <T> ::list(const list <T> & rhs) throw (const char *)
{
    this->num = rhs.num;
    this->pHead = rhs.pHead;
    this->pTail = rhs.pTail;
}

/**********************************************
 * list : clear
 * goes through every element and erases it 
 **********************************************/
template<class T>
void list<T>::clear()
{
    //for (iterator it = begin(); it != end(); it = erase(it));
}

/**********************************************
 * list : push_back
 * pushes a node onto the back of the linked list
 **********************************************/
template <class T>
void list<T>::push_back(T t) throw (const char* )
{

   try 
   {

      bool firstTime = (pHead == NULL && pTail == NULL);

      Node *p = new Node;
      p->data = t;
      p->prev = pTail;
      p->next = NULL;
      pTail = p;
      if(firstTime)
      {
          pHead = p;
      }
      num++;
   }
   catch (const char* s) 
   {
      throw "probably something";
   }
   
   return;
}

/**********************************************
 * list : push_front
 * adds a node to the front of the linked list
 **********************************************/
template<class T>
void list<T>::push_front(T t) throw(const char *)
{
    try
    {
        iterator it(pHead);
        insert(it, t);
    }
    catch (const bad_alloc & e)
    {
        cout << "ERROR: unable to allocate a new node for a list" << endl;
    }
}

/**********************************************
 * list : pop_back
 * removes from the back of the linked list
 **********************************************/
template<class T>
void list<T>::pop_back()
{
    try
    {
        iterator it(pTail);
        erase(it);
    }
    catch (const bad_alloc & e)
    {
        cout << "ERROR: Can not find due to - " << e.what() << endl;
    }
}

/**********************************************
 * list : pop_front
 * removes from the front of the list
 **********************************************/
template<class T>
void list<T>::pop_front()
{
    try
    {
        iterator it(pHead);
        erase(it);
    }
    catch (const bad_alloc & e)
    {
        cout << "ERROR: Can not find due to - " << e.what() << endl;
    }
}

/**********************************************
 * list : FRONT
 * returns the most recent value added, if no
 * values have been added, throw exception
 **********************************************/
template <class T>
T &list<T>::front() throw (const char*)
{

    if (size() > 0)
        return pHead->data;
    else
        throw "ERROR: unable to access data from an empty list";

}

/**********************************************
 * list : BACK
 * returns the most recent value added, if no
 * values have been added, throw exception
 **********************************************/
template <class T>
T &list<T>::back() throw (const char*)
{

    if (size() > 0)
        return pTail->data;
    else
        throw "ERROR: unable to access data from an empty list";

}

/**********************************************
 * list/iterator : find
 * finds the iterator for the given data
 * otherwise, if not found, it will return
 * the end()
 **********************************************/
template<class T>
typename list <T> ::iterator list <T>::find(T t) const throw(const char *)
{
    try
    {
        if (pHead->data == t)
        {
            return iterator(pHead);
        }
        else
        {
            if (pHead->next != NULL) return find(pHead->next, t);
        }

        return end();
    }
    catch (const bad_alloc & e)
    {
        cout << "ERROR: Can not find due to - " << e.what() << endl;
    }
}

}; //namespace custom

#endif // list_H