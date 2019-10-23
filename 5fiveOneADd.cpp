//addtion of two large vectors
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <omp.h>

using namespace std;
#define MAX 100

int main() {
	
	int a[MAX],b[MAX],c[MAX],i;
	
	#pragma omp parallel for
	for(int i=0 ; i<MAX ; i++) {
		a[i] = rand()%1000;
	}
	
	//print first matrix
	
	cout<<"\n First Vector: \n";
	
	for(int i=0 ; i<MAX ; i++) {
		cout<<a[i]<<"\t";
	}
	
	cout<<"\n Second Vector \n";
	
	#pragma omp parallel for
	
	for(int i=0 ; i<MAX ; i++) {
		b[i] = rand()%1000;
	}
	
	for(int i=0  ; i<MAX ; i++) {
		cout<<b[i]<<"\t";
	}
	
	cout<<"\n Parallel Vector addition: \n";
	
	#pragma omp parallel for
	
	for(int i=0 ; i<MAX ; i++) {
		c[i] = a[i] + b[i];
	}
	
	for(int i=0 ; i<MAX ; i++) {
		cout<<"\n"<<a[i]<<"\t"<<b[i]<<"\t"<<c[i];
	}

}
