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
#include "vertex.h"

namespace custom
{

    class Graph
    {
    private:
        int vTotal;
        bool *matrix;

    public:
        Graph()                                throw (const char *);
        Graph(int num)                         throw (const char *);
        Graph(const Graph & rhs)               throw (const char *);
        Graph & operator = (const Graph & rhs) throw (const char *);

        int size() const { return vTotal; }

        void add(const Vertex &v, const custom::set<Vertex> &s);
        void add(const Vertex &v1, const Vertex &v2);
    };







};

#endif // GRAPH_H