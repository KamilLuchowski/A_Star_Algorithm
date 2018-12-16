#include "pch.h"
#include "Graph.h"
#include "Node.h"
#include "File.h"
#include "Algorithm.h"
#include <iostream>

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
	//graph.printGraph();

	std::vector<int> A_previousNode(f.getNodesAmount());
	std::vector<double> A_wayValue(f.getNodesAmount());
	Algorithm a(start, end, graph, &A_previousNode, &A_wayValue);
	a.aStar();

	std::vector<int> B_previousNode(f.getNodesAmount());
	std::vector<double> B_wayValue(f.getNodesAmount());
	Algorithm b(start, end, graph, &B_previousNode, &B_wayValue);
	b.Dijkstra();

	std::cout<<std::endl;
	for (int i = 0; i < 10; i++)
		std::cout <<i<<". " <<A_previousNode[i] <<"  " <<A_wayValue[i]<< std::endl;

	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << i << ". " << B_previousNode[i] << "  " << B_wayValue[i] << std::endl;

	std::vector<int> *A_vec;
	A_vec = a.buildTheWay(start, end);
	std::reverse(A_vec->begin(), A_vec->end());

	for (int i = 0; i < A_vec->size(); i++)
		std::cout << A_vec->at(i) << std::endl;

	std::vector<int> *B_vec;
	B_vec = b.buildTheWay(start, end);
	std::reverse(B_vec->begin(), B_vec->end());

	for (int i = 0; i < B_vec->size(); i++)
		std::cout << B_vec->at(i) << std::endl;



}

