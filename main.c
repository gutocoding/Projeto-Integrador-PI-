#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "src/produtos.h"
#include "src/busca.h"
#include "src/medirtempo.h"
#include "src/hash.h"

void motor_de_buscas_hash(TabelaHash* tabela, Produto* vetor_base, int total_reg) {
    printf(">>> Iniciando Motor de Buscas Automatizado (Protocolo de 3 Rodadas)...\n");
    
    srand(time(NULL)); 
    
    double soma_tempos_totais = 0.0;
    int total_encontradas = 0;
    int total_nao_encontradas = 0;

    // CRITÉRIO DE ACEITE: Rodar o teste 3 vezes
    for (int rodada = 1; rodada <= 3; rodada++) {
        int encontradas = 0;
        int nao_encontradas = 0;
        
        int chaves_teste[1000];
        for (int i = 0; i < 1000; i++) {
            if (rand() % 2 == 0) {
                int indice_aleatorio = rand() % total_reg;
                chaves_teste[i] = vetor_base[indice_aleatorio].id;
            } else {
                chaves_teste[i] = - (rand() % 10000) - 1; 
            }
        }
        
        // 2. CRITÉRIO DE ACEITE: Medição de alta precisão (Apenas a busca)
        clock_t inicio = clock();
        
        for (int i = 0; i < 1000; i++) {
            int resultado = buscar_hash(tabela, chaves_teste[i]);
            
            if (resultado == 1) encontradas++;
            else nao_encontradas++;
        }
        
        clock_t fim = clock();
        
        double tempo_rodada = (double)(fim - inicio) / CLOCKS_PER_SEC;
        soma_tempos_totais += tempo_rodada;
        
        total_encontradas += encontradas;
        total_nao_encontradas += nao_encontradas;
        
        printf(" -> Rodada %d finalizada. Tempo: %f segundos\n", rodada, tempo_rodada);
    }
    
    // 4. CRITÉRIO DE ACEITE: Calcular a média final e exibir outputs
    double media_tempo_total_1000 = soma_tempos_totais / 3.0; 
    double tempo_medio_por_busca = media_tempo_total_1000 / 1000.0;
    
    printf("\n=== RESULTADO FINAL DO MOTOR (TABELA HASH) ===\n");
    printf("Total de buscas realizadas: 3000 (3 rodadas de 1000)\n");
    printf("- Chaves Existentes encontradas: %d\n", total_encontradas);
    printf("- Chaves Inexistentes detectadas: %d\n", total_nao_encontradas);
    printf("----------------------------------------------\n");
    printf("Tempo MEDIO TOTAL (1000 buscas): %f segundos\n", media_tempo_total_1000);
    printf("Tempo MEDIO POR BUSCA individual : %f segundos\n", tempo_medio_por_busca);
    printf("==============================================\n\n");
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