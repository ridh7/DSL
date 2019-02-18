//============================================================================
// Name        : Assignment 9.cpp
// Author      : 21258
// Version     :
// Copyright   : Your copyright notice
// Description : Priority queue
//============================================================================

#include <iostream>
using namespace std;
class Node
{
public:
	string name;
	int priority;
	Node *next;
	Node()
	{
		name='\0';
		priority=0;
		next=NULL;
	}
};
class Queue
{
public:
	Node *front,*rear;
	Queue()
	{
		front=NULL;
		rear=NULL;
	}
	bool isempty()
	{
		if(front==NULL)
			return 1;
		else
			return 0;
	}
	void push(string c, int a)
	{
		if(!isempty())
		{
			Node *t=new Node();
			t->name=c;
			t->priority=a;
			if(t->priority>front->priority)
			{
				t->next=front;
				front=t;
			}
			else if(t->priority<rear->priority)
			{
				rear->next=t;
				rear=t;
			}
			else
			{
				Node *temp=front->next;
				Node *m=front;
				while(temp!=NULL)
				{
					if(temp->priority<t->priority)
					{
						t->next=m->next;
						m->next=t;
						break;
					}
					else
					{
						temp=temp->next;
						m=m->next;
					}
				}
			}

		}
		else
		{
			front=new Node();
			front->name=c;
			front->priority=a;
			rear=front;
		}
	}
	void pop()
	{
		Node *t=front;
		front=front->next;
		delete t;
	}
	void display()
	{
		Node *t=front;
		while(t!=rear)
		{
			cout<<t->name<<endl;
			t=t->next;
		}
		cout<<rear->name<<endl;
	}
};

int main() {
	Queue q;
	string h;
	int t,c;
	char e;
	do
	{
		cout<<"Enter your choice : \n1.Add a job\n2.Delete a job\n3.Display jobs according to priority\n";
		cin>>c;
		switch(c)
		{
		case 1:
			cout<<"Enter job name : ";
			cin>>h;
			cout<<"Enter priority : ";
			cin>>t;
			q.push(h,t);
			break;
		case 2:
			q.pop();
			break;
		case 3:
			q.display();
			break;
		default:
			cout<<"Invalid choice"<<endl;
		}
		cout<<"Would you like to continue? (Y/N) ";
		cin>>e;
	}
	while(e=='Y'||e=='y');
	cout<<"Thank you!";
	return 0;
}
