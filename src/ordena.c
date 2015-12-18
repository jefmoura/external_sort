#include "tad.h"

int main( int argc, char *argv[] ){
	entidade *fita;
	int numeroEnti;
	int rodada = 1;
	FILE *arqIn, *arqOut;

	abrirArquivo( &arqIn, "teste.txt" );
	//sscanf( argv[3], "%d", &numeroEnti );
	numeroEnti = 200;

	alocarFita( numeroEnti, &fita );

	while( !feof( arqIn ) ){
		numeroEnti = lerRodada( arqIn, numeroEnti, fita );
		quickSort( fita, numeroEnti );
		insertionSort( fita, numeroEnti );

		criarArqRodada( &arqOut, &rodada );
		escrRodada( arqOut, fita, numeroEnti );
		fechaArquivo( &arqOut );

		zerarFita( fita, numeroEnti );
	}
	realocarFita( rodada, &fita );
	--rodada;
	FILE *arqRodadas[rodada];

	fechaArquivo( &arqIn );

	criarOrdenado( &arqOut, "ordenado.txt" );
	abrirRodadasn( rodada, arqRodadas );

	entidadesSort( arqRodadas, arqOut, fita, rodada );

	for( numeroEnti = 0; numeroEnti < rodada; numeroEnti++ ){
		fechaArquivo( &arqRodadas[numeroEnti] );
		removeArquivo( numeroEnti+1 );
	}

	fechaArquivo( &arqOut );

	desalocEntidade( &fita );

	return 0;
}
