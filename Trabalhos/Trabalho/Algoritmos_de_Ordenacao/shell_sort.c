#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000

void shellSort(int *vet, int size) {
    int i , j , value, mov=0, comp=0;
    int gap = 1;
    while(gap < size) {
        gap = 3*gap+1;
        comp++;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value = vet[i];
            j = i - gap;
            while (j >= 0 && value < vet[j]) {
                vet [j + gap] = vet[j];
                j -= gap;
                comp++;
                mov++;
            }
            vet [j + gap] = value;
            mov++;
            comp++;
        }
        comp++;
    }
    for(i=0; i<size; i++){
        printf("[%d] %d\n", i, vet[i]);
    }
    printf("M - %d\n", mov);
    printf("C - %d\n", comp);
}
int main(){
    int i;
    int vet[MAX];
    srand(time(NULL));
    for(i=0; i<MAX; i++){
        vet[i] = rand() % MAX;
    }
    shellSort(vet, MAX);

}
