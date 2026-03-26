 #ifndef LEITURA_PROJETO_H
 #define LEITURA_PROJETO_H

 typedef struct { 
    int id;
    char name [51];
    char categoria [31];
    float valor ;     
    
 } Produto ;
 Produto* ler_cvs(const char*caminho_arquvo,int* total);
 #endif 
  
 
 
  