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
			
		public:

			//Constructors
			iterator() : mapit(NULL) {}
			iterator(BST <pair <K, V>>::iterator rhs) : mapit(rhs) {}
			iterator(iterator rhs) : mapit(rhs.mapit) {}

			//Assignment operator, can be assigned to a map iterator
			iterator & operator = (const iterator & rhs) 
			{ 
				mapit = rhs.mapit;
				return *this;
			}


			bool operator == (const iterator & rhs) { return (mapit == rhs.mapit); }
			bool operator != (const iterator & rhs) { return (mapit != rhs.mapit); }
			pair<K, V> & operator * () const { return *mapit; }

			// prefix increment
			iterator & operator ++ () { return ++mapit; }

			// postfix increment
			iterator operator ++ (int postfix) { return mapit++; }

			//prefix decrement
			iterator & operator -- () { return --mapit; }

			// postfix decrement
			iterator operator -- (int postfix) { return mapit--; }
		};

		// default and copy constructor
		map() : mapBST() {}
		map(const map<K, V> & rhs) throw (const char *): mapBST(rhs.mapBST) {}

		// copy the values, assignment operator
		map <K, V> & operator = (const map <K, V> & rhs)
		{
			mapBST = rhs.mapBST;
			return *this;
		}
		
		// access operators, returns values by reference
		V & operator [] (K key) throw (const char *)
		{
			pair<K, V> tempPair(key, V());
			iterator temp(mapBST.find(tempPair));
			if (temp == end())
			{
				insert(tempPair);
			}
			return tempPair.second;
		}
		const V & operator [] (K key) const throw (const char *)
		{
			pair<K, V> tempPair(key, V());
			iterator temp(mapBST.find(tempPair));
			if (temp == end())
			{
				insert(tempPair);
			}
			return tempPair.second;
		}

		bool empty() { return mapBST.empty(); }
		int size() { return mapBST.size(); }
		void clear() { mapBST.clear(); }
		void insert(K key, V value) 
		{
			pair<K, V> pair(key, value); 
			mapBST.insert(pair);
		}
		void insert(pair<K, V> pair) { mapBST.insert(pair); }
		iterator find(K key) 
		{
			iterator temp(mapBST.find(key));
			return temp;
		}
		iterator begin()
		{
			iterator temp(mapBST.begin());
			return temp;
		}
		iterator end()
		{
			iterator temp();
			return temp;
		}

	private:
		BST <pair <K, V>> mapBST;
	};// map class
} // namespace custom

#endif // MAP_H
