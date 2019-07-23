//============================================================================
// Name        : ShortestPath.h
// Author      : Sushain Razdan
// Version     :
// Copyright   :
// Description : Declerations for interface with ShortestPath
//============================================================================

#ifndef __SHORTEST_PATH_H__
#define __SHORTEST_PATH_H__

#include "common.h"
#include "Graph.h"
#include "PriorityQueue.h"

class ShortestPath {
public:
    // find the shortest path from u to w
	std::vector<int> path(Graph &graph, int u, int w);
	// return the path cost associated with the shortest path
	int pathSize(Graph &graph, int u, int w);
private:
    int dijkstra(Graph &graph, int u, int w);
    //parent vector to save to construct the path
    std::vector <int> parent;
};

#endif
