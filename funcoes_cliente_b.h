
void LimpaStringCliente(char *str);
void ConverteMaiusculaCliente(char *str);
void LimpaBufferCliente();
int ObtemInteiroValidoCliente(int n);

void MenuCliente();
void MenuBuscaCliente();
void MenuAtualizaCliente();

void ImprimeCliente(Cliente * pnt_cadastroCliente, int tam);
void CadastraCliente(Cliente * pnt_cadastroCliente);
void ListaCliente(Cliente * pnt_cadastroCliente);
void BuscaCliente(Cliente * pnt_cadastroCliente);
void AtualizaCliente(Cliente  * pnt_cadastroCliente);
void RemoveCliente(Cliente * pnt_cadastroCliente);
void ApagaSistemaCliente(Cliente  * pnt_cadastroCliente);



void LimpaStringCliente(char *str)
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

void ConverteMaiusculaCliente(char *str)
{
    while (*str)
	{
        *str = toupper((unsigned char)*str);
        str++;
    }
}

void LimpaBufferCliente()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // apenas descarta os caracteres restantes
    }
}

int ObtemInteiroValidoCliente(int n)
{
    //int n;
    int resultado;

    while (1) {
        resultado = scanf("%d", &n);

        if (resultado == 1) {
            LimpaBufferCliente(); // limpa o '\n' e o que sobrou
            return n;
        } else {
            printf("\nEntrada inválida!\a\n\n");
			printf("Tente novamente: ");
            LimpaBufferCliente(); // descarta entrada inválida
        }
    }
}


void MenuCliente()
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

void MenuBuscaCliente()
{
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("║                    BUSCAR CLIENTE                 ║\n");
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

void MenuAtualizaCliente()
{
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("║           ATUALIZAR CADASTRO DE CLIENTE           ║\n");
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


void ImprimeCliente(Cliente * pnt_cadastroCliente, int tam)
{
	int i = 0;
	int clientes_exibidos = 0;
	
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
	if(tam > 0)
	{
		printf("╚══════════════════════════════════════════════════════════════════╝\n\n");
		printf("\nLISTAGEM CONCLUIDA\n\n");
	}
}

void CadastraCliente(Cliente * pnt_cadastroCliente)
{
	FILE *pont_cliente;
	int k = 1;
	int y = 0;
	int id = 0;
	int cadastro = 0;
	
	system("cls");
	
	pont_cliente = fopen("cliente.txt","r");
	while(fscanf(pont_cliente,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n",
								&pnt_cadastroCliente[y].id,
								pnt_cadastroCliente[y].nome,
								pnt_cadastroCliente[y].cpf,
								pnt_cadastroCliente[y].telefone) != EOF)
	{
		y++;
	}
	fclose(pont_cliente);
	
	//Obtendo o numero de id para auto incremento
	id = pnt_cadastroCliente[y-1].id + 1;
	
	pont_cliente = fopen("cliente.txt","a");
				
	if(pont_cliente == NULL)
	{
		printf("ERRO! O arquivo nao foi aberto!\n\n");
	}
	else
	{
		printf("\n");
		printf("\nCADASTRO DE CLIENTES\n");
		printf("--------------------\n\n");	
		printf("Informe quantos CLIENTES deseja cadastrar: ");
		
		cadastro = ObtemInteiroValidoCliente(cadastro);
		
		for(int i = 0; i < cadastro; i++)
		{
		
			printf("\nInforme o NOME COMPLETO do cliente 0%d : ",k);
			scanf(" %[^\n]",pnt_cadastroCliente[i].nome);
			
			// Limpar a string, remover espaços extras antes e depois
			LimpaStringCliente(pnt_cadastroCliente[i].nome);
			// Converter a unidade para maiúsculas
			ConverteMaiusculaCliente(pnt_cadastroCliente[i].nome);
			
			printf("Informe o CPF do cliente 0%d : ",k);
			scanf(" %[^\n]",pnt_cadastroCliente[i].cpf);
				
			
			printf("Informe o TELEFONE do cliente 0%d : ",k);
			scanf(" %[^\n]",pnt_cadastroCliente[i].telefone);
		
			printf("\n");	
			
			fprintf(pont_cliente,"%d\n%s\n%s\n%s\n",
									id,
									pnt_cadastroCliente[i].nome,
									pnt_cadastroCliente[i].cpf,
									pnt_cadastroCliente[i].telefone);
			k++;
			id++;
		}
			
	}
	fclose(pont_cliente);
	system("cls");
	printf("\n\nCADASTRO CONCLUIDO\n\n");
	printf("Aperte qualquer tecla para voltar ao MENU INICIAL...");
	system("pause > nul");
	system("cls");
}
	
void ListaCliente(Cliente * pnt_cadastroCliente)
{
	FILE *pont_cliente;
	int y = 0;
	
	system("cls");
	printf("\n");
	
	pont_cliente = fopen("cliente.txt","r");
	
	while(fscanf(pont_cliente,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n",
								&pnt_cadastroCliente[y].id,
								pnt_cadastroCliente[y].nome,
								pnt_cadastroCliente[y].cpf,
								pnt_cadastroCliente[y].telefone) != EOF)
	{
		y++;
	}
	
	fclose(pont_cliente);	
	
	if(y > 0)
	{
		printf("╔══════════════════════════════════════════════════════════════════╗\n");
		printf("║                       **LISTA DE CLIENTES**                      ║\n");
		printf("╠══════════════════════════════════════════════════════════════════╣\n");
		ImprimeCliente(pnt_cadastroCliente, y);
		
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

void BuscaCliente(Cliente * pnt_cadastroCliente)
{
	FILE *pont_cliente;
	int menu_busca = -1;
	int y = 0;
	int t = 0;
	int c;
	int id = 0;
	char nome[30];
	char cpf[15];
	int op = 0;
	int clientes_exibidos = 0;
	
	system("cls");
	pont_cliente = fopen("cliente.txt","r");
	while(fscanf(pont_cliente,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n",
								&pnt_cadastroCliente[y].id,
								pnt_cadastroCliente[y].nome,
								pnt_cadastroCliente[y].cpf,
								pnt_cadastroCliente[y].telefone) != EOF)
	{
		y++;
	}	
	
	do{
		system("cls");
		printf("\n");
		MenuBuscaCliente();
		menu_busca = ObtemInteiroValidoCliente(menu_busca);
		switch(menu_busca)
		{
			case 1:			
				do{
					system("cls");
					printf("\nBUSCA POR ID\n");
					printf("------------\n\n");
					printf("Informe o ID do cliente: ");
					
					id = ObtemInteiroValidoCliente(id);
					
					printf("\n");
						
					t = 0;
					
					for(int i = 0; i < y; i++)
					{	
						if(pnt_cadastroCliente[i].id == id)
						{
							printf("╔══════════════════════════════════════════════════════════════════╗\n");
							printf("║                     **BUSCA DE CLIENTE POR ID**                  ║\n");
							printf("╠══════════════════════════════════════════════════════════════════╣\n");
							printf("║ COD │          NOME          │       CPF       │     TELEFONE    ║\n");
							printf("╟──────────────────────────────────────────────────────────────────╢\n");
							printf("╟──────────────────────────────────────────────────────────────────╢\n");
							printf("║%5d│\033[32m%24s\033[0m│%17s│%17s║\n",
										pnt_cadastroCliente[i].id,
										pnt_cadastroCliente[i].nome,
										pnt_cadastroCliente[i].cpf,
										pnt_cadastroCliente[i].telefone);
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
						printf("█        CLIENTE NAO CADASTRADO!      █\n");
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
							menu_busca = ObtemInteiroValidoCliente(menu_busca);
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
					printf("Informe o NOME do cliente: ");
					scanf(" %[^\n]", nome);
					LimpaStringCliente(nome);
					// Converter a unidade para maiúsculas para garantir que a comparação não seja sensível a maiúsculas/minúsculas
					ConverteMaiusculaCliente(nome);	
					
					printf("\n");
					
					t = 0;
					
					for(int i = 0; i < y; i++)
					{	
						if(strstr(pnt_cadastroCliente[i].nome, nome) != NULL)
						{
							printf("╔══════════════════════════════════════════════════════════════════╗\n");
							printf("║                    **BUSCA DE CLIENTE POR NOME**                 ║\n");
							printf("╠══════════════════════════════════════════════════════════════════╣\n");
							printf("║ COD │          NOME          │       CPF       │     TELEFONE    ║\n");
							printf("╟──────────────────────────────────────────────────────────────────╢\n");
							printf("╟──────────────────────────────────────────────────────────────────╢\n");
							break;
						}
					}
					
					for(int i = 0; i < y; i++)
					{	
						if(strstr(pnt_cadastroCliente[i].nome, nome) != NULL)
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
							
							t = 1;
						}	
					}
					
					clientes_exibidos = 0;
					
					if(t == 1)
					{
						printf("╚══════════════════════════════════════════════════════════════════╝\n\n");
						printf("BUSCA CONCLUIDA\n\n");
					}
					
					if(t == 0)
					{
						printf("\n███████████████████████████████████████\n\a");
						printf("█                                     █\n");
						printf("█        CLIENTE NAO CADASTRADO!      █\n");
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
								menu_busca = ObtemInteiroValidoCliente(menu_busca);
								
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
					printf("Informe o CPF do cliente: ");
					scanf(" %[^\n]", cpf);
						
					printf("\n");
						
					t = 0;
					
					for(int i = 0; i < y; i++)
					{	
						if(strstr(pnt_cadastroCliente[i].cpf, cpf) != NULL)
						{	
							printf("╔══════════════════════════════════════════════════════════════════╗\n");
							printf("║                    **BUSCA DE CLIENTE POR CPF**                  ║\n");
							printf("╠══════════════════════════════════════════════════════════════════╣\n");
							printf("║ COD │          NOME          │       CPF       │     TELEFONE    ║\n");
							printf("╟──────────────────────────────────────────────────────────────────╢\n");
							printf("╟──────────────────────────────────────────────────────────────────╢\n");
							break;
						}
					}
					
					for(int i = 0; i < y; i++)
					{	
						if(strstr(pnt_cadastroCliente[i].cpf, cpf) != NULL)
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
							
							t = 1;
						}	
					}
					
					clientes_exibidos = 0;
					
					if(t == 1)
					{
						printf("╚══════════════════════════════════════════════════════════════════╝\n\n");
						printf("BUSCA CONCLUIDA\n\n");
					}
					
					if(t == 0)
					{
						printf("\n███████████████████████████████████████\n\a");
						printf("█                                     █\n");
						printf("█        CLIENTE NAO CADASTRADO!      █\n");
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
								menu_busca = ObtemInteiroValidoCliente(menu_busca);
								
							}while(menu_busca < 1 || menu_busca > 2);
					}	
					
					printf("\n");
					t = 0;
					
				}while(menu_busca != 2);
				
			break;
		}	
	}while(menu_busca != 0);		
	fclose(pont_cliente);
	system("cls");
	
	
}

void AtualizaCliente(Cliente * pnt_cadastroCliente)
{
	FILE *pont_cliente;
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
		MenuAtualizaCliente();
		
		menu_atualiza = ObtemInteiroValidoCliente(menu_atualiza);
		
		system("cls");	
		
		switch(menu_atualiza)
		{
			case 1:
				y = 0;
				system("cls");
				pont_cliente = fopen("cliente.txt","r");		
				if(pont_cliente == NULL)
				{
					printf("\nERRO! O arquivo nao foi aberto!\n\n");
				}
				else
				{
					printf("\nO arquivo foi aberto com sucesso\n\n");
					while(fscanf(pont_cliente,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n",
												&pnt_cadastroCliente[y].id,
												pnt_cadastroCliente[y].nome,
												pnt_cadastroCliente[y].cpf,
												pnt_cadastroCliente[y].telefone) != EOF)
					{
						y++;
					}
					
					fclose(pont_cliente);
					printf("ATUALIZAR NOME\n");
					printf("--------------\n\n");
					printf("Informe o ID do cliente: ");
					id = ObtemInteiroValidoCliente(id);
					printf("\n");
					do{
						for(int i = 0; i < y; i++)
						{	
							if(pnt_cadastroCliente[i].id == id)
							{
								printf("\n");
								printf("ID: %d\n",pnt_cadastroCliente[i].id);
								printf("Nome: %s\n",pnt_cadastroCliente[i].nome);
								printf("CPF: %s\n",pnt_cadastroCliente[i].cpf);
								printf("Telefone: %s\n\n",pnt_cadastroCliente[i].telefone);
								printf("Informe o NOVO NOME COMPLETO: ");
								scanf(" %[^\n]",nome);
								LimpaStringCliente(nome);
								ConverteMaiusculaCliente(nome);
								strcpy(pnt_cadastroCliente[i].nome, nome);
								printf("\n");
								printf("╔══════════════════════════════════════════════════════════════════╗\n");
								printf("║                       **CADASTRO ATUALIZADO**                    ║\n");
								printf("╠══════════════════════════════════════════════════════════════════╣\n");
								printf("║ COD │          NOME          │       CPF       │     TELEFONE    ║\n");
								printf("╟──────────────────────────────────────────────────────────────────╢\n");
								printf("║%5d│\033[32m%24s\033[0m│%17s│%17s║\n",
											pnt_cadastroCliente[i].id,
											pnt_cadastroCliente[i].nome,
											pnt_cadastroCliente[i].cpf,
											pnt_cadastroCliente[i].telefone);
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
							printf("█        CLIENTE NAO ENCONTRADO!      █\n");
							printf("█                                     █\n");
							printf("███████████████████████████████████████\n");
							printf("\nAperte qualquer tecla para voltar ao MENU... \n\n");
							system("pause > nul");
							a = 1;
						}

					}while(a != 1);	
					pont_cliente = fopen("cliente.txt","w");	
					for(int i = 0; i < y; i++)
					{
						fprintf(pont_cliente,"%d\n%s\n%s\n%s\n",
												pnt_cadastroCliente[i].id,
												pnt_cadastroCliente[i].nome,
												pnt_cadastroCliente[i].cpf,
												pnt_cadastroCliente[i].telefone);
					}					
					y = 0;
					fclose(pont_cliente);	
				}
			break;
			case 2:
				y = 0;
				system("cls");				
				pont_cliente = fopen("cliente.txt","r");		
				if(pont_cliente == NULL)
				{
					printf("\nERRO! O arquivo nao foi aberto!\n\n");
				}
				else
				{
					printf("\nO arquivo foi aberto com sucesso\n\n");
					while(fscanf(pont_cliente,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n",
												&pnt_cadastroCliente[y].id,
												pnt_cadastroCliente[y].nome,
												pnt_cadastroCliente[y].cpf,
												pnt_cadastroCliente[y].telefone) != EOF)
					{
						y++;
					}
					fclose(pont_cliente);
					printf("ATUALIZAR CPF\n");
					printf("-------------\n\n");
					printf("Informe o ID do cliente: ");
					id = ObtemInteiroValidoCliente(id);
					printf("\n");
					do{
						for(int i = 0; i < y; i++)
						{	
							if(pnt_cadastroCliente[i].id == id)
							{
								printf("\n");
								printf("ID: %d\n",pnt_cadastroCliente[i].id);
								printf("Nome: %s\n",pnt_cadastroCliente[i].nome);
								printf("CPF: %s\n",pnt_cadastroCliente[i].cpf);
								printf("Telefone: %s\n\n",pnt_cadastroCliente[i].telefone);
								printf("Informe o novo CPF: ");
								scanf(" %[^\n]",cpf);
								strcpy(pnt_cadastroCliente[i].cpf, cpf);
								printf("\n");
								printf("╔══════════════════════════════════════════════════════════════════╗\n");
								printf("║                       **CADASTRO ATUALIZADO**                    ║\n");
								printf("╠══════════════════════════════════════════════════════════════════╣\n");
								printf("║ COD │          NOME          │       CPF       │     TELEFONE    ║\n");
								printf("╟──────────────────────────────────────────────────────────────────╢\n");
								printf("║%5d│%24s│\033[32m%17s\033[0m│%17s║\n",
											pnt_cadastroCliente[i].id,
											pnt_cadastroCliente[i].nome,
											pnt_cadastroCliente[i].cpf,
											pnt_cadastroCliente[i].telefone);
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
							printf("█        CLIENTE NAO ENCONTRADO!      █\n");
							printf("█                                     █\n");
							printf("███████████████████████████████████████\n");
							printf("\nAperte qualquer tecla para voltar ao MENU... \n\n");
							system("pause > nul");
							a = 1;
						}
								
					}while(a != 1);	
					pont_cliente = fopen("cliente.txt","w");	
					for(int i = 0; i < y; i++)
					{
						fprintf(pont_cliente,"%d\n%s\n%s\n%s\n",
												pnt_cadastroCliente[i].id,
												pnt_cadastroCliente[i].nome,
												pnt_cadastroCliente[i].cpf,
												pnt_cadastroCliente[i].telefone);
					}
					y = 0;				
					fclose(pont_cliente);	
				}
			break;
			case 3:
				y = 0;
				system("cls");
				pont_cliente = fopen("cliente.txt","r");		
				if(pont_cliente == NULL)
				{
					printf("\nERRO! O arquivo nao foi aberto!\n\n");
				}
				else
				{
					printf("\nO arquivo foi aberto com sucesso\n\n");
					while(fscanf(pont_cliente,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n",
												&pnt_cadastroCliente[y].id,
												pnt_cadastroCliente[y].nome,
												pnt_cadastroCliente[y].cpf,
												pnt_cadastroCliente[y].telefone) != EOF)
					{
						y++;
					}
					fclose(pont_cliente);
					printf("ATUALIZAR TELEFONE\n");
					printf("------------------\n\n");
					printf("Informe o ID do cliente: ");
					id = ObtemInteiroValidoCliente(id);
					printf("\n");
					do{
						for(int i = 0; i < y; i++)
						{	
							if(pnt_cadastroCliente[i].id == id)
							{
								printf("\n");
								printf("ID: %d\n",pnt_cadastroCliente[i].id);
								printf("Nome: %s\n",pnt_cadastroCliente[i].nome);
								printf("CPF: %s\n",pnt_cadastroCliente[i].cpf);
								printf("Telefone: %s\n\n",pnt_cadastroCliente[i].telefone);
								printf("Informe o novo telefone: ");
								scanf(" %[^\n]",telefone);
								strcpy(pnt_cadastroCliente[i].telefone, telefone);
								printf("\n");
								printf("╔══════════════════════════════════════════════════════════════════╗\n");
								printf("║                       **CADASTRO ATUALIZADO**                    ║\n");
								printf("╠══════════════════════════════════════════════════════════════════╣\n");
								printf("║ COD │          NOME          │       CPF       │     TELEFONE    ║\n");
								printf("╟──────────────────────────────────────────────────────────────────╢\n");
								printf("║%5d│%24s│%17s│\033[32m%17s\033[0m║\n",
											pnt_cadastroCliente[i].id,
											pnt_cadastroCliente[i].nome,
											pnt_cadastroCliente[i].cpf,
											pnt_cadastroCliente[i].telefone);
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
							printf("█        CLIENTE NAO ENCONTRADO!      █\n");
							printf("█                                     █\n");
							printf("███████████████████████████████████████\n");
							printf("\nAperte qualquer tecla para voltar ao MENU... \n\n");
							system("pause > nul");
							a = 1;
						}
							
					}while(a != 1);	
					pont_cliente = fopen("cliente.txt","w");	
					for(int i = 0; i < y; i++)
					{
						fprintf(pont_cliente,"%d\n%s\n%s\n%s\n",
												pnt_cadastroCliente[i].id,
												pnt_cadastroCliente[i].nome,
												pnt_cadastroCliente[i].cpf,
												pnt_cadastroCliente[i].telefone);
					}
					y = 0;
					fclose(pont_cliente);	
				}
			break;
			case 0:
			break;
			default:
				printf("\n\nDigite uma opcao valida!\n\n");
		}			
	}while(menu_atualiza != 0);	
}

void RemoveCliente(Cliente * pnt_cadastroCliente)
{
	FILE *pont_cliente;
	int menu_remove = 0;
	int y = 0;
	int r = 0;
	int id = 0;
	
	system("cls");
	pont_cliente = fopen("cliente.txt","r");	
	if(pont_cliente == NULL)
	{
		printf("\nERRO! O arquivo nao foi aberto!\n\n");
	}
	else
	{
		while(fscanf(pont_cliente,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n",
									&pnt_cadastroCliente[y].id,
									pnt_cadastroCliente[y].nome,
									pnt_cadastroCliente[y].cpf,
									pnt_cadastroCliente[y].telefone) != EOF)
		{
			y++;
		}
		fclose(pont_cliente);	
		pont_cliente = fopen("cliente.txt","w");
		printf("\nREMOVER CLIENTE\n");
		printf("---------------\n\n");
		printf("Informe o ID do cliente a ser removido: ");
		//LimpaBufferCliente();
		id = ObtemInteiroValidoCliente(id);
		printf("\n");
		do{
			for(int i = 0; i < y; i++)
			{
				if(pnt_cadastroCliente[i].id == id)
				{
					printf("╔══════════════════════════════════════════════════════════════════╗\n");
					printf("║                       **CLIENTE ENCONTRADO**                     ║\n");
					printf("╠══════════════════════════════════════════════════════════════════╣\n");
					printf("║ COD │          NOME          │       CPF       │     TELEFONE    ║\n");
					printf("╟──────────────────────────────────────────────────────────────────╢\n");
					printf("║%5d│\033[31m%24s\033[0m│%17s│%17s║\n",
								pnt_cadastroCliente[i].id,
								pnt_cadastroCliente[i].nome,
								pnt_cadastroCliente[i].cpf,
								pnt_cadastroCliente[i].telefone);
					printf("╚══════════════════════════════════════════════════════════════════╝\n");
				
					printf("\nRemover cliente - 1 | Cancelar remoção - 2\n");
					menu_remove = ObtemInteiroValidoCliente(menu_remove);
					switch (menu_remove)
					{
						case 1:			
							r = 1;
						break;
						case 2:
							fprintf(pont_cliente,"%d\n%s\n%s\n%s\n",
													pnt_cadastroCliente[i].id,
													pnt_cadastroCliente[i].nome,
													pnt_cadastroCliente[i].cpf,
													pnt_cadastroCliente[i].telefone);
							r = -1;
						break;
						default:
							printf("\nDigite uma opcao valida\n\n");
					}
						
				}
				
				if(pnt_cadastroCliente[i].id != id)
				{
					fprintf(pont_cliente,"%d\n%s\n%s\n%s\n",
											pnt_cadastroCliente[i].id,
											pnt_cadastroCliente[i].nome,
											pnt_cadastroCliente[i].cpf,
											pnt_cadastroCliente[i].telefone);
				}
				
			}
			if(r == 0)
			{
				printf("\n");
				printf("███████████████████████████████████████\n\a");
				printf("█                                     █\n");
				printf("█        CLIENTE NAO ENCONTRADO!      █\n");
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
				printf("\n\nCLIENTE REMOVIDO\n\n");
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
	fclose(pont_cliente);
}

void ApagaSistemaCliente(Cliente  * pnt_cadastroCliente)
{
	FILE * pont_cliente;
	int op = -1;
	system("cls");
	
	printf("\n████████████████████████████████████████████████████████████████████████\n\a");
	printf("█                                                                      █\n");
	printf("█   \033[31mATENÇÃO!\033[0m Todos os dados de CLIENTES do sistema serão apagados...   █\n");
	printf("█                                                                      █\n");
	printf("████████████████████████████████████████████████████████████████████████\n\n");
	
	printf("Confirmar - 1 | Cancelar - 0\n");
	op = ObtemInteiroValidoCliente(op);
	switch(op)
	{
		case 1:
			pont_cliente = fopen("cliente.txt","w");
			if(pont_cliente != NULL)
			{
				fprintf(pont_cliente,"%s","");
				fclose(pont_cliente);
				system("cls");
				printf("\nCADASTRO DE CLIENTES DELETADO\n\n");
				printf("Aperte qualquer tecla para voltar ao MENU INICIAL...\n\n");
				system("pause > nul");
				system("cls");
				
			}	
			else
			{
				system("cls");
				printf("\n\nO cadastro de clientes NAO FOI APAGAGO...\n\n");
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