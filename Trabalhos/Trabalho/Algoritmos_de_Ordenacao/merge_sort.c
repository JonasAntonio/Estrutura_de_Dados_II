#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000

int mov=0, comp=0;

void Juntar(int vetor[], int ini, int meio, int fim, int vetAux[]) {
      int esq = ini;
      int dir = meio;
      int i;
      for (i = ini; i < fim; ++i) {
          if ((esq < meio) && ((dir >= fim) || (vetor[esq] < vetor[dir]))) {
              vetAux[i] = vetor[esq];
              ++esq;
              comp++;
              mov++;
          }
          else {
             vetAux[i] = vetor[dir];
             ++dir;
             comp++;
             mov++;
         }
     }
    //copiando o vetor de volta
     for (i = ini; i < fim; ++i) {
         vetor[i] = vetAux[i];
         mov++;
     }
 }

 void MergeSort(int vetor[], int inicio, int fim, int vetorAux[]) {
     if ((fim - inicio) < 2){
	 	comp++;
	 	return;
	 }

     int meio = ((inicio + fim)/2);
     MergeSort(vetor, inicio, meio, vetorAux);
     MergeSort(vetor, meio, fim, vetorAux);
     Juntar(vetor, inicio, meio, fim, vetorAux);
 }

 void mergeSort(int vetor[], int tamanho) { //função que o usuario realmente chama
     //criando vetor auxiliar
     int vetorAux[tamanho];
     MergeSort(vetor, 0, tamanho, vetorAux);
 }

int main(){
	int i,vet[MAX];
	srand(time(NULL));
	for(i=0;i<MAX;i++){
		vet[i] = rand() % MAX;
	}
   	mergeSort(vet,MAX);
	for(i=0;i<MAX;i++){
		printf("[%d] %d\n", i,vet[i]);
	}
	printf("Movimentos: %d\n", mov);
	printf("Comparacoes: %d\n", comp);
	return 0;
}
