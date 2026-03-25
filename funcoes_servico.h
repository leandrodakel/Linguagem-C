
void LimpaStringServico(char *str);
void ConverteMaiusculaServico(char *str);
void LimpaBufferServico(); // Função para limpar o buffer de entrada (stdin)
float ObtemFloatValidoServico();
int ObtemInteiroValidoServico(); // Função para obter numero inteiro valido

void MenuBuscaServico();
void MenuAtualizaServico();

int LeArquivoServico(Servico * pnt_cadastroServico);
void ImprimeServico(Servico * pnt_cadastroServico, int tam);
void CadastraServico(Servico * cadastroServico);
void ListaServico(Servico * pnt_cadastroServico);
void BuscaServico(Servico * pnt_cadastroServico);
void AtualizaServico(Servico  * pnt_cadastroServico);
void RemoveServico(Servico * pnt_cadastroServico);
void ApagaSistemaServico(Servico  * pnt_cadastroServico);



void LimpaStringServico(char *str)
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

void ConverteMaiusculaServico(char *str)
{
    while (*str)
	{
        *str = toupper((unsigned char)*str);
        str++;
    }
}

void LimpaBufferServico()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // apenas descarta os caracteres restantes
    }
}

float ObtemFloatValidoServico()
{
    float valor;
    int status_leitura;
    char caractere;

    while (1) { // Loop infinito até uma entrada válida ser fornecida
        status_leitura = scanf("%f", &valor);

        if (status_leitura == 1)
		{
            // Limpa o buffer do teclado para remover o caractere de nova linha (\n)
            // e quaisquer caracteres extras que possam ter sido digitados
            while ((caractere = getchar()) != '\n' && caractere != EOF);
            return valor; // Retorna o valor válido
        }
		else 
		{
            // Se a leitura falhou, limpa o buffer para evitar loop infinito
            printf("\n\aEntrada invalida. Por favor, digite apenas numeros: ");
            while ((caractere = getchar()) != '\n' && caractere != EOF);
        }
    }
}

int ObtemInteiroValidoServico(int n)
{
    //int n;
    int resultado;

    while (1) {
        resultado = scanf("%d", &n);

        if (resultado == 1) {
            LimpaBufferServico(); // limpa o '\n' e o que sobrou
            return n;
        } else {
            printf("\nEntrada inválida!\a\n\n");
			printf("Tente novamente: ");
            LimpaBufferServico(); // descarta entrada inválida
        }
    }
}


void MenuBuscaServico()
{
	printf("\n");
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("║                   BUSCAR SERVICO                  ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                                   ║\n");
	printf("║      Buscar SERVICO por CODIGO ----------- 1      ║\n");
	printf("║      Buscar SERVICO por DESCRICAO -------- 2      ║\n");
	printf("║                                                   ║\n");
	printf("║      Voltar ao MENU INICIAL -------------- 0      ║\n");
	printf("║                                                   ║\n");
	printf("╚═══════════════════════════════════════════════════╝\n\n");
}

void MenuAtualizaServico()
{
	printf("\n");
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("║                  ATUALIZAR SERVICO                ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                                   ║\n");
	printf("║          Atualizar DESCRICAO --------- 1          ║\n");
	printf("║          Atualizar PRECO ------------- 2          ║\n");
	printf("║                                                   ║\n");
	printf("║          Voltar ao MENU INICIAL ------ 0          ║\n");
	printf("║                                                   ║\n");
	printf("╚═══════════════════════════════════════════════════╝\n\n");
}


int LeArquivoServico(Servico * pnt_cadastroServico)
{
	FILE *pont_servico;
	int e = 0;
	pont_servico = fopen("servico.txt", "r");
	while(fscanf(pont_servico,
					 "%d\n%[^\n]\n%f\n",
					 &pnt_cadastroServico[e].codigo,
					 pnt_cadastroServico[e].descricao,
					 &pnt_cadastroServico[e].preco) != EOF)
		{
			e++;
		}
	
	fclose(pont_servico);
	return e;
}

void ImprimeServico(Servico * pnt_cadastroServico, int tam)
{
	int i = 0;
	int itens_exibidos = 0;
	if(tam > 0)
	{
		printf("╠════════════════════════════════════════════════════════════════════╣\n");
		printf("║ COD │                   DESCRICAO                 │      PRECO     ║\n");
		printf("╟────────────────────────────────────────────────────────────────────╢\n");
		printf("╟────────────────────────────────────────────────────────────────────╢\n");
	}
	
	for(i = 0; i < tam; i++)
	{
		if(i % 2 == 0)
		{
			printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%45s\x1b[0m│\x1b[36m%16.2f\x1b[0m║\n",
					 pnt_cadastroServico[i].codigo,
					 pnt_cadastroServico[i].descricao,
					 pnt_cadastroServico[i].preco);
			printf("╟────────────────────────────────────────────────────────────────────╢\n");
			itens_exibidos++;
		}
		else
		{
			printf("║%5d│%45s│%16.2f║\n",
					 pnt_cadastroServico[i].codigo,
					 pnt_cadastroServico[i].descricao,
					 pnt_cadastroServico[i].preco);
			printf("╟────────────────────────────────────────────────────────────────────╢\n");
			itens_exibidos++;
		}
		
		if(itens_exibidos % 10 == 0 && i < tam - 1)
		{
			printf("╚════════════════════════════════════════════════════════════════════╝\n");
			printf("\nAperte qualquer tecla para continuar a lista de servicos... \n\n");
			system("pause > nul");
			printf("╔════════════════════════════════════════════════════════════════════╗\n");
			printf("║ COD │                   DESCRICAO                 │     PRECO      ║\n");
			printf("╟────────────────────────────────────────────────────────────────────╢\n");
			printf("╟────────────────────────────────────────────────────────────────────╢\n");
			itens_exibidos = 0;
		}
		
	}
	
	if(tam > 0)
	{
		printf("╚════════════════════════════════════════════════════════════════════╝\n\n");
	}
	printf("LISTAGEM CONCLUIDA\n");
}

void CadastraServico(Servico * pnt_cadastroServico)
{
	FILE *pont_servico;
	
	int k = 1;
	int y = 0;
	int c = 0;
	int codigo = 0;
	int cadastro = 0;
	
	system("cls");
	
	y = LeArquivoServico(pnt_cadastroServico);
	
	//Obtendo codigo para auto incremento
	codigo = pnt_cadastroServico[y-1].codigo + 1;
	
	pont_servico = fopen("servico.txt","a");
				
	if(pont_servico == NULL)
	{
		printf("ERRO! O arquivo nao foi aberto!\n\n");
	}
	else
	{
		printf("O arquivo foi aberto com sucesso\n\n");
		
		printf("\nCADASTRO DE SERVICOS\n");
		printf("--------------------\n\n");	
		printf("Informe quantos servicos deseja cadastrar: ");
		cadastro = ObtemInteiroValidoServico(cadastro);
		printf("\n");
		
		for(int i = 0; i < cadastro; i++)
		{
			printf("\nInforme a DESCRICAO do servico 0%d : ",k);
			scanf(" %[^\n]",pnt_cadastroServico[i].descricao);
			
			// Limpar a string, remover espaços extras antes e depois
			LimpaStringServico(pnt_cadastroServico[i].descricao);
			// Converter a unidade para maiúsculas
			ConverteMaiusculaServico(pnt_cadastroServico[i].descricao);
			
			printf("\nInforme o PRECO do servico 0%d : ",k);
			pnt_cadastroServico[i].preco = ObtemFloatValidoServico();
			
			printf("\n");	
			fprintf(pont_servico,"%d\n%s\n%.2f\n",
								codigo,
								pnt_cadastroServico[i].descricao,
								pnt_cadastroServico[i].preco);
			k++;
			codigo++;
		}
		
		printf("\n\nCADASTRO CONCLUIDO\n\n");
		printf("\n Aperte qualquer tecla para voltar ao MENU INICIAL...");
		system("pause > nul");
		
		fclose(pont_servico);
	}
	system("cls");
	
}
	
void ListaServico(Servico * pnt_cadastroServico)
{
	FILE *pont_servico;
	
	int y = 0;

	system("cls");

	y = 0;
	system("cls");
	
	y = LeArquivoServico(pnt_cadastroServico);
	
	if(y > 0)
	{	
		printf("\n");
		printf("╔════════════════════════════════════════════════════════════════════╗\n");
		printf("║                        **LISTA DE SERVICOS**                       ║\n");
		ImprimeServico(pnt_cadastroServico, y);
	}
	else
	{
		printf("\n\nNAO HA REGISTROS NO ARQUIVO\n\n");
	}
					
	printf("\nAperte qualquer tecla para voltar ao MENU... \n\n");
	system("pause > nul");
	system("cls");	
}

void BuscaServico(Servico * pnt_cadastroServico)
{
	FILE *pont_servico;
	
	int menu_busca = 0;
	int y = 0;
	int c = 0;
	int t = 0;
	int codigo = 0;
	
	int op = 0;
	char descricao[50];
	
	int servicos_exibidos = 0;
	system("cls");
	
	
	do
	{
		MenuBuscaServico();
		menu_busca = ObtemInteiroValidoServico(menu_busca);
		
		switch(menu_busca)
		{
			case 1:
				system("cls");
				
				y = LeArquivoServico(pnt_cadastroServico);
				
				do{
					system("cls");
					printf("\nBUSCA DE SERVICO POR CODIGO\n");
					printf("---------------------------\n\n");
					printf("Informe o CODIGO do servico: ");
					codigo = ObtemInteiroValidoServico(codigo);
					printf("\n");
					
					t = 0;
					
					for(int i = 0; i < y; i++)
					{	
						if(pnt_cadastroServico[i].codigo == codigo)
						{
							printf("╔════════════════════════════════════════════════════════════════════╗\n");
							printf("║                         **BUSCA POR CODIGO**                       ║\n");
							printf("╠════════════════════════════════════════════════════════════════════╣\n");
							printf("║ COD │                   DESCRICAO                 │     PRECO      ║\n");
							printf("╟────────────────────────────────────────────────────────────────────╢\n");
							printf("╟────────────────────────────────────────────────────────────────────╢\n");
							printf("║%5d│\033[32m%45s\033[0m│%16.2f║\n",
									 pnt_cadastroServico[i].codigo,
									 pnt_cadastroServico[i].descricao,
									 pnt_cadastroServico[i].preco);
							printf("╟────────────────────────────────────────────────────────────────────╢\n");
							printf("╚════════════════════════════════════════════════════════════════════╝\n\n");
							printf("BUSCA CONCLUIDA\n\n");
							t = 1;
						}	
					}
					if(t == 0)
					{
						printf("\n");
						printf("███████████████████████████████████████\n\a");
						printf("█                                     █\n");
						printf("█        SERVICO NAO ENCONTRADO!      █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n\n\n");
					
					}				
					printf("Continuar busca - 1 | Voltar ao MENU - 2\n");
					op = ObtemInteiroValidoServico(op);
					
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
								printf("Continuar busca - 1 | Voltar ao MENU - 2\n");
								
								op = ObtemInteiroValidoServico(op);
								
							}while(op < 1 || op > 2);
					}
				}while(op != 2);
				y = 0;
				op = 0;
				system("cls");
			break;
			case 2:
				system("cls");
				
				y = LeArquivoServico(pnt_cadastroServico);
				
				do
				{
					system("cls");
					printf("\nBUSCA DE SERVICO POR DESCRICAO\n");
					printf("------------------------------\n\n");
					printf("Informe a DESCRICAO do servico: ");
					scanf(" %[^\n]", descricao);
					
					// Limpar a string, remover espaços extras antes e depois
					LimpaStringServico(descricao);
					// Converter a unidade para maiúsculas
					ConverteMaiusculaServico(descricao);	
					
					printf("\n");
					
					servicos_exibidos = 0;
					t = 0; // Reinicie a flag 't' para cada nova busca
					
					for (int i = 0; i < y; i++)
					{
						// strstr() verifica se 'descricao' esta contida no nome do produto
						if (strstr(pnt_cadastroServico[i].descricao, descricao) != NULL)
						{
							t = 1;
							break;
						}
					}
					
					if(t == 1)
					{
						printf("╔════════════════════════════════════════════════════════════════════╗\n");
						printf("║                       **BUSCA POR DESCRICAO**                      ║\n");
						printf("╠════════════════════════════════════════════════════════════════════╣\n");
						printf("║ COD │                   DESCRICAO                 │     PRECO      ║\n");
						printf("╟────────────────────────────────────────────────────────────────────╢\n");
						printf("╟────────────────────────────────────────────────────────────────────╢\n");
					}
					
					for (int i = 0; i < y; i++)
					{
						// strstr() verifica se 'descricao' esta contida no nome do produto
						if (strstr(pnt_cadastroServico[i].descricao, descricao) != NULL)
						{
							
							printf("║%5d│\033[32m%45s\033[0m│%16.2f║\n",
									 pnt_cadastroServico[i].codigo,
									 pnt_cadastroServico[i].descricao,
									 pnt_cadastroServico[i].preco);
							printf("╟────────────────────────────────────────────────────────────────────╢\n");

							servicos_exibidos++;
						}
					
						if(servicos_exibidos < y && servicos_exibidos % 10 == 0 && servicos_exibidos != 0)
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
						printf("╚════════════════════════════════════════════════════════════════════╝\n");
						printf("\n\nBUSCA CONCLUIDA\n\n");
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
					printf("Continuar busca - 1 | Voltar ao MENU - 2\n");
					op = ObtemInteiroValidoServico(op);
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
								printf("Continuar busca - 1 | Voltar ao menu - 2\n");
								op = ObtemInteiroValidoServico(op);
							}while(op < 1 || op > 2);
					}
				}while(op != 2);				
				y = 0;
				op = 0;
				system("cls");
			break;
			
			case 0:
				system("cls");
			break;
			default:
				printf("\nDigite uma opcao valida!\n\n");	
		}
	}while(menu_busca != 0);
}

void AtualizaServico(Servico * pnt_cadastroServico)
{
	FILE *pont_servico;
	int menu_atualiza = 0;
	int codigo = 0;
	char descricao[30];
	float preco = 0.0;
	int y = 0;
	int a = 2;
	int r = 0;
	char s;
	
	system("cls");
	
	y = 0;
	
	do{
		menu_atualiza = 0;
		MenuAtualizaServico();
		menu_atualiza = ObtemInteiroValidoServico(menu_atualiza);
		system("cls");	
		switch(menu_atualiza)
		{
			case 1:			
				
				y = LeArquivoServico(pnt_cadastroServico);

					printf("\nATUALIZAR DESCRICAO\n");
					printf("-------------------\n\n");
					printf("Informe o CODIGO do servico: ");
					codigo = ObtemInteiroValidoServico(codigo);
					printf("\n\n");
					
					a = 0;
					
					do{
						for(int i = 0; i < y; i++)
						{	
							if(pnt_cadastroServico[i].codigo == codigo)
							{
								printf("╔════════════════════════════════════════════════════════════════════╗\n");
								printf("║                        **SERVICO ENCONTRADO**                      ║\n");
								printf("╠════════════════════════════════════════════════════════════════════╣\n");
								printf("║ COD │                   DESCRICAO                 │      PRECO     ║\n");
								printf("╟────────────────────────────────────────────────────────────────────╢\n");
								printf("╟────────────────────────────────────────────────────────────────────╢\n");
								printf("║%5d│\033[32m%45s\033[0m│%5d│%25s│%6d│%4s│%16.2f│%16.2f║\n",
										 pnt_cadastroServico[i].codigo,
										 pnt_cadastroServico[i].descricao,
										 pnt_cadastroServico[i].preco);
								printf("╟────────────────────────────────────────────────────────────────────╢\n");
								printf("╚════════════════════════════════════════════════════════════════════╝\n\n");
								
								printf("Informe a NOVA DESCRICAO: ");
								scanf(" %[^\n]",descricao);
								
								// Limpar a string, remover espaços extras antes e depois
								LimpaStringServico(descricao);
								// Converter a unidade para maiúsculas
								ConverteMaiusculaServico(descricao);
								
								strcpy(pnt_cadastroServico[i].descricao, descricao);
								printf("\n");
								printf("╔════════════════════════════════════════════════════════════════════╗\n");
								printf("║                      **DESCRICAO ATUALIZADA**                      ║\n");
								printf("╠════════════════════════════════════════════════════════════════════╣\n");
								printf("║ COD │                   DESCRICAO                 │      PRECO     ║\n");
								printf("╟────────────────────────────────────────────────────────────────────╢\n");
								printf("╟────────────────────────────────────────────────────────────────────╢\n");
								printf("║%5d│\033[32m%45s\033[0m│%16.2f║\n",
										 pnt_cadastroServico[i].codigo,
										 pnt_cadastroServico[i].descricao,
										 pnt_cadastroServico[i].preco);
								printf("╟────────────────────────────────────────────────────────────────────╢\n");
								printf("╚════════════════════════════════════════════════════════════════════╝\n\n");
								
								a = 1;
							}
							
						}
						if(a == 0)
						{
							printf("\n");
							printf("███████████████████████████████████████\n\a");
							printf("█                                     █\n");
							printf("█        SERVICO NAO ENCONTRADO!      █\n");
							printf("█                                     █\n");
							printf("███████████████████████████████████████\n\n");
						}
						printf("\nAperte uma tecla para continuar... ");
						system("pause > nul");
					a = 1;
					}while(a != 1);	
					
					pont_servico = fopen("servico.txt","w");	
					
					for(int i = 0; i < y; i++)
					{
						fprintf(pont_servico,"%d\n%s\n%.2f\n",
											pnt_cadastroServico[i].codigo,
											pnt_cadastroServico[i].descricao,
											pnt_cadastroServico[i].preco);
					}
					a = 0;
					y = 0;					
					fclose(pont_servico);
					system("cls");					
				
			break;
			case 2:			
				y = LeArquivoServico(pnt_cadastroServico);
					
					printf("\nATUALIZAR PRECO\n");
					printf("---------------\n\n");
					printf("Informe o CODIGO do servico: ");
					codigo = ObtemInteiroValidoServico(codigo);
					printf("\n\n");
					do{
						for(int i = 0; i < y; i++)
						{	
							if(pnt_cadastroServico[i].codigo == codigo)
							{
								printf("╔════════════════════════════════════════════════════════════════════╗\n");
								printf("║                        **SERVICO ENCONTRADO**                      ║\n");
								printf("╠════════════════════════════════════════════════════════════════════╣\n");
								printf("║ COD │                   DESCRICAO                 │      PRECO     ║\n");
								printf("╟────────────────────────────────────────────────────────────────────╢\n");
								printf("╟────────────────────────────────────────────────────────────────────╢\n");
								printf("║%5d│\033[32m%45s\033[0m│%16.2f║\n",
										 pnt_cadastroServico[i].codigo,
										 pnt_cadastroServico[i].descricao,
										 pnt_cadastroServico[i].preco);
								printf("╟────────────────────────────────────────────────────────────────────╢\n");
								printf("╚════════════════════════════════════════════════════════════════════╝\n\n");
								
								printf("Informe o NOVO PRECO: ");
								preco = ObtemFloatValidoServico();
								pnt_cadastroServico[i].preco = preco;
								
								printf("\n");
								printf("╔════════════════════════════════════════════════════════════════════╗\n");
								printf("║                         **PRECO ATUALIZADO**                       ║\n");
								printf("╠════════════════════════════════════════════════════════════════════╣\n");
								printf("║ COD │                   DESCRICAO                 │      PRECO     ║\n");
								printf("╟────────────────────────────────────────────────────────────────────╢\n");
								printf("╟────────────────────────────────────────────────────────────────────╢\n");
								printf("║%5d│%45s│\033[32m%16.2f\033[0m║\n",
										 pnt_cadastroServico[i].codigo,
										 pnt_cadastroServico[i].descricao,
										 pnt_cadastroServico[i].preco);
								printf("╟────────────────────────────────────────────────────────────────────╢\n");
								printf("╚════════════════════════════════════════════════════════════════════╝\n\n");
								
								a = 1;
							}	
						}
						
						if(a == 0)
						{
							printf("\n");
							printf("███████████████████████████████████████\n\a");
							printf("█                                     █\n");
							printf("█        SERVICO NAO ENCONTRADO!      █\n");
							printf("█                                     █\n");
							printf("███████████████████████████████████████\n\n");
						}
						printf("\nAperte uma tecla para continuar... ");
						system("pause > nul");
					a = 1;
					}while(a != 1);	
					
					pont_servico = fopen("servico.txt","w");	
					
					for(int i = 0; i < y; i++)
					{
						fprintf(pont_servico,"%d\n%s\n%.2f\n",
											pnt_cadastroServico[i].codigo,
											pnt_cadastroServico[i].descricao,
											pnt_cadastroServico[i].preco);
					}
					a = 0;
					y = 0;					
					fclose(pont_servico);
					system("cls");
			break;
			case 0:
				system("cls");
			break;
			default:
				printf("\n\nDigite uma opcao valida!\n\n");
		}			
	}while(menu_atualiza != 0);	
	
}

void RemoveServico(Servico * pnt_cadastroServico)
{
	FILE *pont_servico;
	int y = 0;
	int r = 0;
	int op = 0;
	int codigo = 0;
	int menu_remove = 0;
	
	system("cls");
		
	do{
		r = 0;
		y = 0;
		
		y = LeArquivoServico(pnt_cadastroServico);
			
		printf("\n");
			
		printf("REMOVER SERVICO\n");
		printf("---------------\n\n");
		printf("Informe o CODIGO do servico a ser removido: ");
		codigo = ObtemInteiroValidoServico(codigo);
		printf("\n");
			
		for(int i = 0; i < y; i++)
		{
			if(pnt_cadastroServico[i].codigo == codigo)
			{
				printf("\n");
				printf("╔════════════════════════════════════════════════════════════════════╗\n");
				printf("║                        **SERVICO ENCONTRADO**                      ║\n");
				printf("╠════════════════════════════════════════════════════════════════════╣\n");
				printf("║ COD │                   DESCRICAO                 │      PRECO     ║\n");
				printf("╟────────────────────────────────────────────────────────────────────╢\n");
				printf("╟────────────────────────────────────────────────────────────────────╢\n");
				printf("║\033[31m%5d\033[0m│\033[31m%45s\033[0m│%16.2f║\n",
						 pnt_cadastroServico[i].codigo,
						 pnt_cadastroServico[i].descricao,
						 pnt_cadastroServico[i].preco);
				printf("╟────────────────────────────────────────────────────────────────────╢\n");
				printf("╚════════════════════════════════════════════════════════════════════╝\n\n");
				r = 1;
			}
		}	
			
		if(r == 1)
		{
			printf("\nRemover servico - 1\n");
			printf("Cancelar remocao e continuar busca - 2\n");
			printf("Cancelar remocao e voltar ao MENU INICIAL - 0\n");
			menu_remove = ObtemInteiroValidoServico(menu_remove);
			
			switch (menu_remove)
			{
				case 1:
					pont_servico = fopen("servico.txt","w");
					
					for(int i = 0; i < y; i++)
					{
						if(pnt_cadastroServico[i].codigo != codigo)
						{
							fprintf(pont_servico,"%d\n%s\n%.2f\n",
											  pnt_cadastroServico[i].codigo,
											  pnt_cadastroServico[i].descricao,
											  pnt_cadastroServico[i].preco);
						}
					}
						
					fclose(pont_servico);
					
					system("cls");
					printf("\n\nSERVICO REMOVIDO\n\n");
					printf("Remover outro produto - 1 | Voltar ao MENU INICIAL - 2\n");
					op = ObtemInteiroValidoServico(op);
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
								printf("Remover outro servico - 1 | Voltar ao MENU INICIAL - 2\n");
								op = ObtemInteiroValidoServico(op);
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
						printf("\nRemover servico - 1\n");
						printf("Cancelar remocao e continuar busca - 2\n");
						printf("Cancelar remocao e voltar ao MENU INICIAL - 0\n");
						menu_remove = ObtemInteiroValidoServico(menu_remove);
					}while(menu_remove < 0 || menu_remove > 2);
			}
		}
		if(r == 0)
		{
			printf("\n");
			printf("███████████████████████████████████████\n\a");
			printf("█                                     █\n");
			printf("█        SERVICO NAO ENCONTRADO!      █\n");
			printf("█                                     █\n");
			printf("███████████████████████████████████████\n\n");
				
			printf("Continuar busca - 1 | Voltar ao MENU INICIAL - 0\n");
			menu_remove = ObtemInteiroValidoServico(menu_remove);
				
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
						
						menu_remove = ObtemInteiroValidoServico(menu_remove);
						
					}while(menu_remove < 0 || menu_remove > 1);
			}		
		}	
	}while(r != 2);	
}

void ApagaSistemaServico(Servico  * pnt_cadastroServico)
{
	FILE * pont_servico;
	int op = -1;
	
	system("cls");
	
	printf("\n███████████████████████████████████████████████████████████████████████████\n\a");
	printf("█                                                                         █\n");
	printf("█   \033[31mATENCAO!\033[0m Todos os DADOS de SERVICOS do sistema serao DELETADOS...     █\n");
	printf("█                                                                         █\n");
	printf("███████████████████████████████████████████████████████████████████████████\n\n");
	
	printf("Confirmar - 1 | Cancelar - 0\n");
	op = ObtemInteiroValidoServico(op);
	if(op < 0 || op > 1)
	{
		do{
			system("cls");
		
			printf("\n███████████████████████████████████████████████████████████████████████████\n\a");
			printf("█                                                                         █\n");
			printf("█   \033[31mATENCAO!\033[0m Todos os DADOS de SERVICOS do sistema serao DELETADOS...     █\n");
			printf("█                                                                         █\n");
			printf("███████████████████████████████████████████████████████████████████████████\n\n");
			
			printf("Confirmar - 1 | Cancelar - 0\n");
			printf("\nDigite uma opcao valida!\n\n");
			op = ObtemInteiroValidoServico(op);
		}while(op < 0 || op > 1);
	}
	
	switch(op)
	{
		case 1:
			if(pont_servico != NULL)
			{
				pont_servico = fopen("servico.txt","w");
				fprintf(pont_servico,"%s","");
				fclose(pont_servico);
				system("cls");
				printf("\n\nDADOS REMOVIDOS\n\n");
				printf("\nAperte qualquer tecla para voltar ao MENU INICIAL...");
				system("pause > nul");
				system("cls");
			}	
			
			else
			{
				system("cls");
				printf("\n\n\aOs dados de servicos nao foram apagados...\n\n");
				printf("ERRO ao acessar o arquivo! Contate o administrador do sistema\n\n");
				printf("\nAperte qualquer tecla para voltar ao MENU INICIAL...");
				system("pause > nul");
				system("cls");
			}
		break;
		case 0:
			printf("\n\nACAO CANCELADA\n\n");
			printf("\nAperte qualquer tecla para voltar ao MENU INICIAL...");
			system("pause > nul");
			system("cls");
	}
}
