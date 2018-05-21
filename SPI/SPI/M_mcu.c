#include <msp430g2553.h>

unsigned char MST_Data,SLV_Data;

int main(void)
{
	volatile unsigned int i;
	WDTCTL=WDTPW + WDTHOLD;      //关掉开门狗
	UCA0CTL1 |= UCSWRST;		//USCI_Ax模块逻辑复位
	P1OUT = 0x00;				//P1out初始化
	P1DIR |=BIT0+BIT5;			//P1.0 P1.5端口为输出
	P1SEL = BIT1+BIT2+BIT4;
	P1SEL2 = BIT1+BIT2+BIT4;
	UCA0CTL0 |=UCCKPL+UCMSB+UCMST+UCSYNC;//3线，8bit，SPI主机，前沿采样后沿输出，时钟空闲状态为高电平，高字节优先，同步通信
	UCA0CTL1 |= UCSSEL_2;				//选择SMCLK
	UCA0BR0 |= 0x02; 					//二分频配置波特率
	UCA0BR1 = 0;						//二分频配置波特率
	UCA0MCTL = 0;						 // No modulation
	UCA0CTL1 &= ~UCSWRST;                     // USCI_Ax复位释放

	IE2 |= UCA0RXIE;                          // 开启接收中断 Enable USCI0 RX interrupt
	P1OUT &= ~BIT5;                           // Now with SPI signals initialized,
	P1OUT |= BIT5;                            // reset slave

	__delay_cycles(75);                 // Wait for slave to initialize
	
	MST_Data = 0x01;                          // Initialize data values
	SLV_Data = 0x00;

	UCA0TXBUF = MST_Data;                     // Transmit first character

	__bis_SR_register(LPM0_bits + GIE);       // CPU off, enable interrupts
}

#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCIA0RX_ISR(void)
{
  volatile unsigned int i;

  while (!(IFG2 & UCA0TXIFG));              // 判断发送缓冲是否为空，如果为空，标志位置位，则说明上个数据未发送完毕，等待直到数据发送完毕

  if (UCA0RXBUF == SLV_Data)                // Test for correct character RX'd
    P1OUT |= BIT0;                          // If correct, light LED
  else
    P1OUT &= ~BIT0;                         // If incorrect, clear LED

  MST_Data++;                               // Increment master value
  SLV_Data++;                               // Increment expected slave value
  UCA0TXBUF = MST_Data;                     // Send next value

  __delay_cycles(50);                     // Add time between transmissions to
}                                           // make sure slave can keep up




