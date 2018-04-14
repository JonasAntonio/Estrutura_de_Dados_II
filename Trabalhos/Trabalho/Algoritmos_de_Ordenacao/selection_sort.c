#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000


void selection_sort (int vetor[],int max) {
  int i, j, min, aux, mov=0,comp=0;

  for (i = 0; i < (max - 1); i++) {
    /* O minimo é o primeiro número não ordenado ainda */
    min = i;
    for (j = i+1; j < max; j++) {
      /* Caso tenha algum numero menor ele faz a troca do minimo*/
      if (vetor[j] < vetor[min]) {
        min = j;
        comp++;
      }
    }
    /* Se o minimo for diferente do primeiro numero não ordenado ele faz a troca para ordena-los*/
    if (vetor[i] != vetor[min]) {
      aux = vetor[i];
      vetor[i] = vetor[min];
      vetor[min] = aux;
      comp++;
      mov++;
    }
  }
  /* Imprime o vetor ordenado */
  for (i = 0; i < max; i++) {
    printf ("[%d] %d \n",i,vetor[i]);
  }
    printf("%d\n", mov);
    printf("%d\n", comp);
}

int main () {
  int i;
  int  vetor[MAX];
  /* Lê os algarismos do vetor */
  srand(time(NULL));
  for (i = 0; i < MAX; i++) {
    vetor[i] = rand() % MAX;
  }

  selection_sort (vetor, MAX);

}
