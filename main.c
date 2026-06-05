#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "src/produtos.h"
#include "src/busca.h"
#include "src/medirtempo.h"
#include "src/hash.h"

void motor_de_buscas_hash(TabelaHash* tabela, Produto* vetor_base, int total_reg) {
    printf(">>> Iniciando Motor de Buscas Automatizado (1000 iteracoes)...\n");
    
    int encontradas = 0;
    int nao_encontradas = 0;

    // Inicializa a semente de números aleatórios do C para garantir que seja randomico
    srand(time(NULL)); 

    // O loop ininterrupto exigido pelo Critério de Aceite
    for (int i = 0; i < 1000; i++) {
        int id_teste;

        // Sorteia um número de 0 a 1. Se for 0 (50% de chance), busca um ID real.
        if (rand() % 2 == 0) {
            int indice_aleatorio = rand() % total_reg;
            id_teste = vetor_base[indice_aleatorio].id;
        } 
        else {
            id_teste = - (rand() % 10000) - 1; 
        }

        // Executa a busca na Hash
        int resultado = buscar_hash(tabela, id_teste);

        if (resultado == 1) {
            encontradas++;
        } else {
            nao_encontradas++;
        }
    }

    printf("Motor finalizado! Resultados das 1000 buscas aleatorias:\n");
    printf("- Chaves Existentes encontradas: %d\n", encontradas);
    printf("- Chaves Inexistentes detectadas: %d\n", nao_encontradas);
    printf("========================================\n\n");
}

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

    motor_de_buscas_hash(tabela, produtos, total_reg); //Chamando buscas


    // ---------------------------------------------------
    // LIMPEZA FINAL DA MEMÓRIA
    // ---------------------------------------------------
    liberar_tabela_hash(tabela);
    free(produtos);
    
    return 0;
}