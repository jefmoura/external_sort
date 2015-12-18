#include "tad.h"

//Alocar dinamicamente um vetor de entidades;

void alocarFita( int tam, entidade **fita ){
	*fita = ( entidade * ) malloc( tam*( sizeof(entidade ) ) );
}

//Realocar dinamicamente o vetor de entidades para o tamanho igual ao número de rodadas;

void realocarFita( int tam, entidade **fita ){
	*fita = ( entidade * ) realloc( *fita, tam*( sizeof( entidade ) ) );
}

//Função para desalocar entidade;

void desalocEntidade( entidade **fita ){
	free( *fita );
}
