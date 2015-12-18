#include "tad.h"

//As três funções seguintes fazem parte do algoritmo de ordenação quicksort;

void quickSort( entidade fita[], int numEntidade ){
	ordena( 0, numEntidade-1, fita );
}

void ordena( int esq, int dir, entidade fita[] ){
	int i, j;

	particao( esq, dir, &i, &j, fita );
	if( esq < j ) ordena( esq, j, fita );
	if( i < dir ) ordena( i, dir, fita );
}

void particao( int esq, int dir, int *i, int *j, entidade fita[] ){
	entidade auxTroca, pivo;
	int indPivo;

	*i = esq;
	*j = dir;
	indPivo = (*i + *j)/2;
	pivo = fita[indPivo];
	do{
		while( pivo.acesso < fita[*i].acesso ) (*i)++;
		while( pivo.acesso > fita[*j].acesso ) (*j)--;
		if( *i <= *j ){

			auxTroca = fita[*i];
			fita[*i] = fita[*j];
			fita[*j] = auxTroca;
			(*i)++;
			(*j)--;
		}
	}
	while( *i <= *j );
}

//Termina aqui o algoritmo de ordenação do quicksort;

//Algoritmo de inserção, para ordenar em ordem alfabética o quicksort;

void insertionSort( entidade fita[], int fim){
    int i;
    int ini = 1;
	entidade auxTroca;

        for( ; ini < fim; ini++){
            auxTroca = fita[ini];
            i = ini-1;
            while(i >= 0 && fita[i].acesso == auxTroca.acesso ){
                if( strcmp( auxTroca.url, fita[i].url ) < 0 ){
                    fita[i+1] = fita[i];
                    i--;
                }
                else break;
            }
            fita[i+1] = auxTroca;
        }
}

//As duas funções abaixo servem para criar um heap;

void criarHeap( entidade fita[], int tam ){
	int esq;
	esq = ( tam/2 )+1;

	while( esq > 1 ){
		esq--;
		refaz( esq, tam, fita );
	}
}

void refaz( int esq, int dir, entidade fita[] ){
	int i = esq;
	int j = i*2;
	entidade auxTroca;

	auxTroca = fita[i];
	while( j<= dir ){
		if( j < dir )
			if( fita[j].acesso <= fita[j+1].acesso ){
				j++;
				if( fita[j-1].acesso == fita[j].acesso )
                    if( strcmp( fita[j-1].url, fita[j].url ) < 0 )
                        j--;
			}
		if( auxTroca.acesso > fita[j].acesso )
			break;
        if( auxTroca.acesso == fita[j].acesso )
            if( strcmp( auxTroca.url, fita[j].url ) < 0 )
                break;
		fita[i] = fita[j];
		i = j;
		j = i*2;
	}
	fita[i] = auxTroca;
}
