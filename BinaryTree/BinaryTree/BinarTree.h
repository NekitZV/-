#include <iostream>
#include <set>

using namespace std;

class Node
{
public:
  int value;
  Node* left;
  Node* right;

  Node(int value)
  {
    this->value = value;
    left = NULL;
    right = NULL;
  }  
};

class BinaryTree
{
private:
    Node* root;
    void destroyTree(Node* p);
    set<int> multiplyValues(Node* p, int factor);

public:
    BinaryTree();
    ~BinaryTree();
    void insert(int key);
    set<int> mulValues(int factor);
};

BinaryTree::BinaryTree()
{
    root = NULL;
}

BinaryTree::~BinaryTree()
{
    destroyTree(root);
}

void BinaryTree::destroyTree(Node* p)
{
    if (p != NULL)
    {
        destroyTree(p->left);
        destroyTree(p->right);
        delete p;
    }
}

void BinaryTree::insert(int key)
{
    
    if (root == NULL)
    {
        root = new Node(key);
    }
    else
    {
        Node* curr = root;
        Node* parent;
        while (true)
        {
            parent = curr;
            if (key < curr->value)
            {
                curr = curr->left;
                if (curr == NULL)
                {
                    parent->left = new Node(key);
                    break;
                }
            }
            else
            {
                curr = curr->right;
                if (curr == NULL)
                {
                    parent->right = new Node(key);
                    break;
                }
            }
        }
    }
}

set<int> BinaryTree::multiplyValues(Node* p, int factor)
{
 set<int> res;
 if (p != NULL)
 {
  res.insert(p->value * factor);
  res.merge(multiplyValues(p->left, factor));
  res.merge(multiplyValues(p->right, factor));
 }
 return res;
}

set<int> BinaryTree::mulValues(int factor)
{
 return multiplyValues(root, factor);
}

int main()
{
 BinaryTree tree;
 tree.insert(15);
 tree.insert(10);
 tree.insert(20);
 tree.insert(25);

 set<int> res = tree.mulValues(5);

 for (int v : res) {
  cout << v << endl;
 }
    return 0;
}
