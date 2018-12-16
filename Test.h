#pragma once
#include "Algorithm.h"
#include "Graph.h"
#include "File.h"
#include "Node.h"
#include <iostream>
#include <fstream>
class Test
{
private:
	File f;
	Graph<Node> graph;

public:
	Test();
	~Test();
	void testAll();
	void printGraph();
};

