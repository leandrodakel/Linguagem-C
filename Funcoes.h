void Menu();
void Filtro();
void Ordem();
void Imprimir(Estoque * pnt_deposito, int tam);
void CadastraProduto(Estoque * pnt_deposito);
void ListaProduto(Estoque * pnt_deposito);
void BuscaProduto(Estoque * pnt_deposito);
void AtualizaProduto(Estoque  * pnt_deposito);
void RemoveProduto(Estoque * pnt_deposito);
void CalculaTotal(Estoque  * pnt_deposito);
void AutomatizaCodigo(Estoque  * pnt_deposito);
int ComparaPalavras(char *palavra1, char *palavra2);
void BubbleSortCodigo(Estoque * pnt_deposito, int opcao, int tamanho);
void BubbleSortQuantidade(Estoque * pnt_deposito, int opcao, int tamanho);
void BubbleSortPreco(Estoque * pnt_deposito, int opcao, int tamanho);
void BubbleSortDescricao(Estoque * pnt_deposito, int opcao, int tamanho);
void FiltraOrdena(Estoque  * pnt_deposito);
void ApagaDadosSistema(Estoque  * pnt_deposito);

void Menu()
{
	system("chcp 65001");
	system("color 07");
	printf("\n");
	
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("║               *** B E M - V I N D O ***           ║\n");
	printf("║          GERENCIADOR DE ESTOQUE DE PRODUTOS       ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                     \033[32m**CONSULTAS**\033[0m ║\n");
	printf("║                                                   ║\n");
	printf("║   \033[32mOpções que nao alteram o banco de dados\033[0m         ║\n");
	printf("║                                                   ║\n");
	printf("║   \033[32mListar produtos ---------------------- 1\033[0m        ║\n");
	printf("║   \033[32mFiltrar e ordenar estoque ------------ 2\033[0m        ║\n");
	printf("║   \033[32mBuscar produto por codigo ------------ 3\033[0m        ║\n");
	printf("║   \033[32mCalcular valor total do estoque ------ 4\033[0m        ║\n");
	printf("║                                                   ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                   \033[33m**ATUALIZACAO**\033[0m ║\n");
	printf("║                                                   ║\n");
	printf("║   \033[33mOpcoes que alteram o banco de dados\033[0m             ║\n");
	printf("║                                                   ║\n");
	printf("║   \033[33mCadastrar produtos ------------------- 5\033[0m        ║\n");
	printf("║   \033[33mAtualizar quantidade em estoque ------ 6\033[0m        ║\n");
	printf("║                                                   ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                       \033[31m**DELETAR**\033[0m ║\n");
	printf("║                                                   ║\n");
	printf("║   \033[31mAlteracoes irreversiveis no banco de dados\033[0m      ║\n");
	printf("║                                                   ║\n");
	printf("║   \033[31mReordenar codigos -------------------- 7\033[0m        ║\n");
	printf("║   \033[31mRemove produto ----------------------- 8\033[0m        ║\n");
	printf("║   \033[31mApagar TODOS os itens do estoque ----- 9\033[0m        ║\n");
	printf("║                                                   ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                                   ║\n");
	printf("║   Encerrar sistema  -------------------- 0        ║\n");
	printf("║                                                   ║\n");
	printf("╚═══════════════════════════════════════════════════╝\n\n");
	
	
	
	
	
	
	
}



void Filtro()
{
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("║              ORDENAR E FILTRAR LISTA              ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                                   ║\n");
	printf("║         Filtrar por DESCRICAO ---------- 1        ║\n");
	printf("║         Filtrar por CODIGO ------------- 2        ║\n");
	printf("║         Filtrar por QUANTIDADE --------- 3        ║\n");
	printf("║         Filtrar por PRECO -------------- 4        ║\n");
	printf("║                                                   ║\n");
	printf("╚═══════════════════════════════════════════════════╝\n\n");
	
}

void Ordem()
{
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("║              ORDENAR E FILTRAR LISTA              ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                                   ║\n");
	printf("║            Ordem CRESCENTE ----------- 1          ║\n");
	printf("║            Ordem DECRESCENTE --------- 2          ║\n");
	printf("║                                                   ║\n");
	printf("╚═══════════════════════════════════════════════════╝\n\n");
	
}

void Imprimir(Estoque * pnt_deposito, int tam)
{
	int i = 0;
	printf("╔══════════════════════════════════════════════════════════════╗\n");
	printf("║ COD |        DESCRICAO         | QUANTIDADE | VALOR UNITARIO ║\n");
	printf("╟──────────────────────────────────────────────────────────────╢\n");
	for(i = 0; i < tam; i++)
	{
		printf("║%5d|\033[32m%26s\033[0m|%12d|%16.2f║\n",pnt_deposito[i].codigo,pnt_deposito[i].descricao,pnt_deposito[i].quantidade,pnt_deposito[i].preco);
	}
	printf("╚══════════════════════════════════════════════════════════════╝\n\n");	
}

void CadastraProduto(Estoque * pnt_deposito)
{
	FILE *pont_arq;
	int k = 1;
	int y = 0;
	int codigo = 0;
	int cadastro = 0;
	
	pont_arq = fopen("estoque.txt","r");
	
	while(fscanf(pont_arq,"%d\n%[^\n]\n%d\n%f\n",&pnt_deposito[y].codigo,pnt_deposito[y].descricao,&pnt_deposito[y].quantidade,&pnt_deposito[y].preco) != EOF)
	{
		y++;
	}
	
	fclose(pont_arq);
	
	//Obtendo codigo para auto incremento
	codigo = pnt_deposito[y-1].codigo + 1;
	
	
	pont_arq = fopen("estoque.txt","a");
				
	if(pont_arq == NULL)
	{
		printf("ERRO! O arquivo nao foi aberto!\n\n");
	}
	else
	{
		printf("O arquivo foi aberto com sucesso\n\n");
		
		printf("\nCADASTRO DE PRODUTOS\n");
		printf("----------------------\n\n");	
		printf("Informe quantos produtos deseja cadastrar: ");
		LimpaBuffer();
		cadastro = ObtemInteiroValido();
		
		for(int i = 0; i < cadastro; i++)
		{
		
			//printf("Informe o codigo do produto 0%d : ",k);
			//scanf("%d",&pnt_deposito[i].codigo);
			printf("Informe o descricao do produto 0%d : ",k);
			scanf(" %[^\n]",pnt_deposito[i].descricao);
			printf("Informe a quantidade do produto 0%d : ",k);
			scanf("%d",&pnt_deposito[i].quantidade);
			printf("Informe o preco do produto 0%d : ",k);
			scanf("%f",&pnt_deposito[i].preco);
			printf("\n");	
			fprintf(pont_arq,"%d\n%s\n%d\n%.2f\n",codigo,pnt_deposito[i].descricao,pnt_deposito[i].quantidade,pnt_deposito[i].preco);
			k++;
			codigo++;	
		}
			fclose(pont_arq);
	}
	system("cls");
	printf("\n\nCADASTRO CONCLUIDO\n\n");
}
	
void ListaProduto(Estoque * pnt_deposito)
{
	FILE *pont_arq;
	int y = 0;
	
	printf("\nLISTA DE PRODUTOS\n");
	printf("-------------------\n\n");	
	pont_arq = fopen("estoque.txt","r");
	
	printf("╔══════════════════════════════════════════════════════════════╗\n");
	printf("║                     **LISTA DE PRODUTOS**                    ║\n");
	printf("╠══════════════════════════════════════════════════════════════╣\n");	
	printf("║ COD |        DESCRICAO         | QUANTIDADE | VALOR UNITARIO ║\n");
	printf("╟──────────────────────────────────────────────────────────────╢\n");
	while(fscanf(pont_arq,"%d\n%[^\n]\n%d\n%f\n",&pnt_deposito[y].codigo,pnt_deposito[y].descricao,&pnt_deposito[y].quantidade,&pnt_deposito[y].preco) != EOF)
	{
		printf("║%5d|\033[32m%26s\033[0m|%12d|%16.2lf║\n",pnt_deposito[y].codigo,pnt_deposito[y].descricao,pnt_deposito[y].quantidade,pnt_deposito[y].preco);
		y++;
	}
	printf("╚══════════════════════════════════════════════════════════════╝\n");	
	fclose(pont_arq);
	printf("\nAperte qualquer tecla para continuar... ");
	system("pause");
}

void BuscaProduto(Estoque * pnt_deposito)
{
	FILE *pont_arq;
	int menu_busca = 0;
	int y = 0;
	int t = 0;
	int indice_codigo = 0;
	
	pont_arq = fopen("estoque.txt","r");
	while(fscanf(pont_arq,"%d\n%[^\n]\n%d\n%f\n",&pnt_deposito[y].codigo,pnt_deposito[y].descricao,&pnt_deposito[y].quantidade,&pnt_deposito[y].preco) != EOF)
	{
		y++;
	}				
	do{
		printf("\nBUSCA DE PRODUTO POR CODIGO\n");
		printf("-----------------------------\n\n");
		printf("Informe o codigo do produto: ");
		scanf("%d",&indice_codigo);
		for(int i = 0; i < y; i++)
		{	
			if(pnt_deposito[i].codigo == indice_codigo)
			{
				printf("╔══════════════════════════════════════════════════════════════╗\n");
				printf("║                **BUSCA DE PRODUTO POR CODIGO**               ║\n");
				printf("╠══════════════════════════════════════════════════════════════╣\n");	
				printf("║ COD |        DESCRICAO         | QUANTIDADE | VALOR UNITARIO ║\n");
				printf("╟──────────────────────────────────────────────────────────────╢\n");
				printf("║%5d|%26s|%12d|%16.2lf║\n",pnt_deposito[i].codigo,pnt_deposito[i].descricao,pnt_deposito[i].quantidade,pnt_deposito[i].preco);
				printf("╚══════════════════════════════════════════════════════════════╝\n");
				t = 1;
			}	
		}
		if(t == 0)
		{
			printf("███████████████████████████████████████\n\a");
			printf("█                                     █\n");
			printf("█        PRODUTO NAO ENCONTRADO!      █\n");
			printf("█                                     █\n");
			printf("███████████████████████████████████████\n\n");	
		}
		printf("Continuar busca - 1 | Voltar ao menu - 2 ");
		scanf("%d",&menu_busca);
		printf("\n");
		t = 0;
	}while(menu_busca != 2);
	printf("\nAperte qualquer tecla para continuar... ");
	system("pause");
	system("cls");
	printf("\n\nBUSCA ENCERRADA\n\n");
	fclose(pont_arq);
}

void AtualizaProduto(Estoque * pnt_deposito)
{
	FILE *pont_arq;
	int menu_atualiza = 0;
	int quantidade = 0;
	int y = 0;
	int a = 2;
	int r = 0;
	char s;
	int indice_codigo = 0;
	y = 0;
	
	do{
		printf("\nATUALIZAR ESTOQUE\n");
		printf("-------------------\n\n");
		printf("Atualizar quantidade - 1\nVoltar ao menu inicial - 2 ");
		scanf("%d",&menu_atualiza);
		system("cls");	
		switch(menu_atualiza)
		{
			case 1:			
				pont_arq = fopen("estoque.txt","r");		
				if(pont_arq == NULL)
				{
					printf("\nERRO! O arquivo nao foi aberto!\n\n");
				}
				else
				{
					printf("\nO arquivo foi aberto com sucesso\n\n");
					while(fscanf(pont_arq,"%d\n%[^\n]\n%d\n%f\n",&pnt_deposito[y].codigo,pnt_deposito[y].descricao,&pnt_deposito[y].quantidade,&pnt_deposito[y].preco) != EOF)
					{
						y++;
					}
					fclose(pont_arq);
					printf("ATUALIZAR QUANTIDADE\n");
					printf("--------------------\n\n");
					printf("Informe o codigo do produto: ");
					scanf("%d",&indice_codigo);
					printf("\n\n");
					do{
						for(int i = 0; i <= y; i++)
						{	
							if(pnt_deposito[i].codigo == indice_codigo)
							{
								printf("Codigo: %d\n",pnt_deposito[i].codigo);
								printf("Descricao: %s\n",pnt_deposito[i].descricao);
								printf("Quantidade: %d\n",pnt_deposito[i].quantidade);
								printf("Preco unitario: %.2f\n\n",pnt_deposito[i].preco);
								printf("Informe a nova quantidade: ");
								scanf("%d",&quantidade);
								pnt_deposito[i].quantidade = quantidade;
								printf("\n\n------------------------------------------------\n\n");
								printf("╔══════════════════════════════════════════════════════════════╗\n");
								printf("║                     **ESTOQUE ATUALIZADO**                   ║\n");
								printf("╠══════════════════════════════════════════════════════════════╣\n");	
								printf("║ COD |        DESCRICAO         | QUANTIDADE | VALOR UNITARIO ║\n");
								printf("╟──────────────────────────────────────────────────────────────╢\n");
								printf("║%5d|%26s|%12d|%16.2lf║\n",pnt_deposito[i].codigo,pnt_deposito[i].descricao,pnt_deposito[i].quantidade,pnt_deposito[i].preco);
								printf("╚══════════════════════════════════════════════════════════════╝\n");
								
								a = 1;
							}
							if(a == 0)
							{
								printf("███████████████████████████████████████\n\a");
								printf("█                                     █\n");
								printf("█        PRODUTO NAO ENCONTRADO!      █\n");
								printf("█                                     █\n");
								printf("███████████████████████████████████████\n\n");
							}	
						}
					}while(a != 1);	
					pont_arq = fopen("estoque.txt","w");	
					for(int i = 0; i < y; i++)
					{
						fprintf(pont_arq,"%d\n%s\n%d\n%.2f\n",pnt_deposito[i].codigo,pnt_deposito[i].descricao,pnt_deposito[i].quantidade,pnt_deposito[i].preco);
					}
					
					y = 0;					
					fclose(pont_arq);
										
				}
			break;
			
		}			
	}while(menu_atualiza != 2);	
	printf("\nAperte qualquer tecla para continuar... ");
	system("pause");
	system("cls");
	printf("\n\nESTOQUE ATUALIZADO\n\n");
}

void RemoveProduto(Estoque * pnt_deposito)
{
	FILE *pont_arq;
	int y = 0;
	int r = 0;
	int codigo = 0;
	
	pont_arq = fopen("estoque.txt","r");	
	if(pont_arq == NULL)
	{
		printf("\nERRO! O arquivo nao foi aberto!\n\n");
	}
	else
	{
		printf("\nO arquivo foi aberto com sucesso\n\n");
		while(fscanf(pont_arq,"%d\n%[^\n]\n%d\n%f\n",&pnt_deposito[y].codigo,pnt_deposito[y].descricao,&pnt_deposito[y].quantidade,&pnt_deposito[y].preco) != EOF)
		{
			y++;
		}
		fclose(pont_arq);	
		pont_arq = fopen("estoque.txt","w");
		printf("REMOVER PRODUTO\n");
		printf("---------------\n\n");
		printf("Informe o codigo do produto a ser removido: ");
		scanf("%d",&codigo);
		printf("\n");
		do{
			for(int i = 0; i < y; i++)
			{
				if(pnt_deposito[i].codigo == codigo)
				{
					printf("╔══════════════════════════════════════════════════════════════╗\n");
					printf("║                     **PRODUTO ENCONTRADO**                   ║\n");
					printf("╠══════════════════════════════════════════════════════════════╣\n");	
					printf("║ COD |        DESCRICAO         | QUANTIDADE | VALOR UNITARIO ║\n");
					printf("╟──────────────────────────────────────────────────────────────╢\n");
					printf("║%5d|%26s|%12d|%16.2lf║\n",pnt_deposito[i].codigo,pnt_deposito[i].descricao,pnt_deposito[i].quantidade,pnt_deposito[i].preco);
					printf("╚══════════════════════════════════════════════════════════════╝\n");
					r = 1;	
				}
				
				if(pnt_deposito[i].codigo != codigo)
				{
					fprintf(pont_arq,"%d\n%s\n%d\n%.2f\n",pnt_deposito[i].codigo,pnt_deposito[i].descricao,pnt_deposito[i].quantidade,pnt_deposito[i].preco);
				}
				
			}
			if(r == 0)
			{
				printf("███████████████████████████████████████\n\a");
				printf("█                                     █\n");
				printf("█        PRODUTO NAO ENCONTRADO!      █\n");
				printf("█                                     █\n");
				printf("███████████████████████████████████████\n\n");
				break;
			}
			else if(r == 1)
			{
				printf("PRODUTO REMOVIDO!\n\n");
			}
			
		}while(r != 1);
	}
	fclose(pont_arq);
}

void CalculaTotal(Estoque * pnt_deposito)
{
	system("color 07");
	FILE *pont_arq;
	float acumulador = 0.0;
	int y = 0;
	
	pont_arq = fopen("estoque.txt","r");
			
	while(fscanf(pont_arq,"%d\n%[^\n]\n%d\n%f\n",&pnt_deposito[y].codigo,pnt_deposito[y].descricao,&pnt_deposito[y].quantidade,&pnt_deposito[y].preco) != EOF)
	{
		y++;
	}
	for(int i = 0; i < y; i++)
	{
		acumulador += pnt_deposito[i].quantidade * pnt_deposito[i].preco;
	}
	printf("╔═════════════════════════════════════╗\n");
	printf("║      **VALOR TOTAL DO ESTOQUE**     ║\n");
	printf("╠═════════════════════════════════════╣\n");	
	printf("║\033[32mR$ %.2f                            ║\033[0m\n",acumulador);
	printf("╚═════════════════════════════════════╝\n");
	fclose(pont_arq);	
}

void ReordenaCodigo(Estoque  * pnt_deposito)
{
	FILE *pont_arq;
	int y = 0;
	pont_arq = fopen("estoque.txt","r");
	while(fscanf(pont_arq,"%d\n%[^\n]\n%d\n%f\n",&pnt_deposito[y].codigo,pnt_deposito[y].descricao,&pnt_deposito[y].quantidade,&pnt_deposito[y].preco) != EOF)
	{
		//printf("|%5d|%26s|%12d|%16.2lf|\n",pnt_deposito[y].codigo,pnt_deposito[y].descricao,pnt_deposito[y].quantidade,pnt_deposito[y].preco);
		y++;
	}
	fclose(pont_arq);
	pont_arq = fopen("estoque.txt","w");
	
	for(int i = 0; i < y; i++)
	{
		pnt_deposito[i].codigo = i + 1;
		fprintf(pont_arq,"%d\n%s\n%d\n%.2f\n",pnt_deposito[i].codigo,pnt_deposito[i].descricao,pnt_deposito[i].quantidade,pnt_deposito[i].preco);
	}
	system("cls");
	printf("\n\nCODIGOS REORDENADOS\n\n");
	fclose(pont_arq);
}

int ComparaPalavras(char *palavra1, char *palavra2)
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

void BubbleSortCodigo(Estoque * pnt_deposito, int opcao, int tamanho)
{
	Estoque aux;
	if(opcao == 1)
	{	
		for(int i = 0; i < tamanho; i++)
		{
			for(int k = 0; k < tamanho-1; k++)
			{
				if(pnt_deposito[i].codigo < pnt_deposito[k].codigo)
				{
					aux = pnt_deposito[i];
					pnt_deposito[i] = pnt_deposito[k];
					pnt_deposito[k] = aux;
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
				if(pnt_deposito[i].codigo > pnt_deposito[k].codigo)
				{
					aux = pnt_deposito[i];
					pnt_deposito[i] = pnt_deposito[k];
					pnt_deposito[k] = aux;
				}
			}
		}
	}
	
}

void BubbleSortQuantidade(Estoque * pnt_deposito, int opcao, int tamanho)
{
	Estoque aux;
	if(opcao == 1)
	{	
		for(int i = 0; i < tamanho; i++)
		{
			for(int k = 0; k < tamanho-1; k++)
			{
				if(pnt_deposito[i].quantidade < pnt_deposito[k].quantidade)
				{
					aux = pnt_deposito[i];
					pnt_deposito[i] = pnt_deposito[k];
					pnt_deposito[k] = aux;
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
				if(pnt_deposito[i].quantidade > pnt_deposito[k].quantidade)
				{
					aux = pnt_deposito[i];
					pnt_deposito[i] = pnt_deposito[k];
					pnt_deposito[k] = aux;
				}
			}
		}
	}
	
}

void BubbleSortPreco(Estoque * pnt_deposito, int opcao, int tamanho)
{
	Estoque aux;
	if(opcao == 1)
	{	
		for(int i = 0; i < tamanho; i++)
		{
			for(int k = 0; k < tamanho-1; k++)
			{
				if(pnt_deposito[i].preco < pnt_deposito[k].preco)
				{
					aux = pnt_deposito[i];
					pnt_deposito[i] = pnt_deposito[k];
					pnt_deposito[k] = aux;
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
				if(pnt_deposito[i].preco > pnt_deposito[k].preco)
				{
					aux = pnt_deposito[i];
					pnt_deposito[i] = pnt_deposito[k];
					pnt_deposito[k] = aux;
				}
			}
		}
	}
	
}

void BubbleSortDescricao(Estoque * pnt_deposito, int opcao, int tamanho)
{
	Estoque aux;
	int troca = -1;

	for(int i = 0; i < tamanho; i++)
	{
		for(int k = 0; k < tamanho-1; k++)
		{
			if(opcao == 1)
			{
				troca = ComparaPalavras(pnt_deposito[i].descricao,pnt_deposito[k].descricao);
				if(!troca)
				{
					aux = pnt_deposito[i];
					pnt_deposito[i] = pnt_deposito[k];
					pnt_deposito[k] = aux;
				}
			}
			else
			{
				troca = ComparaPalavras(pnt_deposito[i].descricao,pnt_deposito[k].descricao);
				if(troca)
				{
					aux = pnt_deposito[i];
					pnt_deposito[i] = pnt_deposito[k];
					pnt_deposito[k] = aux;
				}
			}
		}
	}
}

void FiltraOrdena(Estoque  * pnt_deposito)
{
	FILE * pont_arq;
	int i = 0;
	int escolha = 0;
	pont_arq = fopen("estoque.txt","r");
	system("cls");
	if(pont_arq != NULL)
	{
		while(fscanf(pont_arq,"%d\n%[^\n]\n%d\n%f\n",&pnt_deposito[i].codigo,pnt_deposito[i].descricao,&pnt_deposito[i].quantidade,&pnt_deposito[i].preco) != EOF)
		{
			i++;
		}
		fclose(pont_arq);		
		Filtro();
		scanf("%d",&escolha);
		system("cls");
		switch(escolha)
		{
			//Ordenar por Descrição do produto(s);
			case 1:
				Ordem();
				scanf("%d",&escolha);
				switch(escolha)
				{
					//Crescente 
					case 1:
						BubbleSortDescricao(pnt_deposito, escolha, i);
						system("cls");
						printf("\n╔══════════════════════════════════════════════════════════════╗\n");
						printf("║              **FILTRAGEM POR DESCRICAO - CRESCENTE**         ║\n");
						Imprimir(pnt_deposito, i);
					break;
					//Decrescente 
					case 2:
						BubbleSortDescricao(pnt_deposito, escolha, i);
						system("cls");
						printf("\n╔══════════════════════════════════════════════════════════════╗\n");
						printf("║              **FILTRAGEM POR DESCRICAO - CRESCENTE**         ║\n");
						Imprimir(pnt_deposito, i);
					break;
					//Caso não seja escolhido uma opção válida
					default:
						printf("Escolha uma opcao valida no sistema!\n");
				}
			break;
			//Ordernar por Codigo do produto;
			case 2:
				Ordem();
				scanf("%d",&escolha);
				switch(escolha)
				{
					//Crescente 
					case 1:
						BubbleSortCodigo(pnt_deposito, escolha, i);
						system("cls");
						printf("\n╔══════════════════════════════════════════════════════════════╗\n");
						printf("║              **FILTRAGEM POR CODIGO - CRESCENTE**            ║\n");
						Imprimir(pnt_deposito, i);
					break;
					//Decrescente 
					case 2:
						BubbleSortCodigo(pnt_deposito, escolha, i);
						system("cls");
						printf("\n╔══════════════════════════════════════════════════════════════╗\n");
						printf("║             **FILTRAGEM POR CODIGO - DECRESCENTE**           ║\n");
						Imprimir(pnt_deposito, i);
					break;
					//Caso não seja escolhido uma opção válida
					default:
						printf("Escolha uma opcao valida no sistema!\n");
				}
			break;
			//Ordernar por Quantidade de produtos no estoque;
			case 3:
				Ordem();
				scanf("%d",&escolha);
				switch(escolha)
				{
					//Crescente 
					case 1:
						
						BubbleSortQuantidade(pnt_deposito, escolha, i);
						system("cls");
						printf("\n╔══════════════════════════════════════════════════════════════╗\n");
						printf("║             **FILTRAGEM POR QUANTIDADE - CRESCENTE**         ║\n");
						Imprimir(pnt_deposito, i);
					break;
					//Decrescente
					case 2:
						BubbleSortQuantidade(pnt_deposito, escolha, i);
						system("cls");
						printf("\n╔══════════════════════════════════════════════════════════════╗\n");
						printf("║          **FILTRAGEM POR QUANTIDADE - DECRESCENTE**          ║\n");
						Imprimir(pnt_deposito, i);
					break;
					//Caso não seja escolhido uma opção válida
					default:
						printf("Escolha uma opcao valida no sistema!\n");
				}
			break;
			//Ordernar por Preco do Produto;
			case 4:
				Ordem();
				scanf("%d",&escolha);
				switch(escolha)
				{
					//Crescente 
					case 1:
						BubbleSortPreco(pnt_deposito, escolha, i);
						system("cls");
						printf("\n╔══════════════════════════════════════════════════════════════╗\n");
						printf("║             **FILTRAGEM POR PRECO - CRESCENTE**              ║\n");
						Imprimir(pnt_deposito, i);
					break;
					//Decrescente 
					case 2:
						BubbleSortPreco(pnt_deposito, escolha, i);
						system("cls");
						printf("\n╔══════════════════════════════════════════════════════════════╗\n");
						printf("║             **FILTRAGEM POR PRECO - DECRESCENTE**            ║\n");
						Imprimir(pnt_deposito, i);
					break;
					//Caso não seja escolhido uma opção válida
					default:
						printf("Escolha uma opcao valida no sistema!\n");
				}
			break;
			//Caso não seja escolhido uma opção válida
			default:
				printf("Escolha uma opcao valida no sistema!\n");
		}
	}
	else
	{
		printf("ERRO ao acessar o arquivo! Contate o administrador do sistema\n");
	}
	
}

void ApagaDadosSistema(Estoque  * pnt_deposito)
{
	FILE * pont_arq;
	pont_arq = fopen("estoque.txt","w");
	if(pont_arq != NULL)
	{
		fprintf(pont_arq,"%s","");
		fclose(pont_arq);
	}	
	else
	{
		printf("ERRO ao acessar o arquivo! Contate o administrador do sistema\n");
	}
}