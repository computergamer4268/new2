#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <omp.h>
#include <ctime>
using namespace std;

int main() {
	int n;
	cout<<"Enter number of elements :"<<endl;
	cin>>n;
	int a[n], sum = 0, sum1 = 0;
	for(int i=0 ; i<n ; i++) {
		a[i] = rand()%n;
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	
	#pragma omp parallel for reduction(+:sum)
	for(int i=0 ; i<n ; i++) {
		sum += a[i];
	}
	cout<<sum<<endl;
	
	#pragma omp parallel for reduction(+:sum1)
	for(int i=0 ; i<n ; i++) {
		sum1 += a[i];
	}
	float avg = (float)sum/n;
	cout<<avg<<endl;
	return 0; 
	
	
}
