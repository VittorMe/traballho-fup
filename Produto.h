//#ifdef PRODUTO_H
#ifndef PRODUTO_H
#define PRODUTO_H


typedef struct {
    int codP;
	char nome[40];
	int qnt;
	float valor;
}Produtos;


Produtos lerProduto();

Produtos *insere_produto(Produtos *v, int *tam, Produtos novo);

void pesquisa_produto(Produtos *v, int *tam);

void listar_produto(Produtos *p, int *tam);

void salvar_produto(Produtos * v, int * tam);

Produtos *excluir_produto(Produtos *v, int *tam);
#endif