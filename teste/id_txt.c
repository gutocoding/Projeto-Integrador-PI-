#include <stdio.h>

void salvar_resultado_teste(int id, double tempo)
{
    FILE *arquivo = fopen("resultados_teste.txt", "a");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para salvar os resultados.\n");
        return;
    }

    fprintf(arquivo, "ID buscado: %d, Tempo medio: %.6f segundos\n", id, tempo);
    fclose(arquivo);
}
