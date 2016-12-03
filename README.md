## Smart Surveillance System

LinkIt Smart 7688 Duo + PIR Motion Sensor + Web Cam

![Project Illustration](http://www.lambmobistudio.com/imgs/iot-project-illustration.png)

Workflow:

1. PIR detects suspicious object movement
2. MCU sends a signal to MPU through serial port
3. MPU receives the signal and does the following two things
  1. Takes a picture using Webcam
  2. Send the picture to MCS (Mediatek Cloud Sandbox)
