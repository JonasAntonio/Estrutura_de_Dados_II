#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 100000

int mov=0,comp=0;

void heapsort(int a[], int n) {
   int i = n / 2, pai, filho, t;
   for (;;) {
      if (i > 0) {
          i--;
          t = a[i];
          comp++;
      } else {
          n--;
          if (n == 0){
            comp++;
            return;
          }
          t = a[n];
          a[n] = a[0];
          mov++;
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho])){
              filho++;
              comp++;
              mov++;
          }
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
             comp++;
             mov+=2;
          } else {
             break;
          }
      }
      a[pai] = t;
      mov++;
   }

}

int main(){
    int i,vet[MAX];
    srand(time(NULL));
    for(i=0;i<MAX;i++){
        vet[i] = rand() % MAX;
    }
    heapsort(vet,MAX);
    for(i=0;i<MAX;i++){
        printf("[%d] %d\n", i, vet[i]);
   }
   printf("MOVIMENTOS: %d\n", mov);
   printf("COMPARACOES: %d\n", comp);
return 0;
}
