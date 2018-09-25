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
	void List(); 

private: 
	Node* rootNode; 
	void _createRoot(string input);
	//Node _browseDown(Node currentNode); 
	void _search(string in_key); 
};


