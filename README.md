# Projeto Integrador: Análise Experimental de Algoritmos de Busca 
Este projeto analisa o desempenho de busca em um dataset real de 300.007 registros de produtos (`dataset3.csv`), comparando a eficiência da Busca Sequencial com a Tabela Hash.
## 🚀 Métodos Implementados
### Fase I: Busca Sequencial
- Algoritmo: Varredura linear com complexidade $O(n)$.
- Medição: Média de tempo após 1.000 repetições por cenário.
### Fase II: Tabela Hash (Dobra + Encadeamento)
- Algoritmo: Acesso via função hash com complexidade média $O(1)$.
- Função: Dobra simples de dois blocos: `h(x) = ((x/1000) + (x%1000)) % m`.
- Tratamento de Colisões: Encadeamento externo via listas encadeadas.
# 📊 Comparativo de Resultados

| Cenário | ID Buscado | Tempo Sequencial | Tempo Hash |
| :--- | :--- | :--- | :--- |
| Melhor Caso | 43614 | 0,000000 s | 0,000032 s     |
| Caso Médio | 127776 | 0,000256 s | 0,000032 s     |
| Pior Caso | 189553 | 0,001227 s | 0,000032 s    |
| Inexistente | -999 | 0,001246 s | 0,000032 s   |

## 💻 Compilação e Execução
Utilize o compilador `gcc` na pasta raiz do projeto:
```bash
# Compilar
gcc main.c src/*.c -o programa -I.
# Executar
./programa

##integrantes   
- Sabrina Borges da Trindade 
- Augusto Santana de Sousa
