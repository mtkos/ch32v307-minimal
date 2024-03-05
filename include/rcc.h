#define RCC 0x40021000
#define   CTLR 0x0
#define     PLLRDY 1<<25
#define     PLLON 1<<24
#define   CFGR0 0x4
#define     HPRE_Reset_Mask 0xFFFFFF0F
#define     HPRE_DIV1 0
#define     PLL_MUL6 (0b0100 << 18)
#define     PLL_MUL18 (0b0000 << 18)
#define     SW_PLL 0x2
#define   AHBPCENR 0x14
#define    RCC_RNGEN 1<<9
#define    DMA1EN 1<<0
#define   APB2PCENR 0x18
#define     USART1EN 1<<14
#define     TIM1EN 1<<11
#define     IOPEEN 1<<6
#define     IOPDEN 1<<5
#define     IOPCEN 1<<4
#define     IOPBEN 1<<3
#define     IOPAEN 1<<2
#define     AFIOEN 1<<0
#define   APB1PCENR 0x1c
#define     TIM2EN 1<<0