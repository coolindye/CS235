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

void custom::Graph::add(const Vertex & source, const set<Vertex>& destination)
{
	for (int i = 0; i < destination.size() ; i++)
	{
		matrix[(source.index() + destination[i].index()*vTotal)] = true;
	}
	for (int i = 0; i < vTotal*vTotal; i++)
	{
		if (i % vTotal == 0) cout << "\n";
		cerr << matrix[i] << " ";
	}
}

void custom::Graph::add(const Vertex & source, const Vertex & destination)
{
	matrix[(source.index() + destination.index()*vTotal)] = true;
	for (int i = 0; i < vTotal*vTotal; i++)
	{
		if (i % vTotal == 0) cout << "\n";
		cerr << matrix[i] << " ";
	}
}

set <Vertex> custom::Graph::findEdges(const Vertex & source)
{
	matrix[(source.index() + destination.index()*vTotal)] = true;
	for (int i = 0; i < vTotal*vTotal; i++)
	{
		if (i % vTotal == 0) cout << "\n";
		cerr << matrix[i] << " ";
	}
}



