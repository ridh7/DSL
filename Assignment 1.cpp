//============================================================================
// Name        : Assignment 1.cpp
// Author      : 21258
// Version     :
// Copyright   : Your copyright notice
// Description : Student marks using array
//============================================================================

#include <iostream>
using namespace std;

class Student{
public:
	int roll,marks,p;
	string name;
	void input()
	{
		cout<<"Enter name : ";
		cin>>name;
		cout<<"Enter roll number : ";
		cin>>roll;
		cout<<"Enter 1 for present and 0 for absent : ";
		cin>>p;
		if(p==1)
		{
			cout<<"Enter marks : ";
		    cin>>marks;
		}
		if(p==0)
			marks=-1;

	}
};
void avg(int n, Student a[])
	{
	int i,sum=0;
	float res;
	for(i=0;i<=n;i++)
	{
	sum=sum+a[i].marks;
	}
	res=sum/n;
	cout<<"The average of score is : "<<res<<endl;
	}

void minimum(int n,Student a[])
{
	int i,min;
	min=a[0].marks;
	for(i=0;i<n;++i)
	{
		if(a[i].marks<=0)
			continue;
		if(a[i].marks<min)
			min=a[i].marks;
	}
	cout<<"The minimum score is : "<<min<<endl;


}

void maximum(int n,Student a[])
{
	int i,max;
	max=a[0].marks;
	for(i=0;i<n;++i)
	{
		if(a[i].marks>max)
		max=a[i].marks;
	}
	cout<<"The maximum score is : "<<max<<endl;
}

void count(int n,Student a[])
{
	int i,count=0,temp,j,b[100],max;
	for(i=0;i<=n;++i)
	{
		temp=a[i].marks;
	for(j=0;j<=n;++j)
	{
		if(temp==-1)
		continue;
		if(temp==a[j].marks)
			++count;

	}
	b[i]=count;
	count=0;

	}
	max=b[0];
			for(i=1;i<=n;++i)
			{
				if(b[i]>max)
					max=b[i];
			}
	for(i=0;i<=n;++i)
	{
		if(max==b[i])
			{
			cout<<"The most frequent element is : "<<a[i].marks<<endl;
			break;
			}
	}

}

void absent(int n,Student a[])
{
	int i,count=0;
	for(i=0;i<n;++i)
	{
		if(a[i].marks==-1)
			count++;
	}
	cout<<"The number of absent students is : "<<count;
}

int main()
{
	int i,n,m;
	Student s[100];
	cout<<"Enter the number of students : ";
	cin>>n;
	m=n-1;
	for(i=0;i<=m;++i)
		s[i].input();
	minimum(n,s);
	maximum(n,s);
	avg(n,s);
	count(n,s);
	absent(n,s);


	return 0;
}


