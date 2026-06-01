#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "src/produtos.h"
#include "src/busca.h"
#include "src/medirtempo.h"
#include "src/hash.h"

void salvar_id_no_arquivo(int id, double tempo);


int main(void)
{
    printf("=== TESTE UNITARIO - TABELA HASH === \n");
    TabelaHash* minha_tabela = inicializar_tabela(10);
    Produto p1 = {1005, "Teclado", "Informatica", 150.0};
    Produto p2 = {2005, "Mouse", "Informatica", 80.0};

    inserir_hash(minha_tabela, p1);
    inserir_hash(minha_tabela, p2);
    Produto p3 = {3004, "Monitor", "Informatica", 900.0};
    inserir_hash(minha_tabela, p3);
    printf("Colisoes registradas: %d\n", minha_tabela->total_colisoes);

    printf("\nItens na Gaveta 7:\n");
    No* atual = minha_tabela->indices[7];
    while (atual != NULL) {
        printf(" -> ID: %d | Nome: %s\n", atual->produto.id, atual->produto.nome);
        atual = atual->proximo;
    }

    liberar_tabela_hash(minha_tabela);
    return 0;     //--- fim do teste unitario



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

    printf(">>> Medindo o caso inexistente...\n");
    medir_tempo(produtos, total_reg, -999);

    free(produtos);
    return 0;
    
}