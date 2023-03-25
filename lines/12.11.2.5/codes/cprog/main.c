/*Code by B.Sai Sindhu (works on termux)
March 25, 2023
Link to License("https://github.com/sindhu023/FWC/blob/main/LICENSE")

Find the equation of the line in vector and in cartesian form that passes through
the point with position vector 2 i ˆ − j + 4 k ˆ and is in the direction i ˆ + 2 ˆ j − k ˆ .*/



#include<stdio.h>       
#include<stdlib.h>
#include<math.h>
#include"lib.h"	

int main()
{
	double **A,**m,lambda,**C,**r;       //Declaring Variables
	int M=3,N=1;
	A=loadtxt("data/A.dat",3,1);        //loading the Vector A from the text file
	m=loadtxt("data/m.dat",3,1);     //loading the direction vector m from the text file
	lambda=2;
	C=mult_int(2,m,3,1);        //lambda*m
	r=linalg_add(A, C,3,1);     //A+lambda*m 
	print(r,M,N);
	return 0;
}
