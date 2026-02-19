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
#include "funcoes_admin.h"



int main()
{
	Estoque deposito[1000];
	Cliente cadastro[1000];
	Pedido recibo[1000];
	Pedido aux[1000];
	//Compra fatura[1000];
	
	int menu = -1;
	
	do{
		MenuAdmin();
		//scanf("%d",&menu);
		menu = ObtemInteiroValidoEstoque(menu);
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
				RemoveCliente(cadastro);
			break;
			case 5:
				ApagaSistemaCliente(cadastro);
			break;
			case 6:
				ListaProduto(deposito);
			break;
			case 7:
				FiltraOrdenaProduto(deposito);
			break;
			case 8:
				ListaCategoria(deposito);
			break;
			case 9:
				BuscaProduto(deposito);
			break;
			case 10:
				RemoveProduto(deposito);
			break;
			case 11:
				RemoveCategoria(deposito);
			break;
			case 12:
				ReordenaCodigoProduto(deposito);
			break;
			case 13:
				ApagaDadosSistemaCategoria(deposito);
			break;
			case 14:
				ApagaDadosSistemaProduto(deposito);
			break;
			case 15:
				ListaVarejo(recibo);
			break;
			case 16:
				BuscaPedido(recibo);
			break;
			case 17:
				RegistraVarejo(cadastro,deposito,aux,recibo);
			break;
			case 18:
				RemovePedido(recibo);
			break;
			case 19:
				ApagaDadosSistemaVarejo(recibo);
			break;
			case 20:
				CadastraCliente(cadastro);
			break;
			case 21:
				CadastraProduto(deposito);
			break;
			case 22:
				CadastraCategoria(deposito);
			break;
			case 23:
				AtualizaCliente(cadastro);
			break;
			case 24:
				AtualizaProduto(deposito);
			break;
			case 25:
				CalculaBalancoProduto(deposito);
			break;
			case 26:
				CalculaBalancoVarejo(recibo,deposito);
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