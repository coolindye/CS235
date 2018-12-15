#include "graph.h"

custom::Graph::Graph() throw (const char *)
{
    this->vTotal = 0;
}

custom::Graph::Graph(int num) throw (const char *)
{
    int count = num * num;
    this->vTotal = num;
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

void custom::Graph::add(const Vertex & v, const custom::set<Vertex>& s)
{
}

void custom::Graph::add(const Vertex & v1, const Vertex & v2)
{
}



