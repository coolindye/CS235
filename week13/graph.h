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

#include "set.h"

namespace custom
{

    template <class T>
    class Graph
    {
    private:
        int vertices;
        int twoD;
        bool **matrix[];
        //bool *matrix2D[][];
    public:
        Graph() {}
        Graph(int vertices) throw (const char *);
    };

    template<class T>
    Graph<T>::Graph(int vertices) throw(const char *)
    {
        this->vertices = vertices;
        /*int rowCount = vertices;
        int colCount = vertices;
        matrix = new bool*[rowCount];
        for (int i = 0; i < rowCount; ++i)
            a[i] = new bool[colCount];*/
    }


};

#endif // GRAPH_H