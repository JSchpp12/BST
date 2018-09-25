#include "pch.h"
#include "BST.h"


BST::BST()
{
}


BST::~BST()
{
}

//public methods 
void BST::Insert(string input)
{
	bool cont = false; 
	Node* nextNode; 

	//need to search first 

	if (rootNode != nullptr)
	{
		nextNode = rootNode->leftChild; 
		//the root node exsists, need to find first open spot 
		while (cont == false)
		{
			if (nextNode = nullptr)
			{
				
			}
		}
	}
	else
	{
		this->_createRoot(input); 
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

//private methods 
void BST::_createRoot(string input) 
{
	this->rootNode = new Node(input); 
}

/*
Node BST::_browseDown(Node currentNode)
{
	//this will get child node of the input node 
	return 
}
*/

void BST::_search(string in_key)
{
	bool done = false; 
	Node* currentNode; 
	if (rootNode != nullptr)
	{
		currentNode = rootNode; 
		while (done == false)
		{
			if (currentNode->key == in_key)
			{
				//found node
				cout << in_key << currentNode->counter; 
				done = true; 
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
				}
			}
		}
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
}