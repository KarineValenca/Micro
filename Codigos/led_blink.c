#include <msp430g2553.h>
#define LED1 BIT0	
#define LED2 BIT6

void led_blink(){
    P1OUT ^= LED1 + LED2;
}

int main(){
	WDTCTL = WDTPW | WDTHOLD;	

	P1DIR = LED1 + LED2;	

	P1OUT = LED1 + LED2;	

	for(;;)	{	
		blink_led();
		__delay_cycles(300000);
	}	


}
