import numpy as np
A=np.array([0,2,3])
B=np.array([4,3,-2])
#finding A.B
if (A.T@B)==0:
  print("perpendicular")
else:
  print("not perpendicular")
