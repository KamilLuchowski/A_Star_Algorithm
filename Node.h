#pragma once
class Node
{
private:
	int nr; //each node has its own number
	int x; //coordinates of the point
	int y;
public:
	Node();
	~Node();
	int getX();
	int getY();
	int getNr();

	void setX(int _mx);
	void setY(int m_y);
	void setNr(int m_nr);
};

