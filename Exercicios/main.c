//
//  main.c
//  arquivo
//
//  Created by Barbara de Melo Quintela on 04/08/17.
//  Copyright © 2017 CESJF. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    
    FILE* f1;
    FILE* f2;
    char str[20];
    
    f1 = fopen("alomundo.txt", "w");
    
    if (f1 != NULL){
        fprintf(f1, "alo mundo!");
        fclose(f1);
   
        f1 = fopen("alomundo.txt", "r");
        if (f1 != NULL){
        
            f2 = fopen("teste.txt", "w");
            if (f2 != NULL ){
                fgets(str,sizeof(str),f1);
                fprintf(f2, "%s", str);
                
                fclose(f1);
                fclose(f2);
            }
            else
                printf("erro ao abrir arquivo\n");
        }
        else
            printf("erro ao abrir arquivo\n");
    
    }
    else
        printf("erro ao abrir arquivo\n");
    
    
    
    

    
    
    return 0;
}
