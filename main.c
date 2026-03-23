#include <stdio.h>
#include <stdlib.h>
#include "produtos.h"

int main(void)
{
    int total_reg = 0;
    Produto *produtos = ler_produtos(&total_reg);

    return 0;
    
}