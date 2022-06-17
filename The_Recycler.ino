// Include the Arduino Stepper Library
#include <Stepper.h>

// Number of steps per output rotation
const int stepsPerRevolution = 1000;

// Create Instance of Stepper library
Stepper myStepper1(stepsPerRevolution,4, 5, 6, 7); //Sweepr
Stepper myStepper2(stepsPerRevolution,8, 9, 10, 11); //Shelach_forward
Stepper myStepper3(stepsPerRevolution,8, 9, 10, 11);  //Shelach_forward
Stepper myStepper4(stepsPerRevolution,8, 9, 10, 11);//Shelach_backword
Stepper myStepper5(stepsPerRevolution,4, 5, 6, 7); //Sweepr
int i=0,Step1=5,Step2=1,Step3=3,Step4=4,Step5=5,j=0,k;

const int trigPin = A1;
void stepper1();
void stepper2();
void stepper3();
void stepper4();
void stepper5();
void sensor_down();
void distance_meas_down(int k);
void sensor_up();
void sensor_stop();
const int echoPin = A0;
// defines variables
long duration=0;
int distance=0;
void setup()
{  // set the speed at 60 rpm:
  myStepper1.setSpeed(60);
  myStepper2.setSpeed(60);
  myStepper3.setSpeed(60);
  myStepper4.setSpeed(60);
  myStepper5.setSpeed(60);
  pinMode(A2,INPUT);//omron
 pinMode(A4,OUTPUT);//DIR PIN
 pinMode(A5,OUTPUT);//PWM PIN
 pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
 pinMode(echoPin, INPUT);
   
}

void loop()
{
  
  if(digitalRead(A2)==1)
   {
    
   //stepper1();
    i=0;
   //stepper2();
    i=0;  
   stepper3(); 
    i=0;
   //stepper4();
    i=0;
 
  sensor_down();
  distance_meas_down(24);
  sensor_up();
  delay(12000);
  sensor_stop();
  stepper5(); 
 
  }

}

//STEP1
void stepper1()
   {
   
    while(i<Step1)
    {
  myStepper1.step(-1000); 
  i++;
  }
   }
   
//STEP2
void stepper2()
   {
   
    while(i<Step2)
    {
  myStepper2.step(1000); 
  i++;
  }
   }
 
 void stepper3()
   {
   
    while(i<Step3)
    {
  myStepper3.step(1000); 
  i++;
  }
   }

  void stepper4()
   {
   
    while(i<Step4)
    {
  myStepper3.step(1000); 
  i++;
  }
   }

 void stepper5()
   {
   
    while(i<Step5)
    {
  myStepper1.step(1000); 
  i++;
  }
   }

 void sensor_down()
{
 
  digitalWrite(A4,HIGH);
  digitalWrite(A5,HIGH);
 }

   void sensor_up()
{
 
  digitalWrite(A4,LOW);
  digitalWrite(A5,HIGH);
 }
 
  
  void sensor_stop()
  {
  digitalWrite(A4,LOW);
  digitalWrite(A5,LOW);
   }

   void distance_meas_down(int k)
  {
    distance=0;
    while(distance<=k)
    {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
    }
   }

   
   void distance_meas_up(int j)
   {
    distance=0;
    while(distance>=j)
    {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
    }
   }
