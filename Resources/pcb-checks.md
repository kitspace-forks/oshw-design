###Verifying and populating a new PCB

######Things to prepare
- Schematic printout
- Parts layout/orientation printout
- Multimeter
- Clamping vise (nice to have)
- ye' old tweezer
- Solder spool(0.3mm is ideal for dealing with SMD parts)
- Solder wick-(ed) (this is going to be invaluable)
- Solder paste (if you are reflowing)
- Scrapper (to spread peanut butter..opps Solder paste)

######Systematic verification steps

**Checking the bare PCB**
- Test for short between power lines. eg. 5V and GND
- Supply power and check that power pins are receiving the correct voltage

**Preparing to populate!**
- Lay out your parts neatly and have an idea of which part gets placed first and which goes next
- Have a spacious work area as entropy will spontaneously increase and things get disorganized
- Place your print-out somewhere within sight for easy referencing

**Populating the PCB (by hand)**
- Start off by populating the smallest and toughest package. eg. QFN before through hole
- **Remember** that **solder flux** is your best friend! Apply sparingly to the pad to be soldered before continuing
- Look out for the polarity and "pin 1" position before soldering down each part
- Solder one "leg" to hold the part in place, double-check that the orientation is correct before continuing. This will save you a ton of heartache/desoldering
- Perfection is great but a burnt component is not. As long as the component is properly in place, (i know it's hard to resist having a perfectly oriented part) move on to the next one!
- If you are not confident that the parts are properly soldered, whip out your trusty multimeter and test for connector from each leg to the respective end-point

***Special notes***
- Solder one part, check for goodness before moving on
- As you solder, visually inspect the board and make sure the part is not "tombed"
- For IC, be sure to apply some pressure to solder them firmly on the pad (not floating)
-

**Populating the PCB (for reflow)**
- If you are doing this process, you probably have a stencil ready to spread the Solder paste
- Grab some spare pcbs or material and stick them down on the work area to serve as a jig so that the PCB stays in place while you spread solder paste. Imagine something like a "L" shape where the pcb can be pushed against
- Align your stencil and scrap the solder paste through! Place enough solder paste and do a smooth one-time apply.
- It is not recommended to go back and forth too many times so... do it once, do it good! Practice makes perfect for this step
- Once that is done, carefully populate each component before sending the PCB for baking/reflow
