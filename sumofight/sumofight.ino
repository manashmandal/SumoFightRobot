byte incomingByte;   // for incoming serial data
int Speed = 230;

#include <SoftwareSerial.h>

SoftwareSerial bt(50, 51);

const int rightMotor[2] = {9 , 8};
const int leftMotor[2] = {7, 6};
const int backLeftMotor[2] = {3, 2};
const int backRightMotor[2] = {5, 4};

void forward(void)
{
  digitalWrite(rightMotor[0], HIGH);
  digitalWrite(leftMotor[0] , HIGH);
  digitalWrite(backRightMotor[0], HIGH);
  digitalWrite(backLeftMotor[0], HIGH);

  digitalWrite(rightMotor[1], LOW);
  digitalWrite(leftMotor[1] , LOW);
  digitalWrite(backRightMotor[1], LOW);
  digitalWrite(backLeftMotor[1], LOW);
}

void backward(void)
{
  digitalWrite(rightMotor[0], LOW);
  digitalWrite(leftMotor[0] , LOW);
  digitalWrite(backRightMotor[0], LOW);
  digitalWrite(backLeftMotor[0], LOW);

  digitalWrite(rightMotor[1], HIGH);
  digitalWrite(leftMotor[1] , HIGH);
  digitalWrite(backRightMotor[1], HIGH);
  digitalWrite(backLeftMotor[1], HIGH);
  
}

void anticlockwise(void)
{
  digitalWrite(rightMotor[0], HIGH);
  digitalWrite(leftMotor[0] , LOW);
  digitalWrite(backRightMotor[0], HIGH);
  digitalWrite(backLeftMotor[0], LOW);

  digitalWrite(rightMotor[1], LOW);
  digitalWrite(leftMotor[1] , HIGH);
  digitalWrite(backRightMotor[1], LOW);
  digitalWrite(backLeftMotor[1], HIGH);
  
}


void clockwise(void)
{
  digitalWrite(rightMotor[0], LOW);
  digitalWrite(leftMotor[0] , HIGH);
  digitalWrite(backRightMotor[0], LOW);
  digitalWrite(backLeftMotor[0], HIGH);

  digitalWrite(rightMotor[1], HIGH);
  digitalWrite(leftMotor[1] , LOW);
  digitalWrite(backRightMotor[1], HIGH);
  digitalWrite(backLeftMotor[1], LOW);
}

void stop(void)
{
 digitalWrite(rightMotor[0], LOW);
  digitalWrite(leftMotor[0] , LOW);
  digitalWrite(backRightMotor[0], LOW);
  digitalWrite(backLeftMotor[0], LOW);

  digitalWrite(rightMotor[1], LOW);
  digitalWrite(leftMotor[1] , LOW);
  digitalWrite(backRightMotor[1], LOW);
  digitalWrite(backLeftMotor[1], LOW); 
}

void setspeed(byte data)
{
  switch(data){
    
       case 'H':
         Speed = 255;
         break;
       case 'h':
         Speed = 255;
         break;
       case 'M':
         Speed = 220;
         break;
       case 'm':
         Speed = 220;
         break;
       case 'l':
         Speed = 190;
         break;
       case 'L':
         Speed = 190;
         break;

     } 
    
}


void setup() {
    bt.begin(9600);
    Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
     
    for (int i = 0; i < 2; i++){
      pinMode(leftMotor[i], OUTPUT);
      pinMode(rightMotor[i], OUTPUT);
      pinMode(backLeftMotor[i], OUTPUT);
      pinMode(backRightMotor[i], OUTPUT);
  }
}

void loop() {
        // send data only when you receive data:
    if (bt.available() > 0) {
        incomingByte = bt.read();         // read the incoming byte:
       // if (incomingByte > 150 && incomingByte <= 255) Speed = incomingByte.parseInt();
                // say what you got:
                bt.print("I received: ");
                bt.println(incomingByte);
        }
        
    if (incomingByte == 'w' || incomingByte == 'W') forward();
    else if (incomingByte == 's' || incomingByte == 'S') backward();
    else if (incomingByte == 'a' || incomingByte == 'A') anticlockwise();
    else if (incomingByte == 'd' || incomingByte == 'D') clockwise();
    else if (incomingByte == 'H' || incomingByte == 'h' || incomingByte == 'L' || incomingByte == 'l' || incomingByte == 'm' || incomingByte == 'M') setspeed(incomingByte);   
    else stop();    
} 
