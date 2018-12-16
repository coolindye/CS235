#include "graph.h"
#include "set.h"
#include "vector.h"

/**********************************************
 * graph : DEFAULT CONSTRUCTOR
 * set total amount of vertices to 0
 **********************************************/
custom::Graph::Graph() throw (const char *)
{
	this->vTotal = 0;
}

/**********************************************
 * graph : NON-DEFAULT CONSTRUCTOR
 * set total amount of vertices to given value
 * adjacency matrix needs to be vTotal squared
 * in order to know direction of the edges
 **********************************************/
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

/**********************************************
 * graph : COPY CONSTRUCTOR
 * set all private variable to rhs variables
 **********************************************/
custom::Graph::Graph(const Graph & rhs) throw(const char *)
{
	this->vTotal = rhs.vTotal;
	int count = rhs.vTotal * rhs.vTotal;
	this->matrix = new bool[count];

	//For loops to make sure that we are copying the data and not just the references to another object
	for (int i = 0; i < count; i++)
	{
		matrix[i] = rhs.matrix[i];
	}
}

/**********************************************
 * graph : ASSIGNMENT
 * set all private variable to rhs variables
 **********************************************/
custom::Graph & custom::Graph::operator=(const Graph & rhs) throw(const char *)
{
	int count = rhs.vTotal * rhs.vTotal;
	this->vTotal = rhs.vTotal;
	this->matrix = new bool[count];

	//For loops to make sure that we are copying the data and not just the references to another object
	for (int i = 0; i < count; i++)
	{
		matrix[i] = rhs.matrix[i];
	}

	return *this;
}

/**********************************************
 * graph : ADD
 * takes a source vertex and a set of others
 * and creates an edge from the source to each
 * of the destinations in the set
 **********************************************/
void custom::Graph::add(const Vertex & source, const set<Vertex>& destination)
{
	// Using a one dimensional array we need to be able to treat it like a 2-d array 
	// by using formulas like this: SourceIndex + DestinationIndex*TotalVertices
	for (int i = 0; i < destination.size(); i++)
		matrix[(source.index() + destination[i].index()*vTotal)] = true;
}

/**********************************************
 * graph : ADD
 * takes source vertex and a destination vertex
 * and creates an edge from the source to the
 * destination
 **********************************************/
void custom::Graph::add(const Vertex & source, const Vertex & destination)
{
	matrix[(source.index() + destination.index()*vTotal)] = true;
}

/**********************************************
 * graph : CLEAR
 * deletes the dynamically allocated matrix var
 **********************************************/
void custom::Graph::clear()
{
	delete matrix;
}

/**********************************************
 * graph : FIND EDGES
 * takes a vertex and finds all vertices that it
 * shares an edge with starting from the source
 * DOES NOT count vertices with an edge towards
 * it but not the other way around
 **********************************************/
custom::set <Vertex> custom::Graph::findEdges(const Vertex & source)
{
	custom::set <Vertex> s;
	for (int i = source.index(); i < (vTotal*vTotal); i += vTotal)
	{
		if (matrix[i])
		{
			//This will give us the index of the vertex that is identified by the adjacency matrix
			Vertex temp(i / vTotal);
			s.insert(temp);
		}
	}
	return s;
}

/**********************************************
 * graph : FIND PATH
 * inserts all of the vertices that form the  
 * shortest path from the source vertex to the 
 * destination vertex into the path vector. 
 * done recursively.
 **********************************************/
void custom::Graph::findPath(Vertex & source, Vertex & destination, vector <Vertex> & path)
{
	for (int i = source.index(); i < (vTotal*vTotal); i += vTotal)
	{
		if (matrix[i])
		{
			Vertex temp((i / vTotal));
			if ((temp.index() == destination.index()))
			{
				path.push_back(temp);
			}
			else
			{
				findPath(temp, destination, path);
			}
			
		}
		//if the end is found, this will stop all recursion and fall back to the beginning
		if (path.size() != 0)
		{
			path.push_back(source);
			return;
		}
	}
	return;

	//FAILED ATTEMPT #5
	/*custom::set <Vertex> options(4);
	options = findEdges(source);
	if (options.size() == 0 && source != destination) 
		return;
	else if (options.size() == 0 && source == destination) 
		path.push_back(source);
	else if (options.size() != 0 && source != destination)
	{
		for (int it = 0; it < options.size(); ++it)
		{
			Vertex s = options[it].index();
			findPath(s, destination, path);
			if (path.size() != 0)
			{
				path.push_back(source);
				return;
			}

		}

	}*/
	return;
}

/**********************************************
 * graph : IS EDGE
 * only returns true if there is an edge from the 
 * source to the destination. Direction matters.
 **********************************************/
bool custom::Graph::isEdge(Vertex source, Vertex destination) const
{
	return matrix[(source.index() + destination.index()*vTotal)];
}


