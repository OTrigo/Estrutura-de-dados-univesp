#include <stdio.h>
#include <malloc.h>

int main()
{
  int* endereco = (int*) malloc(sizeof(int));
  *endereco = 20;
  int tamanhoDoNumero = sizeof(int);
  printf("endereco: %i, tamanho do numero: %i\n", endereco, tamanhoDoNumero);
  return 0;
}
