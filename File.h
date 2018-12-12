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

public:
	File();
	~File();
	void loadData();

};

