#include <stdlib.h>
#include <iostream>
#include <omp.h>
#include <ctime>
#include <stdio.h>
using namespace std;

int main() {

	cout<<"Enter no. of elements"<<endl;
	int n;
	cin>>n;
	int a[n], max_v = 0, min_v = 99999;
	for(int i=0 ; i<n ; i++) {
		a[i] = rand()%n;
		cout<<a[i]<<" ";
	}
	cout<<"\n";
	#pragma omp parallel for reduction(max:max_v)
	for(int i=0 ; i<n ; i++) {
		if(a[i] > max_v) {
			max_v = a[i];
		}
	}
	cout<<max_v<<endl;
	
	#pragma omp parallel for reduction(min:min_v)
	for(int i=0 ; i<n ; i++) {
		if(a[i] < min_v) {
			min_v = a[i];
		}
	}
	cout<<min_v<<endl;
	return 0;

}

