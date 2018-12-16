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
	std::cout << "Enter start node nr: ";
	std::cin >> start;
	std::cout << "Enter end node nr: ";
	std::cin >> end;

	File f;
	f.loadData();
	Graph<Node> graph;
	graph.setGraph(f.getNodes(), f.getConnections(), f.getNodesAmount());

	std::vector<int> A_previousNode(f.getNodesAmount());
	std::vector<double> A_wayValue(f.getNodesAmount());
	Algorithm a(start, end, graph, &A_previousNode, &A_wayValue);
	a.aStar();

	std::vector<int> B_previousNode(f.getNodesAmount());
	std::vector<double> B_wayValue(f.getNodesAmount());
	Algorithm b(start, end, graph, &B_previousNode, &B_wayValue);
	b.Dijkstra();

	std::vector<int> *A_vec = a.buildTheWay(start, end);
	std::vector<int> *B_vec = b.buildTheWay(start, end);
	f.saveData(a.getWayLength(), b.getWayLength(), A_vec, B_vec, &A_previousNode, &A_wayValue, &B_previousNode, &B_wayValue);

	//graph.printGraph();
	Test t;
	t.testAll();
}

