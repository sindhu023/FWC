/*Code by B.Sai Sindhu (works on termux)
March 23, 2023
Link to License("https://github.com/sindhu023/FWC/blob/main/LICENSE")
If a=i+j+k,b=2i-j+3k and c=i-2j+k , find a unit vector parallel to the vector 2a-b+3c.*/


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "lib.h"

int main()
{
	double **veca,**vecb,**vecc,**a,**b,**c,**u,mag;                 //Declaring Variables
	double c1,c2,c3,**uv;
	int m=3,n=1;
	veca=loadtxt("data/veca.dat",m,n);	                                    //loading the Vector a from the text file
	vecb=loadtxt("data/vecb.dat",m,n);                                   //loading the Vector b from the text file
	vecc=loadtxt("data/vecc.dat",m,n);                                   //loading the Vector c from the text file
	a=mult_int(2,veca,m,n);                                                     //2a
	c=mult_int(3,vecc,m,n);                                                    //3c
	b=linalg_sub(a,vecb,m,n);                                               //2a-b
	u=linalg_add(b, c,m,n);                                                   //2a-b+c
	mag=linalg_norm(u,m);                                                  //norm of u
	uv=unit_vec(c1,c2,c3,u,mag);                                        //unit vector 
	print(uv,m,n);
	return 0;
}
