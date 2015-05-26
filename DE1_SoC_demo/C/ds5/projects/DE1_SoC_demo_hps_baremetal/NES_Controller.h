#ifndef __NES_CONTROLLER_H__
#define __NES_CONTROLLER_H__

#include <stdint.h>
#include <stdbool.h>
#include "../hps_soc_system.h"
#include "socal/hps.h"

#define BUTTON_MEMORY_BASE (ALT_LWFPGASLVS_ADDR + BUTTONS_MEMORY_BASE)

/* Direction Offset for the PIO
 * https://www.altera.com/content/dam/altera-www/global/en_US/pdfs/literature/hb/nios2/n2cpu_nii51007.pdf
 *	0: Latch  	-> OUT
 *	1: Pulse 	-> OUT
 *	0: Data 	-> IN
 */

typedef struct NES_Controller {
	bool A_PRESSED;
	bool B_PRESSED;
	bool SELECT_PRESSED;
	bool START_PRESSED;
	bool UP_PRESSED;
	bool DOWN_PRESSED;
	bool LEFT_PRESSED;
	bool RIGHT_PRESSED;

	uint32_t pio_base;
} NES_Controller;

void NES_Controller_Update(NES_Controller* controller);

#endif
