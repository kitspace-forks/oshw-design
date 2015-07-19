#include "Adafruit_MCP23008.h"

/*
2 x MCP23008 on the e-ink display
For e-ink data control D0-D7, the address is 0x20
For other pins control, the address is 0x21

The available commands are:

d - Pull-down
h - help info
i - set all to INPUT
o - set all to OUTPUT
p - enter DFU mode
r - read the GPIO pin status
u - Pull-up
*/

Adafruit_MCP23008 mcp1;
Adafruit_MCP23008 mcp2;

SYSTEM_MODE(MANUAL);

void setup() {
  mcp1.begin();       // use default address 0
  mcp2.begin(1);      // use address 1

  //start safe and set all the pins to be an input
  for (uint8_t i=0;i<7;i++){
    mcp1.pinMode(i, INPUT);
    mcp2.pinMode(i, INPUT);
  }

  //Make use of RGB led
  RGB.control(true);
  RGB.color(0, 255, 0); //start off with green status

  //Using USB serial to perform tests
  Serial.begin(9600);
  while(!Serial.available()) Spark.process();
  Serial.flush();
  Serial.println("\ne-ink board testing v001");
  Serial.println("MCP23008 test");
}


void loop() {
  char input;

  if(Serial.available()){
    input = Serial.read();

    switch(input){

      case 'p':
        System.bootloader();
        break;

      case 'i':
        Serial.println("\nSetting all pins to input.");
        Serial.print("hit e char to confirm: ");
        while(!Serial.available());
        if(Serial.read() == 'e'){
          RGB.color(0, 0, 255); //blue
          for (uint8_t i=0;i<7;i++){
            mcp1.pinMode(i, INPUT);
            mcp2.pinMode(i, INPUT);
          }
          Serial.println("set to INPUT!");
        }
        else
          Serial.println("nothing");
        break;

      case 'o':
        Serial.println("\nSetting all pins to output.");
        Serial.print("hit e char to confirm: ");
        while(!Serial.available());
        if(Serial.read() == 'e'){
          RGB.color(0, 0, 255); //blue
          for (uint8_t i=0;i<7;i++){
            mcp1.pinMode(i, OUTPUT);
            mcp2.pinMode(i, OUTPUT);
          }
          Serial.println("set to OUTPUT!");
        }
        else
          Serial.println("nothing");
        break;

      case 'r':
        RGB.color(0, 0, 255); //blue
        Serial.print("\nMCP 01 pin status: ");
        Serial.println(mcp1.readGPIO());
        Serial.print("\nMCP 02 pin status: ");
        Serial.println(mcp2.readGPIO());
        Serial.println("pin status read!");
        break;

      case 'u':
        RGB.color(0, 0, 255); //blue
        Serial.println("\nSetting all pins to Pull-up.");
        Serial.print("hit e char to confirm: ");
        while(!Serial.available());
        if(Serial.read() == 'e'){
          RGB.color(0, 0, 255); //blue
          for (uint8_t i=0;i<7;i++){
            mcp1.pullUp(i, HIGH);
            mcp2.pullUp(i, HIGH);
          }
          Serial.println("set to Pull-up!");
        }
        else
          Serial.println("nothing");
        break;

      case 'd':
        RGB.color(0, 0, 255); //blue
        Serial.println("\nSetting all pins to Pull-down.");
        Serial.print("hit e char to confirm: ");
        while(!Serial.available());
        if(Serial.read() == 'e'){
          RGB.color(0, 0, 255); //blue
          for (uint8_t i=0;i<7;i++){
            mcp1.pullUp(i, LOW);
            mcp2.pullUp(i, LOW);
          }
          Serial.println("set to Pull-down!");
        }
        else
          Serial.println("nothing");
        break;

      case 'h':
      default:
        Serial.print("\ncommands available: ");
        Serial.print("d");
        Serial.print(", ");
        Serial.print("i");
        Serial.print(", ");
        Serial.print("o");
        Serial.print(", ");
        Serial.print("p");
        Serial.print(", ");
        Serial.print("r");
        Serial.print(", ");
        Serial.print("u");
        Serial.print(", ");
        break;
    }

  while(Serial.available()) Serial.read();
  RGB.color(0, 255, 0); //green
  }
}
