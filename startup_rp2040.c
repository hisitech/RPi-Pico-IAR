#include "rp2040.h"

void main( void );
//-----------------------------------------------------------------------------
void irq_handler_reset(void);
void irq_handler_nmi(void);
void irq_handler_hard_fault(void);
void irq_handler_sv_call(void);
void irq_handler_pend_sv(void);
void irq_handler_sys_tick(void);

void irq_handler_timer0(void);
void irq_handler_timer1(void);
void irq_handler_timer2(void);
void irq_handler_timer3(void);
void irq_handler_pwm(void);
void irq_handler_usb(void);
void irq_handler_xip(void);
void irq_handler_pio_0_0(void);
void irq_handler_pio_0_1(void);
void irq_handler_pio_1_0(void);
void irq_handler_pio_1_1(void);
void irq_handler_dma0(void);
void irq_handler_dma1(void);
void irq_handler_io(void);
void irq_handler_qspi(void);
void irq_handler_sio0(void);
void irq_handler_sio1(void);
void irq_handler_clocks(void);
void irq_handler_spi0(void);
void irq_handler_spi1(void);
void irq_handler_uart0(void);
void irq_handler_uart1(void);
void irq_handler_adc(void);
void irq_handler_i2c0(void);
void irq_handler_i2c1(void);
void irq_handler_rtc(void);

#pragma weak irq_handler_nmi=irq_handler_dummy
#pragma weak irq_handler_hard_fault=irq_handler_dummy
#pragma weak irq_handler_sv_call=irq_handler_dummy
#pragma weak irq_handler_pend_sv=irq_handler_dummy
#pragma weak irq_handler_sys_tick=irq_handler_dummy
#pragma weak irq_handler_timer0=irq_handler_dummy
#pragma weak irq_handler_timer1=irq_handler_dummy
#pragma weak irq_handler_timer2=irq_handler_dummy
#pragma weak irq_handler_timer3=irq_handler_dummy
#pragma weak irq_handler_pwm=irq_handler_dummy
#pragma weak irq_handler_usb=irq_handler_dummy
#pragma weak irq_handler_xip=irq_handler_dummy
#pragma weak irq_handler_pio_0_0=irq_handler_dummy
#pragma weak irq_handler_pio_0_1=irq_handler_dummy
#pragma weak irq_handler_pio_1_0=irq_handler_dummy
#pragma weak irq_handler_pio_1_1=irq_handler_dummy
#pragma weak irq_handler_dma0=irq_handler_dummy
#pragma weak irq_handler_dma1=irq_handler_dummy
#pragma weak irq_handler_io=irq_handler_dummy
#pragma weak irq_handler_qspi=irq_handler_dummy
#pragma weak irq_handler_sio0=irq_handler_dummy
#pragma weak irq_handler_sio1=irq_handler_dummy
#pragma weak irq_handler_clocks=irq_handler_dummy
#pragma weak irq_handler_spi0=irq_handler_dummy
#pragma weak irq_handler_spi1=irq_handler_dummy
#pragma weak irq_handler_uart0=irq_handler_dummy
#pragma weak irq_handler_uart1=irq_handler_dummy
#pragma weak irq_handler_adc=irq_handler_dummy
#pragma weak irq_handler_i2c0=irq_handler_dummy
#pragma weak irq_handler_i2c1=irq_handler_dummy
#pragma weak irq_handler_rtc=irq_handler_dummy

#pragma segment  = "CSTACK"
//-----------------------------------------------------------------------------
#pragma location=".intvec"
void *const __vector_table[] =
{
  __sfe("CSTACK"),               // 0 - Initial Stack Pointer Value

  // Cortex-M0+ handlers
  (void *)irq_handler_reset,             // 1  - Reset
  (void *)irq_handler_nmi,               // 2  - NMI
  (void *)irq_handler_hard_fault,        // 3  - Hard Fault
  0,                             // 4  - Reserved
  0,                             // 5  - Reserved
  0,                             // 6  - Reserved
  0,                             // 7  - Reserved
  0,                             // 8  - Reserved
  0,                             // 9  - Reserved
  0,                             // 10 - Reserved
  (void *)irq_handler_sv_call,           // 11 - SVCall
  0,                             // 12 - Reserved
  0,                             // 13 - Reserved
  (void *)irq_handler_pend_sv,           // 14 - PendSV
  (void *)irq_handler_sys_tick,          // 15 - SysTick

  // Peripheral handlers
  (void *)irq_handler_timer0,            // 0  - Timer 0
  (void *)irq_handler_timer1,            // 1  - Timer 1
  (void *)irq_handler_timer2,            // 2  - Timer 2
  (void *)irq_handler_timer3,            // 3  - Timer 3
  (void *)irq_handler_pwm,               // 4  - PWM
  (void *)irq_handler_usb,               // 5  - USB
  (void *)irq_handler_xip,               // 6  - XIP
  (void *)irq_handler_pio_0_0,           // 7  - PIO_0_0
  (void *)irq_handler_pio_0_1,           // 8  - PIO_0_1
  (void *)irq_handler_pio_1_0,           // 9  - PIO_1_0
  (void *)irq_handler_pio_1_1,           // 10 - PIO_1_1
  (void *)irq_handler_dma0,              // 11 - DMA0
  (void *)irq_handler_dma1,              // 12 - DMA1
  (void *)irq_handler_io,                // 13 - IO
  (void *)irq_handler_qspi,              // 14 - Quad SPI
  (void *)irq_handler_sio0,              // 15 - SIO0
  (void *)irq_handler_sio1,              // 16 - SIO1
  (void *)irq_handler_clocks,            // 17 - CLOCKS
  (void *)irq_handler_spi0,              // 18 - SPI0
  (void *)irq_handler_spi1,              // 19 - SPI1
  (void *)irq_handler_uart0,             // 20 - UART0
  (void *)irq_handler_uart1,             // 21 - UART1
  (void *)irq_handler_adc,               // 22 - ADC
  (void *)irq_handler_i2c0,              // 23 - I2C0
  (void *)irq_handler_i2c1,              // 24 - I2C1
  (void *)irq_handler_rtc,               // 25 - Real Time Clock
};

//-----------------------------------------------------------------------------
void irq_handler_reset(void)
{
  scb_hw->vtor = (uint32_t)__vector_table;

  main();

  while (1);
}

//-----------------------------------------------------------------------------
void irq_handler_dummy(void)
{
  while (1);
}

//-----------------------------------------------------------------------------
/* the first 256 bytes is CRC-32 protected bootstrap code to configure the flash QSPI */
#pragma location=".boot2"
const uint8_t bs2[] =
{
  0x00, 0xb5, 0x32, 0x4b, 0x21, 0x20, 0x58, 0x60, 0x98, 0x68, 0x02, 0x21, 0x88, 0x43, 0x98, 0x60,
  0xd8, 0x60, 0x18, 0x61, 0x58, 0x61, 0x2e, 0x4b, 0x00, 0x21, 0x99, 0x60, 0x02, 0x21, 0x59, 0x61,
  0x01, 0x21, 0xf0, 0x22, 0x99, 0x50, 0x2b, 0x49, 0x19, 0x60, 0x01, 0x21, 0x99, 0x60, 0x35, 0x20,
  0x00, 0xf0, 0x44, 0xf8, 0x02, 0x22, 0x90, 0x42, 0x14, 0xd0, 0x06, 0x21, 0x19, 0x66, 0x00, 0xf0,
  0x34, 0xf8, 0x19, 0x6e, 0x01, 0x21, 0x19, 0x66, 0x00, 0x20, 0x18, 0x66, 0x1a, 0x66, 0x00, 0xf0,
  0x2c, 0xf8, 0x19, 0x6e, 0x19, 0x6e, 0x19, 0x6e, 0x05, 0x20, 0x00, 0xf0, 0x2f, 0xf8, 0x01, 0x21,
  0x08, 0x42, 0xf9, 0xd1, 0x00, 0x21, 0x99, 0x60, 0x1b, 0x49, 0x19, 0x60, 0x00, 0x21, 0x59, 0x60,
  0x1a, 0x49, 0x1b, 0x48, 0x01, 0x60, 0x01, 0x21, 0x99, 0x60, 0xeb, 0x21, 0x19, 0x66, 0xa0, 0x21,
  0x19, 0x66, 0x00, 0xf0, 0x12, 0xf8, 0x00, 0x21, 0x99, 0x60, 0x16, 0x49, 0x14, 0x48, 0x01, 0x60,
  0x01, 0x21, 0x99, 0x60, 0x01, 0xbc, 0x00, 0x28, 0x00, 0xd0, 0x00, 0x47, 0x12, 0x48, 0x13, 0x49,
  0x08, 0x60, 0x03, 0xc8, 0x80, 0xf3, 0x08, 0x88, 0x08, 0x47, 0x03, 0xb5, 0x99, 0x6a, 0x04, 0x20,
  0x01, 0x42, 0xfb, 0xd0, 0x01, 0x20, 0x01, 0x42, 0xf8, 0xd1, 0x03, 0xbd, 0x02, 0xb5, 0x18, 0x66,
  0x18, 0x66, 0xff, 0xf7, 0xf2, 0xff, 0x18, 0x6e, 0x18, 0x6e, 0x02, 0xbd, 0x00, 0x00, 0x02, 0x40,
  0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x07, 0x00, 0x00, 0x03, 0x5f, 0x00, 0x21, 0x22, 0x00, 0x00,
  0xf4, 0x00, 0x00, 0x18, 0x22, 0x20, 0x00, 0xa0, 0x00, 0x01, 0x00, 0x10, 0x08, 0xed, 0x00, 0xe0,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x74, 0xb2, 0x4e, 0x7a,
};

