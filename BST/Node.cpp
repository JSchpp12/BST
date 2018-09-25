#include "pch.h"
#include "Node.h"


Node::Node(string in_key)
{
	key = in_key; 

	//should be 1 since it is new 
	counter = 1; 
}


Node::~Node()
{
}
