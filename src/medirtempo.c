#include <stdio.h>
#include <time.h>
#include "medirtempo.h"

void medir_tempo(Produto *vetor, int total_elementos, int id_buscado)
{
    clock_t inicio = clock();

    for (int i = 0; i < 1000; i++)
    {
        buscar(vetor, total_elementos, id_buscado);
    }

    clock_t fim = clock();

    double tempototal = (double)(fim - inicio) / CLOCKS_PER_SEC;
    double tempomedio = tempototal / 1000;

    printf("--- ID buscado: %d ---\n", id_buscado);
    printf("Tempo total para 1000 buscas: %f segundos\n", tempototal);
    printf("Tempo medio por busca: %f segundos\n", tempomedio);
}
