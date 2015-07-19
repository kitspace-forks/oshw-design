#include "application.h"
#include "eink_lib.h"

SYSTEM_MODE(MANUAL);

Eink_display eink;
Eink_low_level eink_ll;


void setup(){
  //added
  Wire.setSpeed(CLOCK_SPEED_1_7MHZ);
  Wire.begin();

  eink.pinInit();

  RGB.control(true);
  RGB.color(0,0,255); //blue

  //Use D7 to monitor EINK_VDD
  pinMode(D7,OUTPUT);
  digitalWrite(D7,digitalRead(EINK_VDD));
  Serial.begin(115200);
//  while(!Serial.available()) Spark.process();
  Serial.println("E-ink pin random started.\n");
  eink.powerOn();

  RGB.color(0,255,0); //green

}

void loop(){
  eink.pinRand();
}





/*
#define e_ink_pin_count 4

struct pin_Info {
  uint8_t pin_name;
  PinMode pin_mode;
  String pin_label;
};

pin_Info e_ink[e_ink_pin_count]{
  { D5, OUTPUT, "U1CKV"},
  { D4, OUTPUT, "U1SPV"},
  { A6, INPUT, "BM_PGOOD"},
  { A0, INPUT, "BM_CHG"}
};

uint8_t nameToPin(String name){
  for(uint8_t i = 0; i<e_ink_pin_count;i++){
    if(name == e_ink[i].pin_label) return e_ink[i].pin_name;
  }
  return -1;
}

void setup(){
  //Setup all the pinMode
  for(uint8_t i = 0; i<e_ink_pin_count;i++)
    pinMode(e_ink[i].pin_name,e_ink[i].pin_mode);

  //Set all OUTPUT pins to LOW
  for(uint8_t i = 0; i<e_ink_pin_count;i++)
    if(PinMode (OUTPUT) == e_ink[i].pin_mode) digitalWrite(e_ink[i].pin_name, LOW);
}

*/
