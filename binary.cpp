#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<omp.h>
using namespace std;
int binary_parallel(int *,int ,int, int );

int binary_parallel(int *a,int low,int high,int key)
{
	int mid;
	mid=(low+high)/2;
	int mid1,mid2,low1,low2,high1,high2,found=0,loc=-1;
	
	#pragma omp parallel sections
	{
		#pragma omp section
		{
			low1=low;
			high1=mid;
			while(low1<=high1)
			{
			if(!(key>=a[low1] && key<=a[high1]))
			{
				low1=low1+high1;
				continue;
			}
			mid1=(low1+high1)/2;
			if(key==a[mid1])
			{
				found=1;
				loc=mid1;
				low1=high1+1;
			}
			else if(key>a[mid1])
			{
				low1=mid1+1;
				
			}
			else if(key<a[mid1])
			{
				high1=mid1-1;
			}
			}
		}
		#pragma omp section
		{
			low2=mid+1;
			high2=high;
			while(low2<=high2)
			{
			
			if(!(key>=a[low2] && key<=a[high2]))
			{
				low2=low2+high2;
				continue;
			}
			mid2=(low2+high2)/2;
			if(key==a[mid2])
			{
				found=1;
				loc=mid2;
				low2=high2+1;
			}
			else if(key>a[mid2])
			{
				low2=mid2+1;
			}
			else if(key<a[mid2])
			{
				high2=mid2-1;
			}
			}
		}
	}
	return loc;
	
}
int main()
{
	int *a,n,key,loc1=-1;
	float t;
	clock_t c1,c2;
	cout<<"\nEnter no. of elele: \n";
	cin>>n;
	a=new int[n];
	cout<<"\nEnter sorted elements :\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"\nEnter key: \n";
	cin>>key;
	c1=clock();
	loc1=binary_parallel(a,0,n-1,key);
	c2=clock();
	t=(float)(c2-c1)/CLOCKS_PER_SEC;
	if(loc1==-1)
	{
		cout<<"\nKey not found\n";
	}
	else
	{
		cout<<"\nkey found at "<<loc1+1<<" location";
	}
	cout<<"\nexec time :"<<t;
	return 0;
}
