#include "../../../../../.platformio/packages/toolchain-atmelavr/avr/include/stdio.h"

void uart_putchar(char c, FILE *stream);
char uart_getchar(FILE *stream);

void uart_init(void);

/* http://www.ermicro.com/blog/?p=325 */

FILE uart_output = FDEV_SETUP_STREAM(uart_putchar, 0, _FDEV_SETUP_WRITE);
FILE uart_input = FDEV_SETUP_STREAM(0, uart_getchar, _FDEV_SETUP_READ);
