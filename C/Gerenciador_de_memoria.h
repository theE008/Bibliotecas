#ifndef GERENCIADOR_DE_MEMORIA___H
#define GERENCIADOR_DE_MEMORIA___H

#define BIBLIOTECA_GERENCIADOR_DE_MEMORIA_DISPONIVEL

/////////////////////////////////////////////////////////////////////////////////////////////////////
// BIBLIOTECAS

#include <stdlib.h>
#include <stdio.h>

/////////////////////////////////////////////////////////////////////////////////////////////////////
// DEFINES

/**\
|*   Em um código que já tenha sido feito, para usar o malloc contabilizado, deverá redefinir ele.
|*  Em qualquer outro caso, isso NÃO É recomendado. Utilize limpar, reservar, e malocar.
\**/

// #define GERENCIADOR_DE_MEMORIA_OVERLOAD

#ifdef GERENCIADOR_DE_MEMORIA_OVERLOAD
    #define reservar(tipo,quantos)  (tipo*) MALLOC_OVERWRITER (quantos*sizeof (tipo))
    #define free(ponteiro) FREE_OVERWRITER (ponteiro)
    #define malloc(size) MALLOC_OVERWRITER (size)
#else
    #define reservar(tipo,quantos)  (tipo*) MALLOC_OVERWRITER (quantos*sizeof (tipo))
    #define limpar(ponteiro) FREE_OVERWRITER (ponteiro)
    #define malocar(size) MALLOC_OVERWRITER (size)
#endif

//*/

/////////////////////////////////////////////////////////////////////////////////////////////////////
// PROTÓTIPO DE FUNÇÕES

void* MALLOC_OVERWRITER (size_t size);
int Testar_GerenciadorDeMemoria ();
void FREE_OVERWRITER (void* ptr);
void status_da_memoria ();
int getLixo_de_memoria ();
int getReservas_feitas ();
int getLimpezas_feitas ();

#endif
