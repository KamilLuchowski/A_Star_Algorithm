#pragma once
#include <vector>
#include "Graph.h"
class Algorithm
{
private:
	Graph<Node> g;
	std::vector<int> *previousNode;
	std::vector<double> *wayValue;
	int start;
	int end;
public:
	Algorithm();
	~Algorithm();
	void setAlgorithm(int m_start, int m_end, Graph<Node> m_g, std::vector<int> *m_previousNode, std::vector<double> *m_wayValue);
	void aStar();
	void Dijkstra();
};
