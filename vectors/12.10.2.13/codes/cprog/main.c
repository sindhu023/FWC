/*Code by B.Sai Sindhu (works on termux)
March 23, 2023
Link to License("https://github.com/sindhu023/FWC/blob/main/LICENSE")
Find the direction cosines of the vector joining the points A (1, 2, –3) and
B(–1, –2, 1), directed from A to B.*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "lib.h"   

int main()
{
	double **veca,**vecb,**m,mag,**u,c1,c2,c3;   //Declaring Variables
	int M=3,N=1;
	veca=loadtxt("data/veca.dat",3,1);               //loading the Vector A from the text file
	vecb=loadtxt("data/vecb.dat",3,1);              //loading the Vector B from the text file
	m=linalg_sub(vecb, veca, 3, 1);					//Direction vector m
	mag=linalg_norm(m, 3);								//norm of m
	u=unit_vec(c1,c2,c3,m,mag);						//unit vector
	print(u,M,N);
	return 0;
}
