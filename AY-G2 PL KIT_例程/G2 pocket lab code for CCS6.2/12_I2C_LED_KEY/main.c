/*警告：由于G2 LaunchPad上的LED2使用了P1.6（I2C引脚），所以所有涉及到I2C的实验都必须把P1.6跳线拔除,包含本例程！
 * main.c
 */
#include"MSP430G2553.h"
#include"TCA6416A.h"

void WDT_init();
void I2C_IODect()	;		                 //检测事件确实发生了

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;	//关狗
    BCSCTL1 = CALBC1_16MHZ;      /* Set DCO to 8MHz */
    DCOCTL = CALDCO_16MHZ;
    TCA6416A_Init();			// 初始化IO扩展口
//----提示初始化成功----
	PinOUT(0,1);           // 指定0号管脚输出为0
	PinOUT(1,0);           // 指定1号管脚输出为0
	PinOUT(2,1);           // 指定0号管脚输出为0
	PinOUT(3,0);           // 指定1号管脚输出为0
	PinOUT(4,1);           // 指定0号管脚输出为0
	PinOUT(5,0);           // 指定1号管脚输出为0
	PinOUT(6,1);           // 指定0号管脚输出为0
	PinOUT(7,0);           // 指定1号管脚输出为0
	WDT_init();
	while(1)
	{
		PinIN();
		 I2C_IODect();
		 _bis_SR_register(LPM0_bits);
	}


}
/********WDT初始化函数**********/
void WDT_init()
{
	//-----设定WDT为-----------
	WDTCTL=WDT_ADLY_16;
	//-----WDT中断使能----------------------
    IE1 |= WDTIE;
}

/***********WDT定时中断函数*************/
#pragma vector=WDT_VECTOR
__interrupt void watchdog_timer(void)
{
//	PinIN();
//	 I2C_IODect();
__bic_SR_register_on_exit(LPM0_bits );
}
/**********I2C扩展IO中断事件处理函数***************/
void I2C_IO10_Onclick()
{
	static unsigned char turn = 1;
	turn ^= BIT0;
	PinOUT(0,turn);         //指定0号管脚输出为0&1
	PinOUT(1,turn);         //指定1号管脚输出为0&1
}
void I2C_IO11_Onclick()
{
	static unsigned char turn = 1;
	turn ^= BIT0;
	PinOUT(2,turn);         //指定2号管脚输出为0&1
	PinOUT(3,turn);         //指定3号管脚输出为0&1
}
void I2C_IO12_Onclick()
{
	static unsigned char turn = 1;
	turn ^= BIT0;
	PinOUT(5,turn);         //指定5号管脚输出为0&1
	PinOUT(4,turn);         //指定4号管脚输出为0&1
}
void I2C_IO13_Onclick()
{
	static unsigned char turn = 1;
	turn ^= BIT0;
	PinOUT(6,turn);         //指定6号管脚输出为0&1
	PinOUT(7,turn);         //指定7号管脚输出为0&1
}
void I2C_IODect()			                 //检测事件确实发生了
{
	static unsigned char KEY_Past=0,KEY_Now=0;
	KEY_Past=KEY_Now;
	//----判断I2C_IO10所连的KEY1按键是否被按下------
	if((TCA6416A_InputBuffer&BIT8) == BIT8)
		KEY_Now |=BIT0;
	else
		KEY_Now &=~BIT0;
	if(((KEY_Past&BIT0)==BIT0)&&(KEY_Now&BIT0) !=BIT0)
		I2C_IO10_Onclick();
	//----判断I2C_IO11所连的KEY2按键是否被按下------
	if((TCA6416A_InputBuffer&BIT9)== BIT9)
		KEY_Now |=BIT1;
	else
		KEY_Now &=~BIT1;
	if(((KEY_Past&BIT1)==BIT1)&&(KEY_Now&BIT1)!=BIT1)
		I2C_IO11_Onclick();
	//----判断I2C_IO12所连的KEY3按键是否被按下------
	if((TCA6416A_InputBuffer&BITA) == BITA)
		KEY_Now |=BIT2;
	else
		KEY_Now &=~BIT2;
	if(((KEY_Past&BIT2)==BIT2)&&(KEY_Now&BIT2) ==0)
	{
		I2C_IO12_Onclick();
	}
	//----判断I2C_IO13所连的KEY4按键是否被按下------
	if((TCA6416A_InputBuffer&BITB) ==  BITB)
		KEY_Now |=BIT3;
	else
		KEY_Now &=~BIT3;
	if(((KEY_Past&BIT3) == BIT3)&& (KEY_Now&BIT3) == 0)    //
	{
		I2C_IO13_Onclick();
	}
}
