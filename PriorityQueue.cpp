//============================================================================
// Name        : PriortyQueue.cpp
// Author      : Sushain Razdan
// Version     :
// Copyright   :
// Description : Priority Queue to obtain the min Vertex, Distance pair
//===========================================================================

#include "PriorityQueue.h"
#include <algorithm>

using namespace std;

// Compares two Elements according to distances.
bool compareDistance(QElement q1, QElement q2)
{
    return (q1.distance < q2.distance);
}

PriorityQueue::PriorityQueue(const vector <int> &vertices)
{
    for (unsigned int i = 0; i < vertices.size(); i++) {
        insertElem(QElement(vertices[i]));
    }
}

void PriorityQueue::sortQ(void)
{
    sort(pq.begin(), pq.end(), compareDistance);
}

void PriorityQueue::changePriority(const QElement &QElem)
{
    for (auto iter = pq.begin(); iter != pq.end(); iter++){
        if (QElem.vertex == (*iter).vertex) {
            (*iter).distance = QElem.distance;
        }
    }
    sortQ();
}

void PriorityQueue::pop(void)
{
    pq.erase(pq.begin());
}

bool PriorityQueue::contains(QElement &QElem)
{
	for (auto iter = pq.begin(); iter != pq.end(); iter++) {
		if (QElem.vertex == (*iter).vertex) {
            QElem.distance = (*iter).distance;
            return true;
		}
	}
	return false;
}

void PriorityQueue::insertElem(const QElement &QElem)
{
	pq.push_back(QElem);
	sortQ();
}

QElement PriorityQueue::top(void)
{
	return pq.front();
}

int PriorityQueue::qSize(void)
{
	return pq.size();
}
