#pragma once
#include <string>
using namespace std; 

class Node
{
public:
	string key;
	int counter;
	Node* parent; 
	Node* leftChild;
	Node* rightChild;
	Node(string);
	~Node();
};

