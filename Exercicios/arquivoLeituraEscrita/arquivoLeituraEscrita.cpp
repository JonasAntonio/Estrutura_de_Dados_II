#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE* f;
	f = fopen("arquivo.txt", "w+t");
	if(f == NULL){
		printf("Deu ruim");
		exit(1);
	} else {
		printf("Ae carai");
	}
	fclose(f);
	
	return 0;
	
}
