#include <iostream>
#include "pch.h"
#include "Graph.h"
#include "Node.h"
#include "File.h"
#include "Algorithm.h"
#include "Test.h"

int main()
{
	int start, end;

	File f;
	f.loadNodesNr(&start, &end);
	f.loadData();
	Graph<Node> graph;
	graph.setGraph(f.getNodes(), f.getConnections(), f.getNodesAmount());

	//vectors for AStar tests
	std::vector<int> A_previousNode(f.getNodesAmount());
	std::vector<double> A_wayValue(f.getNodesAmount());
	Algorithm a(start, end, graph, &A_previousNode, &A_wayValue);
	int error = a.aStar();
	if (error)
		exit(1);
	//vectors for Dijkstra tests
	std::vector<int> B_previousNode(f.getNodesAmount());
	std::vector<double> B_wayValue(f.getNodesAmount());
	Algorithm b(start, end, graph, &B_previousNode, &B_wayValue);
	error = b.Dijkstra();
	if (error)
		exit(1);

	//vectors storing results- found way from start to end node
	std::vector<int> *A_vec = a.buildTheWay(start, end);
	std::vector<int> *B_vec = b.buildTheWay(start, end);
	//saving to file
	f.saveData(a.getWayLength(), b.getWayLength(), A_vec, B_vec, &A_previousNode, &A_wayValue, &B_previousNode, &B_wayValue);

	//tests displayed on a console
	Test t;
	t.testAll();
}

