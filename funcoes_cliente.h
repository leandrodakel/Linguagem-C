void MenuCliente();
void FiltroCliente();
void OrdemCliente();
void LimpaStringCliente(char *str);
void ConverteMaiusculaCliente(char *str);
void LimpaBufferCliente();
int ObtemInteiroValidoCliente(int n);
void ImprimeCliente(Cliente * pnt_cadastro, int tam);
void MenuBuscaCliente();
void MenuAtualizaCliente();
void LimpaBufferCliente();
int ObtemInteiroValidoCliente();
void CadastraCliente(Cliente * pnt_cadastro);
void ListaCliente(Cliente * pnt_cadastro);
void BuscaCliente(Cliente * pnt_cadastro);
void AtualizaCliente(Cliente  * pnt_cadastro);
void RemoveCliente(Cliente * pnt_cadastro);
int ComparaPalavrasCliente(char * palavra1, char * palavra2);
void BubbleSortIDCliente(Cliente * pnt_cadastro, int opcao, int tamanho);
void BubbleSortNomeCliente(Cliente * pnt_cadastro, int opcao, int tamanho);
void FiltraOrdenaCliente(Cliente  * pnt_cadastro);
void ApagaSistemaCliente(Cliente  * pnt_cadastro);

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

void FiltroCliente()
{
	printf("\n");
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("║            FILTRAGEM LISTA DE CLIENTES            ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                                   ║\n");
	printf("║         Filtrar por NOME --------------- 1        ║\n");
	printf("║         Filtrar por ID ----------------- 2        ║\n");
	printf("║                                                   ║\n");
	printf("╚═══════════════════════════════════════════════════╝\n\n");
	
}

void OrdemCliente()
{
	printf("\n");
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("║           ORDENAMENTO LISTA DE CLIENTES           ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                                   ║\n");
	printf("║            Ordem CRESCENTE ----------- 1          ║\n");
	printf("║            Ordem DECRESCENTE --------- 2          ║\n");
	printf("║                                                   ║\n");
	printf("╚═══════════════════════════════════════════════════╝\n\n");
	
}

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

void ImprimeCliente(Cliente * pnt_cadastro, int tam)
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
			printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%24s\x1b[0m│\x1b[36m%17s\x1b[0m│\x1b[36m%17s\x1b[0m║\n",pnt_cadastro[i].id,pnt_cadastro[i].nome,pnt_cadastro[i].cpf,pnt_cadastro[i].telefone);
			printf("╟──────────────────────────────────────────────────────────────────╢\n");
			clientes_exibidos++;
		}
		else
		{
			printf("║%5d│%24s│%17s│%17s║\n",pnt_cadastro[i].id,pnt_cadastro[i].nome,pnt_cadastro[i].cpf,pnt_cadastro[i].telefone);
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

void CadastraCliente(Cliente * pnt_cadastro)
{
	FILE *pont_cliente;
	int k = 1;
	int y = 0;
	int id = 0;
	int cadastro = 0;
	//char nome_cliente[100];
	//char cpf_cliente[100];
	//char telefone_cliente[100];
	
	system("cls");
	
	pont_cliente = fopen("cliente.txt","r");
	while(fscanf(pont_cliente,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n",&pnt_cadastro[y].id,pnt_cadastro[y].nome,pnt_cadastro[y].cpf,pnt_cadastro[y].telefone) != EOF)
	{
		y++;
	}
	fclose(pont_cliente);
	
	//Obtendo o numero de id para auto incremento
	id = pnt_cadastro[y-1].id + 1;
	
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
		//LimpaBufferCliente();
		cadastro = ObtemInteiroValidoCliente(cadastro);
		
		for(int i = 0; i < cadastro; i++)
		{
		
			printf("\nInforme o NOME COMPLETO do cliente 0%d : ",k);
			scanf(" %[^\n]",pnt_cadastro[i].nome);
			
			// Limpar a string, remover espaços extras antes e depois
			LimpaStringCliente(pnt_cadastro[i].nome);
			// Converter a unidade para maiúsculas
			ConverteMaiusculaCliente(pnt_cadastro[i].nome);
			
			printf("Informe o CPF do cliente 0%d : ",k);
			scanf(" %[^\n]",pnt_cadastro[i].cpf);
				
			
			printf("Informe o TELEFONE do cliente 0%d : ",k);
			scanf(" %[^\n]",pnt_cadastro[i].telefone);
		
			printf("\n");	
			
			fprintf(pont_cliente,"%d\n%s\n%s\n%s\n",id,pnt_cadastro[i].nome,pnt_cadastro[i].cpf,pnt_cadastro[i].telefone);
			k++;
			id++;
		}
			
	}
	fclose(pont_cliente);
	system("cls");
	printf("\n\nCADASTRO CONCLUIDO\n\n");
	printf("Aperte qualquer tecla para voltar ao MENU INICIAL...");
	system("pause > nul");
}
	
void ListaCliente(Cliente * pnt_cadastro)
{
	FILE *pont_cliente;
	int y = 0;
	
	system("cls");
	printf("\n");
	
	pont_cliente = fopen("cliente.txt","r");
	
	while(fscanf(pont_cliente,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n",&pnt_cadastro[y].id,pnt_cadastro[y].nome,pnt_cadastro[y].cpf,pnt_cadastro[y].telefone) != EOF)
	{
		y++;
	}
	
	fclose(pont_cliente);	
	
	if(y > 0)
	{
		printf("╔══════════════════════════════════════════════════════════════════╗\n");
		printf("║                       **LISTA DE CLIENTES**                      ║\n");
		printf("╠══════════════════════════════════════════════════════════════════╣\n");
	}
	ImprimeCliente(pnt_cadastro, y);
	
	printf("\nAperte qualquer tecla para voltar ao MENU INICIAL... ");
	system("pause > nul");
	system("cls");
}

void BuscaCliente(Cliente * pnt_cadastro)
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
	while(fscanf(pont_cliente,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n",&pnt_cadastro[y].id,pnt_cadastro[y].nome,pnt_cadastro[y].cpf,pnt_cadastro[y].telefone) != EOF)
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
						if(pnt_cadastro[i].id == id)
						{
							printf("╔══════════════════════════════════════════════════════════════════╗\n");
							printf("║                     **BUSCA DE CLIENTE POR ID**                  ║\n");
							printf("╠══════════════════════════════════════════════════════════════════╣\n");
							printf("║ COD │          NOME          │       CPF       │     TELEFONE    ║\n");
							printf("╟──────────────────────────────────────────────────────────────────╢\n");
							printf("╟──────────────────────────────────────────────────────────────────╢\n");
							printf("║%5d│\033[32m%24s\033[0m│%17s│%17s║\n",pnt_cadastro[i].id,pnt_cadastro[i].nome,pnt_cadastro[i].cpf,pnt_cadastro[i].telefone);
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
						if(strstr(pnt_cadastro[i].nome, nome) != NULL)
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
						if(strstr(pnt_cadastro[i].nome, nome) != NULL)
						{
							//if(i % 2 == 0)
							if(clientes_exibidos % 2 == 0)
							{
								printf("║\033[32m%5d\033[0m│\033[32m%24s\033[0m│\033[32m%17s\033[0m│\033[32m%17s\033[0m║\n",pnt_cadastro[i].id,pnt_cadastro[i].nome,pnt_cadastro[i].cpf,pnt_cadastro[i].telefone);
								printf("╟──────────────────────────────────────────────────────────────────╢\n");
								clientes_exibidos++;
							}
							else
							{
								printf("║%5d│%24s│%17s│%17s║\n",pnt_cadastro[i].id,pnt_cadastro[i].nome,pnt_cadastro[i].cpf,pnt_cadastro[i].telefone);
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
							
							/*if(i != 0 && i % 10 == 0)
							{
								printf("╚══════════════════════════════════════════════════════════════════╝\n");
								printf("\nAperte qualquer tecla para continuar a lista de clientes... \n\n");
								system("pause > nul");
								printf("╔══════════════════════════════════════════════════════════════════╗\n");
								printf("║ ID  │          NOME          │       CPF       │     TELEFONE    ║\n");
								printf("╟──────────────────────────────────────────────────────────────────╢\n");
								printf("╟──────────────────────────────────────────────────────────────────╢\n");
							}
							printf("║%5d│\033[32m%24s\033[0m│%17s│%17s║\n",pnt_cadastro[i].id,pnt_cadastro[i].nome,pnt_cadastro[i].cpf,pnt_cadastro[i].telefone);
							printf("╟──────────────────────────────────────────────────────────────────╢\n");*/
							
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
						if(strstr(pnt_cadastro[i].cpf, cpf) != NULL)
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
						if(strstr(pnt_cadastro[i].cpf, cpf) != NULL)
						{
							//if(i % 2 == 0)
							if(clientes_exibidos % 2 == 0)
							{
								printf("║\033[32m%5d\033[0m│\033[32m%24s\033[0m│\033[32m%17s\033[0m│\033[32m%17s\033[0m║\n",pnt_cadastro[i].id,pnt_cadastro[i].nome,pnt_cadastro[i].cpf,pnt_cadastro[i].telefone);
								printf("╟──────────────────────────────────────────────────────────────────╢\n");
								clientes_exibidos++;
							}
							else
							{
								printf("║%5d│%24s│%17s│%17s║\n",pnt_cadastro[i].id,pnt_cadastro[i].nome,pnt_cadastro[i].cpf,pnt_cadastro[i].telefone);
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
							
							/*if(i != 0 && i % 10 == 0)
							{
								printf("╚══════════════════════════════════════════════════════════════════╝\n");
								printf("\nAperte qualquer tecla para continuar a lista de clientes... \n\n");
								system("pause > nul");
								printf("╔══════════════════════════════════════════════════════════════════╗\n");
								printf("║ ID  │          NOME          │       CPF       │     TELEFONE    ║\n");
								printf("╟──────────────────────────────────────────────────────────────────╢\n");
								printf("╟──────────────────────────────────────────────────────────────────╢\n");
							}
							printf("║%5d│%24s│\033[32m%17s\033[0m│%17s║\n",pnt_cadastro[i].id,pnt_cadastro[i].nome,pnt_cadastro[i].cpf,pnt_cadastro[i].telefone);
							printf("╟──────────────────────────────────────────────────────────────────╢\n");
							*/
							
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

void AtualizaCliente(Cliente * pnt_cadastro)
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
		//LimpaBufferCliente();
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
					while(fscanf(pont_cliente,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n",&pnt_cadastro[y].id,pnt_cadastro[y].nome,pnt_cadastro[y].cpf,pnt_cadastro[y].telefone) != EOF)
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
							if(pnt_cadastro[i].id == id)
							{
								printf("\n");
								printf("ID: %d\n",pnt_cadastro[i].id);
								printf("Nome: %s\n",pnt_cadastro[i].nome);
								printf("CPF: %s\n",pnt_cadastro[i].cpf);
								printf("Telefone: %s\n\n",pnt_cadastro[i].telefone);
								printf("Informe o NOVO NOME COMPLETO: ");
								scanf(" %[^\n]",nome);
								LimpaStringCliente(nome);
								ConverteMaiusculaCliente(nome);
								strcpy(pnt_cadastro[i].nome, nome);
								printf("\n");
								printf("╔══════════════════════════════════════════════════════════════════╗\n");
								printf("║                       **CADASTRO ATUALIZADO**                    ║\n");
								printf("╠══════════════════════════════════════════════════════════════════╣\n");
								printf("║ COD │          NOME          │       CPF       │     TELEFONE    ║\n");
								printf("╟──────────────────────────────────────────────────────────────────╢\n");
								printf("║%5d│\033[32m%24s\033[0m│%17s│%17s║\n",pnt_cadastro[i].id,pnt_cadastro[i].nome,pnt_cadastro[i].cpf,pnt_cadastro[i].telefone);
								printf("╚══════════════════════════════════════════════════════════════════╝\n");
								printf("\nAperte qualquer tecla para voltar ao menu... \n\n");
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
							printf("\nAperte qualquer tecla para voltar ao menu... \n\n");
							system("pause > nul");
							a = 1;
						}

					}while(a != 1);	
					pont_cliente = fopen("cliente.txt","w");	
					for(int i = 0; i < y; i++)
					{
						fprintf(pont_cliente,"%d\n%s\n%s\n%s\n",pnt_cadastro[i].id,pnt_cadastro[i].nome,pnt_cadastro[i].cpf,pnt_cadastro[i].telefone);
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
					while(fscanf(pont_cliente,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n",&pnt_cadastro[y].id,pnt_cadastro[y].nome,pnt_cadastro[y].cpf,pnt_cadastro[y].telefone) != EOF)
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
							if(pnt_cadastro[i].id == id)
							{
								printf("\n");
								printf("ID: %d\n",pnt_cadastro[i].id);
								printf("Nome: %s\n",pnt_cadastro[i].nome);
								printf("CPF: %s\n",pnt_cadastro[i].cpf);
								printf("Telefone: %s\n\n",pnt_cadastro[i].telefone);
								printf("Informe o novo CPF: ");
								scanf(" %[^\n]",cpf);
								strcpy(pnt_cadastro[i].cpf, cpf);
								printf("\n");
								printf("╔══════════════════════════════════════════════════════════════════╗\n");
								printf("║                       **CADASTRO ATUALIZADO**                    ║\n");
								printf("╠══════════════════════════════════════════════════════════════════╣\n");
								printf("║ COD │          NOME          │       CPF       │     TELEFONE    ║\n");
								printf("╟──────────────────────────────────────────────────────────────────╢\n");
								printf("║%5d│%24s│\033[32m%17s\033[0m│%17s║\n",pnt_cadastro[i].id,pnt_cadastro[i].nome,pnt_cadastro[i].cpf,pnt_cadastro[i].telefone);
								printf("╚══════════════════════════════════════════════════════════════════╝\n");
								printf("\nAperte qualquer tecla para voltar ao menu... ");
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
							printf("\nAperte qualquer tecla para voltar ao menu... \n\n");
							system("pause > nul");
							a = 1;
						}
								
					}while(a != 1);	
					pont_cliente = fopen("cliente.txt","w");	
					for(int i = 0; i < y; i++)
					{
						fprintf(pont_cliente,"%d\n%s\n%s\n%s\n",pnt_cadastro[i].id,pnt_cadastro[i].nome,pnt_cadastro[i].cpf,pnt_cadastro[i].telefone);
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
					while(fscanf(pont_cliente,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n",&pnt_cadastro[y].id,pnt_cadastro[y].nome,pnt_cadastro[y].cpf,pnt_cadastro[y].telefone) != EOF)
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
							if(pnt_cadastro[i].id == id)
							{
								printf("\n");
								printf("ID: %d\n",pnt_cadastro[i].id);
								printf("Nome: %s\n",pnt_cadastro[i].nome);
								printf("CPF: %s\n",pnt_cadastro[i].cpf);
								printf("Telefone: %s\n\n",pnt_cadastro[i].telefone);
								printf("Informe o novo telefone: ");
								scanf(" %[^\n]",telefone);
								strcpy(pnt_cadastro[i].telefone, telefone);
								printf("\n");
								printf("╔══════════════════════════════════════════════════════════════════╗\n");
								printf("║                       **CADASTRO ATUALIZADO**                    ║\n");
								printf("╠══════════════════════════════════════════════════════════════════╣\n");
								printf("║ COD │          NOME          │       CPF       │     TELEFONE    ║\n");
								printf("╟──────────────────────────────────────────────────────────────────╢\n");
								printf("║%5d│%24s│%17s│\033[32m%17s\033[0m║\n", pnt_cadastro[i].id, pnt_cadastro[i].nome, pnt_cadastro[i].cpf, pnt_cadastro[i].telefone);
								printf("╚══════════════════════════════════════════════════════════════════╝\n");
								printf("\nAperte qualquer tecla para voltar ao menu inicial... \n\n");
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
							printf("\nAperte qualquer tecla para voltar ao menu... \n\n");
							system("pause > nul");
							a = 1;
						}
							
					}while(a != 1);	
					pont_cliente = fopen("cliente.txt","w");	
					for(int i = 0; i < y; i++)
					{
						fprintf(pont_cliente,"%d\n%s\n%s\n%s\n",pnt_cadastro[i].id,pnt_cadastro[i].nome,pnt_cadastro[i].cpf,pnt_cadastro[i].telefone);
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

void RemoveCliente(Cliente * pnt_cadastro)
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
		while(fscanf(pont_cliente,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n",&pnt_cadastro[y].id,pnt_cadastro[y].nome,pnt_cadastro[y].cpf,pnt_cadastro[y].telefone) != EOF)
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
				if(pnt_cadastro[i].id == id)
				{
					printf("╔══════════════════════════════════════════════════════════════════╗\n");
					printf("║                       **CLIENTE ENCONTRADO**                     ║\n");
					printf("╠══════════════════════════════════════════════════════════════════╣\n");
					printf("║ COD │          NOME          │       CPF       │     TELEFONE    ║\n");
					printf("╟──────────────────────────────────────────────────────────────────╢\n");
					printf("║%5d│\033[31m%24s\033[0m│%17s│%17s║\n",pnt_cadastro[i].id,pnt_cadastro[i].nome,pnt_cadastro[i].cpf,pnt_cadastro[i].telefone);
					printf("╚══════════════════════════════════════════════════════════════════╝\n");
				
					printf("\nRemover cliente - 1 | Cancelar remoção - 2\n");
					menu_remove = ObtemInteiroValidoCliente(menu_remove);
					switch (menu_remove)
					{
						case 1:			
							r = 1;
						break;
						case 2:
							fprintf(pont_cliente,"%d\n%s\n%s\n%s\n",pnt_cadastro[i].id,pnt_cadastro[i].nome,pnt_cadastro[i].cpf,pnt_cadastro[i].telefone);
							r = -1;
						break;
						default:
							printf("\nDigite uma opcao valida\n\n");
					}
						
				}
				
				if(pnt_cadastro[i].id != id)
				{
					fprintf(pont_cliente,"%d\n%s\n%s\n%s\n",pnt_cadastro[i].id,pnt_cadastro[i].nome,pnt_cadastro[i].cpf,pnt_cadastro[i].telefone);
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
				break;
			}
			else if(r == 1)
			{
				system("cls");
				printf("\n\nCLIENTE REMOVIDO\n\n");
				printf("Aperte qualquer tecla para voltar ao MENU INICIAL...");
				system("pause > nul");
			}
			else if(r == -1)
			{
				r = 1;
				system("cls");
				printf("\n\nREMOCAO CANCELADA\n\n");
				printf("Aperte qualquer tecla para voltar ao MENU INICIAL...");
				system("pause > nul");
			}
			
		}while(r != 1);
	}
	fclose(pont_cliente);
}

int ComparaPalavrasCliente(char *palavra1, char *palavra2)
{
    int i = 0;

    while (palavra1[i] != '\0' && palavra2[i] != '\0')
    {
        if (palavra1[i] < palavra2[i])
        {
           return(0);
        }
        else if (palavra1[i] > palavra2[i])
        {
			return(1);
		}
        i++;
    }

    // Se cheguei aqui, as duas são iguais até o fim de uma delas
    if (palavra1[i] == '\0' && palavra2[i] == '\0')
    {
         return(0);
    }
    else if (palavra1[i] == '\0')
    {
		return(0);
    }
    else
    {
		return(1);
    }
}

void BubbleSortIDCliente(Cliente * pnt_cadastro, int opcao, int tamanho)
{
	Cliente aux;
	if(opcao == 1)
	{	
		for(int i = 0; i < tamanho; i++)
		{
			for(int k = 0; k < tamanho-1; k++)
			{
				if(pnt_cadastro[i].id < pnt_cadastro[k].id)
				{
					aux = pnt_cadastro[i];
					pnt_cadastro[i] = pnt_cadastro[k];
					pnt_cadastro[k] = aux;
				}
			}
		}
	}
	else
	{
		for(int i = 0; i < tamanho; i++)
		{
			for(int k = 0; k < tamanho-1; k++)
			{
				if(pnt_cadastro[i].id > pnt_cadastro[k].id)
				{
					aux = pnt_cadastro[i];
					pnt_cadastro[i] = pnt_cadastro[k];
					pnt_cadastro[k] = aux;
				}
			}
		}
	}
	
}

void BubbleSortNomeCliente(Cliente * pnt_cadastro, int opcao, int tamanho)
{
	Cliente aux;
	int troca = -1;

	for(int i = 0; i < tamanho; i++)
	{
		for(int k = 0; k < tamanho-1; k++)
		{
			if(opcao == 1)
			{
				troca = ComparaPalavrasCliente(pnt_cadastro[i].nome,pnt_cadastro[k].nome);
				if(!troca)
				{
					aux = pnt_cadastro[i];
					pnt_cadastro[i] = pnt_cadastro[k];
					pnt_cadastro[k] = aux;
				}
			}
			else
			{
				troca = ComparaPalavrasCliente(pnt_cadastro[i].nome,pnt_cadastro[k].nome);
				if(troca)
				{
					aux = pnt_cadastro[i];
					pnt_cadastro[i] = pnt_cadastro[k];
					pnt_cadastro[k] = aux;
				}
			}
		}
	}
}

void FiltraOrdenaCliente(Cliente  * pnt_cadastro)
{
	FILE * pont_cliente;
	int i = 0;
	int escolha = 0;
	system("cls");
	pont_cliente = fopen("cliente.txt","r");
	if(pont_cliente != NULL)
	{
		while(fscanf(pont_cliente,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n",&pnt_cadastro[i].id,pnt_cadastro[i].nome,pnt_cadastro[i].cpf,pnt_cadastro[i].telefone) != EOF)
		{
			i++;
		}
		fclose(pont_cliente);		
		FiltroCliente();
		//LimpaBufferCliente();
		escolha = ObtemInteiroValidoCliente(escolha);
		system("cls");
		switch(escolha)
		{
			//Ordenar por nome do cliente(s);
			case 1:
				OrdemCliente();
				escolha = ObtemInteiroValidoCliente(escolha);
				switch(escolha)
				{
					//Crescente 
					case 1:
						BubbleSortNomeCliente(pnt_cadastro, escolha, i);
						system("cls");
						printf("\n╔══════════════════════════════════════════════════════════════════╗\n");
						printf("║                  **FILTRAGEM POR NOME - CRESCENTE**              ║\n");
						ImprimeCliente(pnt_cadastro, i);
						printf("\nAperte qualquer tecla para voltar ao MENU INICIAL... ");
						system("pause > nul");
						system("cls");
					break;
					//Decrescente 
					case 2:
						BubbleSortNomeCliente(pnt_cadastro, escolha, i);
						system("cls");
						printf("\n╔══════════════════════════════════════════════════════════════════╗\n");
						printf("║                 **FILTRAGEM POR NOME - DECRESCENTE**             ║\n");
						ImprimeCliente(pnt_cadastro, i);
						printf("\nAperte qualquer tecla para voltar ao MENU INICIAL... ");
						system("pause > nul");
						system("cls");
					break;
					//Caso não seja escolhido uma opção válida
					default:
						printf("\nEscolha uma opcao valida no sistema!\n");
				}
			break;
			//Ordernar por Codigo do produto;
			case 2:
				OrdemCliente();
				escolha = ObtemInteiroValidoCliente(escolha);
				switch(escolha)
				{
					//Crescente 
					case 1:
						BubbleSortIDCliente(pnt_cadastro, escolha, i);
						system("cls");
						printf("\n╔══════════════════════════════════════════════════════════════════╗\n");
						printf("║                  **FILTRAGEM POR ID - CRESCENTE**                ║\n");
						ImprimeCliente(pnt_cadastro, i);
						printf("\nAperte qualquer tecla para voltar ao MENU INICIAL... ");
						system("pause > nul");
						system("cls");
					break;
					//Decrescente 
					case 2:
						BubbleSortIDCliente(pnt_cadastro, escolha, i);
						system("cls");
						printf("\n╔══════════════════════════════════════════════════════════════════╗\n");
						printf("║                 **FILTRAGEM POR ID - DECRESCENTE**               ║\n");
						ImprimeCliente(pnt_cadastro, i);
						printf("\nAperte qualquer tecla para voltar ao MENU INICIAL... ");
						system("pause > nul");
						system("cls");
					break;
					//Caso não seja escolhido uma opção válida
					default:
						printf("\nEscolha uma opcao valida no sistema!\n");
				}
			break;
			
			//Caso não seja escolhido uma opção válida
			default:
				printf("\nEscolha uma opcao valida no sistema!\n");
		}
	}
	else
	{
		printf("ERRO ao acessar o arquivo! Contate o administrador do sistema\n");
	}
	
}

void ApagaSistemaCliente(Cliente  * pnt_cadastro)
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
				system("cls");
				printf("\nCADASTRO DE CLIENTES DELETADO\n\n");
				fclose(pont_cliente);
			}	
			else
			{
				system("cls");
				printf("\n\nO cadastro de clientes nao foi apagado...\n\n");
				printf("ERRO ao acessar o arquivo! Contate o administrador do sistema\n\n");
			}
			break;
			case 0:
				system("cls");
				printf("\n\nACAO CANCELADA\n\n");
			break;	
			default:
				printf("Digite uma opcao valida!");
	}
}