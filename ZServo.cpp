/*
	ZServo

	Arduino library for Servo
	Author :
	Pierre Valleau
	history :
		add ros supports


*/


#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include <WProgram.h>
#endif
//#include "WMath.h"
#include "ZServo.h"
#ifdef ROS_USED 

	#define ZSERVO_MAX 12
	ZServo * myservo[ZSERVO_MAX]={0,0,0,0,0,0,0,0,0,0,0,0};

#endif
static char nbzservo=-1;
ZServo::ZServo() 
{
	index=nbzservo++;
	#ifdef ROS_USED 
		myservo[index]=this;	
	#endif
}


// attach the given pin to the next free channel, sets pinMode, returns channel number or 0 if failure
 uint8_t ZServo::attach(int pin)
 {
	 
	// nh->subscribe(*subscriber);
	 return servo.attach(pin);
 }
 
  uint8_t ZServo::attach(int pin, int min, int max) // as above but also sets min and max values for writes. 
  {  	

	//   nh->subscribe(*subscriber);
	   return servo.attach(pin,min,max);

  }  
  void ZServo::detach()
  {
	  servo.detach(); 
  //    subscriber->shutdown();
  }  
  void ZServo::write(int value)             // if value is < 200 its treated as an angle, otherwise as pulse width in microseconds 
  {
	 servo.write(value);  
  }  
  
  void ZServo::writeMicroseconds(int value) // Write pulse width in microseconds 
  {
	  servo.writeMicroseconds(value);  
  }  
  
  int ZServo::read()                        // returns current pulse width as an angle between 0 and 180 degrees
  {
	 return servo.read();   
  }  
  
  int ZServo::readMicroseconds()            // returns current pulse width in microseconds for this servo (was read_us() in first release)
  {
	 return servo.readMicroseconds();   
  }  
   // return true if this servo is attached, otherwise false 
  bool ZServo::attached()
  {
	  return servo.attached();  
  }
  
#ifdef ROS_USED 


static void callbackinstance0( const std_msgs::UInt16& cmd_msg)
{	if (myservo[0]!=0)
myservo[0]->write(cmd_msg.data); //set servo angle, should be from 0-180   
}
static void callbackinstance1( const std_msgs::UInt16& cmd_msg)
{	if (myservo[1]!=0)
myservo[1]->write(cmd_msg.data); //set servo angle, should be from 0-180   
}
static void callbackinstance2( const std_msgs::UInt16& cmd_msg)
{	if (myservo[2]!=0)
myservo[2]->write(cmd_msg.data); //set servo angle, should be from 0-180   
}
static void callbackinstance3( const std_msgs::UInt16& cmd_msg)
{	if (myservo[3]!=0)
myservo[3]->write(cmd_msg.data); //set servo angle, should be from 0-180   
}

static void callbackinstance4( const std_msgs::UInt16& cmd_msg)
{	
if (myservo[4]!=0)
	myservo[4]->write(cmd_msg.data); //set servo angle, should be from 0-180   
}
static void callbackinstance5( const std_msgs::UInt16& cmd_msg)
{	
if (myservo[5]!=0)
	myservo[5]->write(cmd_msg.data); //set servo angle, should be from 0-180   
}
static void callbackinstance6( const std_msgs::UInt16& cmd_msg)
{	
if (myservo[6]!=0)
	myservo[6]->write(cmd_msg.data); //set servo angle, should be from 0-180   
}
static void callbackinstance7( const std_msgs::UInt16& cmd_msg)
{	
if (myservo[7]!=0)
	myservo[7]->write(cmd_msg.data); //set servo angle, should be from 0-180   
}
static void callbackinstance8( const std_msgs::UInt16& cmd_msg)
{	
if (myservo[8]!=0)
	myservo[8]->write(cmd_msg.data); //set servo angle, should be from 0-180   
}
static void callbackinstance9( const std_msgs::UInt16& cmd_msg)
{	
if (myservo[9]!=0)
	myservo[9]->write(cmd_msg.data); //set servo angle, should be from 0-180   
}
static void callbackinstance10( const std_msgs::UInt16& cmd_msg)
{	
if (myservo[10]!=0)
	myservo[10]->write(cmd_msg.data); //set servo angle, should be from 0-180   
}
static void callbackinstance11( const std_msgs::UInt16& cmd_msg)
{	
if (myservo[11]!=0)
	myservo[11]->write(cmd_msg.data); //set servo angle, should be from 0-180   
}

void(*callback[ZSERVO_MAX])(const std_msgs::UInt16& cmd_msg)={
	callbackinstance0,callbackinstance1,callbackinstance2,callbackinstance3,
	callbackinstance4,callbackinstance5,callbackinstance6,callbackinstance7,
	callbackinstance8,callbackinstance9,callbackinstance10,callbackinstance11	};

void ZServo::setup( ros::NodeHandle * myNodeHandle,	const char   *	topic ,int pin)
{
  nh=myNodeHandle;
  subscriber=new ros::Subscriber<std_msgs::UInt16> (topic, callback[this->index]); 
  attach( pin);
  nh->subscribe(*subscriber);   
}
// ROS SECTION :
//char frameid[] = "/ir_ranger";
/** setup :
  At setup after NodeHandle setup, call this to initialise the topic
*/
void ZServo::setup( ros::NodeHandle * myNodeHandle,	const char   *	topic ,void callbackinstance( const std_msgs::UInt16& cmd_msg),int pin)
{
  nh=myNodeHandle;
  subscriber=new ros::Subscriber<std_msgs::UInt16> (topic, callbackinstance); 
  attach( pin);
  nh->subscribe(*subscriber);   
}
/** loop :
  on loop  before NodeHandle refresh(spinOnce), call this to update the topic
*/
void ZServo::loop()
{
	//nothing to do just keep for compatibility with others.
}
#endif 

