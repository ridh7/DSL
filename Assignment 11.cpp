//============================================================================
// Name        : Assignment 11.cpp
// Author      : 21258
// Version     :
// Copyright   : Your copyright notice
// Description : Searching algorithms (Linear,Sentinel,Binary,Fibonacci)
//============================================================================
#include <iostream>
using namespace std;
class Student
{
public :
	int r[100],p;
};
void input(int *a,int n)
	{
	cout<<"Please enter the roll numbers in ascending order"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<"Roll number "<<(i+1)<<" : ";
			cin>>a[i];
		}
	}

void linear(int *a,int n)
{
	int m,count=0;
	cout<<"Enter the roll number that is to be searched for : ";
	cin>>m;
	for(int i=0;i<n;i++)
	{
		if(a[i]==m)
		{
			count++;
			cout<<"The student was present"<<endl;
		    break;
		}
	}
	if(count==0)
		cout<<"The student was absent"<<endl;
}
void sentinel(int *a,int n)
{
	int m,i;
	cout<<"Enter the roll number that is to be searched for : ";
	cin>>m;
	a[n]=m;
	while(a[i]!=m)
		i++;
	if(i==n)
		cout<<"The student was absent"<<endl;
	else
		cout<<"The student was present"<<endl;
}
void binary(int *a,int ele,int low,int high)
{
	int mid;
	if(low<=high)
	{
		mid=(low+high)/2;
		if(ele<a[mid])
			binary(a,ele,low,mid-1);
		else if(ele>a[mid])
			binary(a,ele,mid+1,high);
		else cout<<"The number was present"<<endl;
	}
	if(low>high)
		cout<<"The number was absent"<<endl;
}
int fibMonaccianSearch(int arr[], int x, int n)
{
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;
    while (fibM < n)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM  = fibMMm2 + fibMMm1;
    }
    int offset = -1;
    while (fibM > 1)
    {
        int i = min(offset+fibMMm2, n-1);
        if (arr[i] < x)
        {
            fibM  = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (arr[i] > x)
        {
            fibM  = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else return i;
    }
    if(fibMMm1 && arr[offset+1]==x)
    	return offset+1;
    return -1;
}
int main() {
	int o,ele,m=0;
	char e;
	Student ob1;
	cout<<"Enter the number of students : ";
	cin>>ob1.p;
	input(ob1.r,ob1.p);
	do
	{
		cout<<"Enter your choice : \n1.Linear Search\n2.Sentinel Search\n3.Binary Search\n4.Fibonacci Search"<<endl;
		cin>>o;
		switch(o)
		{
		case 1:
			linear(ob1.r,ob1.p);
			break;
		case 2:
			sentinel(ob1.r,ob1.p);
			break;
		case 3:
			cout<<"Enter the roll number that is to be searched for : ";
			cin>>ele;
			binary(ob1.r,ele,0,ob1.p-1);
			break;
		case 4:
			cout<<"Enter the element that is to be searched for : ";
			cin>>ele;
			m=fibMonaccianSearch(ob1.r,ele,ob1.p);
			if(m==-1)
				cout<<"Number is absent!\n";
			else
				cout<<"Number found at index "<<m<<"!\n";
			break;
		default:
			cout<<"Please enter valid choice"<<endl;
		}
		cout<<"Would you like to search for another roll number?"<<endl;
		cin>>e;
	}
	while(e=='Y');
	if(e=='N')
		cout<<"Thank you for using the program!";
	return 0;
}
