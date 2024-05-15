#include "Node.h"

void Node::Remove()
{
	this->isEmpty = true;
}

void Node::SetValue(int value)
{
	this->value = value;
	this->isEmpty = false;
}
