# Projeto-Integrador-PI- Fase I
Analise de desempenho: busca Sequencial em c 

Este projeto realiza a leitura de um dataset de produtos e analisa o tempo de 
execução do algoritmo de busca sequencial em diferentes cenarios.

Estrutura do projeto :
- 'main.c' : ponto de entrada do programa e logica de testes.
- 'src/': pasta contendo os módulos do sistema.
- 'lerprodutos.c/h': Funções para ler o arquivo CVS e alocação dinâmica.
- 'busca.c/h': implementação do algoritmo de busca sequencial.
- 'medirtempo.c/h': Funções para cronometragem de desempenho.
- 'dataset3.cvs': Arquivo de dados com os produtos.

Como Copilar e Rodar 

o comando para realizar os teste:
gcc teste/teste_final.c src/*.c teste/id_txt.c -o programa_teste -I. 

Como o projeto é modular, utilize o seguinte comando no terminal(dentro da pasta raiz) para compilar :
gcc main.c src/*c. -o programa -I.

Para executar o programa:
.\programa.exe

Funcionalidades implementadas 
- [x] leitura dinamica de arquivos CVS ultilizando rewind().
- [x] alocação dinamica de memória para armazenamento dos produtos.
- [x] busca sequencial por id. 
- [x] medição de tempo medio apos 1.000 repetições .

 Análise de Desempenho e Resultados

Nesta fase do Projeto Integrador, focamos na validação e medição de desempenho do algoritmo de Busca Sequencial. Os testes foram realizados utilizando um dataset real com mais de 300.000 registros de produtos (`dataset3.csv`).

Para garantir a precisão dos dados, cada busca foi repetida 1.000 vezes, e calculamos a média de tempo por busca (em segundos). Os cenários testados foram:

| Cenário | ID Buscado | Tempo Médio (s) |
| :--- | :--- | :--- |
| Melhor Caso | 43614 | 0.000000 |
| Caso Médio | 127776 | 0.000256 |
| Pior Caso | 189553 | 0.001227 |
| Inexistente | -999 | 0.001246 |

> Nota: O sistema gera automaticamente um log detalhado em `relatorio_testes.txt`.

| Cenário de Teste | Descrição | Tempo Médio (s) |
| :--- | :--- | :--- |
| Melhor Caso | ID localizado no início do arquivo (ex: ID 43614) | ~0.000000 s |
| Caso Mediano| ID localizado no meio do arquivo (ex: ID 127776) | ~0.000221 s |
| Pior Caso | ID localizado no final do arquivo (ex: ID 189553) | ~0.000884 s |
| Caso Inexistente| ID não cadastrado na planilha (ex: ID -999) | ~0.000860 s |

 Conclusão 

Os resultados obtidos comprovam as características teóricas da Busca Sequencial (complexidade O(n)):

1.  Linearidade: O tempo de execução aumenta de forma proporcional à posição do item no arquivo. O pior caso demorou aproximadamente 4 vezes mais que o caso médio, pois precisou percorrer quase o dataset inteiro.
2.  Eficiência Limidada: Embora eficiente para datasets pequenos ou quando o item está no início, a performance degrada significativamente para buscas no final do arquivo ou para itens inexistentes, onde o algoritmo é forçado a ler todas as 300.007 linhas.


Integrantes 
- Sabrina Borges da Trindade 
- Augusto Santana de Souza 