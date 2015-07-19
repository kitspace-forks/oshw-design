
#ifndef _EINKLIB_H
#define _EINKLIB_H


#include "application.h"
#include "Adafruit_MCP23008.h"

#define U1CKV (D5)
#define U1SPV (D4)
#define GMODE (D2)
#define BM_PGOOD (A5)
#define EINK_VDD (A1)
#define BM_CHG (A0)

//MCP e_ink_ctrl pins
#define CL (0)
#define LE (1)
#define OE (2)
#define SPH (3)
#define NEG_EN (4)
#define SMPS_CTRL (6) //require INPUT_PULLUP
#define POS_EN (7)

class Eink_low_level {
  public:
    bool vddStatus = false;
    bool smpsStatus = false;
    /* Delay for display waveforms. Should be an accurate microsecond delay. */
    void eink_delay(uint8_t us);

    bool setpower_smps(bool on);

    /* Turn the E-ink panel Vdd supply (+3.3V) on or off. */
    bool setpower_vdd(bool on);

    /* Turn the E-ink panel negative supplies (-15V, -20V) on or off. */
    //Active low
    bool setpower_vneg(bool on);

    /* Turn the E-ink panel positive supplies (+15V, +20V) on or off. */
    //Active low
    bool setpower_vpos(bool on);

    /* Set the state of the LE (source driver Latch Enable) pin. */
    void setpin_le(bool on);

    /* Set the state of the OE (source driver Output Enable) pin. */
    void setpin_oe(bool on);

    /* Set the state of the CL (source driver Clock) pin. */
    void setpin_cl(bool on);

    /* Set the state of the SPH (source driver Start Pulse Horizontal) pin. */
    void setpin_sph(bool on);

    /* Set the state of the D0-D7 (source driver Data) pins. */
    void setpins_data(uint8_t value);

    /* Set the state of the CKV (gate driver Clock Vertical) pin. */
    void setpin_ckv(bool on);

    /* Set the state of the GMODE (gate driver Gate Mode) pin. */
    void setpin_gmode(bool on);

    /* Set the state of the SPV (gate driver Start Pulse Vertical) pin. */
    void setpin_spv(bool on);

};

class Eink_display :  Eink_low_level {

  public:
    void pinInit(void);
    void powerOn(void);
    void powerOff(void);
    void data(uint8_t data);

    //testing purpose
    void toggleMcuPin(int pin);
    void toggleAllPin(int pin, bool state);
    void pinRand(void);


};


#endif
