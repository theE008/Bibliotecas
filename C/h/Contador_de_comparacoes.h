#ifndef CONTADOR_DE_COMPARACOES___H
#define CONTADOR_DE_COMPARACOES___H

#define BIBLIOTECA_CONTADOR_DE_COMPARACOES_DISPONIVEL

/////////////////////////////////////////////////////////////////////////////////////////////////////
// BIBLIOTECAS

#include <stdlib.h>
#include <stdio.h>

/////////////////////////////////////////////////////////////////////////////////////////////////////
// PROTÓTIPO DE FUNÇÕES

int Testar_ContadorDeComparacoes ();
int addComparacoes ();
int getComparacoes ();

/////////////////////////////////////////////////////////////////////////////////////////////////////
// DEFINES

/**\
|*  Em um código que já tenha sido feito, para usar o if contabilizado, deverá redefinir ele.
|* Em qualquer outro caso, isso NÃO É recomendado. Utilize IF para contar o valor de comparações.
\**/

// #define CONTADOR_DE_COMPARACOES_OVERLOAD

#ifndef CONTADOR_DE_COMPARACOES_OVERLOAD
    #define IF(comp) if((addComparacoes ()) && comp)
#else
    #define if(comp) if((addComparacoes ()) && comp)
#endif

#endif
