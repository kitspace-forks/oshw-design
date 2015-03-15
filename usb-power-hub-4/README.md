###4 Port USB hub
----------

####Introduction

With many low-cost linux board sitting around, getting more than 2 powered up becomes a pain since each of them require a 5V power supply! You can now power them all up and have external control over each port to turn them on/off. 

This hardware allows you to connect a 5V, ___A power adapter and share it with up to 4 x USB port.

The Data (DM,DP) lines are not connected together but can be individually modified!  You can experiment with different resistor values and see if you can trigger a **samsung fast charge** or get your Iphone to recognize the charger!


###Power Connection

######Input
- 2.1mm diameter power jack
- microB USB
- jumper wire (+ and -)

######Output
- 4 x USB A port
- 1 x Jumper (+5v, GND)

###Signal Connection

######Input

You can individually control each USB port to turn them on/off using this pin. Right now, the power switches chosen are **Active low** with a pull-down resistor.

######Output
Each USB power switch has a **FLAG** output that provides an open-drain output to notify users of a short/overcurrent.

You will need to add a pull-up resistor in you external circuit inorder to use this.
