### Key changes from V0.0.2
- Using a STM32F103RBT6 with direct GPIO connection
- breakout most pins
- MODE and Reset button
- JTAG, UART headers
- SPI test points
- separated ground plane for battery charging, DC/DC module and MCU

### To prepare
- [ ] Schematic print-out
- [ ] Parts
- [ ] Placement diagram
- [ ] this notes

### Bring-up notes

**Major components populating**

- [ ] microUSB (this was nasty in V002)
- [ ] FPC connector
- [ ] BM IC
- [ ] LT1945
- [ ] LM358

**Test sequence**

- [ ] 3V3 SMPS regulator
  - [ ] jumper +5V to BM_SUPPLY
  - [ ] measure the 3V# test-point

- [ ] BMIC
  - [ ] battery should charge as designed upon USB insertion
  - [ ] See if SUPPLY led lights up with USB presence
  - [ ] CHG should light up with Batt attached

- [ ] DC/DC converter
  - already proven working but nevertheless we check it
  - Power up and make sure no voltage at J06B
  - wire TP1 to ground to turn on Q01B
  - Check that only J07B has -20V and J08B is 0V
  - wire TP2 to ground and check J08B for +22V

- [ ] Linear regulators
  - Nothing much here. Populate and measure
  - J09B, -15V
  - J10B, +15V

- [ ] VCOM Opamp
  - populate and measure J11B while turning trimmer at R18B

- [ ] MCU
  - [ ]  Populate U01M, the STM32
  - [ ]  Crystals Y01M, Y02M next
  - [ ]  Decoupling caps, C05M to C10M
  - [ ]  RGB led, D02M and R01M to R03M
  - [ ]  Blue led, D01M and R05M
  - [ ]  Buttons!
  - [ ] USB disconnect circuit
  - we will come back to test the alt circuitry next time
  - JTAG header

- [ ]  MCU testing
  - [ ] wire up STlinkV2 to JTAG header
  - [ ] power up the board via USB as well
  - [ ] attempt to flash bootloader code and pray that everything works well!

- [ ] Eink components
  - [ ] just all the remaining resistors and decoupling caps to go on

- [ ] Last bit
  - [ ] Accelerometer
  - [ ] SD socket
  - [ ] battery holder
  - [ ] FTDI header

- Official tests
  - [ ] make sure all the GPIOs are correctly configured
  - [ ] MODE button test
  - [ ] DC/DC power control tests
  - [ ] Battery indicator input reading
  - [ ] time to insert the Eink!
