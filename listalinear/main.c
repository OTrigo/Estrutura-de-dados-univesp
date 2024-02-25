#include <stdbool.h>

#define MAX 50

typedef int TIPOCHAVE;

typedef struct
{
  TIPOCHAVE chave;
} REGISTRO;

typedef struct
{
  REGISTRO registros[MAX + 1];
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

int buscaSentinela(LISTA *lista, TIPOCHAVE chave)
{
  int i = 0;
  lista->registros[lista->nroElem].chave = chave;
  while (lista->registros[i].chave != chave)
    i++;
  if (i == lista->nroElem)
    return -1;
  else
    return i;
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

bool inserirElemListaOrdenada(LISTA *lista, REGISTRO registro)
{
  if (lista->nroElem >= MAX)
    return false;
  int pos = lista->nroElem;
  while (pos > 0 && lista->registros[pos - 1].chave > registro.chave)
  {
    lista->registros[pos] = lista->registros[pos - 1];
    pos--;
  }
  lista->registros[pos] = registro;
  lista->nroElem++;
}

int buscaBinaria(LISTA *lista, TIPOCHAVE chave)
{
  int esquerda, direita, meio;
  esquerda = 0;
  direita = lista->nroElem - 1;
  while (esquerda <= direita)
  {
    meio = ((esquerda + direita) / 2);
    if (lista->registros[meio].chave == chave)
      return meio;
    else
    {
      if (lista->registros[meio].chave < chave)
        esquerda = meio + 1;
      else
        direita = meio - 1;
    }
  }
  return -1;
}

int main()
{
  return 0;
}
