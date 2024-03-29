#include <iostream>
using namespace std;
class Node
{
	public:
	int data;
	Node * next;
	Node(int d)
	{
		data=d;
		next=NULL;
	}
};
Node* push(Node* head,int data)
{
	Node* new_data=new Node(data);
	Node* temp=head;
	new_data->next=NULL;
	if(head==NULL)
	{
		new_data->next=new_data;
	}
	else
	{
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=new_data;
		new_data->next=head;
		
	}
	head=new_data;
	return head;
}
Node* insertend(Node* head,int data)
{
	Node* new_node=new Node(data);
	if(head==NULL)
	{
		new_node->next=new_node;
		head=new_node;
	}
	else
	{
		Node* temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=new_node;
		new_node->next=head;
	}
	
	return head;
}
void printList(Node * head)
{
	if(head==NULL)
	{
	return ;
	}
	Node * temp=head;
	while(temp->next!=head)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<temp->data;
}
Node* delete_beg(Node * head)
{
	Node* t=head;
	if(head==NULL)
	{
		return NULL;
	}
	else
	{
		Node* temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
			
		}
		temp->next=head->next;
		free(head);
		head=temp->next;
		return head;
	}
}
Node* delete_end(Node* head)
{
	Node* pre=NULL;
	Node* temp=head;
	while(temp->next!=head)
	{
		pre=temp;
		temp=temp->next;
	}
	pre->next=temp->next;
	temp->next=NULL;
	free(temp);
	return head;
}
Node* delete_after(Node* head)
{
	Node* ptr,*preptr;
	int val;
	cout<<"Enter the value after which the node is to be deleted:"<<endl;
	cin>>val;
	ptr=head;
	preptr=NULL;
	while(ptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr=ptr;
	ptr=ptr->next;
	preptr->next=ptr->next;
	ptr->next=NULL;
	free(ptr);
	return head;
}
void printMiddle(Node* head,Node* hearef1,Node* headref2)
{
	if(head!=NULL)
	{
		Node* fast=head;
		Node* slow=head;
		while(fast->next!=head && fast->next->next!=head)
		{
			fast=fast->next->next;
			slow=slow->next;
		}
		if(fast->next->next==head)
		{
			fast=fast->next;
		}
		headref1=head;
		headref2=slow->next;
		fast->next==slow->next;
		slow->next=head;
	}
	
	printList(headref1);
	cout<<endl;
	printList(headref2);
}

//Inserting element in Sorted Manner
Node* sortedInsert(Node* head,Node* new_node)
{
	Node* current=head;
	if(current==NULL)
	{
		new_node->next=new_node;
		head=new_node;
	}
	else if(head->data>new_node->data)
	{
		Node* temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
			
		}
		temp->next=new_node;
		new_node->next=head;
		head=new_node;
	}
	else
	{
		Node* pre=NULL;
		while(current->next!=head && current->data<=new_node->data )
		{
			pre=current;
			current=current->next;
		}
		if(current->next==head && current->data<new_node->data)
		{
		current->next=new_node;
		new_node->next=head;
		}
		else
		{
		new_node->next=pre->next;
		pre->next=new_node;
		}
	}
	return head;
}


int main() {
	Node* head=NULL;
	Node* head1=NULL;
	head=push(head,10);
	head=push(head,20);
	head=push(head,30);
	head=push(head,40);
	head=push(head,50);
	head=insertend(head,60);
	head=insertend(head,70);
	head=insertend(head,80);
	head1=insertend(head1,1);
	head1=insertend(head1,2);
	head1=insertend(head1,3);
	head=delete_beg(head);
	head=delete_end(head);
	printList(head);
	cout<<endl;
	head=delete_after(head);
	cout<<endl;
	printList(head);
	
	return 0;
}
