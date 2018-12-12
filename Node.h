#pragma once
class Node
{
private:
	int nr;
	int x;
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

