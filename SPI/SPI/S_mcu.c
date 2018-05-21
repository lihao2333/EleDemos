#include <msp430g2553.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // 关闭看门狗
  UCA0CTL1 |= UCSWRST;  					//USCI_AX模块逻辑复位
  while (!(P1IN & BIT4));                   // If clock sig from mstr stays low,
                                            // it is not yet in SPI mode
  P1SEL = BIT1 + BIT2 + BIT4;
  P1SEL2 = BIT1 + BIT2 + BIT4;
  UCA0CTL0 |= UCCKPL + UCMSB + UCSYNC;      // 3-pin, 8-bit SPI slave
  UCA0CTL1 &= ~UCSWRST;                     //USCI_Ax复位释放
  IE2 |= UCA0RXIE;                          // Enable USCI0 RX interrupt

  __bis_SR_register(LPM4_bits + GIE);       // Enter LPM4, enable interrupts
}

#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR (void)
{
  while (!(IFG2 & UCA0TXIFG));              // USCI_A0 TX buffer ready?
  UCA0TXBUF = UCA0RXBUF;
}
