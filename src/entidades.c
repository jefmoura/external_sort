#include <string.h>
#include "tad.h"

//Função que lê do arquivo de entrada as entidades, criando as rodadas e retorna o número de entidades que foram lidas;

int lerRodada( FILE *arqIn, int numEntidade, entidade fita[] ){
	int cntEntidade = 0;

	while( !feof( arqIn ) && cntEntidade < numEntidade ){
		fscanf( arqIn, "%s %d", &fita[cntEntidade].url, &fita[cntEntidade].acesso );
		cntEntidade++;
	}
	return cntEntidade;
}

//Função verifica se já acabou as entidades de um arquivo e retorna valores boolenas considerando 1 estando vazio e 0 ainda tem entidade;

int verifArquivo( FILE *arqIn ){
	if( feof( arqIn ) )
		return 1;

	else
		return 0;
}

//Ler apenas uma entidade do arquivo;

void lerEntidade( FILE *arqIn, entidade *fita, int num ){
	fscanf( arqIn, "%[^123456789]s", fita->url );
	fscanf( arqIn, "%d", &fita->acesso );
	fita->rodada = num;
	getc( arqIn );
}

//Função chama funções para ler e ordenar entidade para depois gravar o maior das entidades no arquivo de saída;

void entidadesSort( FILE **arqIn, FILE *arqOut, entidade *fita, int numRodada ){
	int cntRodada = 0;

	for(; cntRodada < numRodada; cntRodada++ )
		lerEntidade( arqIn[cntRodada], &fita[cntRodada+1], cntRodada);
	cntRodada = 1;
    criarHeap( fita, numRodada );

	while( fita[1].acesso != 0 ){
	    escrOrdenado( arqOut, fita[1], cntRodada );

		if( verifArquivo( arqIn[ fita[1].rodada ] ) == 0 )
			lerEntidade( arqIn[ fita[1].rodada ], &fita[1], fita[1].rodada );
		else fita[1].acesso = 0;

		refaz( 1, numRodada, fita );
		cntRodada++;
	}
}

//Função para retirar qualquer elemento que exista na fita;

void zerarFita( entidade fita[], int numEntidade ){
	entidade *aux = ( entidade * ) malloc( sizeof( entidade ) );

	aux->url[0] = '\0';
	aux->acesso = 0;

	memcpy( fita, aux, numEntidade );

    free( aux );
}
