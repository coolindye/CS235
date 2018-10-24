/***********************************************************************
 * Header:
 *    deque
 * Summary:
 *    This class contains an implementatin of a deque
 *
 *    This will contain the class definition of:
 *       deque             : similar to std::deque
 * Author
 *    Br. Helfrich/Aiden/Garrett
 ************************************************************************/

#ifndef deque_H
#define deque_H

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
class deque
{
public:
   // constructors and destructors
   deque();  
   deque(int cap)                   throw (const char *);
   deque(const deque & rhs)        throw (const char *);
  ~deque()                         { delete [] data;   }
   deque & operator = (const deque & rhs) throw (const char *);
   
   //custom out operator override
   friend ostream &operator << (ostream &out, const deque &v)
   {  
      out << "{";
      
      if (v.size() > 0) {
         if (v.head < v.end) {
            //cout << "one" << endl;
            for (int i = v.head; i <= v.end; i++) {
               out << " " << v[i];
            }
         }
         else if (v.head > v.end) {
            //cout << v.head << " " << v.end << endl;
            for (int i = v.head; i < v.cap; i++) {
               out << " " << v[i];
            }
            for (int i = 0; i <= v.end; i++) {
               out << " " << v[i];
            }
         }
         else if (v.head == v.end) {
            //cout << "three" << endl;
            out << " " << v[v.head];
         }
      }
         
      out << " }"; 
      return out;  
   }
   
   // standard container interfaces
   // deque treats size and max_size the same
   int  size()     const { return num; }
   int  max_size() const { return cap; }
   int  capacity() const { return cap; }
   bool empty()    const { return ((size() <= 0) ? true : false); }
   
   //deque specific functions
   void push_back(T t) throw (const char *);
   void push_front(T t) throw (const char *);
   void pop_front();
   void pop_back();
   T    front()   throw (const char *);
   T*   pfront()  throw (const char *);
   T    back()    throw (const char *);  
   T*   pback()   throw (const char *);
   void clear();
   void resize()  throw (const char *); 

   // a debug utility to display the deque
   // this gets compiled to nothing if NDEBUG is defined
   void display() const; 
   
private:
   T * data;              // dynamically allocated deque of T
   int num;               // number or elements
   int cap;               // max size, or the capacity allocated
   int head;              // next item index to be pop_frontped
   int end;               // index after which can be push_backed
   
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
 * deque :: Assignment
 *******************************************/
template <class T>
deque <T> & deque <T> :: operator = (const deque <T> & rhs)
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
 * deque :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
deque <T> :: deque(const deque <T> & rhs) throw (const char *)
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
      throw "ERROR: Unable to allocate a new buffer for deque";
   }
   
   // copy over the capacity
   num = rhs.num;
   cap = rhs.cap;
   head = rhs.head;
   end = rhs.end;
   
   

   // copy the items over one at a time using the assignment operator
   
   if (size() > 0) {
      if (head < end) {
         for (int i = head; i <= end; i++) {
            data[i] = rhs.data[i];
         }
      }
      else if (head > end) {
         int j = 0;
         for (int i = head; i < cap; i++) {
            data[j] = rhs.data[i];
            j++;
         }
         for (int i = 0; i <= end; i++) {
            data[j] = rhs.data[i];
            j++;
         }
      }
      else if (head == end) {
         data[head] = rhs.data[head];
      }
   }

}

/**********************************************
 * deque : NON-DEFAULT CONSTRUCTOR
 * Preallocate the deque to "capacity"
 **********************************************/
template <class T>
deque <T> :: deque(int cap) throw (const char *)
{
   assert(cap >= 0);
   
   // do nothing if there is nothing to do.

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
      throw "ERROR: Unable to allocate a new buffer for deque";
   }

      
   // copy over the stuff (no items yet)
   this->num = 0;
   this->cap  = cap;
   this->head = 0;
   this->end = 0;
   
}

/**********************************************
 * deque : DEFAULT CONSTRUCTOR
 * Nothing to Preallocate, just numbers to set
 **********************************************/
template <class T>
deque <T> :: deque()
{
   this->cap = 0;
   this->data = NULL;
   this->num = 0;
   this->head = 0;
   this->end = 0;
   return;
}

/**********************************************
 * deque : push_back
 * adds item to the back of the deque
 **********************************************/
template <class T>
void deque<T>::push_back(T t) throw (const char* )
{

   try 
   {
      
      resize();

      bool firstRun = (size() < 1);
      
      if(!firstRun && end >= cap - 1) {
         end = 0;
      }
      
      if (firstRun) {
         data[end] = t;
         num++;      
      }
      else if (end + 1 != head && end < cap) {
         end++;
         data[end] = t;
         num++;
         
      }      
   }
   catch (const char* s) 
   {
      throw s;
   }
   
   return;
}

/**********************************************
 * deque : push_back
 * adds item to the back of the deque
 **********************************************/
template <class T>
void deque<T>::push_front(T t) throw (const char* )
{
   try 
   {
   
      resize();
      
      bool firstRun = (size() < 1);
      
      if (!firstRun && head - 1 < 0) {
         head = cap;
      }
      
      if (firstRun) {
         data[head] = t;
         num++;      
      }
      else if (head - 1 != end) {
         head--;
         data[head] = t;
         num++;
         
      }
      
   }
   catch (const char* s) 
   {
      throw s;
   }
   
   return;
}

/**********************************************
 * deque : pop_front
 * lowers size by 1 and moves the head around
 * in such a way that it will not collide with
 * either the cap or the end, save there be no
 * elements of the deque, on which case it will
 * reset the end and start to 0
 **********************************************/
template <class T>
void deque<T>::pop_front() 
{
   if (size() > 1) {
      head++;
      if (head >= cap)
         head = 0;
      num--;
   }
   else if (size() == 1) {
      data[0] = data[head];
      head = 0;
      end = 0;
      num--;
   }
   else if (size() == 0) {
      head = 0;
      end = 0;
   }
   
   return;
}

/**********************************************
 * deque : pop_back
 * lowers size by 1 and moves the head around
 * in such a way that it will not collide with
 * either the cap or the end, save there be no
 * elements of the deque, on which case it will
 * reset the end and start to 0
 **********************************************/
template <class T>
void deque<T>::pop_back() 
{
   if (size() > 1) {
      end--;
      if (end < 0)
         end = cap - 1;
      num--;
   }
   else if (size() == 1) {
      data[0] = data[end];
      head = 0;
      end = 0;
      num--;
   }
   else if (size() == 0) {
      head = 0;
      end = 0;
   }
   
   return;
}

/**********************************************
 * deque : FRONT
 * returns the most recent value added, if no
 * values have been added, throw exception
 **********************************************/

template <class T>
T deque<T>::front() throw (const char*)
{

	if (size() > 0)
		return data[head];
	else
		throw "ERROR: unable to access data from an empty deque";

}

/**********************************************
 * deque : PFRONT
 * returns the reference of the oldest 
 * value added, if no values have been added,
 * throw exception
 **********************************************/

template <class T>
T* deque<T>::pfront() throw (const char*)
{

	if (size() > 0)
		return &data[head];
	else
      throw "ERROR: unable to access data from an empty deque";

}

/**********************************************
 * deque : BACK
 * returns the most recent value added, if no
 * values have been added, throw exception
 **********************************************/
template <class T>
T deque<T>::back() throw (const char* )
{

   if (size() > 0)
      return data[end];
   else
      throw "ERROR: unable to access data from an empty deque";

}

/**********************************************
 * deque : PBACK
 * returns the reference of the most recent 
 * value added, if no values have been added, 
 * throw exception
 **********************************************/
template <class T>
T* deque<T>::pback() throw (const char*)
{

	if (size() > 0)
		return &data[end];
	else
      throw "ERROR: unable to access data from an empty deque";

}
/**********************************************
 * deque : clear
 * erases all data from the deque, resets size
 * but does not reset capacity()
 **********************************************/
template <class T>
void deque<T>::clear() 
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
 * deque : resize
 * if the size() is going to exeed the capacity
 * then double the capacity and reallocate and
 * copy over the data
 **********************************************/
template <class T>
void deque<T>::resize() throw (const char* )
{    
   try 
   {
      if (size()+1 > capacity() ) 
      {

         T *temp = NULL;
         
         cap = (cap > 0) ? cap * 2 : 1;
         int oldCap = (cap > 1) ? cap / 2 : 0;
         
         temp = new T[capacity()];
      
         //loops through different circumstances 
         //depending on where the end it located
         //in relation to the head
         
         if (size() > 0) {
            if (head < end) {
               for (int i = head; i <= end; i++) {
                  temp[i] = data[i];
               }
            }
            else if (head > end) {
               int j = 0;
               for (int i = head; i < oldCap; i++) {
                  temp[j] = data[i];
                  j++;
               }
               for (int i = 0; i <= end; i++) {
                  temp[j] = data[i];
                  j++;
               }
            }
            else if (head == end) {
               temp[head] = data[head];
            }
         }

         head = 0;
         end = (num >= 1) ? num - 1 : 0;
         
         delete [] this->data;
         this->data = temp;
         
      }
      
      return;
   }
   catch (std::bad_alloc) 
   {
      throw "ERROR: Unable to allocate a new buffer for deque";
   }
}

/********************************************
 * deque : DISPLAY
 * A debug utility to display the contents of the deque
 *******************************************/
template <class T>
void deque <T> :: display() const
{
#ifndef NDEBUG
   std::cerr << "deque<T>::display()\n";
   std::cerr << "\tcap = " << cap << "\n";
   for (int i = 0; i < num; i++)
      std::cerr << "\tdata[" << i << "] = " << data[i] << "\n";

#endif // NDEBUG
}

}; // namespace custom

#endif // deque_H