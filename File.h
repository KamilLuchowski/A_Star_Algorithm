#pragma once
#include <iostream>
#include <fstream>
#include "Node.h"
#include <vector>
#include <conio.h>
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
	void saveData(double length, double length2, std::vector<int> *vec, std::vector<int> *vec2);
	std::vector<Node>getNodes();
	std::vector<std::vector<int> >getConnections();
	int getNodesAmount();
};

