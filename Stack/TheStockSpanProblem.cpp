#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void calculateSpan(int a[],int n,int ans[])
{
	ans[0]=1;
	for(int i=1;i<n;i++)
	{
		int counter=1;
		while((i-counter)>=0 && a[i]>a[i-counter])
		{
			counter+=ans[i-counter];
		}
		ans[i]=counter;
	}
}
void calculateSpanStack(int arr[],int n,int ans[])
{
	ans[0]=1;
	stack<int> s;
	s.push(0);
	for(int i=1;i<n;i++)
	{
	while(!s.empty() && arr[s.top()]<=arr[i] )
	{
		s.pop();
	}
	ans[i]=(s.empty())?(i+1):(i-s.top());
	s.push(i);
	}
	
}
void printArray(int arr[],int n)
{
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}
int main() {
	int price[]={10,4,5,90,120,80};
	int n=sizeof(price)/sizeof(price[0]);
	int s[n];
	calculateSpanStack(price,n,s);
	printArray(s,n);

	return 0;
}
