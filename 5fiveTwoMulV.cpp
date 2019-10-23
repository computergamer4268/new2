#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <omp.h>
using namespace std;

int main() {
	int m = 3, n = 2;
	
	int mat[m][n], vect[n], out[m];
	
	//matrix size 3x2
	for(int row = 0 ; row < m ; row++) {
		for(int col = 0 ; col < n ; col++) {
			mat[row][col] = 1;
		}
	}
	
	//display matrix
	cout<<"Input Matrix"<<endl;
	
	for(int row = 0 ; row < m ; row++) {
		for(int col = 0 ; col < n ; col++) {
			cout<<"\t"<<mat[row][col];
		}
		cout<<""<<endl;
	}
	
	//column vector of size 2x1
	
	for(int row = 0 ; row < n ; row++) {
		vect[row] = 2;
	}
	
	//display vector
	
	cout<<"Input Vector"<<endl;
	for(int row = 0 ; row < n ; row++) {
		cout<<"\t"<<vect[row]<<endl;
	}
	
	#pragma omp parallel
	{
	
		#pragma omp parallel for
		for(int row = 0 ; row < m ; row++) {
			out[row] = 0;
			for(int col = 0 ; col < n ; col++) {
				out[row] += mat[row][col]*vect[col];
			}
		}
		
		
		
	}
	
	//display resultant vector
	
	cout<<"Resultant col-vector"<<endl;
	
	for(int row = 0 ; row < m ; row++) {
		cout<<"\n"<<out[row];
	}
	
	cout<<endl;
	
}
