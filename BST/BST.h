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

	int nodeStorage_index = 0; 
	void Insert(string input); 
	void List(); 
	void Search(string in_key); 
	void Delete(string in_key);
	void Minimum(string in_key); 
	void Maximum(string in_key); 
private: 
	Node nodeStorage[100];
	Node* rootNode; 
	void _createRoot(string input);
	bool _search(string in_key, bool call_internal, bool call_delete); 
	void _traverse(Node* current_node); 
	void _getRange(string in_key, bool mM); 
};


