#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Venda.h"


Venda lerVenda(Cliente *c, int *tam_c, Produtos *p, int *tam_p){
    Venda terceiro;
    printf("COdigo da venda: ");
    scanf("%d", &terceiro.codV);
    printf("\n");
    scanf("%*[^\n]");scanf("%*c");

    char buscaC[20];
    int achouC =-1;
    printf("DIgite o CPF do CLiente: ");
    scanf("%[^\n]", buscaC);
    for(int i = 0 ; i < *tam_c; i ++){
        if (strcmp(c[i].CPF , buscaC)== 0){
            achouC = 1;
            break;
        }
    }
    if (achouC == -1){
        printf("Cliente ainda nao esta Cadastrado  no Banco de Dados!!");
        
    }
    else{
        strcpy(terceiro.CodC, buscaC);
    }
    
    int buscaP;
    int achouP = -1;
    printf("DIgite o Codigo do Produto: ");
    scanf("%d", &buscaP);
    for(int i = 0 ; i < *tam_p; i ++){
        if(p[i].codP == buscaP){
            achouP = 1;
            break;
        }
    }
    if (achouP == -1){
        printf("Produto nao cadastro no Banco de Dados !!\n");
        
    }
    else{
        terceiro.CodP == buscaP;
    }

    int qtdV;
    printf("Quantidade que esta sendo vendida: ");
    scanf("%d", &qtdV);  
    for(int i = 0 ; i < *tam_p; i ++){
        if (p[i].codP == buscaP){
            if (p[i].qnt < qtdV){
                printf("Nao possui quatidade necessaria no estoque !!");
                break;
            }
            else{
                p[i].qnt -= qtdV;
                terceiro.qtd = qtdV;
            }
        }
    } 

    return terceiro;

}

Venda *insere_venda(Venda *v, int *tam, Venda novo){
    if (v != 0){
        if (*tam == 0){
            v = (Venda*) malloc ( (*tam + 1) * sizeof(Venda));
            if (v == NULL){
                printf("ERRO: nao foi possivel alocar memoria");
            }
        }
        else{
            v = (Venda*) realloc (v, (*tam + 1) * sizeof(Venda));
            if (v == NULL){
                printf("ERRO: nao foi possivel alocar memoria");
            }
        } 
    }
    v[*tam]= novo;
    (*tam)++;
    return v;
}

void pesquisa_venda(Venda * v, int *tam){
    if (*tam == 0)
        printf("Nenhuma Venda Cadastrada\n");
    else{
        int busca;
        printf("DIgite o Codigo da Venda: ");
        scanf("%d", &busca);
        int achou =-1;
        int a;
        for(int i = 0 ; i < *tam; i++){
            if (v[i].codV == busca){
                achou =1;
                a=i;
                break;
            }
        }
        if(achou == -1){
            printf("Venda nao econtrada !! \n");
        }else{
            printf("\n-----------------------------------\n");
            printf("Codigo da Venda: %d\n", v[a].codV);
            printf("CPF do CLiente: %s\n", v[a].CodC);
            printf("Codigo do Produto: %d\n", v[a].CodP);
            printf("Quantidade vendida: %d", v[a].qtd );
            printf("\n-----------------------------------\n");
            printf("\n\n");	
        }
    }
}

void listar_venda(Venda *v, int *tam){
    if (*tam == 0){
        printf("Nao Possui Venda Cadastrado\n");
    }
    for (int i = 0 ; i < *tam; i ++){
        printf("\n-----------------------------------\n");
        printf("Codigo da Venda: %d\n", v[i].codV);
        printf("CPF do CLiente: %s\n", v[i].CodC);
        printf("Codigo do Produto: %d\n", v[i].CodP);
        printf("Quantidade vendida: %d", v[i].qtd );
        printf("\n-----------------------------------\n");
        printf("\n\n");	
    }
}
void salvar_venda(Venda * v, int * tam){
	FILE *arq = fopen("venda.txt", "w+");
	if (arq == NULL){
        printf("Problema na abertura do arquivo !!");
    }

	for (int i = 0 ; i < *tam; i++){
		
		fprintf(arq, "\n-----------------------------------\n");
		fprintf(arq, "Codigo da Venda: %d", v[i].codV);
		fprintf(arq, "\nCPF do CLiente: %s", v[i].CodC);
		fprintf(arq, "\nCodigo do Produto: %d", v[i].CodP);
		fprintf(arq, "\nQuantidade vendida: %d", v[i].qtd);
		fprintf(arq, "\n-----------------------------------\n\n");
	}
	fclose(arq);
}

Venda *excluir_venda(Venda *v, int *tam){
    printf("Digite o COdigo da Venda que deseja EXCLUIR: ");
    int cod;
    scanf("%d", &cod);
    for (int i = 0 ; i < *tam; i ++){
        if (v[i].codV == cod){
            printf("\n-----------------------------------\n");
            printf("Codigo da Venda: %d\n", v[i].codV);
            printf("CPF do CLiente: %s\n", v[i].CodC);
            printf("Codigo do Produto: %d\n", v[i].CodP);
            printf("Quantidade vendida: %d", v[i].qtd );
            printf("\n-----------------------------------");
            printf("\n\n");	
            char opcao;
            printf("\n\nDeseja excluir? (S/N)\n");
			scanf("%s", &opcao);
            if((opcao == 'S')|| (opcao =='s')){
                v[i] = v[(*tam) -1];
                v= (Venda*) realloc (v, ((*tam) -1) * sizeof(Venda));
                (*tam) --;
                printf("Venda EXCLUIDA !!\n");
                break;
            }
            else
                printf("Operacao CANCELADA !!\n");
        }
        else
            printf("Venda nao encontrado\n");
    }
    return v;
}