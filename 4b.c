#include <stdio.h>
#include <stdlib.h>
#include "4b.h"

struct item
{
	int chave;
};

struct fila
{
	Item item[MAXTAM];
	int primeiro, ultimo, tamanho;
};

Fila * cria_fila_vazia()
{
	Fila *f = malloc(sizeof(Fila));
	f->primeiro = 0;
	f->ultimo = 0;
	f->tamanho = 0;
	return f;
}

int verifica_fila_vazia(Fila *f)
{
	return f->tamanho == 0;
}

int verifica_fila_cheia(Fila *f)
{
	return f->tamanho == MAXTAM;
}

void enfileira(Fila *f, int chave)
{
	if(verifica_fila_cheia(f))
	{
		printf("Erro: Fila cheia.\n");
		return;
	}
	else
	{
		Item novo_item;
		novo_item.chave = chave;
		f->item[f->ultimo] = novo_item;
		f->ultimo = (f->ultimo + 1) % MAXTAM;
		f->tamanho++;
	}
}

void desenfileira(Fila *f)
{
	if(verifica_fila_vazia(f))
	{
		printf("Erro: Fila vazia.\n");
		return;
	}
	else
	{
		f->primeiro = (f->primeiro + 1) % MAXTAM;
		f->tamanho--;
	}
}

void imprime_fila(Fila *f)
{
	int i = f->primeiro;
	int t = f->tamanho;
	while(t > 0)
	{
		printf("%d\t", f->item[i].chave);
		t--;
		i = (i + 1) % MAXTAM;
	}
	printf("\n");
}

void libera(Fila *f)
{
	free(f);
}

void verifica_maior(Fila *f)
{
	int i, b, maior;

	printf("\nChave\tMaior\n\n");
	
	while(verifica_fila_vazia(f) == 0)
	{
		maior = f->item[f->primeiro].chave;
		desenfileira(f);
		int t = f->tamanho;
		int a = f->primeiro;
		//int b = f->ultimo;
		//printf("%d\n", a);
		//printf("%d\n", t);
		//printf("%d\n", maior);
		//printf("%d\n", b);
		
		for(i = a; i <= MAXTAM - 1; i++)
		{
			if(f->item[i].chave > maior && t !=0)
			{
				printf("%d\t%d\n", maior, f->item[i].chave);
				break;
			}
			else if(i == MAXTAM - 1)
			{
				printf("%d\t%d\n", maior, -1);
			}
		}

		/*if(t == 0)
		{
			printf("%d\t%d\n", f->item[i -1].chave, -1);
		}*/
	

		printf("\n\n");
	}
}
