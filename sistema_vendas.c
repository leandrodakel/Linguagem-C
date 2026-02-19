#include <stdio.h>
#include <windows.h>
#include <stdlib.h> // Para strtol()
#include <string.h> // Para strlen()
#include <ctype.h>  // Para isspace()
#include <stdint.h>
#include <time.h>
#include<math.h>



typedef struct Estoque
{
	int codigo;
	char descricao[50];
	int numero;
	char categoria[25];
	int quantidade;
	char unidade[3];
	float preco;
	float custo;
} Estoque;

typedef struct Cliente
{
	int id;
	char nome[40];
	char cpf[15];
	char telefone[15];
} Cliente;

typedef struct {
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
    int segundo;
} DataHora;

typedef struct Pedido
{
	int registro;
	int id;
	char nome[40];
	int codigo;
	char descricao[50];
	int numero;
	char categoria[25];
	int quantidade;
	char unidade[3];
	float preco;
	float desconto;
	float preco_total;
	float pagamento_cartao;
	float pagamento_pix;
	float pagamento_dinheiro;
	float troco;
	struct tm data_hora_pedido; // Armazena a data e hora
	float preco_final_sem_desconto;
	float preco_final_com_desconto;
	float lucro;
} Pedido;

#include "funcoes_estoque.h"
#include "funcoes_cliente.h"
#include "funcoes_varejo.h"

int main()
{
	Estoque deposito[1000];
	Cliente cadastro[1000];
	Pedido recibo[1000];
	Pedido aux[1000];
	//Compra fatura[1000];
	
	int menu = -1;
	
	do{
		MenuCliente();
		scanf("%d",&menu);
		switch(menu)
		{
			case 1:
				ListaCliente(cadastro);
			break;
			case 2:
				FiltraOrdenaCliente(cadastro);
			break;
			case 3:
				BuscaCliente(cadastro);
			break;
			case 4:
				CadastraCliente(cadastro);
			break;
			case 5:
				AtualizaCliente(cadastro);
			break;
			case 6:
				RemoveCliente(cadastro);
			break;
			case 7:
				ApagaSistemaCliente(cadastro);
			break;
			case 8:
				ListaProduto(deposito);
			break;
			case 9:
				FiltraOrdenaProduto(deposito);
			break;
			case 10:
				BuscaProduto(deposito);
			break;
			case 11:
				ListaVarejo(recibo);
			break;
			case 12:
				BuscaPedido(recibo);
			break;
			case 13:
				RegistraVarejo(cadastro,deposito,aux,recibo);
			break;
			case 14:
				RemovePedido(recibo);
			break;
			case 15:
				ApagaDadosSistemaVarejo(recibo);
			break;
			case 0:
				system("cls");
				printf("\n\nSISTEMA FINALIZADO\n\n");
			break;
			default:
				printf("\n\nDigite uma opcao valida\n\n");
		}
	}while(menu != 0);	
	return (0);
}