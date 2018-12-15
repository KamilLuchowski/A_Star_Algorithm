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
		exit(1);
	}
	
	file >> NodesAmount;
	//std::cout << "NodesAmount: " << NodesAmount<< std::endl;

	for (int i = 0; i < NodesAmount; i++) {
		Node n;
		file >> nr;
		file >> x;
		file >> y;
		n.setX(x);
		n.setY(y);
		n.setNr(nr);
		nodes.push_back(n); //adding new node to the vector
		//std::cout << "Nowy wierzcholek " << nr << " " << x << " " << y << std::endl;
	}

	for (int i = 0; i < NodesAmount; i++) {
		file >> edgesAmount; //the first number of a file line inform how many connections has this node
		//std::cout << "Liczba krawedzi z "<<i <<"-tego wierzcholka: " << edgesAmount << std::endl;
		std::vector<int> vec;
		for (int i = 0; i < edgesAmount; i++) {
			file >> nr;
			vec.push_back(nr);
			//std::cout << "Konkretna krawedz: " << nr << std::endl;
		}
		connections.push_back(vec);
	}

	file.close();


	std::cout << connections[7][0] << std::endl;
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

