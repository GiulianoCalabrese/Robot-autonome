import os
import cv2
import math

##Resize with resize command
def resizeImage(img):
    dst = cv2.resize(img,None, fx=0.25, fy=0.25, interpolation = cv2.INTER_LINEAR)
    return dst

##Take image with Raspberry Pi camera
##os.system("raspistill -o image.jpg")
cap = cv2.VideoCapture(0)
##Load image
#img = cv2.imread("/Users/Supernino90/Documents/hobbyes/robot/traitement_image/detecter_circle/Hough_image2.jpg")
#grey = cv2.imread("/Users/Supernino90/Documents/hobbyes/robot/traitement_image/detecter_circle/Hough_image2.jpg",0)
##Run Threshold on image to make it black and white
#ret, thresh = cv2.threshold(grey,50,255,cv2.THRESH_BINARY)
while 1:
    ret1, img = cap.read()
    grey = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    ret, thresh = cv2.threshold(grey, 50, 255, cv2.THRESH_BINARY)
    ##Use houghcircles to determine centre of circle
    circles = cv2.HoughCircles(thresh,cv2.HOUGH_GRADIENT,1,75,param1=50,param2=13,minRadius=0,maxRadius=175)
    for i in circles[0,:]:
        cv2.circle(img,(i[0],i[1]),i[2],(0,255,0),2)#draw the outer circle
        cv2.circle(img,(i[0],i[1]),2,(0,0,255),3)#draw the centre of the circle
    ##Determine co-ordinates for centre of circle
    x1 = circles[0][0][0]
    y1 = circles[0][0][1]
    x2 = circles[0][1][0]
    y2 = circles[0][1][1]
    theta = math.degrees(math.atan((y2-y1)/(x2-x1)))#Angle betwen two circles
    img = resizeImage(img)#Resize image
    thresh = resizeImage(thresh)
    #Show Images
    #cv2.imshow("thresh",thresh)
    cv2.imshow("img",img)
    k = cv2.waitKey(30) & 0xff
    if k == 27:
        break
    #cv2.waitKey(0)

cv2.destroyAllWindows()