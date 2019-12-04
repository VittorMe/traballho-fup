#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cliente.h"

Cliente lerCLiente(){
    Cliente primeiro;

    printf("\nCPF do Cliente: ");
	scanf("%[^\n]", primeiro.CPF);
	printf("\n");

    printf("Nome do Cliente: ");
	scanf("%*[^\n]");scanf("%*c");
	scanf("%[^\n]",primeiro.nome);
	printf("\n");

    printf("Idade do Cliente: ");
	scanf("%d", &primeiro.idade);
	printf("\n");

    printf("Endereco do CLiente: ");
	scanf("%*[^\n]");scanf("%*c");
	scanf("%[^\n]",primeiro.endereco);
	printf("\n");

    printf("Telefone do CLiente: ");
	scanf("%*[^\n]");scanf("%*c");
	scanf("%[^\n]",primeiro.telefone);
	printf("\n");

    return primeiro;
}

Cliente *insere_cliente(Cliente *v, int *tam, Cliente novo){
    if (v != 0){
        if(*tam == 0){
            v=(Cliente*) malloc ( (*tam + 1)* sizeof(Cliente) );
            if (v == NULL){
				printf("ERRO: nao foi possivel alocar memoria ");
			}
        }
        else{
            v=(Cliente*) realloc (v, (*tam +1) * sizeof(Cliente));
            if (v == NULL){
				printf("ERRO: nao foi possivel alocar memoria ");
			}
        }
    } 
    v[*tam]= novo;
    (*tam)++;
    return v;
}

void pesquisa_cliente(Cliente *v, int *tam){
    if (*tam ==0)
        printf("Nenhum Cliente Cadastrado\n");
    else{
        char busca[20];
        printf("Digite o CPF do CLiente: ");
        scanf("%[^\n]", busca);
        int achou = -1;
        int a;
        for (int i = 0 ; i < *tam; i ++){
            if (strcmp(v[i].CPF , busca) == 0){
                achou = 1;
                a= i;
                break;
            }
        }
        if (achou == -1){
            printf ("CLiente nao encontrado !!\n");
        }else{
            printf("\n-----------------------------------\n");
            printf("CPF do Cliente: %s", v[a].CPF);			
            printf("\nNome do Cliente: %s", v[a].nome);						
            printf("\nIdade do CLiente: %d", v[a].idade);
            printf("\nEndereco do Cliente: %s", v[a].endereco);
            printf("\nTelefone do Cliente: %s\n", v[a].telefone);
            printf("-----------------------------------");
            printf("\n\n");	
        }
    }
}

void listar_cliente(Cliente *v, int *tam){
    if (*tam == 0){
        printf("Nao Possui CLiente Cadastrado\n");
    }
    for (int i = 0 ; i < *tam; i ++){
        printf("\n-----------------------------------\n");
        printf("CPF do Cliente: %s", v[i].CPF);			
        printf("\nNome do Cliente: %s", v[i].nome);						
        printf("\nIdade do CLiente: %d", v[i].idade);
        printf("\nEndereco do Cliente: %s", v[i].endereco);
        printf("\nTelefone do Cliente: %s\n", v[i].telefone);
        printf("-----------------------------------");
        printf("\n\n");
    }
}

void salvar_cliente(Cliente *v, int *tam){
	FILE *arq = fopen(".\\Clientes.txt", "w+");
    if (arq == NULL){
        printf("Problema na abertura do arquivo !!");
    }
	
	for(int i =0 ; i < *tam; i++){
		fprintf(arq, "%s", v[i].CPF);
		fprintf(arq, " %s", v[i].nome);
		fprintf(arq, " %d", v[i].idade);
		fprintf(arq, " %s", v[i].endereco);
		fprintf(arq, " %s\n", v[i].telefone);
		
	}
	fclose(arq);
}
void carrega_arqCliente(Cliente *v, int *tam){
    FILE *arq = fopen("Clientes.txt", "r");
    if (arq == NULL){
        printf("ERRO: nao foi possivel abrir arquivo !!");
        return ;
    }
    for (int i = 0 ; i < *tam; i ++){
        fscanf(arq,"%s %s %d %s %s\n", v[i].CPF, v[i].nome, &v[i].idade, v[i].endereco, v[i].telefone);
    }
    fclose(arq);
}

Cliente *excluir_cliente(Cliente *v, int *tam){
    printf("Digite o CPF do Cliente que deseja EXCLUIR: ");
    char cod[20];
    scanf("%[^\n]", cod);
    for (int i = 0 ; i < *tam; i ++){
        if (strcmp(v[i].CPF , cod)== 0){
            printf("\n-----------------------------------\n");
            printf("CPF do Cliente: %s", v[i].CPF);			
            printf("\nNome do Cliente: %s", v[i].nome);						
            printf("\nIdade do CLiente: %d", v[i].idade);
            printf("\nEndereco do Cliente: %s", v[i].endereco);
            printf("\nTelefone do Cliente: %s\n", v[i].telefone);
            printf("-----------------------------------");
            printf("\n\n");	
            char opcao;
            printf("\n\nDeseja excluir? (S/N)\n");
			scanf("%s", &opcao);
            if((opcao == 'S')|| (opcao =='s')){
                v[i] = v[(*tam) -1];
                v= (Cliente*) realloc (v, ((*tam) -1) * sizeof(Cliente));
                (*tam) --;
                printf("Cliente EXCLUIDO !!\n");
                break;
            }
            else
                printf("Operacao CANCELADA !!\n");
        }
        else
            printf("CLiente nao encontrado\n");
    }
    return v;
}

void BoasVindas(){
    system("cls");
    printf("\n\n");
	printf(" %c----------------------------------------------------------------------------%c\n",201,187);
	printf(" | ");printf("\t\t\t                          ");printf("\t\t\t      |\n");
	printf(" | ");printf("\t\t\t         BEM VINDO        ");printf("\t\t\t      |\n");
	printf(" | ");printf("\t\t\t                          ");printf("\t\t\t      |\n");
	printf(" %c----------------------------------------------------------------------------%c\n",200,188);
    system("pause");
}
void SubMenur(){
    printf("\n");
    printf("1 - Cadastrar \n\n");
    printf("2 - Pesquisar \n\n");
    printf("3 - Listar \n\n");
    printf("4 - Excluir \n\n");
    printf("5 - Voltar ao menu principal\n\n");
    printf("\n");
    printf("Opcao: ");
}
void MenuPrincipal(){
    system("cls");
    printf(" %c----------------------------------------------------------------------------%c\n",201,187);
    printf(" | ");printf("\t\t\t     MERCADINHO DO ATILIO      ");printf("\t\t\t      |\n");
    printf(" %c----------------------------------------------------------------------------%c\n",200,188);

    printf("\n\n MENU\n\n");
    printf("|-----------------------------------|\n");
    printf("       1 - Clientes\n");
    printf("|-----------------------------------|\n");
    printf("       2 - Produtos\n");
    printf("|-----------------------------------|\n");
    printf("       3 - Vendas\n");
    printf("|-----------------------------------|\n");
    printf("       4 - Sair\n");
    printf("|-----------------------------------|\n");
    printf("\nOpcao: ");
        
}
