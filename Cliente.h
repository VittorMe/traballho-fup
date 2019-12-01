//#ifdef CLIENTE_H
#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct {
    char CPF[20];
	char nome[40];
	int idade;
	char endereco[40];
	char telefone[40];

}Cliente;

Cliente lerCLiente();

Cliente *insere_cliente(Cliente *v, int *tam, Cliente novo);

void pesquisa_cliente(Cliente *v, int *tam);

void listar_cliente(Cliente *v, int *tam);

Cliente *excluir_cliente(Cliente *v, int *tam);

void BoasVindas();

void SubMenur();

void MenuPrincipal();
#endif