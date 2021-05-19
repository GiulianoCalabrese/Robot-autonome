from picamera.array import PiRGBArray
from picamera import PiCamera
import time
import cv2
import sys
import imutils
import numpy as np
import serial

ser = serial.Serial('/dev/ttyUSB0', 9600)

# Get user supplied values
cascPath = '/home/pi/Desktop/robot/raspberry/face_detect/haarcascade_frontalface_default.xml'
#cascPath = sys.argv[1]

# Create the haar cascade
faceCascade = cv2.CascadeClassifier(cascPath)

# initialize the camera and grab a reference to the raw camera capture
camera = PiCamera()
camera.resolution = (160, 120)
camera.framerate = 32
camera.hflip = True
camera.vflip = True
rawCapture = PiRGBArray(camera, size=(160, 120))

# allow the camera to warmup
time.sleep(0.1)
lastTime = time.time()*1000.0
# capture frames from the camera
for frame in camera.capture_continuous(rawCapture, format="bgr", use_video_port=True):
	# grab the raw NumPy array representing the image, then initialize the timestamp
	# and occupied/unoccupied text
    image = frame.array
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    
    # Detect faces in the image
    faces = faceCascade.detectMultiScale(
    gray,
    scaleFactor=1.1,
    minNeighbors=5,
    minSize=(30, 30),
    flags = 0
    )
    #print (time.time()*1000.0-lastTime," Found {0} faces!".format(len(faces)))
    label = len(faces)
    ser.write(str(label).encode())
    lastTime = time.time()*1000.0
    # Draw a rectangle around the faces
    #for (x, y, w, h) in faces:
     #   cv2.circle(image, (int(x+w/2), int(y+h/2)), int((w+h)/3), (255, 255, 255), 1)
    # show the frame
    #cv2.imshow("Frame", image)
    #key = cv2.waitKey(1) & 0xFF
 
	# clear the stream in preparation for the next frame
    rawCapture.truncate(0)
    
	# if the `q` key was pressed, break from the loop
    #if key == ord("q"):
     #   break
        
  
        

