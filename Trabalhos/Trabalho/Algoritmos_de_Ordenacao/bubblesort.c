#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000

long int mov=0,comp=0;

void bubbleSort(int vetor[], int tam) {
    int i,fim,aux;
    for (fim = tam-1; fim > 0; --fim) {
        for (i = 0; i < fim; ++i) {
            if (vetor[i] > vetor[i+1]) {
                aux = vetor[i];
                vetor[i] = vetor[i+1];
                vetor[i+1] = aux;
                mov+=2;
                comp++;
            }
        }
    }
    for(i=0;i<MAX;i++){
        printf("[%d] %d\n", i,vetor[i]);
    }

}

int main(){
    int i,vet[MAX];
    srand(time(NULL));
    for(i=0;i<MAX;i++){
        vet[i] = rand() % MAX;
    }
    bubbleSort(vet,MAX);
    printf("MOVIMENTOS: %ld\n", mov);
    printf("COMPARACOES: %ld\n", comp);
    return 0;
}
