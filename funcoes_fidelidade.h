
void MenuBuscaFidelidade();

int LeArquivoFidelidade(Fidelidade * pnt_registroFidelidade);
void ImprimeFidelidade(Fidelidade * pnt_registroFidelidade, int tam);
void ImprimeFidelidadeID(Fidelidade *pnt_registroFidelidade, int tam, int idProcurado);
void ListaFidelidade(Fidelidade * pnt_registroFidelidade);
void BuscaFidelidade(Fidelidade * pnt_registroFidelidade);



void MenuBuscaFidelidade()
{
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("║                  BUSCAR FIDELIDADE                ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                                   ║\n");
	printf("║        Buscar por ID DE CLIENTE --------- 1       ║\n");
	printf("║        Buscar por NOME DE CLIENTE ------- 2       ║\n");
	printf("║                                                   ║\n");
	printf("║        Voltar ao MENU INICIAL ----------- 0       ║\n");
	printf("║                                                   ║\n");
	printf("╚═══════════════════════════════════════════════════╝\n\n");
}


int LeArquivoFidelidade(Fidelidade * pnt_registroFidelidade)
{
	FILE *pont_fidelidade;
	int f = 0;
	pont_fidelidade = fopen("fidelidade.txt", "r");

    if(pont_fidelidade == NULL)
    {
        printf("Erro ao abrir fidelidade.txt\n");
        return 0;
    }
	
	while(fscanf(pont_fidelidade,"%d\n%[^\n]\n%d\n%d\n",
				
									 &pnt_registroFidelidade[f].idCliente,
									 pnt_registroFidelidade[f].nomeCliente,
									 &pnt_registroFidelidade[f].servicosAcumulados,
									 &pnt_registroFidelidade[f].bonusUsados) != EOF)
	{
		f++;
	}
	
	fclose(pont_fidelidade);
	return f;
}

void ImprimeFidelidade(Fidelidade * pnt_registroFidelidade, int tam)
{
	int i = 0;
	int clientes_exibidos = 0;
	int id_cliente = 0;
	int soma_servicos = 0;
	int bonus_obtidos = 0;
	int bonus_usados = 0;
	int saldo = 0;
	int ja_impresso = 0;

	if(tam > 0)
	{
		printf("╠═════════════════════════════════════════════════════════════════════════════════════════════╣\n");
		printf("║ ID  │             NOME             │  SERVICOS  │  BONUS OBTIDOS │  BONUS USADOS  │  SALDO  ║\n");
		printf("╟─────────────────────────────────────────────────────────────────────────────────────────────╢\n");
	}

	for(i = 0; i < tam; i++)
	{
		ja_impresso = 0;

		// verifica se esse cliente já apareceu antes
		for(int j = 0; j < i; j++)
		{
			if(pnt_registroFidelidade[j].idCliente == pnt_registroFidelidade[i].idCliente)
			{
				ja_impresso = 1;
				break;
			}
		}

		// se já apareceu, pula para o próximo
		if(ja_impresso)
			continue;
			
		soma_servicos = 0;
		bonus_obtidos = 0;
		bonus_usados = 0;
		saldo = 0;
		id_cliente = pnt_registroFidelidade[i].idCliente;

		for(int k = 0; k < tam; k++)
		{
			if(pnt_registroFidelidade[k].idCliente == id_cliente)
			{
				soma_servicos += pnt_registroFidelidade[k].servicosAcumulados;
				bonus_usados += pnt_registroFidelidade[k].bonusUsados;
			}
		}
		
		bonus_obtidos += soma_servicos / 5;
		saldo = bonus_obtidos - bonus_usados;

		if(clientes_exibidos % 2 == 0)
		{
			printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%30s\x1b[0m│\x1b[36m%12d\x1b[0m│\x1b[36m%16d\x1b[0m│\x1b[36m%16d\x1b[0m│\x1b[36m%9d\x1b[0m║\n",
						pnt_registroFidelidade[i].idCliente,
						pnt_registroFidelidade[i].nomeCliente,
						soma_servicos,
						bonus_obtidos,
						bonus_usados,
						saldo);

			printf("╟─────────────────────────────────────────────────────────────────────────────────────────────╢\n");
			clientes_exibidos++;
		}
		else
		{
			printf("║%5d│%30s│%12d│%16d│%16d│%9d║\n",
						pnt_registroFidelidade[i].idCliente,
						pnt_registroFidelidade[i].nomeCliente,
						soma_servicos,
						bonus_obtidos,
						bonus_usados,
						saldo);
			printf("╟─────────────────────────────────────────────────────────────────────────────────────────────╢\n");
			clientes_exibidos++;
		}
		
		if(clientes_exibidos % 10 == 0 && clientes_exibidos != 0)
		{
			printf("╚═════════════════════════════════════════════════════════════════════════════════════════════╝\n");
			printf("\nAperte qualquer tecla para continuar a lista de clientes... \n\n");
			system("pause > nul");
			printf("╔═════════════════════════════════════════════════════════════════════════════════════════════╗\n");
			printf("║ ID  │             NOME             │  SERVICOS  │  BONUS OBTIDOS │  BONUS USADOS  │  SALDO  ║\n");
			printf("╟─────────────────────────────────────────────────────────────────────────────────────────────╢\n");
			printf("╟─────────────────────────────────────────────────────────────────────────────────────────────╢\n");
			clientes_exibidos = 0;
		}
		
	}
	if(tam > 0)
	{
		printf("╚═════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
		printf("\nLISTAGEM CONCLUIDA\n\n");
	}
}

void ImprimeFidelidadeID(Fidelidade *pnt_registroFidelidade, int tam, int idProcurado)
{
    int soma_servicos = 0;
    int bonus_usados = 0;
    int bonus_obtidos = 0;
    int saldo = 0;
    char nomeCliente[50] = ""; // Para guardar o nome do cliente (assumindo que todos os registros tenham o mesmo nome)
    int encontrado = 0;

    for(int i = 0; i < tam; i++)
    {
        if(pnt_registroFidelidade[i].idCliente == idProcurado)
        {
            encontrado = 1;
            soma_servicos += pnt_registroFidelidade[i].servicosAcumulados;
            bonus_usados += pnt_registroFidelidade[i].bonusUsados;

            // Assume que todos os registros para o mesmo ID têm o mesmo nome
            strcpy(nomeCliente, pnt_registroFidelidade[i].nomeCliente);
        }
    }

    if(encontrado)
    {
        bonus_obtidos = soma_servicos / 5; // regra de cálculo
        saldo = bonus_obtidos - bonus_usados;

        printf("╔═════════════════════════════════════════════════════════════════════════════════════════════╗\n");
        printf("║ ID  │             NOME             │  SERVICOS  │  BONUS OBTIDOS │  BONUS USADOS  │  SALDO  ║\n");
        printf("╠═════════════════════════════════════════════════════════════════════════════════════════════╣\n");
        printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%30s\x1b[0m│\x1b[36m%12d\x1b[0m│\x1b[36m%16d\x1b[0m│\x1b[36m%16d\x1b[0m│\x1b[36m%9d\x1b[0m║\n",
               idProcurado,
               nomeCliente,
               soma_servicos,
               bonus_obtidos,
               bonus_usados,
               saldo);
        printf("╚═════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
    }
    else
    {
        printf("\n██████████████████████████████████████████████████████\n\a");
		printf("█                                                    █\n");
		printf("█     CLIENTE NAO CONSTA NA LISTA DE FIDELIDADE!     █\n");
		printf("█                                                    █\n");
		printf("██████████████████████████████████████████████████████\n\n");	
    }
}

void ListaFidelidade(Fidelidade * pnt_registroFidelidade)
{
	FILE *pont_fidelidade;
	int f = 0;
	
	f = LeArquivoFidelidade(pnt_registroFidelidade);
	
	system("cls");
	
	if(f > 0)
	{
		printf("\n");
		printf("╔═════════════════════════════════════════════════════════════════════════════════════════════╗\n");
		printf("║                                    **LISTA DE FIDELIDADE**                                  ║\n");
		ImprimeFidelidade(pnt_registroFidelidade, f);
		printf("\nAperte qualquer tecla para voltar ao MENU INICIAL... \n\n");
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
		
		printf("\nAperte qualquer tecla para voltar ao MENU INICIAL... \n\n");
		system("pause > nul");
		system("cls");
	}
}

void BuscaFidelidade(Fidelidade * pnt_registroFidelidade)
{
	FILE *pont_fidelidade;
	int menu_busca = -1;
	int y = 0;
	int t = 0;
	int f = 0;
	int c;
	int id = 0;
	char nome[30];
	int op = 0;
	int clientes_exibidos = 0;
	int soma_servicos = 0;
	int bonus_obtidos = 0;
	int bonus_usados = 0;
	int saldo = 0;
	int ja_impresso = 0;
	
	system("cls");
	MenuBuscaFidelidade();
	f = LeArquivoFidelidade(pnt_registroFidelidade);
				
	do{
		system("cls");
		printf("\nBUSCA DE FIDELIDADE POR ID\n");
		printf("--------------------------\n\n");
		printf("Informe o ID do cliente: ");
				
		id = ObtemInteiroValidoCliente(id);
				
		printf("\n");
		
		ImprimeFidelidadeID(pnt_registroFidelidade, f, id);
					
		printf("Continuar busca - 1 | Voltar ao MENU INICIAL - 0 ");
		menu_busca = ObtemInteiroValidoCliente(menu_busca);
		switch (menu_busca)
		{
			case 1:
			break;
			case 0:
			break;
			default:
				do{
					printf("\nDigite uma opcao valida\n\n");
					printf("Continuar busca - 1 | Voltar ao MENU INICIAL - 0 ");
							menu_busca = ObtemInteiroValidoCliente(menu_busca);
				}while(menu_busca < 0 || menu_busca > 1);
		}				
		printf("\n");
		t = 0;
	}while(menu_busca != 0);

	system("cls");
}
