/***********************************************************************
 * Header:
 *    stack
 * Summary:
 *    This class contains the notion of an stack: a bucket to hold
 *    data for the user. This is just a starting-point for more advanced
 *    constainers such as the stack, set, stack, queue, deque, and map
 *    which we will build later this semester.
 *
 *    This will contain the class definition of:
 *       stack             : similar to std::stack
 *       stack :: iterator : an iterator through the stack
 * Author
 *    Br. Helfrich/Aiden
 ************************************************************************/

#ifndef stack_H
#define stack_H

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

	template <class T>
	class stack
	{
	public:
		// constructors and destructors
		stack();
		stack(int cap)                   throw (const char *);
		stack(const stack & rhs)        throw (const char *);
		~stack() { delete[] data; }
		stack & operator = (const stack & rhs) throw (const char *);

		friend ostream &operator << (ostream &out, const stack &v)
		{
			out << "{";
			for (int i = 0; i < v.num; i++)
				out << " " << v[i];
			out << " }";
			return out;
		}

		// standard container interfaces
		// stack treats size and max_size the same
		int  size()     const { return num; }
		int  max_size() const { return cap; }
		int  capacity() const { return cap; }
		bool empty()    const { return (size() > 0) ? false : true; }

		void push(T t);
		void pop();
		T    top();
		void clear();
		void resize();

		// the various iterator interfaces
		class iterator;
		iterator begin() { return iterator(data); }
		iterator end();

		// a debug utility to display the stack
		// this gets compiled to nothing if NDEBUG is defined
		void display() const;

	private:
		T * data;              // dynamically allocated stack of T
		int num;
		int cap;

		// vector-specific interfaces
		// what would happen if I passed -1 or something greater than cap?
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
	 * stack :: Assignment
	 *******************************************/
	template <class T>
	stack <T> & stack <T> :: operator = (const stack <T> & rhs)
		throw (const char *)
	{

		if (cap != rhs.capacity()) {
			data = NULL;
			delete[] data;
			data = new T[rhs.capacity()];
			cap = rhs.cap;
			num = rhs.num;
		}

		for (int i = 0; i < rhs.size(); i++)
			data[i] = rhs.data[i];

		return *this;
	}

	/*******************************************
	 * stack :: COPY CONSTRUCTOR
	 *******************************************/
	template <class T>
	stack <T> ::stack(const stack <T> & rhs) throw (const char *)
	{
		assert(rhs.cap >= 0);

		// do nothing if there is nothing to do
		if (rhs.cap == 0)
		{
			cap = 0;
			num = 0;
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
			throw "ERROR: Unable to allocate a new buffer for stack";
		}

		// copy over the capacity
		num = rhs.num;
		cap = rhs.cap;

		// copy the items over one at a time using the assignment operator
		for (int i = 0; i < rhs.size(); i++)
			data[i] = rhs.data[i];
	}

	/**********************************************
	 * stack : NON-DEFAULT CONSTRUCTOR
	 * Preallocate the stack to "capacity"
	 **********************************************/
	template <class T>
	stack <T> ::stack(int cap) throw (const char *)
	{
		assert(cap >= 0);

		// do nothing if there is nothing to do.
		// since we can't grow an stack, this is kinda pointless
		if (cap == 0)
		{
			this->cap = 0;
			this->data = NULL;
			this->num = 0;
			return;
		}

		// attempt to allocate
		try
		{
			data = new T[cap];
		}
		catch (std::bad_alloc)
		{
			throw "ERROR: Unable to allocate a new buffer for Stack";
		}


		// copy over the stuff
		this->num = 0;
		this->cap = cap;

	}

	/**********************************************
	 * stack : DEFAULT CONSTRUCTOR
	 * Preallocate the stack to "capacity"
	 **********************************************/
	template <class T>
	stack <T> ::stack()
	{
		this->cap = 0;
		this->data = NULL;
		this->num = 0;
		return;
	}

	/**********************************************
	 * stack : PUSH
	 * Preallocate the stack to "capacity"
	 **********************************************/
	template <class T>
	void stack<T>::push(T t)
	{
		try {
			resize();
		}
		catch (const char* s) {
			cout << s << endl;
		}
		data[size()] = t;
		num += 1;
		return;
	}

	/**********************************************
	 * stack : POP
	 * Preallocate the stack to "capacity"
	 **********************************************/
	template <class T>
	void stack<T>::pop()
	{
		num -= 1;
		return;
	}

	/**********************************************
	 * stack : TOP
	 * Preallocate the stack to "capacity"
	 **********************************************/
	template <class T>
	T stack<T>::top()
	{
		try {
			if (size() > 0)
				return data[size() - 1];
			else
				throw "Error: Unable to reference the element from an empty stack";
		}
		catch (const char* s) {
			//cout << s << endl;
		}
	}

	/**********************************************
	 * stack : clear
	 * Preallocate the stack to "capacity"
	 **********************************************/
	template <class T>
	void stack<T>::clear()
	{
		data = NULL;
		delete[] data;
		data = new T[capacity()];
		num = 0;
		return;
	}

	/**********************************************
	 * stack : resize
	 * Preallocate the stack to "capacity"
	 **********************************************/
	template <class T>
	void stack<T>::resize()
	{
		try {
			if (size() + 1 > capacity())
			{
				T *temp = NULL;

				cap = (capacity() > 0) ? capacity() * 2 : 1;

				temp = new T[capacity()];

				for (int i = 0; i < num; i++)
					temp[i] = data[i];

				delete[] this->data;
				this->data = temp;

			}

			return;
		}
		catch (std::bad_alloc) {
			throw "ERROR: Unable to allocate a new buffer for Stack";
		}
	}

	/********************************************
	 * stack : DISPLAY
	 * A debug utility to display the contents of the stack
	 *******************************************/
	template <class T>
	void stack <T> ::display() const
	{
#ifndef NDEBUG
		std::cerr << "stack<T>::display()\n";
		std::cerr << "\tcap = " << cap << "\n";
		for (int i = 0; i < num; i++)
			std::cerr << "\tdata[" << i << "] = " << data[i] << "\n";

#endif // NDEBUG
	}

}; // namespace custom

#endif // stack_H