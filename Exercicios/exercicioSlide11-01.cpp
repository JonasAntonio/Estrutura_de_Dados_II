#include <stdio.h>
#include <stdlib.h>
#define Maxn 1000

typedef int TipoChave;

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
    		printf("Valor %d nao existe na tabela!\n", x);
	}else {
    		printf("Valor %d existe na posição %d da tabela!\n", x, i);
	}
	return i;
}

void Insere(Registro reg, Tabela *T) {
	if(T->n == Maxn) {
    		printf("Erro: tabela repleta\n");
    		exit(1);
	}
	else {
    		T->n++;
    		T->Item[T->n] = reg;
    		printf("Valor %d inserido na tabela!\n", reg.Chave);
	}
}

void Remove(TipoChave x, Tabela *T) {
	int i = Pesquisa(x, T);
	if(i) {
    		T->Item[i] = T->Item[T->n];
    		T->n -= 1;
    		printf("Valor %d removido da tabela!\n", x);
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
    		printf("\t3 - Pesquisar\n");
    		printf("\t0 - Sair\n");
    		printf("\t ------------ \n\n");

    		scanf("%d", &menu);
    		system("cls || clear");

    		switch(menu) {
        		case 1:
            		scanf("%d", &reg.Chave);
            		Insere(reg, &Tab);
            	break;
        		case 2:
            		scanf("%d", &reg.Chave);
            		Remove(reg.Chave, &Tab);
            	break;
        		case 3:
            		scanf("%d", &reg.Chave);
            		Pesquisa(reg.Chave, &Tab);
            	break;
        		case 0:
            	break;
        		default:
            		printf("\nDigite uma opcao valida\n");
    		}
	} while(menu);
}

