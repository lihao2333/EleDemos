#include <msp430g2553.h>

void SPI_init_s(void)
{ 	P1DIR |= BIT0+BIT6;
	//--------引脚初始化为SPI功能------
	P1SEL = BIT1+BIT2+BIT4;				//P1.1为SIMO P1.2为SOMI P1.4为同步时钟
	P1SEL2 = BIT1+BIT2+BIT4;
	P1DIR |=BIT1+BIT4;					//主MCU：设置P1.1 P1.4为输出
  //--------对UCA0进行设置-----------------
    UCA0CTL1 |= UCSWRST;		//USCI_Ax模块逻辑复位
	UCA0CTL0 |=UCCKPL+UCMSB+UCMST+UCSYNC;//3线，8bit，SPI主机，前沿采样后沿输出，时钟空闲状态为高电平，高字节优先，同步通信
	UCA0CTL1 |= UCSSEL_2;				//选择SMCLK
	UCA0BR0 |= 0x02; 					//二分频配置波特率
	UCA0BR1 = 0;						//二分频配置波特率
	UCA0MCTL = 0;						 // No modulation
	UCA0CTL1 &= ~UCSWRST;                     // USCI_Ax复位释放
    IE2 |= UCA0RXIE;              //使能接收中断
  //--------使能CS引脚为输出功能（从机不需要）-------------
	//P1OUT = 0x00;				//P1out初始化
	//P1DIR |= BIT5;			//P1.0 P1.5端口为输出
	//P1OUT &= ~BIT5;                           // Now with SPI signals initialized,
	//P1OUT |= BIT5;                            // reset slave
  //--------清除中断标志位------------
  IFG2 &= ~ (UCA0RXIFG+UCA0TXIFG);
  //--------开启CPU低功耗模式----------
  __bis_SR_register(LPM0_bits + GIE);       // CPU off, enable interrupts
}

#pragma vector=USCIAB0RX_VECTOR
__interrupt void USCI0RX_ISR_HOOK(void)
{
      unsigned char Rx_data;
	  Rx_data= UCA0RXBUF;
	  switch(Rx_data)
	  {
		  case 0x01:
				P1OUT &=~ BIT1 + BIT6;
				break;
		  case 0x03:
				P1OUT |= BIT6;
				break;
		  case 0x05:
		        P1OUT |= BIT1+BIT6;
				break;
		  case 0x07:
				P1OUT |= BIT1;
				break;
		  default:
		        P1OUT &=~ BIT1+BIT6;
				break;

	  }

}

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;                    // 关闭看门狗。
	SPI_init_s();
	while(1);

}
