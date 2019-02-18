//============================================================================
// Name        : Assignment 3.cpp
// Author      : 21258
// Version     :
// Copyright   : Your copyright notice
// Description : Polynomial operations using array
//============================================================================

#include <iostream>
#include <math.h>
using namespace std;

class Polynomial
{
public: int a[100],n;
void input()
{
	cout<<"Enter the degree of the polynomial : ";
	cin>>n;
	for(int i=n;i>=1;i--)
	{
		cout<<"Enter coefficient of degree "<<i<<" : ";
		cin>>a[i];
	}
	for(int i=n+1;i<100;i++)
	{
		a[i]=0;
	}
	cout<<"Enter the constant term : ";
	cin>>a[0];
}
void output()
{
	cout<<"The polynomial is : ";
	for(int i=n;i>=1;i--)
	{
		cout<<a[i]<<"x^"<<i<<"+";
	}
	cout<<a[0]<<endl;
}
void eval()
{
	int x,val=0;
	cout<<"Enter the value of x : ";
	cin>>x;
	for(int i=n;i>=1;i--)
	{
		val=val+a[i]*pow(x,i);
	}
	val=val+a[0];
	cout<<val<<endl;
}
};
void add(Polynomial p1, Polynomial p2)
{
	if(p1.n>=p2.n)
	{
		for(int i=0;i<=p1.n;i++)
		{
		    p1.a[i]=p1.a[i]+p2.a[i];
		}
		p1.output();
	}
	if(p2.n>p1.n)
	{
	    for(int i=0;i<=p2.n;i++)
		{
			p2.a[i]=p2.a[i]+p1.a[i];
		}
	    p2.output();
	}
}
void multiply(Polynomial p1, Polynomial p2)
{
	Polynomial p3;
	for(int i=0;i<=100;i++)
		{
			p3.a[i]=0;
		}
	for(int i=0;i<=p1.n;i++)
	{
		for(int j=0;j<=p2.n;j++)
		{
			p3.a[i+j]+=p1.a[i]*p2.a[j];
		}
	}
	p3.n=p1.n+p2.n;
	p3.output();
}
int main() {
	int o;
	char e;
	Polynomial p1,p2;
	cout<<"Enter polynomial 1 : "<<endl;
	p1.input();
	p1.output();
	cout<<"Enter polynomial 2 : "<<endl;
	p2.input();
	p2.output();
	do
	{
	cout<<"Enter your choice : \n1.Evaluation\n2.Addition\n3.Multiplication"<<endl;
	cin>>o;
	switch(o)
	{
	case 1:
		cout<<"Evaluating polynomial 1"<<endl;
		p1.eval();
		cout<<"Evaluating polynomial 2"<<endl;
		p2.eval();
		break;
	case 2:
		cout<<"Addition : ";
		add(p1,p2);
		break;
	case 3:
		cout<<"Multiplication : ";
		multiply(p1,p2);
		break;
	default:
		cout<<"Please enter a valid choice!";
	}
	cout<<"Would you like to perform another operation?(Y/N)"<<endl;
	cin>>e;
	}
	while(e=='Y');
	if(e=='N')
		cout<<"Thank you!";
	return 0;
}
