#include <stdio.h>
#include <stdlib.h>
#include "4b.h"

main()
{
	int i;
	Fila *f = cria_fila_vazia();
	Fila *g = cria_fila_vazia();
	int vetor_teste[4] = {4, 5, 2, 25};
	int vetor_teste2[4] = {13, 7, 6, 12};

	for(i = 0; i < 4; i++)
	{
		verifica_fila_cheia(f);
		verifica_fila_cheia(g);
		enfileira(f, vetor_teste[i]);
		enfileira(g, vetor_teste2[i]);
	}

	imprime_fila(f);

	verifica_maior(f);

	printf("\n\n\n");

	imprime_fila(g);

	verifica_maior(g);
	
	libera(f);
	libera(g);
}
