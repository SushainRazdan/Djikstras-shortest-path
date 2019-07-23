//============================================================================
// Name        : ShortestPath.cpp
// Author      : Sushain Razdan
// Version     :
// Copyright   :
// Description : Finds shortest path between 2 vertices
//============================================================================

#include "ShortestPath.h"
#include <algorithm>

using namespace std;

vector <int> ShortestPath::path(Graph &graph, int u, int w)
{
    vector <int> route;
    if (dijkstra(graph, u, w) == MAX_VALUE)
	{
		return route;
	}
	int cur = w;
	do
	{
		route.push_back(cur);
		cur = parent[cur];

	} while (cur != -1);

	reverse(route.begin(), route.end());

	return route;
}

int ShortestPath::pathSize(Graph &graph, int u, int w)
{
    return dijkstra(graph, u, w);
}

int ShortestPath::dijkstra(Graph &graph, int u, int w)
{
    int graphSize = graph.Vertices();
    const vector <int> verticeList = graph.VerticeList();
    PriorityQueue pq(verticeList);

    //set priority of the first element
    pq.changePriority(QElement(u, 0));
    parent.clear();
    parent.resize(graphSize, -1);

    while (graph.Vertices() > 0) {
        QElement top = pq.top();
        pq.pop();

        if (top.distance == MAX_VALUE) {
            return MAX_VALUE;
        }
        if (top.vertex == w) {
            return top.distance;
        }
        vector <int> neighbours = graph.Neighbours(top.vertex);
        QElement Qelem;
        for (unsigned int i = 0; i < neighbours.size(); i++) {
            Qelem.vertex = neighbours[i];
            if (pq.contains(Qelem)) {
                int edgeValue = graph.GetEdgeValue(top.vertex, Qelem.vertex);
                if (edgeValue + top.distance < Qelem.distance) {
                    parent[Qelem.vertex] = top.vertex;
                    Qelem.distance = edgeValue + top.distance;
                    pq.changePriority(Qelem);
                }
            }
        }
    }
    return MAX_VALUE;
}
