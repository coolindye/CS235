#include "graph.h"

custom::Graph::Graph() throw (const char *)
{
    this->vTotal = 0;
}

custom::Graph::Graph(int vertex) throw (const char *)
{
    int count = vertex * vertex;
    this->vTotal = vertex;
    this->matrix = new bool[count];
    for (int i = 0; i < count; i++)
    {
        matrix[i] = false; //setting all elements to false to start
    }
}

custom::Graph::Graph(const Graph & rhs) throw(const char *)
{
    this->vTotal = rhs.vTotal;
    int count = rhs.vTotal * rhs.vTotal;
    this->matrix = new bool[count];
    for (int i = 0; i < count; i++)
    {
        matrix[i] = rhs.matrix[i];
    }
}

custom::Graph & custom::Graph::operator=(const Graph & rhs) throw(const char *)
{
    int count = rhs.vTotal * rhs.vTotal;
    this->vTotal = rhs.vTotal;
    this->matrix = new bool[count];
    for (int i = 0; i < count; i++)
    {
        matrix[i] = rhs.matrix[i];
    }

    return *this;
}



