#include <stdio.h>

void mostrarBinario(unsigned char num)
{
    for(int i = 7; i >= 0; i--)
    {
        printf("%d", (num >> i) & 1);
    }
}

unsigned char binarioParaDecimal(char bin[])
{
    unsigned char valor = 0;

    for(int i = 0; i < 8; i++)
    {
        valor <<= 1;

        if(bin[i] == '1')
            valor |= 1;
    }

    return valor;
}

int main()
{
    char entrada[9];

    printf("Digite um numero binario de 8 bits: ");
    scanf("%8s", entrada);

    unsigned char numero = binarioParaDecimal(entrada);

    printf("\n========== REPRESENTACOES ==========\n");

    printf("Binario: [");
    mostrarBinario(numero);
    printf("]\n");

    printf("UInt: %u\n", numero);

    printf("2C: %d\n", (signed char)numero);

    printf("\n========== OPERACOES BIT A BIT ==========\n");

    printf("AND com 11110000: [");
    mostrarBinario(numero & 0b11110000);
    printf("]\n");

    printf("OR com 00001111:  [");
    mostrarBinario(numero | 0b00001111);
    printf("]\n");

    printf("XOR com 11111111: [");
    mostrarBinario(numero ^ 0b11111111);
    printf("]\n");

    printf("\n========== SHIFTS ==========\n");

    printf("Shift Logico Esquerda: [");
    mostrarBinario(numero << 1);
    printf("]\n");

    printf("Shift Logico Direita:  [");
    mostrarBinario(numero >> 1);
    printf("]\n");

    signed char aritmetico = (signed char)numero;

    printf("Shift Aritmetico Direita: [");
    mostrarBinario((unsigned char)(aritmetico >> 1));
    printf("]\n");

    unsigned char circularE = (numero << 1) | (numero >> 7);

    printf("Shift Circular Esquerda: [");
    mostrarBinario(circularE);
    printf("]\n");

    unsigned char circularD = (numero >> 1) | (numero << 7);

    printf("Shift Circular Direita:  [");
    mostrarBinario(circularD);
    printf("]\n");

    return 0;
}