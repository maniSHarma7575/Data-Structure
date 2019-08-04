#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class StackNode
{
	public:
	int data;
	StackNode* next;
};
StackNode* newNode(int data)
{
	StackNode* stackNode=new StackNode();
	stackNode->data=data;
	stackNode->next=NULL;
	return stackNode;
}

bool isEmpty(StackNode* root)
{
	return root==NULL;
}

void push(StackNode** root,int data)
{
	StackNode* stackNode=newNode(data);
	stackNode->next=*root;
	*root=stackNode;
	cout<< data<<"pushed into the stack";
}
int pop(StackNode** root)
{
	if(isEmpty(*root))
		return INT_MIN;
	StackNode* temp=*root;
	*root=(*root)->next;
	int popped=temp->data;
	free(temp);
	return popped;
}
int peek(StackNode* root)
{
	if(isEmpty(root))
	{
		return INT_MIN;
	}
	return root->data;
}
int main() {
	StackNode* root=NULL;
	push(&root,10);
	push(&root, 20);
	push(&root, 30);
	
	cout<<pop(&root)<<" Popped from the stack\n";
	cout<<"Top element is "<< peek(root) <<endl;

	return 0;
}
