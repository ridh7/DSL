//============================================================================
// Name        : Assignment 10.cpp
// Author      : 21258
// Version     :
// Copyright   : Your copyright notice
// Description : Deque using circular array
//============================================================================

#include <iostream>
using namespace std;
class Dequeue
{
public:
	int b[5],front,rear;
	Dequeue()
	{
		front=-1;
		rear=0;
		for(int i=0;i<5;i++)
			b[i]=0;
	}
	bool isempty()
	{
		if(front==-1)
			return 1;
		else
			return 0; 		
	}
	bool isfull()
	{
		if((front==0 && rear==4)||front==rear+1)
			return 1;
		else
			return 0;
	}
	void addF(int a)
	{
		if(isfull()) 
	    { 
	        cout<<"Dequeue is full"<<endl;  
	    } 
	    else 
	    {
			if(front==-1) 
		    { 
		    	front=0; 
		        rear=0; 
		    } 
		    else
				if(front==0) 
			        front=4;
			    else
			        front=front-1; 
		    b[front]=a; 
		    cout<<"Number has been added to the front successfully!"<<endl;
		}
	}
	void addR(int a)
	{
		if(isfull()) 
	    { 
			cout<<"Dequeue is full"<<endl; 
	    } 
	    else 
	    {
			if(front==-1) 
		    {
		        front=0; 
		        rear=0; 
		    } 
		    else
				if(rear==4) 
			        rear=0;
			    else
			        rear=rear+1;
		    b[rear]=a;
		    cout<<"Number has been added to the rear successfully!"<<endl;
		}
	}
	void delF()
	{
		if(isempty()) 
	    { 
	        cout<<"Dequeue is empty"<<endl; 
	    } 
	    else
	    {
	    	b[front]=0;
			if(front==rear) 
		    { 
		        front=-1; 
		        rear=-1; 
		    } 
		    else 
		        if(front==4) 
		            front=0;
		        else 
		            front=front+1;
		    cout<<"Number has been deleted from the front successfully!"<<endl;
		}
	}
	void delR()
	{
		if (isempty()) 
	    { 
	        cout<<"Dequeue is empty"<<endl; 
	    }
	    else
	    {
	    	b[rear]=0;
			if (front==rear) 
		    { 
		        front=-1; 
		        rear=-1; 
		    } 
		    else 
				if(rear==0) 
			        rear=4; 
			    else
			        rear=rear-1;
			cout<<"Number has been deleted from the rear successfully!"<<endl; 
	    }
	}
	void display()
	{
		for(int i=0;i<5;i++)
		{
			cout<<b[i]<<"\t";
		}
		cout<<endl;
	}
};

int main() {
	Dequeue q;
	int c,t;
	char e;
	do
	{
		cout<<"Enter your choice : \n1.Add from front\n2.Add from rear\n3.Delete from front\n4.Delete from rear\n5.Display\n";
		cin>>c;
		switch(c)
		{
		case 1:
			cout<<"Enter number: ";
			cin>>t;
			q.addF(t);
			break;
		case 2:
			cout<<"Enter number: ";
			cin>>t;
			q.addR(t);
			break;
		case 3:
			q.delF();
			break;
		case 4:
			q.delR();
			break;
		case 5:
			q.display();
			break;
		default:
			cout<<"Invalid Option"<<endl;
		}
		cout<<"Would you like to continue? (Y/N) ";
		cin>>e;
	}
	while(e=='Y'||e=='y');
	cout<<"Thank you!";
	return 0;
}
