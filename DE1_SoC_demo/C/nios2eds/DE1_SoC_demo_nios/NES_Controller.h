#ifndef __NES_CONTROLLER_H__
#define __NES_CONTROLLER_H__

#include <stdint.h>
#include <stdbool.h>

#define LATCH_US (12)
#define PULSE_US (6)
#define NB_BUTTONS 8

#define PULSE_OFFSET (0b00000010)
#define LATCH_OFFSET (0b00000001)
#define DATA_OFFSET  (0b00000001)

/* Direction Offset for the PIO
 * https://www.altera.com/content/dam/altera-www/global/en_US/pdfs/literature/hb/nios2/n2cpu_nii51007.pdf
 *	0: Latch  	-> OUT
 *	1: Pulse 	-> OUT
 *	0: Data 	-> IN
 */

uint8_t NES_Controller_Update();

#endif
