//============================================================================
// Name        : Assignment 4.cpp
// Author      : 21258
// Version     :
// Copyright   : Your copyright notice
// Description : Singly linked list (Pinnacle Club)
//============================================================================

#include <iostream>
using namespace std;
class Node
{
public:
	double prn;
	string name;
	Node *ptr;

    Node()
    {
	    prn=0;
	    ptr=NULL;
    }
};
class LinkedList
{
public:
	Node *first,*last,*n,*temp;
	LinkedList()
	{
		first=NULL;
		last=NULL;
		n=NULL;
		temp=NULL;
	}

	void initial()
	{
		first=new Node();
		last=new Node();
	    n=new Node();
		first->ptr=n;
		n->ptr=last;
		cout<<"Enter President's Name and PRN : "<<endl;
		cin>>first->name;
		cin>>first->prn;
		cout<<"Enter Secretary's Name and PRN : "<<endl;
		cin>>last->name;
		cin>>last->prn;
		cout<<"Enter Node's Name and PRN : "<<endl;
		cin>>n->name;
		cin>>n->prn;
	}
	void add()
	{
		int c;
		double o;
		cout<<"Enter 1 for President, 2 for Secretary, 3 for Member : ";
		cin>>c;
		if(c==1)
		{
			cout<<"Enter President's Name and PRN : "<<endl;
			cin>>first->name;
			cin>>first->prn;
		}
		if(c==2)
		{
			cout<<"Enter Secretary's Name and PRN : "<<endl;
			cin>>last->name;
			cin>>last->prn;
		}
		if(c==3)
		{
			Node *temp,*t;
			temp=new Node();
			cout<<"Enter name and PRN : "<<endl;
			cin>>temp->name;
			cin>>temp->prn;
			cout<<"Enter the PRN of node after which you would like to add new node : ";
			cin>>o;
			t=first;
			if(o==last->prn)
				cout<<"Node cannot be added after secretary"<<endl;
			else
				while(o!=t->prn)
				{
					t=t->ptr;
				}
				temp->ptr=t->ptr;
				t->ptr=temp;
		}
	}

	void del()
	{
		double o;
		Node *t,*y;
		t=new Node();
		y=new Node();
		t=first;
		cout<<"Enter the PRN of the node to be deleted : ";
		cin>>o;
		if(o==first->prn)
		{
			first=first->ptr;
		}
		else
		{
			while(t!=NULL&&t->prn!=o)
			{
				y=t;
				t=t->ptr;
			}
			if(t->prn==last->prn)
			{
				y->ptr=NULL;
				last=y;
			}
			else
				y->ptr=t->ptr;
		}
	}
	void display()
	{
		int count=0;
		Node *t;
		t=new Node();
		t=first;
		cout<<"The members are : "<<endl;
		while(t->ptr!=NULL)
		{
			cout<<"   "<<t->name<<"   "<<t->prn<<endl;
			t=t->ptr;
			count++;
		}
		cout<<"   "<<last->name<<"   "<<last->prn<<endl;
		count++;
		cout<<"The number of nodes is : "<<count<<endl;
	}
	void reverse(Node *t)
		{
			if(t!=NULL)
			{
				reverse(t->ptr);
			    cout<<"   "<<t->name<<"   "<<t->prn<<endl;
			}
		}
};
int main() {
	LinkedList l1,l2;
	l1.initial();
	int e;
	char a;
	do
	{
		cout<<"Enter your choice : \n1.Add new node\n2.Display members and count of members\n3.Delete node\n4.Print in reverse order"<<endl;
		cin>>e;
		switch(e)
		{
		case 1:
			l1.add();
			break;
		case 2:
			l1.display();
			break;
		case 3:
			l1.del();
			break;
		case 4:
			l1.reverse(l1.first);
			break;
		default:
			cout<<"Please enter valid option"<<endl;
		}
		cout<<"Would you like to perform another operation? (Y/N) ";
		cin>>a;
	}
	while(a=='Y');
	if(a=='N')
		cout<<"Thank you!";
	return 0;
}
