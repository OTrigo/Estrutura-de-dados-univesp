#include <stdio.h>
#include <stdbool.h>

#define VERDADEIRO true

void bubbleSort(int array[], int numero){
  for(int index = 0; index < numero - 1; index++){
    for(int index2 = 0; index2 < numero - 1; index2++){
      if(array[index2]>array[index2+1]){
        // Caso seja verdadeiro, o valor maior será armazenado na variavel auxiliar e será feito um swap entre a variável index2 e index2+1.
        int variavelTemporaria = array[index2];
        array[index2] = array[index2 + 1];
        array[index2 + 1] = variavelTemporaria;
      }
    }
  }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Array ordenado: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}