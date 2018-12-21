#include "Arduino.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

const int full = 0;
const int half = 1;
const int potmet = 2;
const int change = 2;
const int ledR = 9;
const int ledG = 8;
const int ledB = 7;

int fullValue;
int halfValue;
int potValue;
int oldPotValue;

int state;

int folderNumber;

int maxFolder;

SoftwareSerial mySoftwareSerial(10, 11); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
//void printDetail(uint8_t type, int value);

void setup()
{
  mySoftwareSerial.begin(9600);
  Serial.begin(115200);
  pinMode(change, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(change),changeInstrument , FALLING);
  
  Serial.println();
  Serial.println(F("DFRobot DFPlayer Mini Demo"));
  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));
  
  if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while(true);
  }
  Serial.println(F("DFPlayer Mini online."));

  potValue=analogRead(potmet);
  myDFPlayer.volume(potValue * 30/1024);

  pinMode(ledR,OUTPUT);
  pinMode(ledG,OUTPUT);
  pinMode(ledB,OUTPUT);
  digitalWrite(ledR,HIGH);
  digitalWrite(ledG,LOW);
  digitalWrite(ledB,LOW); 
  
  fullValue = 0;
  halfValue = 0;
  potValue = 0;
  state = 0;
  maxFolder = myDFPlayer.readFolderCounts()-1;
  folderNumber = 0;

  //pinMode(change,INPUT);
   
}

void loop()
{
  //static unsigned long timer = millis();
  oldPotValue=potValue;
  potValue=analogRead(potmet);
  if(abs(oldPotValue-potValue)>5)
  { 
    myDFPlayer.volume(potValue * 30/1024);
  }
  
  fullValue = analogRead(full);
  halfValue = analogRead(half);

  Serial.print("Egesz: ");
  Serial.print(fullValue);
  Serial.print("       Fel: ");
  Serial.println(halfValue);

  //Serial.print("Play: ");
  //Serial.println(myDFPlayer.readCurrentFileNumber());

  if(fullValue >= 1018)
  {
    //myDFPlayer.play(1);
    state = 1;
    //myDFPlayer.playFolder((uint8_t) folderNumber, (uint8_t)state);
  }
  else if(fullValue <= 936 && fullValue >= 926)
  {
    //myDFPlayer.play(3);
    state = 3;
    //myDFPlayer.playFolder((uint8_t) folderNumber, (uint8_t)state);
  }
  else if(fullValue <= 860 && fullValue >= 850)
  {
    //myDFPlayer.play(5);
    state = 5;
    //myDFPlayer.playFolder((uint8_t) folderNumber, (uint8_t)state);
  }
  else if(fullValue <= 794 && fullValue >= 784)
  {
    //myDFPlayer.play(6);
    state = 6;
    //myDFPlayer.playFolder((uint8_t) folderNumber, (uint8_t)state);
  }
  else if(fullValue <= 738 && fullValue >= 728)
  {
    //myDFPlayer.play(8);
    state = 8;
    //myDFPlayer.playFolder((uint8_t) folderNumber, (uint8_t)state);
  }
  else if(fullValue <= 688 && fullValue >= 678)
  {
    //myDFPlayer.play(10);
    state = 10;
    //myDFPlayer.playFolder((uint8_t) folderNumber, (uint8_t)state);
  }
  else if(fullValue <= 645 && fullValue >= 635)
  {
    //myDFPlayer.play(12);
    state = 12;
    //myDFPlayer.playFolder((uint8_t) folderNumber, (uint8_t)state);
  }
  else if(fullValue <= 608 && fullValue >= 598)
  {
    //myDFPlayer.play(13);
    state = 13;
   // myDFPlayer.playFolder((uint8_t) folderNumber, (uint8_t)state);
  }
  else if(halfValue >= 1018)
  {
    //myDFPlayer.play(2);
    state = 2;
    //myDFPlayer.playFolder((uint8_t) folderNumber, (uint8_t)state);
  }
  else if(halfValue <= 937 && halfValue >= 927)
  {
    //myDFPlayer.play(4);
    state = 4;
    //myDFPlayer.playFolder((uint8_t) folderNumber, (uint8_t)state);
  }
  else if(halfValue <= 859 && halfValue >= 849)
  {
    //myDFPlayer.play(7);
    state = 7;
    //myDFPlayer.playFolder((uint8_t) folderNumber, (uint8_t)state);
  }
  else if(halfValue <= 794 && halfValue >= 784)
  {
    //myDFPlayer.play(9);
    state = 9;
    //myDFPlayer.playFolder((uint8_t) folderNumber, (uint8_t)state);
  }
  else if(halfValue <= 738 && halfValue >= 728)
  {
    //myDFPlayer.play(11);
    state = 11;
    //myDFPlayer.playFolder((uint8_t) folderNumber, (uint8_t)state);
  }
  else
  {
    state = 0;
  }
  //myDFPlayer.playFolder((uint8_t) folderNumber, (uint8_t)state);
 // myDFPlayer.play(state);
  Serial.println(folderNumber);
  Serial.println(state);
  //myDFPlayer.play(state + folderNumber * 13);

  switch (state)
  {
    case 0:
      //myDFPlayer.stop();
      break;
    case 1:
      myDFPlayer.play(state + folderNumber * 13);
      //myDFPlayer.playLargeFolder(1, 1);
      break;
    case 2:
      myDFPlayer.play(state + folderNumber * 13);
      //delay(3000);
      break;
    case 3:
      myDFPlayer.play(state + folderNumber * 13);
      //delay(3000);
      break;
    case 4:
      myDFPlayer.play(state + folderNumber * 13);
      //delay(3000);
      break;
    case 5:
      myDFPlayer.play(state + folderNumber * 13);
      //delay(3000);
      break;
    case 6:
      myDFPlayer.play(state + folderNumber * 13);
      //delay(3000);
      break;
    case 7:
      myDFPlayer.play(state + folderNumber * 13);
      //delay(3000);
      break;
    case 8:
      myDFPlayer.play(state + folderNumber * 13);
      //delay(3000);
      break;
    case 9:
      myDFPlayer.play(state + folderNumber * 13);
      //delay(3000);
      break;
    case 10:
      myDFPlayer.play(state + folderNumber * 13);
      //delay(3000);
      break;
    case 11:
      myDFPlayer.play(state + folderNumber * 13);
      //delay(3000);
      break;  
    case 12:
      myDFPlayer.play(state + folderNumber * 13);
      //delay(3000);
      break;
    case 13:
      myDFPlayer.play(state + folderNumber * 13);
      //delay(3000);
      break;    
  }

  switch(folderNumber){
    case 0:
      digitalWrite(ledR,HIGH);
      digitalWrite(ledG,LOW);
      digitalWrite(ledB,LOW);
      break;
    case 1:
      digitalWrite(ledR,LOW);
      digitalWrite(ledG,HIGH);
      digitalWrite(ledB,LOW);
      break;
    case 2:
      digitalWrite(ledR,LOW);
      digitalWrite(ledG,LOW);
      digitalWrite(ledB,HIGH);
      break;
    case 3:
      digitalWrite(ledR,HIGH);
      digitalWrite(ledG,HIGH);
      digitalWrite(ledB,LOW);
      break;
    case 4:
      digitalWrite(ledR,HIGH);
      digitalWrite(ledG,LOW);
      digitalWrite(ledB,HIGH);
      break;
    case 5:
      digitalWrite(ledR,LOW);
      digitalWrite(ledG,HIGH);
      digitalWrite(ledB,HIGH);
      break;
    case 6:
      digitalWrite(ledR,HIGH);
      digitalWrite(ledG,HIGH);
      digitalWrite(ledB,HIGH);
      break;      
  }

  //delay(1000);
  /*
  if (millis() - timer > 3000) {
    timer = millis();
    //myDFPlayer.next();  //Play next mp3 every 3 second.
  }
  
  if (myDFPlayer.available()) {
    printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
  }*/
}

void changeInstrument(){
  if(folderNumber == maxFolder - 1)
    {
      folderNumber = 0;
    }
    else
    {
      folderNumber = folderNumber + 1;
    }
    /*if(myDFPlayer.readCurrentFileNumber()!=0){
      myDFPlayer.pause();
      }*/
    
}
/*
void printDetail(uint8_t type, int value){
  switch (type) {
    case TimeOut:
      Serial.println(F("Time Out!"));
      break;
    case WrongStack:
      Serial.println(F("Stack Wrong!"));
      break;
    case DFPlayerCardInserted:
      Serial.println(F("Card Inserted!"));
      break;
    case DFPlayerCardRemoved:
      Serial.println(F("Card Removed!"));
      break;
    case DFPlayerCardOnline:
      Serial.println(F("Card Online!"));
      break;
    case DFPlayerPlayFinished:
      Serial.print(F("Number:"));
      Serial.print(value);
      Serial.println(F(" Play Finished!"));
      break;
    case DFPlayerError:
      Serial.print(F("DFPlayerError:"));
      switch (value) {
        case Busy:
          Serial.println(F("Card not found"));
          break;
        case Sleeping:
          Serial.println(F("Sleeping"));
          break;
        case SerialWrongStack:
          Serial.println(F("Get Wrong Stack"));
          break;
        case CheckSumNotMatch:
          Serial.println(F("Check Sum Not Match"));
          break;
        case FileIndexOut:
          Serial.println(F("File Index Out of Bound"));
          break;
        case FileMismatch:
          Serial.println(F("Cannot Find File"));
          break;
        case Advertise:
          Serial.println(F("In Advertise"));
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }

}*/
