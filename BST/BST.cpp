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
	found = _search(in_key, true);
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

						//set child pointer to the new node
						currentNode->rightChild = &newNode; 
						//store the new node
						nodeStorage[nodeStorage_index] = newNode; 
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

	}
	else
	{
		cout << "Tree is Empty";
	}
}

void BST::Search(string in_key)
{
	_search(in_key, false); 
}

//private methods 
void BST::_createRoot(string input) 
{
	cout << "creating root node" << input; 
	this->rootNode = new Node(input); 
}

bool BST::_search(string in_key, bool call_internal)
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
						cout << in_key << "0";
						done = true;
						found = false;
					}
				}
				else if (in_key < currentNode->key)
				{
					if (currentNode->rightChild != nullptr)
					{
						currentNode = currentNode->rightChild;
					}
					else
					{
						//fell off the tree -- not found 
						cout << in_key << "0";
						done = true;
						found = false;
					}
				}
			}
			else 
			{
				cout << "Hit the garbage \n"; 
			}
		}
	}
	return found;
}
	/*
	bool found = false; 
	Node* currentNode; 
	if (rootNode != nullptr)
	{
		currentNode = rootNode; 

		while (found == false)
		{
			if (currentNode->key == in_key)
			{
				cout << currentNode->key << " " << currentNode->counter; 
				found = true; 
			}
			else
			{
				if (currentNode->leftChild != nullptr)
				{
					//check the left child first 
					currentNode = currentNode->leftChild;

					if (currentNode->key == in_key)
					{
						cout << currentNode->key << " " << currentNode->counter;
						found = true;
					}
					else
					{
						//check the right child
						if (currentNode->rightChild != nullptr)
						{
							currentNode = currentNode->rightChild;
							if (currentNode->key == in_key)
							{

							}
						}
						else 
						{
							//right child is null so reached end of this branch 
							cout << in_key << " " << "0"; 
						}
					}
				}
				else
				{
					//hit bottom of tree so nothing is found
					cout << in_key << " " << "0";
					found = true;
				}
			}
		}
	}
	else
	{
		cout << "Tree is empty"; 
	}
	*/ 
//}