//============================================================================
// Name        : Assignment 14.cpp
// Author      : 21258
// Version     :
// Copyright   : Your copyright notice
// Description : Miniproject
//============================================================================
#include<iostream>
#include<string.h>
using namespace std;
class student
{
public:
    char name[20];
    int cet_m, mains_m;
    double ssc_p,number;
    student *next;
};
class list
{
public:
    char name[20];
    double aggr;
	long int number;
    list *next;
    
};
double calculate_aggregate(student *stud)
{   
    student *s = stud;
    double aggr;
    aggr = s->ssc_p * 10/100  + (s->cet_m * 100/200) * 50/100  + 
        (s->mains_m * 100/360) * 40/100;
    return aggr;
}
void addToList(student *stud, list *l)
{   
    list *pointer = l;
    while (pointer->next != NULL)
    {
        pointer = pointer->next;
    } 
    pointer->next = new list();
    pointer = pointer->next;
    strcpy(pointer->name , stud->name);
    pointer->number=stud->number;
    pointer->aggr = calculate_aggregate(stud);
    pointer->next = NULL;
}
void showList(student *stud, list *l)
{
    list *pointer = l;
    if (pointer->next == NULL)
        cout<<"No student registered yet!\n";
    else
    {
		cout<<"---------------------------------------------"<<endl;
        cout<<"Students statistics are: \n";
        while (pointer->next != NULL)
        {
            pointer = pointer->next;
            cout<<"Name: "<<pointer->name<<endl;
            cout<<"Number: "<<pointer->number<<endl;
            cout<<"Aggregate of student is: "<<pointer->aggr<<"\n";
            if (pointer->aggr >= 60)
                cout<<"Student registered in Computer Engineering (CE)\n";
            else if(pointer->aggr >=50)
                cout<<"Student registered in Information Technology (IT)\n";
            else
                cout<<"Student registered in Electronics and Telecommunication (ENTC)\n";
			cout<<"---------------------------------------------"<<endl;
            cout<<"\n";
            }
        }
    }
bool register_student(student *stud, list *ls)
{   
    student *s = stud;
    cout<<"Enter name: ";
    cin>>s->name;
    cout<<"Enter contact number: ";
    cin>>s->number;
    cout<<"Enter SSC percentage: ";
    cin>>s->ssc_p;
    cout<<"Enter CET marks (out of 200): ";
    cin>>s->cet_m;
    cout<<"Enter JEE (Mains) (out of 360): ";
    cin>>s->mains_m;
    double aggregate;
    aggregate = calculate_aggregate(s);   //-->call to function below...
    cout<<"Aggregate percentage is "<< aggregate<<"\n";
    if (aggregate >= 60)
    {
        cout<<"Student registered in CE\n";
        addToList(s,ls);
        return true;
    }
    else if (aggregate >= 50)
    {
        cout<<"Student registered in IT\n";
        addToList(s,ls);
        return true;
    }
    else if (aggregate >= 40)
    {
        cout<<"Student registered in ENTC\n";
        addToList(s,ls);
        return true;
    }
    else
    {
        cout<<"Sorry, the student can't be registered in PICT\n";
        return false;
    }
}
void priorityqueue(list *p)
{
	list *a,*b;
	char name1[20];
	double aggregate1;
	long int number1;
	for(a=p->next;a!=NULL;a=a->next)
	{
		for(b=a;b!=NULL;b=b->next)
		{
			if(a->aggr<=b->aggr)
			{
			    aggregate1=a->aggr;
			    a->aggr=b->aggr;
			    b->aggr=aggregate1; 
			    strcpy(name1,a->name);
				strcpy(a->name,b->name);
				strcpy(b->name,name1);
			    number1=a->number;
			    a->number=b->number;
			    b->number=number1;
			}
		}
	}
}
void update(list *p, student *s)
{
	long int number2;
	cout<<"Enter contact number: ";
	cin>>number2;
	list *temp=p->next;
	while(temp->number!=number2)
		temp=temp->next;
	cout<<"Enter name: ";
	cin>>temp->name;
	cout<<"Enter contact number: ";
	cin>>temp->number;
    cout<<"Enter SSC percentage: ";
    cin>>s->ssc_p;
    cout<<"Enter CET marks (out of 200): ";
    cin>>s->cet_m;
    cout<<"Enter JEE (Mains) (out of 360): ";
    cin>>s->mains_m;
    double aggregate;
    aggregate = calculate_aggregate(s);
	temp->aggr=aggregate;
	if(aggregate<40)
	{
		cout<<"Sorry, the student can't be registered in PICT\n";
		delete temp;
	}
	else
	{
		cout<<"---------------------------------------------"<<endl;
		cout<<"The details after the updation are as follows"<<endl;
		cout<<"Name: "<<temp->name<<endl;
	    cout<<"Number: "<<temp->number<<endl;
	    cout<<"Aggregate of student is: "<<temp->aggr<<"\n";
	    if (temp->aggr >= 60)
	        cout<<"Student registered in Computer Engineering (CE)\n";
	    else if(temp->aggr >=50)
	        cout<<"Student registered in Information Technology (IT)\n";
	    else
	        cout<<"Student registered in Electronics and Telecommunication (ENTC)\n";
		cout<<"---------------------------------------------"<<endl;
		cout<<"\n";
	}
}
int main()
{   
    student *s;
    student *p;
    p= new student();
    s = new student();
    list *ls;
    ls = new list();
    ls->name[0] = '\0';
    ls->aggr = 0;
    ls->next= NULL;
    do
    {
	cout<<"Enter your choice: \n1.Register a new student\n2.Display in order of entry\n3.Display registered students based on their merit score\n4.Update information\n5.Exit\n";
    int input;
    cin>>input;
    if (input == 1)
    {
        register_student(s, ls);
    }
	else if (input == 2)
    {
        showList(s, ls);
    }
    else if (input == 3)
    {
        priorityqueue(ls);
        showList(s, ls);
    }
    else if (input == 4)
    {
		update(ls,p);
        priorityqueue(ls);
    }
    else if (input == 5)
        exit(0);
    cout<<"\n";
    } 
	while(1);
}

