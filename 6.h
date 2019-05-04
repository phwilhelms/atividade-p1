#define MAXTAM 50

typedef struct item Item;
typedef struct lista Lista;

Lista * cria_lista_vazia();
int verifica_lista_cheia(Lista *l);
void adiciona_item(Lista *l, float chave);
void imprime_lista(Lista *l);
int verifica_lista_vazia(Lista *l);
float verifica_peso (Lista *l, float peso_M);
float mais_pesado(Lista *l, int tam);
int busca_item_por_chave(Lista *l, float chave);
void remove_item(Lista *l, float chave);
void libera_lista(Lista *l);
