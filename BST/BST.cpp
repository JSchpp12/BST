#include "pch.h"
#include "BST.h"


BST::BST()
{
}


BST::~BST()
{
}

//public methods 
void BST::Insert(string in_key)
{
	bool cont = false;
	bool done = false; 
	bool found; 
	Node* currentNode;

	//need to search first 
	found = _search(in_key, true, false);
	//if not found, need to make a new node 
	if (found == false) 
	{
		if (rootNode != nullptr)
		{
			currentNode = rootNode; 
			while (done == false)
			{
				if (in_key > currentNode->key)
				{
					if (currentNode->rightChild == nullptr)
					{
						//this is empty spot
						Node newNode(in_key, currentNode); 

						//store the new node
						nodeStorage[nodeStorage_index] = newNode; 
						currentNode->rightChild = &nodeStorage[nodeStorage_index]; 
						nodeStorage_index++; 
						

						done = true; 
					}
					else 
					{
						//not an empty spot need to keep looking 
						currentNode = currentNode->rightChild; 
					}
				}
				else if (in_key < currentNode->key)
				{
					if (currentNode->leftChild == nullptr)
					{
						//this is an empty spot
						Node newNode(in_key, currentNode); 
						//store new node in array 
						currentNode->leftChild = &newNode; 
						nodeStorage[nodeStorage_index] = newNode; 
						nodeStorage_index++; 

						done = true; 
					}
					else
					{
						//need to keep looking for empty spot
						currentNode = currentNode->leftChild; 
					}
				}
			}
		}
		else
		{
			this->_createRoot(in_key);
		}
	}
}

void BST::List()
{
	if (rootNode != nullptr)
	{
		_traverse(rootNode); 
	}
	else
	{
		cout << "Tree is Empty";
	}
}

void BST::Search(string in_key)
{
	_search(in_key,false, false); 
}

void BST::Delete(string in_key)
{
	bool returned; 
	returned = _search(in_key, false, true); 
}

void BST::Minimum(string in_key)
{
	_getRange(false); 
}

void BST::Maximum(string in_key)
{
	_getRange(true); 
}

void BST::Next()
{

}

void BST::Previous()
{

}

//private methods 
void BST::_createRoot(string input) 
{
	cout << "creating root node" << input; 
	this->rootNode = new Node(input); 
}

bool BST::_search(string in_key, bool call_internal, bool call_delete)
{
	cout << "Searching..."; 
	bool done = false;
	bool found = false; 
	Node* currentNode;
	if (rootNode != nullptr)
	{
		currentNode = rootNode;
		while (done == false)
		{
			if (currentNode)
			{
				if (currentNode->key == in_key)
				{
					//found node
					if (call_internal == true)
					{
						//called from insert method, so add 1 to found node 
						currentNode->counter = currentNode->counter + 1;
						done = true;
						found = true;
					}
					else if (call_delete == true)
					{
						//called from delete method, so subtract 1 from found node 
						currentNode->counter--; 
						done = true; 
						found = true; 
					}
					else 
					{
						//called from search command 
						cout << in_key << currentNode->counter;
						done = true;
						found = true;
					}
				}
				else if (in_key > currentNode->key)
				{
					if (currentNode->rightChild != nullptr)
					{
						currentNode = currentNode->rightChild;
					}
					else
					{
						//fell off tree -- not found 
						cout << in_key << " 0\n";
						done = true;
						found = false;
					}
				}
				else if (in_key < currentNode->key)
				{
					if (currentNode->rightChild != nullptr)
					{
						//set to next node in tree and rerun above code with this new node 
						currentNode = currentNode->rightChild;
					}
					else
					{
						//fell off the tree -- not found 
						cout << in_key << "0\n";
						done = true;
						found = false;
					}
				}
			}
			else 
			{
				//Hopefully never hit this 
				cout << "Unknown Error! \n"; 
			}
		}
	}
	return found;
}

void BST::_traverse(Node* in_node)
{
	if (in_node != nullptr)
	{
		cout << in_node->key << " " << in_node->counter; 

	}
}

void BST::_getRange(bool mM)
{
	//using mM to tell if this should search for the minimum or maximum 
	//false for minimum
	//true for maximum

	Node* currentNode; 
	bool complete = false; 

	if (rootNode != nullptr)
	{
		currentNode = rootNode; 
		while (complete == false)
		{
			if (mM == false)
			{
				if (currentNode->leftChild != nullptr)
				{
					currentNode = currentNode->leftChild;
				}
				else
				{
					//fell off the tree 
					//currentNode is the minimum 
					cout << "Minimum: " << currentNode->key << " " << currentNode->counter;
					complete = true;
				}
			}
			else
			{
				if (currentNode->rightChild != nullptr)
				{
					currentNode = currentNode->rightChild; 
				}
				else
				{
					//fell off the tree
					//currentNode is the minimum 
					cout << "Maximum: " << currentNode->key << " " << currentNode->counter; 
				}
			}
		}
	}
	else
	{
		//tree is empty 
		cout << "Tree is empty\n";
	}
}