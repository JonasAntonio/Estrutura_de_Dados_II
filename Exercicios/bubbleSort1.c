#include<stdio.h>
#include<stdlib.h>
#define t 3

struct Produto{
    int cod;
    float preco;
};

void swap(struct Produto *pv, int x, int y){
    struct Produto aux = pv[x];
    pv[x] = pv[y];
    pv[y] = aux;
}

void bubbleSort(struct Produto *p){
    int i,j;
    for(i=t-1; i>0; i--){
        for(j=0; j<i; j++){
            if(p[j].cod > p[j+1].cod)
                //A comparação pelo membro cod da struct
                swap(p,j,j+1);
        }
    }
}



int main(){
    struct Produto a[t];
    int i;
    printf("ENTRE COM OS DADOS: CODIGO E PRECO \n");
    for(i=0;i<t;i++){
        scanf("%d",&a[i].cod);
        scanf("%f",&a[i].preco);
    }
    //system("clear");
    bubbleSort(a);

    printf("BUBBLESORTED\n");
    for(i=0;i<t;i++){
        printf("%d %.2f\n", a[i].cod, a[i].preco);
    }


    return 0;
}
