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
        Node()            : data(T()), pNext(NULL), pPrev(NULL) {}
        Node(const T & t) : data(t)  , pNext(NULL), pPrev(NULL) {}
    };

    /****************************************************
    * List
    * A class that holds stuff as part of a linked list
    ***************************************************/
    template <class T>
    class List
    {
    private:
        Node *pHead;
        Node *pTail;
        int numElements;
    public:
        List() : pHead(NULL), pTail(NULL), numElements(0) {}
        List(const List & rhs) throw (const char *);
        ~List();

        List & operator = (const List & rhs);

        int size() const   { return numElements; }
        bool empty() const { return (numElements == 0) ? true : false; }
        void clear();

        void push_back (const T & t) throw (const char *);
        void push_front(const T & t) throw (const char *);
        void pop_back ();
        void pop_front();

        T & back ()       throw (const char *);
        T & front()       throw (const char *);
        T & back () const throw (const char *);
        T & front() const throw (const char *);

    };





    template<class T>
    List<T>::List(const List & rhs) throw(const char *)
    {
    }

    template<class T>
    List<T>::~List()
    {
    }

    template<class T>
    List<T> & List<T>::operator=(const List & rhs)
    {
        // TODO: insert return statement here
    }

    template<class T>
    void List<T>::clear()
    {
    }

    template<class T>
    void List<T>::push_back(const T & t) throw(const char *)
    {
    }

    template<class T>
    void List<T>::push_front(const T & t) throw(const char *)
    {
    }

    template<class T>
    void List<T>::pop_back()
    {
    }

    template<class T>
    void List<T>::pop_front()
    {
    }

    template<class T>
    T & List<T>::back() throw(const char *)
    {
        // TODO: insert return statement here
    }

    template<class T>
    T & List<T>::front() throw(const char *)
    {
        // TODO: insert return statement here
    }

    template<class T>
    T & List<T>::back() const throw(const char *)
    {
        // TODO: insert return statement here
    }

    template<class T>
    T & List<T>::front() const throw(const char *)
    {
        // TODO: insert return statement here
    }

};

#endif // LIST_H