#include "graph.h"
#include "set.h"

custom::Graph::Graph() throw (const char *)
{
    this->vTotal = 0;
}

custom::Graph::Graph(int num) throw (const char *)
{
    int count = num * num;
    this->vTotal = num;
    this->matrix = new bool[count];
	this->vertices = new Vertex[num];
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
	this->vertices = new Vertex[this->vTotal];
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
	this->vertices = new Vertex[this->vTotal];
	for (int i = 0; i < vTotal; i++)
	{
		vertices[i] = rhs.vertices[i];
	}
    for (int i = 0; i < count; i++)
    {
        matrix[i] = rhs.matrix[i];
    }

    return *this;
}

void custom::Graph::add(const Vertex & source, const set<Vertex>& destination)
{
	vertices[source.index()] = source;
	for (int i = 0; i < destination.size() ; i++)
	{
		matrix[(source.index() + destination[i].index()*vTotal)] = true;
		vertices[destination[i].index()] = destination[i];
	}
	/*for (int i = 0; i < vTotal*vTotal; i++)
	{
		if (i % vTotal == 0) cout << "\n";
		cerr << matrix[i] << " ";
	}*/
}

void custom::Graph::add(const Vertex & source, const Vertex & destination)
{
	matrix[(source.index() + destination.index()*vTotal)] = true;
	vertices[source.index()] = source;
	vertices[destination.index()] = destination;
	/*for (int i = 0; i < vTotal*vTotal; i++)
	{
		if (i % vTotal == 0) cout << "\n";
		cerr << matrix[i] << " ";
	}*/
}

void custom::Graph::clear()
{
	delete matrix;
	delete vertices;
}

custom::set <Vertex> custom::Graph::findEdges(const Vertex & source)
{
	custom::set <Vertex> s;
	for (int i = source.index(); i < (vTotal*vTotal); i += vTotal)
	{
		if (matrix[i])
		{
			s.insert(vertices[(i / vTotal)]);
		}
	}
	return s;
}

bool custom::Graph::isEdge(Vertex source, Vertex destination) const
{
	return matrix[(source.index() + destination.index()*vTotal)];
}


