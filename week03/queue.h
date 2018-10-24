/***********************************************************************
 * Header:
 *    queue
 * Summary:
 *    This class contains an implementatin of a queue
 *
 *    This will contain the class definition of:
 *       queue             : similar to std::queue
 * Author
 *    Br. Helfrich/Aiden/Garrett
 ************************************************************************/

#ifndef queue_H
#define queue_H

#include <cassert>  // because I am paranoid
#include <iostream>
using namespace std;

//testBed cs235/assign03 assignment03.tar or a.out

// a little helper macro to write debug code
#ifdef NDEBUG
#define Debug(statement)
#else
#define Debug(statement) statement
#endif // !NDEBUG

namespace custom
{
 
template <class T>
class queue
{
public:
   // constructors and destructors
   queue();  
   queue(int cap)                   throw (const char *);
   queue(const queue & rhs)        throw (const char *);
  ~queue()                         { delete [] data;   }
   queue & operator = (const queue & rhs) throw (const char *);
   
   friend ostream &operator << (ostream &out, const queue &v)
   {  
      out << "{";
      if (v.head < v.end) {
         for (int i = v.head; i < v.end; i++)
            out << " " << v[i];
      }
      if (v.end < v.head) {
         for (int i = v.head; i < v.cap; i++)
            out << " " << v[i];
         for (int i = 0; i < v.end; i++)
            out << " " << v[i];
      }
      if (v.end == v.head && !(v.head == 0 && v.end == 0)) {
         for (int i = v.head; i < v.cap; i++)
            out << " " << v[i];
         for (int i = 0; i < v.end; i++)
            out << " " << v[i];
      }
         
      out << " }"; 
      return out;  
   }
   
   // standard container interfaces
   // queue treats size and max_size the same
   int  size()     const { return num; }
   int  max_size() const { return cap; }
   int  capacity() const { return cap; }
   bool empty()    const { return (size() > 0) ? false : true;}
   
   void push(T t) throw (const char *);
   void pop();
   T    front()   throw (const char *);
   T*   pfront()  throw (const char *);
   T    back()    throw (const char *);  
   T*   pback()   throw (const char *);
   void clear();
   void resize()  throw (const char *); 

   // a debug utility to display the queue
   // this gets compiled to nothing if NDEBUG is defined
   void display() const; 
   
private:
   T * data;              // dynamically allocated queue of T
   int num;               // number or elements
   int cap;               // max size, or the capacity allocated
   int head;              // next item index to be popped
   int end;               // index after which can be pushed
   
   // privitized random access so that only functions can access it
   T & operator [] (int index)       throw (const char *)
   {
      return data[index];
   }
   const T & operator [] (int index) const throw (const char *)
   {
      return data[index];
   }  
   
}; 

/*******************************************
 * queue :: Assignment
 *******************************************/
template <class T>
queue <T> & queue <T> :: operator = (const queue <T> & rhs)
          throw (const char *)
{
   
   if (cap != rhs.capacity() ) 
   {      
      data = NULL;
      delete [] data;
      data = new T[rhs.capacity()];
      cap = rhs.cap;
      num = rhs.num;
      head = rhs.head;
      end = rhs.end;
   }
   
   for (int i = 0; i < rhs.size(); i++)
      data[i] = rhs.data[i];
  
   return *this;
}

/*******************************************
 * queue :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
queue <T> :: queue(const queue <T> & rhs) throw (const char *)
{
   assert(rhs.cap >= 0);
      
   // do nothing if there is nothing to do
   if (rhs.cap == 0)
   {
      cap = 0;
      num = 0;
      head = 0;
      end = 0;
      data = NULL;
      return;
   }
    
   // attempt to allocate
   try
   {
      data = new T[rhs.cap];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a new buffer for queue";
   }
   
   // copy over the capacity
   num = rhs.num;
   cap = rhs.cap;
   head = rhs.head;
   end = rhs.end;
   
   

   // copy the items over one at a time using the assignment operator
   if (rhs.head < rhs.end) {
      for (int i = rhs.head; i < rhs.end; i++)
         data[i] = rhs.data[i];
   }
   if (rhs.end < rhs.head) {
      int j = 0;
      for (int i = rhs.head; i < rhs.cap; i++) {
         data[j] = rhs.data[i];
         j++;
      }
      for (int i = 0; i < rhs.end; i++) {
         data[j] = rhs.data[i];
         j++;
      }
   }
   if (rhs.end == rhs.head && !(rhs.head == 0 && rhs.end == 0)) {
      int j = 0;
      for (int i = rhs.head; i < rhs.cap; i++) {
         data[j] = rhs.data[i];
         j++;
      }
      for (int i = 0; i < rhs.end; i++) {
         data[j] = rhs.data[i];
         j++;
      }
   }
}

/**********************************************
 * queue : NON-DEFAULT CONSTRUCTOR
 * Preallocate the queue to "capacity"
 **********************************************/
template <class T>
queue <T> :: queue(int cap) throw (const char *)
{
   assert(cap >= 0);
   
   // do nothing if there is nothing to do.
   // since we can't grow an queue, this is kinda pointless
   if (cap == 0)
   {
      this->cap = 0;
      this->data = NULL;
      this->num = 0;
      this->head = 0;
      this->end = 0;
      return;
   }

   // attempt to allocate
   try
   {
      data = new T[cap];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a new buffer for queue";
   }

      
   // copy over the stuff (no items yet)
   this->num = 0;
   this->cap  = cap;
   this->head = 0;
   this->end = 0;
   
}

/**********************************************
 * queue : DEFAULT CONSTRUCTOR
 * Nothing to Preallocate, just numbers to set
 **********************************************/
template <class T>
queue <T> :: queue()
{
   this->cap = 0;
   this->data = NULL;
   this->num = 0;
   this->head = 0;
   this->end = 0;
   return;
}

/**********************************************
 * queue : PUSH
 * adds item to the top of the queue
 **********************************************/
template <class T>
void queue<T>::push(T t) throw (const char* )
{
   try 
   {
   
      resize();
      
      bool firstRun = (num == head && head == end && head == 0);
      
      if(!firstRun && end >= cap) {
         end = 0;
      }
      
      if (firstRun) {
         data[end] = t;
         num++;
         end++;        
      }
      else if (end < cap && end != head) {
         data[end] = t;
         num++;
         end++; 
      }
      //else
         //cout << head << " " << end << " " << cap << endl;
      
      
      
   }
   catch (const char* s) 
   {
      throw s;
   }
   
   return;
}

/**********************************************
 * queue : POP
 * lowers the size by 1, does not delete the
 * data because there is no other way to access
 * it once the size has been lowered. Adding 
 * something on the top overwrites it anyway
 **********************************************/
template <class T>
void queue<T>::pop() 
{
   
//   if ((head != end)) {
//      head++;
//      if (head > cap)
//         head = 0;
//      num--;
//   }
   
   
   if (size() > 0) {
      head++;
      if (head > cap)
         head = 1;
      num--;
   }
   
   if (size() == 0) {
      head = 0;
      end = 0;
   }
   
   
   return;
}

/**********************************************
 * queue : FRONT
 * returns the most recent value added, if no
 * values have been added, throw exception
 **********************************************/

template <class T>
T queue<T>::front() throw (const char*)
{

	if (size() > 0)
		return data[head];
	else
		throw "ERROR: attempting to access an element in an empty queue";

}

/**********************************************
 * queue : PFRONT
 * returns the reference of the oldest 
 * value added, if no values have been added,
 * throw exception
 **********************************************/

template <class T>
T* queue<T>::pfront() throw (const char*)
{

	if (size() > 0)
		return &data[head];
	else
		throw "ERROR: attempting to access an element in an empty queue";

}

/**********************************************
 * queue : BACK
 * returns the most recent value added, if no
 * values have been added, throw exception
 **********************************************/
template <class T>
T queue<T>::back() throw (const char* )
{

   if (size() > 0)
      return data[end]; 
   else
      throw "ERROR: attempting to access an element in an empty queue";

}

/**********************************************
 * queue : PBACK
 * returns the reference of the most recent 
 * value added, if no values have been added, 
 * throw exception
 **********************************************/
template <class T>
T* queue<T>::pback() throw (const char*)
{

	if (size() > 0)
		return &data[end];
	else
		throw "ERROR: attempting to access an element in an empty queue";

}
/**********************************************
 * queue : clear
 * erases all data from the queue, resets size
 * but does not reset capacity()
 **********************************************/
template <class T>
void queue<T>::clear() 
{
   data = NULL;
   delete [] data;
   data = new T[capacity()];
   num = 0;
   head = 0;
   end = 0;
   return;
}

/**********************************************
 * queue : resize
 * if the size() is going to exeed the capacity
 * then double the capacity and reallocate and
 * copy over the data
 **********************************************/
template <class T>
void queue<T>::resize() throw (const char* )
{    
   try 
   {
      if (size()+1 > capacity() ) 
      {

         T *temp = NULL;
         
         cap = (cap > 0) ? cap * 2 : 1;
         int oldCap = (cap > 1) ? cap / 2 : 0;
         
         temp = new T[capacity()];
         
//         int i = head;
//         while (i < end) {
//            temp[i] = data[i];
//            i++;
//         }
//         if (end < head) {
//            i = head;
//            int j = 0;
//            while (i < cap) {
//               temp[j] = data[i];
//               i++;
//               j++;
//            }
//            i = 0;
//            while (i < end) {
//               temp[j] = data[i];
//               i++;
//               j++;
//            }
//         }
         
         if (head < end) {
            for (int i = head; i < end; i++)
               temp[i] = data[i];
         }
         if (end < head) {
            int j = 0;
            for (int i = head; i < oldCap; i++) {
               temp[j] = data[i];
               j++;
            }
            for (int i = 0; i < end; i++) {
               temp[j] = data[i];
               j++;
            }
         }
         if (end == head && !(head == 0 && end == 0)) {
            int j = 0;
            for (int i = head; i < oldCap; i++) {
               temp[j] = data[i];
               j++;
            }
            for (int i = 0; i < end; i++) {
               temp[j] = data[i];
               j++;
            }
         }
         
         
         //cout << "hahxzccx" << endl;
         
         head = 0;
         end = size();
         
         delete [] this->data;
         this->data = temp;
         
         //XXXXXXXXXXXXXXXXXXXXXXXXXXXX
         
      }
      
      return;
   }
   catch (std::bad_alloc) 
   {
      throw "ERROR: Unable to allocate a new buffer for queue";
   }
}

/********************************************
 * queue : DISPLAY
 * A debug utility to display the contents of the queue
 *******************************************/
template <class T>
void queue <T> :: display() const
{
#ifndef NDEBUG
   std::cerr << "queue<T>::display()\n";
   std::cerr << "\tcap = " << cap << "\n";
   for (int i = 0; i < num; i++)
      std::cerr << "\tdata[" << i << "] = " << data[i] << "\n";

#endif // NDEBUG
}

}; // namespace custom

#endif // queue_H