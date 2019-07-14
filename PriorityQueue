//============================================================================
// Name        : PriortyQueue.cpp
// Author      : Sushain Razdan
// Version     :
// Copyright   :
// Description : Priority Queue to obtain the min Vertex, Distance pair
//============================================================================
#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <vector>
#include <algorithm>

using namespace std;

class QNode {

private:
    int vertex;
    int distance;

public:
    QNode(int vertex = -1, int distance = -1){
        this->vertex = vertex;
        this->distance = distance;
    }
    int getDistance(void) const { return distance;}
};

class QComparator
{
public:
    int operator() (const QNode& node1, const QNode& node2)
    {
        return node1.getDistance() > node2.getDistance();
    }
};

struct QElement {
    int vertex;
    int distance;
};

// Compares two intervals according to staring times.
bool compareDistance(QElement q1, QElement q2)
{
    return (q1.distance < q2.distance);
}


class PriorityQueue {

private:
    //priority_queue <QNode, vector<QNode>, QComparator> pq;
    vector <QElement> pq;
public:
    PriorityQueue(){}
    void sortQ(void)
    {
        sort(pq.begin(), pq.end(), compareDistance);
    }
    void changePriority(const QElement &QElem)
    {
        for (auto iter = pq.begin(); iter != pq.end(); iter++){
            if (QElem.vertex == (*iter).vertex) {
                (*iter).distance = QElem.distance;
            }
        }
        sortQ();
    }
    void minPrioirty()
    {
        pq.erase(pq.begin());
    }
    bool contains(const QElement &QElem)
    {
        for (auto iter = pq.begin(); iter != pq.end(); iter++) {
            if (QElem.vertex == (*iter).vertex) return true;
        }
        return false;
    }
    void insertElem(const QElement &QElem)
    {
        pq.push_back(QElem);
    }
};
