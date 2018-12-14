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

public:
	Graph();
	~Graph();
	void copyFromFile(std::vector<Type>m_nodes, std::vector<std::vector<int> > m_connections);
};

template<class Type>
Graph<Type>::Graph() {

}

template<class Type>
inline Graph<Type>::~Graph()
{
}

template<class Type>
void Graph<Type>::copyFromFile(std::vector<Type>m_nodes, std::vector<std::vector<int> > m_connections) {
	nodes = m_nodes;
	connections = m_connections;
}