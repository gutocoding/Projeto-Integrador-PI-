#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "src/produtos.h"
#include "src/busca.h"
#include "src/medirtempo.h"

int main(void)
{
    //Lendo produtos da planilha e armazenando em um vetor
    int total_reg = 0;
    Produto *produtos = ler_produtos(&total_reg);

    //Testando funcao buscar
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

    //medindo o tempo

    printf(">>> Medindo pior caso (ultimo ID da lista)...\n");
    medir_tempo(produtos, total_reg, 189553);

    printf(">>> Medindo o caso mediano (ID no meio da lista)...\n");
    medir_tempo(produtos, total_reg, 127776);

    printf(">>> Medindo o melhor caso (Primeiro ID da lista)...\n");
    medir_tempo(produtos, total_reg, 43614);
    
    return 0;
    
}