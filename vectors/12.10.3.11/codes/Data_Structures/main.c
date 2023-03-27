/*Code by B.Sai Sindhu (works on termux)
March 27, 2023
Link to License("https://github.com/sindhu023/FWC/blob/main/LICENSE")
Show that |a|b+|b|a is perpendicular to  |a|b-|b|a, for any two nonzero vectors a and b.*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "lib.h"

int main()
{
	Node *A = NULL;        //Declaring the node for point A
	Node *B=NULL;        //Declaring the node for point B
	Node *T=NULL;        //Declaring the node for transpose of A
	int m=3,n=1;
	A=loadtxt("data/A.dat",m,n);        //loading the point A from the text file
	B=loadtxt("data/B.dat",m,n);       //loading the point B from the text file 
	T=transpose_matrix(A);         	//Transpose of a Matrix 
	if(matmul(T,B,1,1)->value==0)    //Checking whether perpendicular or not
	{
		printf("perpendicular \n");
	}
	else
	{
		printf("Not perpendicular \n");
	}
	return 0;
}
