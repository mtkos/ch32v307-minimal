#include <stdint.h>

#include "../include/common.h"
#include "../include/pfic.h"
#include "../include/systick.h"
#include "../include/rcc.h"
#include "../include/gpio.h"

#define SysTicK_IRQn 12

#define PIN0 0
#define PIN1 1

volatile uint8_t onoff[2];
volatile uint32_t period;

extern uint32_t _sidata, _sdata, _edata, _ebss, _sbss;

void SysTick_Handler() __attribute__((interrupt));

void SysTick_Handler(){

    REG(GPIOA + BSHR) = Pin(PIN1 + 16*onoff[1]);
    REG(SysTick + SR) = 0;
    onoff[1] = 1 - onoff[1];
}

void flash_to_ram(){

    uint32_t *p_idata = &_sidata;

    for(uint32_t *p_data = &_sdata; p_data < &_edata; *p_data++ = *p_idata++);
    for(uint32_t *p_bss = &_sbss; p_bss < &_ebss; *p_bss++ = 0);

}

void inc(){

    period += 1000;
}

void prog(){

    flash_to_ram();

    REG(RCC + APB2PCENR) |= IOPAEN;

    REG(GPIOA + CFGLR) &= Clear(PIN0);
    REG(GPIOA + CFGLR) |= Output_PP_2MHz(PIN0);
    REG(GPIOA + CFGLR) &= Clear(PIN1);
    REG(GPIOA + CFGLR) |= Output_PP_2MHz(PIN1);

    REG(SysTick + CNTR) = 0;
    REG(SysTick + CMPR) = 1000000;
    REG(SysTick + CTLR) = STE | STIE | STRE;

    REG(PFIC + IENR0) = 1<<SysTicK_IRQn;

    while(1){
        for(volatile uint32_t i = period; i; i--);
        REG(GPIOA + BSHR) = Pin(PIN0 + 16*onoff[0]);
        onoff[0] = 1 - onoff[0];
        inc();
    }
}
