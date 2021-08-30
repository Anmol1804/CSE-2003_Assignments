#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void matrixMul(int mat1[][10], int mat2[][10], int r1, int c1, int r2, int c2){
	
	int output[r1][c2];
	
	// Initializing elements of matrix mult to 0.
   for (int i = 0; i < r1; ++i) {
      for (int j = 0; j < c2; ++j) {
         output[i][j] = 0;
      }
   }
   
   // Calculating mul matrix
   for (int i = 0; i < r1; i++) {
      for (int j = 0; j < c2; j++) {
         for (int k = 0; k < c1; k++) {
            output[i][j] += mat1[i][k] * mat2[k][j];
         }
      }
   }
	
	
	// printing
	for(int i=0; i<r1; i++){
		for(int j=0; j<c2; j++){
			cout<<output[i][j]<<" ";
		}
		cout<<endl;
	}
}


int main(){
	cout<<"----- ANMOL 19BCE0891 -----"<<endl;
	
	// First matrix
	int m,n;
	cout<<"\nEnter rows and cols of 1st matrix : ";
	cin>>m>>n;
	int matrix1[10][10];
	
	// second matrix
	int p,q;
	cout<<"\nEnter rows and cols of 2nd matrix : ";
	cin>>p>>q;
	int matrix2[10][10];
	
	// Checking matrix mul condn
	if(n != p){
		cout<<"\n Matrix multiplication not possible as no. of cols in 1st matrix not equal to no. of rows in 2nd matrix"<<endl;
	}
	else{
		
		// inputing matrices
		cout<<"\n --- ENTER MATRIX 1 --- "<<endl;
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				cin>>matrix1[i][j];
			}
		}
		
		cout<<"\n --- ENTER MATRIX 2 --- "<<endl;
		for(int i=0; i<p; i++){
			for(int j=0; j<q; j++){
				cin>>matrix2[i][j];
			}
		}
		
		cout<<"\n --- OUTPUT MATRIX --- "<<endl;
		
		// passing matrices and printing matrices multiplication
		matrixMul(matrix1, matrix2, m, n, p, q);
	
	}
		
}
