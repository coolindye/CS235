/***********************************************************************
 * Component:
 *    Assignment 13, Maze
 *    Graph.h file
 * Author:
 *    Ian, Garrett, Aiden
 * Summary:
 *    All components of graph class
 ************************************************************************/

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include "set.h"
#include "vector.h"
 //#include <set>
#include "vertex.h"

namespace custom
{

	class Graph
	{
	private:
		int vTotal;
		bool *matrix;

		//Display method that prints out the grid of the adjacency matrix, used for testing
		void display() {
			for (int i = 0; i < vTotal*vTotal; i++)
			{
				if (i % vTotal == 0) cout << "\n";
				cerr << matrix[i] << " ";
			}
		}

	public:
		//Construtors and assignment operator
		Graph()                                throw (const char *);
		Graph(int num)                         throw (const char *);
		Graph(const Graph & rhs)               throw (const char *);
		Graph & operator = (const Graph & rhs) throw (const char *);

		//Number of vertices in the graph
		int size() const { return vTotal; }


		void add(const Vertex &v, const custom::set<Vertex> &s);
		void add(const Vertex &v1, const Vertex &v2);
		void clear();

		set <Vertex> findEdges(const Vertex & source);

		void findPath(Vertex & source, Vertex & destination, vector <Vertex> & path);

		bool isEdge(Vertex source, Vertex destination) const;
	};







};

#endif // GRAPH_H