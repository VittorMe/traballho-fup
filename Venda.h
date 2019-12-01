//#ifdef VENDA_H
#ifndef VENDA_H


typedef struct {
    int codV;
    char CodC[50];
    int CodP;
    int qtd;
}Venda;


Venda lerVenda(Cliente *c, int *tam_c, Produtos *p, int *tam_p);

Venda *insere_venda(Venda *v, int *tam, Venda novo);

void pesquisa_venda(Venda * v, int *tam);

void listar_venda(Venda *v, int *tam);

Venda *excluir_venda(Venda *v, int *tam);
#endif