#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class MinHeap
{
	int *harr;
	int capacity;
	int heap_size;
	public:
	MinHeap(int cap)
	{
		heap_size=0;
		capacity=cap;
		harr=new int[cap];
	}
	int parent(int i)
	{
		return (i-1)/2;
	}
	int left(int i)
	{
		return ((2*i)+1);
	}
	int right(int i)
	{
		return ((2*i)+2);
	}
	void insertKey(int k)
	{
		if(heap_size==capacity)
		{
			cout<<"\n Overflow: Could not insertKey\n";
			return;
		}
		heap_size++;
		int i=heap_size-1;
		harr[i]=k;
		while(i!=0 && harr[parent(i)]>harr[i])
		{
			int temp=harr[i];
			harr[i]=harr[parent(i)];
			harr[parent(i)]=temp;
			i=parent(i);
		}
	}
	void Display()
	{
		for(int i=0;i<heap_size;i++)
		{
			cout<<harr[i]<<" ";
		}
	}
	int extractMin()
	{
		if(heap_size<=0)
			return INT_MAX;
		if(heap_size==1)
		{
			heap_size--;
			return harr[0];
		}
		int root=harr[0];
		harr[0]=harr[heap_size-1];
		heap_size--;
		MinHeapfiy(0);
		return root;
	}
	void MinHeapfiy(int i)
	{
		int l=left(i);
		int r=right(i);
		int smallest=i;
		if(l<heap_size && harr[l]<harr[i])
			smallest=l;
		if(r<heap_size && harr[r]<harr[smallest])
			smallest=r;
		if(smallest!=i)
		{
			int temp=harr[i];
			harr[i]=harr[smallest];
			harr[smallest]=temp;
			MinHeapfiy(smallest);
		}
	}
	
};
int main() {
	MinHeap m(7);
	for(int i=7;i>=1;i--)
	{
		m.insertKey(i);
	}
	m.Display();
	m.extractMin();
	cout<<endl;
	m.Display();
	return 0;
}
