Steps taken
---

###Plan out the high level features

eg.

- Wifi enabled
- Wireless charging
- Battery management
- orientation detection

###Select all the key ICs

- ensure that parts are source-able
- study known designs (eg. adafruit, sparkfun, bunniestudios) and evaluate the best IC for that project
- select the best MCU for the job

###Prepare the project files

- Follow the current directory tree and create a new forked version
- start off with a `0.0.1` schematic design
- use a `FRAME-A4L` from Sparkfun for the layout
- create the global attributes (CNAME, CREVISION, DESIGNER)
- give that page a description of what it contains

###Start off laying out the power module
- This will be the best place to kick off!
- Create them and label the NET with the appropriate voltage values

###Key points

- Decoupling caps everywhere. Every time an IC is placed, a bypass/decoupling Cap should follow next.
- Think of pins where flexibility is required and use a 0604 0 Ohm resistor.
- Come out with a `pin-out table` if there are too many pins to be inter-connected.
- Save each datasheet (MANU-SHORTFORM_PART-NO) as you work so that you don't forget
- Write the `README.md` as you go or even at the beginning of the project so that key features are decided before starting work. This helps me decide which IC containing the required features is used.
- Write out a checklist on paper and tick them when you are done. Yeah i know digital is cool but pen and paper is rock solid.

###Some dimensions

- For silkscreen, mm, 1.27, 20%, Vector font works great
- Via, inches, round, Drill 0.01968504, Diameter 0.05
- Via, mm, round, Drill 0.5mm, Diameter 1.27mm
- For polygon, set **isolate** to `0.012inch/12mil"`
- For routing, mil, 12

### Labels

- IC                (Uxx/B/M/C/R), where the suffix tells which module it relates to eg B is for battery
- Resistor          (Rxx/B/M/C/R)
- Capacitor         (Cxx/B/M/C/R)
- Inductor          (Lxx/B/M/C/R)
- Diode/LED         (Dxx/B/M/C/R)
- FET/Transistor    (Qxx/B/M/C/R)
- Header/Connectors (Jxx/B/M/C/R)
- Switch            (SWxx/B/M/C/R)


### Checks after initial routing completion

- turn off layers and look for "unrouted" wires and see what's going on
- Run a DRC check
- smash all the labels and change to 1.016, 20%, vector, mm as a minimum
- Add other labels like "+" for battery, jumper labels etc.
- finalize mounting hole position by entering co-ordinates manually for accuracy
- Add in license and OSHW logo, designer name, designed in Singapore, date, revision

```text
Copyrights: CC-BY-SA 3.0
Designed in Singapore 07/15
Project name rev x.x.x
Apache License 2.0
@kennethlimcp
````

- print-out and check for silkscreen visibility
- final DRC rule cos it does not hurt
- make a copy of the `.sch` and `.brd` and run the `teardrop` ULP. That will make the vias/pads stronger with increased trace surface area
- zip up all the GERBERS!
