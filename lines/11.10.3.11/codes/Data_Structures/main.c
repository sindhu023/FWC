/*Code by B.Sai Sindhu (works on termux)
March 24, 2023
Link to License("https://github.com/sindhu023/FWC/blob/main/LICENSE")
Prove that the line through the point (x 1 , y 1 ) and parallel to the line Ax + By + C = 0 is
A (x –x 1 ) + B (y – y 1 ) = 0.*/

#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"

int main()
{
	Node *P,*X,*m,*n,*O,*nt,*z,*tempm;
	int M=2,N=1;
	P=loadtxt("data/P.dat",2,1);				
	X=loadtxt("data/X.dat",2,1);    
	n=loadtxt("data/n.dat",2,1);
	m=linalg_sub(P,X);
	nt=transpose_matrix(n);
	z=matmul(nt,m,1,1);
	print(z);
	return 0;
}


