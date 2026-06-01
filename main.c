#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "src/produtos.h"
#include "src/busca.h"
#include "src/medirtempo.h"
#include "src/hash.h"

// void salvar_id_no_arquivo(int id, double tempo); // (Se for usar depois, pode manter)

int main(void)
{
    printf("=== INICIANDO SISTEMA DE BUSCA ===\n");

    // 1. CARREGAMENTO BASE (Lendo o CSV)
    int total_reg = 0;
    Produto *produtos = ler_produtos(&total_reg);

    if (produtos == NULL || total_reg == 0) {
        printf("Falha critica ao ler o banco de dados.\n");
        return 1;
    }

    // ===================================================
    // FASE I: TESTES DA BUSCA SEQUENCIAL (Baseline)
    // ===================================================
    printf("\n--- RESULTADOS DA FASE I (BUSCA SEQUENCIAL) ---\n");
    printf(">>> Medindo pior caso (ultimo ID da lista)...\n");
    medir_tempo(produtos, total_reg, 189553);

    printf(">>> Medindo o caso mediano (ID no meio da lista)...\n");
    medir_tempo(produtos, total_reg, 127776);

    printf(">>> Medindo o melhor caso (Primeiro ID da lista)...\n");
    medir_tempo(produtos, total_reg, 43614);

    printf(">>> Medindo o caso inexistente...\n");
    medir_tempo(produtos, total_reg, -999);


    // ===================================================
    // FASE II: TABELA HASH
    // ===================================================
    printf("\n--- INICIALIZANDO FASE II (TABELA HASH) ---\n");
    
    // Inicializa a tabela com o tamanho exato do dataset
    TabelaHash* tabela = inicializar_tabela(total_reg);
    if (tabela == NULL) {
        free(produtos); // Se falhar, limpa o vetor antes de fechar
        return 1;
    }

    printf("Populando a Tabela Hash com %d registros...\n", total_reg);
    // Transfere todos os produtos do vetor para a Tabela Hash
    for (int i = 0; i < total_reg; i++) {
        inserir_hash(tabela, produtos[i]);
    }

    printf("\n=== RELATORIO DE CARREGAMENTO (HASH) ===\n");
    printf("Quantidade total de registros carregados: %d\n", total_reg);
    printf("Numero total de colisoes: %d\n", tabela->total_colisoes);
    printf("========================================\n\n");


    // ---------------------------------------------------
    // LIMPEZA FINAL DA MEMÓRIA
    // ---------------------------------------------------
    liberar_tabela_hash(tabela);
    free(produtos);
    
    return 0;
}