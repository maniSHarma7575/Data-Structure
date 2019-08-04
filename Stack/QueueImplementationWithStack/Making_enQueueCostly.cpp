#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Queue //Implementation by making Enqueue operation more costly
{
	public:
	stack <int> s1,s2;
	void enQueue(int x)
	{
		while(!s1.empty())
		{
			
			s2.push(s1.top());
			s1.pop();
		}
		s1.push(x);
		while(!s2.empty())
		{
			
			s1.push(s2.top());
			s2.pop();
		}
	}
	int deQueue()
	{
		if(!s1.empty())
		{
			int y=s1.top();
			s1.pop();
			return y;
		}
		return -1;
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
	
}
