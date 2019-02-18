//============================================================================
// Name        : Assignment 7.cpp
// Author      : 21258
// Version     :
// Copyright   : Your copyright notice
// Description : Paranthesis expression check using stack
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
	void check(int l,string r)
	{
		for(int i=0;i<l;i++)
			{
				if(r[i]=='('||r[i]=='{'||r[i]=='[')
					push(r[i]);
				else if((r[i]==')'&& top->s=='(')||(r[i]=='}' && top->s=='{')||(r[i]==']' && top->s=='['))
					pop();
				else
					continue;
			}
	}
};

int main() {
	int l;
	Stack s;
	string r;
	cout<<"Enter the expression : ";
	cin>r;
	l=r.length();
	s.check(l,r);
	if(s.isempty())
		cout<<"The expression is well parenthesized";
	else
		cout<<"The expression is not well parenthesized";
	return 0;
}
