#include <stdio.h>
#include <windows.h>
#include <stdlib.h> // Para strtol()
#include <string.h> // Para strlen()
#include <ctype.h>  // Para isspace()
#include <stdint.h>
#include <time.h>
#include<math.h>
#include <conio.h>

typedef struct Cliente
{
	int id;
	char nome[40];
	char cpf[15];
	char telefone[15];
} Cliente;

typedef struct Barber
{
	int id;
	char nome[40];
	char cpf[15];
	char telefone[15];
} Barber;

typedef struct Servico
{
	int codigo;
	char descricao[50];
	float preco;
	
} Servico;

typedef struct {
    int dia;
    int mes;
    int ano;
    int hora;
    int minuto;
    int segundo;
} DataHora;

typedef struct Atendimento
{
	int registro;
	int idCliente;
	char nomeCliente[40];
	int idBarber;
	char nomeBarber[40];
	int codigo;
	char descricao[50];
	float preco;
	float desconto;
	float preco_total;
	float pagamento_cartao;
	float pagamento_pix;
	float pagamento_dinheiro;
	int pagamento_fidelidade;
	float troco;
	struct tm data_hora_atendimento; // Armazena a data e hora
	float preco_final_sem_desconto;
	float preco_final_com_desconto;

} Atendimento;

typedef struct Agendamento
{
	int registro;
	int idCliente;
	char nomeCliente[40];
	int idBarber;
	char nomeBarber[40];
	struct tm data_hora_agendamento; // Armazena a data e hora
	int dia;
	int mes;
	int ano;
	int hora;
	int minuto;

} Agendamento;

typedef struct Fidelidade
{
	int idCliente;
	char nomeCliente[40];
	int servicosAcumulados;
	int bonusUsados;
	

} Fidelidade;

#include "funcoes_cliente_b.h"
#include "funcoes_barber.h"
#include "funcoes_servico.h"
#include "funcoes_fidelidade.h"
#include "funcoes_atendimento.h"
#include "funcoes_agendamento.h"
#include "funcoes_admin_b.h"
#include "funcoes_estatistica.h"

int main()
{

	Servico cadastroServico[1000];
	Cliente cadastroCliente[1000];
	Barber cadastroBarber[1000];
	Agendamento registroAgendamento[1000];
	Fidelidade registroFidelidade[1000];
	Atendimento recibo[1000];
	Atendimento aux[1000];
	
	int menu = -1;

	if (!GetConsoleWindow()) {
		AllocConsole();
	}
	
	do{
		MenuAdmin();
		menu = ObtemInteiroValidoCliente(menu);
		switch(menu)
		{
			case 1:
				ListaCliente(cadastroCliente);
			break;
			case 2:
				BuscaCliente(cadastroCliente);
			break;
			case 3:
				CadastraCliente(cadastroCliente);
			break;
			case 4:
				AtualizaCliente(cadastroCliente);
			break;
			case 5:
				RemoveCliente(cadastroCliente);
			break;
			case 6:
				ApagaSistemaCliente(cadastroCliente);
			break;
			case 7:
				ListaServico(cadastroServico);
			break;
			case 8:
				BuscaServico(cadastroServico);
			break;
			case 9:
				CadastraServico(cadastroServico);
			break;
			case 10:
				AtualizaServico(cadastroServico);
			break;
			case 11:
				RemoveServico(cadastroServico);
			break;
			case 12:
				ApagaSistemaServico(cadastroServico);
			break;
			case 13:
				ListaFidelidade(registroFidelidade);
			break;
			case 14:
				BuscaFidelidade(registroFidelidade);
			break;	
			case 15:
				ListaAtendimento(recibo);
			break;
			case 16:
				BuscaAtendimento(recibo);
			break;
			case 17:
				RegistraAtendimento(cadastroCliente,cadastroBarber,cadastroServico,aux,recibo,registroFidelidade);
			break;
			case 18:
				RemoveAtendimento(recibo);
			break;
			case 19:
				ListaBarber(cadastroBarber);	
			break;
			case 20:
				BuscaBarber(cadastroBarber);
			break;
			case 21:
				CadastraBarber(cadastroBarber);
			break;
			case 22:
				AtualizaBarber(cadastroBarber);
			break;
			case 23:
				RemoveBarber(cadastroBarber);
			break;
			case 24:
				ApagaSistemaBarber(cadastroBarber);
			break;
			case 25:
				ListaAgendamento(registroAgendamento);
			break;
			case 26:
				BuscaAgendamento(registroAgendamento);
			break;
			case 27:
				RegistraAgendamento(cadastroCliente,cadastroBarber, registroAgendamento);
			break;
			case 28:
				RemoveAgendamento(registroAgendamento);
			break;
			case 29:
				CalculaBalancoGeralEstatistica(recibo);
			break;
			case 30:
				CalculaBalancoGeralPorDataEstatistica(recibo);
			break;
			case 31:
				CalculaBalancoEspecificoEstatistica(recibo);
			break;
			case 32:
				CalculaBalancoEspecificoPessoaEstatistica(recibo);
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