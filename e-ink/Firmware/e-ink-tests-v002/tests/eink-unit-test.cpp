#include "unit-test.h"

#include "eink_lib.h"
/**
 * Demonstrates a simple test that passes and one that fails.
 * Input/Output via serial.
 * To start the test, press 't'.
 */

SYSTEM_MODE(MANUAL);

Eink_low_level eink_ll;

test(set_VDD_on)
{
  bool a1 = eink_ll.setpower_vdd(true);
  bool b1 = true;
  bool x1 = eink_ll.vddStatus;
  bool y1 = false;

  assertEqual(a1,b1);
  assertNotEqual(x1,y1);
}

test(set_VDD_off)
{
  bool a2 = eink_ll.setpower_vdd(false);
  bool b2 = true;
  bool x2 = eink_ll.vddStatus;
  bool y2 = true;


  assertEqual(a2,b2);
  assertNotEqual(x2,y2);
}

test(on_Neg_Voltage_Without_VDD_on)
{
  bool a3 = eink_ll.setpower_vdd(false);
  bool b3 = true;
  bool x3 = eink_ll.setpower_vneg(true);
  bool y3 = true;

  assertEqual(a3,b3);
  assertNotEqual(x3,y3);

}

test(on_Neg_Voltage_With_VDD_on)
{
  bool a4 = eink_ll.setpower_vdd(true);
  bool b4 = true;
  bool x4 = eink_ll.setpower_vneg(true);
  bool y4 = true;

  assertEqual(a4,b4);
  assertEqual(x4,y4);

}

test(off_Neg_Voltage)
{
  bool a5 = eink_ll.setpower_vneg(false);
  bool b5 = true;

  assertEqual(a5,b5);
}

test(on_Pos_Voltage_Without_VDD_on)
{
  bool a6 = eink_ll.setpower_vdd(false);
  bool b6 = true;
  bool x6 = eink_ll.setpower_vpos(true);
  bool y6 = true;

  assertEqual(a6,b6);
  assertNotEqual(x6,y6);

}

test(on_Pos_Voltage_With_VDD_on)
{
  bool a7 = eink_ll.setpower_vdd(true);
  bool b7 = true;
  bool x7 = eink_ll.setpower_vpos(true);
  bool y7 = true;

  assertEqual(a7,b7);
  assertEqual(x7,y7);

}

test(off_Pos_Voltage)
{
  bool a8 = eink_ll.setpower_vpos(false);
  bool b8 = true;

  assertEqual(a8,b8);
}

UNIT_TEST_APP()
