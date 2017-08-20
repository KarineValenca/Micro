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

### 3. Considerando a placa Launchpad do MSP430, escreva o código em C para piscar duas vezes os dois LEDs sempre que o usuário pressionar o botão.

### 4. Considerando a placa Launchpad do MSP430, faça uma função em C que pisca os dois LEDs uma vez.

### 5. Reescreva o código da questão 2 usando a função da questão 4.

### 6. Reescreva o código da questão 3 usando a função da questão 4.

