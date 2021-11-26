
/* Libraries */

// Standard Headers (libc)
#include <inttypes.h>

// Device/Framework Headers
#include <avr/io.h>
#include <util/delay.h>

// Project Headers
#include "constants.h"

/*****************************************************************************/

/* Constants */

// Led delay after toggle Toggle
static const uint16_t DELAY_MS_LED_TOGGLE = 500;

/*****************************************************************************/

/* Main Function */

int main(void)
{
    // Set LED Pin as digital Output
    DDRB |= PIN_LED;

    while (1)
    {
        // LED ON
        PORTB |= PIN_LED;
        _delay_ms(DELAY_MS_LED_TOGGLE);

        // LED OFF
        PORTB &= ~PIN_LED;
        _delay_ms(DELAY_MS_LED_TOGGLE);
    }
}

/*****************************************************************************/
