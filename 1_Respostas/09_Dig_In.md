1. Escreva uma função em C que faz o debounce de botões ligados à porta P1.
```C
//debounce de software de botões ligados à p1
int debounce (int entry){
  int value_compair = P1IN & entry;
  int i;
  for(i=0;i<1000; i++){
    if(P1IN & entry != value_compair){
      value_compair = P1IN & entry;
      i = 0;
    }
  }
}
```

2. Escreva um código em C que lê 9 botões multiplexados por 6 pinos, e pisca os LEDs da placa Launchpad de acordo com os botões. Por exemplo, se o primeiro botão é pressionado, os LEDs piscam uma vez; se o segundo botão é pressionado, os LEDs piscam duas vezes; e assim por diante. Se mais de um botão é pressionado, os LEDs não piscam.
