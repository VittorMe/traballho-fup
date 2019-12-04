#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Produto.h"

Produtos lerProduto(){
    Produtos segundo;
    printf("Codigo do Produto: ");
	scanf("%d", &segundo.codP);
	printf("\n");

    printf("Nome do Produto: ");
	scanf("%*[^\n]");scanf("%*c");
	scanf("%[^\n]",segundo.nome);
	printf("\n");

    printf("Quantidade do Produto: ");
	scanf("%d", &segundo.qnt);
	printf("\n");

    printf("Valor do Produto: ");
	scanf("%f", &segundo.valor);
	printf("\n");
    
    return segundo;
}

Produtos *insere_produto(Produtos *v, int *tam, Produtos novo){
    if (v != 0){
        if(*tam == 0){
            v=(Produtos*) malloc ( (*tam + 1)* sizeof(Produtos) );
            if (v == NULL){
				printf("ERRO: nao foi possivel alocar memoria ");
			}
        }
        else{
            v=(Produtos*) realloc (v, (*tam +1) * sizeof(Produtos));
            if (v == NULL){
				printf("ERRO: nao foi possivel alocar memoria ");
			}
        }
    } 
    v[*tam]= novo;
    (*tam)++;
    return v;
}

void pesquisa_produto(Produtos *v, int *tam){
    if (*tam ==0)
        printf("Nenhum Produto Cadastrado\n");
    else{
        int busca;
        printf("Digite o COdigo do Produto: ");
        scanf("%d", &busca);
        int achou = -1;
        int a;
        for (int i = 0 ; i < *tam; i ++){
            if (v[i].codP == busca) {
                achou = 1;
                a= i;
                break;
            }
        }
        if (achou == -1){
            printf ("Produto nao encontrado !!\n");
        }else{
            printf("\n-----------------------------------\n");
            printf("Codigo do Produto: %d", v[a].codP);			
            printf("\nNome do Produto: %s", v[a].nome);						
            printf("\nQuantidade do Produto: %d", v[a].qnt);
            printf("\nValor do Produto: R$ %.2f", v[a].valor);
            printf("\n-----------------------------------");
            printf("\n\n");	
        }
    }
}

void listar_produto(Produtos *p, int *tam){
    if (*tam == 0){
        printf("Nao Possui Produto Cadastrado\n");
    }
    for (int i = 0 ; i < *tam; i ++){
        printf("\n-----------------------------------\n");
        printf("Codigo do Produto: %d", p[i].codP);			
        printf("\nNome do Produto: %s", p[i].nome);						
        printf("\nQuantidade do Produto: %d", p[i].qnt);
        printf("\nValor do Produto: R$ %.2f", p[i].valor);
        printf("\n-----------------------------------");
        printf("\n\n");
    }
}
void salvar_produto(Produtos * v, int * tam){
	FILE *arq = fopen("Produtos.txt", "w+");
	
	for (int i = 0 ; i < *tam; i++){
		fprintf(arq, "\n-----------------------------------\n");
		fprintf(arq, "Codigo do Produto: %d", v[i].codP);
		fprintf(arq, "\nNome do Produto: %s", v[i].nome);
		fprintf(arq, "\nQuantidade do Produto: %d", v[i].qnt);
		fprintf(arq, "\nValor do Produto: R$ %.2f", v[i].valor);
		fprintf(arq, "\n-----------------------------------\n\n");
	}
	fclose(arq);

}
Produtos *excluir_produto(Produtos *v, int *tam){
    printf("Digite o COdigo do Produto que deseja EXCLUIR: ");
    int cod;
    scanf("%d", &cod);
    for (int i = 0 ; i < *tam; i ++){
        if (v[i].codP == cod){
            printf("\n-----------------------------------\n");
            printf("Codigo do Produto: %d", v[i].codP);			
            printf("\nNome do Produto: %s", v[i].nome);						
            printf("\nQuantidade do Produto: %d", v[i].qnt);
            printf("\nValor do Produto: R$ %.2f", v[i].valor);
            printf("\n-----------------------------------");
            printf("\n\n");	
            char opcao;
            printf("\n\nDeseja excluir? (S/N)\n");
			scanf("%s", &opcao);
            if((opcao == 'S')|| (opcao =='s')){
                v[i] = v[(*tam) -1];
                v= (Produtos*) realloc (v, ((*tam) -1) * sizeof(Produtos));
                (*tam) --;
                printf("Produto EXCLUIDO !!\n");
                break;
            }
            else
                printf("Operacao CANCELADA !!\n");
        }
        else
            printf("Produto nao encontrado\n");
    }
    return v;
}