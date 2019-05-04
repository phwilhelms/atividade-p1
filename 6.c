# include <stdio.h>
# include <stdlib.h>
# include "6.h"


typedef struct item Item;
typedef struct lista Lista;


struct item {
    float chave;
};

struct lista {
    Item item[MAXTAM];
    int ultimo;
};

Lista * cria_lista_vazia() {
    Lista *l = malloc(sizeof(Lista));
    l->ultimo = -1;
    return l;
}

int verifica_lista_cheia(Lista *l) {
    return l->ultimo == MAXTAM - 1;
}

void adiciona_item(Lista *l, float chave) {
    if(verifica_lista_cheia(l)){
        printf("Erro: a lista est� cheia.\n");
        return;
    }
    else {
        Item novo_item;
        novo_item.chave = chave;
        l->ultimo++;
        l->item[l->ultimo] = novo_item;
    }
}

void imprime_lista(Lista *l) {
    int tam = l->ultimo + 1;
    int i;
    for(i = 0; i < tam; i++)
    {
        printf("Peso: %.3f kg\n", l->item[i].chave);
    }
}

int verifica_lista_vazia(Lista *l) {
    return l->ultimo == -1;
}

float verifica_peso (Lista *l, float peso_M)
{
    int tam = l->ultimo + 1;
    int i;
    float soma = 0,somaT = 0 ;

    for(i = 0; i < tam; i++)
    {
        soma = soma + l->item[i].chave;
    }

    somaT= soma + peso_M;

 return somaT;
}

float mais_pesado(Lista *l, int tam)
{
    int i;
    float maior;
    maior = l->item[0].chave;
    for (i=0 ; i< tam;i++)
    {
        if ( maior < l->item[i].chave)
      {
          maior = l->item[i].chave;
      }
    }
    return maior;
}

int busca_item_por_chave(Lista *l, float chave) {
    int tam, i, posicao;
    tam = l->ultimo + 1;
    posicao = -1;
    for(i = 0; i < tam; i++)
        if(l->item[i].chave == chave)
            posicao = i;
    return posicao;
}

void remove_item(Lista *l, float chave) {
    int posicao, vazia, i, tam;
    vazia = verifica_lista_vazia(l);
    posicao = busca_item_por_chave(l, chave);
    if (vazia || posicao == -1) {
        printf("Erro: a lista est� vazia ou o item n�o existe.\n");
        return;
    }
    else {
        tam = l->ultimo + 1;
        for(i = posicao; i < tam - 1; i++)
            l->item[i] = l->item[i + 1];
        l->ultimo--;
    }
}

void libera_lista(Lista *l) {
    free(l);
}
