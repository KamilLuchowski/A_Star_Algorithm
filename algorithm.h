#pragma once
#include <vector>
#include "Graph.h"
class Algorithm
{
private:
	Graph<Node> g;
	std::vector<int> *previousNode; //pointer to vector storing the way from start to end
	std::vector<double> *wayValue; //pointer to vector storing the shortest length from start to a node
	int start; //start node nr
	int end; //end node nr
	typedef std::pair<double, int> QueueValue; //two values, double is the value of the way, int is a number of a node
	std::vector<int> inOrderWay;
public:
	Algorithm();
	~Algorithm();
	Algorithm(int m_start, int m_end, Graph<Node> m_g, std::vector<int> *m_previousNode, std::vector<double> *m_wayValue);
	void aStar();
	void Dijkstra();
	std::vector<int>* buildTheWay(int start, int end); //making a vector with the numbers of node, it is a way from start to end
	double getWayLength(); //returns the value of length from start to end
};
