//EXAMPLE OF SERVO WITH ROS.
// do
// roscore &
// for raspberry pi : rosrun rosserial_python serial_node.py /dev/ttyUSB0 &
// or for windows on COM4 : rosrun rosserial_python serial_node.py /dev/ttyS4 & 
// rostopic pub servo std_msgs/UInt16 0 --once
//  rostopic pub servo std_msgs/UInt16 180 --once


// NOTE : WINDOWS 10 with ubuntu 16.04 as subsystem, after ros install do this :
//      sudo apt-get install ros-kinetic-rosserial-windows
//     sudo apt-get install ros-kinetic-rosserial-server
// chmod 666 /dev/ttyS4 if COM4

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include <WProgram.h>
#endif
#include <ZServo.h> 
#include <Servo.h> 
#include <ros.h>

ros::NodeHandle  nh;
ZServo servoA;

int pin=9;// digital  9
void setup() {
  nh.initNode();
  servoA.setup(&nh,"servo",pin);
}
void loopnh() {
  
  servoA.loop();

  nh.spinOnce();
}
void loop()
{// put your main code here, to run repeatedly:
  loopnh();
}
