#pragma once
#include "TreeElement.h"

class BinaryTree
{
	TreeElement* root;
	TreeElement* findElement(int n);
	TreeElement* recursiveFindElement(int n);
	TreeElement* recursiveFindElement(TreeElement* r,int n);
	void recursiveRemove(int n, TreeElement* r);
public:
	BinaryTree() :root(nullptr) {};
	BinaryTree(TreeElement* r) :root(r) {};
	

	void add(int current_n,int new_n);
	void remove(int n);
	


};

