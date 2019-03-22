//
// Created by vidwalk on 3/22/19.
//
#include <stdio.h>
#include <stdio_driver.h>
#include <USBAPI.h>


int main(void)
{
    stdioCreate(0);
    sei();

    puts("Program started");

    uint16_t counter = 0;

    while(1)
    {
        printf("The counter value: %05d and in hex: %04X\n", counter, counter);
        counter++;

        if(stdioInputWaiting())
        {
            printf("###>%c\n", getchar());
        }

        _delay_ms(500);
    }
}
