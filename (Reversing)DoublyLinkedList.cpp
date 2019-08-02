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
Node* reverse(Node* head)
{
	Node* temp=NULL;
	Node* current=head;
	while(current!=NULL)
	{
		temp=current->prev;
		current->prev=current->next;
		current->next=temp;
		current=current->prev;
	}
	if(temp!=NULL)
	{
		head=temp->prev;
	}
	return head;
}
Node* reverseRecursion(Node* head)
{
	if(head==NULL)
	{
		return NULL ;
	}
	Node* temp=head->next;
	head->next=head->prev;
	head->prev=temp;
	if(!head->prev)
		return head;
	return reverseRecursion(head->prev);
}
Node* pushNode(Node* head,Node* new_node)
{
	new_node->prev=NULL;
	new_node->next=head;
	if(head!=NULL)
	{
		head->prev=new_node;
	}
	head=new_node;
	return head;
}
Node* reverseSegment(Node* head,int k)
{
	Node* current=head;
	Node* next=NULL;
	Node* newhead=NULL;
	int count=0;
	while(current!=NULL && count<k)
	{
		next=current->next;
		newhead=pushNode(newhead,current);
		current=next;
		count++;
	}
	if(next!=NULL)
	{
		head->next=reverseSegment(next,k);
		head->next->prev=head;
	}
	return newhead;
}
Node* reverseSwapData(Node* head)
{
	Node *left=head,*right=head;
	while(right->next!=NULL)
	{
		right=right->next;
	}
	while(left!=right && left->prev!=right)
	{
		swap(left->data,right->data);
		left=left->next;
		right=right->prev;
	}
	return head;
}
int main() {
	Node* head=NULL;
	head=push(head,10);
	head=push(head,20);
	head=push(head,30);
	head=push(head,40);
	head=push(head,50);
	printList(head);
	cout<<endl;
	head=reverse(head);
	printList(head);
	head=reverseRecursion(head);
	cout<<endl;
	printList(head);
	cout<<endl;
	head=reverseSegment(head,2);
	printList(head);
	cout<<endl;
	head=reverseSwapData(head);
	printList(head);
	return 0;
}
