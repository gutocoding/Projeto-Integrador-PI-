#ifndef HASH_H
#define HASH_H
#include "produtos.h"

typedef struct No {
    Produto produto;
    struct No* proximo;
}No;

typedef struct {
    No** indices;
    int tamanho;
    int total_colisoes;
}TabelaHash;

TabelaHash* inicializar_tabela(int tamanho);
int funcao_hash(int id, int tamanho);
int inserir_hash(TabelaHash* tabela, Produto produto);
void liberar_tabela_hash(TabelaHash* tabela);
int buscar_hash(TabelaHash* tabela, int id_buscado);

#endif