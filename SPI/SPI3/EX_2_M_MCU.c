#include <msp430g2553.h>

void SPI_init_m(void)
{ //--------引脚初始化为SPI功能------
	P1SEL |= BIT1+BIT2+BIT4;				//P1.1为SIMO P1.2为SOMI P1.4为同步时钟
	P1SEL2 |= BIT1+BIT2+BIT4;
	P1DIR |=BIT1+BIT4;					//主MCU：设置P1.1 P1.4为输出
////  //--------对UCA0进行设置-----------------
    UCA0CTL1 |= UCSWRST;		//USCI_Ax模块逻辑复位
    UCA0CTL0 |=UCCKPL+UCMSB+UCMST+UCSYNC;//3线，8bit，SPI主机，前沿采样后沿输出，时钟空闲状态为高电平，高字节优先，同步通信
    UCA0CTL1 |= UCSSEL_2;				//选择SMCLK
    UCA0BR0 |= 0x02; 					//二分频配置波特率
    UCA0BR1 = 0;						//二分频配置波特率
    UCA0MCTL = 0;						 // No modulation
    UCA0CTL1 &= ~UCSWRST;                     // USCI_Ax复位释放
//    IE2 |= UCA0RXIE;//+UCA0TXIE;              //使能接收和发送中断
 // //--------使能CS引脚为输出功能-------------
 //   P1OUT = 0x00;				//P1out初始化
 //   P1DIR |= BIT5;			//P1.0 P1.5端口为输出
 //   P1OUT &= ~BIT5;                           // Now with SPI signals initialized,
 //   P1OUT |= BIT5;                            // reset slave
 // //--------清除中断标志位------------
 // IFG2 &= ~ (UCA0RXIFG+UCA0TXIFG);
  //--------开启CPU低功耗模式----------
//  __bis_SR_register(LPM0_bits + GIE);       // CPU off, enable interrupts
}

void SPI_send(unsigned int Tx_data)
{
	 while (!(IFG2 & UCA0TXIFG));                // 判断发送缓冲区是否为空。
       UCA0TXBUF = Tx_data;                          // 将数据发送到串口。

}

void GPIO_init()
{
  	P1DIR |= BIT6;
	P1OUT |= BIT6;
	//-----配合机械按键，启用内部上拉电阻-----
	P1REN |= BIT3;				        //启用P1.3内部上下拉电阻
	P1OUT |= BIT3;			            //将电阻设置为上拉
	//-----配置P1.3中断参数-----
	P1DIR &= ~BIT3;                    // P1.3设为输入(可省略)
	P1IES |= BIT3;                          // P1.3设为下降沿中断
	P1IE  |= BIT3 ;                          // 允许P1.3中断
	_EINT();
}


void P13_Onclick(void)
{
	static int cnt=0;
	unsigned char SPI_table[]={0x01,0x03,0x05,0x07};
	cnt=(++cnt)%4;
	//SPI_send(SPI_table[cnt]);
	P1OUT^=BIT6;
	}

void P1_IODect(void)
{
	unsigned int Push_Key=0;
	//-----排除输出IO的干扰后，锁定唯一被触发的中断标志位-----
	Push_Key=P1IFG&(~P1DIR);
	//-----延时一段时间，避开机械抖动区域-----
	__delay_cycles(10000);							//消抖延时
	//----判断按键状态是否与延时前一致-----
	if((P1IN&Push_Key)==0) 	                	//如果该次按键确实有效
   {
	 //----判断具体哪个IO被按下，调用该IO的事件处理函数-----
	  switch(Push_Key){
//	 case BIT0:	P10_Onclick();		break;
//	 case BIT1: 	P11_Onclick();		break;
//	 case BIT2: 	P12_Onclick();		break;
	 case BIT3: 	P13_Onclick();		break;
//	 case BIT4: 	P14_Onclick();		break;
//	 case BIT5: 	P15_Onclick();		break;
//	 case BIT6: 	P16_Onclick();		break;
//	 case BIT7: 	P17_Onclick();		break;
	 default:									break;		//任何情况下均加上default
	 }
   }
}

#pragma vector = PORT1_VECTOR
__interrupt void PORT1_ISR(void)
{
	//-----启用Port1事件检测函数-----
	P1_IODect();								//检测通过，则会调用事件处理函数
   	P1IFG=0;                            			//退出中断前必须手动清除IO口中断标志
}

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;                     // 关闭看门狗。
	GPIO_init();
	SPI_init_m();
	while(1);
}
