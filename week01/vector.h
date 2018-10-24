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
#include <iostream>
#include <cassert>
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
		// Constructors
		vector();
		vector(int num)                   throw (const char *);
		vector(const vector & rhs)        throw (const char *);

		//Destructor
		~vector() { delete[] data; }

		//Operator Overrides
		vector & operator = (const vector & rhs) throw (const char *);

		friend ostream &operator << (ostream &out, const vector &v)
		{
			out << "{ ";
			for (int i = 0; i < v.num; i++)
				out << v[i] << " ";
			out << "}";
			return out;
		}

		//Getters
		int  size()     const { return num; }
		int  max_size() const { return num; }
		int  capacity() const { return cap; }
		bool empty()    const { return (size() > 0) ? false : true; }

		void push_back(T t);
		void clear();
		void resize();

		// vector-specific interfaces
		// what would happen if I passed -1 or something greater than num?
		T & operator [] (int index)       throw (const char *)
		{
			if (index < 0 || index > this->num)
			{
				string s = "Index must be between 0 and " + this->num;
				throw s;
			}
			return data[index];
		}
		const T & operator [] (int index) const throw (const char *)
		{
			if (index < 0 || index > this->num)
			{
				string s = "Index must be between 0 and " + this->num;
				throw s;
			}
			return data[index];
		}

		// the various iterator interfaces
		class iterator;
		iterator begin() { return iterator(data); }
		iterator end();

		// the various const_iterator interfaces
		class const_iterator;
		const const_iterator cbegin() const { return const_iterator(data); }
		const const_iterator cend() const { return const_iterator(data + num); }
	private:
		T * data;              // dynamically allocated vector of T
		int num;               // number of elements
		int cap;
	};


	/**************************************************
	 * vector CONST_ITERATOR
	 * An iterator through vector
	 *************************************************/
	 /*
	 template <class T>
	 class vector <T> ::const_iterator
	 {
	 public:
		 // constructors, destructors, and assignment ocperator
		 const_iterator() : cp(NULL) {              }
		 const_iterator(T * cp) : cp(cp) {              }
		 const_iterator(const const_iterator & rhs) { *this = rhs; }


		 const const_iterator & operator = (const const_iterator & rhs)
		 {
			 this->cp = rhs.cp;
			 return *this;
		 }

		 // equals, not equals operator
		 const bool operator != (const const_iterator & rhs) const { return rhs.cp != this->cp; }
		 const bool operator == (const const_iterator & rhs) const { return rhs.cp == this->cp; }

		 // dereference operator
		 const T & operator * () const { return *cp; }

		 // prefix increment
		 const const_iterator & operator ++ ()
		 {
			 ++cp;
			 //return *this;
		 }

		 // postfix increment
		 const const_iterator operator ++ const (int postfix)
		 {
			 //const_iterator tmp(*this);
			 ++cp;
			 //return tmp;
		 }

		 // prefix increment
		 const const_iterator & operator -- ()
		 {
			 --cp;
			 //return *this;
		 }

		 // postfix increment
		 const const_iterator operator -- const (int postfix)
		 {
			 //const_iterator tmp(*this);
			 --cp;
			 //return tmp;
		 }

	 private:
		 T * cp;
	 };

	 /**************************************************
	  * vector ITERATOR
	  * An iterator through vector
	  *************************************************/
	  
	  template <class T>
	  class vector <T> ::iterator
	  {
	  public:
		  // constructors, destructors, and assignment operator
		  iterator() : p(NULL) {              }
		  iterator(T * p) : p(p) {              }
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
		  T & operator * () { return *p; }
		  const T & operator * () const { return *p; }

		  // prefix increment
		  iterator & operator ++ ()
		  {
			  ++p;
			  return *this;
		  }

		  // postfix increment
		  iterator operator ++ (int postfix)
		  {
			  iterator tmp(*this);
			  ++p;
			  return tmp;
		  }

		  // prefix decrement
		  iterator & operator -- ()
		  {
			  --p;
			  return *this;
		  }

		  // postfix decrement
		  iterator operator -- (int postfix)
		  {
			  iterator tmp(*this);
			  --p;
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
	   typename vector <T> ::iterator vector <T> ::end()
	   {
		  return iterator(data + num);
	   }

	   /*******************************************
		* vector :: Assignment
		*******************************************/
	template <class T>
	vector <T> & vector <T> :: operator = (const vector <T> & rhs)  throw (const char *)
	{

		if (size() != rhs.size()) {
			data = NULL;
			delete[] data;
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
	vector <T> ::vector(const vector <T> & rhs) throw (const char *)
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
	vector <T> ::vector(int num) throw (const char *)
	{
		assert(num >= 0);

		// do nothing if there is nothing to do.

		if (num == 0)
		{
			this->num = 0;
			this->data = NULL;

			return;
		}

		// Allocate
		try
		{
			data = new T[num];
		}
		catch (std::bad_alloc)
		{
			throw "ERROR: Unable to allocate buffer";
		}

		this->num = num;
		this->cap = num;

	}

	/**********************************************
	 * vector : DEFAULT CONSTRUCTOR
	 * Preallocate the vector to "capacity"
	 **********************************************/
	template <class T>
	vector <T> ::vector()
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
		delete[] data;
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

		if (num + 1 > capacity())
		{
			T *temp = NULL;

			if (capacity() > 0)
				cap *= 2;
			else
				cap = 1;

			temp = new T[cap];

			for (int i = 0; i < num; i++)
				temp[i] = data[i];

			delete[] this->data;
			this->data = temp;

		}

		return;
	}

}; // namespace custom

#endif // vector_H

