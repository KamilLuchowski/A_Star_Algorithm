#include "pch.h"
#include "Graph.h"
#include "Node.h"
#include "File.h"
#include "Algorithm.h"
#include <iostream>

int main()
{
	File f;
	f.loadData();

	Graph<Node> graph;
	graph.copyFromFile(f.getNodes(), f.getConnections(), f.getNodesAmount(), f.getEdgesAmount());

	std::vector<int> previousNode(f.getNodesAmount());
	std::vector<double> wayValue(f.getNodesAmount(), DBL_MAX);
	graph.printGraph();
	graph.nodeDistance(0, 2);
	Algorithm a;
	a.setAlgorithm(0, 9, graph, &previousNode, &wayValue);
	a.aStar();
}
