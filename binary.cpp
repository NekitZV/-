#include "BinaryTree.h"
TreeElement* BinaryTree::findElement(int n) 
{
	TreeElement* element = root;
	int state = 0;
	while(true)
	{
		if (element->getData() == n)
		{
			return element;
		}
		if (element->getRight() != nullptr && state < 1 ) 
		{
			element = element->getRight();
			state = 0;
		}
		else 
		{
			if (element->getLeft() != nullptr && state < 2)
			{
				element = element->getLeft();
				state = 0;
			}
			else 
			{
				if (element->getBack() == nullptr) { return nullptr; }
				if (element->getBack()->getRight() == element) 
				{
					state = 1;
				}
				else
				{
					state = 2;
				}
				element = element->getBack();

			}
		}
	}
}
TreeElement* BinaryTree::recursiveFindElement(int n)
{
	return recursiveFindElement(root, n);
}

TreeElement* BinaryTree::recursiveFindElement
(TreeElement* r, int n) {
	if (r == nullptr) return nullptr;
	if (r->getData() == n) return r;	
	else {
		TreeElement* cur = recursiveFindElement
		(r->getRight(), n);
		if (cur	!= nullptr) { return  cur;
		} else 
		return recursiveFindElement
		(r->getLeft(), n);		
	}
}

void BinaryTree::add(int current_n, int new_n){
	if (root == nullptr) {
		TreeElement* new_element = 
			new TreeElement(new_n, 
				nullptr, nullptr, nullptr);
		root->setRight(new_element);
		new_element->setBack(root);

	}
	TreeElement* current = recursiveFindElement
	(root, current_n);
	if (current == nullptr) return;
	if (recursiveFindElement
	(root, new_n) != nullptr) return;
	TreeElement* new_element = new TreeElement(new_n, nullptr, nullptr, nullptr);
	if (current->getRight() == nullptr) {
		current->setRight(new_element);
		new_element->setBack(current);
	}
	else {
		if (current->getLeft() == nullptr) {
			current->setLeft(new_element);
			new_element->setBack(current);
		}
	}
}

void BinaryTree::remove(int n){
	TreeElement* current = recursiveFindElement
	(root, n);
	if (current == nullptr) return;
	recursiveRemove(n, current);
	
	 
}

void BinaryTree::recursiveRemove(int n, TreeElement* r)
{
	if (r == nullptr) return;
	recursiveRemove(n, r->getRight());
	recursiveRemove(n, r->getLeft());
	if (r->getBack()->getRight() == r)
	{
		r->getBack()->setRight(nullptr);
	}
	else
	{
		r->getBack()->setLeft(nullptr);
	}
	
	delete r;
}