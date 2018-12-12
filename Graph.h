#pragma once
#include <vector>
#include <map>
#include "Node.h"

template <class Type>
class Graph
{
private:
	std::vector <Type> nodes;
	std::map <Type, std::vector <Type, int> > edges; 


public:
	Graph();
	~Graph();
	void getNodes(std::vector<Type>vec);
};

template<class Type>
Graph<Type>::Graph() {
	Type t;
	t.value();
}

template<class Type>
void Graph<Type>::getNodes(std::vector<Type>vec) {

}