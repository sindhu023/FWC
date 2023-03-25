/*Code by B.Sai Sindhu (works on termux)
March 25, 2023
Link to License("https://github.com/sindhu023/FWC/blob/main/LICENSE")

AB is a line segment and P is its mid-point. D and E are points on the same side 
of AB such that ∠ BAD = ∠ ABE and ∠ EPA = ∠ DPB . Show that
(i) ∆ DAP ≅ ∆ EBP
(ii) AD = BE*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "lib.h"
#define PI 3.1415926

int main()
{
	//Declaring Variables
	double **A,**e1,**B,**P,**Q,**D,**E,**a,**q,**d;        //Declaring Variables
	double **m_1,**m_2,**n_1,**n_2,m1,m2,n1,n2;
	double **m1t,**m2t,**n1t,**n2t,dot,dot1;
	double theta,theta1,theta2,angDPB,angEPA;
	int c=8,m=2,n=1,p=1;
	float b=8.2;
	
	//loading text from text file
	A=loadtxt("data/A.dat",2,1);         //loading the point A from the text file	
	e1=loadtxt("data/e1.dat",2,1);        //loading the basis vector from the text file	
	B=mult_int(c,e1,m,n);               //point B
	save(B,m,n,"data/B.dat");      //saving point B to the figure
	a=linalg_add(A, B,m,n);
	P=mult(0.5,a,2,1);               //(A+B)/2
	save(P,m,n,"data/P.dat");     //saving point P to the figure 
	theta=(PI*7)/36;
	q=np_array(cos(PI-theta),sin(PI-theta));
	Q=mult_int(b,q,m,n);         //point Q
	save(Q,m,n,"data/Q.dat");    //saving point Q to the figure
	d=np_array(cos(theta),sin(theta)); 
	D=mult_int(b,d,m,n);         //point D
	save(D,m,n,"data/D.dat");     //saving point D to the figure
	E=linalg_add(B,Q,m,n);      //E=B+Q
	save(E,m,n,"data/E.dat");     //saving point E to the figure

	
	//Directional Vectors
	m_1=linalg_sub(D,P,m,n);
	m_2=linalg_sub(B,P,m,n);
	n_1=linalg_sub(E,P,m,n);
	n_2=linalg_sub(A,P,m,n);
	
	//transpose
	m1t=transpose(m_1,m,n);
	n1t=transpose(n_1,m,n);
	
	//norm of Directional vectors
	m1=linalg_norm(m_1,m);
	m2=linalg_norm(m_2,m);
	n1=linalg_norm(n_1,m);
	n2=linalg_norm(n_2,m);
	
	//Finding angle DPB
	dot=mat_mult(m1t,m_2,1,n,p);
	theta1=dot/(m1*m2);
	angDPB= degrees(acos(theta1));
	printf("angDPB=%lf \n",angDPB);
	
	//Finding angle EPA
	dot1=mat_mult(n1t,n_2,1,n,p);
	theta2=dot1/(n1*n2);
	angEPA= degrees(acos(theta2));
	printf("angEPA=%lf \n",angEPA);
	
	//To prove ∠ EPA = ∠ DPB
	if (angDPB = angEPA)
	{
 		printf("∠ EPA = ∠ DPB ");
 	}
	
	return 0;
}
