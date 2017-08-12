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
TO DO

### 4. Quais são as diferenças, vantagens e desvantagens das arquiteturas Harvard e Von Neumann?
A principal diferença é que na arquitetura de Harvard, a CPU tem um barramento para a memória não volátil e outro barramento para a memória volátil. Enquanto a arquitetura de Von Neumann possui apenas um barramento para acessar tanto a memória volátil quanto a não volátil.
TO DO

### 5. Considere a variável inteira i, armazenando o valor 0x8051ABCD. Se i é armazenada na memória a partir do endereço 0x0200, como ficam este byte e os seguintes, considerando que a memória é: (a) Little-endian; (b) Big-endian.
TO DO

### 6. Sabendo que o processador do MSP430 tem registradores de 16 bits, como ele soma duas variáveis de 32 bits?

TO DO
