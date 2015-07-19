#include "eink_lib.h"

Adafruit_MCP23008 eink_data;
Adafruit_MCP23008 eink_ctrl;

//The pin initialization should not be moved unless mentioned as the sequence can cause the e-ink display to be damaged
void Eink_display::pinInit(void){
  pinMode(BM_PGOOD,INPUT);
  pinMode(BM_CHG,INPUT);

  pinMode(U1CKV,OUTPUT);
  pinMode(U1SPV,OUTPUT);
  pinMode(GMODE,OUTPUT);
  //Drive as HIGH or INPUT (HIGH-Z) or it might become damaged
  //http://www.essentialscrap.com/comments/eink/electronics.html
  pinMode(EINK_VDD,OUTPUT);

  //Set all to low for known state
  digitalWrite(U1CKV,LOW);
  digitalWrite(U1SPV,LOW);
  digitalWrite(GMODE,LOW);

  eink_data.begin(0);       // use default address 0
  eink_ctrl.begin(1);      // use address 1

  //All the pins on the e_ink_data is used as OUTPUT and known state of LOW
  //0 output, 1 input
  //0 LOW, 1 HIGH
  eink_data.pinModeAll(0B00000000);
  eink_data.writeGPIO(0B00000000);

  eink_ctrl.pinModeAll(0B00000000);
  //needed in rev V0.0.2 PCB
  eink_ctrl.writeGPIO(0B01000000);
  //SMPS_CTRL  Active low so set to HIGH
  //eink_ctrl.pullUp(SMPS_CTRL,HIGH);
  //POS_EN, NEG_EN,  all Active High
  eink_ctrl.pullUp(NEG_EN,LOW);
  eink_ctrl.pullUp(POS_EN,LOW);

}

void Eink_display::powerOn(void){
  setpins_data(0x00);
  setpin_le(false);
  setpin_oe(false);
  setpin_cl(false);
  setpin_ckv(false);
  setpin_gmode(false);
  setpin_spv(false);
  setpin_sph(true);

  setpower_vdd(true);
  delayMicroseconds(100);
  setpower_smps(true);
  delayMicroseconds(100);
  setpower_vpos(true);
  delayMicroseconds(100);
  setpower_vneg(true);

}

void Eink_display::powerOff(void){

  setpins_data(0x00);
  setpin_ckv(false);
  setpin_gmode(false);
  setpin_spv(false);
  setpin_le(false);
  setpin_oe(false);
  setpin_cl(false);
  setpin_sph(false);

  setpower_vneg(false);
  delayMicroseconds(100);
  setpower_vpos(false);
  delayMicroseconds(100);
  setpower_smps(false);
  delayMicroseconds(100);
  setpower_vdd(false);
}


void  Eink_display::pinRand(void){

  uint8_t filter = 0B10110000;
  uint8_t ctrl = random(15);
  uint8_t filtered = filter | ctrl;
  uint8_t data = random(254);
  setpin_gmode(random(2));
  eink_ctrl.writeGPIO(filtered);

  setpin_spv(random(2));
  eink_data.writeGPIO(0B01010101);
  setpin_ckv(random(2));


  // Serial.print(filtered, HEX);
  // Serial.print(" ");
  // Serial.print(data, HEX);

}

//for testing purpose
void  Eink_display::toggleMcuPin(int pin){
  if (vddStatus == true){
    digitalWrite(pin, !digitalRead(pin));
  }
}

void  Eink_display::toggleAllPin(int pin, bool state){

    setpins_data(pin);

    setpin_ckv(state);
    setpin_gmode(state);
    setpin_spv(state);
    setpin_le(state);
    setpin_oe(state);
    setpin_cl(state);
    setpin_sph(state);

    setpower_vneg(state);
    setpower_vpos(state);
    setpower_smps(state);
}

void Eink_display::data(uint8_t data){
  setpins_data(data);
}

void Eink_low_level::eink_delay(uint8_t us){
  delayMicroseconds(us);
}

/* Turn the E-ink panel Vdd supply (+3.3V) on or off. */
bool Eink_low_level::setpower_vdd(bool on){
  //Set to HIGH-Z instead of '0' to prevent shorting
  if(on){
    digitalWrite(EINK_VDD, HIGH);
    vddStatus = true;
    return true;
  }
  else{
    setpins_data(0x00);
    setpin_ckv(false);
    setpin_gmode(false);
    setpin_spv(false);
    setpin_le(false);
    setpin_oe(false);
    setpin_cl(false);
    setpin_sph(false);

    setpower_vneg(false);
    delayMicroseconds(100);
    setpower_vpos(false);
    delayMicroseconds(100);
    setpower_smps(false);
    delayMicroseconds(100);
    digitalWrite(EINK_VDD, LOW);
    vddStatus = false;
    return true;
  }
}

bool Eink_low_level::setpower_smps(bool on){
  if(on){
    if(vddStatus != true)
      return false;
    else{
      eink_ctrl.digitalWrite(SMPS_CTRL, LOW);
      return true;
    }
  }
  else{
    eink_ctrl.digitalWrite(SMPS_CTRL, HIGH);
    return true;
  }
}
/* Turn the E-ink panel negative supplies (-15V, -20V) on or off. */
//Active low
bool Eink_low_level::setpower_vneg(bool on){
  if(on){
    if(vddStatus != true)
      return false;
    else{
      eink_ctrl.digitalWrite(NEG_EN, HIGH);
      return true;
    }
  }
  else{
    eink_ctrl.digitalWrite(NEG_EN, LOW);
    return true;
  }
}

/* Turn the E-ink panel positive supplies (+15V, +20V) on or off. */
//Active low
bool Eink_low_level::setpower_vpos(bool on){
  if(on){
    if(vddStatus != true)
      return false;
    else{
      eink_ctrl.digitalWrite(POS_EN, HIGH);
      return true;
    }
  }
  else{
    eink_ctrl.digitalWrite(POS_EN, LOW);
    return true;
  }
}

/* Set the state of the LE (source driver Latch Enable) pin. */
void Eink_low_level::setpin_le(bool on){
  if(on && vddStatus == true)
    eink_ctrl.digitalWrite(LE,HIGH);
  else
    eink_ctrl.digitalWrite(LE,LOW);
}

/* Set the state of the OE (source driver Output Enable) pin. */
void Eink_low_level::setpin_oe(bool on){
  if(on && vddStatus == true)
    eink_ctrl.digitalWrite(OE,HIGH);
  else
    eink_ctrl.digitalWrite(OE,LOW);
}

/* Set the state of the CL (source driver Clock) pin. */
void Eink_low_level::setpin_cl(bool on){
  if(on && vddStatus == true)
    eink_ctrl.digitalWrite(CL,HIGH);
  else
    eink_ctrl.digitalWrite(CL,LOW);
}

/* Set the state of the SPH (source driver Start Pulse Horizontal) pin. */
void Eink_low_level::setpin_sph(bool on){
  if(on && vddStatus == true)
    eink_ctrl.digitalWrite(SPH,HIGH);
  else
    eink_ctrl.digitalWrite(SPH,LOW);
};

/* Set the state of the D0-D7 (source driver Data) pins. */
void Eink_low_level::setpins_data(uint8_t value){
  eink_data.writeGPIO(value);
}

/* Set the state of the CKV (gate driver Clock Vertical) pin. */
void Eink_low_level::setpin_ckv(bool on){
  if(on && vddStatus == true)
    digitalWrite(U1CKV,HIGH);
  else
    digitalWrite(U1CKV,LOW);
}

/* Set the state of the GMODE (gate driver Gate Mode) pin. */
void Eink_low_level::setpin_gmode(bool on){
  if(on && vddStatus == true)
    digitalWrite(GMODE,HIGH);
  else
    digitalWrite(GMODE,LOW);
}

/* Set the state of the SPV (gate driver Start Pulse Vertical) pin. */
void Eink_low_level::setpin_spv(bool on){
  if(on && vddStatus == true)
    digitalWrite(U1SPV,HIGH);
  else
    digitalWrite(U1SPV,LOW);
}
