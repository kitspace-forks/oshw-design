/*
 * 2013 Petteri Aimonen <jpa@gfx.mail.kapsi.fi>
 * This file is released to the public domain.
 */

/* Board interface definitions for ED060SC4 PrimeView E-ink panel.
 *
 * You should implement the following functions to define the interface to
 * the panel on your board.
 */

#ifndef _GDISP_LLD_BOARD_H
#define _GDISP_LLD_BOARD_H

/* Set up IO pins for the panel connection. */
static inline void init_board(void) {
#error Unimplemented
}

/* Delay for display waveforms. Should be an accurate microsecond delay. */
static void eink_delay(int us)
{
  micros(us);
}


#endif
