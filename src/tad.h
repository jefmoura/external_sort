#include <stdio.h>
#include <stdlib.h>

typedef struct{
	char url[100];
	int acesso;
	int rodada;
} entidade;

//Funções que tratam arquivos;

void escrRodada( FILE *, entidade [], int );
void criarArqRodada( FILE **, int * );
void abrirRodadasn( int, FILE ** );
void criarOrdenado( FILE **, char * );
void escrOrdenado( FILE *, entidade, int );
void fechaArquivo( FILE ** );
void abrirArquivo( FILE **, char * );
void removeArquivo( int );

//Funções que alocam e desalocam memória;

void alocarFita( int, entidade ** );
void realocarFita( int, entidade ** );
void desalocEntidade( entidade ** );

//Funções que fazem parte de algoritmos de ordenação;

void quickSort( entidade [], int );
void ordena( int, int, entidade [] );
void particao( int, int, int *, int *, entidade [] );
void insertionSort( entidade [], int );
void criarHeap( entidade [], int );
void refaz( int, int, entidade [] );

//Funções que tratam entradas de arquivos, as entidades;

int lerRodada( FILE *, int, entidade [] );
int verifArquivo( FILE * );
void lerEntidade( FILE *, entidade *, int );
void entidadesSort( FILE **, FILE *, entidade *, int );
void zerarFita( entidade [], int );
