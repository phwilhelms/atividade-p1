#define MAXTAM 4

typedef struct item Item;
typedef struct fila Fila;

Fila * cria_fila_vazia();
int verifica_fila_vazia(Fila *f);
int verifica_fila_cheia(Fila *f);
void enfileira(Fila *f, int chave);
void desenfileira(Fila *f);
void imprime_fila(Fila *f);
void libera (Fila *f);
void verifica_maior(Fila *f);
