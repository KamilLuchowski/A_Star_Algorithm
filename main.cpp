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
	graph.setGraph(f.getNodes(), f.getConnections(), f.getNodesAmount());
	graph.printGraph();
	graph.nodeDistance(0, 2);

	std::vector<int> A_previousNode(f.getNodesAmount());
	std::vector<double> A_wayValue(f.getNodesAmount());
	Algorithm a(0, 9, graph, &A_previousNode, &A_wayValue);
	a.aStar();

	std::vector<int> B_previousNode(f.getNodesAmount());
	std::vector<double> B_wayValue(f.getNodesAmount());
	Algorithm b(0, 9, graph, &B_previousNode, &B_wayValue);
	b.Dijkstra();
}
