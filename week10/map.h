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

			
			bool operator == (const iterator & rhs) { return (it == rhs.it); }
			bool operator != (const iterator & rhs) { return (it != rhs.it); }
			pair<K, V> & operator * () 
			{ 
				return *it; 
			}

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

		// default and copy constructor
		map() : bst() {}
		map(const map<K, V> & rhs) throw (const char *)
		{
			bst = rhs.bst;
		}

		// copy the values, assignment operator
		map <K, V> & operator = (const map <K, V> & rhs)
		{
			bst = rhs.bst;
			return *this;
		}
		
		// access operators, returns values by reference
		V & operator [] (K key) throw (const char *)
		{
			pair<K, V> tempPair(key, V());
			iterator temp(find(key));
			if (temp == end())
			{
				insert(tempPair);
				temp = find(key);
			}
			return (*temp).second;
		}

		bool empty() { return bst.empty(); }
		int size() { return bst.size(); }
		void clear() { bst.clear(); }
		void insert(K key, V value) 
		{
			pair<K, V> pair(key, value); 
			bst.insert(pair);
		}
		void insert(pair<K, V> pair) { bst.insert(pair); }
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
		BST < pair <K, V> > bst;
	};
	// map class
} // namespace custom

#endif // MAP_H
