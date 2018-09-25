#pragma once
#include <string>
#include <iostream>
#include "Node.h"
using namespace std; 
class BST
{
public:
	BST();
	~BST();
	void Insert(string input); 

private: 
	Node* rootNode; 
	void _createRoot(string input);

};


