//============================================================================
// Name        : PriortyQueue.cpp
// Author      : Sushain Razdan
// Version     :
// Copyright   :
// Description : Declerations for interface with PriortyQueue
//============================================================================

#ifndef __PRIORITY_QUEUE_H__
#define __PRIORITY_QUEUE_H__

#include "common.h"

struct QElement {
    int vertex;
    int distance;

    QElement(int vertex = -1, int distance = MAX_VALUE):
        vertex(vertex), distance(distance){}
};

class PriorityQueue {

private:
	std::vector <QElement> pq;
	//sort elements of the vector
	void sortQ(void);
public:
	//default constructor
	PriorityQueue(void){}
	//Initializes PriorityQueue with vertex elements of the graph
	PriorityQueue(const std::vector <int> &vertices);
	//Change Priority of the Queue Element
	void changePriority(const QElement &QElem);
	//Check element is contained within the Queue
	bool contains(QElement &QElem);
	//insert element inside the queue
	void insertElem(const QElement &QElem);
	//Get top element of the queue
	QElement top(void);
    //Remove the element from top of the queue
	void pop(void);
	//Get size of the queue
	int qSize(void);
};

#endif
