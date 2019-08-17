/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
class Queue
{
	int front,rear,size;
	int capacity;
	int array[];
	public Queue(int capacity)
	{
		this.capacity=capacity;
		front=this.size=0;
		rear=capacity-1;
		array=new int[this.capacity];
	}
	boolean isFull(Queue queue)
	{
		return (queue.size==queue.capacity);
	}
	boolean isEmpty(Queue queue)
	{
		return (queue.size==0);
	}
	void enqueue(int item)
	{
		if(isFull(this))return;
		this.rear=(this.rear+1)%this.capacity;
		this.array[this.rear]=item;
		this.size=this.size+1;
		
	}
	int dequeue()
	{
		if(isEmpty(this))return Integer.MIN_VALUE;
		int item = this.array[this.front];
		this.front=(this.front+1)%this.capacity;
		this.size=this.size-1;
		return item;
	}
	int front()
	{
		if(isEmpty(this))
			return Integer.MIN_VALUE;
		return this.array[this.front];
	}
	int rear()
	{
		if(isEmpty(this))
			return Integer.MIN_VALUE;
		return this.array[this.rear];
	}
}
/* Name of the class has to be "Main" only if the class is public. */
class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Queue queue=new Queue(10);
		queue.enqueue(10);
		queue.enqueue(20);
		queue.enqueue(30);
		queue.enqueue(40);
		System.out.println("Element Deleted :"+queue.dequeue());
		System.out.println("Element at front: "+queue.front());
		System.out.println("Element at rear:"+queue.rear());
	}
}
