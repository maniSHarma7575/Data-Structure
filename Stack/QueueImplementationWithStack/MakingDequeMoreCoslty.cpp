#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Queue //Implementation by making Enqueue operation more costly
{
	public:
	stack <int> s1,s2;
	void enQueue(int x)
	{
		s1.push(x);
	}
	int deQueue()
	{
		if(s1.empty())
		{
			return -1;
		}
		else
		{
			int x=-1;
			if(s2.empty())
			{
				while(!s1.empty())
				{
				s2.push(s1.top());
				s1.pop();
				}
				x=s2.top();
				s2.pop();
				while(!s2.empty())
				{
					s1.push(s2.top());
					s2.pop();
				}
			}
			return x;
			
			
			
		}
	}
	
};
int main()
{
	Queue q;
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);
	q.enQueue(4);
	q.enQueue(5);
	cout<<q.deQueue()<<endl;
	cout<<q.deQueue()<<endl;
	cout<<q.deQueue()<<endl;
	q.enQueue(6);
	q.enQueue(7);
	cout<<q.deQueue()<<endl;
	cout<<q.deQueue()<<endl;
	cout<<q.deQueue()<<endl;
	cout<<q.deQueue()<<endl;
	cout<<q.deQueue()<<endl;
	cout<<q.deQueue()<<endl;
}
