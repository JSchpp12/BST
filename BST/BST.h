#pragma once
#include <string>
#include <iostream>
#include "Node.h"
#include <list>
using namespace std; 
class BST
{
public:
	BST();
	~BST();
	list<Node> nodeList; 
	Node nodeStorage[100]; 
	int nodeStorage_index = 0; 
	void Insert(string input); 
	void List(); 

private: 
	Node* rootNode; 
	void _createRoot(string input);
	//Node _browseDown(Node currentNode); 
	bool _search(string in_key, bool call_internal); 
};


