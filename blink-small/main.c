#include <stdint.h>

#include "../include/common.h"
#include "../include/rcc.h"
#include "../include/gpio.h"

#define PIN 0

void prog(){

    REG(RCC + APB2PCENR) = IOPAEN;

    REG(GPIOA + CFGLR) &= Clear(PIN);
    REG(GPIOA + CFGLR) |= Output_PP_2MHz(PIN);

    while(1){
        for(volatile uint32_t i = 200000; i > 0; i--);
        REG(GPIOA + OUTDR) ^= Pin(PIN);
        for(volatile uint32_t i = 100000; i > 0; i--);
        REG(GPIOA + OUTDR) ^= Pin(PIN);
    }
}
