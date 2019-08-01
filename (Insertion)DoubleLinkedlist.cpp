#include <iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node* prev;
	Node* next;
};
Node* new_node(int data)
{
	Node* temp=new Node();
	temp->data=data;
	temp->next=NULL;
	temp->prev=NULL;
	return temp;
}
Node* push(Node* head,int data)
{
	Node* newNode=new_node(data);
	if(head==NULL)
	{
		head=newNode;
	}
	else
	{
		newNode->next=head;
		newNode->next->prev=newNode;
		head=newNode;
	}
	return head;
}

Node* insertEnd(Node* head,int data)
{
	Node* temp=new_node(data);
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		Node* current=head;
		while(current->next!=NULL)
		{
			current=current->next;
		}
		current->next=temp;
		temp->prev=current;
		
	}
	return head;
}
void insertAfter(Node* prevNode,int data)
{
Node* temp=new_node(data);
if(prevNode==NULL)
{
	cout<<"Node Cannot be inserted"<<endl;
}
else
{
	temp->next=prevNode->next;
	if(prevNode->next!=NULL)
	{
	prevNode->next->prev=temp;
	
	}
	prevNode->next=temp;
	temp->prev=temp;
}
}
void printList(Node* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}
Node* insertBefore(Node* head,Node* nextNode,int data)
{
	Node* temp=new_node(data);
	if(new_node==NULL)
	{
		cout<<"Node cannot be insertes before a null node";
		
	}
	else
	{
		temp->prev=nextNode->prev;
		nextNode->prev=temp;
		temp->next=nextNode;
		if(temp->prev!=NULL)
		{
			temp->prev->next=temp;
		}
		else
		{
			head=temp;
		}
	
	}
	return head;
}
int main() {
	Node* head=NULL;
	head=push(head,10);
	head=push(head,20);
	head=push(head,30);
	head=push(head,40);
	head=insertEnd(head,50);
	insertAfter(head->next->next->next->next,60);
	printList(head);
	cout<<endl;
	head=insertBefore(head,head->next->next->next,70);
	printList(head);
	return 0;
}
