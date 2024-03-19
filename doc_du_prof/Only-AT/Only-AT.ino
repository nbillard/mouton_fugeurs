/*
  * File  : DFRobot_SIM7000_ATtest.ino
  * Power : SIM7000 needs 7-12V DC power supply
  * Brief : This example use the serial port to send AT command to control the SIM7000
  *         With initialization completed, we can enter AT command to SIM7000 directly
  * AT command list:
  * https://github.com/DFRobot/binaryfiles/raw/master/DFR0505/doc/SIM7000%20Series_AT%20Command%20Manual_V1.01.pdf
  * Note  : If you use Mega please connect PIN8 PIN10 and set PIN_RX = 10
  *         The AT command must end with CRLF
  */
#include "SIM_7000.h"

#define PIN_TX     7
#define PIN_RX     8
//SoftwareSerial     mySerial(PIN_RX,PIN_TX);
SIM_7000    sim7000(&Serial1); //Serial 1 is hardware serial on genuino 101

void setup() {
    Serial.begin(115200);  // <-- serial for USB
    //Serial1.begin(19200); // <-- serial for SIM7000
    Serial1.begin(115200); // <-- serial for SIM7600
    //mySerial.begin(115200);

    while (!Serial) ;
    
    Serial.print("Turn ON SIM7000......");
    if(sim7000.turnON()){                             //Turn ON SIM7000
        Serial.println("Ok");
    } else
    {
      Serial.println("Failed");
      Serial.println("System halted.");
      while (1);
    }

    // Serial.println("Set baud rate (115200)......");
    // if(sim7000.setBaudRate(115200)){                   //Set baud rate from autobaud(19200) to 115200
    //     Serial.println("Ok");
    // }else{
    //     Serial.println("Failed");
    //     Serial.println("System halted.");
    //     while(1);
    // }

    // Serial1.begin(115200);
    // Serial.println("For example, if you type AT\\r\\n, OK\\r\\n will be responsed!");
    // Serial.println("Enter your AT command :");
}

void loop() {
    // mySerial.listen();
    // while(mySerial.available()){
    //     Serial.write(mySerial.read());
    // }

    // mySerial.flush();
    // while(Serial.available()){
    //     mySerial.write(Serial.read());
    // }

    //Serial1.listen();
    while(Serial1.available()){
        Serial.write(Serial1.read());
    }

    //Serial1.flush();
    while(Serial.available()){
        Serial1.write(Serial.read());
    }

    //delay(20);
}