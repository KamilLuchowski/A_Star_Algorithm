#pragma once
#include <vector>
#include <map>
#include "Node.h"

template <class Type>
class Graph
{
private:
	std::vector<Type>nodes; //vector stores nodes
	std::vector<std::vector<int> > connections; //vector stores vectors of direct connections of each node
	int nodesAmount;

public:
	Graph();
	~Graph();
	void setGraph(std::vector<Type>m_nodes, std::vector<std::vector<int> > m_connections, int nodesNr); //
	std::vector<int> getDirectConnections(int node); //returns a vector to n-node direct connections
	void printGraph(); //TO DELETE??
	double nodeDistance(int a, int b); //return a distance between node nr a and node nr b
	int getNodesAmount();
};

template<class Type>
Graph<Type>::Graph() {

}

template<class Type>
inline Graph<Type>::~Graph()
{
}

template<class Type>
void Graph<Type>::setGraph(std::vector<Type>m_nodes, std::vector<std::vector<int> > m_connections, int nodesNr) {
	nodes = m_nodes;
	connections = m_connections;
	nodesAmount = nodesNr;
}

template<class Type>
inline std::vector<int> Graph<Type>::getDirectConnections(int node)
{
	return connections[node];
}

template<class Type>
inline void Graph<Type>::printGraph() //to delete??
{
	for (Type next : nodes) {
		std::cout << next.getNr() <<" - ";
		for (int next1 : getDirectConnections(next.getNr())) {
			std::cout << next1 << " ";
		}
		std::cout << std::endl;
	}

}

template<class Type>
inline double Graph<Type>::nodeDistance(int a, int b)
{
	Type A, B;
	A = nodes[a];
	B = nodes[b];
	double val = sqrt((B.getX()-A.getX())*(B.getX() - A.getX()) + (B.getY() - A.getY())*(B.getY() - A.getY()));
	return val;
}

template<class Type>
inline int Graph<Type>::getNodesAmount()
{
	return nodesAmount;
}
