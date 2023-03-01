import numpy as np
import matplotlib.pyplot as plt
import math

def line_gen(A,B):
    len=10
    dim = A.shape[0]
    x_AB = np.zeros((dim,len))
    lam_1 = np.linspace(0,1,len)
    for i in range(len):
        temp1 = A + lam_1[i]*(B-A)
        x_AB[:,i] = temp1.T
    return x_AB

#To construct triangle APD and BPE
r=4
b=5.43
theta=np.pi/3
theta1=np.pi*2/3
A=np.array([-r,0])
B=np.array([r,0])
P=(A+B)/2
D=b*np.array(([np.cos(theta),np.sin(theta)]))
E=b*np.array(([np.cos(theta1),np.sin(theta1)]))

m_1 = P-D
m_2 = P-A
n_1 = P-E
n_2 = P-B
m_3 = A-D
m_4 = A-P
n_3 = B-E
n_4 = B-A

m1 = np.linalg.norm(m_1)
m2 = np.linalg.norm(m_2)
n1 = np.linalg.norm(n_1)
n2 = np.linalg.norm(n_2)
m3 = np.linalg.norm(m_3)
m4 = np.linalg.norm(m_4)
n3 = np.linalg.norm(n_3)
n4 = np.linalg.norm(n_4)

angDPA=np.degrees(np.arccos(np.dot(m_1,m_2)/(m1*m2)))
angEPB=np.degrees(np.arccos(np.dot(n_1,n_2)/(n1*n2)))
angDAP=np.degrees(np.arccos(np.dot(m_3,m_4)/(m3*m4)))
angEBP=np.degrees(np.arccos(np.dot(n_3,n_4)/(n3*n4)))
l1 = np.linalg.norm(A-D)
l2 = np.linalg.norm(B-E)
l3 = np.linalg.norm(A-P)
l4 = np.linalg.norm(P-B)
if (l1.all()==l2.all()) and (l3.all()==l4.all()) and (round(angDPA) == round(angEPB)) and (round(angDAP) == round(angEBP)):
  print("(i) ∆ DAP ≅ ∆ EBP")
  print(" (ii) AD = BE")
   
#Generating lines
x_AP = line_gen(A,P)
x_PD = line_gen(P,D)
x_AD = line_gen(A,D)
x_PE = line_gen(P,E)
x_BE = line_gen(B,E)
x_BP = line_gen(B,P)


#Plotting all lines
plt.plot(x_AP[0,:],x_AP[1,:],label='$AP$')
plt.plot(x_PD[0,:],x_PD[1,:],label='$PD$')
plt.plot(x_AD[0,:],x_AD[1,:],label='$AD$')
plt.plot(x_PE[0,:],x_PE[1,:],label='$PE$')
plt.plot(x_BE[0,:],x_BE[1,:],label='$BE$')
plt.plot(x_BP[0,:],x_BP[1,:],label='$BP$')
#Labeling the coordinates
tri_coords = np.vstack((A,B,P,D,E)).T
plt.scatter(tri_coords[0,:], tri_coords[1,:])
vert_labels = ['A','B','P','D','E']
for i, txt in enumerate(vert_labels):
    plt.annotate(txt, # this is the text
                 (tri_coords[0,i], tri_coords[1,i]), # this is the point to label
                 textcoords="offset points", # how to position the text
                 xytext=(0,10), # distance from text to points (x,y)
                 ha='center') # horizontal alignment can be left, right or center
plt.xlabel('$xaxis$')
plt.ylabel('$yaxis$')
plt.legend(loc='best')
plt.grid() # minor
plt.axis('equal')
plt.savefig('/sdcard/Download/codes/lines/9.7.1.7/figs/fig.png')
plt.show()
