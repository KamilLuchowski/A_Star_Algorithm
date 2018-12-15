#include "pch.h"
#include "Algorithm.h"
#include <iostream>

Algorithm::Algorithm()
{
	previousNode = NULL;
	wayValue = NULL;
}

Algorithm::~Algorithm()
{
}

void Algorithm::setAlgorithm(int m_start, int m_end, Graph<Node> m_g, std::vector<int> *m_previousNode, std::vector<double> *m_wayValue)
{
	start = m_start;
	end = m_end;
	g = m_g;
	previousNode = m_previousNode;
	wayValue = m_wayValue;
	std::cout << "Start "<<start <<std::endl;
	std::cout << "End " << end << std::endl;
	std::cout << "Random wayValue " <<wayValue->at(2) << std::endl;
	std::cout << "Random wayValue " << wayValue->at(3) << std::endl;
	std::cout << "Random wayValue " << wayValue->at(4) << std::endl;


}

void Algorithm::aStar() //make a priority_queue
{
	//add the start node to queue

	previousNode->at(start) = start;
	wayValue->at(start) = 0;

	//while (if there is any nodes in queue) {
	int current = 0; //take a node from the queue and set it as current

		if (current == end) {
			//found, leave this method;
		}

		for (int next : g.getDirectConnections(current)) {
			double newVal = wayValue->at(current) + g.nodeDistance(current, next);

			if (wayValue->at(next) == DBL_MAX || newVal < wayValue->at(next)) {
				wayValue->at(next) = newVal;

				double toQueue = newVal + g.nodeDistance(next, end);
				//put next, toQueue  to priority_queue
				previousNode->at(next) = current;
			}
		}
	//}
}
