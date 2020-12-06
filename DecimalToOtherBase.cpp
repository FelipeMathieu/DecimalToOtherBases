// DecimalToOtherBase.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

char *conversaoParaBinario(int numero)
{
    int c, d, t;
    char* p;

    t = 0;
    p = (char*)malloc(32 + 1);

    if (p == NULL)
        exit(EXIT_FAILURE);

    for (c = 31; c >= 0; c--)
    {
        d = numero >> c;

        if (d & 1)
        {
            *(p + t) = 1 + '0';
            t++;
        }
        else {
            if (t != 0) {
                *(p + t) = 0 + '0';
                t++;
            }
        }
    }
    *(p + t) = '\0';

    return p;
}

void conversaoParaOctal(int numero)
{
    int resultadoOctal[100];
    int c = numero;
    int i = 1;
    int j;

    while (c != 0)
    {
        resultadoOctal[i++] = c % 8;
        c = c / 8;
    }

    printf("O numero %d convertido para octal e: ", numero);
    for (j = i - 1; j > 0; j--)
        printf("%d", resultadoOctal[j]);
    printf("\n\n");
}

void conversaoParaHexadecimal(int numero)
{
    int c = numero;
    int aux;
    int i;
    int j = 0;
    char resultadoHexa[100];

    while (c != 0)
    {
        aux = c % 16;
        if (aux < 10)
            resultadoHexa[j++] = 48 + aux;
        else
            resultadoHexa[j++] = 55 + aux;
        c = c / 16;
    }

    printf("O numero %d convertido para hexadecimal e: ", numero);
    for (i = j - 1; i >= 0; i--)
        printf("%c", resultadoHexa[i]);
    printf("\n\n");
}

void calcularConversao(int numero, int base)
{
    char *resultadoBinario;
    switch (base)
    {
        case 2:
            printf("Base binaria selecionada!\nComecando conversao...\n");
            resultadoBinario = conversaoParaBinario(numero);
            printf("O numero %d convertido para binario e: %s\n\n", numero, resultadoBinario);
            break;
        case 8:
            printf("Base octal selecionada!\nComecando conversao...\n");
            conversaoParaOctal(numero);
            break;
        case 16:
            printf("Base hexadecimal selecionada!\nComecando conversao...\n");
            conversaoParaHexadecimal(numero);
            break;
        default:
            printf("Base informada nao pode ser calculada, tente novamente com as bases binaria, octal ou hexadecimal!\n");
            break;
    }
}

int main()
{
    float numero;
    int base;

    printf("Por favor informe um numero decimal:\n");
#pragma warning(suppress : 4996)
    scanf("%f", &numero);

    int inteiro = (int)numero;

    if (inteiro < 0) {
        printf("Valor inteiro considerado deve ser maior que 0\n\n");
        return 0;
    }

    printf("Valor inteiro considerado %d\n\n", inteiro);

    printf("Informe a base de conversao:\n");
#pragma warning(suppress : 4996)
    scanf("%d", &base);

    calcularConversao(inteiro, base);

    return 0;
}

// Executar programa: Ctrl + F5 ou Menu Depurar > Iniciar Sem Depuração
// Depurar programa: F5 ou menu Depurar > Iniciar Depuração

// Dicas para Começar: 
//   1. Use a janela do Gerenciador de Soluções para adicionar/gerenciar arquivos
//   2. Use a janela do Team Explorer para conectar-se ao controle do código-fonte
//   3. Use a janela de Saída para ver mensagens de saída do build e outras mensagens
//   4. Use a janela Lista de Erros para exibir erros
//   5. Ir Para o Projeto > Adicionar Novo Item para criar novos arquivos de código, ou Projeto > Adicionar Item Existente para adicionar arquivos de código existentes ao projeto
//   6. No futuro, para abrir este projeto novamente, vá para Arquivo > Abrir > Projeto e selecione o arquivo. sln
