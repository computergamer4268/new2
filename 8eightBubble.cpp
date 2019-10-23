#include <iostream>
#include <stdio.h>
#include <omp.h>
#include <cstdlib>
using namespace std;

void bubble(int *, int);
void swap(int &, int &);

void bubble(int *a, int n) {
	
	for(int i = 0 ; i < n ; i++) {
		int first = i % 2;
		
		#pragma omp parallel for shared(a, first)
		for(int j = first ; j< n -1 ; j+=2) {
			if(a[j] > a[j+1]) {
				swap(a[j] , a[j+1]);
			}
		}
	}

}

void swap(int &a, int &b) {
	
	int test;
	test = a;
	a = b;
	b = test;
}

int main() {
	
	int *a , n;
	cout<<"Enter total no. of ellements \n";
	cin>>n;
	a = new int[n];
	cout<<"Enter Elements\n";
	
	for(int i=0 ; i<n ; i++) {
		cin>>a[i];
	}
	
	bubble(a,n);
	
	cout<<"Sorted array is :\n";
	for(int i=0 ; i<n ; i++) {
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
	
	
	
}
