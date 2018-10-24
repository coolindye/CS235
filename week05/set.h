/***********************************************************************
 * Header:
 *    set
 * Summary:
 *    This class contains the notion of an set: a bucket to hold
 *    data for the user. 
 *
 *    This will contain the class definition of:
 *       set             : similar to std::vector
 *       set :: iterator : an iterator through the set
 * Author
 *    Br. Helfrich
 ************************************************************************/

#ifndef set_H
#define set_H

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
 * set
 * A class that holds stuff
 ***********************************************/
template <class T>
class set
{
public:
   // constructors and destructors
   set();  
   set(int num)                   throw (const char *);
   set(const set & rhs)        throw (const char *);
  ~set()                         { delete [] data;   }
   set & operator = (const set & rhs) throw (const char *);
   set & operator && (const set & rhs) throw (const char *);
   set & operator || (const set & rhs) throw (const char *);
   set & operator - (set & rhs) throw (const char *);
   
   friend ostream &operator << (ostream &out, set &v)
   {  
      out << "{ ";
      for (int i = 0; i < v.num; i++)
         out << v[i] << " ";
      out << "}"; 
      return out;  
   }
   
   // standard container interfaces
   // set treats size and max_size the same
   int  size()     const { return num; }
   int  max_size() const { return num; }
   int  capacity() const { return cap; }
   bool empty()    const { return (size() > 0) ? false : true;}

   int findIndex(T t);
   
   void insert (T t);
   void clear();
   void resize();
   
   // set-specific interfaces
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
   class const_iterator;
   iterator begin()      { return iterator (data); }
   const_iterator cbegin() const { return const_iterator(data); }
   iterator end();
   const_iterator cend() const;
   iterator erase(iterator it);
   iterator find(T s);

   // a debug utility to display the set
   // this gets compiled to nothing if NDEBUG is defined
   void display() const; 
   
private:
   T * data;              // dynamically allocated set of T
   int num;               // number of elements
   int cap;
}; 

/**************************************************
 * set CONST_ITERATOR
 * An const iterator through set
 *************************************************/
template <class T>
class set <T> :: const_iterator
{
public:
	// constructors, destructors, and assignment operator
	const_iterator() : p(NULL) {}
	const_iterator(T * p) : p(p) {}
	const_iterator(const const_iterator & rhs) : p(rhs.p) {}


	const_iterator & operator = (const const_iterator & rhs)
	{
		this->p = rhs->p;
	}

	// equals, not equals operator
	bool operator != (const T *p) const { return this->p != p; }
	bool operator == (const T *p) const { return this->p == p; }

	// equals, not equals operators for iterators
	bool operator != (const const_iterator & rhs) const { return p != rhs.p; }
	bool operator == (const const_iterator & rhs) const { return p == rhs.p; }

	// dereference operator
	const T & operator * () const { return *p; }

	// prefix increment
	const_iterator & operator ++ ()
	{
		p++;
		return *this;
	}

	// postfix increment
	const_iterator operator ++ (int postfix)
	{
		iterator tmp(*this);
		p++;
		return tmp;
	}

	// prefix decrement
	const_iterator & operator -- ()
	{
		p--;
		return *this;
	}

	// postfix decrement
	const_iterator operator -- (int postfix)
	{
		iterator tmp(*this);
		p--;
		return tmp;
	}

private:
	const T * p;
};


/********************************************
 * set :: END
 * Note that you have to use "typename" before
 * the return value type
 ********************************************/
template <class T>
typename set <T> ::const_iterator set <T> :: cend() const
{
	const_iterator it(data + num);
	return it;
}


/**************************************************
 * set ITERATOR
 * An iterator through set
 *************************************************/
template <class T>
class set <T> :: iterator
{
public:
   // constructors, destructors, and assignment operator
   iterator()                     : p(NULL)   {}
   iterator(T * p)                : p(p)      {}
   iterator(const iterator & rhs) : p(rhs.p) {}


   iterator & operator = (const iterator & rhs)
   {
      this->p = rhs.p;
	  return *this;
   }

   iterator & operator = (const T p)
   { 
	   *this->p = p; 
	   return *this;
   }

   // equals, not equals operator
   bool operator != (const T *p) const { return (this->p != p); }
   bool operator == (const T *p) const { return (this->p == p); }

   // equals, not equals operators for iterators
   bool operator != (const iterator & rhs) const { return p != rhs.p; }
   bool operator == (const iterator & rhs) const { return p == rhs.p; }

   // dereference operator
   T & operator * () { return *p; }

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
   
   // prefix decrement
   iterator & operator -- ()
   {
	   p--;
	   return *this;
   }

   // postfix decrement
   iterator operator -- (int postfix)
   {
	   iterator tmp(*this);
	   p--;
	   return tmp;
   }

private:
   T * p;
};


/********************************************
 * set :: END
 * Note that you have to use "typename" before
 * the return value type
 ********************************************/
template <class T>
typename set <T> :: iterator set <T> :: end ()
{
	iterator it(data + cap);
    return it;
}

/*******************************************
 * set :: Assignment
 *******************************************/
template <class T>
set <T> & set <T> :: operator = (const set <T> & rhs)
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
 * set :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
set <T> :: set(const set <T> & rhs) throw (const char *)
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
 * set : NON-DEFAULT CONSTRUCTOR
 * Preallocate the set to "capacity"
 **********************************************/
template <class T>
set <T> :: set(int num) throw (const char *)
{
   assert(num >= 0);
   
   // do nothing if there is nothing to do.
   // since we can't grow an set, this is kinda pointless
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
   this->num = 0;
   this->cap = num;
   
}

/**********************************************
 * set : DEFAULT CONSTRUCTOR
 * Preallocate the set to "capacity"
 **********************************************/
template <class T>
set <T> :: set()
{
   this->num = 0;
   this->data = NULL;
   this->cap = 0;
   return;
}

/**********************************************
 * set : FIND
 * Find if a value is in the set and return an
 * iterator of the position that it is
 **********************************************/
template <class T>
typename set <T> ::iterator set <T> :: find(T t)
{
	for (int i = 0; i < num; i++)
	{
		if (this->data[i] == t)
		{
			iterator it(this->data + i);
			return it;
		}
	}
	return this->end();
}

/**********************************************
 * set : FINDINDEX
 * Add a value to a set
 **********************************************/
template <class T>
int set<T>::findIndex(T t)
{
	int index = 0;
	iterator it(find(t));

	if (it == this->end())
	{
		return (cap);
	}

	for (it; it != this->end(); ++it)
	{
		index++;
	}

	return cap - index;
}

/**********************************************
 * set : INSERT
 * Add a value to a set
 **********************************************/
template <class T>
void set <T> :: insert(T t)
{
	T s = T();
	resize();
	iterator it = find(t);
	if (it == this->end())
	{
		for (int i = 0; i <= num; i++)
		{
			if (data[i] > t)
			{
				for (int j = num; j > i; j--)
					data[j] = data[j - 1];
				data[i] = t;
				num++;
				break;
			}
			else if (data[i] <= s)
			{
				data[i] = t;
				num++;
				break;
			}
			else
			{
				continue;
			}
		}
		return;
	}
	return;
}

/**********************************************
 * set : ERASE
 * Remove an element from a set
 **********************************************/
template <class T>
typename set <T> ::iterator set <T> ::erase(iterator it)
{
	for (int j = findIndex(*it); j < num-1; j++)
		data[j] = data[j + 1];
	num--;
	return it;
}

/*******************************************
 * set :: INTERSECTION
 *******************************************/
template <class T>
set <T> & set <T> :: operator && (const set <T> & rhs) throw (const char *)
{
	set <T> *temp = new set <T>;
	/*
	for (set <T> ::iterator <T> it1 = this->begin(); it1 != this->end(); ++it1)
	{
		for (set <T> ::iterator <T> it2 = rhs->begin(); it2 != rhs->end(); ++it2)
		{
			if (*it1 == *it2) temp->insert(*it1);
		}
	}
	*/

	for (int i = 0; i < this->size(); i++)
	{
		for (int j = 0; j < rhs.size(); j++)
		{
			if (this->data[i] == rhs.data[j])
				temp->insert(this->data[i]);
		}
	}

	return *temp;
}

/*******************************************
 * set :: UNION
 *******************************************/
template <class T>
set <T> & set <T> :: operator || (const set <T> & rhs) throw (const char *)
{
	set <T> *temp = new set <T>;

	/*
	for (set <T> ::iterator <T> it = rhs->begin(); it != rhs->end(); ++it)
	{
		temp->insert(*it);
	}
	*/

	for (int j = 0; j < this->size(); j++)
	{
		temp->insert(this->data[j]);
	}

	for (int i = 0; i < rhs.size(); i++)
	{
		temp->insert(rhs.data[i]);
	}

	return *temp;
}

/*******************************************
 * set :: DIFFERENCE
 *******************************************/
template <class T>
set <T> & set <T> :: operator - ( set <T> & rhs) throw (const char *)
{
	set <T> *temp = new set <T>;
	/*
	for (set <T> ::iterator <T> it1 = this->begin(); it1 != this->end(); ++it1)
	{
		for (set <T> ::iterator <T> it2 = rhs->begin(); it2 != rhs->end(); ++it2)
		{
			if (*it1 == *it2) temp->insert(*it1);
		}
	}
	*/

	for (int i = 0; i < this->size(); ++i)
	{
		if (rhs.find(data[i]) == rhs.end())
			temp->insert(data[i]);
	}

	return *temp;
}

/**********************************************
 * set : clear
 * Preallocate the set to "capacity"
 **********************************************/
template <class T>
void set<T>::clear() 
{
   data = NULL;
   delete [] data;
   data = new T[size()];
   num = 0;
   return;
}

/**********************************************
 * set : resize
 * Preallocate the set to "capacity"
 **********************************************/
template <class T>
void set<T>::resize() 
{    

   if (num+1 > capacity() ) 
   {
	   T s = T();

      cap = (capacity() > 0) ? capacity() * 2 : 1;

	  T *temp = new T[capacity()];

	  for (int i = 0; i < capacity(); i++)
		  temp[i] = s;

      for (int i = 0; i < num; i++)
         temp[i] = data[i];
      
      delete [] this->data;
      this->data = temp;
      
   }
   
   return;
}

/********************************************
 * set : DISPLAY
 * A debug utility to display the contents of the set
 *******************************************/
template <class T>
void set <T> :: display() const
{
#ifndef NDEBUG
   std::cerr << "set<T>::display()\n";
   std::cerr << "\tnum = " << num << "\n";
   for (int i = 0; i < num; i++)
      std::cerr << "\tdata[" << i << "] = " << data[i] << "\n";

#endif // NDEBUG
}

}; // namespace custom

#endif // set_H

