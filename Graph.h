//============================================================================
// Name        : Graph.h
// Author      : Sushain Razdan
// Version     :
// Copyright   :
// Description : Declerations for interface with Graph
//============================================================================

#ifndef __GRAPH_H__
#define __GRAPH_H__

#include "common.h"

class Graph {
private:
	int vertices;	//no of vertices in a graph
	double edgeDensity;	//probability that an edge exists between 2 vertices
	int **graph;		//Array representing graph
	//utility function to display the graph
	void DisplayGraph(void);
public:
	//Graph Initializer
	Graph(int vertices, double edgeDensity);
	//returns no of vertices
	int Vertices(void);
	//get list of vertices in a graph
	std::vector <int> VerticeList(void);
	//returns no connected edges
	int Edges(void);
	//Checks whether an edge exists between source and destination
	bool Adjacent(int source, int dest);
	//Find all neighbours of a vertex
	std::vector <int> Neighbours(int vertex);
	//Add edge between source and destination
	bool AddEdge(int source, int dest, int cost);
	//Removes and edge between source and destination
	void RemoveEdge(int source, int dest);
	//Set the cost of edge between source and destination
	void SetEdgeValue(int source, int dest, int cost);
	//Set the cost of edge between source and destination
	int GetEdgeValue(int source, int dest);
	//destructor
	~Graph(void);
};

#endif
