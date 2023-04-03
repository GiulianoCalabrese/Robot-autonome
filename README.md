# Robot-autonome

A video illustration of the code :

https://www.youtube.com/watch?v=KmISzDWKcg0



Here is an autonomous robot that we built. This robot is able to move by detecting obstacles and recognizing images.

For this video we run a python3 code that uses OpenCV to recognize faces.



Hardware:
-Raspberry Pi3 + Pi Camera

-Arduino Mega (Uno would have done the trick too)

-DC motors with encoder + L9110 driver + wheels
http://www.robot-maker.com/forum/topic/11228-driver-l9110-pour-moteur-cc-teste-par-mthibs/
http://www.robot-maker.com/shop/blog/32_Utilisation-des-encodeurs.html

-Analog Polulu sensor :
 http://www.instructables.com/id/How-to-setup-a-Pololu-Carrier-with-Sharp-GP2Y0A60S/

- Breadboard, external rechargeable battery and DIY stand


Lib to install:

-Raspberry Pi3 for image recognition :
https://www.pyimagesearch.com/2016/04/18/install-guide-raspberry-pi-3-raspbian-jessie-opencv-3/

-Communication between raspberry and arduino :
http://electroniqueamateur.blogspot.fr/2014/05/communication-par-usb-entre-raspberry.html

Link :
https://gitlab.com/GiulianoCalabrese/Robot-autonome
- Arduino code
- Raspberry code (Be careful the haarcascade file must be in the same folder as the face_detect.py file)
- instruction to execute the python code in loop when the raspberry is turned on:
1-Go to Rasp console
2-open terminal
3-Type : sudo nano /etc/rc.local
4-Write in the first line the command : python3 /path_to/face_detect.py & 
5-Save with ctrl+o and exit with ctrl+q
6-Turn off and on the raspberry and the python script should run automatically

