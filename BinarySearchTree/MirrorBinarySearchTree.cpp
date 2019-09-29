#include <iostream>
using namespace std;
class BST
{
class Node
{
	public:
	int data;
	Node* left;
	Node* right;
};
public:
Node* root;
BST()
{
	root=NULL;
}
Node* newNode(int key)
{
	Node* temp=new Node();
	temp->data=key;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
void insert(int key)
{
	root=insertrec(root,key);
}
Node* insertrec(Node* root,int key)
{
	if(root==NULL)
	{
		return newNode(key);
	}
	else
	{
		if(root->data>key)
		{
			root->left=insertrec(root->left,key);
		}
		else
		{
			root->right=insertrec(root->right,key);	
		}
	}
	return root;
	
}
void inorder()
{
	inordered(root);
}
void inordered(Node* root)
{
	
	if(root!=NULL)
	{
	inordered(root->left);
	cout<<root->data<<" ";
	inordered(root->right);
	}
}

void mirrorImage()
{
	m(root);
}
void m(Node * root)

	{
		if(root!=NULL)
		{
			m(root->left);
			m(root->right);
			Node* temp=root->right;
			root->right=root->left;
			root->left=temp;
		}
	}
};

int main() {
	BST tree;
	tree.insert(5);
	tree.insert(1);
	tree.insert(10);
	tree.insert(30);
	tree.insert(4);
	tree.insert(3);
	tree.inorder();
	tree.mirrorImage();
	tree.inorder();
	
	return 0;
}
