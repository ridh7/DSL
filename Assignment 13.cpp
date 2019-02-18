//============================================================================
// Name        : Assignment 13.cpp
// Author      : 21258
// Version     :
// Copyright   : Your copyright notice
// Description : Quicksort
//============================================================================

#include <iostream>
using namespace std;
class student
{
public:
	float a[100];
	int n;
	int partition(int low, int high)
	{
		float pivot=a[high],t;
		int i=low;
		int j=high;
		while(i<j)
		{
			while(a[i]<=pivot&&i<high)
				i++;
			while(a[j]>=pivot&&j>low)
				j--;
			if(i<j)
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
		t=a[high];
		a[high]=a[i];
		a[i]=t;
		return i;
	}
	void quickSort(int low, int high)
	{
		if(low<high)
		{
			int p=partition(low,high);
			quickSort(low,p-1);
			quickSort(p+1,high);
		}
	}
	void input()
	{
		cout<<"Enter the number of students: ";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cout<<"Enter percentage of student "<<i+1<<": ";
			cin>>a[i];
		}
	}
	void output()
	{
		for(int i=0;i<n;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	void top5()
	{
		for(int i=n-1;i>n-6;i--)
		{
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
};
int main() {
	student s;
	s.input();
	cout<<"Unsorted list: \n";
	s.output();
	s.quickSort(0,s.n-1);
	cout<<"Sorted list: \n";
	s.output();
	cout<<"Top 5: \n";
	s.top5();
	return 0;
}
