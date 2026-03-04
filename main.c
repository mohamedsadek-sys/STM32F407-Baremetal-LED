/*
 * STM32F407VG - Bare Metal LED Control (PD12)
 * Author: Mohamed Sadek
 *
 * Description:
 *  - Enables clock for GPIOD
 *  - Configures PD12 as output
 *  - Sets PD12 HIGH
 *  Direct register access using memory-mapped I/O
 *  Reference Manual: RM0090 (STM32F407)
 */

#include <stdint.h>

/* Base Addresses */
#define RCC_BASE        0x40023800UL
#define GPIOD_BASE      0x40020C00UL

/* Register Offsets */
#define RCC_AHB1ENR_OFFSET   0x30UL
#define GPIO_MODER_OFFSET    0x00UL
#define GPIO_ODR_OFFSET      0x14UL

/* Register Definitions */
#define RCC_AHB1ENR   (*(volatile uint32_t *)(RCC_BASE + RCC_AHB1ENR_OFFSET))
#define GPIOD_MODER   (*(volatile uint32_t *)(GPIOD_BASE + GPIO_MODER_OFFSET))
#define GPIOD_ODR     (*(volatile uint32_t *)(GPIOD_BASE + GPIO_ODR_OFFSET))

int main(void)
{
    /* 1. Enable clock for GPIOD (bit 3 in RCC_AHB1ENR) */
    RCC_AHB1ENR |= (1 << 3);

    /* 2. Configure PD12 as output
       Each pin uses 2 bits in MODER register
       PD12 -> bits 24 and 25
       00: Input
       01: Output
    */

    GPIOD_MODER &= ~(3 << (12 * 2));  // Clear bits 24-25
    GPIOD_MODER |=  (1 << (12 * 2));  // Set bit 24 (01:output)

    /* 3. Set PD12 HIGH */
    GPIOD_ODR |= (1 << 12);

    while (1)
    {
        // Infinite loop
    }
}
