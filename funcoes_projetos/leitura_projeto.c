#include <stdio.h>
#include <stdlib.h>
#include "leitura_projeto.h"
 
Produto* ler_cvs(const char* caminho_arquivo, int* total){
    FILE* file= fopen(caminho_arquivo, "r");
    if(!file){
        printf("erro: não foi possivel abri o arquivo %s\n",caminho_arquivo);
    }
     // contar as linhas existem para o malloc 
    int count =0 ;
    char buffer[256];
    while(fgets (buffer, sizeof(buffer),file)){
        count++;
    }
     *total= count;
     rewind(file);
     // alocar a memoria para todos os produtos

     Produto* vetor = (Produto*)
     malloc (count* sizeof(Produto));
     if(!vetor){
        printf("erro: falha ao  alocar memoria para %d registros.\n",count);
        fclose(file);
        return NULL;
     }
    // ler os dados formatados 
    for (int i = 0; i<count;i++){
        if(fscanf(file,"%d,%50[^,],%30[^,],%f\n",&vetor[i].id, vetor[i].name, vetor[i].categoria,
            &vetor[i].valor)!=4){
            printf("erro: falha ao ler dados do produto %d.\n", i+1);
        }
    }
         fclose(file);  
         return vetor;
        

}
  

