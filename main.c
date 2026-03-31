#include <stdio.h>
#include <stdlib.h>
#include "src/produtos.h"
#include "src/busca.h"

int main(void)
{
    int total_reg = 0;
    Produto *produtos = ler_produtos(&total_reg);

    int bbusca = buscar(produtos, total_reg, 54165);
    if (bbusca != -1)
    {
        printf("Achou ID: 54165, i: %d\n", bbusca);
    }

    bbusca = buscar(produtos, total_reg, 2);
    if (bbusca != -1)
    {
        printf("Achou ID: 2, i: %d\n", bbusca);
    }

    bbusca = buscar(produtos, total_reg, 900000000);
    if (bbusca != -1)
    {
        printf("Achou ID: 900000000, i: %d\n", bbusca);
    }
    else
    {
        printf("ID 900000000 nao encontrado.\n");
    }


    return 0;
    
}