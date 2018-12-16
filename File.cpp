#include "pch.h"
#include "File.h"


File::File()
{
}


File::~File()
{
}

void File::loadData()
{
	file.open("graph.dat"); //name of a graph file set here
	int nr, x, y;

	if (!file.good()) {
		exit(2);
	}
	
	file >> NodesAmount;

	for (int i = 0; i < NodesAmount; i++) {
		Node n;
		file >> nr;
		file >> x;
		file >> y;
		n.setX(x);
		n.setY(y);
		n.setNr(nr);
		nodes.push_back(n); //adding new node to the vector
	}

	for (int i = 0; i < NodesAmount; i++) {
		file >> edgesAmount; //the first number of a file line inform how many connections has this node
		std::vector<int> vec; //vector of direct connections
		for (int i = 0; i < edgesAmount; i++) {
			file >> nr;
			vec.push_back(nr);
		}
		connections.push_back(vec); //adding direct connections vector to the connections vector
	}

	file.close();
}

void File::saveData(double length, double length2, std::vector<int> *vec, std::vector<int> *vec2)
{
	//file.open("out.dat"); //name of a graph file set here
	file.open("out.dat", std::ios::out | std::ios::trunc);
	file.clear();

	if (!file.good()) {
		exit(2);
	}

	file << "Dijkstra algorithm results: "<<std::endl;
	for (int i = 0; i < vec->size(); i++)
		file << vec->at(i) << " ";
	file << "Length: " << length;
	file << std::endl;

	file << "AStar algorithm results: " << std::endl;
	for (int i = 0; i < vec2->size(); i++)
		file << vec2->at(i) << " ";
	file << "Length: " << length2;
	file << std::endl;


	file.close();

}

std::vector<Node> File::getNodes()
{
	return nodes;
}

std::vector<std::vector<int>> File::getConnections()
{
	return connections;
}

int File::getNodesAmount()
{
	return NodesAmount;
}

