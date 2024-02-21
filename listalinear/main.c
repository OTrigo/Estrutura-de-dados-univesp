#include <stdbool.h>

#define MAX 50

typedef int TIPOCHAVE;

typedef struct
{
  TIPOCHAVE chave;
} REGISTRO;

typedef struct
{
  REGISTRO registros[MAX];
  int nroElem;
} LISTA;

void inicializarLista(LISTA *lista)
{
  lista->nroElem = 0;
}

int imprimirNumeroElementos(LISTA *lista)
{
  return lista->nroElem;
}

void exibirLista(LISTA *lista)
{
  int i;
  printf("Lista: \" ");
  for (i = 0; i < lista->nroElem; i++)
  {
    printf("%i", lista->registros[i].chave);
  }
}

int buscaSequencial(LISTA *lista, TIPOCHAVE chave)
{
  int i = 0;
  while (i < lista->nroElem)
  {
    if (chave == lista->registros[i].chave)
      return i;
    else
      i++;
  }
  return -1;
}

bool inserirElemLista(LISTA *lista, REGISTRO registro, int indice)
{
  int j;
  if ((lista->nroElem == MAX) || (indice < 0) || (indice > lista->nroElem))
    return false;

  for (j = lista->nroElem; j > indice; j--)
  {
    lista->registros[j] = lista->registros[j - 1];
  }
  lista->registros[indice] = registro;
  lista->nroElem++;
  return true;
}

int main()
{

  return 0;
}
