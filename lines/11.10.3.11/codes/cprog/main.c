/*Code by B.Sai Sindhu (works on termux)
March 24, 2023
Link to License("https://github.com/sindhu023/FWC/blob/main/LICENSE")

Prove that the line through the point (x 1 , y 1 ) and parallel to the line Ax + By + C = 0 is
A (x –x 1 ) + B (y – y 1 ) = 0.*/



#include<stdio.h>       
#include<stdlib.h>
#include<math.h>
#include"lib.h"

int main()
{		
	double **P,**X,**m,**n,z,**O,**nt;      //Declaring Variables
	int M=2,N=1;					
	P=loadtxt("data/P.dat",2,1);	     //loading the Vector P from the text file				
	X=loadtxt("data/X.dat",2,1);    //loading the Vector X from the text file	
	O=loadtxt("data/O.dat",2,2);    //loading the Omat from the text file	
	m=linalg_sub(P,X,M,N);        //Directional vector 
	n=matmul(O,m,M,2,1);	        //normal vector
	nt=transpose(n,2,1);
	z=mat_mult(nt,m,1,2,1);					 
	printf("z=%lf \n",z);
	return 0;
}
