# 
# christian.jaques@gmail.com
#
# demo code for the use of PyBind with the inclusion of a C module
# check the use of "extern "C"{" in display_array.h
# 
import numpy as np
import wrapper
import cv2

batchImageData = np.zeros((1, 360, 640, 3), dtype=int)
img = cv2.imread('1555.jpg')
batchImageData[0,:,:] = img[:,:]
print batchImageData.shape
wrapper.display(batchImageData)

