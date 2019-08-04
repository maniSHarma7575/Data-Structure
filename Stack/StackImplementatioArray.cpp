#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define MAX 100
class Stack
{
	int top;
public:
	int a[MAX];
	Stack()
	{
		top=-1;
		
	}
	bool push(int x);
	int pop();
	int peek();
	bool isEmpty();
};
bool Stack::push(int x)
{
	if(top>=(MAX-1))
	{
		cout<<"Stack Overflow:";
		return false;
	}
	else
	{
		a[++top]=x;
		cout<<a[top]<<endl;
		return true;
	}
}

int Stack::pop()
{
	if(top<0)
	{
		cout<<"Stack underflow:";
		return -1;
	}
	else
	{
		return a[top--];
	}
}
int Stack::peek()
{
	if(top<0)
	{
		cout<<"Underflow";
		return -1;
	}
	else
	{
		return a[top];
	}
}
bool Stack::isEmpty()
{
	if(top<0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main() {
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	cout<<s.pop()<<" Popped from stack\n";
	cout<<s.peek()<<" Element at the top of the stack";
	return 0;
}
