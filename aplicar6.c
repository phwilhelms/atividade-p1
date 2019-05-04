# include <stdio.h>
# include <stdlib.h>
# include "6.h"


int main(void) {
	Lista *l;
    int qtde;
    int i;
    float peso,mala_p,max_permitido,somaT;


    printf("Quantos itens deseja colocar?\n");
    scanf("%d",&qtde);
    printf("Informe o peso da mala:\n");
    scanf("%f",&mala_p);
    printf("Informe o maximo permitido:\n");
    scanf("%f",&max_permitido);


    printf("Foi criada a lista vazia.\n");
    l = cria_lista_vazia();
    for (i=0;i<qtde;i++)
    {
     	printf("Informe o peso do objeto: %d\n",i+1);
      	scanf("%f",&peso);
      	adiciona_item(l,peso);
    }
    somaT = verifica_peso(l,mala_p);
    imprime_lista(l);
    while (somaT > max_permitido)
    {
        printf("Maximo permitido alcancado, retirando mais pesado...\n");
        remove_item(l,mais_pesado(l,qtde));
        somaT = verifica_peso(l,mala_p);
        imprime_lista(l);
    }
    printf("Mala despachada com o peso total de %.3f kg\n", verifica_peso(l,mala_p));


    return(0);
}
