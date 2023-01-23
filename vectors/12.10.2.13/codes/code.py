# Define the vector
veca = np.array([1,2,-3])
vecb = np.array([-1,-2,1])
m=np.subtract(vecb,veca)
e1  = np.array([1,0,0])
e2  = np.array([0,1,0])
e3  = np.array([0,0,1])
# Find the magnitude of the vector
mag = np.linalg.norm(m)
a = np.linalg.norm(e1)
b = np.linalg.norm(e2)
c = np.linalg.norm(e3)

# Divide the vector by its magnitude to find the direction cosines
cos1 = ((m.T)@e1) / (mag*a)
cos2 = ((m.T)@e2) / (mag*b)
cos3 = ((m.T)@e3) / (mag*c)

print(cos1,cos2,cos3)
