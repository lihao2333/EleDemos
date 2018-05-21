/* Blink LED example */
 
#include<msp430g2553.h>
typedef unsigned int unsignedint ;
int temp=300;
/** Delay function. **/
delay(unsignedint d){
int i;
for(i =0; i<d; i++){
nop();
}
}
 
int main(void){
WDTCTL = WDTPW | WDTHOLD;
P1DIR =0xFF;
P1OUT =0x01;
 
for(;;){
P1OUT =~P1OUT;
delay(0x4fff);
}
}
