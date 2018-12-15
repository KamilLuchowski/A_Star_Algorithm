#pragma once
#include <vector>
#include "Graph.h"

class aStar
{
private:
	Graph<Node> g;
	std::vector<int> previousNode;
	std::vector<double> wayValue;

public:
	aStar();
	~aStar();
};

