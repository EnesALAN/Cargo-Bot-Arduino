
                          
/*
 * Author:Enes ALAN
 * 
 * Last Modified Date:25.03.2017
 * 
 * Pin description and controlling robotic arm with using keyboard commands
 * Digital and Analog Pin Numbers can change if i attach wires another pins.
 */

#include <SPI.h>
#include <TFT.h>            // Arduino TFT library

#define cs   10
#define dc   9
#define rst  8

TFT screen = TFT(cs, dc, rst);


int baseMotorEnablePin = 2;
int baseMotorPin1 = 3;                             
int baseMotorPin2 = 4;                           
int upperRightMotorEnablePin = 14;
int upperRightMotorPin1 = 15;   
int upperRightMotorPin2 = 16; 
int leftMotorEnablePin = 8;
int leftMotorPin1 = 9;                             
int leftMotorPin2 = 10;                           

int clampMotorEnablePin = 11;
int clampMotorPin1 = 17;                             
int clampMotorPin2 = 18; 

int incomingByte;//sending byte for the port

void setup() {
 screen.begin();

  // make the background black
  screen.background(0,0,0);

  // set the stroke color to white
  screen.stroke(255,255,255);

  // set the fill color to grey
  screen.fill(127,127,127);

  // draw a circle in the center of screen
  screen.circle(screen.width()/2, screen.height()/2, 10);
/*int boxSize = 64;
arrow myRightArrow;
int rightArrowxpoints[7]={30,54,30,30,0,0,30}; 
int rightArrowypoints[7]={0,27,54,40,40,15,15};

int leftArrowxpoints[7]={0,24,24,54,54,24,24}; 
int leftArrowypoints[7]={27,0,15,15,40,40,54};*/
  pinMode(baseMotorPin1, OUTPUT);
  pinMode(baseMotorPin2, OUTPUT);
  pinMode(baseMotorEnablePin, OUTPUT);
  digitalWrite(baseMotorEnablePin, HIGH);
  
  pinMode(upperRightMotorPin1, OUTPUT);
  pinMode(upperRightMotorPin2, OUTPUT);
  pinMode(upperRightMotorEnablePin, OUTPUT);
  digitalWrite(upperRightMotorEnablePin, HIGH);
  
  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
  pinMode(leftMotorEnablePin, OUTPUT);
  digitalWrite(leftMotorEnablePin, HIGH);

  pinMode(clampMotorPin1, OUTPUT);
  pinMode(clampMotorPin2, OUTPUT);
  pinMode(clampMotorEnablePin, OUTPUT);
  digitalWrite(clampMotorEnablePin, HIGH);
/*  myRightArrow.drawArrow(80,30);
  myRightArrow.drawArrow(80,120);
  myRightArrow.drawArrow(80,210);
  myRightArrow.drawArrow(80,300);
  myRightArrow.drawArrow(80,390);
  myLeftArrow.drawArrow(10,30);
  myLeftArrow.drawArrow(10,120);
  myLeftArrow.drawArrow(10,210);
  myLeftArrow.drawArrow(10,300);
  myLeftArrow.drawArrow(10,390);*/
  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0) {
    
    incomingByte = Serial.read();

    /*char c = Serial.read();  //gets one byte from serial buffer
    readString += c; //makes the string readString*/
    
    if (incomingByte == 'Q') {
    digitalWrite(baseMotorPin1, LOW);   
    digitalWrite(baseMotorPin2, HIGH);  
    } 
    
    if (incomingByte == 'W') {
    digitalWrite(baseMotorPin1, HIGH);   
    digitalWrite(baseMotorPin2, LOW);  
    }
    
    if (incomingByte == 'E') {
    digitalWrite(upperRightMotorPin1, LOW);   
    digitalWrite(upperRightMotorPin2, HIGH);  
    } 
    
    if (incomingByte == 'R') {
    digitalWrite(upperRightMotorPin1, HIGH);   
    digitalWrite(upperRightMotorPin2, LOW);  
    }
    if (incomingByte == 'A') {
    digitalWrite(leftMotorPin1, LOW);   
    digitalWrite(leftMotorPin2, HIGH);  
    } 
    if (incomingByte == 'S') {
    digitalWrite(leftMotorPin1, HIGH);   
    digitalWrite(leftMotorPin2, LOW);  
    }

    if (incomingByte == 'Z') {
    digitalWrite(clampMotorPin1, LOW);   
    digitalWrite(clampMotorPin2, HIGH);  
    } 
    if (incomingByte == 'X') {
    digitalWrite(clampMotorPin1, HIGH);   
    digitalWrite(clampMotorPin2, LOW);  
    }
    
    // if a C is input it closes all motors
    if (incomingByte == 'C') {
    digitalWrite(baseMotorPin1, LOW);   
    digitalWrite(baseMotorPin2, LOW);  
    digitalWrite(upperRightMotorPin1, LOW);   
    digitalWrite(upperRightMotorPin2, LOW); 
    digitalWrite(leftMotorPin1, LOW);   
    digitalWrite(leftMotorPin2, LOW);  
    digitalWrite(clampMotorPin1, LOW);   
    digitalWrite(clampMotorPin2, LOW); 
    }
  }
}

