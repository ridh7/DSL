//============================================================================
// Name        : Assignment 6.cpp
// Author      : 21258
// Version     :
// Copyright   : Your copyright notice
// Description : Polynomial operations using circular array
//============================================================================

#include <iostream>
#include <math.h>
using namespace std;

class term
{
public:
	int coeff,pow;
	term *next;
	term()
	{
		coeff=0;
		pow=0;
		next=NULL;
	}
};

class poly
{
public:
	term *head;
	poly()
	{
		head=NULL;
	}
	void create(int n)
	{
		head=new term();
		cout<<"Enter coefficient of term 1 : ";
		cin>>head->coeff;
		cout<<"Enter power of term 1 : ";
		cin>>head->pow;
		term *t,*temp;
		int i=1;
		temp=head;
		while(i<n)
		{
			t=new term();
			cout<<"Enter coefficient of term "<<i+1<<" : ";
			cin>>t->coeff;
			cout<<"Enter power of term "<<i+1<<" : ";
			cin>>t->pow;
			temp->next=t;
			t->next=head;
			temp=t;
			++i;
		}
	}
	void output()
	{
		term *temp;
		temp=head;
		do
		{
			cout<<temp->coeff<<"x^"<<temp->pow<<" + ";
			temp=temp->next;
		}
		while(temp->next!=head);
		cout<<temp->coeff<<"x^"<<temp->pow<<endl;
	}
	void eval(int x)
	{
		term *temp;
		temp=head;
		int sum=0;
		do
		{
			sum+=temp->coeff*pow(x,temp->pow);
			temp=temp->next;
		}
		while(temp!=head);
		cout<<"Value : "<<sum<<endl;
	}
	void add(poly p1, poly p2)
	{
		term *s1,*s2,*temp,*t;
		s1=p1.head;
		s2=p2.head;
		head =new term();
		if(s1->pow>s2->pow)
		{
			head->coeff=s1->coeff;
			head->pow=s1->pow;
			s1=s1->next;
		}
		else if(s1->pow<s2->pow)
		{
			head->coeff=s2->coeff;
			head->pow=s2->pow;
			s2=s2->next;
		}
		else
		{
			head->pow=s1->pow;
			head->coeff=s1->coeff+s2->coeff;
			s1=s1->next;
			s2=s2->next;
		}
		t=head;
		do
		{
			temp=new term();
			if(s1->pow>s2->pow)
			{
				temp->pow=s1->pow;
				temp->coeff=s1->coeff;
				s1=s1->next;
			}
			else
			{
				if(s1->pow<s2->pow)
				{
					temp->pow=s2->pow;
					temp->coeff=s2->coeff;
					s2=s2->next;
				}
				else
					{
						temp->pow=s1->pow;
						temp->coeff=s1->coeff+s2->coeff;
						s1=s1->next;
						s2=s2->next;
					}
			}
			t->next=temp;
			temp->next=head;
			t=temp;
		}
		while(s1!=p1.head && s2!= p2.head);
		while(s2!=p2.head)
		{
			temp=new term();
			temp->pow=s2->pow;
			temp->coeff=s2->coeff;
			s2=s2->next;
			t->next=temp;
			temp->next=head;
			t=temp;
		}
		while(s1!=p1.head)
		{
			temp=new term();
			temp->pow=s1->pow;
			temp->coeff=s1->coeff;
			s1=s1->next;
			t->next=temp;
			temp->next=head;
			t=temp;
		}
	}
};
int main() {
	poly p1,p2,p3;
	int n,x;
	cout<<"Polynomial 1 : "<<endl;
	cout<<"Enter the number of terms : ";
	cin>>n;
	p1.create(n);
	p1.output();
	cout<<"Enter the value of x : ";
	cin>>x;
	p1.eval(x);
	cout<<"Polynomial 2 : "<<endl;
	cout<<"Enter the number of terms : ";
	cin>>n;
	p2.create(n);
	p2.output();
	cout<<"Enter the value of x : ";
	cin>>x;
	p2.eval(x);
	p3.add(p1,p2);
	cout<<"Addition : ";
	p3.output();
	return 0;
}
