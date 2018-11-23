/***********************************************************************
 * Component:
 *    Assignment 09, Binary Search Tree (Map)
 *    Brother Kirby, CS 235
 * Author:
 *    Garrett/Aiden/Ian
 * Summary:
 *    Create a Map
 ************************************************************************/

#ifndef MAP_H
#define MAP_H
#include "bst.h"
#include "pair.h"
using namespace std;
using namespace custom;

namespace custom
{
	template <class K, class V>
	class map
	{
	public:
		/*****************************************************
		* Class: iterator
		* Description: the iterator class for the map
		*****************************************************/
		class iterator
		{

		private:

			// We are just using the BST iterator but because BST::iterator is a nested class we need to put
			// typename so the compiler knows that this is a type and not a static member of BST
			typename BST < pair <K, V> > ::iterator it;

		public:

			//Constructors
			iterator() : it() {}
			iterator(const typename BST < pair <K, V> >::iterator & rhs)
			{
				it = rhs;
			}
			iterator(const iterator & rhs)
			{
				it = rhs.it;
			}

			//Assignment operator, can be assigned to a map iterator
			iterator & operator = (const iterator & rhs)
			{
				it = rhs.it;
				return *this;
			}

			// Uses the equality functions of the BST class
			bool operator == (const iterator & rhs) { return (it == rhs.it); }
			bool operator != (const iterator & rhs) { return (it != rhs.it); }

			// Dereference operator uses the derefernce code of the BST class
			pair<K, V> & operator * ()
			{
				return *it;
			}

			// Alll increment and decrement operators use the code from the BST class

			// prefix increment
			iterator & operator ++ ()
			{
				++it;
				return *this;
			}

			// postfix increment
			iterator operator ++ (int postfix)
			{
				iterator tmp(*this);
				it++;
				return tmp;

			}

			//prefix decrement
			iterator & operator -- ()
			{
				--it;
				return *this;
			}

			// postfix decrement
			iterator operator -- (int postfix)
			{
				iterator tmp(*this);
				it--;
				return tmp;
			}
		};

		// default and copy constructor uses BST code
		map() : bst() {}
		map(const map<K, V> & rhs) throw (const char *)
		{
			bst = rhs.bst;
		}

		// copy the values, assignment operator uses BST code
		map <K, V> & operator = (const map <K, V> & rhs)
		{
			bst = rhs.bst;
			return *this;
		}

		// access operators, returns values by reference
		V & operator [] (K key) throw (const char *)
		{
			iterator temp(find(key));

			//If the specified key is not there, then add it
			if (temp == end())
			{
				pair<K, V> tempPair(key, V());
				insert(tempPair);
				temp = find(key);
			}
			return (*temp).second;
		}

		// access operator for const values, does not allow changing values
		const V & operator [] (K key) const throw (const char *)
		{
			iterator temp(find(key));

			//If the specified key is not there, then return default value for V
			if (temp == end())
			{
				return V();
			}

			return (*temp).second;
		}

		// Use code from BST for the rest of the class, only new code is in find()
		bool empty() { return bst.empty(); }
		int size() { return bst.size(); }
		void clear() { bst.clear(); }
		void insert(K key, V value)
		{
			pair<K, V> pair(key, value);
			bst.insert(pair);
		}
		void insert(pair<K, V> pair) { bst.insert(pair); }

		// We need it to return a map::iterator so we have to set it to BST::iterator
		// that is returned from the BST find() method 
		iterator find(K key)
		{
			pair<K, V> tempPair(key, V());
			iterator it(bst.find(tempPair));
			iterator temp(it);
			return temp;
		}
		iterator begin()
		{
			return bst.begin();
		}
		iterator end()
		{
			iterator temp(nullptr);
			return temp;
		}

	private:

		// Since the map class is so similar to a Binary search tree, we just need a BST of type pair<K, V>
		BST < pair <K, V> > bst;
	};
	// map class
} // namespace custom

#endif // MAP_H
