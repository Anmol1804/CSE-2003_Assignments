#include<iostream>
#include<math.h>
using namespace std;

/*
	formula ->  inv(A) = adjoint(A)/det(A);  det(A) != 0
*/

//finding determinant of matrix
float determinant(float a[25][25], int k){
	float s = 1, det = 0, b[25][25];
	int i, j, m, n, c;
	
	if (k == 1){
	    return (a[0][0]);
	}
	
	else{
    	det = 0;
    	for (c = 0; c < k; c++){
        	m = 0;
        	n = 0;
        	for (i = 0;i < k; i++){
            	for (j = 0 ;j < k; j++){
                	b[i][j] = 0;
                	
                	if (i != 0 && j != c){
                   		b[m][n] = a[i][j];
                   		
                   		if (n < (k - 2))
                    		n++;
                   		else{
                     		n = 0;
                     		m++;
                     	}
                   }
               }
            }
            
        	det = det + s * (a[0][c] * determinant(b, k - 1));
          	s = -1 * s;
          }
    }
 
    return det;
}


//transpose of matrix
void transpose(float num[25][25], float fac[25][25], int r){
  	int i, j;
  	float b[25][25], inverse[25][25], d;
 
  	for (i = 0;i < r; i++){
     	for (j = 0;j < r; j++){
         	b[i][j] = fac[j][i];
        }
    }
    
  	d = determinant(num, r);
	for (i = 0;i < r; i++){
     	for (j = 0;j < r; j++){
        	inverse[i][j] = b[i][j] / d;
        }
    }
   	cout<<"\n The inverse of matrix is : "<<endl;
 
   	for (i = 0;i < r; i++){
     	for (j = 0;j < r; j++){
         	cout<<inverse[i][j]<<" ";
        }
    	cout<<endl;
    }
}


//cofactor of matrix
void cofactor(float num[25][25], int f){

	float b[25][25], fac[25][25];
 	int p, q, m, n, i, j;
 	for (q = 0;q < f; q++){
   		for (p = 0;p < f; p++){
     		m = 0;
     		n = 0;
     		for (i = 0;i < f; i++){
       			for (j = 0;j < f; j++){
          			if (i != q && j != p){
            			b[m][n] = num[i][j];
            			
            			if (n < (f - 2)){
             				n++;
             			}
            			else{
               				n = 0;
               				m++;
               			}
            		}
        		}
      		}
      	
      		fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
    	}
  	}
  	transpose(num, fac, f);
}


int main(){
	cout<<"--- ANMOL 19BCE0891 --- "<<endl;

	int k;
 	float a[25][25], d;
  	int i, j;
  	cout<<"Enter the order of the Matrix : ";
  	cin>>k;
  	cout<<"Enter elements of "<<k<<"X"<<k<<" of matrix"<<endl;
  	for (i = 0;i < k; i++){
     	for (j = 0;j < k; j++){
        	cin>>a[i][j];
        }
    }
    
  	d = determinant(a, k);
  	if (d == 0)
   		printf("\nInverse of Entered Matrix is not possible\n");
  	else
   		cofactor(a, k);
}

