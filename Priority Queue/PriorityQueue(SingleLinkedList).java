#include <iostream>
using namespace std;
class Node
{
	public:
	int data;
	int priority;
	Node* next;
};
Node* newNode(int d,int p)
{
	Node* temp=new Node();
	temp->data=d;
	temp->priority=p;
	temp->next=NULL;
	
	return temp;
}
Node* push(Node* head,int d,int p)
{
	Node* start=head;
	Node* temp=newNode(d,p);
	if(head->priority>p)
	{
		temp->next=head;
		head=temp;
	}
	else
	{
		while(start->next !=NULL && start->next->priority<p)
		{
			start=start->next;
		}
		temp->next=start->next;
		start->next=temp;
	}
	return head;
}
int peek(Node* head)
{
	return head->data;
}
Node* pop(Node* head)
{
	Node* temp=head;
	head=head->next;
	free(temp);
	return head;
}
bool isEmpty(Node * head)
{
	return head==NULL;
}
int main() {
	Node* head=newNode(4,1);
	head=push(head,5,2);
	head=push(head,6,3);
	head=push(head,7,0);
	
	while(!isEmpty(head))
	{
		cout<<peek(head);
		head=pop(head);
	}
	return 0;
}
