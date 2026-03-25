
void LimpaStringBarber(char *str);
void ConverteMaiusculaBarber(char *str);
void LimpaBufferBarber();
int ObtemInteiroValidoBarber(int n);

void MenuBarber();
void MenuBuscaBarber();
void MenuAtualizaBarber();

void ImprimeBarber(Barber * pnt_cadastroBarber, int tam);
void CadastraBarber(Barber * pnt_cadastroBarber);
void ListaBarber(Barber * pnt_cadastroBarber);
void BuscaBarber(Barber * pnt_cadastroBarber);
void AtualizaBarber(Barber  * pnt_cadastroBarber);
void RemoveBarber(Barber * pnt_cadastroBarber);
void ApagaSistemaBarber(Barber  * pnt_cadastroBarber);



void LimpaStringBarber(char *str)
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

void ConverteMaiusculaBarber(char *str)
{
    while (*str)
	{
        *str = toupper((unsigned char)*str);
        str++;
    }
}

void LimpaBufferBarber()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // apenas descarta os caracteres restantes
    }
}

int ObtemInteiroValidoBarber(int n)
{
    //int n;
    int resultado;

    while (1) {
        resultado = scanf("%d", &n);

        if (resultado == 1) {
            LimpaBufferBarber(); // limpa o '\n' e o que sobrou
            return n;
        } else {
            printf("\nEntrada inválida!\a\n\n");
			printf("Tente novamente: ");
            LimpaBufferBarber(); // descarta entrada inválida
        }
    }
}


void MenuBarber()
{
	system("chcp 65001 > nul");
	system("color 07");
	printf("\n");
	
	printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
	printf("║                                        *** B E M - V I N D O ***                                      ║\n");
	printf("║                             G E R E N C I A M E N T O   D E   V E N D A S                             ║\n");
	printf("╠═══════════════════════════════════════════════════╦═══════════════════════════════════════════════════╣\n");
	printf("║               CADASTRO DE CLIENTES                ║                REGISTRO DE PEDIDOS                ║\n");
	printf("╠═══════════════════════════════════════════════════╬═══════════════════════════════════════════════════╣\n");
	printf("║                                        *CONSULTAR ║                                        *CONSULTAR ║\n");
	printf("║                                                   ║                                                   ║\n");
	printf("║     Listar CLIENTES ----------------------- 1     ║     Listar ESTOQUE ------------------------ 8     ║\n");
	printf("║     Filtrar e ordenar CLIENTES ------------ 2     ║	  Filtrar e ordenar ESTOQUE ------------- 9     ║\n");
	printf("║     Buscar CLIENTE ------------------------ 3     ║	  Buscar no ESTOQUE --------------------- 10    ║\n");
	printf("║                                                   ║                                                   ║\n");
	printf("╠═══════════════════════════════════════════════════╣     Listar PEDIDOS ------------------------ 11    ║\n");
	printf("║                                                   ║     Buscar PEDIDO ------------------------- 12    ║\n");
	printf("║                                       **CADASTRAR ║                                                   ║\n");
	printf("║                                                   ╠═══════════════════════════════════════════════════╣\n");
	printf("║                                                   ║                                       **REGISTRAR ║\n");
	printf("║     Cadastrar CLIENTES -------------------- 4     ║                                                   ║\n");
	printf("║     Atualizar cadastro de CLIENTES -------- 5     ║     Registrar PEDIDO ---------------------- 13    ║\n");
	printf("║                                                   ║                                                   ║\n");
	printf("╠═══════════════════════════════════════════════════╬═══════════════════════════════════════════════════╣\n");
	printf("║                                        ***DELETAR ║                                        ***DELETAR ║\n");
	printf("║                                                   ║                                                   ║\n");
	printf("║     Remover CLIENTE ----------------------- 6     ║     Deletar PEDIDO ------------------------ 14    ║\n");
	printf("║     Apagar TODOS os dados de CLIENTES ----- 7     ║     Apagar TODOS os PEDIDOS --------------- 15    ║\n");
	printf("║                                                   ║                                                   ║\n");
	printf("╠═══════════════════════════════════════════════════╩═══════════════════════════════════════════════════╣\n");
	printf("║                                                       * Opções que nao alteram o banco de dados       ║\n");
	printf("║     Encerrar SISTEMA  --------------------- 0         ** Opcoes que alteram o banco de dados          ║\n");
	printf("║                                                       *** Alteracoes irreversiveis no banco de dados  ║\n");
	printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
}

void MenuBuscaBarber()
{
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("║                   BUSCAR BARBER                   ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                                   ║\n");
	printf("║          Buscar por ID --------------- 1          ║\n");
	printf("║          Buscar por NOME ------------- 2          ║\n");
	printf("║          Buscar por CPF -------------- 3          ║\n");
	printf("║                                                   ║\n");
	printf("║          Voltar ao MENU INICIAL ------ 0          ║\n");
	printf("║                                                   ║\n");
	printf("╚═══════════════════════════════════════════════════╝\n\n");
}

void MenuAtualizaBarber()
{
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("║           ATUALIZAR CADASTRO DE BARBERS           ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                                   ║\n");
	printf("║          Atualizar NOME --------------- 1         ║\n");
	printf("║          Atualizar CPF ---------------- 2         ║\n");
	printf("║          Atualizar TELEFONE ----------- 3         ║\n");
	printf("║                                                   ║\n");
	printf("║          Voltar ao MENU INICIAL ------- 0         ║\n");
	printf("║                                                   ║\n");
	printf("╚═══════════════════════════════════════════════════╝\n\n");
}


void ImprimeBarber(Barber * pnt_cadastroBarber, int tam)
{
	int i = 0;
	int barbers_exibidos = 0;
	
	if(tam > 0)
	{
		printf("╠══════════════════════════════════════════════════════════════════╣\n");
		printf("║ COD │          NOME          │       CPF       │     TELEFONE    ║\n");
		printf("╟──────────────────────────────────────────────────────────────────╢\n");
	}
	for(i = 0; i < tam; i++)
	{
		
		if(i % 2 == 0)
		{
			printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%24s\x1b[0m│\x1b[36m%17s\x1b[0m│\x1b[36m%17s\x1b[0m║\n",
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
	if(tam > 0)
	{
		printf("╚══════════════════════════════════════════════════════════════════╝\n\n");
		printf("\nLISTAGEM CONCLUIDA\n\n");
	}
}

void CadastraBarber(Barber * pnt_cadastroBarber)
{
	FILE *pont_barber;
	int k = 1;
	int y = 0;
	int id = 0;
	int cadastro = 0;
	
	system("cls");
	
	pont_barber = fopen("barber.txt","r");
	
	if(pont_barber == NULL)
	{
		printf("Erro ao abrir barber.txt\n");
		return;
	}
	
	while(fscanf(pont_barber,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n",
							&pnt_cadastroBarber[y].id,
							pnt_cadastroBarber[y].nome,
							pnt_cadastroBarber[y].cpf,
							pnt_cadastroBarber[y].telefone) != EOF)
	{
		y++;
	}
	fclose(pont_barber);
	
	//Obtendo o numero de id para auto incremento
	id = pnt_cadastroBarber[y-1].id + 1;
	
	pont_barber = fopen("barber.txt","a");
				
	if(pont_barber == NULL)
	{
		printf("ERRO! O arquivo nao foi aberto!\n\n");
	}
	else
	{
		printf("\n");
		printf("\nCADASTRO DE BARBERS\n");
		printf("--------------------\n\n");	
		printf("Informe quantos BARBERS deseja cadastrar: ");
		
		cadastro = ObtemInteiroValidoBarber(cadastro);
		
		for(int i = 0; i < cadastro; i++)
		{
		
			printf("\nInforme o NOME COMPLETO do barber 0%d : ",k);
			scanf(" %[^\n]",pnt_cadastroBarber[i].nome);
			
			// Limpar a string, remover espaços extras antes e depois
			LimpaStringBarber(pnt_cadastroBarber[i].nome);
			// Converter a unidade para maiúsculas
			ConverteMaiusculaBarber(pnt_cadastroBarber[i].nome);
			
			printf("Informe o CPF do barber 0%d : ",k);
			scanf(" %[^\n]",pnt_cadastroBarber[i].cpf);
				
			
			printf("Informe o TELEFONE do barber 0%d : ",k);
			scanf(" %[^\n]",pnt_cadastroBarber[i].telefone);
		
			printf("\n");	
			
			fprintf(pont_barber,"%d\n%s\n%s\n%s\n",
						id,
						pnt_cadastroBarber[i].nome,
						pnt_cadastroBarber[i].cpf,
						pnt_cadastroBarber[i].telefone);
			k++;
			id++;
		}
			
	}
	fclose(pont_barber);
	system("cls");
	printf("\n\nCADASTRO CONCLUIDO\n\n");
	printf("Aperte qualquer tecla para voltar ao MENU INICIAL...");
	system("pause > nul");
	system("cls");
}
	
void ListaBarber(Barber * pnt_cadastroBarber)
{
	FILE *pont_barber;
	int y = 0;
	
	system("cls");
	printf("\n");
	
	pont_barber = fopen("barber.txt","r");
	
	while(fscanf(pont_barber,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n",
							&pnt_cadastroBarber[y].id,
							pnt_cadastroBarber[y].nome,
							pnt_cadastroBarber[y].cpf,
							pnt_cadastroBarber[y].telefone) != EOF)
	{
		y++;
	}
	
	fclose(pont_barber);	
	
	if(y > 0)
	{
		printf("╔══════════════════════════════════════════════════════════════════╗\n");
		printf("║                       **LISTA DE BARBERS**                       ║\n");
		printf("╠══════════════════════════════════════════════════════════════════╣\n");
		ImprimeBarber(pnt_cadastroBarber, y);
		
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

void BuscaBarber(Barber * pnt_cadastroBarber)
{
	FILE *pont_barber;
	int menu_busca = -1;
	int y = 0;
	int t = 0;
	int c;
	int id = 0;
	char nome[30];
	char cpf[15];
	int op = 0;
	int barbers_exibidos = 0;
	
	system("cls");
	pont_barber = fopen("barber.txt","r");
	while(fscanf(pont_barber,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n",
							&pnt_cadastroBarber[y].id,
							pnt_cadastroBarber[y].nome,
							pnt_cadastroBarber[y].cpf,
							pnt_cadastroBarber[y].telefone) != EOF)
	{
		y++;
	}	
	
	do{
		system("cls");
		printf("\n");
		MenuBuscaBarber();
		menu_busca = ObtemInteiroValidoBarber(menu_busca);
		switch(menu_busca)
		{
			case 1:			
				do{
					system("cls");
					printf("\nBUSCA POR ID\n");
					printf("------------\n\n");
					printf("Informe o ID do barber: ");
					
					id = ObtemInteiroValidoBarber(id);
					
					printf("\n");
						
					t = 0;
					
					for(int i = 0; i < y; i++)
					{	
						if(pnt_cadastroBarber[i].id == id)
						{
							printf("╔══════════════════════════════════════════════════════════════════╗\n");
							printf("║                     **BUSCA DE BARBER POR ID**                   ║\n");
							printf("╠══════════════════════════════════════════════════════════════════╣\n");
							printf("║ COD │          NOME          │       CPF       │     TELEFONE    ║\n");
							printf("╟──────────────────────────────────────────────────────────────────╢\n");
							printf("╟──────────────────────────────────────────────────────────────────╢\n");
							printf("║%5d│\033[32m%24s\033[0m│%17s│%17s║\n",
										pnt_cadastroBarber[i].id,
										pnt_cadastroBarber[i].nome,
										pnt_cadastroBarber[i].cpf,
										pnt_cadastroBarber[i].telefone);
							printf("╟──────────────────────────────────────────────────────────────────╢\n");
							printf("╚══════════════════════════════════════════════════════════════════╝\n\n");
							printf("BUSCA CONCLUIDA\n\n");
								t = 1;
						}	
					}
					
					if(t == 0)
					{
						printf("\n███████████████████████████████████████\n\a");
						printf("█                                     █\n");
						printf("█        BARBER NAO CADASTRADO!       █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n\n");	
					}
					
					printf("Continuar busca - 1 | Voltar ao menu - 2 ");
					menu_busca = ObtemInteiroValidoBarber(menu_busca);
					switch (menu_busca)
					{
						case 1:
						break;
						case 2:
						break;
						default:
							do{
							printf("\nDigite uma opcao valida\n\n");
							printf("Continuar busca - 1 | Voltar ao menu - 2 ");
							menu_busca = ObtemInteiroValidoBarber(menu_busca);
							}while(menu_busca < 1 || menu_busca > 2);
					}	
					printf("\n");
					t = 0;
				}while(menu_busca != 2);
			break;
			case 2:		
				do{
					system("cls");
					printf("\nBUSCA POR NOME\n");
					printf("--------------\n\n");
					printf("Informe o NOME do barber: ");
					scanf(" %[^\n]", nome);
					LimpaStringBarber(nome);
					// Converter a unidade para maiúsculas para garantir que a comparação não seja sensível a maiúsculas/minúsculas
					ConverteMaiusculaBarber(nome);	
					
					printf("\n");
					
					t = 0;
					
					for(int i = 0; i < y; i++)
					{	
						if(strstr(pnt_cadastroBarber[i].nome, nome) != NULL)
						{
							printf("╔══════════════════════════════════════════════════════════════════╗\n");
							printf("║                    **BUSCA DE BARBER POR NOME**                  ║\n");
							printf("╠══════════════════════════════════════════════════════════════════╣\n");
							printf("║ COD │          NOME          │       CPF       │     TELEFONE    ║\n");
							printf("╟──────────────────────────────────────────────────────────────────╢\n");
							printf("╟──────────────────────────────────────────────────────────────────╢\n");
							break;
						}
					}
					
					for(int i = 0; i < y; i++)
					{	
						if(strstr(pnt_cadastroBarber[i].nome, nome) != NULL)
						{
							//if(i % 2 == 0)
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
							
							t = 1;
						}	
					}
					
					barbers_exibidos = 0;
					
					if(t == 1)
					{
						printf("╚══════════════════════════════════════════════════════════════════╝\n\n");
						printf("BUSCA CONCLUIDA\n\n");
					}
					
					if(t == 0)
					{
						printf("\n███████████████████████████████████████\n\a");
						printf("█                                     █\n");
						printf("█        BARBER NAO CADASTRADO!       █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n\n");	
					}
					printf("Continuar busca - 1 | Voltar ao menu - 2 ");
					menu_busca = ObtemInteiroValidoBarber(menu_busca);
									
					switch (menu_busca)
					{
						case 1:
						break;
						case 2:
						break;
						default:
							do{
								printf("\nDigite uma opcao valida\n\n");
								printf("Continuar busca - 1 | Voltar ao menu - 2 ");
								menu_busca = ObtemInteiroValidoBarber(menu_busca);
								
							}while(menu_busca < 1 || menu_busca > 2);
						}	
						printf("\n");
						t = 0;
					}while(menu_busca != 2);
					
			break;
			case 3:			
				do{
					system("cls");
					printf("\nBUSCA POR CPF\n");
					printf("-------------\n\n");
					printf("Informe o CPF do barber: ");
					scanf(" %[^\n]", cpf);
						
					printf("\n");
						
					t = 0;
					
					for(int i = 0; i < y; i++)
					{	
						if(strstr(pnt_cadastroBarber[i].cpf, cpf) != NULL)
						{	
							printf("╔══════════════════════════════════════════════════════════════════╗\n");
							printf("║                    **BUSCA DE BARBER POR CPF**                   ║\n");
							printf("╠══════════════════════════════════════════════════════════════════╣\n");
							printf("║ COD │          NOME          │       CPF       │     TELEFONE    ║\n");
							printf("╟──────────────────────────────────────────────────────────────────╢\n");
							printf("╟──────────────────────────────────────────────────────────────────╢\n");
							break;
						}
					}
					
					for(int i = 0; i < y; i++)
					{	
						if(strstr(pnt_cadastroBarber[i].cpf, cpf) != NULL)
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
							
							t = 1;
						}	
					}
					
					barbers_exibidos = 0;
					
					if(t == 1)
					{
						printf("╚══════════════════════════════════════════════════════════════════╝\n\n");
						printf("BUSCA CONCLUIDA\n\n");
					}
					
					if(t == 0)
					{
						printf("\n███████████████████████████████████████\n\a");
						printf("█                                     █\n");
						printf("█        BARBER NAO CADASTRADO!       █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n\n");	
					}
					printf("Continuar busca - 1 | Voltar ao menu - 2 ");
					menu_busca = ObtemInteiroValidoCliente(menu_busca);
					
					switch (menu_busca)
					{
						case 1:
						break;
						case 2:
						break;
						default:
							do{
								printf("\nDigite uma opcao valida\n\n");
								printf("Continuar busca - 1 | Voltar ao menu - 2 ");
								menu_busca = ObtemInteiroValidoBarber(menu_busca);
								
							}while(menu_busca < 1 || menu_busca > 2);
					}	
					
					printf("\n");
					t = 0;
					
				}while(menu_busca != 2);
				
			break;
		}	
	}while(menu_busca != 0);		
	fclose(pont_barber);
	system("cls");
	
	
}

void AtualizaBarber(Barber * pnt_cadastroBarber)
{
	FILE *pont_barber;
	int menu_atualiza = 0;
	char nome[30];
	char cpf[15];
	char telefone[15];
	int y = 0;
	int a = 0;
	int r = 0;
	char s;
	int id = 0;
	y = 0;
	
	do{
		a = 0;
		system("cls");
		printf("\n");
		MenuAtualizaBarber();
		
		menu_atualiza = ObtemInteiroValidoBarber(menu_atualiza);
		
		system("cls");	
		
		switch(menu_atualiza)
		{
			case 1:
				y = 0;
				system("cls");
				pont_barber = fopen("barber.txt","r");		
				if(pont_barber == NULL)
				{
					printf("\nERRO! O arquivo nao foi aberto!\n\n");
				}
				else
				{
					printf("\nO arquivo foi aberto com sucesso\n\n");
					while(fscanf(pont_barber,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n",
												&pnt_cadastroBarber[y].id,
												pnt_cadastroBarber[y].nome,
												pnt_cadastroBarber[y].cpf,
												pnt_cadastroBarber[y].telefone) != EOF)
					{
						y++;
					}
					
					fclose(pont_barber);
					printf("ATUALIZAR NOME\n");
					printf("--------------\n\n");
					printf("Informe o ID do barber: ");
					id = ObtemInteiroValidoBarber(id);
					printf("\n");
					do{
						for(int i = 0; i < y; i++)
						{	
							if(pnt_cadastroBarber[i].id == id)
							{
								printf("\n");
								printf("ID: %d\n",pnt_cadastroBarber[i].id);
								printf("Nome: %s\n",pnt_cadastroBarber[i].nome);
								printf("CPF: %s\n",pnt_cadastroBarber[i].cpf);
								printf("Telefone: %s\n\n",pnt_cadastroBarber[i].telefone);
								printf("Informe o NOVO NOME COMPLETO: ");
								scanf(" %[^\n]",nome);
								LimpaStringBarber(nome);
								ConverteMaiusculaBarber(nome);
								strcpy(pnt_cadastroBarber[i].nome, nome);
								printf("\n");
								printf("╔══════════════════════════════════════════════════════════════════╗\n");
								printf("║                       **CADASTRO ATUALIZADO**                    ║\n");
								printf("╠══════════════════════════════════════════════════════════════════╣\n");
								printf("║ COD │          NOME          │       CPF       │     TELEFONE    ║\n");
								printf("╟──────────────────────────────────────────────────────────────────╢\n");
								printf("║%5d│\033[32m%24s\033[0m│%17s│%17s║\n",
											pnt_cadastroBarber[i].id,
											pnt_cadastroBarber[i].nome,
											pnt_cadastroBarber[i].cpf,
											pnt_cadastroBarber[i].telefone);
								printf("╚══════════════════════════════════════════════════════════════════╝\n");
								printf("\nAperte qualquer tecla para voltar ao MENU... \n\n");
								system("pause > nul");
								system("cls");
								a = 1;
							}
						}
						if(a == 0)
						{
							printf("███████████████████████████████████████\n\a");
							printf("█                                     █\n");
							printf("█        BARBER NAO ENCONTRADO!       █\n");
							printf("█                                     █\n");
							printf("███████████████████████████████████████\n");
							printf("\nAperte qualquer tecla para voltar ao MENU... \n\n");
							system("pause > nul");
							a = 1;
						}

					}while(a != 1);	
					pont_barber = fopen("barber.txt","w");	
					for(int i = 0; i < y; i++)
					{
						fprintf(pont_barber,"%d\n%s\n%s\n%s\n",
											pnt_cadastroBarber[i].id,
											pnt_cadastroBarber[i].nome,
											pnt_cadastroBarber[i].cpf,
											pnt_cadastroBarber[i].telefone);
					}					
					y = 0;
					fclose(pont_barber);	
				}
			break;
			case 2:
				y = 0;
				system("cls");				
				pont_barber = fopen("barber.txt","r");		
				if(pont_barber == NULL)
				{
					printf("\nERRO! O arquivo nao foi aberto!\n\n");
				}
				else
				{
					printf("\nO arquivo foi aberto com sucesso\n\n");
					while(fscanf(pont_barber,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n",
												&pnt_cadastroBarber[y].id,
												pnt_cadastroBarber[y].nome,
												pnt_cadastroBarber[y].cpf,
												pnt_cadastroBarber[y].telefone) != EOF)
					{
						y++;
					}
					fclose(pont_barber);
					printf("ATUALIZAR CPF\n");
					printf("-------------\n\n");
					printf("Informe o ID do barber: ");
					id = ObtemInteiroValidoBarber(id);
					printf("\n");
					do{
						for(int i = 0; i < y; i++)
						{	
							if(pnt_cadastroBarber[i].id == id)
							{
								printf("\n");
								printf("ID: %d\n",pnt_cadastroBarber[i].id);
								printf("Nome: %s\n",pnt_cadastroBarber[i].nome);
								printf("CPF: %s\n",pnt_cadastroBarber[i].cpf);
								printf("Telefone: %s\n\n",pnt_cadastroBarber[i].telefone);
								printf("Informe o novo CPF: ");
								scanf(" %[^\n]",cpf);
								strcpy(pnt_cadastroBarber[i].cpf, cpf);
								printf("\n");
								printf("╔══════════════════════════════════════════════════════════════════╗\n");
								printf("║                       **CADASTRO ATUALIZADO**                    ║\n");
								printf("╠══════════════════════════════════════════════════════════════════╣\n");
								printf("║ COD │          NOME          │       CPF       │     TELEFONE    ║\n");
								printf("╟──────────────────────────────────────────────────────────────────╢\n");
								printf("║%5d│%24s│\033[32m%17s\033[0m│%17s║\n",
											pnt_cadastroBarber[i].id,
											pnt_cadastroBarber[i].nome,
											pnt_cadastroBarber[i].cpf,
											pnt_cadastroBarber[i].telefone);
								printf("╚══════════════════════════════════════════════════════════════════╝\n");
								printf("\nAperte qualquer tecla para voltar ao MENU... ");
								system("pause > nul");
								system("cls");
								a = 1;
							}
							
						}
						if(a == 0)
						{
							printf("███████████████████████████████████████\n\a");
							printf("█                                     █\n");
							printf("█        BARBER NAO ENCONTRADO!       █\n");
							printf("█                                     █\n");
							printf("███████████████████████████████████████\n");
							printf("\nAperte qualquer tecla para voltar ao MENU... \n\n");
							system("pause > nul");
							a = 1;
						}
								
					}while(a != 1);	
					pont_barber = fopen("barber.txt","w");	
					for(int i = 0; i < y; i++)
					{
						fprintf(pont_barber,"%d\n%s\n%s\n%s\n",
											pnt_cadastroBarber[i].id,
											pnt_cadastroBarber[i].nome,
											pnt_cadastroBarber[i].cpf,
											pnt_cadastroBarber[i].telefone);
					}
					y = 0;				
					fclose(pont_barber);	
				}
			break;
			case 3:
				y = 0;
				system("cls");
				pont_barber = fopen("barber.txt","r");		
				if(pont_barber == NULL)
				{
					printf("\nERRO! O arquivo nao foi aberto!\n\n");
				}
				else
				{
					printf("\nO arquivo foi aberto com sucesso\n\n");
					while(fscanf(pont_barber,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n",
												&pnt_cadastroBarber[y].id,
												pnt_cadastroBarber[y].nome,
												pnt_cadastroBarber[y].cpf,
												pnt_cadastroBarber[y].telefone) != EOF)
					{
						y++;
					}
					fclose(pont_barber);
					printf("ATUALIZAR TELEFONE\n");
					printf("------------------\n\n");
					printf("Informe o ID do barber: ");
					id = ObtemInteiroValidoBarber(id);
					printf("\n");
					do{
						for(int i = 0; i < y; i++)
						{	
							if(pnt_cadastroBarber[i].id == id)
							{
								printf("\n");
								printf("ID: %d\n",pnt_cadastroBarber[i].id);
								printf("Nome: %s\n",pnt_cadastroBarber[i].nome);
								printf("CPF: %s\n",pnt_cadastroBarber[i].cpf);
								printf("Telefone: %s\n\n",pnt_cadastroBarber[i].telefone);
								printf("Informe o novo telefone: ");
								scanf(" %[^\n]",telefone);
								strcpy(pnt_cadastroBarber[i].telefone, telefone);
								printf("\n");
								printf("╔══════════════════════════════════════════════════════════════════╗\n");
								printf("║                       **CADASTRO ATUALIZADO**                    ║\n");
								printf("╠══════════════════════════════════════════════════════════════════╣\n");
								printf("║ COD │          NOME          │       CPF       │     TELEFONE    ║\n");
								printf("╟──────────────────────────────────────────────────────────────────╢\n");
								printf("║%5d│%24s│%17s│\033[32m%17s\033[0m║\n",
											pnt_cadastroBarber[i].id,
											pnt_cadastroBarber[i].nome,
											pnt_cadastroBarber[i].cpf,
											pnt_cadastroBarber[i].telefone);
								printf("╚══════════════════════════════════════════════════════════════════╝\n");
								printf("\nAperte qualquer tecla para voltar ao MENU INICIAL... \n\n");
								system("pause > nul");
								system("cls");
								a = 1;
							}
							
						}
						if(a == 0)
						{
							printf("███████████████████████████████████████\n\a");
							printf("█                                     █\n");
							printf("█        BARBER NAO ENCONTRADO!       █\n");
							printf("█                                     █\n");
							printf("███████████████████████████████████████\n");
							printf("\nAperte qualquer tecla para voltar ao MENU... \n\n");
							system("pause > nul");
							a = 1;
						}
							
					}while(a != 1);	
					pont_barber = fopen("barber.txt","w");	
					for(int i = 0; i < y; i++)
					{
						fprintf(pont_barber,"%d\n%s\n%s\n%s\n",
												pnt_cadastroBarber[i].id,
												pnt_cadastroBarber[i].nome,
												pnt_cadastroBarber[i].cpf,
												pnt_cadastroBarber[i].telefone);
					}
					y = 0;
					fclose(pont_barber);	
				}
			break;
			case 0:
			break;
			default:
				printf("\n\nDigite uma opcao valida!\n\n");
		}			
	}while(menu_atualiza != 0);	
}

void RemoveBarber(Barber * pnt_cadastroBarber)
{
	FILE *pont_barber;
	int menu_remove = 0;
	int y = 0;
	int r = 0;
	int id = 0;
	
	system("cls");
	pont_barber = fopen("barber.txt","r");	
	if(pont_barber == NULL)
	{
		printf("\nERRO! O arquivo nao foi aberto!\n\n");
	}
	else
	{
		while(fscanf(pont_barber,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n",
									&pnt_cadastroBarber[y].id,
									pnt_cadastroBarber[y].nome,
									pnt_cadastroBarber[y].cpf,
									pnt_cadastroBarber[y].telefone) != EOF)
		{
			y++;
		}
		fclose(pont_barber);	
		pont_barber = fopen("barber.txt","w");
		printf("\nREMOVER BARBER\n");
		printf("---------------\n\n");
		printf("Informe o ID do barber a ser removido: ");
		
		id = ObtemInteiroValidoBarber(id);
		printf("\n");
		do{
			for(int i = 0; i < y; i++)
			{
				if(pnt_cadastroBarber[i].id == id)
				{
					printf("╔══════════════════════════════════════════════════════════════════╗\n");
					printf("║                       **BARBER ENCONTRADO**                      ║\n");
					printf("╠══════════════════════════════════════════════════════════════════╣\n");
					printf("║ COD │          NOME          │       CPF       │     TELEFONE    ║\n");
					printf("╟──────────────────────────────────────────────────────────────────╢\n");
					printf("║%5d│\033[31m%24s\033[0m│%17s│%17s║\n",
								pnt_cadastroBarber[i].id,
								pnt_cadastroBarber[i].nome,
								pnt_cadastroBarber[i].cpf,
								pnt_cadastroBarber[i].telefone);
					printf("╚══════════════════════════════════════════════════════════════════╝\n");
				
					printf("\nRemover barber - 1 | Cancelar remoção - 2\n");
					menu_remove = ObtemInteiroValidoBarber(menu_remove);
					switch (menu_remove)
					{
						case 1:			
							r = 1;
						break;
						case 2:
							fprintf(pont_barber,"%d\n%s\n%s\n%s\n",
													pnt_cadastroBarber[i].id,
													pnt_cadastroBarber[i].nome,
													pnt_cadastroBarber[i].cpf,
													pnt_cadastroBarber[i].telefone);
							r = -1;
						break;
						default:
							printf("\nDigite uma opcao valida\n\n");
					}
						
				}
				
				if(pnt_cadastroBarber[i].id != id)
				{
					fprintf(pont_barber,"%d\n%s\n%s\n%s\n",
											pnt_cadastroBarber[i].id,
											pnt_cadastroBarber[i].nome,
											pnt_cadastroBarber[i].cpf,
											pnt_cadastroBarber[i].telefone);
				}
				
			}
			if(r == 0)
			{
				printf("\n");
				printf("███████████████████████████████████████\n\a");
				printf("█                                     █\n");
				printf("█        BARBER NAO ENCONTRADO!       █\n");
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
				printf("\n\nBARBER REMOVIDO\n\n");
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
	}
	fclose(pont_barber);
}

void ApagaSistemaBarber(Barber  * pnt_cadastroBarber)
{
	FILE * pont_barber;
	int op = -1;
	system("cls");
	
	printf("\n████████████████████████████████████████████████████████████████████████\n\a");
	printf("█                                                                      █\n");
	printf("█   \033[31mATENÇÃO!\033[0m Todos os dados de BARBERS do sistema serão apagados...    █\n");
	printf("█                                                                      █\n");
	printf("████████████████████████████████████████████████████████████████████████\n\n");
	
	printf("Confirmar - 1 | Cancelar - 0\n");
	op = ObtemInteiroValidoBarber(op);
	switch(op)
	{
		case 1:
			pont_barber = fopen("barber.txt","w");
			if(pont_barber != NULL)
			{
				fprintf(pont_barber,"%s","");
				fclose(pont_barber);
				system("cls");
				printf("\nCADASTRO DE BARBERS DELETADO\n\n");
				printf("Aperte qualquer tecla para voltar ao MENU INICIAL...\n\n");
				system("pause > nul");
				system("cls");
				
			}	
			else
			{
				system("cls");
				printf("\n\nO cadastro de barbers NAO FOI APAGAGO...\n\n");
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