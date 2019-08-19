#include <iostream>
#include <queue>
using namespace std;

void showpq(priority_queue <int> pq)
{
	priority_queue <int> g=pq;
	while(!g.empty())
	{
		cout<<'\t'<<g.top();
		g.pop();
	}
	cout<<'\n';
}
int main()
{
	priority_queue<int> pq;
	pq.push(10);
	pq.push(20);
	pq.push(30);
	pq.push(40);
	cout<<"The priority queue is :";
	showpq(pq);
	cout<<pq.size()<<" ";
	cout<<pq.top()<<" ";
	pq.pop();
}
