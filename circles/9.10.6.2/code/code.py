import math as ma
import numpy as np
import mpmath as mp
import math
import matplotlib.pyplot as plt
from numpy import linalg as LA


def circ_gen(O,r):
    len = 50
    theta = np.linspace(0,2*np.pi,len)
    x_circ = np.zeros((2,len))
    x_circ[0,:] = r*np.cos(theta)
    x_circ[1,:] = r*np.sin(theta)
    x_circ = (x_circ.T + O).T
    return x_circ

def line_gen(A,B):
  len =10
  dim = A.shape[0]
  x_AB = np.zeros((dim,len))
  lam_1 = np.linspace(0,1,len)
  for i in range(len):
    temp1 = A + lam_1[i]*(B-A)
    x_AB[:,i]= temp1.T
  return x_AB
 

#input parameters
O=np.array([0,0])
theta1=0
theta2=np.pi/2
theta3=3*np.pi/2
theta4=np.pi
r=6/np.sqrt(2)
A=r*np.array([np.cos(theta1),np.sin(theta1)])
B=r*np.array([np.cos(theta2),np.sin(theta2)])
C=r*np.array([np.cos(theta3),np.sin(theta3)])
D=r*np.array([np.cos(theta4),np.sin(theta4)])

#Generating all lines
x_CD= line_gen(C,D)
x_AB= line_gen(A,B)
x_AC= line_gen(A,C)


#Plotting all lines
plt.plot(x_CD[0,:],x_CD[1,:],label='CD')
plt.plot(x_AB[0,:],x_AB[1,:],label='AB')
plt.plot(x_AC[0,:],x_AC[1,:],label="AC")

AC=np.linalg.norm(A-C)
print("distance between AB and CD is",AC)

#generating circle
s_circ= circ_gen(O,r)
plt.plot(s_circ[0,:],s_circ[1,:],label='$Circle$')
print("Raduis is :",round(r,2))




#Labeling the coordinates
tri_coords =np.vstack((C,D,O,A,B)).T

plt.scatter(tri_coords[0,:],tri_coords[1,:])
vert_labels = ['C','D','O','A','B']
for i,txt in enumerate(vert_labels):
	plt.annotate(txt,
			(tri_coords[0,i],tri_coords[1,i]),
			textcoords="offset points",
			xytext=(0,10),
			ha='center')

plt.xlabel('$X$')
plt.ylabel('$Y$')
plt.legend(loc='best')
plt.grid()
plt.axis('equal')
plt.savefig('/sdcard/Download/codes/circles/9.10.6.2/figs/fig.png')
plt.show()
