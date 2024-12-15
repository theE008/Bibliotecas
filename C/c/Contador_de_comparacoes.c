/**
 * @date: 12/2024
 * @author: Thiago Pereira de Oliveira
 * @details: Conta a quantia de IFS sendo executada no seu código.
*/

#include "../h/Contador_de_comparacoes.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
// VARIÁVEIS

static unsigned long int comparacoes = 0;

/////////////////////////////////////////////////////////////////////////////////////////////////////
// FUNÇÕES

// get & add
int addComparacoes () {comparacoes++; return 1;}
int getComparacoes () {return comparacoes;}  

/////////////////////////////////////////////////////////////////////////////////////////////////////
// MAIN DE TESTE

int Testar_ContadorDeComparacoes ()
{
    printf("\n-------------------------------------------------------------\n");
    // Testando a contagem de comparações com a macro IF
    printf("Testando o contador de comparacoes:\n");

    // Variáveis para comparação
    int a = 5, b = 10, c = 5;

    // Realizando comparações usando a macro IF
    IF(a > b) 
    {
        printf("a eh maior que b\n");
    }

    IF(a < b) 
    {
        printf("a eh menor que b\n");
    }

    IF(a == c) 
    {
        printf("a eh igual a c\n");
    }

    // Exibindo o número de comparações realizadas
    printf("Numero de comparacoes realizadas: %d\n", getComparacoes());

    printf("\n-------------------------------------------------------------\n");

    return 0;
}