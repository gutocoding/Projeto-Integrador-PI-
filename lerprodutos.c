#include "produtos.h"
#include <stdio.h>
#include <stdlib.h>

Produto* ler_produtos(int* total)
{
    Produto *produtos = NULL;
    int total_registros = 0;
    int capacidade = 20;
    FILE *arqv = NULL;


    arqv = fopen("dataset3.csv", "r");
    if (arqv == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return produtos;
    }

    produtos = malloc(capacidade * sizeof(Produto));
    if (produtos == NULL)
    {
        printf("Erro ao alocar memoria\n");
        return produtos;
    }

    char buffer[100];
    fgets(buffer, sizeof(buffer), arqv);
    printf("tentando ler...\n");
    char linha[512];

    while (fgets(linha, sizeof(linha), arqv))
{
    int lidos = sscanf(linha, "%d,%50[^,],%30[^,],%f",
    &produtos[total_registros].id,
    produtos[total_registros].nome,
    produtos[total_registros].categoria,
    &produtos[total_registros].valor);

    if (lidos != 4)
    {
        printf("Linha ignorada: %s\n", linha); //aqui foi só para diagnosticar o que estava dando de errado
    }

    if (lidos == 4)
    {
        //printf("Li um produto!\n");
        total_registros++;

        if (total_registros >= capacidade)
        {
            capacidade *= 2;
            Produto *temp = realloc(produtos, capacidade * sizeof(Produto));

            if (temp == NULL)
            {
                printf("Erro ao alocar memoria\n");
                free(produtos);
                return NULL;
            }

            produtos = temp;
        }
    }
}
    *total = total_registros;
    printf("%d Produtos lidos com sucesso.", total_registros);
    fclose(arqv);
    return produtos;
}