//============================================================================
// Name        : Assignment 8.cpp
// Author      : 21258
// Version     :
// Copyright   : Your copyright notice
// Description : Expression conversion (infix to postfix) using stack
//============================================================================

#include <iostream>
#include<string.h>
using namespace std;
class node{
public:
	char s;
	node *next;
	node()
	{
		s=' ';
		next=NULL;
	}
};
class Stack{
public:
	node *top;
	Stack()
	{
		top=NULL;
	}
	bool isempty()
	{
		if(top==NULL)
			return 1;
		else
			return 0;
	}
	void push(char c)
	{
		if(!isempty())
		{
			node *t=new node();
			t->s=c;
			t->next=top;
			top=t;
		}
		else
		{
			top=new node();
			top->s=c;
		}
	}
	void pop()
	{
		node *t=top;
		top=top->next;
		delete t;
	}
};
string check(string r, int l)
{
	Stack s2;
	string n[10];
	int j=0;
	for(int i=0;i<l;i++)
	{
		if(r[i]=='+'||r[i]=='-'||r[i]=='*'||r[i]=='/')
		{
			if(s2.isempty())
				s2.push(r[i]);
			else
			{
				if((s2.top->s=='+'||s2.top->s=='-')&&(r[i]=='*'||r[i]=='/'))
					s2.push(r[i]);
				else
				{
					do
					{
						j=j-2;
						n[j]=n[j]+n[j+1]+s2.top->s;
						n[j+1]='\0';
						s2.pop();
						j=j+1;
						if(s2.isempty())
							break;
					}
					while((s2.top->s=='+'&&r[i]=='-')||(s2.top->s=='-'&&r[i]=='+'));
					s2.push(r[i]);
				}
			}
		}
		else
		{
			n[j++]=r[i];
		}
	}
	while(!s2.isempty())
	{
		n[j++]=s2.top->s;
		s2.pop();
	}
	for(int i=0;i<l;i++)
		cout<<n[i];

	for(int i=1;i<l;i++)
	{
		n[0]+=n[i];
	}
	string t=n[0];
	return t;
}
 void eval(string r, int l)
 {
	 Stack s;
	 int g=l/2+1,a[100],res=0,x,y;
	 cout<<"Enter the values of "<<g<<" operands in their order of appearance in the postfix form : "<<endl;
	 for(int i=0;i<g;i++)
		 cin>>a[i];
	 for(int i=0,j=0;i<l;i++)
	 {
		 if(r[i]=='+'||r[i]=='-'||r[i]=='*'||r[i]=='/')
		 {
			 x=s.top->s;
			 s.pop();
			 y=s.top->s;
			 s.pop();
		 }
		 switch(r[i])
		 {
		 case '+':
			 res=x+y;
			 s.push(res);
			 break;
		 case '*':
			 res=x*y;
			 s.push(res);
			 break;
		 case '-':
			 res=y-x;
			 s.push(res);
			 break;
		 case '/':
			 res=y/x;
			 s.push(res);
			 break;
		 default:
			 s.push(a[j++]);
		 }


	 }
	 cout<<res;
 }
int main() {
	Stack s;
	string r,q;
	int l;
	cout<<"Enter the expression: ";
	cin>>r;
	l=r.length();
	q=check(r,l);
	cout<<endl;
	int z=q.length();
	eval(q,z);
	return 0;
}
