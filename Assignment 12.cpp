//============================================================================
// Name        : Assignment 12.cpp
// Author      : 21258
// Version     :
// Copyright   : Your copyright notice
// Description : Sorting algorithms (Insertion,Shell)
//============================================================================

#include <iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}
int shellSort(int arr[], int n)
{
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
    return 0;
}
void print(int *a, int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int main() {
	int a[100],n,e;
	char c;
	do
	{
		cout<<"Enter the number of elements: ";
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cout<<"Enter element "<<i+1<<": ";
			cin>>a[i];
		}
		cout<<"Your list is: "<<endl;
		print(a,n);
		cout<<"Enter your choice: \n1.Insertion Sort\n2.Shell Sort\n";
		cin>>e;
		switch(e)
		{
		case 1:
			insertionSort(a,n);
			cout<<"Sorted list is: "<<endl;
			print(a,n);
			break;
		case 2:
			shellSort(a,n);
			cout<<"Sorted list is: "<<endl;
			print(a,n);
			break;
		default:
			cout<<"Invalid option!"<<endl;
		}
		cout<<"Continue?";
		cin>>c;
	}
	while(c=='Y'||c=='y');
	cout<<"Exit!";
	return 0;
}
