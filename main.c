#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cliente.h"
#include "Produto.h"



int main(){
    
    Cliente *Primeiro;
    Produtos *Segundo;
    Venda *terceiro;
    int tam_cliente = 0;
    int tam_produto = 0;
    int tam_venda = 0;
    
    BoasVindas();
    char escolha;
    int opc=0;
    while(escolha !='s'){
        MenuPrincipal();
        scanf("%c", &escolha);
        fflush(stdin);

        switch(escolha){
            case '1':
                system("cls");
            	printf("\n");
                printf(" %c----------------------------------------------------------------------------%c\n",201,187);
	    		printf(" | ");printf("\t\t\t           CLIENTES        ");printf("\t\t\t      |\n");
	    		printf(" %c----------------------------------------------------------------------------%c\n",200,188);
                SubMenur();
                scanf("%d", &opc);
                system("cls");
            	getchar();
                if(opc == 1){
                    system("cls");
                    printf(" %c----------------------------------------------------------------------------%c\n",201,187);
                    printf(" | ");printf("\t\t\t          NOVO CADASTRO     ");printf("\t\t\t      |\n");
                    printf(" %c----------------------------------------------------------------------------%c\n",200,188);
                    Primeiro = insere_cliente(Primeiro, &tam_cliente, lerCLiente());
                break;
                }
                if(opc== 2){
                    system ("cls");
                    printf(" %c----------------------------------------------------------------------------%c\n",201,187);
                    printf(" | ");printf("\t\t\t     Pesquisar Cliente  ");printf("\t\t\t      |\n");
                    printf(" %c----------------------------------------------------------------------------%c\n",200,188);
                    pesquisa_cliente(Primeiro, &tam_cliente);
                    system("pause");
                break;
                }
                if(opc== 3){
                    system ("cls");
                    printf(" %c----------------------------------------------------------------------------%c\n",201,187);
                    printf(" | ");printf("\t\t\t     Clientes Cadastrados");printf("\t\t\t      |\n");
                    printf(" %c----------------------------------------------------------------------------%c\n",200,188);
                    listar_cliente(Primeiro, &tam_cliente);
                    system("pause");
                    break;
                }
                if(opc==4){
                    system ("cls");
                    printf(" %c----------------------------------------------------------------------------%c\n",201,187);
                    printf(" | ");printf("\t\t\t        EXCLUIR CLIENTE  ");printf("\t\t\t      |\n");
                    printf(" %c----------------------------------------------------------------------------%c\n",200,188);
                    printf("\n\n");
                    Primeiro = excluir_cliente(Primeiro, &tam_cliente);
                    system("pause");
                    break;
                }
                if(opc==5){
                    MenuPrincipal();
                }
                else
                    printf("Opcao invalida!!");
                    system("pause");
            break;
        case '2':
            system("cls");
            printf("\n");
            printf(" %c----------------------------------------------------------------------------%c\n",201,187);
            printf(" | ");printf("\t\t\t           PRODUTOS        ");printf("\t\t\t      |\n");
            printf(" %c----------------------------------------------------------------------------%c\n",200,188);
            printf("\n\n");
            SubMenur();
            scanf("%d", &opc);
            system("cls");
            getchar();
                if(opc == 1){
                    system("cls");
                    printf(" %c----------------------------------------------------------------------------%c\n",201,187);
                    printf(" | ");printf("\t\t\t          NOVO CADASTRO     ");printf("\t\t\t      |\n");
                    printf(" %c----------------------------------------------------------------------------%c\n",200,188);
                    Segundo = insere_produto(Segundo, &tam_produto, lerProduto());
                    break;
                }
                if(opc==2){
                    system("cls");
                    printf(" %c----------------------------------------------------------------------------%c\n",201,187);
                    printf(" | ");printf("\t\t\t    Pesquisar Produtos  ");printf("\t\t\t      |\n");
                    printf(" %c----------------------------------------------------------------------------%c\n",200,188);
                    pesquisa_produto(Segundo, &tam_produto);
                    system("pause");
                    break;
                }
                if(opc==3){
                    system("cls");
                    printf(" %c----------------------------------------------------------------------------%c\n",201,187);
                    printf(" | ");printf("\t\t\t     Produtos Cadastrados");printf("\t\t\t      |\n");
                    printf(" %c----------------------------------------------------------------------------%c\n",200,188);
                    listar_produto(Segundo, &tam_produto);
                    system("pause");
                break;
                }
                if(opc == 4){
                    system ("cls");
                    printf(" %c----------------------------------------------------------------------------%c\n",201,187);
                    printf(" | ");printf("\t\t\t        EXCLUIR PRODUTO  ");printf("\t\t\t      |\n");
                    printf(" %c----------------------------------------------------------------------------%c\n",200,188);
                    Segundo = excluir_produto(Segundo, &tam_produto);
                    system("pause");
                    break;
                }
                if(opc==5){
                    MenuPrincipal();
                    
                }
                else
                    printf("Opcao Invalida\n\n");
            break;
        case '3':
            system("cls");
            printf("\n");
            printf(" %c----------------------------------------------------------------------------%c\n",201,187);
            printf(" | ");printf("\t\t\t           VENDAS         ");printf("\t\t\t      |\n");
            printf(" %c----------------------------------------------------------------------------%c\n",200,188);
            printf("\n\n");
            SubMenur();
            scanf("%d", &opc);
            system("cls");
            getchar();
                
        }
    }   
    free(Primeiro);
    free(Segundo);
}
