Battery Management
---

####Input

- VUSB
- Header pins (with diode protection)

####Control pins
- CE (enable/disable charger)
- BM_SYSOFF (con/discon battery to system output)

####Output
- BM_OUT (battery positive voltage)
- PGOOD (external power attached)
- CHG (battery charging)
- ISET (charging current-->voltage)

3V3 Buck regulator
---

####Input
- BM_OUT
- Enable pin

####Output
- +3V3


DC/DC converter
---

####Input
- BM_OUT

####Control pins
- NEG_EN
- POS_EN
- SMPS_CTRL

####Output
- -20V
- +22V

+15V linear regulator
---

####Input
- +22V
####Output
- +15V

-15V linear regulator
---
####Input
- -20V

####Output
- -15V

LM358 Opamp
---

####Input
- +15V
- -15V

####Output
- VCOM negative voltage

e-ink display
---

####Input
- +15V
- -15V
- +22V
- -20V

####Control pins (15)
- D0-D7
- GMODE2
- U1SPV
- U1CKV
- CL
- LE
- OE
- SPH
- E_INK_VDD

####Output
- VCOM negative voltage

GPIO expander (e-ink data line)
---
####Input (ascending)
- D0-D7

####Control pins (15)
- SCL
- SDA
- INT (not using as all will be OUTPUT pins)
- RST

GPIO expander (control line)
---
####Input (ascending)
- CL
- LE
- OE
- SPH
-
-
- NEG_EN (DC/DC)
- POS_EN (DC/DC)

####Control pins (15)
- SCL
- SDA
- INT (not using as all will be OUTPUT pins)
- RST
