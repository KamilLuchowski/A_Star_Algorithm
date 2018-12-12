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
	file.open("graph.dat");
	int NodesAmount, nr, x, y;
	int edgesAmount;

	if (!file.good()) {
		exit(1);
	}
	
	file >> NodesAmount;
	std::cout << "NodesAmount: " << NodesAmount<< std::endl;

	for (int i = 0; i < NodesAmount; i++) {
		Node n;
		file >> nr;
		file >> x;
		file >> y;
		n.setX(x);
		n.setY(y);
		n.setNr(nr);
		nodes.push_back(n);
		std::cout << "Nowy wierzcholek " << nr << " " << x << " " << y << std::endl;
	}

	for (int i = 0; i < NodesAmount; i++) {
		file >> edgesAmount;
		std::cout << "Liczba krawedzi z "<<i <<"-tego wierzcholka: " << edgesAmount << std::endl;
		std::vector<int> vec;
		for (int i = 0; i < edgesAmount; i++) {
			file >> nr;
			vec.push_back(nr);
			std::cout << "Konkretna krawedz: " << nr << std::endl;
		}
		connections.push_back(vec);
	}

	file.close();


	std::cout << connections[7][0] << std::endl;
}
