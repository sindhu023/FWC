/*Code by B.Sai Sindhu (works on termux)
March 23, 2023
Link to License("https://github.com/sindhu023/FWC/blob/main/LICENSE")
Show that |a|b+|b|a is perpendicular to  |a|b-|b|a, for any two nonzero vectors a and b.*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "lib.h"

int main()
{
	double **A,**B,**T,mat;                      //Declaring Variables
	A=loadtxt("data/A.dat",3,1);              //loading the Vector A from the text file
	B=loadtxt("data/B.dat",3,1);             //loading the Vector B from the text file
	T=transpose(A,3,1);                           //Transpose of A
	mat=mat_mult(T,B,1,3,3);                  //matrix multiplication
	printf("AT.B=%lf \n",mat);
	if (mat==0)
	{
		printf("perpendicular \n");
	}
	else
	{
		printf("not perpendicular \n");
	}
	return 0;
}

