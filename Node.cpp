#include "pch.h"
#include "Node.h"


Node::Node()
{
}


Node::~Node()
{
}

int Node::getX()
{
	return x;
}

int Node::getY()
{
	return y;
}

int Node::getNr()
{
	return nr;
}

void Node::setX(int m_x)
{
	x = m_x;
}

void Node::setY(int m_y)
{
	y = m_y;
}

void Node::setNr(int m_nr)
{
	nr = m_nr;
}
