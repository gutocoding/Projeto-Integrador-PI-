#include <stdio.h>
#include "busca.h"


int buscar(Produto *vetor, int total_elementos, int id_buscado)
{
    if (vetor == NULL)
    {
        printf("Vetor invalido.\n");
        return -1;
    }

    for (int i = 0; i < total_elementos; i++)
    {
        if (vetor[i].id == id_buscado)
        {
            return i;
        }
    }
    return -1;
}