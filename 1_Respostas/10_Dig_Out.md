1. Projete o hardware necessário para o MSP430 controlar um motor DC de 12V e 4A. Utilize transistores bipolares de junção (TBJ) com Vbe = 0,7 V, beta = 100 e Vce(saturação) = 0,2 V. Além disso, considere que Vcc = 3 V para o MSP430, e que este não pode fornecer mais do que 10 mA por porta digital.
```
Ic = Ib * beta²
4 = Ib * 100²
Ib = 4/10000
Ib = 4*10^-4
Ib = 0.4 mA

Rb = (Vcc-2*Vbe)/Ib
Rb = (3-2*0.7)/0.0004
Rb = (3-1.4)/0.0004
Rb = 4000 ohm

```


2. Projete o hardware necessário para o MSP430 controlar um motor DC de 10V e 1A. Utilize transistores bipolares de junção (TBJ) com Vbe = 0,7 V e beta = 120. Além disso, considere que Vcc = 3,5 V para o MSP430, e que este não pode fornecer mais do que 10 mA por porta digital.
```
Ic = Ib * beta²
1 = Ib * 120²
Ib = 1/14400
Ib = 69.44 uA

Rb = (Vcc-2*Vbe)/Ib
Rb = (3.5-2*0.7)/0.00006944
Rb = 2.1/0.00006944
Rb = 30241.93 ohm

```

3. Projete o hardware utilizado para controlar 6 LEDs utilizando charlieplexing. Apresente os pinos utilizados no MSP430 e os LEDs, nomeados L1-L6.
![im](https://user-images.githubusercontent.com/8433187/30514980-4a185302-9af6-11e7-86cc-74e748188dc9.png)

Para acender:
L1: P1.0 = entrada digital P1.1 = 1 P1.2 = 0 
L2: P1.0 = entrada digital P1.1 = 0 P1.2 = 1
L3: P1.0 = 1 P1.1 = 0 P1.2 = entrada digital
L4: P1.0 = 0 P1.1 = 1 P1.2 = entrada digital
L5: P1.0 = 1 P1.1 = entrada digital P1.2 = 0
L6: P1.0 = 0 P1.1 = entrada digital P1.2 = 1


4. Defina a função `void main(void){}` para controlar 6 LEDs de uma árvore de natal usando o hardware da questão anterior. Acenda os LEDs de forma que um ser humano veja todos acesos ao mesmo tempo.
```C
void main(void){}
	char anodo[] = {BIT1,BIT2 ,BIT0, BIT1, BIT0, BIT2};
	char catodo[] = {BIT2, BIT1, BIT1, BIT0, BIT2, BIT0};
	char entrada[] = {BIT0, BIT0, BIT2, BIT2, BIT1, BIT1};
	int i = 0;
	while(1){
		PIDIR |= (anodo[i] + catodo[i]);
		P1DIR &= entrada[i];
		P1OUT |= anodo[i];
		P1OUT &= ~catodo[i];
		//fazer módulo 6
		i = (i+1)%6;
	}
```

5. Defina a função `void main(void){}` para controlar 6 LEDs de uma árvore de natal usando o hardware da questão 3. Acenda os LEDs de forma que um ser humano veja os LEDs L1 e L2 acesos juntos por um tempo, depois os LEDs L3 e L4 juntos, e depois os LEDs L5 e L6 juntos.
```C
int atraso(int unsigned volatile i){
	while((i--)>0)
}

void main(void){}
	char anodo[] = {BIT1,BIT2 ,BIT0, BIT1, BIT0, BIT2};
	char catodo[] = {BIT2, BIT1, BIT1, BIT0, BIT2, BIT0};
	char entrada[] = {BIT0, BIT0, BIT2, BIT2, BIT1, BIT1};
	int i = 0;
	while(1){
		PIDIR |= (anodo[i] + catodo[i]);
		P1DIR &= entrada[i];
		P1OUT |= anodo[i];
		P1OUT &= ~catodo[i];
		
		i = (i+1)%6;
		
		if(i%2 != 0){
			_delay_cycles(1000);
		}
	}
```

6. Defina a função `void EscreveDigito(volatile char dig);` que escreve um dos dígitos 0x0-0xF em um único display de 7 segmentos via porta P1, baseado na figura abaixo. Considere que em outra parte do código os pinos P1.0-P1.6 já foram configurados para corresponderem aos LEDs A-G, e que estes LEDs possuem resistores externos para limitar a corrente.

```
        ---  ==> A
       |   |
 F <== |   | ==> B
       |   |
        ---  ==> G
       |   |
 E <== |   | ==> C
       |   |
        ---  ==> D
```


```C
void EscreveDigito(volatile int dig){
	switch('dig'){
		case 0:
			P1OUT &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR |= BIT0+BIT1+BIT2+BIT3+BIT4+BIT5;
			P1OUT |= BIT0+BIT1+BIT2+BIT3+BIT4+BIT5;
		case 1:
			P1OUT &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR |= BIT1+BIT2;
			P1OUT |= BIT1+BIT2;
		case 2:
			P1OUT &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR |= BIT0+BIT1+BIT6+BIT4+BIT3;
			P1OUT |= BIT0+BIT1+BIT6+BIT4+BIT3;
		case 3:
			P1OUT &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR |= BIT0+BIT1+BIT6+BIT2+BIT3;
			P1OUT |= BIT0+BIT1+BIT6+BIT2+BIT3;
		case 4:
			P1OUT &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR |= BIT5+BIT6+BIT1+BIT2;
			P1OUT |= BIT5+BIT6+BIT1+BIT2;
		case 5:
			P1OUT &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR |= BIT0+BIT5+BIT6+BIT2+BIT3;
			P1OUT |= BIT0+BIT5+BIT6+BIT2+BIT3;
		case 6:
			P1OUT &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR |= BIT0+BIT5+BIT4+BIT3+BIT2+BIT6;
			P1OUT |= BIT0+BIT5+BIT4+BIT3+BIT2+BIT6;
		case 7:
			P1OUT &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR |= BIT0+BIT1+BIT2;
			P1OUT |= BIT0+BIT1+BIT2;
		case 8:
			P1OUT &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR |= BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1OUT |= BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
		case 9:
			P1OUT &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR |= BIT0+BIT1+BIT6+BIT5+BIT3;
			P1OUT |= BIT0+BIT1+BIT6+BIT5+BIT3;
		case 10:
			P1OUT &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR |= BIT0+BIT1+BIT6+BIT5+BIT2+BIT4;
			P1OUT |= BIT0+BIT1+BIT6+BIT5+BIT2+BIT4;
		case 11:
			P1OUT &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR |= BIT5+BIT4+BIT3+BIT2+BIT6;
			P1OUT |= BIT5+BIT4+BIT3+BIT2+BIT6;
		case 12:
			P1OUT &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR |= BIT0+BIT5+BIT4+BIT3;
			P1OUT |= BIT0+BIT5+BIT4+BIT3;
		case 13:
			P1OUT &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR |= BIT1+BIT2+BIT3+BIT4+BIT6;
			P1OUT |= BIT1+BIT2+BIT3+BIT4+BIT6;
		case 14:
			P1OUT &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR |= BIT0+BIT5+BIT6+BIT4+BIT3;
			P1OUT |= BIT0+BIT5+BIT6+BIT4+BIT3;
		case 15:
			P1OUT &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR &=~BIT0+BIT1+BIT2+BIT3+BIT4+BIT5+BIT6;
			P1DIR |= BIT0+BIT5+BIT6+BIT4;
			P1OUT |= BIT0+BIT5+BIT6+BIT4;
		
	}
}
```
7. Multiplexe 2 displays de 7 segmentos para apresentar a seguinte sequência em loop:
	00 - 11 - 22 - 33 - 44 - 55 - 66 - 77 - 88 - 99 - AA - BB - CC - DD - EE - FF
```C
int atraso(int unsigned volatile i){
	while((i--)>0)
}
int main(){
	WDTCTL = WDTPW|WDTHOLD;
	int i = 0;
	
	
	while(1){
		P1DIR|=BIT7;
    		P1OUT|=BIT7;
		EscreveDigito(i);
    		P1DIR|=BIT0;
		P1OUT|=BIT0;
		EscreveDigito(i);
		atraso(1000);
	}
	
} 
```
