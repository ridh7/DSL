//============================================================================
// Name        : Assignment 2.cpp
// Author      : 21258
// Version     :
// Copyright   : Your copyright notice
// Description : String operations using array
//============================================================================

#include <iostream>
using namespace std;
class Assignment2
{
public:
	char p[100];
	int m;
};

int length(char *a)
{
	int count=0;
	for(int i=0;a[i]!='\0';i++)
	{
		count++;
	}
	return count;
}

void equal(int m,char a[])
{
	int count=0;
	char b[100];
	int n=length(b);
	cout<<"Enter the string to be checked : ";
	cin>>b;
	if(m==n)
	{
		for(int i=0;i<m;i++)
		{
				if(a[i]==b[i])
				{
					count++;
				}
				else
					break;
		}
		if(count==m)
			cout<<"The strings are equal"<<endl;
	}
	else
			cout<<"The strings are unequal"<<endl;



}


void copy(int m,char a[])
	{
	    char b[100];
		int i;
		for(i=0;i<m;i++)
		{
			b[i]=a[i];
		}
		cout<<"The string has been copied to another array b = "<<b<<endl;
	}

void concatenate(int m,char a[])
	{
	    char c[200],b[100];
		int i,n;
		n=length(b);
		cout<<"Enter string 2: ";
		cin>>b;
		for(i=0;i<m;i++)
		{
			c[i]=a[i];
		}
		for(i=0;i<n;i++)
		{
			c[m+i]=b[i];
		}
		cout<<"The concatenated string is "<<c<<endl;
		/*for(int i=0;i<(m+n);i++)
		{
			cout<<c[i];
		}
		cout<<endl;*/
	}
void reverse(int m, char a[])
{
	char b[100];
	int i,j=m-1;
	for(i=0;i<m;i++)
	{
		b[j]=a[i];
		j--;
	}
	cout<<"The reversed string is "<<b<<endl;
}
void freq(int m, char a[])
{
	char c;
	int count=0;
	cout<<"Enter the character whose frequency is to be found : ";
	cin>>c;
	for(int i=0;i<m;i++)
	{
		if(a[i]==c)
			count++;
	}
	cout<<"The chosen character occurs "<<count<<" times in the string"<<endl;
}
void del(int m, char a[])
{
	int i,j,h,l;
	cout<<"Enter the starting number and length of string to be deleted : ";
	cin>>h;
	cin>>l;
	char temp[100];
	for(i=0,j=0;i<m;i++)
	{
		if(i<(h-1))
			temp[j++]=a[i];
		if(i>(h+l-2))
			temp[j++]=a[i];
	}
	cout<<"The string after deletion is : "<<temp<<endl;
}
void chardel(int m,char a[])
{
	char c,temp[100];
	int i,j;
	cout<<"Enter character to be deleted : ";
	cin>>c;
	for(i=0,j=0;i<m;i++)
	{
		if(c!=a[i])
			temp[j++]=a[i];
	}
	if(j==m)
		cout<<"The character is not present"<<endl;
	else
	    cout<<"The selected character has been removed"<<endl;
	cout<<temp<<endl;
}
void palindrome(int m,char a[])
{
	char b[100];
	int count=0,j=m;
	for(int i=0;i<m;i++)
	{
		if(a[i]!=b[j--])
		{
			cout<<"The string is not a palindrome"<<endl;
			break;
		}

		else
			count++;
	}
	if(count>0)
		cout<<"The string is a palindrome"<<endl;
}
void substr(int m,char *a)
{
	char b[100];
	int i,j;
	cout<<"Enter substring that is to be searched for : ";
	cin>>b;
	for(i=0,j=0;a[i]!='\0';i++)
	{
		if(a[i]==b[j])
		{
			j++;
		}
	}
	if(b[j]=='\0')
		cout<<"The substring is present"<<endl;
	else
		cout<<"The substring is absent"<<endl;
}
void replace(int m,char *a)
{
	char b[100],s[100],temp[200];
	int i,j,x,y,k;
	for(i=0;i<m;i++)
	{
		temp[i]=a[i];
	}
	cout<<"Enter substring to be replaced : ";
	cin>>b;
	cout<<"Enter replacement substring : ";
	cin>>s;
	x=length(b);
	y=length(s);
	for(i=0,j=0;a[i]!='\0';i++)
		{
			if(a[i]==b[j])
			{
				j++;
				if(j==1)
					k=i;
			}
		}
		if(b[j]=='\0')
		{
		for(i=k;i<(m+y-x);i++)
		{
			temp[i+y]=a[i+x];
		}
		for(i=k,j=0;j<y;i++,j++)
			temp[i]=s[j];for(i=0,j=0;a[i]!='\0';i++)
			{
				if(a[i]==b[j])
				{
					j++;
				}
			}
			cout<<"The new string is "<<temp<<endl;
		}
		else
			cout<<"The substring is absent"<<endl;

}


int main() {
	Assignment2 ob1;
	int c;
	char e;
	cout<<"Enter string : ";
	cin>>ob1.p;
	ob1.m=length(ob1.p);
    do
    {
    	cout<<"Enter your choice : \n1.Check Substring\n2.Concatenate\n3.Copy\n4.Check if the strings are equal\n5.Reverse the string\n6.Find frequency of particular character\n7.Delete substring\n8.Delete character\n9.Check for palindrome\n10.Replace substring\n";
    	cin>>c;
    switch(c)
    {
    case 1 :
    	substr(ob1.m,ob1.p);
    	break;
    case 2 :
    	concatenate(ob1.m,ob1.p);
    	break;
    case 3 :
    	copy(ob1.m,ob1.p);
    	break;
    case 4 :
    	equal(ob1.m,ob1.p);
    	break;
    case 5 :
    	reverse(ob1.m,ob1.p);
    	break;
    case 6 :
    	freq(ob1.m,ob1.p);
    	break;
    case 7 :
    	del(ob1.m,ob1.p);
    	break;
    case 8 :
    	chardel(ob1.m,ob1.p);
    	break;
    case 9 :
	    palindrome(ob1.m,ob1.p);
	    break;
    case 10 :
    	replace(ob1.m,ob1.p);
    	break;
    default : cout<<"Please enter a valid option";
    }
    cout<<"Would you like to perform another operation?";
    cin>>e;
    }
    while(e=='Y');
    if(e=='N')
    	cout<<"Thanks for using the program!";
    return 0;
}
