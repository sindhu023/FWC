import matplotlib.pyplot as plt
import numpy as np
import math as ma

P=np.loadtxt('data/P.dat',dtype='float')
X=np.loadtxt('data/X.dat',dtype='float')

def line_gen(A,B):
    len=10
    dim = A.shape[0]
    x_AB = np.zeros((dim,len))
    lam_1 = np.linspace(0,1,len)
    for i in range(len):
        temp1 = A + lam_1[i]*(B-A)
        x_AB[:,i] = temp1.T
    return x_AB
 
 
 #line generation and plotting   
x_PX=line_gen(P,X)
plt.plot(x_PX[0,:],x_PX[1,:],label='$PX$')
sqr_vert = np.vstack((P,X)).T
plt.scatter(sqr_vert[0,:],sqr_vert[1,:])
vert_labels = ['P(1,5)','X(4,3)']
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
