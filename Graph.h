#pragma once
#include <vector>
#include <map>
#include "Node.h"

template <class Type>
class Graph
{
private:
	std::vector<Type>nodes;
	std::vector<std::vector<int> > connections;
	int nodesAmount;
	int edgesAmount;

public:
	Graph();
	~Graph();
	void copyFromFile(std::vector<Type>m_nodes, std::vector<std::vector<int> > m_connections, int nodesNr, int edgesNr);
	std::vector<int> getDirectConnections(int node);
	void printGraph();
};

template<class Type>
Graph<Type>::Graph() {

}

template<class Type>
inline Graph<Type>::~Graph()
{
}

template<class Type>
void Graph<Type>::copyFromFile(std::vector<Type>m_nodes, std::vector<std::vector<int> > m_connections, int nodesNr, int edgesNr) {
	nodes = m_nodes;
	connections = m_connections;
	nodesAmount = nodesNr;
	edgesAmount = edgesNr;
}

template<class Type>
inline std::vector<int> Graph<Type>::getDirectConnections(int node)
{
	return connections[node];
}

template<class Type>
inline void Graph<Type>::printGraph()
{
	for (Type next : nodes) {
		std::cout << next.getNr() << std::endl;
	}

	for (int next: getDirectConnections(3)) {
		std::cout << next << std::endl;
	}
}
