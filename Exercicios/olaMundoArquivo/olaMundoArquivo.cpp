#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE* f;
	char frase[100];
	char c;
	f = fopen("arquivo.txt", "rt");
	if(f == NULL){
		printf("Deu ruim");
		exit(1);
	} else {
		while((c = fgetc(f)) != EOF){
			putchar(c);
		}
	}
	
	fclose(f);
	
	return 0;
	
}
