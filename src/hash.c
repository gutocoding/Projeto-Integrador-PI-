#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

TabelaHash* inicializar_tabela(int tamanho)
{
    TabelaHash* tabela = (TabelaHash*)malloc(sizeof(TabelaHash));
    if (tabela == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        return NULL;
    }

    tabela->indices = (No**)calloc(tamanho, sizeof(No*));
    if (tabela->indices == NULL) 
    {
        printf("Erro ao alocar os indices da Tabela Hash.\n");
        free(tabela);
        return NULL;
    }

    tabela->tamanho = tamanho;
    tabela->total_colisoes = 0;

    return tabela;
}

int funcao_hash(int id, int tamanho)
{
    int bloco1 = id / 1000;
    int bloco2 = id % 1000;
    int resultado = bloco1 + bloco2;
    int indice = resultado % tamanho;
    return indice;
}