
###Bring up sequence and testing steps

####Battery management module

Getting the BQ24075 to work first will be the first priority as all the other subsystems require this primary rail to be up and running.

- R05B to be populated with a 0 Ohm resistor to enable charging
- Measure Battery voltage at J05B
- 2-pin jumper needed at J04B as a physical switch to join Li-ion to system
- Measure BM_OUT at J02B
- Plug in microUSB at J07B and measure +5V at J01B
- Check that D01B lights up when microUSB power source is present
- Check that D02B lights up to indicate battery charging

####3.3V buck regulator

Pretty straight forward to bring this up. Measure at J06B for +3.3V

####DC/DC converter module

- Do not populate R12B due to control issues not able to do open-drain output
- Measure at J08B to have no voltage since Q01B load switch is disabled by default
- Need to pull down SMPS_CTRL pin but that will require the GPIO Expander. Jumper to ground for testing
- Measure J09B for -20V
- Measure J10B for +22V

####Linear regulators

- Populate the LM7815 first and measure J12B for +15V
- Populate the LM7915 and measure -15V at J11B

####OpAmp module

- Populate U6B and vary Trimpot R18B while measuring voltage at J13B

####GPIO Expander

- Hard to test without the MCU
- Probably monitor current and note for any spike?
- Run a series of GPIO output toggling tests and do a pull-up test as well


####MCU - Photon

- Check that the 3.3V and GND are properly routed and no input on the VIN or other pins
- Check for continuity for I2C lines
- Check for BM_PGOOD (A6), GMODE2 (D2), U1CKV (D5), U1SPB (D4). EINK_VDD(A2), BM_CHG (A0)

####microSD

- Check that LED flickers during read/write

####Accelerometer

- run a read test and rotate the PCB around to test changes
