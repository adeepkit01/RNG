import numpy as np
import cv2
import sys
import os

f = open('/dev/null', 'w')
sys.stdout = f
sys.stderr = f
"""Program to take a snapshot from the webcam"""

cap = cv2.VideoCapture(0) # video capture source camera (Here webcam of laptop) 
ret,frame = cap.read() # return a single frame in variable `frame`

while(True):
    cv2.imshow('img1',frame) #display the captured image
    cv2.imwrite('image.png',frame) 
    cv2.destroyAllWindows()
    break

cap.release()
