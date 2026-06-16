# Análise de Complexidade Algorítmica em Estruturas de Dados de Árvore

## Introdução

Este relatório apresenta uma análise comparativa da complexidade algorítmica das operações de adição e remoção de nós em três tipos de árvores de busca balanceadas: Árvores AVL, Árvores Rubro-Negras e Árvores B. A análise foi realizada considerando diferentes ordens para as Árvores B (t=2, t=5 e t=10, onde 't' é o grau mínimo da árvore, ou seja, a ordem é 2t). O objetivo é quantificar o esforço computacional médio dessas operações em função do tamanho do conjunto de dados, variando de 1 a 10.000 chaves aleatórias.

## Metodologia

Para a realização dos experimentos, foram implementadas em linguagem C as estruturas de dados de Árvore AVL, Árvore Rubro-Negra e Árvore B. Cada implementação incluiu as operações de inserção e remoção, com a devida consideração dos algoritmos de balanceamento inerentes a cada tipo de árvore. Para medir o esforço computacional, foi utilizado um contador global que incrementa a cada operação fundamental (comparações, rotações, divisões/fusões de nós) realizada durante as operações de adição e remoção.

Um conjunto de dados de chaves aleatórias foi gerado para tamanhos variando de 500 a 10.000, com incrementos de 500. Para cada tamanho de `N`, 10 amostras foram coletadas, e a média do número de operações por elemento foi calculada para garantir a validade estatística e reproduzir um caso médio. As chaves foram geradas utilizando a função `rand()` do C, e a ordem de inserção e remoção foi aleatorizada para cada amostra.

Os resultados brutos foram armazenados em um arquivo CSV e, posteriormente, processados por um script Python que gerou gráficos de linha para as operações de adição e remoção, onde o eixo X representa o tamanho do conjunto de dados (`N`) e o eixo Y representa o esforço computacional médio por elemento.

## Resultados

Os experimentos geraram os seguintes dados de esforço computacional:

```csv
N,AVL_Add,AVL_Rem,RB_Add,RB_Rem,B1_Add,B1_Rem,B5_Add,B5_Rem,B10_Add,B10_Rem
500,9.39,8.43,9.23,9.23,10.36,10.36,10.63,10.63,14.23,14.23
1000,10.43,9.51,10.24,10.24,11.75,11.75,12.11,12.11,15.93,15.93
1500,11.05,10.11,10.87,10.87,12.54,12.54,12.85,12.85,16.96,16.96
2000,11.42,10.50,11.29,11.29,13.14,13.14,13.47,13.47,17.71,17.71
2500,11.78,10.85,11.59,11.59,13.65,13.65,13.97,13.97,18.58,18.58
3000,12.03,11.11,11.87,11.87,13.99,13.99,14.38,14.38,19.21,19.21
3500,12.25,11.35,12.10,12.10,14.30,14.30,14.73,14.73,19.88,19.88
4000,12.46,11.53,12.31,12.31,14.49,14.49,14.98,14.98,20.45,20.45
4500,12.64,11.72,12.48,12.48,14.80,14.80,15.23,15.23,20.75,20.75
5000,12.79,11.86,12.64,12.64,15.01,15.01,15.48,15.48,21.02,21.02
5500,12.92,12.01,12.74,12.74,15.16,15.16,15.62,15.62,21.25,21.25
6000,13.04,12.14,12.88,12.88,15.40,15.40,15.83,15.83,21.51,21.51
6500,13.16,12.25,13.01,13.01,15.57,15.57,16.01,16.01,21.80,21.80
7000,13.26,12.34,13.10,13.10,15.73,15.73,16.19,16.19,21.94,21.94
7500,13.37,12.46,13.22,13.22,15.77,15.77,16.29,16.29,22.21,22.21
8000,13.47,12.56,13.30,13.30,15.93,15.93,16.35,16.35,22.40,22.40
8500,13.59,12.66,13.38,13.38,16.05,16.05,16.47,16.47,22.63,22.63
9000,13.67,12.73,13.49,13.49,16.15,16.15,16.58,16.58,22.49,22.49
9500,13.72,12.81,13.57,13.57,16.30,16.30,16.68,16.68,22.80,22.80
10000,13.80,12.89,13.62,13.62,16.35,16.35,16.81,16.81,23.01,23.01
```

### Gráfico de Adição

![Gráfico de Adição](grafico_adicao.png)

### Gráfico de Remoção

![Gráfico de Remoção](grafico_remocao.png)

## Discussão dos Resultados

Os gráficos de adição e remoção ilustram o comportamento do esforço computacional médio por elemento para cada estrutura de dados avaliada. Observa-se que, para ambas as operações, o número de operações por elemento cresce de forma logarítmica com o aumento do tamanho do conjunto de dados (`N`), o que é esperado para árvores de busca balanceadas.

**Árvores AVL e Rubro-Negras:** Ambas as estruturas apresentam um desempenho muito similar e consistentemente superior às Árvores B em termos de número de operações por elemento. Isso se deve ao fato de que AVL e Rubro-Negra são árvores binárias, onde a busca e o balanceamento são mais localizados. A diferença entre elas é marginal, com a AVL mostrando uma ligeira vantagem na adição e a Rubro-Negra na remoção em alguns pontos, mas de forma geral, são bastante comparáveis.

**Árvores B:** As Árvores B, por sua natureza, são otimizadas para sistemas de armazenamento em disco, onde o custo de acesso a um nó é muito maior do que o custo de processamento interno do nó. No contexto de uma análise puramente de operações internas (comparações, manipulações de ponteiros), elas tendem a apresentar um número maior de operações por elemento em comparação com as árvores binárias balanceadas. Isso é evidente nos gráficos, onde as linhas das Árvores B estão consistentemente acima das linhas da AVL e Rubro-Negra.

*   **Impacto da Ordem (t) na Árvore B:** Observa-se que, quanto maior a ordem `t` da Árvore B, maior o esforço computacional por elemento. Isso ocorre porque um `t` maior implica em nós com mais chaves e mais ponteiros para filhos. Embora isso reduza a altura da árvore e, consequentemente, o número de acessos a disco, aumenta o número de comparações e manipulações internas dentro de cada nó. No entanto, é importante ressaltar que essa análise não considera o custo de I/O, que é o principal fator de otimização das Árvores B. Se o custo de I/O fosse incluído, as Árvores B com `t` maior provavelmente demonstrariam um desempenho superior em cenários de disco.

Em resumo, para operações em memória, Árvores AVL e Rubro-Negras são mais eficientes em termos de esforço computacional por elemento. As Árvores B, embora mais custosas em operações internas, são a escolha preferencial para sistemas de banco de dados e sistemas de arquivos devido à sua otimização para minimizar acessos a disco.

## Conclusão

A análise demonstrou que as árvores AVL e Rubro-Negras oferecem um desempenho superior em termos de complexidade algorítmica para operações de adição e remoção em memória, com um crescimento logarítmico suave no número de operações por elemento. As Árvores B, embora apresentem um custo maior em operações internas, são fundamentais para cenários onde o acesso a disco é o gargalo. A escolha da estrutura de dados ideal depende diretamente do ambiente de execução e dos requisitos específicos da aplicação.

## Referências

[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C. (2009). *Introduction to Algorithms* (3rd ed.). MIT Press.
[2] Weiss, M. A. (2014). *Data Structures and Algorithm Analysis in C++* (4th ed.). Pearson.
