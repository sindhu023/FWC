import matplotlib.pyplot as plt
import numpy as np
import math as ma

O=np.loadtxt('data/O.dat',dtype='float')
A=np.loadtxt('data/A.dat',dtype='float')
B=np.loadtxt('data/B.dat',dtype='float')
P=np.loadtxt('data/P.dat',dtype='float')

def line_gen(A,B):
    len=10
    dim = A.shape[0]
    x_AB = np.zeros((dim,len))
    lam_1 = np.linspace(0,1,len)
    for i in range(len):
        temp1 = A + lam_1[i]*(B-A)
        x_AB[:,i] = temp1.T
    return x_AB
    
x_PO=line_gen(P,O)
x_AB=line_gen(A,B)
#plotting lines
plt.plot(x_AB[0,:],x_AB[1,:],label='(1 1)x=1')
plt.plot(x_PO[0,:],x_PO[1,:],label='$PO$')
#Labeling the coordinates
sqr_vert = np.vstack((A,B,P,O)).T
plt.scatter(sqr_vert[0,:],sqr_vert[1,:])
vert_labels = ['A','B','P','O(0,0)']

for i, txt in enumerate(vert_labels):
    plt.annotate(txt,
            (sqr_vert[0,i], sqr_vert[1,i]),
            textcoords = 'offset points',
            xytext = (0,10),
            ha='center')

plt.xlabel('x', color='#1C2833')
plt.ylabel('y', color='#1C2833')
plt.legend(loc='upper right')  
plt.grid()                                      
plt.axis('equal')
plt.show()
