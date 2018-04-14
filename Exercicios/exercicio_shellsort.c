#include<stdio.h>
#include<stdlib.h>

void shellsort(int n,char v[]){
    //span: tamanho do incremento
    int i,j,k,span,y,incr[3] = {5,3,1};
    for(i=0;i<sizeof(incr);i++){
        span = incr[i];
        for(j=span;j<n;j++){
            //insere elemento v[j] na posicao correta no subvetor
            y = v[j];
            for(k=j-span;k>=0 && y<v[k];k-=span)
                v[k+span] = v[k];
            v[k+span] = y;
        }
    }
}
int main(){
    char v[10] = {'G','E','I','J','A','D','F','C','H','B'};
    int i;
    shellsort(10,v);
    for(i = 0; i < 10; i++){
        printf("%c", v[i]);
    }
    return 0;
}
