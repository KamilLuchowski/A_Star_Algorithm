#pragma once
#include "Algorithm.h"
#include "Graph.h"
#include "File.h"
class Test
{
private:
	File f;
	Graph<Node> graph;

public:
	Test();
	~Test();
	void testAll();
};

