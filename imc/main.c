#include <stdio.h>
#include <malloc.h>

#define alturaMaxima 225

typedef struct
{
  int peso;
  int altura;
} PesoAltura;

int main()
{
  PesoAltura *pessoa1 = (PesoAltura *)malloc(sizeof(PesoAltura));
  pessoa1->peso = 80;
  pessoa1->altura = 185;

  printf("Peso: %i, Altura: %i, Endereco de memoria: %i\n", pessoa1->peso, pessoa1->altura, &pessoa1);

  return 0;
}
