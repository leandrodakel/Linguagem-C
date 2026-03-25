
double arredonda(double v);
int anoBissexto(int ano);
int dataValida(int dia, int mes, int ano);
int mesValida(int mes, int ano);
void LimpaBufferAtendimento();
int ObtemInteiroValidoAtendimento();
float ObtemFloatValidoAtendimento();
void LimpaStringAtendimento(char *str);
void ConverteMaiusculaAtendimento(char *str);

void MenuBuscaAtendimento();
void ImprimeCabecalhoItensInicio();
void ImprimeCabecalhoItens();

int LeArquivoAtendimento(Atendimento * pnt_recibo);
void ImprimeAtendimento(Atendimento * pnt_recibo, int tam);
void RegistraAtendimento(Cliente * pnt_cadastroCliente, Barber * pnt_cadastroBarber, Servico * pnt_cadastroServico, Atendimento * pnt_recibo, Atendimento * pnt_aux, Fidelidade * pnt_registroFidelidade);
void BuscaAtendimento(Atendimento * pnt_recibo);
void ListaAtendimento(Atendimento * pnt_recibo);
void RemoveAtendimento(Atendimento * pnt_recibo);
void CalculaBalancoAtendimento(Atendimento * pnt_recibo);
void ApagaDadosSistemaAtendimento(Atendimento  * pnt_recibo);
int ValidaFidelidade(Fidelidade *pnt_registroFidelidade, int tam, int id_cliente);



double arredonda(double v)
{
    return floor(v * 100.0 + 0.5) / 100.0;
}

int anoBissexto(int ano)
{
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
        return 1;
    return 0;
}

int dataValida(int dia, int mes, int ano)
{
    if (ano <= 0)
        return 0;

    if (mes < 1 || mes > 12)
        return 0;

    if (dia < 1)
        return 0;

    int diasNoMes;

    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            diasNoMes = 31;
            break;

        case 4: case 6: case 9: case 11:
            diasNoMes = 30;
            break;

        case 2:
            if (anoBissexto(ano))
                diasNoMes = 29;
            else
                diasNoMes = 28;
            break;
    }

    if (dia > diasNoMes)
        return 0;

    return 1;
}

int mesValida(int mes, int ano)
{
    if (ano <= 0)
        return 0;

    if (mes < 1 || mes > 12)
        return 0;

    return 1;
}

void LimpaBufferAtendimento()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // apenas descarta os caracteres restantes
    }
}

int ObtemInteiroValidoAtendimento(int n)
{
    //int n;
    int resultado;

    while (1) {
        resultado = scanf("%d", &n);

        if (resultado == 1) {
            LimpaBufferAtendimento(); // limpa o '\n' e o que sobrou
            return n;
        } else {
            printf("\nEntrada inválida!\a\n\n");
			printf("Tente novamente: ");
            LimpaBufferAtendimento(); // descarta entrada inválida
        }
    }
}

float ObtemFloatValidoAtendimento()
{
    float valor;
    int status_leitura;
    char caractere;

    while (1) { // Loop infinito até uma entrada válida ser fornecida
        status_leitura = scanf("%f", &valor);

        if (status_leitura == 1) {
            // Limpa o buffer do teclado para remover o caractere de nova linha (\n)
            // e quaisquer caracteres extras que possam ter sido digitados
            while ((caractere = getchar()) != '\n' && caractere != EOF);
            return valor; // Retorna o valor válido
        } else {
            // Se a leitura falhou, limpa o buffer para evitar loop infinito
            printf("\n\aEntrada invalida. Por favor, digite apenas numeros: ");
            while ((caractere = getchar()) != '\n' && caractere != EOF);
        }
    }
}

void LimpaStringAtendimento(char *str)
{
    char *end;

    // Remover espaços à esquerda
    while(isspace((unsigned char)*str)) str++;

    // Se a string estiver vazia, retornar
    if(*str == 0) return;

    // Remover espaços à direita
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;

    // Colocar o caracter nulo após o último caractere válido
    *(end+1) = 0;
}

void ConverteMaiusculaAtendimento(char *str)
{
    while (*str)
	{
        *str = toupper((unsigned char)*str);
        str++;
    }
}


void MenuBuscaAtendimento()
{
	printf("\n");
	printf("╔═════════════════════════════════════════════════════════╗\n");
	printf("║                     BUSCAR ATENDIMENTO                  ║\n");
	printf("╠═════════════════════════════════════════════════════════╣\n");
	printf("║                                                         ║\n");
	printf("║      Buscar por REGISTRO de ATENDIMENTO -------- 1      ║\n");
	printf("║                                                         ║\n");
	printf("║      Buscar por ID de Cliente e DATA ----------- 2      ║\n");
	printf("║      Buscar por NOME de Cliente e DATA --------- 3      ║\n");
	printf("║                                                         ║\n");
	printf("║      Flitrar por ID de Cliente ----------------- 4      ║\n");
	printf("║      Filtrar por NOME de Cliente --------------- 5      ║\n");
	printf("║      Filtrar por DATA do Pedido ---------------- 6      ║\n");
	printf("║                                                         ║\n");
	printf("║      Voltar ao MENU INICIAL -------------------- 0      ║\n");
	printf("║                                                         ║\n");
	printf("╚═════════════════════════════════════════════════════════╝\n\n");
}

void ImprimeCabecalhoItensInicio()
{
    printf("╠══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║ ID  │              CLIENTE              │ ID  │           BARBER           │ COD │         DESCRICAO        │  VALOR UNIT. │   VALOR TOTAL   ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
}

void ImprimeCabecalhoItens()
{
	printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║ ID  │              CLIENTE              │ ID  │           BARBER           │ COD │         DESCRICAO        │  VALOR UNIT. │   VALOR TOTAL   ║\n");
    printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
}


int LeArquivoAtendimento(Atendimento * pnt_recibo)
{
	FILE *pont_atendimento;
	int f = 0;
	pont_atendimento = fopen("atendimento.txt", "r");

    if(pont_atendimento == NULL)
    {
        printf("Erro ao abrir atendimento.txt\n");
        return 0;
    }
	
	while(fscanf(pont_atendimento,"%d\n%d\n%[^\n]\n%d\n%[^\n]\n%d\n%[^\n]\n%f\n%f\n%f\n%f\n%f\n%f\n%d\n%f\n%d\n%d\n%d\n%d\n%d\n%d\n%f\n%f\n",
									 &pnt_recibo[f].registro,
									 &pnt_recibo[f].idCliente,
									 pnt_recibo[f].nomeCliente,
									 &pnt_recibo[f].idBarber,
									 pnt_recibo[f].nomeBarber,
									 &pnt_recibo[f].codigo,
									 pnt_recibo[f].descricao,
									 &pnt_recibo[f].preco,
									 &pnt_recibo[f].desconto,
									 &pnt_recibo[f].preco_total,
									 &pnt_recibo[f].pagamento_cartao,
									 &pnt_recibo[f].pagamento_pix,
									 &pnt_recibo[f].pagamento_dinheiro,
									 &pnt_recibo[f].pagamento_fidelidade,
									 &pnt_recibo[f].troco,
									 &pnt_recibo[f].data_hora_atendimento.tm_mday,
									 &pnt_recibo[f].data_hora_atendimento.tm_mon,
									 &pnt_recibo[f].data_hora_atendimento.tm_year,
									 &pnt_recibo[f].data_hora_atendimento.tm_hour,
									 &pnt_recibo[f].data_hora_atendimento.tm_min,
									 &pnt_recibo[f].data_hora_atendimento.tm_sec,
									 &pnt_recibo[f].preco_final_sem_desconto,
									 &pnt_recibo[f].preco_final_com_desconto) != EOF)
	{
		f++;
	}
	
	fclose(pont_atendimento);
	return f;
}

void ImprimeAtendimento(Atendimento * pnt_recibo, int tam)
{
	int i = 0;
    float soma_desconto_total_item = 0.0f;
	float soma_preco_final_sem_desconto = 0.0f;
    float soma_preco_total_item = 0.0f;
	
	ImprimeCabecalhoItensInicio();
    for (i = 0; i < tam; i++)
    {
		int fim_atendimento;
        Atendimento atual = pnt_recibo[i];
        Atendimento anterior = (i > 0) ? pnt_recibo[i - 1] : atual;
        Atendimento proximo = (i < tam - 1) ? pnt_recibo[i + 1] : atual;

        // Acumulações de atendimento
        soma_preco_total_item += atual.preco_total;
        soma_desconto_total_item += atual.desconto;
		soma_preco_final_sem_desconto = soma_preco_total_item + soma_desconto_total_item;

        // --- Impressão dos itens ---
        if (i == 0)
        {
            //Primeiro atendimento → imprime o NOME e o ID do cliente e do barber                                                                                                                                         ║\n");
			
			printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
            printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%35s\x1b[0m│%5d│%28s│%5d│%26s│%14.2f│%17.2f║\n",
                      atual.idCliente, atual.nomeCliente,
					  atual.idBarber, atual.nomeBarber, 
					  atual.codigo, atual.descricao,
                      atual.preco, atual.preco_total);
        }
		
		
		if (atual.registro > anterior.registro)
        {
            // Novo atendimento → imprime o cabeçalho do item
			printf("\n");
			ImprimeCabecalhoItens();
			printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
            printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%35s\x1b[0m│%5d│%28s│%5d│%26s│%14.2f│%17.2f║\n",
                      atual.idCliente, atual.nomeCliente,
					  atual.idBarber, atual.nomeBarber, 
					  atual.codigo, atual.descricao,
                      atual.preco, atual.preco_total);
        }
        
		if(i > 0 && atual.registro == anterior.registro && anterior.registro != 0)
        {
            // Mesmo atendimento → imprime sem cabeçalho
			printf("║     │                                   │     │                            │%5d│%26s│%14.2f│%17.2f║\n",
                      atual.codigo, atual.descricao,
                      atual.preco, atual.preco_total);
        }

        // --- Detecta fim do atendimento ---
        fim_atendimento = (i == tam - 1) || (atual.registro < proximo.registro);

        if (fim_atendimento)
        {
            printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
            printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
            printf("║  REGISTRO  │    DATA    │    HORA    │ CARTAO TEF │     PIX    │  DINHEIRO  │ FIDEL │ VALOR TOTAL │  DESCONTO  │   TROCO   │   VALOR FINAL   ║\n");
            printf("║────────────│────────────│────────────│────────────│────────────│────────────│───────│─────────────│────────────├───────────│─────────────────╢\n");

           printf("║      %06d│  %02d/%02d/%04d│    %02d:%02d:%02d│  %10.2f│  %10.2f│  %10.2f│      %1d│%13.2f│%12.2f│%11.2f│\x1b[36m%17.2f\x1b[0m║\n",
                   atual.registro,
                   atual.data_hora_atendimento.tm_mday,
                   atual.data_hora_atendimento.tm_mon,
                   atual.data_hora_atendimento.tm_year,
                   atual.data_hora_atendimento.tm_hour,
                   atual.data_hora_atendimento.tm_min,
                   atual.data_hora_atendimento.tm_sec,
                   atual.pagamento_cartao,
                   atual.pagamento_pix,
                   atual.pagamento_dinheiro,
				   atual.pagamento_fidelidade,
				   atual.preco_final_sem_desconto,
                   soma_desconto_total_item,
                   atual.troco,
				   atual.preco_final_com_desconto);
			printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");	   
			printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
            // Zera acumuladores para o próximo atendimento
            soma_desconto_total_item = 0.0f;
            soma_preco_total_item = 0.0f;

            // Pausa a cada 10 registros
            if (i < tam - 1 && atual.registro % 10 == 0)
            {
           		
				printf("\nAperte qualquer tecla para seguir a listagem de atendimentos... \n\n");
                system("pause > nul");
            }
        }
    }
	
	printf("\nLISTAGEM CONCLUIDA\n");
    printf("\nAperte qualquer tecla para voltar ao MENU... \n");
    system("pause > nul");
	system("cls");
}

void RegistraAtendimento(Cliente * pnt_cadastroCliente, Barber * pnt_cadastroBarber, Servico * pnt_cadastroServico, Atendimento * pnt_recibo, Atendimento * pnt_aux, Fidelidade * pnt_registroFidelidade)
{
	
	FILE *pont_cliente;
	FILE *pont_barber;
	FILE *pont_atendimento;
	FILE *pont_servico;
	FILE *pont_fidelidade;
	
	DataHora data_hora_atendimento;
	
	int indice = -1;
	
	int servicos_exibidos = 0;
	int clientes_exibidos = 0;
	int barbers_exibidos = 0;
	
	int id_cliente = 0;
	int id_barber = 0;
	
	char nome_cliente[40];
	char nome_barber[40];
	
	int cod_servico = 0;
	char descricao_servico[50];
	float preco_servico = 0.0;

	float preco_unitario = 0.0;
	float preco_total_item = 0.0;
	
	char forma_pagamento[10];
	float valor_desconto = 0.0;
	int registro_atendimento = 0;
	float cartao_pagamento = 0.0;
	float pix_pagamento = 0.0;
	float dinheiro_pagamento = 0.0;
	int fidelidade_pagamento = 0;
	float troco_pago = 0.0;
	
	float soma_preco_total_item = 0.0;
	float soma_desconto_total_item = 0.0;
	float soma_preco_final_sem_desconto = 0.0;
	int pagamento_validado = 0;
	int soma_pagamento = 0;
	long long real = 0;
	long long centavos = 0;
	long long cartao_cent = 0;
	long long pix_cent = 0;
	long long dinheiro_cent = 0;
	long long soma_pagamento_cent = 0;
	float total_pago = 0.0;
	float soma_custo = 0.0;
	float lucro_total = 0.0;
	
	int busca_servico = 0;
	int cliente_encontrado = 0;
	int barber_encontrado = 0;
	int servico_encontrado = 0;
	int nova_busca_cliente = 0;
	int nova_busca_barber = 0;
	int nova_busca_servico = 0;

	int id_cliente_fidelidade = 0;
	int fidelidade_usada = 0;
	int fidelidade_saldo = 0;
	int servicos_prestados = 0;
	int bonus_usados = 0;
	int fidelidade_validada =0;
	int tam_fidelidade;
	int saldo;

	
	int id = 0;
	int a = 0;
	int b = 0;
	int y = 0;
	int e = 0; 
	int p = 0;
	int r = 0;
	int w = 0;
	int f = 0;
	int q = 0;
	int j = 0;
	int t = 0;
	int s = 0;
	
	int op = 0;
	
	pont_cliente = fopen("cliente.txt","r");	
	
	if(pont_cliente == NULL)
	{
		printf("Erro ao abrir cliente.txt\n");
		return;
	}
	
	while(fscanf(pont_cliente,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n",
								&pnt_cadastroCliente[y].id,
								pnt_cadastroCliente[y].nome,
								pnt_cadastroCliente[y].cpf,
								pnt_cadastroCliente[y].telefone) != EOF)
	{
		y++;
	}
		
	fclose(pont_cliente);
	
	pont_barber = fopen("barber.txt","r");
	
	if(pont_barber == NULL)
	{
		printf("Erro ao abrir barber.txt\n");
		return;
	}
	
	while(fscanf(pont_barber,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n",
								&pnt_cadastroBarber[b].id,
								pnt_cadastroBarber[b].nome,
								pnt_cadastroBarber[b].cpf,
								pnt_cadastroBarber[b].telefone) != EOF)
	{
		b++;
	}
		
	fclose(pont_barber);
	


		system("cls");
		
		t = 0;
		cliente_encontrado = 0;
		
		printf("\nREGISTRO DE ATENDIMENTOS\n");
		printf("-------------------\n\n");
		
		printf("Informe o NOME do cliente: ");
		scanf(" %[^\n]",nome_cliente);
		LimpaStringAtendimento(nome_cliente);
		ConverteMaiusculaAtendimento(nome_cliente);
		
		if (pont_cliente == NULL)
		{
			strcpy(nome_cliente, "CLIENTE NAO IDENTIFICADO");
		}
		
		for(int i = 0; i < y; i++)
		{	
			if(strstr(pnt_cadastroCliente[i].nome, nome_cliente) != NULL)
			{
				printf("\n");
				printf("╔══════════════════════════════════════════════════════════════════╗\n");
				printf("║                         **DADOS DO CLIENTE**                     ║\n");
				printf("╠══════════════════════════════════════════════════════════════════╣\n");
				printf("║ COD │          NOME          │       CPF       │     TELEFONE    ║\n");
				printf("╟──────────────────────────────────────────────────────────────────╢\n");
				printf("╟──────────────────────────────────────────────────────────────────╢\n");
				t = 1;
				break;
			}
		}
		
		for(int i = 0; i < y; i++)
		{	
			if(strstr(pnt_cadastroCliente[i].nome, nome_cliente) != NULL)
			{
				//if(i % 2 == 0)
				if(clientes_exibidos % 2 == 0)
				{
					printf("║\033[32m%5d\033[0m│\033[32m%24s\033[0m│\033[32m%17s\033[0m│\033[32m%17s\033[0m║\n",
								pnt_cadastroCliente[i].id,
								pnt_cadastroCliente[i].nome,
								pnt_cadastroCliente[i].cpf,
								pnt_cadastroCliente[i].telefone);
					printf("╟──────────────────────────────────────────────────────────────────╢\n");
					clientes_exibidos++;
				}
				else
				{
					printf("║%5d│%24s│%17s│%17s║\n",
								pnt_cadastroCliente[i].id,
								pnt_cadastroCliente[i].nome,
								pnt_cadastroCliente[i].cpf,
								pnt_cadastroCliente[i].telefone);
					printf("╟──────────────────────────────────────────────────────────────────╢\n");
					clientes_exibidos++;
				}
						
				if(clientes_exibidos % 10 == 0 && clientes_exibidos != 0)
				{
					printf("╚══════════════════════════════════════════════════════════════════╝\n");
					printf("\nAperte qualquer tecla para continuar a lista de clientes... \n\n");
					system("pause > nul");
					printf("╔══════════════════════════════════════════════════════════════════╗\n");
					printf("║ ID  │          NOME          │       CPF       │     TELEFONE    ║\n");
					printf("╟──────────────────────────────────────────────────────────────────╢\n");
					printf("╟──────────────────────────────────────────────────────────────────╢\n");
					clientes_exibidos = 0;
				}
			}
		}
		
		if(t == 1)
		{		
			printf("╚══════════════════════════════════════════════════════════════════╝\n\n");
		}
		clientes_exibidos = 0;
		
		if (!t)
		{
			printf("\n██████████████████████████████\n\a");
			printf("█                            █\n");
			printf("█   CLIENTE NAO ENCONTRADO!  █\n");
			printf("█                            █\n");
			printf("██████████████████████████████\n\n");				
		}

	do{
			
		printf("Informe o ID do cliente: ");
		id_cliente = ObtemInteiroValidoAtendimento(id_cliente);
			
		for(int i = 0; i < y; i++)
		{	
			if(pnt_cadastroCliente[i].id == id_cliente)
			{
				system("cls");
				printf("\n");
				printf("╔══════════════════════════════════════════════════════════════════╗\n");
				printf("║                        **DADOS DO CLIENTE**                      ║\n");
				printf("╠══════════════════════════════════════════════════════════════════╣\n");
				printf("║ COD │          NOME          │       CPF       │     TELEFONE    ║\n");
				printf("╟──────────────────────────────────────────────────────────────────╢\n");
				printf("║%5d│\x1b[32m%24s\x1b[0m│%17s│%17s║\n",
						 pnt_cadastroCliente[i].id,
						 pnt_cadastroCliente[i].nome,
						 pnt_cadastroCliente[i].cpf,
						 pnt_cadastroCliente[i].telefone);
				printf("╚══════════════════════════════════════════════════════════════════╝\n");
					
				printf("\nConfirmar cliente - 1\n");
				printf("Continuar busca - 2\n"); 
				printf("CLIENTE NAO IDENTIFICADO - 0\n\n");
				op = ObtemInteiroValidoAtendimento(op);
				
				switch(op)
				{
					case 1:
						cliente_encontrado = 1;
						strcpy(nome_cliente, pnt_cadastroCliente[i].nome);
					break;
					case 2:
						cliente_encontrado = 0;   // não encontrado AINDA, mas não é erro
						nova_busca_cliente = 1;
					continue;
					case 0:
						cliente_encontrado = 1;
						strcpy(nome_cliente, "CLIENTE NAO IDENTIFICADO");
						id_cliente = 0;						
					break;
					default:
						do{
							printf("\n\aDigite uma opcao valida!\n\n");
							printf("Confirmar Cliente - 1\n");
							printf("Continuar busca - 2\n"); 
							printf("CLIENTE NAO IDENTIFICADO - 0\n\n");
							op = ObtemInteiroValidoAtendimento(op);
						}while(op < 0 || op > 2);
				}
			}
		}
		
		if(!cliente_encontrado && !nova_busca_cliente)
		{
			printf("\n██████████████████████████████\n\a");
			printf("█                            █\n");
			printf("█   CLIENTE NAO ENCONTRADO!  █\n");
			printf("█                            █\n");
			printf("██████████████████████████████\n\n");	
			
			printf("Confirmar CLIENTE NAO IDENTIFICADO - 1 | Continuar busca - 2 ");
			op = ObtemInteiroValidoAtendimento(op);
	
			switch(op)
			{
				case 1:
					cliente_encontrado = 1;
					strcpy(nome_cliente, "CLIENTE NAO IDENTIFICADO");
					id_cliente = 0;
				break;
				case 2:
				break;
				default:
					do{
						printf("\nDigite uma opcao valida!\n\n");
						printf("\nConfirmar cliente - 1\n");
						printf("Continuar busca - 2\n"); 
						printf("CLIENTE NAO IDENTIFICADO - 0\n\n");
						op = ObtemInteiroValidoAtendimento(op);
					}while(op < 1 || op > 2);
			}
		}
	
	}while(!cliente_encontrado);
	
	t = 0;
	
	system("cls");
	
	//do{
		t = 0;
		barber_encontrado = 0;
		
		printf("\nREGISTRO DE ATENDIMENTOS\n");
		printf("-------------------\n\n");
		
		printf("Informe o NOME do barber: ");
		scanf(" %[^\n]",nome_barber);
		LimpaStringAtendimento(nome_barber);
		ConverteMaiusculaAtendimento(nome_barber);
			
		if (pont_barber == NULL)
		{
			strcpy(nome_barber, "BARBER NAO IDENTIFICADO");
		}
					
		for(int i = 0; i < b; i++)
		{	
			if(strstr(pnt_cadastroBarber[i].nome, nome_barber) != NULL)
			{
				printf("\n");
				printf("╔══════════════════════════════════════════════════════════════════╗\n");
				printf("║                         **DADOS DO BARBER**                      ║\n");
				printf("╠══════════════════════════════════════════════════════════════════╣\n");
				printf("║ COD │          NOME          │       CPF       │     TELEFONE    ║\n");
				printf("╟──────────────────────────────────────────────────────────────────╢\n");
				printf("╟──────────────────────────────────────────────────────────────────╢\n");
				t = 1;
				break;
				
			}
		}
			
		for(int i = 0; i < b; i++)
		{	
			if(strstr(pnt_cadastroBarber[i].nome, nome_barber) != NULL)
			{
				if(barbers_exibidos % 2 == 0)
				{
					printf("║\033[32m%5d\033[0m│\033[32m%24s\033[0m│\033[32m%17s\033[0m│\033[32m%17s\033[0m║\n",
								pnt_cadastroBarber[i].id,
								pnt_cadastroBarber[i].nome,
								pnt_cadastroBarber[i].cpf,
								pnt_cadastroBarber[i].telefone);
					printf("╟──────────────────────────────────────────────────────────────────╢\n");
					barbers_exibidos++;
				}
				else
				{
					printf("║%5d│%24s│%17s│%17s║\n",
								pnt_cadastroBarber[i].id,
								pnt_cadastroBarber[i].nome,
								pnt_cadastroBarber[i].cpf,
								pnt_cadastroBarber[i].telefone);
					printf("╟──────────────────────────────────────────────────────────────────╢\n");
					barbers_exibidos++;
				}
						
				if(barbers_exibidos % 10 == 0 && barbers_exibidos != 0)
				{
					printf("╚══════════════════════════════════════════════════════════════════╝\n");
					printf("\nAperte qualquer tecla para continuar a lista de barbers... \n\n");
					system("pause > nul");
					printf("╔══════════════════════════════════════════════════════════════════╗\n");
					printf("║ ID  │          NOME          │       CPF       │     TELEFONE    ║\n");
					printf("╟──────────────────────────────────────────────────────────────────╢\n");
					printf("╟──────────────────────────────────────────────────────────────────╢\n");
					barbers_exibidos = 0;
				}
			}
		}
			
		if(t == 1)
		{		
			printf("╚══════════════════════════════════════════════════════════════════╝\n\n");
		}
		barbers_exibidos = 0;
		
		if (!t)
		{
			printf("\n██████████████████████████████\n\a");
			printf("█                            █\n");
			printf("█   BARBER NAO ENCONTRADO!   █\n");
			printf("█                            █\n");
			printf("██████████████████████████████\n\n");			
		}
	
	do{
				
		printf("Informe o ID do barber: ");
		id_barber = ObtemInteiroValidoAtendimento(id_barber);
			
		for(int i = 0; i < b; i++)
		{	
			if(pnt_cadastroBarber[i].id == id_barber)
			{
				system("cls");
				printf("\n");
				printf("╔══════════════════════════════════════════════════════════════════╗\n");
				printf("║                        **DADOS DO BARBER**                       ║\n");
				printf("╠══════════════════════════════════════════════════════════════════╣\n");
				printf("║ COD │          NOME          │       CPF       │     TELEFONE    ║\n");
				printf("╟──────────────────────────────────────────────────────────────────╢\n");
				printf("║%5d│\x1b[32m%24s\x1b[0m│%17s│%17s║\n",
							pnt_cadastroBarber[i].id,
							pnt_cadastroBarber[i].nome,
							pnt_cadastroBarber[i].cpf,
							pnt_cadastroBarber[i].telefone);
				printf("╚══════════════════════════════════════════════════════════════════╝\n");
					
				printf("\nConfirmar barber - 1\n");
				printf("Continuar busca - 2\n"); 
				printf("Cliente NAO IDENTIFICADO - 0\n\n");
				op = ObtemInteiroValidoAtendimento(op);
				
				switch(op)
				{
					case 1:
						barber_encontrado = 1;
						strcpy(nome_barber, pnt_cadastroBarber[i].nome);
					break;
					case 2:
						barber_encontrado = 0;   // não encontrado AINDA, mas não é erro
						nova_busca_barber = 1;
					continue;
					case 0:
						barber_encontrado = 1;
						strcpy(nome_barber, "BARBER NAO IDENTIFICADO");
						id_barber = 0;						
					break;
					default:
						do{
							printf("\n\aDigite uma opcao valida!\n\n");
							printf("Confirmar Barber - 1\n");
							printf("Continuar busca - 2\n"); 
							printf("BARBER NAO IDENTIFICADO - 0\n\n");
							op = ObtemInteiroValidoAtendimento(op);
						}while(op < 0 || op > 2);
				}
			}
		}
		
		if(!barber_encontrado && !nova_busca_barber)
		{
			printf("\n██████████████████████████████\n\a");
			printf("█                            █\n");
			printf("█   BARBER NAO ENCONTRADO!   █\n");
			printf("█                            █\n");
			printf("██████████████████████████████\n\n");	
			
			printf("Confirmar BARBER NAO IDENTIFICADO - 1 | Continuar busca - 2 ");
			op = ObtemInteiroValidoAtendimento(op);
	
			switch(op)
			{
				case 1:
					barber_encontrado = 1;
					strcpy(nome_barber, "BARBER NAO IDENTIFICADO");
					id_barber = 0;
				break;
				case 2:
				break;
				default:
					do{
						printf("\nDigite uma opcao valida!\n\n");
						printf("Confirmar Barber - 1\n");
						printf("Continuar busca - 2\n"); 
						printf("BARBER NAO IDENTIFICADO - 0\n\n");	
						op = ObtemInteiroValidoAtendimento(op);
					}while(op < 1 || op > 2);
			}
		}
		
	}while(!barber_encontrado);

	r = LeArquivoAtendimento(pnt_recibo);

	if(r == 0)
		registro_atendimento = 1;
	else
		registro_atendimento = pnt_recibo[r-1].registro + 1;
	
	do{
		w = 0;

		busca_servico = 0;
		servico_encontrado = 0;
		cod_servico = 0;
		preco_unitario = 0.0;
		preco_total_item = 0.0;
		cartao_pagamento = 0.0;
		pix_pagamento = 0.0;
		dinheiro_pagamento = 0.0;
		fidelidade_pagamento = 0;
		troco_pago = 0.0;
		
		e = 0;
		
		do{
			servico_encontrado = 0;
			nova_busca_servico = 0;
			t = 0;
			q = 0;

			e = LeArquivoServico(pnt_cadastroServico);
			
			//do{

				system("cls");
				printf("\nREGISTRO DE ATENDIMENTOS\n");
				printf("------------------------\n\n");
				
				printf("Informe a DESCRICAO do servico: ");
				scanf(" %[^\n]", descricao_servico);
				LimpaStringAtendimento(descricao_servico);
				ConverteMaiusculaAtendimento(descricao_servico);
				
				t = 0;
				q = 0;
				servico_encontrado = 0;
				nova_busca_servico = 0;
				servicos_exibidos = 0;
				
				for (int i = 0; i < e; i++)
				{
							
					if (strstr(pnt_cadastroServico[i].descricao, descricao_servico) != NULL)
					{
						printf("\n");
						printf("╔════════════════════════════════════════════════════════════════════╗\n");
						printf("║                      **BUSCA POR DESCRICAO**                       ║\n");
						printf("╠════════════════════════════════════════════════════════════════════╣\n");
						printf("║ COD │                   DESCRICAO                 │     PRECO      ║\n");
						printf("╟────────────────────────────────────────────────────────────────────╢\n");
						printf("╟────────────────────────────────────────────────────────────────────╢\n");
						t = 1;
						break;
					}
				}
			
				for (int i = 0; i < e; i++)
				{
					// strstr() verifica se 'descricao' esta contida no nome do servico
					if (strstr(pnt_cadastroServico[i].descricao, descricao_servico) != NULL)
					{
							
						printf("║%5d│\033[32m%45s\033[0m│%16.2f║\n",
									 pnt_cadastroServico[i].codigo,
									 pnt_cadastroServico[i].descricao,
									 pnt_cadastroServico[i].preco);
							printf("╟────────────────────────────────────────────────────────────────────╢\n");

						servicos_exibidos++;
					}
					
					if(servicos_exibidos < e && servicos_exibidos % 10 == 0 && servicos_exibidos != 0)
					{
						printf("╚════════════════════════════════════════════════════════════════════╝\n");
						printf("\nAperte qualquer tecla para continuar a lista de servicos... \n\n");
						system("pause > nul");
						printf("╠════════════════════════════════════════════════════════════════════╣\n");
						printf("║ COD │                   DESCRICAO                 │     PRECO      ║\n");
						printf("╟────────────────────────────────────────────────────────────────────╢\n");
						printf("╟────────────────────────────────────────────────────────────────────╢\n");
						servicos_exibidos = 0;
					}
				}
				if(t == 1)
				{
					printf("╚════════════════════════════════════════════════════════════════════╝\n\n");
				}
				if (!t)
				{
					printf("\n");
					printf("███████████████████████████████████████\n\a");
					printf("█                                     █\n");
					printf("█        SERVICO NAO ENCONTRADO!      █\n");
					printf("█                                     █\n");
					printf("███████████████████████████████████████\n\n\n");
						
				}
				
			op = 2;

			do{
				
				//system("cls");

				printf("\nInforme o CODIGO do servico: ");
				cod_servico = ObtemInteiroValidoAtendimento(cod_servico);
				servico_encontrado = 0;
				indice = -1;
				t = 0;
				
				for(int i = 0; i < e; i++)
				{	
					if(pnt_cadastroServico[i].codigo == cod_servico)
					{					
						indice = i;
						strcpy(descricao_servico, pnt_cadastroServico[i].descricao);
						preco_servico = pnt_cadastroServico[i].preco;
						break;
					}
				}
					
				if(indice == -1)
				{
					printf("\n");
					printf("███████████████████████████████████████\n\a");
					printf("█                                     █\n");
					printf("█        SERVICO NAO ENCONTRADO!      █\n");
					printf("█                                     █\n");
					printf("███████████████████████████████████████\n\n\n");	
					printf("Continuar busca - 1 | Encerrar busca - 2\n");
					op = ObtemInteiroValidoAtendimento(op);
					switch (op)
					{
						case 1:
						break;
						case 2:
							op = 2;
						break;
						default:
							do{
								printf("\n\a\033[31mDigite uma opcao valida!\033[0m\n\n");
								printf("Continuar busca - 1 | Encerrar busca - 2\n");
								op = ObtemInteiroValidoAtendimento(op);
							}while(op < 1 || op > 2);
					}
				}
				
				else
				{
					system("cls");
					printf("\n");
					printf("╔════════════════════════════════════════════════════════════════════╗\n");
					printf("║                       **SERVICO ENCONTRADO**                       ║\n");
					printf("╠════════════════════════════════════════════════════════════════════╣\n");
					printf("║ COD │                   DESCRICAO                 │     PRECO      ║\n");
					printf("╟────────────────────────────────────────────────────────────────────╢\n");
					printf("╟────────────────────────────────────────────────────────────────────╢\n");
					printf("║%5d│\033[32m%45s\033[0m│%16.2f║\n",
									cod_servico,
									descricao_servico,
									preco_servico);
									
					printf("╟────────────────────────────────────────────────────────────────────╢\n");
					printf("╚════════════════════════════════════════════════════════════════════╝\n\n");
					t = 1;
				}

			}while(op != 2);
			
			if(t)
			{
				do{
					printf("\nIncluir servico no atendimento - 1 | Continuar busca - 2 ");
					op = ObtemInteiroValidoAtendimento(op);
					
					if(op == 1)
					{
						servico_encontrado = 1;
						q = 2;
						s += 1;
					}
					else if(op == 2)
					{
						servico_encontrado = -1;
						nova_busca_servico = 1;
						q = 1;
						break;
					}
					
					if(op < 1 || op > 2)
					{
						printf("\a\nDigite uma opcao valida!\n\n");
							
						printf("\nIncluir servico no atendimento - 1 | Continuar busca - 2 ");
						op = ObtemInteiroValidoAtendimento(op);
						if(op == 1)
						{
							servico_encontrado = 1;
							q = 2;
							s += 1;
						}
						else if(op == 2)
						{
							servico_encontrado = -1;
							nova_busca_servico = 1;
							q = 1;
							break;
						}
					}
				
				}while(op < 1 || op > 2);
			}
			
		}while(q != 2);
		
		//Procurar o servico e atualizar a quantidade no arquivo temporário
		for(int w = 0; w < e; w++)
		{
			if (pnt_cadastroServico[w].codigo == cod_servico)
			{
				
				printf("\n");
				printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
				printf("║                                          **PORCENTAGEM DE DESCONTO**                                           ║\n");
				printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
				printf("║  5%% - Digite 5  │   10%% - Digite 10   │   15%% - Digite 15   │   20%% - Digite 20   │  \x1b[32mPRECO NORMAL - Digite 0\x1b[0m   ║\n");
				printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
				
				int valido = 0;
					do{
					op = ObtemInteiroValidoAtendimento(op);
					switch(op)
					{
						case 0:
						case 5:
						case 10:
						case 15:
						case 20:
							valido = 1;
							break;
						default:
							printf("\a\nDigite um desconto valido!\n\n");
					}
					}while(!valido);
				
				//Calcula porcentagem corretamente
				double porcentagem = op / 100.0;
				
				//Calcula valores com double
				double preco        = pnt_cadastroServico[w].preco;
				double desconto     = arredonda(preco * porcentagem);
				double preco_liq    = arredonda(preco - desconto);
				double total        = arredonda(preco_liq);					
				
				//Atribui no recibo
				strcpy(pnt_recibo[a].descricao, pnt_cadastroServico[w].descricao);
				pnt_recibo[a].codigo      = cod_servico;
				pnt_recibo[a].preco       = preco;
				pnt_recibo[a].desconto    = desconto;
				pnt_recibo[a].preco_total = total;
				
				//Validando forma de pagamento
				pnt_recibo[a].pagamento_cartao = 0.0f;
				pnt_recibo[a].pagamento_pix = 0.0f;
				pnt_recibo[a].pagamento_dinheiro = 0.0f;
				pnt_recibo[a].pagamento_fidelidade = 0;
				pnt_recibo[a].troco = 0.0f;
				
				//Zerando o preco final sem desconto e o lucro
				pnt_recibo[a].preco_final_sem_desconto = 0.0f;
				printf("\n");
			}
		}
			
		//Se o servico foi encontrado, finalizar o atendimento
		if (servico_encontrado && pnt_recibo[a].preco > 0.0f) 
		{
			//Limpando variavel para eventual nova contagem
			r = 0;
			
			time_t tempo_bruto; // Variável para armazenar o tempo em segundos
			struct tm *info_tempo; // Ponteiro para a estrutura que armazena data/hora detalhada

			//Obter o tempo bruto atual do sistema
			time(&tempo_bruto); // ou tempo_bruto = time(NULL);

			//Converter o tempo bruto para a hora local (localtime)
			info_tempo = localtime(&tempo_bruto);

			pnt_recibo[a].data_hora_atendimento.tm_mday = info_tempo->tm_mday;
			pnt_recibo[a].data_hora_atendimento.tm_mon = info_tempo->tm_mon + 1; // Meses são de 0 (janeiro) a 11 (dezembro)
			pnt_recibo[a].data_hora_atendimento.tm_year = info_tempo->tm_year + 1900; // Anos são contados a partir de 1900
			pnt_recibo[a].data_hora_atendimento.tm_hour = info_tempo->tm_hour;
			pnt_recibo[a].data_hora_atendimento.tm_min = info_tempo->tm_min;
			pnt_recibo[a].data_hora_atendimento.tm_sec = info_tempo->tm_sec;

			//Registrar o atendimento no arquivo de atendimentos
			pont_atendimento = fopen("atendimento.txt", "a");
			
			pnt_recibo[a].registro = registro_atendimento;
			pnt_recibo[a].idCliente = id_cliente;
			strcpy(pnt_recibo[a].nomeCliente, nome_cliente);
			pnt_recibo[a].idBarber = id_barber;
			strcpy(pnt_recibo[a].nomeBarber, nome_barber);
			
			if (pont_atendimento != NULL)
			{
				fprintf(pont_atendimento,"%d\n%d\n%s\n%d\n%s\n%d\n%s\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%d\n%.2f\n%d\n%d\n%d\n%d\n%d\n%d\n%.2f\n%.2f\n",
									 pnt_recibo[a].registro,
									 pnt_recibo[a].idCliente,
									 pnt_recibo[a].nomeCliente,
									 pnt_recibo[a].idBarber,
									 pnt_recibo[a].nomeBarber,
									 pnt_recibo[a].codigo,
									 pnt_recibo[a].descricao,
									 pnt_recibo[a].preco,
									 pnt_recibo[a].desconto,
									 pnt_recibo[a].preco_total,
									 pnt_recibo[a].pagamento_cartao,
									 pnt_recibo[a].pagamento_pix,
									 pnt_recibo[a].pagamento_dinheiro,
									 pnt_recibo[a].pagamento_fidelidade,
									 pnt_recibo[a].troco,
									 pnt_recibo[a].data_hora_atendimento.tm_mday,
									 pnt_recibo[a].data_hora_atendimento.tm_mon,
									 pnt_recibo[a].data_hora_atendimento.tm_year,
									 pnt_recibo[a].data_hora_atendimento.tm_hour,
									 pnt_recibo[a].data_hora_atendimento.tm_min,
									 pnt_recibo[a].data_hora_atendimento.tm_sec,
									 pnt_recibo[a].preco_final_sem_desconto,
									 pnt_recibo[a].preco_final_com_desconto);
									 
				fclose(pont_atendimento);
				
				
				//Decremento de variavel de registro, mas manter os servicos do atendimento com o mesmo registro
				r--;
			}
			else
			{
				printf("Erro ao registrar o atendimento.\n");
			}
		}
		
		//Incrementando variavel de quantidade de servicos do atendimento
		a++;
		
		do
		{
			//system("cls");
			printf("\n\x1b[32mSERVICO REGISTRADO COM SUCESSO\x1b[0m\n\n");
			printf("\nRegistrar outro servico - 1 | Encerrar atendimento - 2\n");
			op = ObtemInteiroValidoAtendimento(op);
		
			if(op < 1 || op > 2)
			{
				printf("\aDigite uma opcao valida!\n");
			}
			
			if(op == 1 || op == 2)
			{
				system("cls");
			}
			
		}while(op != 2 && op != 1);
		
	}while(op != 2);
	
	//Transfomando em centavos o total para evitar arredondamentos
	int total_centavos = 0;
	
	for(int i = 0; i < a; i++)
	{
		soma_desconto_total_item += pnt_recibo[i].desconto;
		
		//Transfomando em centavos, para evitar arredondamentos
		total_centavos += (int)round(pnt_recibo[i].preco_total * 100.0);
	}
	
	//Tranformando em reais o preco total com desconto
	soma_preco_total_item = total_centavos / 100.0f;
	
	//Calculando o preco total sem desconto para informar no recibo
	soma_preco_final_sem_desconto = soma_preco_total_item + soma_desconto_total_item;
	
	//Registrando a forma de pagamento e eventual troco no ultimo indice do pedido
	printf("\n");
	printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
	printf("║ SERVICO REGISTRADO %04d Itens                                                                                                              ║\n", a);
	printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║ ID  │              CLIENTE              │ ID  │           BARBER           │ COD │         DESCRICAO        │  VALOR UNIT. │  VALOR TOTAL  ║\n");
    printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
	printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
	
	if(servico_encontrado == 1)
	{
		for(int i = 0; i < a; i++)
		{
			printf("║%5d│%35s│%5d│%28s│%5d│%26s│%14.2f│%15.2f║\n",
					 id_cliente,
					 nome_cliente,
					 id_barber,
					 nome_barber,
					 pnt_recibo[i].codigo,
					 pnt_recibo[i].descricao,
					 pnt_recibo[i].preco,
					 pnt_recibo[i].preco_total);
		}
	}
	printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
    printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
    printf("║  REGISTRO  │    DATA    │   HORA   │ CARTAO TEF │     PIX    │  DINHEIRO  │ FIDEL │ VALOR TOTAL │  DESCONTO  │   TROCO   │   VALOR FINAL   ║\n");
    printf("║────────────│────────────│──────────│────────────│────────────│────────────│───────│─────────────│────────────├───────────│─────────────────╢\n");
	printf("║      %06d│  %02d/%02d/%04d│  %02d:%02d:%02d│  %10.2f│  %10.2f│  %10.2f│      %1d│%13.2f│%12.2f│%11.2f│\x1b[36m%17.2f\x1b[0m║\n",
																								
				registro_atendimento,
				pnt_recibo[a-1].data_hora_atendimento.tm_mday,
				pnt_recibo[a-1].data_hora_atendimento.tm_mon,
				pnt_recibo[a-1].data_hora_atendimento.tm_year,
				pnt_recibo[a-1].data_hora_atendimento.tm_hour,
				pnt_recibo[a-1].data_hora_atendimento.tm_min,
				pnt_recibo[a-1].data_hora_atendimento.tm_sec,
				pnt_recibo[a-1].pagamento_cartao,
				pnt_recibo[a-1].pagamento_pix,
				pnt_recibo[a-1].pagamento_dinheiro,
				pnt_recibo[a-1].pagamento_fidelidade,
				soma_preco_final_sem_desconto,
				soma_desconto_total_item,
				pnt_recibo[a-1].troco,
				soma_preco_total_item);
	printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
	
	do{
		printf("\n");
		printf("╔══════════════════════════════════════════════════════════════════════════════════╗\n");
		printf("║                               **FORMA DE PAGAMENTO**                             ║\n");
		printf("╠══════════════════════════════════════════════════════════════════════════════════╣\n");
		printf("║  CARTAO TEF - 1  │  PIX - 2  │  DINHEIRO - 3  │  FIDELIDADE - 4  │  \x1b[32mVALIDAR - 0\x1b[0m  ║\n");
		printf("╚══════════════════════════════════════════════════════════════════════════════════╝\n");
		
		op = ObtemInteiroValidoAtendimento(op);
		
		switch(op)
		{
			case 1:
				printf("\nInforme o valor (\x1b[36mCARTAO TEF\x1b[0m): ");
				scanf("%lld.%lld", &real, &centavos);
				cartao_cent = real * 100 + centavos;
				cartao_pagamento = cartao_cent / 100.0;
				pagamento_validado = 1;
			break;
			case 2:
				printf("\nInforme o valor (\x1b[36mPIX\x1b[0m): ");
				scanf("%lld.%lld", &real, &centavos);
				pix_cent = real * 100 + centavos;
				pix_pagamento = pix_cent / 100.0;
				pagamento_validado = 1;
			break;
			case 3:
				printf("\nInforme o valor (\x1b[36mDINHEIRO\x1b[0m): ");
				scanf("%lld.%lld", &real, &centavos);
				dinheiro_cent = real * 100 + centavos;
				dinheiro_pagamento = dinheiro_cent / 100.0;
				pagamento_validado = 1;
			break;
			case 4:
				servicos_prestados = 0;
				bonus_usados = 0;

				tam_fidelidade = LeArquivoFidelidade(pnt_registroFidelidade);

				saldo = ValidaFidelidade(pnt_registroFidelidade, tam_fidelidade, id_cliente);

				if(saldo >= 1)
				{
					fidelidade_pagamento = 1;
					pagamento_validado = 1;
					fidelidade_usada = 1;
				}
				else
				{
					printf("\nNao ha bonus de fidelidade disponivel!\n\n");
				}

			break;
			case 0:
			
				//Verificando se o valor pago é correspondente ao valor da compra
				soma_pagamento_cent = cartao_cent + pix_cent + dinheiro_cent;
				
				
			if(fidelidade_pagamento)
			{
				// 🔵 FIDELIDADE (prioridade máxima)
				pagamento_validado = 2;

				for(int i = 0; i < a; i++)
				{
					pnt_recibo[a-1].preco_final_com_desconto = 0;
					pnt_recibo[a-1].preco_final_sem_desconto = 0;
				}

				pnt_recibo[a-1].troco = 0;

				pnt_recibo[a-1].pagamento_cartao = cartao_pagamento;
				pnt_recibo[a-1].pagamento_pix = pix_pagamento;
				pnt_recibo[a-1].pagamento_dinheiro = dinheiro_pagamento;
				pnt_recibo[a-1].pagamento_fidelidade = fidelidade_pagamento;

				system("cls");
				printf("\nPagamento realizado com BONUS DE FIDELIDADE\n");
			}
			else if(soma_pagamento_cent >= total_centavos && !fidelidade_pagamento)
			{
				// 🟢 PAGAMENTO NORMAL
				pagamento_validado = 2;

				total_pago = soma_pagamento_cent / 100.0f;

				for(int i = 0; i < a; i++)
				{
					pnt_recibo[a-1].preco_final_com_desconto = soma_preco_total_item;
					pnt_recibo[a-1].preco_final_sem_desconto = soma_preco_final_sem_desconto;
				}

				pnt_recibo[a-1].pagamento_cartao = cartao_pagamento;
				pnt_recibo[a-1].pagamento_pix = pix_pagamento;
				pnt_recibo[a-1].pagamento_dinheiro = dinheiro_pagamento;
				pnt_recibo[a-1].pagamento_fidelidade = fidelidade_pagamento;

				pnt_recibo[a-1].troco = total_pago - soma_preco_total_item;
				troco_pago = pnt_recibo[a-1].troco;

				system("cls");
			}
			else
			{
				printf("\nValor insuficiente! Informe novo valor\n\n");
			}
				/* 
				if(pagamento_validado == 0)
				{
					printf("\a\nValide primeiro a compra escolhendo uma opcao de pagamento!\n\n");
				}
				
				else if(pagamento_validado == 1)
				{
					if(fidelidade_pagamento)
					{
						// Pagamento com fidelidade: preço e troco zerados
						pagamento_validado = 2;
						
						pnt_recibo[a-1].preco_final_sem_desconto = 0;
						pnt_recibo[a-1].preco_final_com_desconto = 0;
						pnt_recibo[a-1].troco = 0;

						pnt_recibo[a-1].pagamento_cartao = cartao_pagamento;
						pnt_recibo[a-1].pagamento_pix = pix_pagamento;
						pnt_recibo[a-1].pagamento_dinheiro = dinheiro_pagamento;
						pnt_recibo[a-1].pagamento_fidelidade = fidelidade_pagamento;
						
						system("cls");

						printf("\nPagamento realizado com BONUS DE FIDELIDADE\n");
					}
					
					if(soma_pagamento_cent >= total_centavos && !fidelidade_pagamento)
					{
						
							// Pagamento normal
							pagamento_validado = 2;

						for(int i = 0; i < a; i++) 
						{
							if(!fidelidade_pagamento) 
							{
								pnt_recibo[i].preco_final_com_desconto = soma_preco_total_item;
								pnt_recibo[i].preco_final_sem_desconto = soma_preco_final_sem_desconto;

								pnt_recibo[a-1].pagamento_cartao = cartao_pagamento;
								pnt_recibo[a-1].pagamento_pix = pix_pagamento;
								pnt_recibo[a-1].pagamento_dinheiro = dinheiro_pagamento;
								pnt_recibo[a-1].pagamento_fidelidade = fidelidade_pagamento;
								pnt_recibo[a-1].preco_final_com_desconto = soma_preco_total_item;
								
								total_pago = soma_pagamento_cent / 100.0f;
								pnt_recibo[a-1].troco = total_pago - soma_preco_total_item;
								troco_pago = pnt_recibo[a-1].troco;
								pnt_recibo[a-1].preco_final_sem_desconto = soma_preco_final_sem_desconto;
							} 
							else 
							{
								pnt_recibo[i].preco_final_com_desconto = 0;
								pnt_recibo[i].preco_final_sem_desconto = 0;
							}
						}

						system("cls");
					}

					else
					{
						printf("\nValor insuficiente! Informe novo valor\n\n");
					}
					*/
			break;
			default:
				do{	
					if(op < 0 || op > 3)
					{
						printf("\nDigite uma opcao valida!\n\n");
						op = ObtemInteiroValidoAtendimento(op);
					}
				}while(op < 0 || op > 3);
		}
	}while(pagamento_validado != 2);	
	
	printf("\n");
	printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
	printf("║ ATENDIMENTO REGISTRADO \x1b[36m%04d\x1b[0m Itens                                                                                       \x1b[36mPAGAMENTO VALIDADO\x1b[0m ║\n", a);
	printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
	printf("║ ID  │              CLIENTE              │ COD │                  DESCRICAO                  │ QTDE │ UN │ VALOR UNITARIO │   VALOR TOTAL   ║\n");
	printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
	printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
	
	if(servico_encontrado == 1)
	{
		for(int i = 0; i < a; i++)
		{
			printf("║%5d│%35s│%5d│%28s│%5d│%26s│%14.2f│%15.2f║\n",
					 id_cliente,
					 nome_cliente,
					 id_barber,
					 nome_barber,
					 pnt_recibo[i].codigo,
					 pnt_recibo[i].descricao,
					 pnt_recibo[i].preco,
					 pnt_recibo[i].preco_total);
		}
	}
	printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
    printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
    printf("║  REGISTRO  │    DATA    │   HORA   │ CARTAO TEF │     PIX    │  DINHEIRO  │ FIDEL │ VALOR TOTAL │  DESCONTO  │   TROCO   │   VALOR FINAL   ║\n");
    printf("║────────────│────────────│──────────│────────────│────────────│────────────│───────│─────────────│────────────├───────────│─────────────────╢\n");
    printf("║      %06d│  %02d/%02d/%04d│  %02d:%02d:%02d│  %10.2f│  %10.2f│  %10.2f│      %1d│%13.2f│%12.2f│%11.2f│\x1b[36m%17.2f\x1b[0m║\n",
																								
				registro_atendimento,
				pnt_recibo[a-1].data_hora_atendimento.tm_mday,
				pnt_recibo[a-1].data_hora_atendimento.tm_mon,
				pnt_recibo[a-1].data_hora_atendimento.tm_year,
				pnt_recibo[a-1].data_hora_atendimento.tm_hour,
				pnt_recibo[a-1].data_hora_atendimento.tm_min,
				pnt_recibo[a-1].data_hora_atendimento.tm_sec,
				pnt_recibo[a-1].pagamento_cartao,
				pnt_recibo[a-1].pagamento_pix,
				pnt_recibo[a-1].pagamento_dinheiro,
				pnt_recibo[a-1].pagamento_fidelidade,
				soma_preco_final_sem_desconto,
				soma_desconto_total_item,
				pnt_recibo[a-1].troco,
				pnt_recibo[a-1].preco_final_com_desconto);
	printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
							
	if(pnt_recibo[a-1].pagamento_cartao > 0.0)
		printf("\nCARTAO TEF = \x1b[36m%.2f\x1b[0m",pnt_recibo[a-1].pagamento_cartao);
	else
		printf("\nCARTAO TEF = %.2f",pnt_recibo[a-1].pagamento_cartao);
						
	if(pnt_recibo[a-1].pagamento_pix > 0.0)					
		printf("\nPIX = \x1b[36m%.2f\x1b[0m",pnt_recibo[a-1].pagamento_pix);
	else
		printf("\nPIX = %.2f",pnt_recibo[a-1].pagamento_pix);
						
	if(pnt_recibo[a-1].pagamento_dinheiro > 0.0)
		printf("\nDINHEIRO = \x1b[36m%.2f\x1b[0m",pnt_recibo[a-1].pagamento_dinheiro);
	else
		printf("\nDINHEIRO = %.2f",pnt_recibo[a-1].pagamento_dinheiro);
	
	if(pnt_recibo[a-1].pagamento_fidelidade > 0)
		printf("\nFIDELIDADE = \x1b[36mCONFIRMADO\x1b[0m");
	else
		printf("\nFIDELIDADE = ---");					
	
	if(pnt_recibo[a-1].troco > 0.0)
		printf("\n\nTROCO = \x1b[36m%.2f\x1b[0m\n\n",pnt_recibo[a-1].troco);
	else
		printf("\n\nTROCO = %.2f\n\n",pnt_recibo[a-1].troco);
	
	f = LeArquivoAtendimento(pnt_recibo);

	//Carregando informacoes financeiras na struct para atualizacao arquivo "atendimento" 
	if(fidelidade_pagamento)
	{
		pnt_recibo[f-1].pagamento_cartao = cartao_pagamento;
		pnt_recibo[f-1].pagamento_pix = pix_pagamento;
		pnt_recibo[f-1].pagamento_dinheiro = dinheiro_pagamento; 
		pnt_recibo[f-1].pagamento_fidelidade = fidelidade_pagamento;
		pnt_recibo[f-1].troco = troco_pago;
		pnt_recibo[f-1].preco_final_com_desconto = 0;
	}
	else
	{
		pnt_recibo[f-1].pagamento_cartao = cartao_pagamento;
		pnt_recibo[f-1].pagamento_pix = pix_pagamento;
		pnt_recibo[f-1].pagamento_dinheiro = dinheiro_pagamento; 
		pnt_recibo[f-1].pagamento_fidelidade = fidelidade_pagamento;
		pnt_recibo[f-1].troco = troco_pago;
		pnt_recibo[f-1].preco_final_com_desconto = soma_preco_total_item;
			
	}
	
	
	//Carregando informacoes financeiras na struct para atualizacao arquivo "FIDELIDADE" 
	pont_fidelidade = fopen("fidelidade.txt","a");
				
	if(pont_fidelidade == NULL)
	{
		printf("ERRO! O arquivo nao foi aberto!\n\n");
	}

	else
	{
		if(fidelidade_usada)
		{
			pnt_registroFidelidade[0].idCliente = id_cliente;
			strcpy(pnt_registroFidelidade[0].nomeCliente, nome_cliente);
			pnt_registroFidelidade[0].servicosAcumulados = 0;
			pnt_registroFidelidade[0].bonusUsados = 1;
		}
		else
		{
			pnt_registroFidelidade[0].idCliente = id_cliente;
			strcpy(pnt_registroFidelidade[0].nomeCliente, nome_cliente);
			pnt_registroFidelidade[0].servicosAcumulados = a; // A variável "a" acumulou o número de serviços, e será útil para dados em fidelidade.txt
			pnt_registroFidelidade[0].bonusUsados = 0;
		}

		fprintf(pont_fidelidade,"%d\n%s\n%d\n%d\n",
									pnt_registroFidelidade[0].idCliente,
									pnt_registroFidelidade[0].nomeCliente,
									pnt_registroFidelidade[0].servicosAcumulados,
									pnt_registroFidelidade[0].bonusUsados);

	}
	
	fclose(pont_fidelidade);

	pont_atendimento = fopen("atendimento.txt","w");	
	for(int i = 0; i < f; i++)
	{
		fprintf(pont_atendimento,"%d\n%d\n%s\n%d\n%s\n%d\n%s\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%d\n%.2f\n%d\n%d\n%d\n%d\n%d\n%d\n%.2f\n%.2f\n",
									 pnt_recibo[i].registro,
									 pnt_recibo[i].idCliente,
									 pnt_recibo[i].nomeCliente,
									 pnt_recibo[i].idBarber,
									 pnt_recibo[i].nomeBarber,
									 pnt_recibo[i].codigo,
									 pnt_recibo[i].descricao,
									 pnt_recibo[i].preco,
									 pnt_recibo[i].desconto,
									 pnt_recibo[i].preco_total,
									 pnt_recibo[i].pagamento_cartao,
									 pnt_recibo[i].pagamento_pix,
									 pnt_recibo[i].pagamento_dinheiro,
									 pnt_recibo[i].pagamento_fidelidade,
									 pnt_recibo[i].troco,
									 pnt_recibo[i].data_hora_atendimento.tm_mday,
									 pnt_recibo[i].data_hora_atendimento.tm_mon,
									 pnt_recibo[i].data_hora_atendimento.tm_year,
									 pnt_recibo[i].data_hora_atendimento.tm_hour,
									 pnt_recibo[i].data_hora_atendimento.tm_min,
									 pnt_recibo[i].data_hora_atendimento.tm_sec,
									 pnt_recibo[i].preco_final_sem_desconto,
									 pnt_recibo[i].preco_final_com_desconto);
	}
	
	fclose(pont_atendimento);
	
	printf("\nAperte qualquer tecla para voltar ao MENU INICIAL... ");
	system("pause > nul");
	system("cls"); 

}

void BuscaAtendimento(Atendimento * pnt_recibo)
{
	FILE *pont_atendimento;
	int menu_busca = 0;
	int y = 0;
	int t = 0;
	int op = 0;
	int registro_atendimento = 0;
	int id_cliente = 0;
	int dia_atendimento = 0;
	int mes_atendimento = 0;
	int ano_atendimento = 0;
	char nome_cliente[40];
	int atendimentos_exibidos = 0;
	float soma_preco_total_item = 0.0;
    float soma_desconto_total_item = 0.0;
	float soma_preco_final_sem_desconto = 0.0f;
	int fim_atendimento;
	int primeiro_item_cliente = 1;
	int contador_atendimentos = 0;
	
	y = LeArquivoAtendimento(pnt_recibo);
	
	do{
		system("cls");
		MenuBuscaAtendimento();
		
		op = ObtemInteiroValidoAtendimento(op);
	
		switch(op)
		{
			case 1:
				do{
					system("cls");
					printf("\nBUSCA DE ATENDIMENTO POR REGISTRO\n");
					printf("----------------------------\n\n");
					printf("Informe o REGISTRO do atendimento: ");
					registro_atendimento = ObtemInteiroValidoAtendimento(registro_atendimento);
					
					primeiro_item_cliente = 1;
					t = 0;
					contador_atendimentos = 0;
					
					for(int i = 0; i < y; i++)
					{	
						if(pnt_recibo[i].registro == registro_atendimento)
						{
							Atendimento atual = pnt_recibo[i];
							Atendimento anterior = (i > 0) ? pnt_recibo[i - 1] : atual;
							Atendimento proximo = (i < y - 1) ? pnt_recibo[i + 1] : atual;

							// Acumulações do atendimento
							soma_preco_total_item += atual.preco_total;
							soma_desconto_total_item += atual.desconto /* * atual.quantidade*/;
							soma_preco_final_sem_desconto = soma_preco_total_item + soma_desconto_total_item;
							
							// --- Impressão dos itens ---
							if (primeiro_item_cliente || atual.registro > anterior.registro)
							{
								// Novo atendimento → imprime o cabeçalho do item
								printf("\n");
								ImprimeCabecalhoItens();
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%35s\x1b[0m│%5d│%28s│%5d│\x1b[31m%26s\x1b[0m│%14.2f│%17.2f║\n",
									     atual.idCliente,
										 atual.nomeCliente,
										 atual.idBarber,
										 atual.nomeBarber,
										 atual.codigo,
										 atual.descricao,
									     atual.preco,
										 atual.preco_total);
								
								primeiro_item_cliente = 0;
							}
							
							
							
							else
							{
								// Mesmo atendimento → imprime sem cabeçalho
								printf("║     │                                   │     │                          │%5d│\x1b[31m%26s\x1b[0m│%14.2f│%17.2f║\n",
										 atual.codigo,
										 atual.descricao,
									     atual.preco,
										 atual.preco_total);
							}

							// --- Detecta fim do atendimento ---
							fim_atendimento = (i == y - 1) || (atual.registro < proximo.registro);

							if (fim_atendimento)
							{
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║  REGISTRO  │    DATA    │   HORA   │ CARTAO TEF │    PIX     │  DINHEIRO  │ FIDEL │ VALOR TOTAL │  DESCONTO  │   TROCO   │    VALOR FINAL    ║\n");
								printf("║────────────│────────────│──────────│────────────│────────────│────────────│───────│─────────────│────────────├───────────│───────────────────╢\n");

								printf("║      %06d│  %02d/%02d/%04d│  %02d:%02d:%02d│%12.2f│%12.2f│%12.2f│%7d│%13.2f│%12.2f│%11.2f│\x1b[36m%19.2f\x1b[0m║\n",
									     atual.registro,
									     atual.data_hora_atendimento.tm_mday,
									     atual.data_hora_atendimento.tm_mon,
									     atual.data_hora_atendimento.tm_year,
									     atual.data_hora_atendimento.tm_hour,
									     atual.data_hora_atendimento.tm_min,
									     atual.data_hora_atendimento.tm_sec,
									     atual.pagamento_cartao,
									     atual.pagamento_pix,
									     atual.pagamento_dinheiro,
										 atual.pagamento_fidelidade,
									     atual.preco_final_sem_desconto,
									     soma_desconto_total_item,
									     atual.troco,
									     atual.preco_final_com_desconto);
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");	   
								printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
								// Zera acumuladores para o próximo pedido
								soma_desconto_total_item = 0.0f;
								soma_preco_total_item = 0.0f;
								soma_preco_final_sem_desconto = 0.0f;
								contador_atendimentos++;
								
								// Pausa a cada 10 registros
								if (contador_atendimentos % 10 == 0)
								{
									printf("\nAperte qualquer tecla para seguir a listagem...\n\n");
									system("pause > nul");
								}
							}
							t = 1;
						}	
					}
					
					if(t == 0)
					{
						printf("\n");
						printf("███████████████████████████████████████\n\a");
						printf("█                                     █\n");
						printf("█       REGISTRO NAO ENCONTRADO!      █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n");	
					}
					printf("\nContinuar busca - 1 | Voltar ao MENU - 2 ");
					menu_busca = ObtemInteiroValidoAtendimento(menu_busca);
					do{
						if(menu_busca < 1 || menu_busca > 2)
						{
							printf("\nOpcao invalida!\n");
							printf("\nContinuar busca - 1 | Voltar ao MENU - 2 ");
							menu_busca = ObtemInteiroValidoAtendimento(menu_busca);
						}
					}while(menu_busca < 1 || menu_busca > 2);
					printf("\n");
					t = 0;
				}while(menu_busca != 2);
			break;
			case 2:
				do{
					system("cls");
					printf("\nBUSCA DE ATENDIMENTO POR ID E DATA\n");
					printf("-----------------------------\n\n");
					printf("Informe o ID do CLIENTE: ");
					id_cliente = ObtemInteiroValidoAtendimento(id_cliente);
					printf("\nInforme a DATA do ATENDIMENTO\n");
					printf("DIA: ");
					dia_atendimento = ObtemInteiroValidoAtendimento(dia_atendimento);
					printf("MES: ");
					mes_atendimento = ObtemInteiroValidoAtendimento(mes_atendimento);
					printf("ANO: ");
					ano_atendimento = ObtemInteiroValidoAtendimento(ano_atendimento);
					printf("\n");
					
					primeiro_item_cliente = 1;
					t = 0;
					contador_atendimentos = 0;
					
					for(int i = 0; i < y; i++)
					{	
						if(pnt_recibo[i].idCliente == id_cliente
						&& pnt_recibo[i].data_hora_atendimento.tm_mday == dia_atendimento
						&& pnt_recibo[i].data_hora_atendimento.tm_mon == mes_atendimento
						&& pnt_recibo[i].data_hora_atendimento.tm_year == ano_atendimento)
						{
							//int fim_atendimento;
							Atendimento atual = pnt_recibo[i];
							Atendimento anterior = (i > 0) ? pnt_recibo[i - 1] : atual;
							Atendimento proximo = (i < y - 1) ? pnt_recibo[i + 1] : atual;

							// Acumulações do atendimento
							soma_preco_total_item += atual.preco_total;
							soma_desconto_total_item += atual.desconto /* * atual.quantidade*/;
							soma_preco_final_sem_desconto = soma_preco_total_item + soma_desconto_total_item;

							// --- Impressão dos itens ---
							if (primeiro_item_cliente || atual.registro > anterior.registro)
							{
								// Novo atendimento → imprime o cabeçalho do item
								printf("\n");
								ImprimeCabecalhoItens();
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%35s\x1b[0m│%5d│%28s│%5d│\x1b[31m%26s\x1b[0m│%14.2f│%17.2f║\n",
									     atual.idCliente,
										 atual.nomeCliente,
										 atual.idBarber,
										 atual.nomeBarber,
										 atual.codigo,
										 atual.descricao,
									     atual.preco,
										 atual.preco_total);
								primeiro_item_cliente = 0;
							}
							else
							{
								// Mesmo atendimento → imprime sem cabeçalho
								printf("║     │                                   │     │                          │%5d│\x1b[31m%26s\x1b[0m│%14.2f│%17.2f║\n",
									     atual.codigo,
										 atual.descricao,
									     atual.preco,
										 atual.preco_total);
							}

							// --- Detecta fim do pedido ---
							fim_atendimento = (i == y - 1) || (atual.registro < proximo.registro);

							if (fim_atendimento)
							{
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║  REGISTRO  │    DATA    │   HORA   │ CARTAO TEF │    PIX     │  DINHEIRO  │ FIDEL │ VALOR TOTAL │  DESCONTO  │   TROCO   │    VALOR FINAL    ║\n");
								printf("║────────────│────────────│──────────│────────────│────────────│────────────│───────│─────────────│────────────├───────────│───────────────────╢\n");

								printf("║      %06d│  %02d/%02d/%04d│  %02d:%02d:%02d│%12.2f│%12.2f│%12.2f│%7d│%13.2f│%12.2f│%11.2f│\x1b[36m%19.2f\x1b[0m║\n",
									   atual.registro,
									   atual.data_hora_atendimento.tm_mday,
									   atual.data_hora_atendimento.tm_mon,
									   atual.data_hora_atendimento.tm_year,
									   atual.data_hora_atendimento.tm_hour,
									   atual.data_hora_atendimento.tm_min,
									   atual.data_hora_atendimento.tm_sec,
									   atual.pagamento_cartao,
									   atual.pagamento_pix,
									   atual.pagamento_dinheiro,
									   atual.pagamento_fidelidade,
									   atual.preco_final_sem_desconto,
									   soma_desconto_total_item,
									   atual.troco,
									   atual.preco_final_com_desconto);
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
								// Zera acumuladores para o próximo pedido
								soma_desconto_total_item = 0.0f;
								soma_preco_total_item = 0.0f;
								contador_atendimentos++;

								// Pausa a cada 10 registros
								if (contador_atendimentos % 10 == 0)
								{
									printf("\nAperte qualquer tecla para seguir a listagem...\n\n");
									system("pause > nul");
								}
							}
							t = 1;	
						}	
					}
					
					if(t == 0)
					{
						printf("\n");
						printf("███████████████████████████████████████\n\a");
						printf("█                                     █\n");
						printf("█       REGISTRO NAO ENCONTRADO!      █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n");	
					}
					printf("\nContinuar busca - 1 | Voltar ao MENU - 2 ");
					menu_busca = ObtemInteiroValidoAtendimento(menu_busca);
					do{
						if(menu_busca < 1 || menu_busca > 2)
						{
							printf("\nOpcao invalida!\n");
							printf("\nContinuar busca - 1 | Voltar ao MENU - 2 ");
							menu_busca = ObtemInteiroValidoAtendimento(menu_busca);
						}
					}while(menu_busca < 1 || menu_busca > 2);
					printf("\n");
					t = 0;
				}while(menu_busca != 2);
			break;
			case 3:
				do{
					system("cls");
					printf("\nBUSCA DE ATENDIMENTO POR NOME DE CLIENTE E DATA\n");
					printf("-----------------------------------------------\n\n");
					printf("Informe o NOME do CLIENTE: ");
					scanf(" %[^\n]",nome_cliente);
					LimpaStringAtendimento(nome_cliente);
					ConverteMaiusculaAtendimento(nome_cliente);
					printf("\nInforme a DATA do ATENDIMENTO\n");
					printf("DIA: ");
					dia_atendimento = ObtemInteiroValidoAtendimento(dia_atendimento);
					printf("MES: ");
					mes_atendimento = ObtemInteiroValidoAtendimento(mes_atendimento);
					printf("ANO: ");
					ano_atendimento = ObtemInteiroValidoAtendimento(ano_atendimento);
					printf("\n");
					
					primeiro_item_cliente = 1;
					t = 0;
					contador_atendimentos = 0;
					
					for(int i = 0; i < y; i++)
					{	
						if(strstr(pnt_recibo[i].nomeCliente, nome_cliente) != NULL 
						&& pnt_recibo[i].data_hora_atendimento.tm_mday == dia_atendimento
						&& pnt_recibo[i].data_hora_atendimento.tm_mon == mes_atendimento
						&& pnt_recibo[i].data_hora_atendimento.tm_year == ano_atendimento)
						{
							
							//int fim_atendimento;
							Atendimento atual = pnt_recibo[i];
							Atendimento anterior = (i > 0) ? pnt_recibo[i - 1] : atual;
							Atendimento proximo = (i < y - 1) ? pnt_recibo[i + 1] : atual;

							// Acumulações do atendimento
							soma_preco_total_item += atual.preco_total;
							soma_desconto_total_item += atual.desconto /* * atual.quantidade*/;
							soma_preco_final_sem_desconto = soma_preco_total_item + soma_desconto_total_item;

							// --- Impressão dos itens ---
							if (primeiro_item_cliente || atual.registro > anterior.registro)
							{
								// Novo atendimento → imprime o cabeçalho do item
								printf("\n");
								ImprimeCabecalhoItens();
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%35s\x1b[0m│%5d│%28s│%5d│\x1b[31m%26s\x1b[0m│%14.2f│%17.2f║\n",
									     atual.idCliente,
										 atual.nomeCliente,
										 atual.idBarber,
										 atual.nomeBarber,
										 atual.codigo,
										 atual.descricao,
									     atual.preco,
										 atual.preco_total);
								primeiro_item_cliente = 0;
							}
							else
							{
								// Mesmo atendimento → imprime sem cabeçalho
								printf("║     │                                   │     │                            │%5d│\x1b[31m%26s\x1b[0m│%14.2f│%17.2f║\n",
									     atual.codigo,
										 atual.descricao,
									     atual.preco,
										 atual.preco_total);
							}

							// --- Detecta fim do atendimento ---
							fim_atendimento = (i == y - 1) || (atual.registro < proximo.registro);

							if (fim_atendimento)
							{
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║  REGISTRO  │    DATA    │   HORA   │ CARTAO TEF │    PIX     │  DINHEIRO  │ FIDEL │ VALOR TOTAL │  DESCONTO  │   TROCO   │    VALOR FINAL    ║\n");
								printf("║────────────│────────────│──────────│────────────│────────────│────────────│───────│─────────────│────────────├───────────│───────────────────╢\n");

								printf("║      %06d│  %02d/%02d/%04d│  %02d:%02d:%02d│%12.2f│%12.2f│%12.2f│%7d│%13.2f│%12.2f│%11.2f│\x1b[36m%19.2f\x1b[0m║\n",
									   atual.registro,
									   atual.data_hora_atendimento.tm_mday,
									   atual.data_hora_atendimento.tm_mon,
									   atual.data_hora_atendimento.tm_year,
									   atual.data_hora_atendimento.tm_hour,
									   atual.data_hora_atendimento.tm_min,
									   atual.data_hora_atendimento.tm_sec,
									   atual.pagamento_cartao,
									   atual.pagamento_pix,
									   atual.pagamento_dinheiro,
									   atual.pagamento_fidelidade,
									   atual.preco_final_sem_desconto,
									   soma_desconto_total_item,
									   atual.troco,
									   atual.preco_final_com_desconto);
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");	   
								printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
								// Zera acumuladores para o próximo atendimento
								soma_desconto_total_item = 0.0f;
								soma_preco_total_item = 0.0f;
								contador_atendimentos++;
								
								// Pausa a cada 10 registros
								if (contador_atendimentos % 10 == 0)
								{
									printf("\nAperte qualquer tecla para seguir a listagem...\n\n");
									system("pause > nul");
								}
							}
							t = 1;	
						}	
					}
					
					if(t == 0)
					{
						printf("\n");
						printf("███████████████████████████████████████\n\a");
						printf("█                                     █\n");
						printf("█       REGISTRO NAO ENCONTRADO!      █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n");	
					}
					printf("\nContinuar busca - 1 | Voltar ao MENU - 2 ");
					menu_busca = ObtemInteiroValidoAtendimento(menu_busca);
					do{
						if(menu_busca < 1 || menu_busca > 2)
						{
							printf("\nOpcao invalida!\n");
							printf("\nContinuar busca - 1 | Voltar ao MENU - 2 ");
							menu_busca = ObtemInteiroValidoAtendimento(menu_busca);
						}
					}while(menu_busca < 1 || menu_busca > 2);
					printf("\n");
					t = 0;
				}while(menu_busca != 2);
			break;
			case 4:
				do{
					//primeiro_item_cliente = 1;
					system("cls");
					printf("\nBUSCA DE ATENDIMENTO POR ID DE CLIENTE\n");
					printf("--------------------------------------\n\n");
					printf("Informe o ID do CLIENTE: ");
					id_cliente = ObtemInteiroValidoAtendimento(id_cliente);
					
					primeiro_item_cliente = 1;
					t = 0;
					contador_atendimentos = 0;
					
					for(int i = 0; i < y; i++)
					{	
						if(pnt_recibo[i].idCliente == id_cliente)
						{
							//int fim_atendimento;
							Atendimento atual = pnt_recibo[i];
							Atendimento anterior = (i > 0) ? pnt_recibo[i - 1] : atual;
							Atendimento proximo = (i < y - 1) ? pnt_recibo[i + 1] : atual;

							// Acumulações do atendimento
							soma_preco_total_item += atual.preco_total;
							soma_desconto_total_item += atual.desconto;
							soma_preco_final_sem_desconto = soma_preco_total_item + soma_desconto_total_item;
							
							// --- Impressão dos itens ---
							
							if (primeiro_item_cliente || atual.registro > anterior.registro)
							{
								// Novo atendimento → imprime o cabeçalho do item
								printf("\n");
								ImprimeCabecalhoItens();
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%35s\x1b[0m│%5d│\033[32m%28s\033[0m│%5d│%26s│%14.2f│%17.2f║\n",
									     atual.idCliente,
										 atual.nomeCliente,
										 atual.idBarber,
										 atual.nomeBarber,
										 atual.codigo,
										 atual.descricao,
									     atual.preco,
										 atual.preco_total);
								primeiro_item_cliente = 0;
							}
							else
							{
								// Mesmo atendimento → imprime sem cabeçalho
								printf("║     │                                   │     │                            │%5d│%26s│%14.2f│%17.2f║\n",
									     atual.codigo,
										 atual.descricao,
									     atual.preco,
										 atual.preco_total);
							}

							// --- Detecta fim do atendimento ---
							fim_atendimento = (i == y - 1) || (atual.registro < proximo.registro);
							
							
							
							if (fim_atendimento)
							{
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║  REGISTRO  │    DATA    │   HORA   │ CARTAO TEF │    PIX     │  DINHEIRO  │ FIDEL │ VALOR TOTAL │  DESCONTO  │   TROCO   │    VALOR FINAL    ║\n");
								printf("║────────────│────────────│──────────│────────────│────────────│────────────│───────│─────────────│────────────├───────────│───────────────────╢\n");

								printf("║      %06d│  %02d/%02d/%04d│  %02d:%02d:%02d│%12.2f│%12.2f│%12.2f│%7d│%13.2f│%12.2f│%11.2f│\x1b[36m%19.2f\x1b[0m║\n",
									   atual.registro,
									   atual.data_hora_atendimento.tm_mday,
									   atual.data_hora_atendimento.tm_mon,
									   atual.data_hora_atendimento.tm_year,
									   atual.data_hora_atendimento.tm_hour,
									   atual.data_hora_atendimento.tm_min,
									   atual.data_hora_atendimento.tm_sec,
									   atual.pagamento_cartao,
									   atual.pagamento_pix,
									   atual.pagamento_dinheiro,
									   atual.pagamento_fidelidade,
									   atual.preco_final_sem_desconto,
									   soma_desconto_total_item,
									   atual.troco,
									   atual.preco_final_com_desconto/*pnt_recibo[i].preco_final_com_desconto*/);
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");	   
								printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
								// Zera acumuladores para o próximo atendimento
								soma_desconto_total_item = 0.0f;
								soma_preco_total_item = 0.0f;
								contador_atendimentos++;
								
								// Pausa a cada 10 registros
								if (contador_atendimentos % 10 == 0)
								{
									printf("\nAperte qualquer tecla para seguir a listagem...\n\n");
									system("pause > nul");
								}
								
								primeiro_item_cliente = 1;
							}
							t = 1;
						}	
					}
					
					if(t == 0)
					{
						printf("\n");
						printf("███████████████████████████████████████\n\a");
						printf("█                                     █\n");
						printf("█       REGISTRO NAO ENCONTRADO!      █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n");	
					}
					printf("\nContinuar busca - 1 | Voltar ao MENU - 2 ");
					menu_busca = ObtemInteiroValidoAtendimento(menu_busca);
					do{
						if(menu_busca < 1 || menu_busca > 2)
						{
							printf("\nOpcao invalida!\n");
							printf("\nContinuar busca - 1 | Voltar ao MENU - 2 ");
							menu_busca = ObtemInteiroValidoAtendimento(menu_busca);
						}
					}while(menu_busca < 1 || menu_busca > 2);
					printf("\n");
					t = 0;
				}while(menu_busca != 2);
			break;
			case 5:
				do{
					system("cls");
					printf("\nBUSCA DE ATENDIMENTO POR NOME DE CLIENTE\n");
					printf("-----------------------------------\n\n");
					printf("Informe o NOME do CLIENTE: ");
					scanf(" %[^\n]",nome_cliente);
					
					LimpaStringAtendimento(nome_cliente);
					ConverteMaiusculaAtendimento(nome_cliente);
					
					primeiro_item_cliente = 1;
					t = 0;
					contador_atendimentos = 0;
					
					for(int i = 0; i < y; i++)
					{	
						if(strstr(pnt_recibo[i].nomeCliente, nome_cliente) != NULL)
						{
							//int fim_atendimento;
							Atendimento atual = pnt_recibo[i];
							Atendimento anterior = (i > 0) ? pnt_recibo[i - 1] : atual;
							Atendimento proximo = (i < y - 1) ? pnt_recibo[i + 1] : atual;

							// Acumulações do atendimento
							soma_preco_total_item += atual.preco_total;
							soma_desconto_total_item += atual.desconto /* * atual.quantidade*/;
							soma_preco_final_sem_desconto = soma_preco_total_item + soma_desconto_total_item;

							// --- Impressão dos itens ---
							if (primeiro_item_cliente || atual.registro > anterior.registro)
							{
								// Novo atendimento → imprime o cabeçalho do item
								printf("\n");
								ImprimeCabecalhoItens();
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%35s\x1b[0m│%5d│\033[32m%28s\033[0m│%5d│%26s│%14.2f│%17.2f║\n",
									     atual.idCliente,
										 atual.nomeCliente,
										 atual.idBarber,
										 atual.nomeBarber,
										 atual.codigo,
										 atual.descricao,
									     atual.preco,
										 atual.preco_total);
								primeiro_item_cliente = 0;
							}
							else
							{
								// Mesmo atendimento → imprime sem cabeçalho
								printf("║     │                                   │     │                            │%5d│%26s│%14.2f│%17.2f║\n",
									     atual.codigo,
										 atual.descricao,
									     atual.preco,
										 atual.preco_total);
							}

							// --- Detecta fim do atendimento ---
							fim_atendimento = (i == y - 1) || (atual.registro < proximo.registro);

							if (fim_atendimento)
							{
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║  REGISTRO  │    DATA    │   HORA   │ CARTAO TEF │    PIX     │  DINHEIRO  │ FIDEL │ VALOR TOTAL │  DESCONTO  │   TROCO   │    VALOR FINAL    ║\n");
								printf("║────────────│────────────│──────────│────────────│────────────│────────────│───────│─────────────│────────────├───────────│───────────────────╢\n");

								printf("║      %06d│  %02d/%02d/%04d│  %02d:%02d:%02d│%12.2f│%12.2f│%12.2f│%7d│%13.2f│%12.2f│%11.2f│\x1b[36m%19.2f\x1b[0m║\n",
									   atual.registro,
									   atual.data_hora_atendimento.tm_mday,
									   atual.data_hora_atendimento.tm_mon,
									   atual.data_hora_atendimento.tm_year,
									   atual.data_hora_atendimento.tm_hour,
									   atual.data_hora_atendimento.tm_min,
									   atual.data_hora_atendimento.tm_sec,
									   atual.pagamento_cartao,
									   atual.pagamento_pix,
									   atual.pagamento_dinheiro,
									   atual.pagamento_fidelidade,
									   atual.preco_final_sem_desconto,
									   soma_desconto_total_item,
									   atual.troco,
									   atual.preco_final_com_desconto);
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");	   
								printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
								// Zera acumuladores para o próximo pedido
								soma_desconto_total_item = 0.0f;
								soma_preco_total_item = 0.0f;
								contador_atendimentos++;

								// Pausa a cada 10 atendimentos
								if (contador_atendimentos % 10 == 0)
								{
									printf("\nAperte qualquer tecla para seguir a listagem...\n\n");
									system("pause > nul");
								}
							}
							t = 1;
						}	
					}
					
					if(t == 0)
					{
						printf("\n");
						printf("███████████████████████████████████████\n\a");
						printf("█                                     █\n");
						printf("█       REGISTRO NAO ENCONTRADO!      █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n");	
					}
					printf("\nContinuar busca - 1 | Voltar ao MENU - 2 ");
					menu_busca = ObtemInteiroValidoAtendimento(menu_busca);
					do{
						if(menu_busca < 1 || menu_busca > 2)
						{
							printf("\nOpcao invalida!\n");
							printf("\nContinuar busca - 1 | Voltar ao MENU - 2 ");
							menu_busca = ObtemInteiroValidoAtendimento(menu_busca);
						}
					}while(menu_busca < 1 || menu_busca > 2);
					printf("\n");
					t = 0;
				}while(menu_busca != 2);
			break;
			case 6:
				do{
					system("cls");
					printf("\nBUSCA DE ATENDIMENTO POR DATA\n");
					printf("------------------------\n\n");
					
					printf("Informe a DATA do PEDIDO\n");
					printf("DIA: ");
					dia_atendimento = ObtemInteiroValidoAtendimento(dia_atendimento);
					printf("MES: ");
					mes_atendimento = ObtemInteiroValidoAtendimento(mes_atendimento);
					printf("ANO: ");
					ano_atendimento = ObtemInteiroValidoAtendimento(ano_atendimento);
					printf("\n");
					
					primeiro_item_cliente = 1;
					t = 0;
					contador_atendimentos = 0;
					
					for(int i = 0; i < y; i++)
					{	
						if(pnt_recibo[i].data_hora_atendimento.tm_mday == dia_atendimento
						&& pnt_recibo[i].data_hora_atendimento.tm_mon == mes_atendimento
						&& pnt_recibo[i].data_hora_atendimento.tm_year == ano_atendimento)
						{
							//int fim_atendimento;
							Atendimento atual = pnt_recibo[i];
							Atendimento anterior = (i > 0) ? pnt_recibo[i - 1] : atual;
							Atendimento proximo = (i < y - 1) ? pnt_recibo[i + 1] : atual;

							// Acumulações do atendimento
							soma_preco_total_item += atual.preco_total;
							soma_desconto_total_item += atual.desconto /* * atual.quantidade*/;
							soma_preco_final_sem_desconto = soma_preco_total_item + soma_desconto_total_item;

							// --- Impressão dos itens ---
							if (primeiro_item_cliente || atual.registro > anterior.registro)
							{
								// Novo atendimento → imprime o cabeçalho do item
								printf("\n");
								ImprimeCabecalhoItens();
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%35s\x1b[0m│%5d│\033[32m%28s\033[0m│%5d│%26s│%14.2f│%17.2f║\n",									     
									     atual.idCliente,
										 atual.nomeCliente,
										 atual.idBarber,
										 atual.nomeBarber,
										 atual.codigo,
										 atual.descricao,
									     atual.preco,
										 atual.preco_total);
								primeiro_item_cliente = 0;
							}
							else
							{
								// Mesmo atendimento → imprime sem cabeçalho
								printf("║     │                                   │     │                            │%5d│%26s│%14.2f│%17.2f║\n",
									     atual.codigo,
										 atual.descricao,
									     atual.preco,
										 atual.preco_total);
							}

							// --- Detecta fim do atendimento ---
							fim_atendimento = (i == y - 1) || (atual.registro < proximo.registro);

							if (fim_atendimento)
							{
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║  REGISTRO  │    DATA    │   HORA   │ CARTAO TEF │    PIX     │  DINHEIRO  │ FIDEL │ VALOR TOTAL │  DESCONTO  │   TROCO   │    VALOR FINAL    ║\n");
								printf("║────────────│────────────│──────────│────────────│────────────│────────────│───────│─────────────│────────────├───────────│───────────────────╢\n");

								printf("║      %06d│  %02d/%02d/%04d│  %02d:%02d:%02d│%12.2f│%12.2f│%12.2f│%7d│%13.2f│%12.2f│%11.2f│\x1b[36m%19.2f\x1b[0m║\n",
									   atual.registro,
									   atual.data_hora_atendimento.tm_mday,
									   atual.data_hora_atendimento.tm_mon,
									   atual.data_hora_atendimento.tm_year,
									   atual.data_hora_atendimento.tm_hour,
									   atual.data_hora_atendimento.tm_min,
									   atual.data_hora_atendimento.tm_sec,
									   atual.pagamento_cartao,
									   atual.pagamento_pix,
									   atual.pagamento_dinheiro,
									   atual.pagamento_fidelidade,
									   atual.preco_final_sem_desconto,
									   soma_desconto_total_item,
									   atual.troco,
									   atual.preco_final_com_desconto);
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");	   
								printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
								// Zera acumuladores para o próximo pedido
								soma_desconto_total_item = 0.0f;
								soma_preco_total_item = 0.0f;
								contador_atendimentos++;
      

								// Pausa a cada 10 atendimentos
								if (contador_atendimentos % 10 == 0)
								{
									printf("\nAperte qualquer tecla para seguir a listagem...\n\n");
									system("pause > nul");
								}
							}
							t = 1;	
						}	
					}
					
					if(t == 0)
					{
						printf("\n");
						printf("███████████████████████████████████████\n\a");
						printf("█                                     █\n");
						printf("█       REGISTRO NAO ENCONTRADO!      █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n");	
					}
					printf("\nContinuar busca - 1 | Voltar ao MENU - 2 ");
					menu_busca = ObtemInteiroValidoAtendimento(menu_busca);
					do{
						if(menu_busca < 1 || menu_busca > 2)
						{
							printf("\nOpcao invalida!\n");
							printf("\nContinuar busca - 1 | Voltar ao MENU - 2 ");
							menu_busca = ObtemInteiroValidoAtendimento(menu_busca);
						}
					}while(menu_busca < 1 || menu_busca > 2);
					printf("\n");
					t = 0;
				}while(menu_busca != 2);
			case 0:
				system("cls");
			break;
			default:
				do{
				printf("\nDigite uma opcao valida!\n\n");
				op = ObtemInteiroValidoAtendimento(op);
				}while(op < 0 || op > 5);
		}
	}while(op != 0);	
	system("cls");
}

void ListaAtendimento(Atendimento * pnt_recibo)
{
	FILE *pont_atendimento;
	int f = 0;
	
	f = LeArquivoAtendimento(pnt_recibo);
	
	system("cls");
	
	if(f > 0)
	{
		printf("\n");
		printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
		printf("║                                                            **LISTA DE ATENDIMENTOS**                                                         ║\n");
		ImprimeAtendimento(pnt_recibo, f);
	}
	else
	{
		printf("\n");
		printf("████████████████████████████████████████████████\n\a");
		printf("█                                              █\n");
		printf("█    NAO HA DADOS REGISTRADOS! ARQUIVO VAZIO   █\n");
		printf("█                                              █\n");
		printf("████████████████████████████████████████████████\n\n");
		
		printf("\nAperte qualquer tecla para voltar ao MENU INICIAL... \n\n");
		system("pause > nul");
		system("cls");
	}
}

void RemoveAtendimento(Atendimento * pnt_recibo)
{
	FILE *pont_atendimento;
	int fim_atendimento;
	int menu_remove = 0;
	int y = 0;
	int r = 0;
	int b = 0;
	int op = 0;
	int registro_atendimento = 0;
	float soma_desconto_total_item = 0.0f;
	float soma_preco_final_sem_desconto = 0.0f;
    float soma_preco_total_item = 0.0f;
	int primeiro_item_cliente = 1;
	
	system("cls");
	
	do{
		r = 0;
		y = 0;
		
		y = LeArquivoAtendimento(pnt_recibo);
		
		printf("\nREMOVER ATENDIMENTO\n");
		printf("--------------\n\n");
		printf("Informe o REGISTRO do atendimento a ser removido: ");
		
		registro_atendimento = ObtemInteiroValidoAtendimento(registro_atendimento);
		printf("\n");
		
		for(int i = 0; i < y; i++)
		{
			if(pnt_recibo[i].registro == registro_atendimento)
			{
				b = 1;
				break;
			}
		}
		if(b == 1)
		{
			printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
			printf("║                                                         **ATENDIMENTO ENCONTRADO**                                                           ║\n");
			b = 0;
		}
		
		for(int i = 0; i < y; i++)
		{
			if(pnt_recibo[i].registro == registro_atendimento)
			{
				Atendimento atual = pnt_recibo[i];
				Atendimento anterior = (i > 0) ? pnt_recibo[i - 1] : atual;
				Atendimento proximo = (i < y - 1) ? pnt_recibo[i + 1] : atual;
				// Acumulações do atendimento
				soma_preco_total_item += atual.preco_total;
				soma_desconto_total_item += atual.desconto /* * atual.quantidade*/;
				soma_preco_final_sem_desconto = soma_preco_total_item + soma_desconto_total_item;
							
				//Impressão dos itens
				if (primeiro_item_cliente || atual.registro > anterior.registro)
				{
					// Novo atendimento → imprime o cabeçalho do item
					ImprimeCabecalhoItensInicio();
					printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
					printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%35s\x1b[0m│%5d│%28s│%5d│%26s│%14.2f│%17.2f║\n",
									     atual.idCliente,
										 atual.nomeCliente,
										 atual.idBarber,
										 atual.nomeBarber,
										 atual.codigo,
										 atual.descricao,
									     atual.preco,
										 atual.preco_total);
								primeiro_item_cliente = 0;
				}
					
				else
				{
					// Mesmo pedido → imprime sem cabeçalho
					printf("║                                            %5d│%26s│%14.2f│%17.2f║\n",
									     atual.codigo,
										 atual.descricao,
									     atual.preco,
										 atual.preco_total);
				}
				//Detecta fim do atendimento
				fim_atendimento = (i == y - 1) || (atual.registro < proximo.registro);

				if (fim_atendimento)
				{
					printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
					printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
					printf("║  REGISTRO  │    DATA    │    HORA    │ CARTAO TEF │     PIX    │  DINHEIRO  │ FIDEL │ VALOR TOTAL │  DESCONTO  │   TROCO   │   VALOR FINAL   ║\n");
					printf("║────────────│────────────│────────────│────────────│────────────│────────────│───────│─────────────│────────────├───────────│─────────────────╢\n");

					printf("║      %06d│  %02d/%02d/%04d│    %02d:%02d:%02d│  %10.2f│  %10.2f│  %10.2f│      %1d│%13.2f│%12.2f│%11.2f│\x1b[36m%17.2f\x1b[0m║\n",
									   atual.registro,
									   atual.data_hora_atendimento.tm_mday,
									   atual.data_hora_atendimento.tm_mon,
									   atual.data_hora_atendimento.tm_year,
									   atual.data_hora_atendimento.tm_hour,
									   atual.data_hora_atendimento.tm_min,
									   atual.data_hora_atendimento.tm_sec,
									   atual.pagamento_cartao,
									   atual.pagamento_pix,
									   atual.pagamento_dinheiro,
									   atual.pagamento_fidelidade,
									   atual.preco_final_sem_desconto,
									   soma_desconto_total_item,
									   atual.troco,
									   atual.preco_final_com_desconto);
					printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");	   
					printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
					
					// Zera acumuladores para o próximo atendimento
					soma_desconto_total_item = 0.0f;
					soma_preco_total_item = 0.0f;
					soma_preco_final_sem_desconto = 0.0f;
				}
				r = 1;
			}	
		}
		
		if(r == 1)
		{
			
			printf("\nRemover atendimento - 1\n");
			printf("Cancelar remoção e continuar busca - 2\n");
			printf("Cancelar remoção e voltar ao MENU INICIAL - 0\n");
			menu_remove = ObtemInteiroValidoAtendimento(menu_remove);
			
			switch (menu_remove)
			{
				case 1:
					pont_atendimento = fopen("atendimento.txt","w");
					
					for(int i = 0; i < y; i++)
					{
						if(pnt_recibo[i].registro != registro_atendimento)
						{
							fprintf(pont_atendimento,"%d\n%d\n%s\n%d\n%s\n%d\n%s\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%d\n%.2f\n%d\n%d\n%d\n%d\n%d\n%d\n%.2f\n%.2f\n",
									 pnt_recibo[i].registro,
									 pnt_recibo[i].idCliente,
									 pnt_recibo[i].nomeCliente,
									 pnt_recibo[i].idBarber,
									 pnt_recibo[i].nomeBarber,
									 pnt_recibo[i].codigo,
									 pnt_recibo[i].descricao,
									 pnt_recibo[i].preco,
									 pnt_recibo[i].desconto,
									 pnt_recibo[i].preco_total,
									 pnt_recibo[i].pagamento_cartao,
									 pnt_recibo[i].pagamento_pix,
									 pnt_recibo[i].pagamento_dinheiro,
									 pnt_recibo[i].pagamento_fidelidade,
									 pnt_recibo[i].troco,
									 pnt_recibo[i].data_hora_atendimento.tm_mday,
									 pnt_recibo[i].data_hora_atendimento.tm_mon,
									 pnt_recibo[i].data_hora_atendimento.tm_year,
									 pnt_recibo[i].data_hora_atendimento.tm_hour,
									 pnt_recibo[i].data_hora_atendimento.tm_min,
									 pnt_recibo[i].data_hora_atendimento.tm_sec,
									 pnt_recibo[i].preco_final_sem_desconto,
									 pnt_recibo[i].preco_final_com_desconto);
						}
					}
					
					fclose(pont_atendimento);
					
					system("cls");
					printf("\n\nATENDIMENTO REMOVIDO\n\n");
					printf("Remover outro atendimento - 1 | Voltar ao MENU INICIAL - 2\n");
					op = ObtemInteiroValidoAtendimento(op);
					switch (op)
					{
						case 1:
							system("cls");
						break;
						case 2:
							r = 2;
							system("cls");
						break;
						default:
							do{
								printf("\nDigite uma opcao valida!\n\n");
								printf("Remover outro atendimento - 1 | Voltar ao MENU INICIAL - 2\n");
								op = ObtemInteiroValidoAtendimento(op);
							}while(op < 1 || op > 2);
					}
					
				break;
				case 2:
					r = 1;
					system("cls");
					printf("\n\nREMOCAO CANCELADA\n\n");
					printf("\nAperte uma tecla para continuar busca... \n\n");
					system("pause > nul");
					system("cls");
				break;
				case 0:
					r = 2;
					system("cls");
					printf("\n\nREMOCAO CANCELADA\n\n");
					printf("\nAperte uma tecla para voltar ao MENU INICIAL... \n\n");
					system("pause > nul");
					system("cls");
				break;
				default:
					do{
						printf("\nDigite uma opcao valida!\n\n");
						printf("\nRemover atendimento - 1\n");
						printf("Cancelar remoção e continuar busca - 2\n");
						printf("Cancelar remoção e voltar ao MENU INICIAL - 0\n");
						menu_remove = ObtemInteiroValidoAtendimento(menu_remove);
					}while(menu_remove < 0 || menu_remove > 2);
			}
		}
						
		if(r == 0)
		{
			printf("\n");
			printf("███████████████████████████████████████\n\a");
			printf("█                                     █\n");
			printf("█     ATENDIMENTO NAO ENCONTRADO!     █\n");
			printf("█                                     █\n");
			printf("███████████████████████████████████████\n\n");
				
			printf("Continuar busca - 1 | Voltar ao MENU INICIAL - 0\n");
			
			menu_remove = ObtemInteiroValidoAtendimento(menu_remove);
					
			switch (menu_remove)
			{
				case 1:
					r = 0;
					system("cls");
				break;
				case 0:
					r = 2;
					system("cls");
				break;
				default:
					do{
						printf("\nDigite uma opcao valida!\n\n");
						printf("Continuar busca - 1 | Voltar ao MENU INICIAL - 0\n");
						
						menu_remove = ObtemInteiroValidoAtendimento(menu_remove);
							
					}while(menu_remove < 0 || menu_remove > 1);
			}		
		}	
	}while(r != 2);
}

int ValidaFidelidade(Fidelidade *pnt_registroFidelidade, int tam, int id_cliente)
{
    int soma_servicos = 0;
    int bonus_usados = 0;

    for(int i = 0; i < tam; i++)
    {
        if(pnt_registroFidelidade[i].idCliente == id_cliente)
        {
            soma_servicos += pnt_registroFidelidade[i].servicosAcumulados;
            bonus_usados += pnt_registroFidelidade[i].bonusUsados;
        }
    }

    int bonus_obtidos = soma_servicos / 5;
    int saldo = bonus_obtidos - bonus_usados;

    return saldo;
}
