#include <AFMotor.h>


#define lefts A4 
#define rights A5 


AF_DCMotor motor1(4, MOTOR12_8KHZ); 
AF_DCMotor motor2(3, MOTOR12_8KHZ);


void setup() {
  
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  pinMode(lefts,INPUT);
  pinMode(rights,INPUT);
  Serial.begin(9600);
  
}

void loop(){
  Serial.println(analogRead(lefts));
  Serial.println(analogRead(rights));
  if(analogRead(lefts)<=400 && analogRead(rights)<=400){
    motor1.run(RELEASE);
    motor2.run(RELEASE);
  }
  //line detected by left sensor
  else if(analogRead(lefts)<=400 && !analogRead(rights)<=400){
    //turn left
    motor1.run(BACKWARD);
    motor2.run(FORWARD);
    
  }
  //line detected by right sensor
  else if(!analogRead(lefts)<=400 && analogRead(rights)<=400){
    //turn right
    motor1.run(FORWARD);
    motor2.run(BACKWARD);
  
  }
  //line detected by none
  else if(!analogRead(lefts)<=400 && !analogRead(rights)<=400){
    //stop
    motor1.run(FORWARD);
    motor2.run(FORWARD);
   
  }
  
}
