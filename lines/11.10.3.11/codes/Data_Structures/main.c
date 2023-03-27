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
	Node *P,*X,*m,*n,*O,*nt,*z,*tempm;    //declaring variables
	int M=2,N=1;
	P=loadtxt("data/P.dat",2,1);	     //loading the Vector P from the text file	
	X=loadtxt("data/X.dat",2,1);    //loading the Vector X from the text file	   
	n=loadtxt("data/n.dat",2,1);    //loading the normal Vector from the text file	
	m=linalg_sub(P,X);       //Directional Vector
	nt=transpose_matrix(n);      //transpose of normal vector
	z=matmul(nt,m,1,1);         // multiplication of  two matrices
	print(z);
	return 0;
}


