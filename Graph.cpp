//============================================================================
// Name        : Djiktra.cpp
// Author      : Sushain Razdan
// Version     :
// Copyright   :
// Description : To calculate the average shortest path in a given graph using
//               Djiktra's shortest path algorithm
//============================================================================
#include "Graph.h"
#include <random>

using namespace std;

//Constructor allocates a graph based on no of vertices and edge density
//edges are randomly created based on the edge density
Graph::Graph(int vertices = 0, double edgeDensity = 0.0)
{
	this->vertices = vertices;
	this->edgeDensity = edgeDensity;

	random_device rd; // access hardware RNG
	default_random_engine e(rd()); // seed the software PRNG
	uniform_int_distribution<int> cost(1, 10); // edge
	uniform_real_distribution<double> prob(0.0, 1.0); // range

	graph = new int*[vertices];
	for (int i = 0; i < vertices; i++) {
		graph[i] = new int[vertices];
	}

	for (int i = 0; i < this->vertices; i++) {
		for (int j = 0; j < this->vertices; j++) {
			if (i == j) graph[i][j] = 0;
			else if (prob(e) < this->edgeDensity)
				graph[i][j] = graph[j][i] = cost(e);
			else
				graph[i][j] = graph[j][i] = 0;
		}
	}
	//DisplayGraph();
}

void Graph::DisplayGraph(void)
{
	for (int i = 0; i < vertices; i++) {
		for (int j = 0; j < vertices; j++) {
			cout<<graph[i][j]<<' ';
		}
		cout<<endl;
	}
}

int Graph::Vertices(void)
{
   return vertices;
}

vector <int> Graph::VerticeList(void)
{
    vector <int> verticeList;
    for (int i = 0; i < vertices; i++)
        verticeList.push_back(i);
    return verticeList;
}

int Graph::Edges(void)
{
	int edgeCounter = 0;
	for (int i = 0; i < vertices; i++) {
		for (int j = i; j < vertices; j++) {
			if (graph[i][j] != 0) edgeCounter++;
		}
	}
	return edgeCounter;
}
//Find if a connection exists between source and destination
bool Graph::Adjacent(int source, int dest)
{
	return (graph[source][dest] != 0);
}
//Find all neighbours of a vertex
vector <int> Graph::Neighbours(int vertex)
{
	vector <int> neighbours;    //vector taken since neighbours can be variable
	for (int j = 0; j < vertices; j++){
		if (graph[vertex][j] != 0) {   //find and push the neighbours
			neighbours.push_back(j);
		}
	}
	return neighbours;
}
//Add an Edge if between source and destination if it is unconnected
bool Graph::AddEdge(int source, int dest, int cost)
{
	if (graph[source][dest] != 0) return false;
	//Since graph is undirected we assign cost at 2 locations
	graph[source][dest] = graph[dest][source] = cost;
	return true;
}
//Removes an edge between source and destination
void Graph::RemoveEdge(int source, int dest)
{
	graph[source][dest] = graph[dest][source] = 0;
}
//Change the value of the edge between source and destination
void Graph::SetEdgeValue(int source, int dest, int cost)
{
	graph[source][dest] = graph[dest][source] = cost;
}
//Get the Edge value between source and destination
int Graph::GetEdgeValue(int source, int dest)
{
	return graph[source][dest];
}
//Destructor to deallocate resources
Graph::~Graph(void)
{
	for (int i = 0; i < vertices; i++)
		delete graph[i];
	delete graph;
}

/*
int main(void)
{
    Graph G{vertices, edgeDensity};

    return 0;
}*/
