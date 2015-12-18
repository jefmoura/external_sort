#include "tad.h"

//Função escreve no arquivo de saída das rodadas;

void escrRodada( FILE *arqOut, entidade fita[], int numEntidade ){
	int cntEntidade = 0;

	while( cntEntidade < numEntidade && fita[cntEntidade].url[0] != '\0' ){
		fprintf( arqOut, "%s", fita[cntEntidade].url );
		fprintf( arqOut, "%d", fita[cntEntidade].acesso );
		cntEntidade++;

		if( cntEntidade < numEntidade && fita[cntEntidade].url[0] != '\0' )
            putc( '\n', arqOut);
	}
}

//Função cria arquivo de cada rodada;

void criarArqRodada( FILE **arqOut, int *numRodadas ){
    char arqRodada[20];

    sprintf( arqRodada, "rodada-%d.txt", *numRodadas );

	if( !( *arqOut = fopen( arqRodada, "w" ) ) )
		exit(1);

	(*numRodadas)++;
}

//Função abre uma sequência de arquivos rodada-i;

void abrirRodadasn( int numRodadas, FILE **arqIn ){
	int i;
    char arqRodada[20];

	for( i = 1; i <= numRodadas; i++ ){
        sprintf( arqRodada, "rodada-%d.txt", i );

		if( !( arqIn[i-1] = fopen( arqRodada, "r" ) ) )
			exit(1);
	}
}

//Função cria arquivo para receber as entidades ordenadas;

void criarOrdenado( FILE **arqOut, char *nome ){
	if( !( *arqOut = fopen( nome, "w" ) ) )
		exit(1);
}

//Função escreve entidade no arquivo ordenado;

void escrOrdenado( FILE *arqOut, entidade fita, int rodada ){

	if( rodada > 1 )
		fprintf( arqOut, "\n%s " , fita.url );
	else fprintf( arqOut, "%s " , fita.url );
	fprintf( arqOut, "%d" , fita.acesso );
}

//Função para fechar arquivo;

void fechaArquivo( FILE **arq ){
	fclose( *arq );
}

//Função para abrir um arquivo;

void abrirArquivo( FILE **arqIn, char *nome ){
	if( !( *arqIn = fopen( nome, "r" ) ) )
		exit(1);
}

void removeArquivo( int numeroArq ){
    char arqRodada[20];

    sprintf( arqRodada, "rodada-%d.txt", numeroArq );

    remove( arqRodada );
}
