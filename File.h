#pragma once
#include <iostream>
#include <fstream>
#include "Node.h"
#include <vector>
class File
{
private:
	std::fstream file;
	std::vector<Node>nodes;
	std::vector<std::vector<int> > connections;
	int edgesAmount;
	int NodesAmount;

public:
	File();
	~File();
	void loadData();
	std::vector<Node>getNodes();
	std::vector<std::vector<int> >getConnections();
	int getNodesAmount();
};

