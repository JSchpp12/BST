//Jacob Schaupp 
//EECS 2510 Non Linear 
//09-28-2018
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
	Node(); 
	Node(string);
	Node(string in_key, Node* parentNode); 
	~Node();
};

