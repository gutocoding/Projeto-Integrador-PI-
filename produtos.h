#ifndef PRODUTOS_H
#define PRODUTOS_H

typedef struct {
int id;
char nome[51];
char categoria[31];
float valor;
} Produto;

Produto* ler_produtos(int* total);


#endif