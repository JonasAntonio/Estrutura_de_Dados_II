#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 10000

int mov=0, comp=1;

void quicksort(int n, int vet[]){
    if(n<=1)
        return;
    int x = vet[0]; //pivo
    int i;
    int a = 1;
    int b = n-1;
    int temp;
    do{
        while(a<n && vet[a]<=x){
            a++;
            comp++;
        }
        while(vet[b]>x){
            b--;
            comp++;
        }
        if(a<b){
            temp = vet[a];
            vet[a] = vet[b];
            vet[b] = temp;
            a++;
            b--;
            mov++;
            comp++;
        }
    } while(a<=b);
    //troca o pivo
    vet[0] = vet[b];
    vet[b] = x;
    mov++;
    //ordena subvetores recursivamente
    quicksort(b,vet);
    quicksort(n-a,&vet[a]);


}

int main() {
    int i;
    int vet[MAX];
    srand(time(NULL));
    for(i = 0; i<MAX; i++){
        vet[i] = rand() % MAX;
    }
    quicksort(MAX,vet);
    for (i = 0; i < MAX; i++) {
        printf ("[%d] %d \n",i,vet[i]);
    }
    printf("%d\n", mov);
    printf("%d\n", comp);

    return 0;
}
