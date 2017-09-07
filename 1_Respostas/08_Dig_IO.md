Para todas as questões, utilize os LEDs e/ou os botões da placa Launchpad do MSP430.
1. Escreva um código em C que pisca os LEDs ininterruptamente.
```C
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
		led_blink();
		__delay_cycles(300000);
	}	


}```

2. Escreva um código em C que pisca os LEDs ininterruptamente. No ciclo que pisca os LEDs, o tempo que os LEDs ficam ligados deve ser duas vezes maior do que o tempo que eles ficam desligados.
```C
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
		led_blink();
		__delay_cycles(1000000);
		P1OUT = 0;
		__delay_cycles(500000);
		
	}	


}```

3. Escreva um código em C que acende os LEDs quando o botão é pressionado.
```C
#include <msp430g2553.h>	

#define BTN BIT3	
#define LED1 BIT0	
#define LED2 BIT6	

void led_on(){
    P1OUT ^= LED1 + LED2;
}
int main(void){	

	WDTCTL = WDTPW | WDTHOLD;

	P1DIR = LED1 + LED2;	
	P1REN = BTN;
	P1REN = BTN;

	for(;;) {	
		if((P1IN & BTN)!= BTN){
				led_on();
				P1OUT = BIT3;
		}
	

	}	
}

```

4. Escreva um código em C que pisca os LEDs ininterruptamente somente se o botão for pressionado.
```C
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

	for(;;) {	
		if((P1IN & BTN)!= BTN){
				led_blink();
				__delay_cycles(300000);
				P1OUT = BIT3;
				__delay_cycles(300000);
		}
	}	
}
```
5. Escreva um código em C que acende os LEDs quando o botão é pressionado. Deixe o MSP430 em modo de baixo consumo, e habilite a interrupção do botão.
```C
#include <msp430g2553.h>
#include <io.h>
#include <signal.h>	

#define BTN BIT3	
#define LED1 BIT0	
#define LED2 BIT6	


int main(void){	

	WDTCTL = WDTPW | WDTHOLD;

	P1DIR = LED1 + LED2;	

	// permite interrupacao para BTN 

	P1IE |= BTN;
	// configura borda de descida para BTN
	P1IES |= BTN;

	// Limpa flag para BTN
	P1IFG &= ~BTN;

	_BIS_SR(GIE);

	while (1);	
	return 0;
}

interrupt(PORT1_VECTOR) p1_isr(void) {
    switch (P1IFG & BTN) {
        case BTN:
            P1IFG = P1IFG & ~BTN;
			P1OUT ^= LED1 + LED2;
            break;
        default:
            break;
    }
    
    return;
}

```
