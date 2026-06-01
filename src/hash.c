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

int inserir_hash(TabelaHash* tabela, Produto produto)
{
    if (tabela == NULL) return 0;
    int indice = funcao_hash(produto.id, tabela->tamanho);

    if(tabela->indices[indice] != NULL)
    {
        tabela->total_colisoes++;
        //significa que tal indice já tem alguém, registrando colisões...
    }

    //Cria um novo "Nó" na memória para guardar esse produto
    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) 
    {
        printf("Erro de memoria ao inserir o produto ID: %d\n", produto.id);
        return 0; // Falha na alocação
    }

    novo_no->produto = produto;
    novo_no->proximo = tabela->indices[indice];
    tabela->indices[indice] = novo_no;
    return 1;
}

void liberar_tabela_hash(TabelaHash* tabela)
{
    if (tabela == NULL) return;

    // 1. Percorre todas as gavetas do vetor
    for (int i = 0; i < tabela->tamanho; i++) 
    {
        No* atual = tabela->indices[i];
        
        // 2. Enquanto houver produtos nesta gaveta, deleta um por um
        while (atual != NULL) {
            No* temp = atual;
            atual = atual->proximo;
            free(temp); // Libera o nó específico
        }
    }
    free(tabela->indices);    
    free(tabela);
}
