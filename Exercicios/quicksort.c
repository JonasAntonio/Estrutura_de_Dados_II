#include<stdio.h>

void quicksort(int n, int vet[]){
    if(n<=1)
        return;
    int x = vet[0]; //pivo
    int a = 1;
    int b = n-1;
    int temp;
    do{
        while(a<n && vet[a]<=x)
            a++;
        while(vet[b]>x)
            b--;
        if(a<b){
            temp = vet[a];
            vet[a] = vet[b];
            vet[b] = temp;
            a++;
            b--;
        }
    } while(a<=b);
    //troca o pivo
    vet[0] = vet[b];
    vet[b] = x;
    //ordena subvetores recursivamente
    quicksort(b,vet);
    quicksort(n-a,&vet[a]);
}

int main(){

    int i, num[10] = {9,8,7,6,5,4,3,2,1,0};
    quicksort(10,num);
    for(i = 0; i<10; i++){
        printf("%d", num[i]);
    }
    return 0;
}
