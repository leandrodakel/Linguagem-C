
int ValidaDataFutura(int dia, int mes, int ano, int hora, int minuto);
void LimpaStringAgendamento(char *str);
void ConverteMaiusculaAgendamento(char *str);
void LimpaBufferAgendamento();
int ObtemInteiroValidoAgendamento(int n);

int LeArquivoAgendamento(Agendamento * pnt_registroAgendamento);
void ImprimeAgendamento(Agendamento * pnt_registroAgendamento, int tam);

void MenuBuscaAgendamento();
void MenuAtualizaAgendamento();

void RegistraAgendamento(Cliente * pnt_cadastroCliente, Barber * pnt_cadastroBarber, Agendamento * pnt_registroAgendamento);
void ListaAgendamento(Agendamento * pnt_registroAgendamento);
void BuscaAgendamento(Agendamento * pnt_registroAgendamento);
void RemoveAgendamento(Agendamento * pnt_registroAgendamento);
void ApagaSistemaAgendamento(Agendamento  * pnt_registroAgendamento);



int ValidaDataFutura(int dia, int mes, int ano, int hora, int minuto)
{
    int dias_mes[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    time_t tempo;
    struct tm *data_atual;

    time(&tempo);
    data_atual = localtime(&tempo);

    int ano_atual = data_atual->tm_year + 1900;
    int mes_atual = data_atual->tm_mon + 1;
    int dia_atual = data_atual->tm_mday;
    int hora_atual = data_atual->tm_hour;
    int minuto_atual = data_atual->tm_min;

    // valida mes
    if(mes < 1 || mes > 12)
        return 0;

    // ano bissexto
    if((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
        dias_mes[1] = 29;

    // valida dia
    if(dia < 1 || dia > dias_mes[mes-1])
        return 0;

    // valida hora
    if(hora < 0 || hora > 23)
        return 0;

    // valida minuto
    if(minuto < 0 || minuto > 59)
        return 0;

    // verifica se é data futura
    if(ano < ano_atual)
        return 0;

    if(ano == ano_atual && mes < mes_atual)
        return 0;

    if(ano == ano_atual && mes == mes_atual && dia < dia_atual)
        return 0;

    if(ano == ano_atual && mes == mes_atual && dia == dia_atual && hora < hora_atual)
        return 0;

    if(ano == ano_atual && mes == mes_atual && dia == dia_atual && hora == hora_atual && minuto <= minuto_atual)
        return 0;

    return 1;
}

void LimpaStringAgendamento(char *str)
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

void ConverteMaiusculaAgendamento(char *str)
{
    while (*str)
	{
        *str = toupper((unsigned char)*str);
        str++;
    }
}

void LimpaBufferAgendamento()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // apenas descarta os caracteres restantes
    }
}

int ObtemInteiroValidoAgendamento(int n)
{
    //int n;
    int resultado;

    while (1) {
        resultado = scanf("%d", &n);

        if (resultado == 1) {
            LimpaBufferAgendamento(); // limpa o '\n' e o que sobrou
            return n;
        } else {
            printf("\nEntrada inválida!\a\n\n");
			printf("Tente novamente: ");
            LimpaBufferAgendamento(); // descarta entrada inválida
        }
    }
}


int LeArquivoAgendamento(Agendamento * pnt_registroAgendamento)
{
	FILE *pont_agendamento;
	int y = 0;
	pont_agendamento = fopen("agendamento.txt", "r");

    if(pont_agendamento == NULL)
    {
        printf("Erro ao abrir agendamento.txt\n");
        return 0;
    }

	while(fscanf(pont_agendamento,"%d\n%d\n%[^\n]\n%d\n%[^\n]\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
								&pnt_registroAgendamento[y].registro,
								&pnt_registroAgendamento[y].idCliente,
								pnt_registroAgendamento[y].nomeCliente,
								&pnt_registroAgendamento[y].idBarber,
								pnt_registroAgendamento[y].nomeBarber,
								&pnt_registroAgendamento[y].data_hora_agendamento.tm_mday,
								&pnt_registroAgendamento[y].data_hora_agendamento.tm_mon,
								&pnt_registroAgendamento[y].data_hora_agendamento.tm_year,
								&pnt_registroAgendamento[y].data_hora_agendamento.tm_hour,
								&pnt_registroAgendamento[y].data_hora_agendamento.tm_min,
								&pnt_registroAgendamento[y].data_hora_agendamento.tm_sec,
								&pnt_registroAgendamento[y].dia,
								&pnt_registroAgendamento[y].mes,
								&pnt_registroAgendamento[y].ano,
								&pnt_registroAgendamento[y].hora,
								&pnt_registroAgendamento[y].minuto) != EOF)
	{
		y++;
	}

	fclose(pont_agendamento);
	return y;
}

void ImprimeAgendamento(Agendamento * pnt_registroAgendamento, int tam)
{
	int i = 0;
	int agendamentos_exibidos = 0;
	
	if(tam > 0)
	{
		printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
		printf("║ DIA AGENDADO │ HORA AGENDADA │ ID  │           NOME DO CLIENTE            │ ID  │           NOME DO BARBER             │    DATA    │    HORA    │   REGISTRO   ║\n");
		printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
	}
	for(i = 0; i < tam; i++)
	{
		
		if(i % 2 == 0)
		{
			printf("║\x1b[36m    %02d/%02d/%04d\x1b[0m│\x1b[36m          %02d:%02d\x1b[0m│\x1b[36m%5d\x1b[0m│\x1b[36m%38s\x1b[0m│\x1b[36m%5d\x1b[0m│\x1b[36m%38s\x1b[0m│\x1b[36m  %02d/%02d/%04d\x1b[0m│\x1b[36m    %02d:%02d:%02d\x1b[0m│         \x1b[36m%05d\x1b[0m║\n",
						pnt_registroAgendamento[i].dia,
						pnt_registroAgendamento[i].mes,
						pnt_registroAgendamento[i].ano,
						pnt_registroAgendamento[i].hora,
						pnt_registroAgendamento[i].minuto,		
						pnt_registroAgendamento[i].idCliente,
						pnt_registroAgendamento[i].nomeCliente,
						pnt_registroAgendamento[i].idBarber,
						pnt_registroAgendamento[i].nomeBarber,
						pnt_registroAgendamento[i].data_hora_agendamento.tm_mday,
						pnt_registroAgendamento[i].data_hora_agendamento.tm_mon,
						pnt_registroAgendamento[i].data_hora_agendamento.tm_year,
						pnt_registroAgendamento[i].data_hora_agendamento.tm_hour,
						pnt_registroAgendamento[i].data_hora_agendamento.tm_min,
						pnt_registroAgendamento[i].data_hora_agendamento.tm_sec,
						pnt_registroAgendamento[i].registro);
			printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
			agendamentos_exibidos++;
		}
		else
		{
			printf("║    %02d/%02d/%04d│          %02d:%02d│%5d│%38s│%5d│%38s│  %02d/%02d/%04d│    %02d:%02d:%02d│         %05d║\n",
						pnt_registroAgendamento[i].dia,
						pnt_registroAgendamento[i].mes,
						pnt_registroAgendamento[i].ano,
						pnt_registroAgendamento[i].hora,
						pnt_registroAgendamento[i].minuto,		
						pnt_registroAgendamento[i].idCliente,
						pnt_registroAgendamento[i].nomeCliente,
						pnt_registroAgendamento[i].idBarber,
						pnt_registroAgendamento[i].nomeBarber,
						pnt_registroAgendamento[i].data_hora_agendamento.tm_mday,
						pnt_registroAgendamento[i].data_hora_agendamento.tm_mon,
						pnt_registroAgendamento[i].data_hora_agendamento.tm_year,
						pnt_registroAgendamento[i].data_hora_agendamento.tm_hour,
						pnt_registroAgendamento[i].data_hora_agendamento.tm_min,
						pnt_registroAgendamento[i].data_hora_agendamento.tm_sec,
						pnt_registroAgendamento[i].registro);
			printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
			agendamentos_exibidos++;
		}
		
		if(agendamentos_exibidos % 10 == 0 && agendamentos_exibidos != 0)
		{
			printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
			printf("\nAperte qualquer tecla para continuar a lista de agendamentos... \n\n");
			
			system("pause > nul");
			printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
			printf("║ DIA AGENDADO │ HORA AGENDADA │ ID  │           NOME DO CLIENTE            │ ID  │           NOME DO BARBER             │    DATA    │    HORA    │   REGISTRO   ║\n");
			printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");

			agendamentos_exibidos = 0;
		}
		
	}
	if(tam > 0)
	{
		printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
		printf("\nLISTAGEM CONCLUIDA\n\n");
	}
}


void MenuBuscaAgendamento()
{
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("║                 BUSCAR AGENDAMENTO                ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                                   ║\n");
	printf("║        Buscar por ID do CLIENTE --------- 1       ║\n");
	printf("║        Buscar por NOME do CLIENTE ------- 2       ║\n");
	printf("║                                                   ║\n");
	printf("║        Buscar por ID do BARBER ---------- 3       ║\n");
	printf("║        Buscar por NOME do BARBER -------- 4       ║\n");
	printf("║                                                   ║\n");
	printf("║        Buscar por DATA ------------------ 5       ║\n");
	printf("║                                                   ║\n");
	printf("║        Voltar ao MENU INICIAL ----------- 0       ║\n");
	printf("║                                                   ║\n");
	printf("╚═══════════════════════════════════════════════════╝\n\n");
}

void MenuAtualizaAgendamento()
{
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("║                ATUALIZAR AGENDAMENTO              ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                                   ║\n");
	printf("║          Atualizar CLIENTE ------------ 1         ║\n");
	printf("║          Atualizar BARBER ------------- 2         ║\n");
	printf("║          Atualizar DATA/HORA ---------- 3         ║\n");
	printf("║                                                   ║\n");
	printf("║          Voltar ao MENU INICIAL ------- 0         ║\n");
	printf("║                                                   ║\n");
	printf("╚═══════════════════════════════════════════════════╝\n\n");
}


void RegistraAgendamento(Cliente * pnt_cadastroCliente, Barber * pnt_cadastroBarber, Agendamento * pnt_registroAgendamento)
{
	FILE *pont_agendamento;
	FILE *pont_cliente;
	FILE *pont_barber;

	int registro_agendamento = 1;
	char nome_cliente[40];
	char nome_barber[40];
	int cliente_encontrado = 0;
	int barber_encontrado = 0;
	int clientes_exibidos = 0;
	int barbers_exibidos = 0;
	int id_cliente = 0;
	int id_barber = 0;
	int nova_busca_cliente = 0;
	int nova_busca_barber = 0;
	int dia = 0;
	int mes = 0;
	int ano = 0;
	int hora = 0;
	int minuto = 0;
	
	int op = 0;
	int t = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int k = 1;
	int y = 0;

	int registro = 0;
	
	system("cls");
	
	y = LeArquivoAgendamento(pnt_registroAgendamento);
	
	//Obtendo o numero de id para auto incremento
	//registro_agendamento = pnt_registroAgendamento[y-1].registro + 1;
	
	pont_agendamento = fopen("agendamento.txt","a");
				
	if(pont_agendamento == NULL)
	{
		printf("ERRO! O arquivo nao foi aberto!\n\n");
	}
	else
	{
		printf("\n");
		printf("\nREGISTRO DE AGENDAMENTOS\n");
		printf("--------------------\n\n");	
		printf("Informe quantos AGENDAMENTOS deseja registrar: ");
		
		registro = ObtemInteiroValidoAgendamento(registro);
		
		pont_cliente = fopen("cliente.txt","r");	
	
		if(pont_cliente == NULL)
		{
			printf("Erro ao abrir cliente.txt\n");
			return;
		}
		
		while(fscanf(pont_cliente,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n",
									&pnt_cadastroCliente[c].id,
									pnt_cadastroCliente[c].nome,
									pnt_cadastroCliente[c].cpf,
									pnt_cadastroCliente[c].telefone) != EOF)
		{
			c++;
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

		//INCERCAO FUNCOES ATENDIMENTO
			
		if(y == 0)
			registro_agendamento = 1;
		else
			registro_agendamento = pnt_registroAgendamento[y-1].registro + 1;

		for(int i = 0; i < registro; i++)
		{
			//INCERSAO FUNÇOES ATENDIMENTO	
			do{

				system("cls");
				
				t = 0;
				cliente_encontrado = 0;
				
				printf("\nREGISTRO DE AGENDAMENTOS\n");
				printf("-------------------\n\n");
				
				printf("Informe o NOME do cliente: ");
				scanf(" %[^\n]",nome_cliente);
				LimpaStringAtendimento(nome_cliente);
				ConverteMaiusculaAtendimento(nome_cliente);
				
				if (pont_cliente == NULL)
				{
					strcpy(nome_cliente, "CLIENTE NAO IDENTIFICADO");
				}
				
				for(int i = 0; i < c; i++)
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
				
				for(int i = 0; i < c; i++)
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
					printf("╚══════════════════════════════════════════════════════════════════╝\n");
					printf("\nBUSCA CONCLUIDA\n\n");
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
							printf("\nDigite uma opcao valida!\n\n");
							printf("Continuar busca - 1 | Encerrar busca - 2\n");
							op = ObtemInteiroValidoAtendimento(op);
						}while(op < 1 || op > 2);
				}
				
			}while(op != 2);		
				
			do{
					
				printf("\nInforme o ID do cliente: ");
				id_cliente = ObtemInteiroValidoAtendimento(id_cliente);
					
				for(int i = 0; i < c; i++)
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
						printf("Cliente NAO IDENTIFICADO - 0\n\n");
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
									printf("Cliente NAO IDENTIFICADO - 0\n\n");
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
								printf("Confirmar cliente - 1 | Continuar busca - 2 | Cliente NAO IDENTIFICADO - 0 ");	
								op = ObtemInteiroValidoAtendimento(op);
							}while(op < 1 || op > 2);
					}
				}
			
			}while(!cliente_encontrado);
			
			t = 0;
			
			system("cls");
			
			do{
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
					printf("╚══════════════════════════════════════════════════════════════════╝\n");
					printf("\nBUSCA CONCLUIDA\n\n");
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
							printf("\nDigite uma opcao valida!\n\n");
							printf("Continuar busca - 1 | Encerrar busca - 2\n");
							op = ObtemInteiroValidoAtendimento(op);
						}while(op < 1 || op > 2);
				}

			}while(op != 2);		
				
			do{
						
				printf("\nInforme o ID do barber: ");
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
						printf("Barber NAO IDENTIFICADO - 0\n\n");
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
									printf("Barber NAO IDENTIFICADO - 0\n\n");
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
								printf("Confirmar barber - 1 | Continuar busca - 2 | Barber NAO IDENTIFICADO - 0 ");	
								op = ObtemInteiroValidoAtendimento(op);
							}while(op < 1 || op > 2);
					}
				}
				
			}while(!barber_encontrado);


	
	
			time_t tempo_bruto; // Variável para armazenar o tempo em segundos
			struct tm *info_tempo; // Ponteiro para a estrutura que armazena data/hora detalhada

			//Obter o tempo bruto atual do sistema
			time(&tempo_bruto); // ou tempo_bruto = time(NULL);

			//Converter o tempo bruto para a hora local (localtime)
			info_tempo = localtime(&tempo_bruto);

			pnt_registroAgendamento[a].data_hora_agendamento.tm_mday = info_tempo->tm_mday;
			pnt_registroAgendamento[a].data_hora_agendamento.tm_mon = info_tempo->tm_mon + 1; // Meses são de 0 (janeiro) a 11 (dezembro)
			pnt_registroAgendamento[a].data_hora_agendamento.tm_year = info_tempo->tm_year + 1900; // Anos são contados a partir de 1900
			pnt_registroAgendamento[a].data_hora_agendamento.tm_hour = info_tempo->tm_hour;
			pnt_registroAgendamento[a].data_hora_agendamento.tm_min = info_tempo->tm_min;
			pnt_registroAgendamento[a].data_hora_agendamento.tm_sec = info_tempo->tm_sec;

			
			system("cls");
			printf("\nREGISTRO DE AGENDAMENTOS\n");
			printf("-------------------\n\n");

			do{	
				printf("Informe a DATA e HORÁRIO em que o cliente será atendido:\n\n");
				printf("DIA: ");
				dia = ObtemInteiroValidoAtendimento(dia);
				printf("MES: ");
				mes = ObtemInteiroValidoAtendimento(mes);
				printf("ANO: ");
				ano = ObtemInteiroValidoAtendimento(ano);
				printf("HORA: ");
				hora = ObtemInteiroValidoAtendimento(hora);
				printf("MINUTO: ");
				minuto = ObtemInteiroValidoAtendimento(minuto);

				if(!dataValida(dia, mes, ano))
				{
					system("cls");
					printf("\nBUSCA DE ATENDIMENTO\n");
					printf("-------------------------\n\n");
					printf("\a\033[31mData invalida! Tente novamente.\033[0m\n\n");
				}

				if(!ValidaDataFutura(dia, mes, ano, hora, minuto))
				{
					system("cls");
					printf("\nBUSCA DE ATENDIMENTO\n");
					printf("-------------------------\n\n");
					printf("\a\033[31mData e horário invalidos! Tente novamente.\033[0m\n\n");
				}

			}while(!dataValida(dia, mes, ano) || !ValidaDataFutura(dia, mes, ano, hora, minuto));

			pnt_registroAgendamento[a].dia     = dia;
			pnt_registroAgendamento[a].mes     = mes;
			pnt_registroAgendamento[a].ano     = ano;
			pnt_registroAgendamento[a].hora    = hora;
			pnt_registroAgendamento[a].minuto  = minuto;

			fprintf(pont_agendamento,"%d\n%d\n%s\n%d\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
									registro_agendamento,
									id_cliente,
									nome_cliente,
									id_barber,
									nome_barber,
									pnt_registroAgendamento[a].data_hora_agendamento.tm_mday,
									pnt_registroAgendamento[a].data_hora_agendamento.tm_mon,
									pnt_registroAgendamento[a].data_hora_agendamento.tm_year,
									pnt_registroAgendamento[a].data_hora_agendamento.tm_hour,
									pnt_registroAgendamento[a].data_hora_agendamento.tm_min,
									pnt_registroAgendamento[a].data_hora_agendamento.tm_sec,
									pnt_registroAgendamento[a].dia,
									pnt_registroAgendamento[a].mes,
									pnt_registroAgendamento[a].ano,
									pnt_registroAgendamento[a].hora,
									pnt_registroAgendamento[a].minuto);
			k++;
			registro_agendamento++;
		}
			
	}
	
	
	
	fclose(pont_agendamento);
	system("cls");
	printf("\n\nCADASTRO CONCLUIDO\n\n");
	printf("Aperte qualquer tecla para voltar ao MENU INICIAL...");
	system("pause > nul");
	system("cls");
}

void ListaAgendamento(Agendamento * pnt_registroAgendamento)
{
	FILE *pont_agendamento;
	int y = 0;
	
	system("cls");
	printf("\n");
	
	y = LeArquivoAgendamento(pnt_registroAgendamento);
	
	if(y > 0)
	{
		printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
		printf("║                                                                          **LISTA DE AGENDAMENTOS**                                                              ║\n");
		printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
		ImprimeAgendamento(pnt_registroAgendamento, y);
		
		printf("\nAperte qualquer tecla para voltar ao MENU INICIAL... ");
		system("pause > nul");
		system("cls");
	}
	
	else
	{
		printf("\n");
		printf("████████████████████████████████████████████████\n\a");
		printf("█                                              █\n");
		printf("█    NAO HA DADOS REGISTRADOS! ARQUIVO VAZIO   █\n");
		printf("█                                              █\n");
		printf("████████████████████████████████████████████████\n\n");
	
		printf("\nAperte qualquer tecla para voltar ao MENU INICIAL...\n\n ");
		system("pause > nul");
		system("cls");
	}
}

void BuscaAgendamento(Agendamento * pnt_registroAgendamento)
{
	FILE *pont_agendamento;
	int menu_busca = -1;
	int y = 0;
	int t = 0;
	int c;
	int id_cliente = 0;
	char nome_cliente[30];
	int id_barber = 0;
	char nome_barber[30];

	int dia_agendamento = 0;
	int mes_agendamento = 0;
	int ano_agendamento = 0;

	int op = 0;
	int agendamentos_exibidos = 0;
	
	system("cls");

	y = LeArquivoAgendamento(pnt_registroAgendamento);
	
	do{
		system("cls");
		printf("\n");
		MenuBuscaAgendamento();

		menu_busca = ObtemInteiroValidoAgendamento(menu_busca);
		
		switch(menu_busca)
		{
			case 1:			
				do{
					system("cls");
					printf("\nBUSCA DE AGENDAMENTO\n");
					printf("------------\n\n");
					printf("Informe o ID do cliente: ");
					
					id_cliente = ObtemInteiroValidoAgendamento(id_cliente);
					
					printf("\n");
						
					t = 0;
					
					for(int i = 0; i < y; i++)
					{	
						if(pnt_registroAgendamento[i].idCliente == id_cliente)
						{
							printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                                             **BUSCA DE AGENDAMENTO POR ID DE CLIENTE**                                                          ║\n");
							printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
							printf("║ DIA AGENDADO │ HORA AGENDADA │ ID  │           NOME DO CLIENTE            │ ID  │           NOME DO BARBER             │    DATA    │    HORA    │   REGISTRO   ║\n");
							printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								break;
						}
					}
					
					
					for(int i = 0; i < y; i++)
					{	
						if(pnt_registroAgendamento[i].idCliente == id_cliente)
						{
							if(agendamentos_exibidos % 2 == 0)
							{
								printf("║\x1b[36m    %02d/%02d/%04d\x1b[0m│\x1b[36m        %02d:%02d\x1b[0m│\x1b[36m%5d\x1b[0m│\x1b[36m%38s\x1b[0m│\x1b[36m%5d\x1b[0m│\x1b[36m%38s\x1b[0m│  \x1b[36m%02d/%02d/%04d\x1b[0m│    \x1b[36m%02d:%02d:%02d\x1b[0m│         \x1b[36m%05d\x1b[0m║\n",
													pnt_registroAgendamento[i].dia,
													pnt_registroAgendamento[i].mes,
													pnt_registroAgendamento[i].ano,
													pnt_registroAgendamento[i].hora,
													pnt_registroAgendamento[i].minuto,
													pnt_registroAgendamento[i].idCliente,
													pnt_registroAgendamento[i].nomeCliente,
													pnt_registroAgendamento[i].idBarber,
													pnt_registroAgendamento[i].nomeBarber,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_mday,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_mon,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_year,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_hour,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_min,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_sec,
													pnt_registroAgendamento[i].registro);
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								agendamentos_exibidos++;
							}
							else
							{
								printf("║    %02d/%02d/%04d│        %02d:%02d│%5d│%38s│%5d│%38s│  %02d/%02d/%04d│    %02d:%02d:%02d│         %05d║\n",
													pnt_registroAgendamento[i].dia,
													pnt_registroAgendamento[i].mes,
													pnt_registroAgendamento[i].ano,
													pnt_registroAgendamento[i].hora,
													pnt_registroAgendamento[i].minuto,				
													pnt_registroAgendamento[i].idCliente,
													pnt_registroAgendamento[i].nomeCliente,
													pnt_registroAgendamento[i].idBarber,
													pnt_registroAgendamento[i].nomeBarber,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_mday,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_mon,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_year,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_hour,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_min,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_sec,
													pnt_registroAgendamento[i].registro);
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								agendamentos_exibidos++;
							}
									
							if(agendamentos_exibidos % 10 == 0 && agendamentos_exibidos != 0)
							{
								printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
								printf("\nAperte qualquer tecla para continuar a lista de agendamentos... \n\n");
										
								system("pause > nul");
								printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
								printf("║ DIA AGENDADO │ HORA AGENDADA │ ID  │           NOME DO CLIENTE            │ ID  │           NOME DO BARBER             │    DATA    │    HORA    │   REGISTRO   ║\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								agendamentos_exibidos = 0;
							}
									
							t = 1;
						}	
					}
					
					agendamentos_exibidos = 0;
					
					if(t == 1)
					{
						printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
						printf("BUSCA CONCLUIDA\n\n");
					}
					
					if(t == 0)
					{
						printf("\n███████████████████████████████████████\n\a");
						printf("█                                     █\n");
						printf("█     AGENDAMENTO NAO REGISTRADO!     █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n\n");	
					}
					printf("Continuar busca - 1 | Voltar ao MENU - 2 ");
					menu_busca = ObtemInteiroValidoAgendamento(menu_busca);
									
					switch (menu_busca)
					{
						case 1:
						break;
						case 2:
						break;
						default:
							do{
								printf("\nDigite uma opcao valida\n\n");
								printf("Continuar busca - 1 | Voltar ao MENU - 2 ");
								menu_busca = ObtemInteiroValidoAgendamento(menu_busca);
								
							}while(menu_busca < 1 || menu_busca > 2);
					}	
						
					printf("\n");
					t = 0;
				}while(menu_busca != 2);
			break;
			case 2:		
				do{
					system("cls");
					printf("\nBUSCA DE AGENDAMENTO\n");
					printf("--------------\n\n");
					printf("Informe o NOME do cliente: ");
					scanf(" %[^\n]", nome_cliente);
					LimpaStringAgendamento(nome_cliente);
					// Converter a unidade para maiúsculas para garantir que a comparação não seja sensível a maiúsculas/minúsculas
					ConverteMaiusculaAgendamento(nome_cliente);	
					
					printf("\n");
					
					t = 0;
					
					for(int i = 0; i < y; i++)
					{	
						if(strstr(pnt_registroAgendamento[i].nomeCliente, nome_cliente) != NULL)
						{
							printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                                         **BUSCA DE AGENDAMENTO POR NOME DE CLIENTE**                                                            ║\n");
							printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
							printf("║ DIA AGENDADO │ HORA AGENDADA │ ID  │           NOME DO CLIENTE            │ ID  │           NOME DO BARBER             │    DATA    │    HORA    │   REGISTRO   ║\n");
							printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");							
							break;
						}
					}
					
					for(int i = 0; i < y; i++)
					{	
						if(strstr(pnt_registroAgendamento[i].nomeCliente, nome_cliente) != NULL)
						{
							if(agendamentos_exibidos % 2 == 0)
							{
								printf("║\x1b[36m    %02d/%02d/%04d\x1b[0m│\x1b[36m        %02d:%02d\x1b[0m│\x1b[36m%5d\x1b[0m│\x1b[36m%38s\x1b[0m│\x1b[36m%5d\x1b[0m│\x1b[36m%38s\x1b[0m│  \x1b[36m%02d/%02d/%04d\x1b[0m│    \x1b[36m%02d:%02d:%02d\x1b[0m│         \x1b[36m%05d\x1b[0m║\n",
													pnt_registroAgendamento[i].dia,
													pnt_registroAgendamento[i].mes,
													pnt_registroAgendamento[i].ano,
													pnt_registroAgendamento[i].hora,
													pnt_registroAgendamento[i].minuto,
													pnt_registroAgendamento[i].idCliente,
													pnt_registroAgendamento[i].nomeCliente,
													pnt_registroAgendamento[i].idBarber,
													pnt_registroAgendamento[i].nomeBarber,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_mday,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_mon,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_year,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_hour,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_min,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_sec,
													pnt_registroAgendamento[i].registro);
							printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");							
								agendamentos_exibidos++;
							}
							else
							{
								printf("║    %02d/%02d/%04d│        %02d:%02d│%5d│%38s│%5d│%38s│  %02d/%02d/%04d│    %02d:%02d:%02d│         %05d║\n",
													pnt_registroAgendamento[i].dia,
													pnt_registroAgendamento[i].mes,
													pnt_registroAgendamento[i].ano,
													pnt_registroAgendamento[i].hora,
													pnt_registroAgendamento[i].minuto,				
													pnt_registroAgendamento[i].idCliente,
													pnt_registroAgendamento[i].nomeCliente,
													pnt_registroAgendamento[i].idBarber,
													pnt_registroAgendamento[i].nomeBarber,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_mday,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_mon,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_year,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_hour,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_min,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_sec,
													pnt_registroAgendamento[i].registro);
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");							
								agendamentos_exibidos++;
							}
							
							if(agendamentos_exibidos % 10 == 0 && agendamentos_exibidos != 0)
							{
								printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
								printf("\nAperte qualquer tecla para continuar a lista de agendamentos... \n\n");
								
								system("pause > nul");
								printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
								printf("║ DIA AGENDADO │ HORA AGENDADA │ ID  │           NOME DO CLIENTE            │ ID  │           NOME DO BARBER             │    DATA    │    HORA    │   REGISTRO   ║\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								agendamentos_exibidos = 0;
							}
							
							t = 1;
						}	
					}
					
					agendamentos_exibidos = 0;
					
					if(t == 1)
					{
						printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
						printf("BUSCA CONCLUIDA\n\n");
					}
					
					if(t == 0)
					{
						printf("\n███████████████████████████████████████\n\a");
						printf("█                                     █\n");
						printf("█     AGENDAMENTO NAO REGISTRADO!     █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n\n");	
					}
					printf("Continuar busca - 1 | Voltar ao MENU - 2 ");
					menu_busca = ObtemInteiroValidoAgendamento(menu_busca);
									
					switch (menu_busca)
					{
						case 1:
						break;
						case 2:
						break;
						default:
							do{
								printf("\nDigite uma opcao valida\n\n");
								printf("Continuar busca - 1 | Voltar ao MENU - 2 ");
								menu_busca = ObtemInteiroValidoAgendamento(menu_busca);
								
							}while(menu_busca < 1 || menu_busca > 2);
					}	
					printf("\n");
					t = 0;
				}while(menu_busca != 2);
			break;
			case 3:			
				do{
					system("cls");
					printf("\nBUSCA DE AGENDAMENTO\n");
					printf("-------------\n\n");
					printf("Informe o ID do barber: ");
					
					id_barber = ObtemInteiroValidoAgendamento(id_barber);
						
					printf("\n");
						
					t = 0;

					for(int i = 0; i < y; i++)
					{	
						if(pnt_registroAgendamento[i].idBarber == id_barber)
						{
							printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                                          **BUSCA DE AGENDAMENTO POR ID DE BARBER**                                                              ║\n");
							printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
							printf("║ DIA AGENDADO │ HORA AGENDADA │ ID  │           NOME DO CLIENTE            │ ID  │           NOME DO BARBER             │    DATA    │    HORA    │   REGISTRO   ║\n");
							printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");							
							break;
						}
							
					}
					
					for(int i = 0; i < y; i++)
					{	
						if(pnt_registroAgendamento[i].idBarber == id_barber)
						{
							if(agendamentos_exibidos % 2 == 0)
							{
								printf("║\x1b[36m    %02d/%02d/%04d\x1b[0m│\x1b[36m        %02d:%02d\x1b[0m│\x1b[36m%5d\x1b[0m│\x1b[36m%38s\x1b[0m│\x1b[36m%5d\x1b[0m│\x1b[36m%38s\x1b[0m│  \x1b[36m%02d/%02d/%04d\x1b[0m│    \x1b[36m%02d:%02d:%02d\x1b[0m│         \x1b[36m%05d\x1b[0m║\n",
													pnt_registroAgendamento[i].dia,
													pnt_registroAgendamento[i].mes,
													pnt_registroAgendamento[i].ano,
													pnt_registroAgendamento[i].hora,
													pnt_registroAgendamento[i].minuto,
													pnt_registroAgendamento[i].idCliente,
													pnt_registroAgendamento[i].nomeCliente,
													pnt_registroAgendamento[i].idBarber,
													pnt_registroAgendamento[i].nomeBarber,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_mday,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_mon,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_year,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_hour,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_min,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_sec,
													pnt_registroAgendamento[i].registro);
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");							
								agendamentos_exibidos++;
							}
							else
							{
								printf("║    %02d/%02d/%04d│        %02d:%02d│%5d│%38s│%5d│%38s│  %02d/%02d/%04d│    %02d:%02d:%02d│         %05d║\n",
													pnt_registroAgendamento[i].dia,
													pnt_registroAgendamento[i].mes,
													pnt_registroAgendamento[i].ano,
													pnt_registroAgendamento[i].hora,
													pnt_registroAgendamento[i].minuto,				
													pnt_registroAgendamento[i].idCliente,
													pnt_registroAgendamento[i].nomeCliente,
													pnt_registroAgendamento[i].idBarber,
													pnt_registroAgendamento[i].nomeBarber,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_mday,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_mon,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_year,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_hour,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_min,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_sec,
													pnt_registroAgendamento[i].registro);
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");							
								agendamentos_exibidos++;
							}
							
							if(agendamentos_exibidos % 10 == 0 && agendamentos_exibidos != 0)
							{
								printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
								printf("\nAperte qualquer tecla para continuar a lista de clientes... \n\n");
								system("pause > nul");
								printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
								printf("║ DIA AGENDADO │ HORA AGENDADA │ ID  │           NOME DO CLIENTE            │ ID  │           NOME DO BARBER             │    DATA    │    HORA    │   REGISTRO   ║\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								agendamentos_exibidos = 0;
							}
							
							t = 1;
						}	
					}
					
					agendamentos_exibidos = 0;
					
					if(t == 1)
					{
						printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
						printf("BUSCA CONCLUIDA\n\n");
					}
					
					if(t == 0)
					{
						printf("\n███████████████████████████████████████\n\a");
						printf("█                                     █\n");
						printf("█     AGENDAMENTO NAO REGISTRADO!     █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n\n");	
					}
					printf("Continuar busca - 1 | Voltar ao MENU - 2 ");
					menu_busca = ObtemInteiroValidoAgendamento(menu_busca);
					
					switch (menu_busca)
					{
						case 1:
						break;
						case 2:
						break;
						default:
							do{
								printf("\nDigite uma opcao valida\n\n");
								printf("Continuar busca - 1 | Voltar ao MENU - 2 ");
								menu_busca = ObtemInteiroValidoAgendamento(menu_busca);
								
							}while(menu_busca < 1 || menu_busca > 2);
					}	
					printf("\n");
					t = 0;
				}while(menu_busca != 2);
			break;
			case 4:
				do{
					system("cls");
					printf("\nBUSCA DE AGENDAMENTO\n");
					printf("--------------\n\n");
					printf("Informe o NOME do barber: ");
					scanf(" %[^\n]", nome_barber);
					LimpaStringAgendamento(nome_barber);
					// Converter a unidade para maiúsculas para garantir que a comparação não seja sensível a maiúsculas/minúsculas
					ConverteMaiusculaAgendamento(nome_barber);	
						
					printf("\n");
						
					t = 0;
						
					for(int i = 0; i < y; i++)
					{	
						if(strstr(pnt_registroAgendamento[i].nomeBarber, nome_barber) != NULL)
						{
							printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                                         **BUSCA DE AGENDAMENTO POR NOME DE BARBER**                                                             ║\n");
							printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
							printf("║ DIA AGENDADO │ HORA AGENDADA │ ID  │           NOME DO CLIENTE            │ ID  │           NOME DO BARBER             │    DATA    │    HORA    │   REGISTRO   ║\n");
							printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");							
							
							break;
						}
					}
					
					for(int i = 0; i < y; i++)
					{	
						if(strstr(pnt_registroAgendamento[i].nomeBarber, nome_barber) != NULL)
						{
							if(agendamentos_exibidos % 2 == 0)
							{
								printf("║\x1b[36m    %02d/%02d/%04d\x1b[0m│\x1b[36m        %02d:%02d\x1b[0m│\x1b[36m%5d\x1b[0m│\x1b[36m%38s\x1b[0m│\x1b[36m%5d\x1b[0m│\x1b[36m%38s\x1b[0m│  \x1b[36m%02d/%02d/%04d\x1b[0m│    \x1b[36m%02d:%02d:%02d\x1b[0m│         \x1b[36m%05d\x1b[0m║\n",
													pnt_registroAgendamento[i].dia,
													pnt_registroAgendamento[i].mes,
													pnt_registroAgendamento[i].ano,
													pnt_registroAgendamento[i].hora,
													pnt_registroAgendamento[i].minuto,
													pnt_registroAgendamento[i].idCliente,
													pnt_registroAgendamento[i].nomeCliente,
													pnt_registroAgendamento[i].idBarber,
													pnt_registroAgendamento[i].nomeBarber,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_mday,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_mon,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_year,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_hour,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_min,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_sec,
													pnt_registroAgendamento[i].registro);
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								agendamentos_exibidos++;
							}
							else
							{
								printf("║    %02d/%02d/%04d│        %02d:%02d│%5d│%38s│%5d│%38s│  %02d/%02d/%04d│    %02d:%02d:%02d│         %05d║\n",
													pnt_registroAgendamento[i].dia,
													pnt_registroAgendamento[i].mes,
													pnt_registroAgendamento[i].ano,
													pnt_registroAgendamento[i].hora,
													pnt_registroAgendamento[i].minuto,				
													pnt_registroAgendamento[i].idCliente,
													pnt_registroAgendamento[i].nomeCliente,
													pnt_registroAgendamento[i].idBarber,
													pnt_registroAgendamento[i].nomeBarber,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_mday,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_mon,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_year,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_hour,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_min,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_sec,
													pnt_registroAgendamento[i].registro);
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								agendamentos_exibidos++;
							}
							
							if(agendamentos_exibidos % 10 == 0 && agendamentos_exibidos != 0)
							{
								printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
								printf("\nAperte qualquer tecla para continuar a lista de agendamentos... \n\n");
								
								system("pause > nul");
								printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
								printf("║ DIA AGENDADO │ HORA AGENDADA │ ID  │           NOME DO CLIENTE            │ ID  │           NOME DO BARBER             │    DATA    │    HORA    │   REGISTRO   ║\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								agendamentos_exibidos = 0;
							}
								
							t = 1;
						}	
					}
						
					agendamentos_exibidos = 0;
					
					if(t == 1)
					{
						printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
						printf("BUSCA CONCLUIDA\n\n");
					}
					
					if(t == 0)
					{
						printf("\n███████████████████████████████████████\n\a");
						printf("█                                     █\n");
						printf("█     AGENDAMENTO NAO REGISTRADO!     █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n\n");	
					}
					printf("Continuar busca - 1 | Voltar ao MENU - 2 ");
					menu_busca = ObtemInteiroValidoAgendamento(menu_busca);
									
					switch (menu_busca)
					{
						case 1:
						break;
						case 2:
						break;
						default:
							do{
								printf("\nDigite uma opcao valida\n\n");
								printf("Continuar busca - 1 | Voltar ao MENU - 2 ");
								menu_busca = ObtemInteiroValidoAgendamento(menu_busca);
								
							}while(menu_busca < 1 || menu_busca > 2);
						}	
					printf("\n");
					t = 0;
				}while(menu_busca != 2);
			break;
			case 5:		
				system("cls");

				printf("\nBUSCA DE AGENDAMENTO\n");
				printf("-------------\n\n");
				
				do{	
					printf("Informe o dia: ");
					dia_agendamento = ObtemInteiroValidoAgendamento(dia_agendamento);
					printf("Informe o mes: ");
					mes_agendamento = ObtemInteiroValidoAgendamento(mes_agendamento);
					printf("Informe o ano: ");
					ano_agendamento = ObtemInteiroValidoAgendamento(ano_agendamento);
	
					if(!dataValida(dia_agendamento, mes_agendamento, ano_agendamento))
					{
						system("cls");
						printf("\nBUSCA DE ATENDIMENTO\n");
						printf("-------------------------\n\n");
						printf("\a\033[31mData invalida! Tente novamente.\033[0m\n\n");
					}

				}while(!dataValida(dia_agendamento, mes_agendamento, ano_agendamento));
				
				printf("\n");
				t = 0;

				do{

					for(int i = 0; i < y; i++)
					{	
						if(dia_agendamento == pnt_registroAgendamento[i].data_hora_agendamento.tm_mday 
						&& mes_agendamento == pnt_registroAgendamento[i].data_hora_agendamento.tm_mon
						&& ano_agendamento == pnt_registroAgendamento[i].data_hora_agendamento.tm_year
						&& dataValida(dia_agendamento, mes_agendamento, ano_agendamento) == 1)
						{
							printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                                                  **BUSCA DE AGENDAMENTO POR DATA**                                                              ║\n");
							printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
							printf("║ DIA AGENDADO │ HORA AGENDADA │ ID  │           NOME DO CLIENTE            │ ID  │           NOME DO BARBER             │    DATA    │    HORA    │   REGISTRO   ║\n");
							printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							break;
						}
								
					}
						
					for(int i = 0; i < y; i++)
					{	
						if(dia_agendamento == pnt_registroAgendamento[i].data_hora_agendamento.tm_mday 
						&& mes_agendamento == pnt_registroAgendamento[i].data_hora_agendamento.tm_mon
						&& ano_agendamento == pnt_registroAgendamento[i].data_hora_agendamento.tm_year
						&& dataValida(dia_agendamento, mes_agendamento, ano_agendamento) == 1)
						{
							if(agendamentos_exibidos % 2 == 0)
							{
								printf("║\x1b[36m    %02d/%02d/%04d\x1b[0m│\x1b[36m        %02d:%02d\x1b[0m│\x1b[36m%5d\x1b[0m│\x1b[36m%38s\x1b[0m│\x1b[36m%5d\x1b[0m│\x1b[36m%38s\x1b[0m│  \x1b[36m%02d/%02d/%04d\x1b[0m│    \x1b[36m%02d:%02d:%02d\x1b[0m│         \x1b[36m%05d\x1b[0m║\n",
													pnt_registroAgendamento[i].dia,
													pnt_registroAgendamento[i].mes,
													pnt_registroAgendamento[i].ano,
													pnt_registroAgendamento[i].hora,
													pnt_registroAgendamento[i].minuto,
													pnt_registroAgendamento[i].idCliente,
													pnt_registroAgendamento[i].nomeCliente,
													pnt_registroAgendamento[i].idBarber,
													pnt_registroAgendamento[i].nomeBarber,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_mday,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_mon,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_year,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_hour,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_min,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_sec,
													pnt_registroAgendamento[i].registro);
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								agendamentos_exibidos++;
							}
							else
							{
								printf("║    %02d/%02d/%04d│        %02d:%02d│%5d│%38s│%5d│%38s│  %02d/%02d/%04d│    %02d:%02d:%02d│         %05d║\n",
													pnt_registroAgendamento[i].dia,
													pnt_registroAgendamento[i].mes,
													pnt_registroAgendamento[i].ano,
													pnt_registroAgendamento[i].hora,
													pnt_registroAgendamento[i].minuto,				
													pnt_registroAgendamento[i].idCliente,
													pnt_registroAgendamento[i].nomeCliente,
													pnt_registroAgendamento[i].idBarber,
													pnt_registroAgendamento[i].nomeBarber,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_mday,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_mon,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_year,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_hour,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_min,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_sec,
													pnt_registroAgendamento[i].registro);
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								agendamentos_exibidos++;
							}
							
							if(agendamentos_exibidos % 10 == 0 && agendamentos_exibidos != 0)
							{
								printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
								printf("\nAperte qualquer tecla para continuar a lista de clientes... \n\n");
								system("pause > nul");
								printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
								printf("║ DIA AGENDADO │ HORA AGENDADA │ ID  │           NOME DO CLIENTE            │ ID  │           NOME DO BARBER             │    DATA    │    HORA    │   REGISTRO   ║\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								agendamentos_exibidos = 0;
							}
								
							t = 1;
						}	
					}
						
					agendamentos_exibidos = 0;
					
					if(t == 1)
					{
						printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
						printf("BUSCA CONCLUIDA\n\n");
					}
					
					if(t == 0)
					{
						printf("\n███████████████████████████████████████\n\a");
						printf("█                                     █\n");
						printf("█     AGENDAMENTO NAO REGISTRADO!     █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n\n");	
					}
					printf("Continuar busca - 1 | Voltar ao MENU - 2 ");
					menu_busca = ObtemInteiroValidoAgendamento(menu_busca);
					
					switch (menu_busca)
					{
						case 1:
						break;
						case 2:
						break;
						default:
							do{
								printf("\nDigite uma opcao valida\n\n");
								printf("Continuar busca - 1 | Voltar ao MENU - 2 ");
								menu_busca = ObtemInteiroValidoAgendamento(menu_busca);
								
							}while(menu_busca < 1 || menu_busca > 2);
					}	
						
					printf("\n");
					t = 0;
				}while(menu_busca != 2);
			break;
			case 0:
				system("cls");
			break;
			default:
				//do{
					system("cls");
					printf("\n");
					MenuBuscaAgendamento();
					//printf("\aDigite uma opcao valida\n");
					//menu_busca = ObtemInteiroValidoAgendamento(menu_busca);
				//}while(menu_busca < 0 || menu_busca > 5);
		}	
	}while(menu_busca != 0);		
	system("cls");
}

void RemoveAgendamento(Agendamento * pnt_registroAgendamento)
{
	FILE *pont_agendamento;
	int menu_remove = 0;
	int y = 0;
	int r = 0;
	int registro_agendamento = 0;
	
	system("cls");
	
	y = LeArquivoAgendamento(pnt_registroAgendamento);
	
	pont_agendamento = fopen("agendamento.txt","w");
	printf("\nREMOVER AGENDAMENTO\n");
	printf("---------------\n\n");
	printf("Informe o REGISTRO do agendamento a ser removido: ");
	
	registro_agendamento = ObtemInteiroValidoAgendamento(registro_agendamento);
	printf("\n");
	do{
		for(int i = 0; i < y; i++)
		{
			if(pnt_registroAgendamento[i].registro == registro_agendamento)
			{
				printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
				printf("║                                                                     **AGENDAMENTO ENCONTRADO**                                                                  ║\n");
				printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
				printf("║ DIA AGENDADO │ HORA AGENDADA │ ID  │           NOME DO CLIENTE            │ ID  │           NOME DO BARBER             │    DATA    │    HORA    │   REGISTRO   ║\n");
				printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
				printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
				printf("║\x1b[36m    %02d/%02d/%04d\x1b[0m│\x1b[36m        %02d:%02d\x1b[0m│\x1b[36m%5d\x1b[0m│\x1b[36m%38s\x1b[0m│\x1b[36m%5d\x1b[0m│\x1b[36m%38s\x1b[0m│  \x1b[36m%02d/%02d/%04d\x1b[0m│    \x1b[36m%02d:%02d:%02d\x1b[0m│         \x1b[36m%05d\x1b[0m║\n",
													pnt_registroAgendamento[i].dia,
													pnt_registroAgendamento[i].mes,
													pnt_registroAgendamento[i].ano,
													pnt_registroAgendamento[i].hora,
													pnt_registroAgendamento[i].minuto,
													pnt_registroAgendamento[i].idCliente,
													pnt_registroAgendamento[i].nomeCliente,
													pnt_registroAgendamento[i].idBarber,
													pnt_registroAgendamento[i].nomeBarber,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_mday,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_mon,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_year,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_hour,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_min,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_sec,
													pnt_registroAgendamento[i].registro);
				printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
				printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
			
				printf("\nRemover agendamento - 1 | Cancelar remoção - 2\n");
				menu_remove = ObtemInteiroValidoAgendamento(menu_remove);
				switch (menu_remove)
				{
					case 1:			
						r = 1;
					break;
					case 2:
						fprintf(pont_agendamento,"%d\n%d\n%s\n%d\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
													pnt_registroAgendamento[i].registro,
													pnt_registroAgendamento[i].idCliente,
													pnt_registroAgendamento[i].nomeCliente,
													pnt_registroAgendamento[i].idBarber,
													pnt_registroAgendamento[i].nomeBarber,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_mday,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_mon,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_year,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_hour,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_min,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_sec,
													pnt_registroAgendamento[i].dia,
													pnt_registroAgendamento[i].mes,
													pnt_registroAgendamento[i].ano,
													pnt_registroAgendamento[i].hora,
													pnt_registroAgendamento[i].minuto);
													
						r = -1;
					break;
					default:
						printf("\nDigite uma opcao valida\n\n");
				}
					
			}
			
			if(pnt_registroAgendamento[i].registro != registro_agendamento)
			{
				fprintf(pont_agendamento,"%d\n%d\n%s\n%d\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
													pnt_registroAgendamento[i].registro,
													pnt_registroAgendamento[i].idCliente,
													pnt_registroAgendamento[i].nomeCliente,
													pnt_registroAgendamento[i].idBarber,
													pnt_registroAgendamento[i].nomeBarber,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_mday,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_mon,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_year,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_hour,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_min,
													pnt_registroAgendamento[i].data_hora_agendamento.tm_sec,
													pnt_registroAgendamento[i].dia,
													pnt_registroAgendamento[i].mes,
													pnt_registroAgendamento[i].ano,
													pnt_registroAgendamento[i].hora,
													pnt_registroAgendamento[i].minuto);
			}
			
		}
		if(r == 0)
		{
			printf("\n");
			printf("███████████████████████████████████████\n\a");
			printf("█                                     █\n");
			printf("█     AGENDAMENTO NAO ENCONTRADO!     █\n");
			printf("█                                     █\n");
			printf("███████████████████████████████████████\n\n");
			printf("Aperte qualquer tecla para voltar ao MENU INICIAL...");
			system("pause > nul");
			system("cls");
			break;
		}
		else if(r == 1)
		{
			system("cls");
			printf("\n\nAGENDAMENTO REMOVIDO\n\n");
			printf("Aperte qualquer tecla para voltar ao MENU INICIAL...");
			system("pause > nul");
			system("cls");
		}
		else if(r == -1)
		{
			r = 1;
			system("cls");
			printf("\n\nREMOCAO CANCELADA\n\n");
			printf("Aperte qualquer tecla para voltar ao MENU INICIAL...");
			system("pause > nul");
			system("cls");
		}
		
	}while(r != 1);
	
	fclose(pont_agendamento);
}

void ApagaSistemaAgendamento(Agendamento  * pnt_registroAgendamento)
{
	FILE * pont_atendimento;
	int op = -1;
	system("cls");
	
	printf("\n████████████████████████████████████████████████████████████████████████\n\a");
	printf("█                                                                      █\n");
	printf("█   \033[31mATENÇÃO!\033[0m Todos os AGENDAMENTOS do sistema serão apagados...   █\n");
	printf("█                                                                      █\n");
	printf("████████████████████████████████████████████████████████████████████████\n\n");
	
	printf("Confirmar - 1 | Cancelar - 0\n");
	op = ObtemInteiroValidoAtendimento(op);
	switch(op)
	{
		case 1:
			pont_atendimento = fopen("atendimento.txt","w");
			if(pont_atendimento != NULL)
			{
				fprintf(pont_atendimento,"%s","");
				fclose(pont_atendimento);
				system("cls");
				printf("\nREGISTRO DE AGENDAMENTOS DELETADO\n\n");
				printf("Aperte qualquer tecla para voltar ao MENU INICIAL...\n\n");
				system("pause > nul");
				system("cls");
				
			}	
			else
			{
				system("cls");
				printf("\n\nO registro de agendamentos NAO FOI APAGAGO...\n\n");
				printf("ERRO ao acessar o arquivo! Contate o administrador do sistema\n\n");
				printf("Aperte qualquer tecla para voltar ao MENU INICIAL...\n\n");
				system("pause > nul");
				system("cls");
			}
			break;
			case 0:
				system("cls");
				printf("\n\nACAO CANCELADA\n\n");
				printf("Aperte qualquer tecla para voltar ao MENU INICIAL...\n\n");
				system("pause > nul");
				system("cls");
			break;	
			default:
				printf("\aDigite uma opcao valida!");
	}
}