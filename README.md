This project demonstrates how to control an LED on STM32F407VG
using bare-metal programming.
 What I Did:
- Located RCC and GPIOD base addresses from reference manual
- Calculated register addresses using base + offset
- Enabled GPIOD clock via RCC_AHB1ENR
- Configured PD12 as output
- Set PD12 HIGH using ODR register

Key Concepts Used:
- Memory-mapped I/O
- Volatile keyword
- Bit manipulation
- Direct register access
