/*
 * main.c
 */
#include "MSP430G2553.h"
#include "UART_Event.h"
#include "UART_FIFO.h"
#include "UART_Global.h"
#include "UART_init.h"

const unsigned char testStr[]="hhhh命令:LED1_ON LED1_OFF LED2_ON LED2_OFF\r\n";
void main(void) {
	WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
	USCI_A0_init();
	UART_SendString(testStr);

__bis_SR_register(LPM3_bits) ;
	while(1){
	}
}
