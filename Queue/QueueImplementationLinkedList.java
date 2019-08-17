/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

class QNode
{
	int key;
	QNode next;
	
	public QNode(int key)
	{
		this.key=key;
		this.next=null;
	}
}
class Queue
{
	QNode front,rear;
	public Queue()
	{
		this.front=this.rear=null;
	}
	void enqueue(int key)
	{
		QNode temp=new QNode(key);
		if(this.rear==null)
		{
			this.front=this.rear=temp;
			return;
		}
		this.rear.next=temp;
		this.rear=temp;
	}
	QNode dequeue()
	{
		if(this.front==null)
			return null;
		QNode temp=this.front;
		this.front=this.front.next;
		if(this.front==null)
			this.rear=null;
		return temp;
		
	}
}
class Ideone
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Queue q=new Queue();
		q.enqueue(10);
		q.enqueue(20);
		q.enqueue(30);
		q.enqueue(40);
		
		System.out.println("Dequeued item 1 is "+ q.dequeue().key);
		System.out.println("Dequeued item 2 is "+ q.dequeue().key);
	}
}
