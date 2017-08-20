#include <msp430g2553.h>	

#define BTN BIT3	
#define LED1 BIT0	
#define LED2 BIT6	

void led_blink(){
    P1OUT ^= LED1 + LED2;
}
int main(void){	

	WDTCTL = WDTPW | WDTHOLD;

	P1DIR = LED1 + LED2;	
	P1REN = BTN;
	P1REN = BTN;

	int i;
	for(;;) {	
		if((P1IN & BTN)!= BTN){
			for(i=0; i<2; i++){
				led_blink();
				__delay_cycles(300000);
				P1OUT = BIT3;
				__delay_cycles(300000);
			}
		}
	

	}	
}

