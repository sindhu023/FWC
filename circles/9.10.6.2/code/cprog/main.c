/*Code by B.Sai Sindhu (works on termux)
March 26, 2023
Link to License("https://github.com/sindhu023/FWC/blob/main/LICENSE")

Two chords AB and CD of lengths 5 cm and 11 cm respectively of a circle are parallel
to each other and are on opposite sides of its centre. If the distance between AB and
CD is 6 cm, find the radius of the circle.*/


#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "lib.h"
#define PI 3.14159265359

int main()
{
	 //Declaring variables
	double **O,theta1,theta2,theta3,theta4,r;      
	double **A,**B,**C,**D,**a,**b,**c,**d;
	int m=2,n=1;
	O=loadtxt("data/O.dat",2,1);            //loading the point O from the text file	
	theta1=0;            //Input parameters
	theta2=PI/2;
	theta3=3*PI/2;
	theta4=PI;
	r=6/sqrt(2);
	printf("radius=%lf \n",r);
	a=np_array(cos(theta1),sin(theta1));       //a=(cos(0),sin(0))
	b=np_array(cos(theta2),sin(theta2));      //b=(cos(90),sin(90))
	c=np_array(cos(theta3),sin(theta3));      //c=(cos(270),sin(270))
	d=np_array(cos(theta4),sin(theta4));     //d=(cos(180),sin(180))
	
	//Defining points
	A=mult_int(r,a,m,n);          
	save(A,m,n,"data/A.dat");         //saving point A to the figure
	B=mult_int(r,b,m,n);
	save(B,m,n,"data/B.dat");        //saving point B to the figure
	C=mult_int(r,c,m,n);
	save(C,m,n,"data/C.dat");       //saving point C to the figure
	D=mult_int(r,d,m,n);
	save(D,m,n,"data/D.dat");       //saving point D to the figure
	return 0;
}
