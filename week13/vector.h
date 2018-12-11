/***********************************************************************
 * Header:
 *    vector
 * Summary:
 *    This class contains the notion of an vector: a bucket to hold
 *    data for the user. This is just a starting-point for more advanced
 *    constainers such as the vector, set, stack, queue, deque, and map
 *    which we will build later this semester.
 *
 *    This will contain the class definition of:
 *       vector             : similar to std::vector
 *       vector :: iterator : an iterator through the vector
 * Author
 *    Br. Helfrich
 ************************************************************************/

#ifndef vector_H
#define vector_H

#include <cassert>  // because I am paranoid
#include <iostream>
using namespace std;

// a little helper macro to write debug code
#ifdef NDEBUG
#define Debug(statement)
#else
#define Debug(statement) statement
#endif // !NDEBUG

namespace custom
{

/************************************************
 * vector
 * A class that holds stuff
 ***********************************************/
template <class T>
class vector
{
public:
   // constructors and destructors
   vector();  
   vector(int num)                   throw (const char *);
   vector(const vector & rhs)        throw (const char *);
  ~vector()                         { delete [] data;   }
   vector & operator = (const vector & rhs) throw (const char *);
   
   friend ostream &operator << (ostream &out, const vector &v)
   {  
      out << "{ ";
      for (int i = 0; i < v.num; i++)
         out << v[i] << " ";
      out << "}"; 
      return out;  
   }
   
   // standard container interfaces
   // vector treats size and max_size the same
   int  size()     const { return num; }
   int  max_size() const { return num; }
   int  capacity() const { return cap; }
   bool empty()    const { return (size() > 0) ? false : true;}
   
   void push_back(T t);
   void clear();
   void resize();
   
   // vector-specific interfaces
   // what would happen if I passed -1 or something greater than num?
   T & operator [] (int index)       throw (const char *)
   {
      return data[index];
   }
   const T & operator [] (int index) const throw (const char *)
   {
      //cout << "that one" << endl;
      return data[index];
   }
   
   // the various iterator interfaces
   class iterator;
   iterator begin()      { return iterator (data); }
   iterator end();

   // a debug utility to display the vector
   // this gets compiled to nothing if NDEBUG is defined
   void display() const; 
   
private:
   T * data;              // dynamically allocated vector of T
   int num;               // number of elements
   int cap;
}; 




/**************************************************
 * vector ITERATOR
 * An iterator through vector
 *************************************************/
template <class T>
class vector <T> :: iterator
{
public:
   // constructors, destructors, and assignment operator
   iterator()      : p(NULL)      {              }
   iterator(T * p) : p(p)         {              }
   iterator(const iterator & rhs) { *this = rhs; }
   iterator & operator = (const iterator & rhs)
   {
      this->p = rhs.p;
      return *this;
   }

   // equals, not equals operator
   bool operator != (const iterator & rhs) const { return rhs.p != this->p; }
   bool operator == (const iterator & rhs) const { return rhs.p == this->p; }

   // dereference operator
         T & operator * ()       { return *p; }
   const T & operator * () const { return *p; }

   // prefix increment
   iterator & operator ++ ()
   {
      p++;
      return *this;
   }

   // postfix increment
   iterator operator ++ (int postfix)
   {
      iterator tmp(*this);
      p++;
      return tmp;
   }
   
private:
   T * p;
};


/********************************************
 * vector :: END
 * Note that you have to use "typename" before
 * the return value type
 ********************************************/
template <class T>
typename vector <T> :: iterator vector <T> :: end ()
{
   return iterator (data + num);
}

/*******************************************
 * vector :: Assignment
 *******************************************/
template <class T>
vector <T> & vector <T> :: operator = (const vector <T> & rhs)
          throw (const char *)
{
   
   if (size() != rhs.size() ) {
      data = NULL;
      delete [] data;
      data = new T[rhs.size()];
      num = rhs.num;
   }
      
   for (int i = 0; i < num; i++)
      data[i] = rhs.data[i];
  
   return *this;
}

/*******************************************
 * vector :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
vector <T> :: vector(const vector <T> & rhs) throw (const char *)
{
   assert(rhs.num >= 0);
      
   // do nothing if there is nothing to do
   if (rhs.num == 0)
   {
      num = 0;
      data = NULL;
      return;
   }
    
   // attempt to allocate
   try
   {
      data = new T[rhs.num];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }
   
   // copy over the capacity
   num = rhs.num;
   cap = rhs.cap;

   // copy the items over one at a time using the assignment operator
   for (int i = 0; i < num; i++)
      data[i] = rhs.data[i];
}

/**********************************************
 * vector : NON-DEFAULT CONSTRUCTOR
 * Preallocate the vector to "capacity"
 **********************************************/
template <class T>
vector <T> :: vector(int num) throw (const char *)
{
   assert(num >= 0);
   
   // do nothing if there is nothing to do.
   // since we can't grow an vector, this is kinda pointless
   if (num == 0)
   {
      this->num = 0;
      this->data = NULL;
      
      return;
   }

   // attempt to allocate
   try
   {
      data = new T[num];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }

      
   // copy over the stuff
   this->num = num;
   this->cap = num;
   
}

/**********************************************
 * vector : DEFAULT CONSTRUCTOR
 * Preallocate the vector to "capacity"
 **********************************************/
template <class T>
vector <T> :: vector()
{
   this->num = 0;
   this->data = NULL;
   this->cap = 0;
   return;
}

/**********************************************
 * vector : PUSH BACK
 * Preallocate the vector to "capacity"
 **********************************************/
template <class T>
void vector<T>::push_back(T t) 
{
   resize();
   data[num] = t;
   num += 1;
   return;
}

/**********************************************
 * vector : clear
 * Preallocate the vector to "capacity"
 **********************************************/
template <class T>
void vector<T>::clear() 
{
   data = NULL;
   delete [] data;
   data = new T[size()];
   num = 0;
   return;
}

/**********************************************
 * vector : resize
 * Preallocate the vector to "capacity"
 **********************************************/
template <class T>
void vector<T>::resize() 
{    

   if (num+1 > capacity() ) 
   {
      T *temp = NULL;
      
      cap = (capacity() > 0) ? capacity() * 2 : 1;
      
      temp = new T[capacity()];
      
      for (int i = 0; i < num; i++)
         temp[i] = data[i];
      
      delete [] this->data;
      this->data = temp;
      
   }
   
   return;
}

/********************************************
 * vector : DISPLAY
 * A debug utility to display the contents of the vector
 *******************************************/
template <class T>
void vector <T> :: display() const
{
#ifndef NDEBUG
   std::cerr << "vector<T>::display()\n";
   std::cerr << "\tnum = " << num << "\n";
   for (int i = 0; i < num; i++)
      std::cerr << "\tdata[" << i << "] = " << data[i] << "\n";

#endif // NDEBUG
}

}; // namespace custom

#endif // vector_H

