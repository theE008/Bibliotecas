/**
 * @date: 12/2024
 * @author: Thiago Pereira de Oliveira
 * @details: Melhor manutenção de ponteiros em C com esta biblioteca.
*/

#include "Gerenciador_de_memoria.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
// VARIÁVEIS

// Variáveis globais para contar tratamentos de memória
static int reservas_feitas = 0;
static int limpezas_feitas = 0;

// GETS
int getLixo_de_memoria () {return reservas_feitas - limpezas_feitas;}
int getReservas_feitas () {return reservas_feitas;}
int getLimpezas_feitas () {return limpezas_feitas;}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// FUNÇÕES DE OVERLOAD

// Sobrescrevendo malloc usando um macro
void* MALLOC_OVERWRITER (size_t size){void* tmp = __builtin_malloc(size); if (tmp == NULL) printf \
("\n\nERRO AO TENTAR RESERVAR ESPACO\n\n"); else {reservas_feitas++; return tmp;}}

// Sobrescrevendo free usando um macro
void FREE_OVERWRITER (void* ptr){if (ptr == NULL) printf ("\n\nERRO AO TENTAR LIMPAR ESPACO\n\n"); \
else {limpezas_feitas++; __builtin_free (ptr); ptr = NULL;}}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// FUNÇÕES

// exibe a situação atual da memória
void status_da_memoria ()
{
    printf 
    (
        "\n\tReservas feitas: %10d"
        "\n\tLimpezas feitas: %10d"
        "\n\t________________ ____" "______"
        "\n\tLixo de memoria: %10d"
        "\n", 
        reservas_feitas, limpezas_feitas, reservas_feitas - limpezas_feitas
    );
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// MAIN DE TESTE

int Testar_GerenciadorDeMemoria ()
{
    printf ("\n-------------------------------------------------------------\n");
    // Exemplo de alocação e liberação usando a biblioteca personalizada
    printf("Testando a biblioteca de gerenciamento de ponteiros em C:\n");

    status_da_memoria();

    // Reservar espaço para um inteiro
    int* ptr1 = reservar(int, 1);
    if (ptr1 != NULL)
        *ptr1 = 42;

    // Reservar espaço para um array de 5 inteiros
    int* array = reservar(int, 5);
    if (array != NULL)
        for (int i = 0; i < 5; i++)
            array[i] = i + 1;

    // Mostrar status da memória
    status_da_memoria();

    #ifdef GERENCIADOR_DE_MEMORIA_OVERLOAD
        // Liberar o primeiro ponteiro
        free(ptr1);

        // Liberar o array
        free(array);
    #else
        limpar (ptr1);
        limpar (array);
    #endif

    // Mostrar status final da memória
    status_da_memoria();

    printf ("\n-------------------------------------------------------------\n");

    return 0;
}