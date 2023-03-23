/*Code by B.Sai Sindhu (works on termux)
March 23, 2023
LInk to License("https://github.com/sindhu023/FWC/blob/main/LICENSE")
Find the direction cosines of the vector joining the points A (1, 2, –3) and
B(–1, –2, 1), directed from A to B.*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "lib.h"
#define PI 


int main()
{
	double **veca,**vecb,**m,mag;
	double cos1,cos2,cos3;
	veca=loadtxt("data/veca.dat",3,1);
	vecb=loadtxt("data/vecb.dat",3,1);
	m=linalg_sub(vecb, veca, 3, 1);
	mag=linalg_norm(m, 3);
	cos1=m[0][0]/mag;
	cos2=m[1][0]/mag;
	cos3=m[2][0]/mag;
	printf("cos1=%lf \n", cos1);
	printf("cos2=%lf \n", cos2);
	printf("cos3=%lf \n", cos3);
	return 0;
}
