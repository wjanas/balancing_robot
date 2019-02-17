import cv2
import numpy as np
import sys
import colorsys
from matplotlib import colors
import time
import sched

def f(x): pass

def timer(savedTime):
    if time.localtime()[5] != savedTime:
        return 1
    else:
        return 0

def getAngle(position):
    calculatedAngle = 0.09375 *position -30
    return calculatedAngle


cv2.namedWindow('Trackbars')
cv2.resizeWindow('Trackbars',400,400)
cv2.createTrackbar('H_lower','Trackbars',0,255, f)
cv2.createTrackbar('S_lower','Trackbars',0,255, f)
cv2.createTrackbar('V_lower','Trackbars',0,255, f)
cv2.createTrackbar('H_upper','Trackbars',0,255, f)
cv2.createTrackbar('S_upper','Trackbars',0,255, f)
cv2.createTrackbar('V_upper','Trackbars',0,255, f)
cv2.setTrackbarPos('H_lower','Trackbars', 40)
cv2.setTrackbarPos('S_lower','Trackbars', 50)
cv2.setTrackbarPos('V_lower','Trackbars', 30)
cv2.setTrackbarPos('H_upper','Trackbars', 70)
cv2.setTrackbarPos('S_upper','Trackbars', 255)
cv2.setTrackbarPos('V_upper','Trackbars', 255)

vc = cv2.VideoCapture(0)
if vc.isOpened(): # try to get the first frame
    isOpened, frame = vc.read()
else:
    isOpened = False

current_time = time.localtime()[5]
objectPosition = 320
angle = 0
while isOpened:
    isOpened, frame = vc.read()
    #frame = cv2.GaussianBlur(frame,(9,9),5)

    lower_H = cv2.getTrackbarPos('H_lower', 'Trackbars')
    lower_S = cv2.getTrackbarPos('S_lower', 'Trackbars')
    lower_V = cv2.getTrackbarPos('V_lower', 'Trackbars')
    upper_H = cv2.getTrackbarPos('H_upper', 'Trackbars')
    upper_S = cv2.getTrackbarPos('S_upper', 'Trackbars')
    upper_V = cv2.getTrackbarPos('V_upper', 'Trackbars')

    lower_blue = np.array([lower_H, lower_S, lower_V])
    upper_blue = np.array([upper_H,upper_S,upper_V])

    hsvImg = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    mask = cv2.inRange(hsvImg,lower_blue,upper_blue)
    mask = cv2.GaussianBlur(mask,(11,11),0)

    circles = cv2.HoughCircles(mask, cv2.HOUGH_GRADIENT, dp= 1 ,minDist= 500, param1= 50, param2= 20, minRadius= 10, maxRadius= 600)
    if circles is not None:
        for circle in circles[0, :]:
            circleImage = cv2.circle(frame, (circle[0], circle[1]), circle[2], (0,0,255), thickness= 3)
            circleCenter = cv2.circle(frame, (circle[0], circle[1]), 3, (0, 0, 255), thickness=5)
            objectPosition = circle[0]
    colorImage = cv2.cvtColor(mask,cv2.COLOR_GRAY2BGR)
    cv2.imshow("Camera", frame)
    cv2.imshow("Mask", colorImage)

    if timer(current_time):
        angle = getAngle(objectPosition)
        current_time = time.localtime()[5]
        #print objectPosition
        print time.localtime()[5], angle
    key = cv2.waitKey(20)
    if key == 27:  # exit on ESC
        break
vc.release()
cv2.destroyAllWindows()