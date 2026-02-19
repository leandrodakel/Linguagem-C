#include <stdio.h>
#include <windows.h>
#include <stdlib.h> // Para strtol()
#include <string.h> // Para strlen()
#include <ctype.h>  // Para isspace()
#include <stdint.h>
#include <time.h>

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
	struct tm data_hora_pedido;
	float preco_final_sem_desconto;
	float preco_final_com_desconto;
	float lucro;
} Pedido;

#include "funcoes_estoque.h"
//#include "funcoes_cliente.h"

int main()
{
	Estoque deposito[1000];
	Cliente cadastro[1000];
	Pedido recibo[1000];
	Pedido aux[1000];
	
	int menu = -1;
			
	do{
		MenuEstoque();
		scanf("%d",&menu);
		switch(menu)
		{
			case 1:
				ListaProduto(deposito);
			break;
			case 2:
				FiltraOrdenaProduto(deposito);
			break;
			case 3:
				BuscaProduto(deposito);
			break;
			case 4:
				CalculaBalancoProduto(deposito);
			break;
			case 5:
				CadastraProduto(deposito);
			break;
			case 6:
				CadastraCategoria(deposito);
			break;
			case 7:
				AtualizaProduto(deposito);
			break;
			case 8:
				ReordenaCodigoProduto(deposito);
			break;
			case 9:
				RemoveProduto(deposito);
			break;
			case 10:
				RemoveCategoria(deposito);
			break;
			case 11:
				ApagaDadosSistemaProduto(deposito);
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