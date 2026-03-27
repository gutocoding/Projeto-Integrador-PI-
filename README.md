# Projeto-Integrador-PI- Fase I
Analise de desempenho: busca Sequencial em c 

Este projeto realiza a leitura de um dataset de produtos e analisa o tempo de 
execução do algoritmo de busca sequencial em diferentes cenarios.

Estrutura do projeto :
- 'main.c' : ponto de entrada do programa e logica de testes.
- 'funcoes_projetos/': pasta contendo os módulos do sistema.
- 'leitura.c/h': Funções para ler o arquivo CVS e alocação dinâmica.
- 'busca.c/h': implementação do algoritmo de busca sequencial.
- 'tempo.c/h': Funções para cronometragem de desempenho.
- 'dataset3.cvs': Arquivo de dados com os produtos.

Como Copilar e Rodar 

Como o projeto é modular, utilize o seguinte comando no terminal(dentro da pasta raiz) para compilar :
gcc main.c funcoes_projetos/*c. -o programa -I.

Para executar o programa:
.\programa.exe

Funcionalidades implementadas 
- [x] leitura dinamica de arquivos CVS ultilizando rewind().
- [x] alocação dinamica de memória para armazenamento dos produtos.
- [x] busca sequencial por id. 
- [x] medição de tempo medio apos 1.000 repetições .

Integrantes 
- Sabrina Borges da Trindade 
- Augusto Santana de Souza 