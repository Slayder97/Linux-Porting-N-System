#ifndef __LED_MODULE_H__
#define __LED_MODULE_H__

#define GPIO_ADDR_BASE  0x44E07000
#define ADDR_SIZE       (0x44E07FFF - 0x44E07000)
#define GPIO_SETDATAOUT_OFFSET          0x194
#define GPIO_CLEARDATAOUT_OFFSET        0x190
#define GPIO_OE_OFFSET                  0x134
#define LED                             (1 << 31)

#endif
