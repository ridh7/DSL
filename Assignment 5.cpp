//============================================================================
// Name        : Assignment 5.cpp
// Author      : 21258
// Version     :
// Copyright   : Your copyright notice
// Description : Cinemax booking operations using doubly circular linked list
//============================================================================

#include <iostream>
using namespace std;
class Seat
{
public:
	int n;
	Seat *next,*prev;
	Seat()
	{
		n=0;
		next=NULL;
		prev=NULL;
	}
};
class Row
{
public:
	Seat *head;
	Row()
	{
		head=NULL;
	}
	void create()
	{
		head=new Seat();
		head->n=1;
		Seat *temp,*t;
		temp=head;
		for(int i=1;i<7;i++)
		{
			t=new Seat();
			if(i==6)
			{
				head->prev=t;
				t->next=head;
				temp->next=t;
				t->prev=temp;
				t->n=i+1;
				temp=temp->next;
			}
			else
			{
				temp->next=t;
				t->prev=temp;
				t->n=i+1;
				temp=temp->next;
			}
		}
	}
	void show()
	{
		Seat *temp;
		temp=head;
		do
		{
			cout<<temp->n<<" ";
			temp=temp->next;
		}
		while(temp!=head);
		cout<<endl;
	}

	void book(int m)
		{
			Seat *temp;
			temp=head;
			do
			{
				if(temp->n==m)
				{
					if(temp==head)

						{
						head->prev->next= head->next;
						head->next->prev=temp->prev;
						head=temp->next;
						delete (temp);
						}
					else
					{
					(temp->next)->prev=temp->prev;
					(temp->prev)->next=temp->next;
					delete(temp);
					}
					break;
				}
				temp=temp->next;
			}
			while(temp!=head);
			cout<<"Seat has been booked"<<endl;

			}
	void cancel(Seat *t,int m)
	{
		int c=0;
		Seat *temp,*p;
		temp=head;
		p=new Seat();
		if(m<temp->n)
		{
			p->next=temp;
			p->prev=temp->prev;
			temp->prev->next=p;
			temp->prev=p;
			p->n=m;
			head=p;
			cout<<"Booking has been cancelled"<<endl;
		}
		else
		{
			while(m>=temp->n)
			{
				if(m==temp->n)
				{
					c=1;
					break;
				}
				temp=temp->next;
			}
			if(c==0)
			{
				p->next=temp;
				p->prev=temp->prev;
				temp->prev->next=p;
				temp->prev=p;
				p->n=m;
				cout<<"Booking has been cancelled"<<endl;
			}
			else
				cout<<"Seat is already available"<<endl;
		}

	}
};
int main() {
	int e;
	Seat *a[10];
	char c;
	Row r[10];
	for(int i=0;i<10;i++)
	{
		r[i].create();
		a[i]=r[i].head;
	}
	do
	{
		cout<<"Enter your choice : \n1.Show available seats\n2.Book a seat\n3.Cancel a booking\n";
		cin>>e;
		switch(e)
		{
		case 1:
			for(int i=0;i<10;i++)
			{
				r[i].show();
			}
			break;
		case 2:
			int rr,s;
			cout<<"Enter row number : ";
			cin>>rr;
			cout<<"Enter seat number : ";
			cin>>s;
			r[rr-1].book(s);
			a[rr-1]=r[rr-1].head;
			break;
		case 3:
			int m,n;
			cout<<"Enter seat to be cancelled :"<<endl;
			cout<<"Row : ";
			cin>>m;
			cout<<"Seat : ";
			cin>>n;
			r[m-1].cancel(a[m-1],n);
		}
		cout<<"Would you like to perform another operation? (Y/N) ";
		cin>>c;
	}
	while(c=='Y'||c=='y');
	if(c=='N'||c=='n')
		cout<<"Thanks!";
	return 0;
}
