#include "pch.h"
#include "Test.h"


Test::Test()
{
	
}


Test::~Test()
{
}

void Test::testAll()
{
	f.loadData();
	graph.setGraph(f.getNodes(), f.getConnections(), f.getNodesAmount());

	graph.printGraph();

	std::vector<int> A_previousNode(f.getNodesAmount());
	std::vector<double> A_wayValue(f.getNodesAmount());
	int start = 0;
	int end = 9;
	Algorithm a(start, end, graph, &A_previousNode, &A_wayValue);
	a.aStar();

	std::vector<int> B_previousNode(f.getNodesAmount());
	std::vector<double> B_wayValue(f.getNodesAmount());
	Algorithm b(start, end, graph, &B_previousNode, &B_wayValue);
	b.Dijkstra();

	std::vector<int> *A_vec = a.buildTheWay(start, end);
	std::vector<int> *B_vec = b.buildTheWay(start, end);

	std::cout << "AStar results for start= 0, end=9" << std::endl;
	for (int next : *A_vec)
		std::cout << next <<" ";
	std::cout << std::endl;

	std::cout << "Dijkstra results for start= 0, end=9" << std::endl;
	for (int next : *B_vec)
		std::cout << next << " ";
	std::cout << std::endl;

}
