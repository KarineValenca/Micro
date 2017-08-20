# Atividade 3 - Introdução MSP430

### 1. Dada uma variável a do tipo char (um byte), escreva os trechos de código em C para: 

(a) Somente setar o bit menos significativo de a.
```C
a = a | 0b00000001
```

(b) Somente setar dois bits de a: o menos significativo e o segundo menos significativo. 
```C
a = a | 0b00000011
```

(c) Somente zerar o terceiro bit menos significativo de a. 
```C
a = a & 0b11111011
```

(d) Somente zerar o terceiro e o quarto bits menos significativo de a. 
```C
a = a & 11110011
```

(e) Somente inverter o bit mais significativo de a. 
```C
int bitXor(int x, int y)
{
    return (x & ~y) | (~x & y);
}
... 
a = bitXor(int(a), 0b10000000)
```

(f) Inverter o nibble mais significativo de a, e setar o nibble menos significativo de a.
```C
int bitXor(int x, int y)
{
    return (x & ~y) | (~x & y);
}
... 
a = bitXor(int(a), 0b11110000)
a = a | 0b00001111

```

### 2. Considerando a placa Launchpad do MSP430, escreva o código em C para piscar os dois LEDs ininterruptamente.
```C
#include <msp430g2553.h>

int main(){
	WDTCTL = WDTPW | WDTHOLD;	

	P1DIR = BIT6 + BIT0;	

	P1OUT = BIT6 + BIT0;	

	for(;;)	{	
		P1OUT ^= BIT6 + BIT0;
		__delay_cycles(300000);
	}	

}
```
### 3. Considerando a placa Launchpad do MSP430, escreva o código em C para piscar duas vezes os dois LEDs sempre que o usuário pressionar o botão.
```C
#include <msp430g2553.h>	

#define BTN BIT3	

#define LED1 BIT0	

#define LED2 BIT6	

int main(void){	

	WDTCTL = WDTPW | WDTHOLD;

	P1DIR = LED1 + LED2;	
	P1REN = BTN;
	P1REN = BTN;

	int i;
	for(;;) {	
		if((P1IN & BTN)!= BTN){
			for(i=0; i<2; i++){
				P1OUT ^= LED1 + LED2;
				__delay_cycles(300000);
				P1OUT = BIT3;
				__delay_cycles(300000);
			}
		}
	

	}	
}
```

### 4. Considerando a placa Launchpad do MSP430, faça uma função em C que pisca os dois LEDs uma vez.
```C
#define LED1 BIT0	
#define LED2 BIT6

void led_blink(){
    P1OUT ^= LED1 + LED2;
}
```
### 5. Reescreva o código da questão 2 usando a função da questão 4.
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


}
```
### 6. Reescreva o código da questão 3 usando a função da questão 4.
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

```
