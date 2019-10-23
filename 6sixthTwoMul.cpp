//matrix-matrix multiplication
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <omp.h>
using namespace std;
#define N 4

float A[N][N], B[N][N], C[N][N];

int main() {
	int i,j,m;
	//fill matrices
	for(i = 0 ; i < N ; i++) {
		for(j = 0 ; j < N ; j++){
			A[i][j] = rand()%5;
			B[i][j] = rand()%5;
		}
	}
	
	//display matrix A
	
	cout<<"Matrix A :\n";
	
	for(i=0 ; i<N ; i++) {
		for(j = 0 ; j < N ; j++) {
			cout<<A[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	//display matrix B
	cout<<"Matrix B:\n";
	for(i = 0 ; i < N ; i++) {
		for(j = 0 ; j < N ; j++) {
			cout<<B[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	//mutiplication
	
	#pragma omp parallel for private(m,j)
	
	for(i = 0; i < N ; i++) {
		for(j = 0 ; j < N ; j++) {
			C[i][j] = 0;
			
			for(m = 0 ; m < N ; m++) {
				C[i][j] += A[i][m]*B[m][j];
			}
		}
	}
	
	//display C matrix
	cout<<"Matrix C is \n";
	for(i = 0 ; i < N ; i++) {
		for(j = 0 ; j<N ; j++) {
			cout<<C[i][j]<<"\t";
		}
		cout<<endl;
	}
	
	
	
	return 0;
	
	
}
