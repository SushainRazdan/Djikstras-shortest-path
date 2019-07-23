//============================================================================
// Name        : main.cpp
// Author      : Sushain Razdan
// Version     :
// Copyright   :
// Description : Generates a graph and calculates average shortest path cost using djikstra's algorithm
//============================================================================

#include "Graph.h"
#include "PriorityQueue.h"
#include "ShortestPath.h"

using namespace std;

int main(void)
{
    const int vertices = 50;
    const double edgeDensity[] = {0.20, 0.40};
    double avgPathCost;
    ShortestPath sp;

    for (unsigned int i = 0; i < 2; i++) {
        int sum = 0;
        int pCount = 0;
        Graph G(vertices, edgeDensity[i]);

        for (unsigned int j = 1; j < vertices; j++) {
            int pathsize = sp.pathSize(G, 0, j);
            if (pathsize != MAX_VALUE) {
                sum += pathsize;
                pCount++;
            }
        }
        avgPathCost = static_cast<double>(sum)/pCount;
        cout << "Graph Density:" << edgeDensity[i] <<" ";
        cout << "Average Path Length:" << avgPathCost << endl;
    }
    return 0;
}
