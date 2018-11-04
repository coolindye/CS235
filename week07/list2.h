/***********************************************************************
 * Header:
 *    list
 * Summary:
 *    This class contains an implementatin of a list
 *
 *    This will contain the class definition of:
 *       list             : similar to std::list
 * Author
 *    Br. Helfrich/Aiden/Garrett/Ian
 ************************************************************************/

#ifndef list_H
#define list_H

#include "node.h"

#include <cassert>  // because I am paranoid
#include <iostream>
#include <type_traits>
using namespace std;

//testBed cs235/assign04 assignment04.tar

// a little helper macro to write debug code
#ifdef NDEBUG
#define Debug(statement)
#else
#define Debug(statement) statement
#endif // !NDEBUG

namespace custom
{
 
template <class T>
class list
{
public:
   // constructors and destructors
   list();  
   list(const list & rhs)          throw (const char *);
  ~list()                         { delete [] data;   }
   list & operator = (const list & rhs) throw (const char *);
   
   //general functions
   int size() { return num; }
   bool empty() {  return (size() > 0) ? true : false; }
   void clear() { }
   void push_back(T);
   void push_front(T);
   void pop_back();
   void pop_front();
   T front() { return pHead-; }
   T back() { return pTail; }

   //iterator functions
   //find()
   //erase()
   //insert()
   //begin()
   //end()

   
private:
   Node *pHead;
   Node *pTail;
   int num;               // num elements   
}; 

/*******************************************
 * list :: Assignment
 *******************************************/
template <class T>
list <T> & list <T> :: operator = (const list <T> & rhs)
          throw (const char *)
{
  
   this->num = rhs.num;
   this->pHead = rhs->pHead;
   this->pTail = rhs->pTail;

   return *this;
}

/*******************************************
 * list :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
list <T> :: list(const list <T> & rhs) throw (const char *)
{
   this->num = rhs.num;
   this->pHead = rhs.pHead;
   this->pTail = rhs.pTail;
}


/**********************************************
 * list : DEFAULT CONSTRUCTOR
 * Nothing to Preallocate, just numbers to set
 **********************************************/
template <class T>
list <T> :: list()
{
   this.num = 0;
   this->pHead = NULL;
   this->pTail = NULL;
   return;
}

/**********************************************
 * list : push_back
 * adds item to the back of the list
 **********************************************/
template <class T>
void list<T>::push_back(T t) throw (const char* )
{

   try 
   {
      Node *p = new Node;
      p->data = t;
      p->nPrev = pTail;
      p->next = NULL;
      pTail = p;
      num++;
   }
   catch (const char* s) 
   {
      throw "probably something";
   }
   
   return;
}

/**********************************************
 * list : push_back
 * adds item to the back of the list
 **********************************************/
template <class T>
void list<T>::push_front(T t) throw (const char* )
{
   try 
   {
      Node *p = new Node;
      p->data = t;
      p->next = pHead;
      p->nPrev = NULL;
      pHead = p;
      num++;
   }
   catch (const char* s) 
   {
      throw "probably something";
   }
   
   return;
}

/**********************************************
 * list : pop_front
 * lowers size by 1 and moves the head around
 * in such a way that it will not collide with
 * either the cap or the end, save there be no
 * elements of the list, on which case it will
 * reset the end and start to 0
 **********************************************/
template <class T>
void list<T>::pop_front() 
{
   
   pHead = pHead->next;
   delete pHead->nPrev;
   pHead->nPrev = NULL;
   num--;

   return;
}

/**********************************************
 * list : pop_back
 * lowers size by 1 and moves the head around
 * in such a way that it will not collide with
 * either the cap or the end, save there be no
 * elements of the list, on which case it will
 * reset the end and start to 0
 **********************************************/
template <class T>
void list<T>::pop_back() 
{
   
   pTail = pTail->nPrev
   delete pTail->next;
   pTail->next = NULL;
   num--;


   return;
}

/**********************************************
 * list : FRONT
 * returns the most recent value added, if no
 * values have been added, throw exception
 **********************************************/

template <class T>
T list<T>::front() throw (const char*)
{

	if (size() > 0)
		return data[head];
	else
		throw "ERROR: unable to access data from an empty list";

}

/**********************************************
 * list : BACK
 * returns the most recent value added, if no
 * values have been added, throw exception
 **********************************************/
template <class T>
T list<T>::back() throw (const char* )
{

   if (size() > 0)
      return data[end];
   else
      throw "ERROR: unable to access data from an empty list";

}

/**********************************************
 * list : clear
 * erases all data from the list, resets size
 * but does not reset capacity()
 **********************************************/
template <class T>
void list<T>::clear() 
{
   data = NULL;
   delete [] data;
   data = new T[capacity()];
   num = 0;
   head = 0;
   end = 0;
   return;
}

/********************************************
 * list : DISPLAY
 * A debug utility to display the contents of the list
 *******************************************/
template <class T>
void list <T> :: display() const
{
#ifndef NDEBUG
   std::cerr << "list<T>::display()\n";
   std::cerr << "\tcap = " << cap << "\n";
   for (int i = 0; i < num; i++)
      std::cerr << "\tdata[" << i << "] = " << data[i] << "\n";

#endif // NDEBUG
}

}; // namespace custom

#endif // list_H