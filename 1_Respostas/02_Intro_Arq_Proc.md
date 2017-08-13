# Atividade 2 - Introdução à Arquitetura de Processadores

### 1. Quais as diferenças entre os barramentos de dados e de endereços?
O barramento de endereço é utilizado para informar aos endereços físicos da memória que um dispositivo deseja acessá-lo.

O barramento de dados é utilizado para troca de dados entre dispositivos.

### 2. Quais são as diferenças entre as memórias RAM e ROM?
A memória RAM é uma memória volátil, ou seja, quando à queda de energia, as informações contidas nela são perdidas. Além disso, seu tipo de acesso é aleatório, ou seja, não sequencial.
Já a memória ROM é uma memória tipo leitura e não é volátil, seus dados so mantidos mesmo após quedas de energia. Seu acesso é sequencial.

### 3. Considere o código abaixo:

    #include <stdio.h>
        int main(void)
        {
	    int i;
            printf("Insira um número inteiro: ");
	    scanf("%d", &i);
	    if(i%2)
		printf("%d eh impar.\n");
	    else
		printf("%d eh par.\n");
	    return 0;
        }

### Para este código, responda: (a) A variável i é armazenada na memória RAM ou ROM? Por quê? (b) O programa compilado a partir deste código é armazenado na memória RAM ou ROM? Por quê?

a) A variável i fica armazenada na memória RAM, isso por que não é importante que o conteúdo dessa variável seja mantido mesmo após uma queda de energia, além disso, é interessante que essa variável seja acessada rapidamente para mostrar o resultado ao usuário, por isso, a memória RAM é mais adequada.

b) Os programas compilados ficam na memória ROM, pois além de ser uma informação relativamente grande, é importante que o programa compilado não se perca em perdas de energia.

### 4. Quais são as diferenças, vantagens e desvantagens das arquiteturas Harvard e Von Neumann?
A principal diferença é que na arquitetura de Harvard, a CPU tem um barramento para a memória não volátil e outro barramento para a memória volátil. Enquanto a arquitetura de Von Neumann possui apenas um barramento para acessar tanto a memória volátil quanto a não volátil.

A vantagem da arquitetura de Von Neumann é que ela é mais simples de ser implementada e sua desvangem é que ela não permite acesso simultâneo às memórias, tornando-a mais lenta.

A vantagem da arquitetura de Harvard é que ela é mais rápida, devido aos acessos simultâneos às memórias, porém, como desvatagem, é uma arquitetura mais difícil de ser implementada.

### 5. Considere a variável inteira i, armazenando o valor 0x8051ABCD. Se i é armazenada na memória a partir do endereço 0x0200, como ficam este byte e os seguintes, considerando que a memória é: (a) Little-endian; (b) Big-endian.

a) Litte-Endian

0x0200 -> 0xCD

0x0201 -> 0xAB

0x0202 -> 0x51

0x0203 -> 0x80

b) Big-Endian

0x0200 -> 0x80

0x0201 -> 0x51

0x0202 -> 0xAB

0x0203 -> 0xCD

### 6. Sabendo que o processador do MSP430 tem registradores de 16 bits, como ele soma duas variáveis de 32 bits?

Nesse tipo situação, para realizar a soma de variáveis com tamanho maior que 16 bits, ele utiliza o carry bit. 
