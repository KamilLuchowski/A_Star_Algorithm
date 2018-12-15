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

Algorithm::Algorithm(int m_start, int m_end, Graph<Node> m_g, std::vector<int> *m_previousNode, std::vector<double> *m_wayValue)
{
	previousNode = NULL;
	wayValue = NULL;
	start = m_start;
	end = m_end;
	g = m_g;
	previousNode = m_previousNode;
	wayValue = m_wayValue;
	wayValue->assign(g.getNodesAmount(), DBL_MAX); //making vector with nodesAmount positions, all values set as DBL_MAX

	/*
	std::cout << "Start "<<start <<std::endl;
	std::cout << "End " << end << std::endl;
	std::cout << "Random wayValue " <<wayValue->at(0) << std::endl;
	std::cout << "Random wayValue " << wayValue->at(1) << std::endl;
	std::cout << "Random wayValue " << wayValue->at(9) << std::endl;
	*/

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
