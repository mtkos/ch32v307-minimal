#include <stdint.h>

#include "../include/common.h"
#include "../include/pfic.h"
#include "../include/rcc.h"
#include "../include/gpio.h"
#include "../include/exti.h"
#include "../include/afio.h"

#define EXTI1_IRQn 23

#define PIN0 0
#define PIN1 1

void EXTI1_IRQHandler() __attribute__((interrupt));

void EXTI1_IRQHandler(){
    REG(EXTI + INTFR) = Pin(PIN1);
}

void prog(){

    REG(RCC + APB2PCENR) = IOPAEN | AFIOEN;

    REG(GPIOA + CFGLR) &= Clear(PIN1);
    REG(GPIOA + CFGLR) |= Input_PUPD(PIN1);

    REG(GPIOA + CFGLR) &= Clear(PIN0);
    REG(GPIOA + CFGLR) |= Output_PP_2MHz(PIN0);

    REG(AFIO + EXTICR1) = PA_Exti(PIN1);
    REG(EXTI + INTENR) = Pin(PIN1);
    REG(EXTI + FTENR) = Pin(PIN1);  // falling edge trigger

    REG(PFIC + IENR0) = 1<<EXTI1_IRQn;

    while(1){
        __asm__ volatile("wfi");
        REG(GPIOA + OUTDR) ^= Pin(PIN0);
    }
}
