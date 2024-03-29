// BST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Jacob Schaupp 
//EECS 2510 Non Linear 
//09-28-2018

#include "pch.h"
#include <iostream>
#include <string>
#include "BST.h"
#include <locale>
#include <algorithm>
using namespace std; 

int main()
{
	BST tree; 
	string cmd, in_key;
	//int x; 
	bool exitIndicator = false;
	cout << "Welcome to Binary Search Tree!\n";
	 

	//Run this section until exit command
	while (exitIndicator == false) {
		//take input from user 

		cout << "Waiting for input...\n";
		locale locale; 

		cin >> cmd; 

		//convert to lower case 
		std::transform(cmd.begin(), cmd.end(), cmd.begin(), ::tolower);
		
		if ((cmd != "exit") && (cmd != "min") && (cmd != "list") && (cmd != "max") && (cmd != "help"))
		{
			cin >> in_key;
		}

		//Case statment for different commands
		if (cmd == "search")
		{
			//do search garbage 
			tree.Search(in_key); 

		}
		else if (cmd == "insert")
		{
			//do insert 
			//insert should search to see if there is node first
			//if it exsists, +1 to the int contained within 
			//then create new node if it does not exsist 
			tree.Insert(in_key); 
		}
		else if (cmd == "delete")
		{
			//do delete
			tree.Delete(in_key);  
		}
		else if (cmd == "min")
		{
			tree.Minimum(); 
		}
		else if (cmd == "max")
		{
			tree.Maximum(); 
		}
		else if (cmd == "next")
		{
			tree.Next(in_key); 
		}
		else if (cmd == "prev")
		{
			tree.Previous(in_key); 
		}
		else if (cmd == "list")
		{
			//list 
			tree.List(); 
		}

		else if (cmd == "help")
		{
			//display available commands
			cout << "List of available commands... \n";
			cout << "Insert - used to insert data into tree \n";
			cout << "Delete - used to delete an exsisting node from the tree \n";
			cout << "Search - used to search for a node and return its key \n";
			cout << "Min    - used to return the minimum value of the set \n ";
			cout << "Max    - used to return the maxamium value of the set \n";
			cout << "Next   - used to return the successor of the requested node \n";
			cout << "Prev   - used to return the predacessor of the requested node \n";
			cout << "List   - used to return all of the values contained within the tree \n";

		}
		else if (cmd == "exit")
		{
			//exit 
			exitIndicator = true;
		}
		else
		{
			cout << "Not a valid command. Please try again...\n";
		}
	}
}