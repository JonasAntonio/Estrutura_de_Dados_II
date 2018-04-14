#include <stdio.h>
#include <stdlib.h>
#define Maxn 1000

typedef char TipoChave;

typedef struct Registro {
	TipoChave Chave;
} Registro;

typedef int Indice;

typedef struct Tabela {
	Registro Item[Maxn + 1];
	Indice n;
} Tabela;

void Inicializa(Tabela *T) {
	T->n=0;
}

Indice Pesquisa(TipoChave x, Tabela *T) {
	int i;
	T->Item[0].Chave = x;
	i = T->n+1;
	do{
    		i--;
	}while(T->Item[i].Chave != x);
	if(i==0){
    		printf("Valor %c nao existe na tabela!\n", x);
	}else {
    		printf("Valor %c existe na posição %d da tabela!\n", x, i);
	}
	return i;
}

Indice Binaria(TipoChave x, Tabela *T) {
	Indice i, esq, dir;
	if(T->n == 0) {
    		printf("Valor %c nao existe na tabela!\n", x);
    		return 0;
	} else {
    		esq = 1;
    		dir = T->n;
    		do{
        			i = (esq+dir)/2;
        			if(x > T->Item[i].Chave){
            			esq = i + 1;
        			} else {
            			dir = i - 1;
        			}
    		}while(x != T->Item[i].Chave && esq<=dir);
    	if(x == T->Item[i].Chave) {
        		printf("Valor %c existe na posição %d da tabela!\n", x, i);
        		return i;
    	} else {
        		return 0;
    	}
}
}

void Insere(Registro reg, Tabela *T) {
	if(T->n == Maxn) {
    		printf("Erro: tabela repleta\n");
    		exit(1);
	}
	else {
    		T->n++;
    		T->Item[T->n] = reg;
    		printf("Valor %c inserido na tabela!\n", reg.Chave);
	}
}

void Remove(TipoChave x, Tabela *T) {
	int i = Pesquisa(x, T);
	if(i) {
    		T->Item[i] = T->Item[T->n];
    		T->n -= 1;
    		printf("Valor %c removido da tabela!\n", x);
	}
}

int main(){
	Tabela Tab;
	Inicializa(&Tab);
	Registro reg;

	int menu = 1;

	do {
    		printf("\n\t ----MENU---- \n");
    		printf("\t1 - Inserir\n");
    		printf("\t2 - Remover\n");
    		printf("\t3 - Pesquisa Sequencial\n");
    		printf("\t4 - Pesquisa Binaria\n");
    		printf("\t0 - Sair\n");
    		printf("\t ------------ \n\n");

    		scanf("%d", &menu);
    		system("cls || clear");

    		switch(menu) {
        		case 1:
            		scanf(" %c", &reg.Chave);
            		Insere(reg, &Tab);
            	break;
        		case 2:
            		scanf(" %c", &reg.Chave);
            		Remove(reg.Chave, &Tab);
            	break;
        		case 3:
            		scanf(" %c", &reg.Chave);
            		Pesquisa(reg.Chave, &Tab);
            	break;
        		case 4:
            		scanf(" %c", &reg.Chave);
            		Binaria(reg.Chave, &Tab);
            	break;
        		case 0:
            	break;

        		default:
            		printf("\nDigite uma opcao valida\n");
    		}
	} while(menu);
}

