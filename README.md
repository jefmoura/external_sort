# External Sort

Todos os dias é gerado uma quantidade enorme de dados na web e fazendo com que
seja difícil processar e extrair dados desta enorme massa de informação. Para detectar em
um arquivo quais os sites mais populares e ordenar esses dados pode não ser simples, pois,
este arquivo contendo URLs e suas respectivas pageviews pode ter diversos gigabytes de
tamanho, excedendo com facilidade a memória principal de um computador.
Este repositório posui um sistema que implementa um algoritmo de ordenação external o qual usa a memória principal e secundária para tal.
O programa basicamente ordena os arquivos por suas respectivas pageviews e no caso de serem iguais o número de acessos da página será colocado em ordem alfabética.

### Compilar e executar
Para compilar bastar executar o seguinte comando:
```
gcc alocar.c arquivos.c  entidades.c ordena.c ordenacao.c -o ordena
```

Para executar o programa é necessário passar o arquivo de entrada e o nome do arquivo de saída, como o seguinte comando:
```
./ordena arquivo_entradada arquivo_saída resultado
```

### Input
Os arquivos de entrada devem seguir o seguinte formato:
*PAGINA_WEB* *PAGE_VIEWS*

Exemplo de entrada:
```
http://www.google.com.br 3
http://www.cade.com.br 5
http://www.ufmg.br 6
http://www.dcc.ufmg.br 1
http://www.dcc.ufmg.br/cursos 2
```

### Output
Os arquivos de saída terão o seguinte padrão:
*PAGINA_WEB* *PAGE_VIEWS*

Exemplo de saída:
```
http://www.cade.com.br 5
http://www.dcc.ufmg.br/cursos 2
http://www.dcc.ufmg.br 1
http://www.google.com.br 3
http://www.ufmg.br 6
```

