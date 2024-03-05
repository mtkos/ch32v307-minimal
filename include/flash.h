#define FLASH 040022000
#define   KEYR 0x4
#define     KEY1 0x45670123
#define     KEY2 0xcdef89ab
#define   OBKEYR 0x8
#define   STATR 0xc
#define     EOP 1<<5
#define     BUSY 1<<0
#define   FLASH_CTLR 0x10
#define     LOCK 1<<7
#define     STRT 1<<6
#define     OBER 1<<5
#define     OBPG 1<<4
#define   MODEKEYR 0x24
