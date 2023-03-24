/*Code by B.Sai Sindhu (works on termux)
March 24, 2023
Link to License("https://github.com/sindhu023/FWC/blob/main/LICENSE")

Find perpendicular distance from the origin to the line joining the points (cosθ, sin θ)
and (cos φ, sin φ).*/


#include<stdio.h>       
#include<stdlib.h>
#include<math.h>
#include"lib.h"	
#define pi 3.141592654

int main()
{
	double **A,**B,d,**P,**O,theta,phi;       //Declaring Variables
	int m=2,n=1;
	O=loadtxt("data/O.dat",2,1);         //loading the point O from the text file	
	theta=0;
	A=np_array(cos(theta),sin(theta));   //point A
	save(A,m,n,"data/A.dat");          //saving point A to the figure
	phi=pi/2;
	B=np_array(cos(phi),sin(phi));       //point B
	save(B,m,n,"data/B.dat");        //saving point B to the figure
	d=sin(pi/2)/(2*(sin(pi/4)));     //perpendicular distance from origin
	printf("Perpendicular distance=%f \n",d);    
	P=np_array(d*cos(pi/4),d*sin(pi/4));     //point P on line AB
	save(P,m,n,"data/P.dat");         //saving point P to the figure
	return 0;
}
