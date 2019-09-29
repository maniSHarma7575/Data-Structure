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
bool search(int key)
{
	return searched(root,key);
}
bool searched(Node* root,int key)
{
	if(root==NULL)
	{
		return false;
	}
	else
	{
		if(root->data<key)
		{
			return searched(root->right,key);
		}
		else if(root->data>key)
		{
			return searched(root->left,key);
		}
		else
		{
			return true;
		}
	}
}
Node* del(Node* root,int key)
{
	if(root==NULL)
	{
		return root;
	}
	if(key<root->data)
	{
		root->left=del(root->left,key);
	}
	else if(key>root->data)
	{
		root->right=del(root->right,key);
	}
	else
	{
		if(root->left==NULL)
		{
			Node* temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			Node* temp=root->left;
			free(root);
			return temp;
		}
		Node* temp=minv(root->right);
		root->data=temp->data;
		root->right=del(root->right,temp->data);
	}
	return root;
}
Node* minv(Node* node)
{
	Node* current=node;
	while(current && current->left!=NULL)
	{
		current=current->left;
	}
	return current;
}
void pop(int key)
{
	del(root,key);
}
int height()
{
	return h(root);
}
int h(Node * node)
{
	int leftheight;
	int rightheight;
	if(node==NULL)
	{
		return 0;
	}
	else
	{
		leftheight=h(node->left);
		rightheight=h(node->right);
		if(leftheight>rightheight)
		{
			return leftheight+1;
		}
		else
		{
			return rightheight+1;
		}
		
	}
}
/*Total Number of Nodes in a binary Search Tree */
int totalnodes()
{
	return tnode(root);
}
int tnode(Node* node)
{
	if(node==NULL)return 0;
	else
	{
		return tnode(node->left)+tnode(node->right)+1;
	}
}
/*Total Number of Internal Nodes*/
	int internalNodes()
{
	return inodes(root);
}
int inodes(Node* node)
{
	if(node==NULL)
	{
		return 0;
	}
	if(node->left==NULL && node->right== NULL)return 0;
	else
	{
		return inodes(node->left)+inodes(node->right)+1;
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
	if(tree.search(10))
	{
		cout<<"Element found";
	}
	if(!(tree.search(50)))
	{
		cout<<"Element Not found";
	}
	tree.pop(30);
	tree.inorder();
	cout<<endl<<" "<<tree.height();
	cout<<endl<<" "<<tree.totalnodes();
	cout<<endl<<" "<<tree.internalNodes();
	return 0;
}
