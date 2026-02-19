//Funções para o sistema de estoque
void MenuEstoque();
void FiltraProduto();
void OrdemProduto();
void OrdemCategoria();
void MenuListaEstoque();
void MenuBuscaEstoque();
void MenuAtualizaEstoque();
void MenuBalancoEstoque();
int LeArquivoEstoque(Estoque * pnt_deposito);
void ImprimeProduto(Estoque * pnt_deposito, int tam);
void LimpaBufferEstoque(); // Função para limpar o buffer de entrada (stdin)
int ObtemInteiroValidoEstoque(); // Função para obter numero inteiro valido
void CadastraProduto(Estoque * pnt_deposito);
void CadastraCategoria(Estoque * pnt_deposito);
void ListaProduto(Estoque * pnt_deposito);
void BuscaProduto(Estoque * pnt_deposito);
void BuscaProdutoDescricao(Estoque *pnt_deposito);
void AtualizaProduto(Estoque  * pnt_deposito);
void RemoveProduto(Estoque * pnt_deposito);
//void CalculaBalancoProduto(Estoque  * pnt_deposito);
void ReordenaCodigoProduto(Estoque  * pnt_deposito);
int ComparaPalavrasProduto(char *palavra1, char *palavra2);
void BubbleSortNumeroCategoria(Estoque * pnt_deposito, int opcao, int tamanho);
void BubbleSortCodigoProduto(Estoque * pnt_deposito, int opcao, int tamanho);
void BubbleSortQuantidadeProduto(Estoque * pnt_deposito, int opcao, int tamanho);
void BubbleSortPrecoProduto(Estoque * pnt_deposito, int opcao, int tamanho);
void BubbleSortDescricaoProduto(Estoque * pnt_deposito, int opcao, int tamanho);
void FiltraOrdenaProduto(Estoque  * pnt_deposito);
void ApagaDadosSistemaProduto(Estoque  * pnt_deposito);
void LimpaStringEstoque(char *str);
void ConverteMaiusculaEstoque(char *str);
float ObtemFloatValidoEstoque();

void MenuEstoque()
{
	system("chcp 65001 > nul");
	system("color 07");
	printf("\n");
	
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("║               *** B E M - V I N D O ***           ║\n");
	printf("║          GERENCIADOR DE ESTOQUE DE PRODUTOS       ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                        *CONSULTAR ║\n");
	printf("║                                                   ║\n");
	printf("║   Opções que nao alteram o banco de dados         ║\n");
	printf("║                                                   ║\n");
	printf("║      Listar ESTOQUE ----------------------- 1     ║\n");
	printf("║      Filtrar e ordenar ESTOQUE ------------ 2     ║\n");
	printf("║      Buscar no ESTOQUE -------------------- 3     ║\n");
	printf("║      Calcular BALANCO do ESTOQUE ---------- 4     ║\n");
	printf("║                                                   ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                       **ATUALIZAR ║\n");
	printf("║                                                   ║\n");
	printf("║   Opcoes que alteram o banco de dados             ║\n");
	printf("║                                                   ║\n");
	printf("║      Cadastrar PRODUTOS ------------------- 5     ║\n");
	printf("║      Cadastrar CATEGORIA ------------------ 6     ║\n");
	printf("║      Atualizar ESTOQUE -------------------- 7     ║\n");
	printf("║                                                   ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                        ***DELETAR ║\n");
	printf("║                                                   ║\n");
	printf("║   Alteracoes irreversiveis no banco de dados      ║\n");
	printf("║                                                   ║\n");
	printf("║      Reordenar CODIGOS de PRODUTOS -------- 8     ║\n");
	printf("║      Remover PRODUTO ---------------------- 9     ║\n");
	printf("║      Remover CATEGORIA -------------------- 10    ║\n");
	printf("║      Apagar TODOS os itens do ESTOQUE ----- 11    ║\n");
	printf("║                                                   ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                                   ║\n");
	printf("║   Encerrar sistema  -------------------- 0        ║\n");
	printf("║                                                   ║\n");
	printf("╚═══════════════════════════════════════════════════╝\n\n");
}

void FiltraProduto()
{
	printf("\n");
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("║               FILTRAR E ORDENA LISTA              ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                                   ║\n");
	printf("║         Filtrar por DESCRICAO ---------- 1        ║\n");
	printf("║         Filtrar por CODIGO ------------- 2        ║\n");
	printf("║         Filtrar por QUANTIDADE --------- 3        ║\n");
	printf("║         Filtrar por PRECO -------------- 4        ║\n");
	printf("║                                                   ║\n");
	printf("║         Voltar ao MENU INICIAL --------- 0        ║\n");
	printf("║                                                   ║\n");
	printf("╚═══════════════════════════════════════════════════╝\n\n");
	
}

void OrdemProduto()
{
	printf("\n");
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("║                FILTRA E ORDENA LISTA              ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                                   ║\n");
	printf("║            Ordem CRESCENTE ----------- 1          ║\n");
	printf("║            Ordem DECRESCENTE --------- 2          ║\n");
	printf("║                                                   ║\n");
	printf("╚═══════════════════════════════════════════════════╝\n\n");
	
}

void OrdemCategoria()
{
	printf("\n");
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("║             ORDENA LISTA POR CATEGORIA            ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                                   ║\n");
	printf("║            Ordem CRESCENTE ----------- 1          ║\n");
	printf("║            Ordem DECRESCENTE --------- 2          ║\n");
	printf("║                                                   ║\n");
	printf("╚═══════════════════════════════════════════════════╝\n\n");
	
}

void MenuListaEstoque()
{
	printf("\n");
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("║                    LISTA ESTOQUE                  ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                                   ║\n");
	printf("║     Listar ESTOQUE de PRODUTOS ------------ 1     ║\n");
	printf("║                                                   ║\n");
	printf("║     Listar Estoque por CATEGORIA ---------- 2     ║\n");
	printf("║     Listar CATEGORIAS --------------------- 3     ║\n");
	printf("║                                                   ║\n");
	printf("║     Voltar ao MENU INICIAL ---------------- 0     ║\n");
	printf("║                                                   ║\n");
	printf("╚═══════════════════════════════════════════════════╝\n\n");
}

void MenuBuscaEstoque()
{
	printf("\n");
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("║                  BUSCAR NO ESTOQUE                ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                                   ║\n");
	printf("║      Buscar PRODUTO por CODIGO ----------- 1      ║\n");
	printf("║      Buscar PRODUTO por DESCRICAO -------- 2      ║\n");
	printf("║                                                   ║\n");
	printf("║      Buscar CATEGORIA por NUMERO --------- 3      ║\n");
	printf("║      Buscar CATEGORIA por NOME ----------- 4      ║\n");
	printf("║                                                   ║\n");
	printf("║      Voltar ao MENU INICIAL -------------- 0      ║\n");
	printf("║                                                   ║\n");
	printf("╚═══════════════════════════════════════════════════╝\n\n");
}

void MenuAtualizaEstoque()
{
	printf("\n");
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("║                  ATUALIZAR ESTOQUE                ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                                   ║\n");
	printf("║          Atualizar DESCRICAO --------- 1          ║\n");
	printf("║          Atualizar QUANTIDADE -------- 2          ║\n");
	printf("║          Atualizar UNIDADE ----------- 3          ║\n");
	printf("║          Atualizar CUSTO ------------- 4          ║\n");
	printf("║          Atualizar PRECO ------------- 5          ║\n");
	printf("║                                                   ║\n");
	printf("║          Voltar ao MENU INICIAL ------ 0          ║\n");
	printf("║                                                   ║\n");
	printf("╚═══════════════════════════════════════════════════╝\n\n");
}

void MenuBalancoEstoque()
{
	printf("\n");
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("║            CALCULAR BALANCO DO ESTOQUE            ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                                   ║\n");
	printf("║    Calcular total do PRODUTO --------------- 1    ║\n");
	printf("║    Calcular BALANCO GERAL detalhado -------- 2    ║\n");
	printf("║    Calcular BALANCO GERAL resumido --------- 3    ║\n");
	printf("║                                                   ║\n");
	printf("║    Voltar ao MENU INICIAL ------------------ 0    ║\n");
	printf("║                                                   ║\n");
	printf("╚═══════════════════════════════════════════════════╝\n\n");
}

int LeArquivoEstoque(Estoque * pnt_deposito)
{
	FILE *pont_estoque;
	int e = 0;
	pont_estoque = fopen("estoque.txt", "r");
	while(fscanf(pont_estoque,
					 "%d\n%[^\n]\n%d\n%[^\n]\n%d\n%[^\n]\n%f\n%f\n",
					 &pnt_deposito[e].codigo,
					 pnt_deposito[e].descricao,
					 &pnt_deposito[e].numero,
					 pnt_deposito[e].categoria,
					 &pnt_deposito[e].quantidade,
					 pnt_deposito[e].unidade,
					 &pnt_deposito[e].custo,
					 &pnt_deposito[e].preco) != EOF)
		{
			e++;
		}
	
	fclose(pont_estoque);
	return e;
}

void ImprimeProduto(Estoque * pnt_deposito, int tam)
{
	int i = 0;
	int itens_exibidos = 0;
	if(tam > 0)
	{
		printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
		printf("║ COD │                   DESCRICAO                 │ NUM │        CATEGORIA        │ QTDE │ UN │ CUSTO UNITARIO │ PRECO UNITARIO ║\n");
		printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
		printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
	}
	
	for(i = 0; i < tam; i++)
	{
		if(i % 2 == 0)
		{
			printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%45s\x1b[0m│\x1b[36m%5d\x1b[0m│\x1b[36m%25s\x1b[0m│\x1b[36m%6d\x1b[0m│\x1b[36m%4s\x1b[0m│\x1b[36m%16.2f\x1b[0m│\x1b[36m%16.2f\x1b[0m║\n",
					 pnt_deposito[i].codigo,
					 pnt_deposito[i].descricao,
					 pnt_deposito[i].numero,
					 pnt_deposito[i].categoria,
					 pnt_deposito[i].quantidade,
					 pnt_deposito[i].unidade,
					 pnt_deposito[i].custo,
					 pnt_deposito[i].preco);
			printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
			itens_exibidos++;
		}
		else
		{
			printf("║%5d│%45s│%5d│%25s│%6d│%4s│%16.2f│%16.2f║\n",
					 pnt_deposito[i].codigo,
					 pnt_deposito[i].descricao,
					 pnt_deposito[i].numero,
					 pnt_deposito[i].categoria,
					 pnt_deposito[i].quantidade,
					 pnt_deposito[i].unidade,
					 pnt_deposito[i].custo,
					 pnt_deposito[i].preco);
			printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
			itens_exibidos++;
		}
		
		if(itens_exibidos % 10 == 0 && itens_exibidos != 0)
		{
			printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
			printf("\nAperte qualquer tecla para continuar a lista de clientes... \n\n");
			system("pause > nul");
			printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
			printf("║ COD │                   DESCRICAO                 │ NUM │        CATEGORIA        │ QTDE │ UN │ CUSTO UNITARIO │ PRECO UNITARIO ║\n");
			printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
			printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
			itens_exibidos = 0;
		}
		
	}
	
	if(tam > 0)
	{
		printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
	}
	printf("LISTAGEM CONCLUIDA\n");
}

void LimpaBufferEstoque()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // apenas descarta os caracteres restantes
    }
}

int ObtemInteiroValidoEstoque(int n)
{
    //int n;
    int resultado;

    while (1) {
        resultado = scanf("%d", &n);

        if (resultado == 1) {
            LimpaBufferEstoque(); // limpa o '\n' e o que sobrou
            return n;
        } else {
            printf("\nEntrada inválida!\a\n\n");
			printf("Tente novamente: ");
            LimpaBufferEstoque(); // descarta entrada inválida
        }
    }
}

void CadastraCategoria(Estoque * pnt_deposito)
{
	FILE *pont_categoria;
	int c = 0;
	int k = 1;
	int cadastro = 0;
	int op = -1;
	int numero_categoria = 0;
	char nome_categoria[25];
	int categoria_encontrada = 0;
	
	int i_linha;
	int i_coluna;
	
	pont_categoria = fopen("categoria.txt","r");
	
	while(fscanf(pont_categoria,"%d\n%[^\n]\n",
								&pnt_deposito[c].numero,
								pnt_deposito[c].categoria) != EOF)
	{
		c++;
	}
	
	fclose(pont_categoria);
	
	//Obtendo codigo para auto incremento
	numero_categoria = pnt_deposito[c-1].numero + 1;
	
	pont_categoria = fopen("categoria.txt","a");
				
	if(pont_categoria == NULL)
	{
		printf("ERRO! O arquivo nao foi aberto!\n\n");
	}
	else
	{
		printf("O arquivo foi aberto com sucesso\n\n");
		
		printf("\nCADASTRO DE CATEGORIAS\n");
		printf("----------------------\n\n");	
		printf("Informe quantas categorias deseja cadastrar: ");
		cadastro = ObtemInteiroValidoEstoque(cadastro);
		printf("\n");
		
		//Preparando numero de iterações visando implementar duas colunas na lista de categoria
		if(c % 2 == 0)
		{
			i_coluna = c;
			i_linha = i_coluna/2;
		}
		else
		{
			i_coluna = c;
			i_coluna++;
			i_linha = i_coluna/2;
		}
		
		printf("\n╔══════════════════════════════════════════════════════════════╗\n");
		printf("║                    **LISTA DE CATEGORIAS**                   ║\n");
		printf("╠═══════════════════════════════╦══════════════════════════════╣\n");
		printf("║        CATEGORIA        │ NUM ║        CATEGORIA       │ NUM ║\n");
		printf("╟───────────────────────────────╢──────────────────────────────╢\n");
		printf("╟───────────────────────────────╢──────────────────────────────╢\n");
		
		for(int i = 0; i < i_linha; i++)
		{	
			if(i % 2 == 0)
			{
				printf("║\x1b[36m%25s\x1b[0m│\x1b[36m%5d\x1b[0m║\x1b[36m%24s\x1b[0m│\x1b[36m%5d\x1b[0m║\n",pnt_deposito[i].categoria,pnt_deposito[i].numero,pnt_deposito[i+i_linha].categoria,pnt_deposito[i+i_linha].numero);
				printf("╟───────────────────────────────╢──────────────────────────────╢\n");			
			}
			else if(i % 2 != 0 && i != (i_linha - 1))
			{
				printf("║%25s│%5d║%24s│%5d║\n",pnt_deposito[i].categoria,pnt_deposito[i].numero,pnt_deposito[i+i_linha].categoria,pnt_deposito[i+i_linha].numero);
				printf("╟───────────────────────────────╢──────────────────────────────╢\n");	
			}
			else if(c % 2 != 0 && i == (i_linha - 1))
			{
				printf("║%25s│%5d║%24s│     ║\n",pnt_deposito[i].categoria,pnt_deposito[i].numero,pnt_deposito[i+i_linha].categoria);
				printf("╟───────────────────────────────╢──────────────────────────────╢\n");	
			}
		}
		
		printf("╚═══════════════════════════════╩══════════════════════════════╝\n");
		
		
		for(int i = 0; i < cadastro; i++)
		{
			do{	
					
				printf("\nInforme o nome do CATEGORIA 0%d : ",k);
				scanf(" %[^\n]", nome_categoria);
				// Limpar a string, remover espaços extras antes e depois
				LimpaStringEstoque(nome_categoria);
				// Converter a unidade para maiúsculas
				ConverteMaiusculaEstoque(nome_categoria);				
				
				categoria_encontrada = 0;
				
				for(int i = 0; i < c; i++)
				{	
					if(strcmp(pnt_deposito[i].categoria, nome_categoria) == 0)
					{
						categoria_encontrada = 1;
						break;
					}
				}
					
				if(categoria_encontrada == 1)
				{
					printf("\n█████████████████████████████████████████\n\a");
					printf("█                                       █\n");
					printf("█        CATEGORIA JA EXISTENTE!        █\n");
					printf("█                                       █\n");
					printf("█████████████████████████████████████████\n\n");
					
					printf("Cadastrar outra categoria - 1 | Cancelar cadastro e voltar ao MENU INICIAL - 0 ");
					op = ObtemInteiroValidoEstoque(op);
					switch(op)
					{
						case 1:
							categoria_encontrada = 2;
						break;
						case 0:
							printf("\n\nCADASTRO CANCELADO\n\n");
							printf("\nAperte qualquer tecla para voltar ao MENU INICIAL... ");
							printf("pause > nul");
						break;
						default:
							do{
								printf("\n\nDigite uma opcao valida!\n\n");
								printf("Cadastrar outra categoria - 1 | Cancelar cadastro e voltar ao MENU INICIAL - 0 ");
								op = ObtemInteiroValidoEstoque(op);
							}while(op < 0 || op > 1);
					}
				}
					
				if(!strcmp(pnt_deposito[i].categoria, nome_categoria) == 0)
				{
					fprintf(pont_categoria,"%d\n%s\n",
									numero_categoria,
									nome_categoria);
					k++;
					numero_categoria++;
				}
			}while(categoria_encontrada != 0);
			if(categoria_encontrada != 0)
			{
				system("cls");
				break;
			}
		}
			
		printf("\n\nCADASTRO CONCLUIDO\n\n");
		printf("\nAperte qualquer tecla para voltar ao MENU INICIAL...");
		system("pause > nul");
		fclose(pont_categoria);	
	}
	system("cls");
}	

void CadastraProduto(Estoque * pnt_deposito)
{
	FILE *pont_arq;
	FILE *pont_categoria;
	int k = 1;
	int y = 0;
	int c = 0;
	int codigo = 0;
	int cadastro = 0;
	char categoria_produto[20];
	char unidade[20];
	char unidade_UN[3] = "UN";
	char unidade_KG[3] = "KG";
	int numero_categoria = 0;
	int categoria_encontrada = 0;
	
	int i_linha;
	int i_coluna;
	
	system("cls");
	
	y = LeArquivoEstoque(pnt_deposito);
	
	/*pont_arq = fopen("estoque.txt","r");
	
	if(pont_arq == NULL)
	{
		printf("ERRO! O arquivo nao foi aberto!\n\n");
	}
	else
	{
		while(fscanf(pont_arq,"%d\n%[^\n]\n%d\n%[^\n]\n%d\n%[^\n]\n%f\n",
								&pnt_deposito[y].codigo,
								pnt_deposito[y].descricao,
								&pnt_deposito[y].numero,
								pnt_deposito[y].categoria,
								&pnt_deposito[y].quantidade,
								pnt_deposito[y].unidade,
								&pnt_deposito[y].preco) != EOF)
		{
			y++;
		}
	}
	fclose(pont_arq);
	*/
	
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
		printf("--------------------\n\n");	
		printf("Informe quantos produtos deseja cadastrar: ");
		cadastro = ObtemInteiroValidoEstoque(cadastro);
		printf("\n");
		
		pont_categoria = fopen("categoria.txt","r");
		while(fscanf(pont_categoria,"%d\n%[^\n]\n",
							&pnt_deposito[c].numero,
							pnt_deposito[c].categoria) != EOF)
		{
			
			c++;
		}
		fclose(pont_categoria);
		
		//Preparando numero de iterações visando implementar duas colunas na lista de categoria
		if(c % 2 == 0)
		{
			i_coluna = c;
			i_linha = i_coluna/2;
		}
		else
		{
			i_coluna = c;
			i_coluna++;
			i_linha = i_coluna/2;
		}
		
		printf("\n╔══════════════════════════════════════════════════════════════╗\n");
		printf("║                    **LISTA DE CATEGORIAS**                   ║\n");
		printf("╠═══════════════════════════════╦══════════════════════════════╣\n");
		printf("║        CATEGORIA        │ NUM ║        CATEGORIA       │ NUM ║\n");
		printf("╟───────────────────────────────╢──────────────────────────────╢\n");
		printf("╟───────────────────────────────╢──────────────────────────────╢\n");
		
		for(int i = 0; i < i_linha; i++)
		{	
			if(i % 2 == 0 && i != (i_linha - 1))
			{
				printf("║\x1b[36m%25s\x1b[0m│\x1b[36m%5d\x1b[0m║\x1b[36m%24s\x1b[0m│\x1b[36m%5d\x1b[0m║\n",
				pnt_deposito[i].categoria,
				pnt_deposito[i].numero,
				pnt_deposito[i+i_linha].categoria,
				pnt_deposito[i+i_linha].numero);
				printf("╟───────────────────────────────╢──────────────────────────────╢\n");			
			}
			else if(i % 2 != 0 && i != (i_linha - 1))
			{
				printf("║%25s│%5d║%24s│%5d║\n",pnt_deposito[i].categoria,pnt_deposito[i].numero,pnt_deposito[i+i_linha].categoria,pnt_deposito[i+i_linha].numero);
				printf("╟───────────────────────────────╢──────────────────────────────╢\n");	
			}
				
			if(c % 2 != 0 && i == (i_linha - 1))
			{
				printf("║\x1b[36m%25s\x1b[0m│\x1b[36m%5d\x1b[0m║                        │     ║\n",pnt_deposito[i].categoria,pnt_deposito[i].numero);
				printf("╟───────────────────────────────╢──────────────────────────────╢\n");	
			}
			if(c % 2 == 0 && i == (i_linha - 1))
			{
				printf("║\x1b[36m%25s\x1b[0m│\x1b[36m%5d\x1b[0m║\x1b[36m%24s\x1b[0m│\x1b[36m%5d\x1b[0m║\n",
				pnt_deposito[i].categoria,
				pnt_deposito[i].numero,
				pnt_deposito[i+i_linha].categoria,
				pnt_deposito[i+i_linha].numero);
				printf("╟───────────────────────────────╢──────────────────────────────╢\n");			
			}
		}
		
		printf("╚═══════════════════════════════╩══════════════════════════════╝\n");
		
		for(int i = 0; i < cadastro; i++)
		{
			
			printf("\nInforme o NUMERO da CATEGORIA: ");
			numero_categoria = ObtemInteiroValidoEstoque(numero_categoria);
			
			for(int i = 0; i < c; i++)
			{	
				if(pnt_deposito[i].numero == numero_categoria)
				{
					strcpy(categoria_produto, pnt_deposito[i].categoria);
					categoria_encontrada = 1;
				}
			}
			if(categoria_encontrada == 0)
			{
				printf("\n█████████████████████████████████████████████████████████\n\a");
				printf("█                                                       █\n");
				printf("█                 CATEGORIA NAO ENCONTRADA!             █\n");
				printf("█   O PRODUTO SERA CLASSIFICADO NA CATEGORIA \x1b[32mDIVERSOS\x1b[0m   █\n");
				printf("█                                                       █\n");
				printf("█████████████████████████████████████████████████████████\n\n");	
				strcpy(categoria_produto, "DIVERSOS");
				numero_categoria = 22;
			}		
			
			printf("\n");
			printf("O produto 0%d será cadastrado na categoria : \x1b[32m%s\x1b[0m\n",k,categoria_produto);
			printf("\nInforme a DESCRICAO do produto 0%d : ",k);
			scanf(" %[^\n]",pnt_deposito[i].descricao);
			
			// Limpar a string, remover espaços extras antes e depois
			LimpaStringEstoque(pnt_deposito[i].descricao);
			// Converter a unidade para maiúsculas
			ConverteMaiusculaEstoque(pnt_deposito[i].descricao);
			printf("\nInforme a QUANTIDADE do produto 0%d : ",k);
			pnt_deposito[i].quantidade = ObtemInteiroValidoEstoque(pnt_deposito[i].quantidade);
			printf("\nInforme a UNIDADE do produto 0%d : ",k);
			scanf(" %[^\n]",unidade);
			
			// Limpar a string, remover espaços extras antes e depois
            LimpaStringEstoque(unidade);
            // Converter a unidade para maiúsculas para garantir que a comparação não seja sensível a maiúsculas/minúsculas
            ConverteMaiusculaEstoque(unidade);
            // Verificar se a unidade informada é válida
            if (strcmp(unidade, unidade_UN) == 0 || strcmp(unidade, unidade_KG) == 0) {
                // Se for válida, copiar para a estrutura
                strcpy(pnt_deposito[i].unidade, unidade);
            } else {
                // Se for inválida, solicitar ao usuário até fornecer uma unidade válida
                do {
                    printf("\nDigite uma unidade valida (UN ou KG): ");
                    scanf(" %[^\n]", unidade);
   
                    // Limpar a string e garantir que a comparação será feita de forma consistente
                    LimpaStringEstoque(unidade);
                    ConverteMaiusculaEstoque(unidade);
                    
                } while (strcmp(unidade, unidade_UN) != 0 && strcmp(unidade, unidade_KG) != 0);

                // Após o loop, a unidade será válida, então copiar para a estrutura
                strcpy(pnt_deposito[i].unidade, unidade);
            }

			printf("\nInforme o CUSTO (para a empresa) do produto 0%d : ",k);
			//scanf("%f",&pnt_deposito[i].custo);
			pnt_deposito[i].custo = ObtemFloatValidoEstoque();
			
			printf("\nInforme o PRECO (para o cliente) do produto 0%d : ",k);
			//scanf("%f",&pnt_deposito[i].preco);
			pnt_deposito[i].preco = ObtemFloatValidoEstoque();
			
			printf("\n");	
			fprintf(pont_arq,"%d\n%s\n%d\n%s\n%d\n%s\n%.2f\n%.2f\n",
								codigo,
								pnt_deposito[i].descricao,
								numero_categoria,
								categoria_produto,
								pnt_deposito[i].quantidade,
								pnt_deposito[i].unidade,
								pnt_deposito[i].custo,
								pnt_deposito[i].preco);
			k++;
			codigo++;
		}
		
		printf("\n\nCADASTRO CONCLUIDO\n\n");
		printf("\n Aperte qualquer tecla para voltar ao MENU INICIAL...");
		system("pause > nul");
		fclose(pont_arq);
		fclose(pont_categoria);
	}
	system("cls");
	
}
	
void ListaProduto(Estoque * pnt_deposito)
{
	FILE *pont_estoque;
	FILE *pont_categoria;
	int y = 0;
	int c = 0;
	int escolha = 0;
	int menu_lista = -1;
	int i_coluna = 0;
	int i_linha = 0;
	
	system("cls");

	do{
		MenuListaEstoque();
		menu_lista = ObtemInteiroValidoEstoque(menu_lista);
		switch(menu_lista)
		{
			case 1:
				y = 0;
				system("cls");
				
				y = LeArquivoEstoque(pnt_deposito);
				
				if(y > 0)
				{	
					printf("\n");
					printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
					printf("║                                                      **LISTA DE PRODUTOS**                                                      ║\n");
					ImprimeProduto(pnt_deposito, y);
				}
				else
				{
					printf("\n\nNAO HA REGISTROS NO ARQUIVO\n\n");
				}
				
				
				printf("\nAperte qualquer tecla para voltar ao MENU... \n\n");
				system("pause > nul");
				system("cls");
			break;
			case 2:
				y = 0;
				
				y = LeArquivoEstoque(pnt_deposito);
				
				system("cls");
				if(y > 0)
				{
					system("cls");
					OrdemCategoria();
					escolha = ObtemInteiroValidoEstoque(escolha);
					switch(escolha)
					{
						//Crescente 
						case 1:
							system("cls");
							BubbleSortNumeroCategoria(pnt_deposito, escolha, y);
							system("cls");
							printf("\n╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                            **FILTRAGEM POR NUMERO DE CATEGORIA - CRESCENTE**                                    ║\n");
							ImprimeProduto(pnt_deposito, y);

						break;
						//Decrescente 
						case 2:
							BubbleSortNumeroCategoria(pnt_deposito, escolha, y);
							system("cls");
							printf("\n╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                           **FILTRAGEM POR NUMERO DE CATEGORIA - DECRESCENTE**                                   ║\n");
							ImprimeProduto(pnt_deposito, y);

						break;
						default:
							do{
								printf("\n\nDigite uma opcao valida!\n\n");
								escolha = ObtemInteiroValidoEstoque(escolha);
							}while(escolha < 1 || escolha > 2);		
					}
				}
				else
				{
					printf("\n\nNAO HA REGISTROS NO ARQUIVO\n\n");
				}
				printf("\nAperte qualquer tecla para voltar ao MENU... \n\n");
				system("pause > nul");
				system("cls");
			break;
			case 3:
				c = 0;
				system("cls");
				pont_categoria = fopen("categoria.txt","r");
				while(fscanf(pont_categoria,"%d\n%[^\n]\n",
									&pnt_deposito[c].numero,
									pnt_deposito[c].categoria) != EOF)
				{
					
					c++;
				}
				fclose(pont_categoria);
				if(c > 0)
				{
					//Preparando numero de iterações visando implementar duas colunas na lista de categoria
					if(c % 2 == 0)
					{
						i_coluna = c;
						i_linha = i_coluna/2;
					}
					else
					{
						i_coluna = c;
						i_coluna++;
						i_linha = i_coluna/2;
					}
					
					printf("\n╔══════════════════════════════════════════════════════════════╗\n");
					printf("║                    **LISTA DE CATEGORIAS**                   ║\n");
					printf("╠═══════════════════════════════╦══════════════════════════════╣\n");
					printf("║        CATEGORIA        │ NUM ║        CATEGORIA       │ NUM ║\n");
					printf("╟───────────────────────────────╢──────────────────────────────╢\n");
					printf("╟───────────────────────────────╢──────────────────────────────╢\n");
					
					for(int i = 0; i < i_linha; i++)
					{	
						if(i % 2 == 0 && i != (i_linha - 1))
						{
							printf("║\x1b[36m%25s\x1b[0m│\x1b[36m%5d\x1b[0m║\x1b[36m%24s\x1b[0m│\x1b[36m%5d\x1b[0m║\n",
							pnt_deposito[i].categoria,
							pnt_deposito[i].numero,
							pnt_deposito[i+i_linha].categoria,
							pnt_deposito[i+i_linha].numero);
							printf("╟───────────────────────────────╢──────────────────────────────╢\n");			
						}
						else if(i % 2 != 0 && i != (i_linha - 1))
						{
							printf("║%25s│%5d║%24s│%5d║\n",pnt_deposito[i].categoria,pnt_deposito[i].numero,pnt_deposito[i+i_linha].categoria,pnt_deposito[i+i_linha].numero);
							printf("╟───────────────────────────────╢──────────────────────────────╢\n");	
						}
						
						if(c % 2 != 0 && i == (i_linha - 1))
						{
							printf("║\x1b[36m%25s\x1b[0m│\x1b[36m%5d\x1b[0m║                        │     ║\n",pnt_deposito[i].categoria,pnt_deposito[i].numero);
							printf("╟───────────────────────────────╢──────────────────────────────╢\n");	
						}
						if(c % 2 == 0 && i == (i_linha - 1))
						{
							printf("║\x1b[36m%25s\x1b[0m│\x1b[36m%5d\x1b[0m║\x1b[36m%24s\x1b[0m│\x1b[36m%5d\x1b[0m║\n",
							pnt_deposito[i].categoria,
							pnt_deposito[i].numero,
							pnt_deposito[i+i_linha].categoria,
							pnt_deposito[i+i_linha].numero);
							printf("╟───────────────────────────────╢──────────────────────────────╢\n");			
						}
					}
					
					printf("╚═══════════════════════════════╩══════════════════════════════╝\n");
					printf("\nLISTAGEM CONCLUIDA\n");
				}
				else
				{
					printf("\n\nNAO HA REGISTROS NO ARQUIVO\n\n");
				}
				printf("\nAperte qualquer tecla para voltar ao MENU...\n\n ");
				system("pause > nul");
				system("cls");
				
			break;
			case 0:
				system("cls");
			break;
			default:
				do{
					printf("\n\nDigite uma opcao valida!\n\n");
					menu_lista = ObtemInteiroValidoEstoque(menu_lista);
				}while(menu_lista < 0 || menu_lista > 3);
		}		
	}while(menu_lista != 0);	
}

void BuscaProduto(Estoque * pnt_deposito)
{
	FILE *pont_arq;
	FILE *pont_categoria;
	int menu_busca = 0;
	int y = 0;
	int c = 0;
	int t = 0;
	int codigo = 0;
	int numero_categoria = 0;
	int op = 0;
	char descricao[50];
	char nome_categoria[25];
	int categorias_exibidas = 0;
	int produtos_exibidos = 0;
	system("cls");
	
	
	do
	{
		MenuBuscaEstoque();
		menu_busca = ObtemInteiroValidoEstoque(menu_busca);
		
		switch(menu_busca)
		{
			case 1:
				system("cls");
				
				y = LeArquivoEstoque(pnt_deposito);
				
				/*
				pont_arq = fopen("estoque.txt","r");
				if (pont_arq == NULL)
				{
					printf("Erro ao abrir o arquivo estoque.txt\n");
					break;
				}
				while(fscanf(pont_arq,"%d\n%[^\n]\n%d\n%[^\n]\n%d\n%[^\n]\n%f\n",
										&pnt_deposito[y].codigo,
										pnt_deposito[y].descricao,
										&pnt_deposito[y].numero,
										pnt_deposito[y].categoria,
										&pnt_deposito[y].quantidade,
										pnt_deposito[y].unidade,
										&pnt_deposito[y].preco) != EOF)
				{
					y++;
				}	
				fclose(pont_arq);
				*/
				
				do{
					system("cls");
					printf("\nBUSCA DE PRODUTO POR CODIGO\n");
					printf("---------------------------\n\n");
					printf("Informe o CODIGO do produto: ");
					codigo = ObtemInteiroValidoEstoque(codigo);
					printf("\n");
					
					t = 0;
					
					for(int i = 0; i < y; i++)
					{	
						if(pnt_deposito[i].codigo == codigo)
						{
							printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                                       **BUSCA POR CODIGO**                                                      ║\n");
							printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
							printf("║ COD │                   DESCRICAO                 │ NUM │        CATEGORIA        │ QTDE │ UN │ CUSTO UNITARIO │ PRECO UNITARIO ║\n");
							printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("║%5d│\033[32m%45s\033[0m│%5d│%25s│%6d│%4s│%16.2f│%16.2f║\n",
									 pnt_deposito[i].codigo,
									 pnt_deposito[i].descricao,
									 pnt_deposito[i].numero,
									 pnt_deposito[i].categoria,
									 pnt_deposito[i].quantidade,
									 pnt_deposito[i].unidade,
									 pnt_deposito[i].custo,
									 pnt_deposito[i].preco);
							printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
							printf("BUSCA CONCLUIDA\n\n");
							t = 1;
						}	
					}
					if(t == 0)
					{
						printf("\n");
						printf("███████████████████████████████████████\n\a");
						printf("█                                     █\n");
						printf("█        PRODUTO NAO ENCONTRADO!      █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n\n\n");
					
					}				
					printf("Continuar busca - 1 | Voltar ao MENU - 2\n");
					//scanf("%d",&op);
					op = ObtemInteiroValidoEstoque(op);
					
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
								//scanf("%d",&op);
								op = ObtemInteiroValidoEstoque(op);
								
							}while(op < 1 || op > 2);
					}
				}while(op != 2);
				y = 0;
				op = 0;
				system("cls");
			break;
			
			case 2:
				system("cls");
				
				y = LeArquivoEstoque(pnt_deposito);
				
				/*
				pont_arq = fopen("estoque.txt","r");
				if (pont_arq == NULL)
				{
					printf("Erro ao abrir o arquivo estoque.txt\n");
					break;
				}
				while(fscanf(pont_arq,"%d\n%[^\n]\n%d\n%[^\n]\n%d\n%[^\n]\n%f\n",
										&pnt_deposito[y].codigo,
										pnt_deposito[y].descricao,
										&pnt_deposito[y].numero,
										pnt_deposito[y].categoria,
										&pnt_deposito[y].quantidade,
										pnt_deposito[y].unidade,
										&pnt_deposito[y].preco) != EOF)
				{
					y++;
				}
				fclose(pont_arq);
				*/
				
				do
				{
					system("cls");
					printf("\nBUSCA DE PRODUTO POR DESCRICAO\n");
					printf("------------------------------\n\n");
					printf("Informe a DESCRICAO do produto: ");
					scanf(" %[^\n]", descricao);
					
					// Limpar a string, remover espaços extras antes e depois
					LimpaStringEstoque(descricao);
					// Converter a unidade para maiúsculas
					ConverteMaiusculaEstoque(descricao);	
					
					printf("\n");
					
					produtos_exibidos = 0;
					t = 0; // Reinicie a flag 't' para cada nova busca
					
					for (int i = 0; i < y; i++)
					{
						// strstr() verifica se 'descricao' esta contida no nome do produto
						if (strstr(pnt_deposito[i].descricao, descricao) != NULL)
						{
							t = 1;
							break;
						}
					}
					
					if(t == 1)
					{
						printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
						printf("║                                                     **BUSCA POR DESCRICAO**                                                     ║\n");
						printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
						printf("║ COD │                   DESCRICAO                 │ NUM │        CATEGORIA        │ QTDE │ UN │ CUSTO UNITARIO │ PRECO UNITARIO ║\n");
						printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
						printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
					}
					
					for (int i = 0; i < y; i++)
					{
						// strstr() verifica se 'descricao' esta contida no nome do produto
						if (strstr(pnt_deposito[i].descricao, descricao) != NULL)
						{
							
							printf("║%5d│\033[32m%45s\033[0m│%5d│%25s│%6d│%4s│%16.2f│%16.2f║\n",
									 pnt_deposito[i].codigo,
									 pnt_deposito[i].descricao,
									 pnt_deposito[i].numero,
									 pnt_deposito[i].categoria,
									 pnt_deposito[i].quantidade,
									 pnt_deposito[i].unidade,
									 pnt_deposito[i].custo,
									 pnt_deposito[i].preco);
							printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");

							produtos_exibidos++;
						}
					
						if(produtos_exibidos < y && produtos_exibidos % 10 == 0 && produtos_exibidos != 0)
							{
								printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
								printf("\nAperte qualquer tecla para continuar a lista de produtos... \n\n");
								system("pause > nul");
								printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
								printf("║ COD │                   DESCRICAO                 │ NUM │        CATEGORIA        │ QTDE │ UN │ CUSTO UNITARIO │ PRECO UNITARIO ║\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								produtos_exibidos = 0;
							}
					}
					if(t == 1)
					{
						printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
						printf("\n\nBUSCA CONCLUIDA\n\n");
					}
					if (!t)
					{
						printf("\n");
						printf("███████████████████████████████████████\n\a");
						printf("█                                     █\n");
						printf("█        PRODUTO NAO ENCONTRADO!      █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n\n\n");
						
						
					}
					printf("Continuar busca - 1 | Voltar ao MENU - 2\n");
					op = ObtemInteiroValidoEstoque(op);
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
								op = ObtemInteiroValidoEstoque(op);
							}while(op < 1 || op > 2);
					}
				}while(op != 2);				
				y = 0;
				op = 0;
				system("cls");
			break;
			case 3:
				system("cls");
				pont_categoria = fopen("categoria.txt","r");
				if (pont_categoria == NULL)
				{
					printf("Erro ao abrir o arquivo categoria.txt\n");
					break;
				}
				while(fscanf(pont_categoria,"%d\n%[^\n]\n",
										&pnt_deposito[c].numero,
										pnt_deposito[c].categoria) != EOF)
				{
					c++;
				}	
				fclose(pont_categoria);
				
				do{
					system("cls");
					printf("\nBUSCA DE CATEGORIA POR NUMERO\n");
					printf("-----------------------------\n\n");
					printf("Informe o NUMERO do categoria: ");
					numero_categoria = ObtemInteiroValidoEstoque(numero_categoria);
					printf("\n");
					
					t = 0;
					
					for(int i = 0; i < c; i++)
					{	
						if(pnt_deposito[i].numero == numero_categoria)
						{
							printf("╔═══════════════════════════════╗\n");
							printf("║      **BUSCA POR NUMERO**     ║\n");
							printf("╠═══════════════════════════════╣\n");
							printf("║ NUM │        CATEGORIA        ║\n");
							printf("╟───────────────────────────────╢\n");
							printf("╟───────────────────────────────╢\n");
							printf("║%5d│\033[32m%25s\033[0m║\n",
									 pnt_deposito[i].numero,
									 pnt_deposito[i].categoria);
							printf("╟───────────────────────────────╢\n");
							printf("╚═══════════════════════════════╝\n\n");
							printf("BUSCA CONCLUIDA\n\n");
							t = 1;
						}	
					}
					if(t == 0)
					{
						printf("\n");
						printf("███████████████████████████████████████\n\a");
						printf("█                                     █\n");
						printf("█      CATEGORIA NAO ENCONTRADA!      █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n\n\n");
					
					}				
					printf("Continuar busca - 1 | Voltar ao MENU - 2\n");
					//scanf("%d",&op);
					op = ObtemInteiroValidoEstoque(op);
					
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
								//scanf("%d",&op);
								op = ObtemInteiroValidoEstoque(op);
								
							}while(op < 1 || op > 2);
					}
				}while(op != 2);
				c = 0;
				op = 0;
				system("cls");
			break;
			case 4:
				system("cls");
				pont_categoria = fopen("categoria.txt","r");
				if (pont_categoria == NULL)
				{
					printf("Erro ao abrir o arquivo categoria.txt\n");
					break;
				}
				while(fscanf(pont_categoria,"%d\n%[^\n]\n",
											 &pnt_deposito[c].numero,
											 pnt_deposito[c].categoria) != EOF)
				{
					c++;
				}
				fclose(pont_categoria);
		
				do
				{
					system("cls");
					printf("\nBUSCA DE CATEGORIA POR NOME\n");
					printf("---------------------------\n\n");
					printf("Informe o NOME da categoria: ");
					scanf(" %[^\n]", nome_categoria);
					
					// Limpar a string, remover espaços extras antes e depois
					LimpaStringEstoque(nome_categoria);
					// Converter a unidade para maiúsculas
					ConverteMaiusculaEstoque(nome_categoria);	
					
					printf("\n");
					
					categorias_exibidas = 0;
					t = 0; // Reinicie a flag 't' para cada nova busca
					
					for (int i = 0; i < c; i++)
					{
						// strstr() verifica se 'nome_categoria' esta contido no nome da categoria
						if (strstr(pnt_deposito[i].categoria, nome_categoria) != NULL)
						{
							t = 1;
							break;
						}
					}
					
					if(t == 1)
					{
						printf("╔═══════════════════════════════╗\n");
						printf("║       **BUSCA POR NOME**      ║\n");
						printf("╠═══════════════════════════════╣\n");
						printf("║ NUM │        CATEGORIA        ║\n");
						printf("╟───────────────────────────────╢\n");
						printf("╟───────────────────────────────╢\n");
					}
					
					for (int i = 0; i < c; i++)
					{
						// strstr() verifica se 'nome_categoria' esta contido no nome ca categoria
						if (strstr(pnt_deposito[i].categoria, nome_categoria) != NULL)
						{
							printf("║%5d│\033[32m%25s\033[0m║\n",
									 pnt_deposito[i].numero,
									 pnt_deposito[i].categoria);
							printf("╟───────────────────────────────╢\n");
							categorias_exibidas++;
						}
						if(categorias_exibidas % 10 == 0 && categorias_exibidas != 0)
							{
								printf("╚═══════════════════════════════╝\n\n");
								printf("\nAperte qualquer tecla para continuar a lista de categorias... \n\n");
								system("pause > nul");
								printf("╔═══════════════════════════════╗\n");
								printf("║ NUM │        CATEGORIA        ║\n");
								printf("╟───────────────────────────────╢\n");
								printf("╟───────────────────────────────╢\n");
								categorias_exibidas = 0;
							}

					}
					
					if(t == 1)
					{
						printf("╚═══════════════════════════════╝\n\n");
						printf("\nBUSCA CONCLUIDA\n\n");
					}
					
					if (!t)
					{
						printf("\n");
						printf("███████████████████████████████████████\n\a");
						printf("█                                     █\n");
						printf("█      CATEGORIA NAO ENCONTRADA!      █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n\n\n");
					}
					
					printf("Continuar busca - 1 | Voltar ao MENU - 2\n");
					op = ObtemInteiroValidoEstoque(op);
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
								op = ObtemInteiroValidoEstoque(op);
							}while(op < 1 || op > 2);
					}
				}while(op != 2);				
				c = 0;
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

void AtualizaProduto(Estoque * pnt_deposito)
{
	FILE *pont_arq;
	int menu_atualiza = 0;
	int quantidade = 0;
	int codigo = 0;
	char descricao[30];
	char unidade[20];
	char unidade_UN[3] = "UN";
	char unidade_KG[3] = "KG";
	float custo = 0.0;
	float preco = 0.0;
	int y = 0;
	int a = 2;
	int r = 0;
	char s;
	
	system("cls");
	
	y = 0;
	
	do{
		menu_atualiza = 0;
		MenuAtualizaEstoque();
		menu_atualiza = ObtemInteiroValidoEstoque(menu_atualiza);
		system("cls");	
		switch(menu_atualiza)
		{
			case 1:			
				
				y = LeArquivoEstoque(pnt_deposito);

					printf("\nATUALIZAR DESCRICAO\n");
					printf("-------------------\n\n");
					printf("Informe o CODIGO do produto: ");
					codigo = ObtemInteiroValidoEstoque(codigo);
					printf("\n\n");
					
					a = 0;
					
					do{
						for(int i = 0; i < y; i++)
						{	
							if(pnt_deposito[i].codigo == codigo)
							{
								printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
								printf("║                                                      **PRODUTO ENCONTRADO**                                                     ║\n");
								printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
								printf("║ COD │                   DESCRICAO                 │ NUM │        CATEGORIA        │ QTDE │ UN │ CUSTO UNITARIO │ PRECO UNITARIO ║\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║%5d│\033[32m%45s\033[0m│%5d│%25s│%6d│%4s│%16.2f│%16.2f║\n",
										 pnt_deposito[i].codigo,
										 pnt_deposito[i].descricao,
										 pnt_deposito[i].numero,
										 pnt_deposito[i].categoria,
										 pnt_deposito[i].quantidade,
										 pnt_deposito[i].unidade,
										 pnt_deposito[i].custo,
										 pnt_deposito[i].preco);
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
								
								printf("Informe a NOVA DESCRICAO: ");
								scanf(" %[^\n]",descricao);
								
								// Limpar a string, remover espaços extras antes e depois
								LimpaStringEstoque(descricao);
								// Converter a unidade para maiúsculas
								ConverteMaiusculaEstoque(descricao);
								
								strcpy(pnt_deposito[i].descricao, descricao);
								printf("\n");
								printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
								printf("║                                                     **DESCRICAO ATUALIZADA**                                                    ║\n");
								printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
								printf("║ COD │                   DESCRICAO                 │ NUM │        CATEGORIA        │ QTDE │ UN │ CUSTO UNITARIO │ PRECO UNITARIO ║\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║%5d│\033[32m%45s\033[0m│%5d│%25s│%6d│%4s│%16.2f│%16.2f║\n",
										 pnt_deposito[i].codigo,
										 pnt_deposito[i].descricao,
										 pnt_deposito[i].numero,
										 pnt_deposito[i].categoria,
										 pnt_deposito[i].quantidade,
										 pnt_deposito[i].unidade,
										 pnt_deposito[i].custo,
										 pnt_deposito[i].preco);
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
								
								a = 1;
							}
							
						}
						if(a == 0)
						{
							printf("\n");
							printf("███████████████████████████████████████\n\a");
							printf("█                                     █\n");
							printf("█        PRODUTO NAO ENCONTRADO!      █\n");
							printf("█                                     █\n");
							printf("███████████████████████████████████████\n\n");
						}
						printf("\nAperte uma tecla para continuar... ");
						system("pause > nul");
					a = 1;
					}while(a != 1);	
					
					pont_arq = fopen("estoque.txt","w");	
					
					for(int i = 0; i < y; i++)
					{
						fprintf(pont_arq,"%d\n%s\n%d\n%s\n%d\n%s\n%.2f\n%.2f\n",
											pnt_deposito[i].codigo,
											pnt_deposito[i].descricao,
											pnt_deposito[i].numero,
											pnt_deposito[i].categoria,
											pnt_deposito[i].quantidade,
											pnt_deposito[i].unidade,
											pnt_deposito[i].custo,
											pnt_deposito[i].preco);
					}
					a = 0;
					y = 0;					
					fclose(pont_arq);
					system("cls");					
				
			break;
			case 2:
				y = LeArquivoEstoque(pnt_deposito);
					
					printf("\nATUALIZAR QUANTIDADE\n");
					printf("--------------------\n\n");
					printf("Informe o CODIGO do produto: ");
					codigo = ObtemInteiroValidoEstoque(codigo);
					printf("\n\n");
					
					a = 0;
					
					do{
						for(int i = 0; i < y; i++)
						{	
							if(pnt_deposito[i].codigo == codigo)
							{
								printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
								printf("║                                                      **PRODUTO ENCONTRADO**                                                     ║\n");
								printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
								printf("║ COD │                   DESCRICAO                 │ NUM │        CATEGORIA        │ QTDE │ UN │ CUSTO UNITARIO │ PRECO UNITARIO ║\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║%5d│%45s│%5d│%25s│\033[32m%6d\033[0m│%4s│%16.2f│%16.2f║\n",
										 pnt_deposito[i].codigo,
										 pnt_deposito[i].descricao,
										 pnt_deposito[i].numero,
										 pnt_deposito[i].categoria,
										 pnt_deposito[i].quantidade,
										 pnt_deposito[i].unidade,
										 pnt_deposito[i].custo,
										 pnt_deposito[i].preco);
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
								printf("Informe a NOVA QUANTIDADE: ");
								quantidade = ObtemInteiroValidoEstoque(quantidade);
								pnt_deposito[i].quantidade = quantidade;
								printf("\n");
								printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
								printf("║                                                      **QUANTIDADE ATUALIZADA**                                                  ║\n");
								printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
								printf("║ COD │                   DESCRICAO                 │ NUM │        CATEGORIA        │ QTDE │ UN │ CUSTO UNITARIO │ PRECO UNITARIO ║\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║%5d│%45s│%5d│%25s│\033[32m%6d\033[0m│%4s│%16.2f│%16.2f║\n",
										 pnt_deposito[i].codigo,
										 pnt_deposito[i].descricao,
										 pnt_deposito[i].numero,
										 pnt_deposito[i].categoria,
										 pnt_deposito[i].quantidade,
										 pnt_deposito[i].unidade,
										 pnt_deposito[i].custo,
										 pnt_deposito[i].preco);
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
								
								a = 1;
							}
							
						}
						if(a == 0)
						{
							printf("\n");
							printf("███████████████████████████████████████\n\a");
							printf("█                                     █\n");
							printf("█        PRODUTO NAO ENCONTRADO!      █\n");
							printf("█                                     █\n");
							printf("███████████████████████████████████████\n\n");
						}
						printf("\nAperte uma tecla para continuar... ");
						system("pause > nul");						
					a = 2;
					}while(a != 2);	
					pont_arq = fopen("estoque.txt","w");	
					for(int i = 0; i < y; i++)
					{
						fprintf(pont_arq,"%d\n%s\n%d\n%s\n%d\n%s\n%.2f\n%.2f\n",
											pnt_deposito[i].codigo,
											pnt_deposito[i].descricao,
											pnt_deposito[i].numero,
											pnt_deposito[i].categoria,
											pnt_deposito[i].quantidade,
											pnt_deposito[i].unidade,
											pnt_deposito[i].custo,
											pnt_deposito[i].preco);
					}
					a = 0;
					y = 0;					
					fclose(pont_arq);
					system("cls");
				
			break;
			case 3:
				
				y = LeArquivoEstoque(pnt_deposito);
					
					printf("\nATUALIZAR UNIDADE\n");
					printf("-----------------\n\n");
					printf("Informe o CODIGO do produto: ");
					codigo = ObtemInteiroValidoEstoque(codigo);
					printf("\n\n");
					
					a = 0;
					
					do{
						for(int i = 0; i < y; i++)
						{	
							if(pnt_deposito[i].codigo == codigo)
							{
								printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
								printf("║                                                      **PRODUTO ENCONTRADO**                                                     ║\n");
								printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
								printf("║ COD │                   DESCRICAO                 │ NUM │        CATEGORIA        │ QTDE │ UN │ CUSTO UNITARIO │ PRECO UNITARIO ║\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║%5d│%45s│%5d│%25s│%6d│\033[32m%4s\033[0m│%16.2f│%16.2f║\n",
										 pnt_deposito[i].codigo,
										 pnt_deposito[i].descricao,
										 pnt_deposito[i].numero,
										 pnt_deposito[i].categoria,
										 pnt_deposito[i].quantidade,
										 pnt_deposito[i].unidade,
										 pnt_deposito[i].custo,
										 pnt_deposito[i].preco);
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
								printf("Informe a NOVA UNIDADE: ");
								scanf(" %[^\n]",unidade);
								
								//Limpar a string, remover espaços extras antes e depois
								LimpaStringEstoque(unidade);
								
								//Converter a unidade para maiúsculas para garantir que a comparação não seja sensível a maiúsculas/minúsculas
								ConverteMaiusculaEstoque(unidade);
								
								// Verificar se a unidade informada é válida
								if (strcmp(unidade, unidade_UN) == 0 || strcmp(unidade, unidade_KG) == 0) {
									//Se for válida, copiar para a estrutura
									strcpy(pnt_deposito[i].unidade, unidade);
								}
								else
								{
									//Se for inválida, solicitar ao usuário até fornecer uma unidade válida
									do{
										printf("\n\aDigite uma unidade valida (UN ou KG): ");
										scanf(" %[^\n]", unidade);
										printf("\n");
										// Limpar a string e garantir que a comparação será feita de forma consistente
										LimpaStringEstoque(unidade);
										ConverteMaiusculaEstoque(unidade);
										
									}while (strcmp(unidade, unidade_UN) != 0 && strcmp(unidade, unidade_KG) != 0);

									// Após o loop, a unidade será válida, então copiar para a estrutura
									strcpy(pnt_deposito[i].unidade, unidade);
								}
								
								printf("\n");
								printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
								printf("║                                                      **UNIDADE ATUALIZADA**                                                     ║\n");
								printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
								printf("║ COD │                   DESCRICAO                 │ NUM │        CATEGORIA        │ QTDE │ UN │ CUSTO UNITARIO │ PRECO UNITARIO ║\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║%5d│%45s│%5d│%25s│%6d│\033[32m%4s\033[0m│%16.2f│%16.2f║\n",
										 pnt_deposito[i].codigo,
										 pnt_deposito[i].descricao,
										 pnt_deposito[i].numero,
										 pnt_deposito[i].categoria,
										 pnt_deposito[i].quantidade,
										 pnt_deposito[i].unidade,
										 pnt_deposito[i].custo,
										 pnt_deposito[i].preco);
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
								
								a = 1;
							}
							
						}
						if(a == 0)
						{
							printf("\n");
							printf("███████████████████████████████████████\n\a");
							printf("█                                     █\n");
							printf("█        PRODUTO NAO ENCONTRADO!      █\n");
							printf("█                                     █\n");
							printf("███████████████████████████████████████\n\n");
						}
						printf("\nAperte uma tecla para continuar... ");
						system("pause > nul");
					a = 1;
					}while(a != 1);	
					
					pont_arq = fopen("estoque.txt","w");	
					
					for(int i = 0; i < y; i++)
					{
						fprintf(pont_arq,"%d\n%s\n%d\n%s\n%d\n%s\n%.2f\n%.2f\n",
											pnt_deposito[i].codigo,
											pnt_deposito[i].descricao,
											pnt_deposito[i].numero,
											pnt_deposito[i].categoria,
											pnt_deposito[i].quantidade,
											pnt_deposito[i].unidade,
											pnt_deposito[i].custo,
											pnt_deposito[i].preco);
					}
					a = 0;
					y = 0;					
					fclose(pont_arq);
					system("cls");
			break;
			case 4:			
				y = LeArquivoEstoque(pnt_deposito);
					
					printf("\nATUALIZAR CUSTO\n");
					printf("---------------\n\n");
					printf("Informe o CODIGO do produto: ");
					codigo = ObtemInteiroValidoEstoque(codigo);
					printf("\n\n");
					do{
						for(int i = 0; i < y; i++)
						{	
							if(pnt_deposito[i].codigo == codigo)
							{
								printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
								printf("║                                                      **PRODUTO ENCONTRADO**                                                     ║\n");
								printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
								printf("║ COD │                   DESCRICAO                 │ NUM │        CATEGORIA        │ QTDE │ UN │ CUSTO UNITARIO │ PRECO UNITARIO ║\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║%5d│%45s│%5d│%25s│%6d│%4s│\033[32m%16.2f\033[0m│%16.2f║\n",
										 pnt_deposito[i].codigo,
										 pnt_deposito[i].descricao,
										 pnt_deposito[i].numero,
										 pnt_deposito[i].categoria,
										 pnt_deposito[i].quantidade,
										 pnt_deposito[i].unidade,
										 pnt_deposito[i].custo,
										 pnt_deposito[i].preco);
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
								
								printf("Informe o NOVO CUSTO: ");
								custo = ObtemFloatValidoEstoque();
								pnt_deposito[i].custo = custo;
								
								printf("\n");
								printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
								printf("║                                                         **CUSTO ATUALIZADO**                                                    ║\n");
								printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
								printf("║ COD │                   DESCRICAO                 │ NUM │        CATEGORIA        │ QTDE │ UN │ CUSTO UNITARIO │ PRECO UNITARIO ║\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║%5d│%45s│%5d│%25s│%6d│%4s│\033[32m%16.2f\033[0m│%16.2f║\n",
										 pnt_deposito[i].codigo,
										 pnt_deposito[i].descricao,
										 pnt_deposito[i].numero,
										 pnt_deposito[i].categoria,
										 pnt_deposito[i].quantidade,
										 pnt_deposito[i].unidade,
										 pnt_deposito[i].custo,
										 pnt_deposito[i].preco);
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
								
								a = 1;
							}
						}
						
						if(a == 0)
						{
							printf("\n");
							printf("███████████████████████████████████████\n\a");
							printf("█                                     █\n");
							printf("█        PRODUTO NAO ENCONTRADO!      █\n");
							printf("█                                     █\n");
							printf("███████████████████████████████████████\n\n");
						}
						printf("\nAperte uma tecla para continuar... ");
						system("pause > nul");
					a = 1;
					}while(a != 1);	
					
					pont_arq = fopen("estoque.txt","w");	
					
					for(int i = 0; i < y; i++)
					{
						fprintf(pont_arq,"%d\n%s\n%d\n%s\n%d\n%s\n%.2f\n%.2f\n",
											pnt_deposito[i].codigo,
											pnt_deposito[i].descricao,
											pnt_deposito[i].numero,
											pnt_deposito[i].categoria,
											pnt_deposito[i].quantidade,
											pnt_deposito[i].unidade,
											pnt_deposito[i].custo,
											pnt_deposito[i].preco);
					}
					a = 0;
					y = 0;					
					fclose(pont_arq);
					system("cls");
				
			break;
			case 5:			
				y = LeArquivoEstoque(pnt_deposito);
					
					printf("\nATUALIZAR PRECO\n");
					printf("---------------\n\n");
					printf("Informe o CODIGO do produto: ");
					codigo = ObtemInteiroValidoEstoque(codigo);
					printf("\n\n");
					do{
						for(int i = 0; i < y; i++)
						{	
							if(pnt_deposito[i].codigo == codigo)
							{
								printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
								printf("║                                                      **PRODUTO ENCONTRADO**                                                     ║\n");
								printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
								printf("║ COD │                   DESCRICAO                 │ NUM │        CATEGORIA        │ QTDE │ UN │ CUSTO UNITARIO │ PRECO UNITARIO ║\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║%5d│%45s│%5d│%25s│%6d│%4s│%16.2f│\033[32m%16.2f\033[0m║\n",
										 pnt_deposito[i].codigo,
										 pnt_deposito[i].descricao,
										 pnt_deposito[i].numero,
										 pnt_deposito[i].categoria,
										 pnt_deposito[i].quantidade,
										 pnt_deposito[i].unidade,
										 pnt_deposito[i].custo,
										 pnt_deposito[i].preco);
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
								
								printf("Informe o NOVO PRECO: ");
								preco = ObtemFloatValidoEstoque();
								pnt_deposito[i].preco = preco;
								
								printf("\n");
								printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
								printf("║                                                        **PRECO ATUALIZADO**                                                     ║\n");
								printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
								printf("║ COD │                   DESCRICAO                 │ NUM │        CATEGORIA        │ QTDE │ UN │ CUSTO UNITARIO │ PRECO UNITARIO ║\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║%5d│%45s│%5d│%25s│%6d│%4s│%16.2f│\033[32m%16.2f\033[0m║\n",
										 pnt_deposito[i].codigo,
										 pnt_deposito[i].descricao,
										 pnt_deposito[i].numero,
										 pnt_deposito[i].categoria,
										 pnt_deposito[i].quantidade,
										 pnt_deposito[i].unidade,
										 pnt_deposito[i].custo,
										 pnt_deposito[i].preco);
								printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
								
								a = 1;
							}	
						}
						
						if(a == 0)
						{
							printf("\n");
							printf("███████████████████████████████████████\n\a");
							printf("█                                     █\n");
							printf("█        PRODUTO NAO ENCONTRADO!      █\n");
							printf("█                                     █\n");
							printf("███████████████████████████████████████\n\n");
						}
						printf("\nAperte uma tecla para continuar... ");
						system("pause > nul");
					a = 1;
					}while(a != 1);	
					
					pont_arq = fopen("estoque.txt","w");	
					
					for(int i = 0; i < y; i++)
					{
						fprintf(pont_arq,"%d\n%s\n%d\n%s\n%d\n%s\n%.2f\n%.2f\n",
											pnt_deposito[i].codigo,
											pnt_deposito[i].descricao,
											pnt_deposito[i].numero,
											pnt_deposito[i].categoria,
											pnt_deposito[i].quantidade,
											pnt_deposito[i].unidade,
											pnt_deposito[i].custo,
											pnt_deposito[i].preco);
					}
					a = 0;
					y = 0;					
					fclose(pont_arq);
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

void RemoveProduto(Estoque * pnt_deposito)
{
	FILE *pont_arq;
	int y = 0;
	int r = 0;
	int op = 0;
	int codigo = 0;
	int menu_remove = 0;
	
	system("cls");
		
	do{
		r = 0;
		y = 0;
		
		y = LeArquivoEstoque(pnt_deposito);
			
		printf("\n");
			
		printf("REMOVER PRODUTO\n");
		printf("---------------\n\n");
		printf("Informe o CODIGO do produto a ser removido: ");
		codigo = ObtemInteiroValidoEstoque(codigo);
		printf("\n");
			
		for(int i = 0; i < y; i++)
		{
			if(pnt_deposito[i].codigo == codigo)
			{
				printf("\n");
				printf("╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
				printf("║                                                       **PRODUTO ENCONTRADO**                                                    ║\n");
				printf("╠═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
				printf("║ COD │                   DESCRICAO                 │ NUM │        CATEGORIA        │ QTDE │ UN │ CUSTO UNITARIO │ PRECO UNITARIO ║\n");
				printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
				printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
				printf("║\033[31m%5d\033[0m│\033[31m%45s\033[0m│%5d│%25s│%6d│%4s│%16.2f│%16.2f║\n",
						 pnt_deposito[i].codigo,
						 pnt_deposito[i].descricao,
						 pnt_deposito[i].numero,
						 pnt_deposito[i].categoria,
						 pnt_deposito[i].quantidade,
						 pnt_deposito[i].unidade,
						 pnt_deposito[i].custo,
						 pnt_deposito[i].preco);
				printf("╟─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
				printf("╚═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
				r = 1;
			}
		}	
			
		if(r == 1)
		{
			printf("\nRemover produto - 1\n");
			printf("Cancelar remoção e continuar busca - 2\n");
			printf("Cancelar remoção e voltar ao MENU INICIAL - 0\n");
			menu_remove = ObtemInteiroValidoEstoque(menu_remove);
			
			switch (menu_remove)
			{
				case 1:
					pont_arq = fopen("estoque.txt","w");
					
					for(int i = 0; i < y; i++)
					{
						if(pnt_deposito[i].codigo != codigo)
						{
							fprintf(pont_arq,"%d\n%s\n%d\n%s\n%d\n%s\n%.2f\n%.2f\n",
											  pnt_deposito[i].codigo,
											  pnt_deposito[i].descricao,
											  pnt_deposito[i].numero,
											  pnt_deposito[i].categoria,
											  pnt_deposito[i].quantidade,
											  pnt_deposito[i].unidade,
											  pnt_deposito[i].custo,
											  pnt_deposito[i].preco);
						}
					}
						
					fclose(pont_arq);
					
					system("cls");
					printf("\n\nPRODUTO REMOVIDO\n\n");
					printf("Remover outro produto - 1 | Voltar ao MENU INICIAL - 2\n");
					op = ObtemInteiroValidoEstoque(op);
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
								printf("Remover outro produto - 1 | Voltar ao MENU INICIAL - 2\n");
								op = ObtemInteiroValidoEstoque(op);
							}while(op < 1 || op > 2);
					}
						//printf("\nAperte uma tecla para continuar... ");
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
						printf("\nRemover produto - 1\n");
						printf("Cancelar remoção e continuar busca - 2\n");
						printf("Cancelar remoção e voltar ao MENU INICIAL - 0\n");
						menu_remove = ObtemInteiroValidoEstoque(menu_remove);
					}while(menu_remove < 0 || menu_remove > 2);
			}
		}
		if(r == 0)
		{
			printf("\n");
			printf("███████████████████████████████████████\n\a");
			printf("█                                     █\n");
			printf("█        PRODUTO NAO ENCONTRADO!      █\n");
			printf("█                                     █\n");
			printf("███████████████████████████████████████\n\n");
				
			printf("Continuar busca - 1 | Voltar ao MENU INICIAL - 0\n");
			menu_remove = ObtemInteiroValidoEstoque(menu_remove);
				
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
						
						menu_remove = ObtemInteiroValidoEstoque(menu_remove);
						
					}while(menu_remove < 0 || menu_remove > 1);
			}		
		}	
	}while(r != 2);	
}

void RemoveCategoria(Estoque * pnt_deposito)
{
	FILE *pont_categoria;
	int y = 0;
	int r = 0;
	int op = 0;
	int numero_categoria = 0;
	int menu_remove = 0;
	
	system("cls");
		
	if(pont_categoria == NULL)
	{
		printf("\nERRO! O arquivo nao foi aberto!\n\n");
	}
	else
	{
		
		do{
			r = 0;
			y = 0;
			
			pont_categoria = fopen("categoria.txt","r");
			
			printf("\nO arquivo foi aberto com sucesso\n\n");
			
			while(fscanf(pont_categoria,"%d\n%[^\n]\n",
									&pnt_deposito[y].numero,
									pnt_deposito[y].categoria) != EOF)
			{
				y++;
			}
			fclose(pont_categoria);
			
			printf("\nO arquivo foi aberto com sucesso\n\n");
			
			printf("REMOVER CATEGORIA\n");
			printf("-----------------\n\n");
			printf("Informe o NUMERO da categoria a ser removida: ");
			numero_categoria = ObtemInteiroValidoEstoque(numero_categoria);
			printf("\n");
			
			for(int i = 0; i < y; i++)
			{
				if(pnt_deposito[i].numero == numero_categoria)
				{
					printf("\n");
					printf("╔═════════════════════════════════════╗\n");
					printf("║       **CATEGORIA ENCONTRADA**      ║\n");
					printf("╠═════════════════════════════════════╣\n");
					printf("║ NUM │           CATEGORIA           ║\n");
					printf("╟─────────────────────────────────────╢\n");
					printf("╟─────────────────────────────────────╢\n");
					printf("║│%5d\033[32m%31s\033[0m║\n",
							 pnt_deposito[i].numero,
							 pnt_deposito[i].categoria);
					printf("╟─────────────────────────────────────╢\n");
					printf("╚═════════════════════════════════════╝\n\n");
					r = 1;
				}
			}	
			
			if(r == 1)
			{
				printf("\nRemover categoria - 1\n");
				printf("Cancelar remoção e continuar busca - 2\n");
				printf("Cancelar remoção e voltar ao MENU INICIAL - 0\n");
				menu_remove = ObtemInteiroValidoEstoque(menu_remove);
				
				switch (menu_remove)
				{
					case 1:
						pont_categoria = fopen("categoria.txt","w");
						
						for(int i = 0; i < y; i++)
						{
							if(pnt_deposito[i].numero != numero_categoria)
							{
								fprintf(pont_categoria,"%d\n%s\n",
												  pnt_deposito[i].numero,
												  pnt_deposito[i].categoria);
							}
						}
						
						fclose(pont_categoria);
						printf("\n\nCATEGORIA REMOVIDA\n\n");
						printf("Remover outra categoria - 1 | Voltar ao MENU INICIAL - 2\n");
						op = ObtemInteiroValidoEstoque(op);
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
									printf("Remover outra categoria - 1 | Voltar ao MENU INICIAL - 2\n");
									op = ObtemInteiroValidoEstoque(op);
								}while(op < 1 || op > 2);
						}
						
					break;
					case 2:
						r = 1;
						printf("\n\nREMOCAO CANCELADA\n\n");
						printf("\nAperte uma tecla para continuar busca... \n\n");
						system("pause > nul");
						system("cls");
					break;
					case 0:
						r = 2;
						printf("\n\nREMOCAO CANCELADA\n\n");
						printf("\nAperte uma tecla para voltar ao MENU INICIAL... \n\n");
						system("pause > nul");
					break;
					default:
						do{
							printf("\nDigite uma opcao valida!\n\n");
							printf("\nRemover categoria - 1\n");
							printf("Cancelar remoção e continuar busca - 2\n");
							printf("Cancelar remoção e voltar ao MENU INICIAL - 0\n");
							menu_remove = ObtemInteiroValidoEstoque(menu_remove);
						}while(menu_remove < 0 || menu_remove > 2);
				}
			}
			if(r == 0)
			{
				printf("\n");
				printf("███████████████████████████████████████\n\a");
				printf("█                                     █\n");
				printf("█      CATEGORIA NAO ENCONTRADA!      █\n");
				printf("█                                     █\n");
				printf("███████████████████████████████████████\n\n");
					
				printf("Continuar busca - 1 | Voltar ao MENU INICIAL - 0\n");
				
				menu_remove = ObtemInteiroValidoEstoque(menu_remove);
					
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
							
							menu_remove = ObtemInteiroValidoEstoque(menu_remove);
							
						}while(menu_remove < 0 || menu_remove > 1);
				}		
			}	
		}while(r != 2);
	}

}

void CalculaBalancoProduto(Estoque * pnt_deposito)
{
	system("color 07");
	FILE *pont_arq;
	FILE *pont_categoria;
	int acumulador_quantidade = 0;
	
	float acumulador_preco = 0.0;
	int64_t acumulador_preco_total = 0;
	int64_t preco_reais = 0;
	int64_t preco_centavos = 0;
	float total_preco_produto = 0.0;
	
	float acumulador_custo = 0.0;
	int64_t acumulador_custo_total = 0;
	int64_t custo_reais = 0;
	int64_t custo_centavos = 0;
	float total_custo_produto = 0.0;
	
	int codigo = 0;
	int y = 0;
	int c = 0;
	int t = 0;
	int op = -1;
	
	system("cls");
	
	pont_categoria = fopen("categoria.txt","r");
	while(fscanf(pont_categoria,"%d\n%[^\n]\n",
							&pnt_deposito[y].numero,
							pnt_deposito[y].categoria) != EOF)
	{
		c++;
	}
	fclose(pont_categoria);
	
	y = LeArquivoEstoque(pnt_deposito);

	do{
		MenuBalancoEstoque();
		scanf("%d",&op);
		
		switch(op)
		{
			case 1:
				do{
					system("cls");
					printf("\nCALCULO TOTAL DO PRODUTO\n");
					printf("------------------------\n\n");
					printf("Informe o CODIGO do produto: ");
					codigo = ObtemInteiroValidoEstoque(codigo);
					printf("\n");
					
					total_preco_produto = 0.0;
					t = 0;
					
					for(int i = 0; i < y; i++)
					{	
						if(pnt_deposito[i].codigo == codigo)
						{
		
							total_preco_produto = pnt_deposito[i].quantidade * pnt_deposito[i].preco;
							total_preco_produto *= 100;
							acumulador_preco_total += (int)total_preco_produto;
							preco_reais = acumulador_preco_total / 100;
							preco_centavos = llabs(acumulador_preco_total % 100);
							
							total_custo_produto = pnt_deposito[i].quantidade * pnt_deposito[i].custo;
							total_custo_produto *= 100;
							acumulador_custo_total += (int)total_custo_produto;
							custo_reais = acumulador_custo_total / 100;
							custo_centavos = llabs(acumulador_custo_total % 100);
						
							printf("\n");
							printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                                                     **CALCULO TOTAL DO PRODUTO**                                                                  ║\n");
							printf("╠═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
							printf("║ COD │                   DESCRICAO                 │ NUM │        CATEGORIA        │ QTDE │ UN │ CUSTO UNITARIO │  CUSTO TOTAL   │ PRECO UNITARIO │  PRECO TOTAL   ║\n");
							printf("╟───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("║%5d│\033[32m%45s\033[0m│%5d│%25s│%6d│%4s│%16.2f│\x1b[36m%13lld.%02lld\x1b[0m│%16.2f│\x1b[36m%13lld.%02lld\x1b[0m║\n",
									 pnt_deposito[i].codigo,
									 pnt_deposito[i].descricao,
									 pnt_deposito[i].numero,
									 pnt_deposito[i].categoria,
									 pnt_deposito[i].quantidade,
									 pnt_deposito[i].unidade,
									 pnt_deposito[i].custo,
									 (long long)custo_reais,
									 (long long)custo_centavos,
									 pnt_deposito[i].preco,
									 (long long)preco_reais,
									 (long long)preco_centavos);
							printf("╟───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
							printf("CALCULO CONCLUIDO\n\n");
							t = 1;
						}	
					}
					
					if(t == 0)
					{
						printf("\n");
						printf("███████████████████████████████████████\n\a");
						printf("█                                     █\n");
						printf("█        PRODUTO NAO ENCONTRADO!      █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n\n\n");
					}	
					
					total_preco_produto = 0.0;
					acumulador_preco = 0.0;
					acumulador_preco_total = 0;
					
					total_custo_produto = 0.0;
					acumulador_custo = 0.0;
					acumulador_custo_total = 0;
					
					printf("Realizar outro calculo - 1 | Voltar ao MENU - 2\n");
					op = ObtemInteiroValidoEstoque(op);
					switch (op)
					{
						case 1:
						break;
						case 2:
							op = 2;
							system("cls");
						break;
						default:
							do{
								printf("\n\nDigite uma opcao valida!\n\n");
								printf("Realizar outro calculo - 1 | Voltar ao MENU - 2\n");
								op = ObtemInteiroValidoEstoque(op);
							}while(op < 1 || op > 2);
							system("cls");
					}
					
				}while(op != 2);
				op = -1;
				system("cls");	
			break;
			case 2:
				system("cls");
					
				total_preco_produto = 0.0;
				acumulador_preco = 0.0;
				acumulador_preco_total = 0;
				acumulador_quantidade = 0;
				preco_reais = 0;
				preco_centavos = 0;
				
				total_custo_produto = 0.0;
				acumulador_custo = 0.0;
				acumulador_custo_total = 0;
				acumulador_quantidade = 0;
				custo_reais = 0;
				custo_centavos = 0;
				
				if(y > 0)
				{
					printf("\n");
					printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
					printf("║                                                                     **BALANCO GERAL DETALHADO**                                                                   ║\n");
					printf("╠═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
					printf("║ COD │                   DESCRICAO                 │ NUM │        CATEGORIA        │ QTDE │ UN │ CUSTO UNITARIO │  CUSTO TOTAL   │ PRECO UNITARIO │  PRECO TOTAL   ║\n");
					printf("╟───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
					printf("╟───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
				
				}
				
				for(int i = 0; i < y; i++)
				{	
					total_preco_produto = pnt_deposito[i].quantidade * pnt_deposito[i].preco;
					total_preco_produto *= 100;
					acumulador_preco_total = (int)total_preco_produto;
					preco_reais = acumulador_preco_total / 100;
					preco_centavos = llabs(acumulador_preco_total % 100);
					
					total_custo_produto = pnt_deposito[i].quantidade * pnt_deposito[i].custo;
					total_custo_produto *= 100;
					acumulador_custo_total = (int)total_custo_produto;
					custo_reais = acumulador_custo_total / 100;
					custo_centavos = llabs(acumulador_custo_total % 100);
					
					if(i != 0 && i % 10 == 0)
					{
						printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
						printf("\nAperte qualquer tecla para continuar o calculo e a listagem dos produtos... \n\n");
						system("pause > nul");
						printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
						printf("║ COD │                   DESCRICAO                 │ NUM │        CATEGORIA        │ QTDE │ UN │ CUSTO UNITARIO │  CUSTO TOTAL   │ PRECO UNITARIO │  PRECO TOTAL   ║\n");
						printf("╟───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
						printf("╟───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
					}
					if(i % 2 == 0)
					{
						printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%45s\x1b[0m│\x1b[36m%5d\x1b[0m│\x1b[36m%25s\x1b[0m│\x1b[36m%6d\x1b[0m│\x1b[36m%4s\x1b[0m│\x1b[36m%16.2f\x1b[0m│\x1b[36m%13lld.%02lld\x1b[0m│\x1b[36m%16.2f\x1b[0m│\x1b[36m%13lld.%02lld\x1b[0m║\n",
								 pnt_deposito[i].codigo,
								 pnt_deposito[i].descricao,
								 pnt_deposito[i].numero,
								 pnt_deposito[i].categoria,
								 pnt_deposito[i].quantidade,
								 pnt_deposito[i].unidade,
								 pnt_deposito[i].custo,
								 (long long)custo_reais,
								 (long long)custo_centavos,
								 pnt_deposito[i].preco,
								 (long long)preco_reais,
								 (long long)preco_centavos);
						printf("╟───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
					}
					else
					{
						printf("║%5d│%45s│%5d│%25s│%6d│%4s│%16.2lf│%13lld.%02lld│%16.2lf│%13lld.%02lld║\n",
							     pnt_deposito[i].codigo,
								 pnt_deposito[i].descricao,
								 pnt_deposito[i].numero,
								 pnt_deposito[i].categoria,
								 pnt_deposito[i].quantidade,
								 pnt_deposito[i].unidade,
								 pnt_deposito[i].custo,
								 (long long)custo_reais,
								 (long long)custo_centavos,
								 pnt_deposito[i].preco,
								 (long long)preco_reais,
								 (long long)preco_centavos);
						printf("╟───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
					}
					
				}
				
				acumulador_preco = 0.0;
				acumulador_custo = 0.0;
				
				for(int i = 0; i < y; i++)
				{
					acumulador_custo += pnt_deposito[i].quantidade * pnt_deposito[i].custo;
					acumulador_preco += pnt_deposito[i].quantidade * pnt_deposito[i].preco;
					acumulador_quantidade += pnt_deposito[i].quantidade;
				}
				
				acumulador_custo *= 100;
				acumulador_custo_total = (int)acumulador_custo;
				custo_reais = acumulador_custo_total / 100;
				custo_centavos = llabs(acumulador_custo_total % 100);
				
				acumulador_preco *= 100;
				acumulador_preco_total = (int)acumulador_preco;
				preco_reais = acumulador_preco_total / 100;
				preco_centavos = llabs(acumulador_preco_total % 100);
				
				if(y > 0)
				{
					printf("╟───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
					printf("║                                                          │  ANO  │  CATEGORIA  │  PRODUTOS   │  TOTAL DE ITENS  │      CUSTO FINAL       │       PRECO FINAL      ║\n");
					printf("╟───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
					printf("╟───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
					printf("║                                                          │   \x1b[36m2025\x1b[0m│\x1b[36m%13d\x1b[0m│\x1b[36m%13d\x1b[0m│\x1b[36m%18d\x1b[0m│\x1b[36m%21lld.%02lld\x1b[0m│\x1b[36m%21lld.%02lld\x1b[0m║\n",
							 c,
							 y,
							 acumulador_quantidade,
							 (long long)custo_reais,
							 (long long)custo_centavos,
							 (long long)preco_reais,
							 (long long)preco_centavos);
					printf("╟───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
					printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
					printf("CALCULO E LISTAGEM CONCLUIDOS\n");
				}
				
				if(y == 0)
				{
					printf("\nO arquivo estoque esta vazio! Não há dados a serem exibidos\n");
				}
				
				printf("\nAperte qualquer tecla para voltar ao MENU... \n\n");
				system("pause > nul");
				system("cls");				
				
				total_preco_produto = 0.0;
				acumulador_preco = 0.0;
				acumulador_preco_total = 0;
				
				total_custo_produto = 0.0;
				acumulador_custo = 0.0;
				acumulador_custo_total = 0;
				
				acumulador_quantidade = 0;
				
			break;
			case 3:
				acumulador_custo = 0.0;
				acumulador_custo_total = 0;
				total_custo_produto = 0.0;
				custo_reais = 0;
				custo_centavos = 0;
				
				acumulador_preco = 0.0;
				acumulador_preco_total = 0;
				total_preco_produto = 0.0;
				preco_reais = 0;
				preco_centavos = 0;
				
				acumulador_quantidade = 0;
				
				system("cls");
				
				for(int i = 0; i < y; i++)
				{
					acumulador_custo += pnt_deposito[i].quantidade * pnt_deposito[i].custo;
					acumulador_preco += pnt_deposito[i].quantidade * pnt_deposito[i].preco;
					acumulador_quantidade += pnt_deposito[i].quantidade;
				}
				
				acumulador_custo *= 100;
				acumulador_custo_total += (int)acumulador_custo; // em centavos
				custo_reais = acumulador_custo_total / 100;
				custo_centavos = llabs(acumulador_custo_total % 100);
				
				acumulador_preco *= 100;
				acumulador_preco_total += (int)acumulador_preco; // em centavos
				preco_reais = acumulador_preco_total / 100;
				preco_centavos = llabs(acumulador_preco_total % 100);
				
				if(y > 0)
				{
					printf("\n");
					printf("╔══════════════════════════════════════════════════════════════════════════════════╗\n");
					printf("║                             **BALANCO GERAL RESUMIDO**                           ║\n");
					printf("╠══════════════════════════════════════════════════════════════════════════════════╣\n");	
					printf("║  CATEGORIA  │  PRODUTOS  │     ITENS     │    CUSTO TOTAL    │    PRECO TOTAL    ║\n");
					printf("╟──────────────────────────────────────────────────────────────────────────────────╢\n");
					printf("╟──────────────────────────────────────────────────────────────────────────────────╢\n");
					printf("║\x1b[36m%13d\x1b[0m│\x1b[36m%12d\x1b[0m│\x1b[36m%15d\x1b[0m│\x1b[36m%16lld.%02lld\x1b[0m│\x1b[36m%16lld.%02lld\x1b[0m║\n",
							 c,
							 y,
							 acumulador_quantidade,
							 (long long)custo_reais,
							 (long long)custo_centavos,
							 (long long)preco_reais,
							 (long long)preco_centavos);
					printf("╟──────────────────────────────────────────────────────────────────────────────────╢\n");
					printf("╚══════════════════════════════════════════════════════════════════════════════════╝\n");
					printf("\nBALANCO FINALIZADO\n");
				}
				
				if(y == 0)
				{
					printf("\nO arquivo estoque esta vazio! Não há dados a serem exibidos\n");
				}
				
				printf("\nAperte uma tecla para continuar... ");
				system("pause > nul");
				system("cls");

				total_custo_produto = 0.0;
				acumulador_custo = 0.0;
				acumulador_custo_total = 0;
				
				total_preco_produto = 0.0;
				acumulador_preco = 0.0;
				acumulador_preco_total = 0;
				
				acumulador_quantidade = 0;
				
			break;
			case 0:
				system("cls");
			break;
			default:
				printf("\nDigite uma opcao valida\n\n");
		}
	}while(op != 0);
}

void ReordenaCodigoProduto(Estoque  * pnt_deposito)
{
	FILE *pont_arq;
	int y = 0;
	int op = -1;
	
	system("cls");
	
	y = LeArquivoEstoque(pnt_deposito);
	
	printf("\n██████████████████████████████████████████████████████████████████████████████\n\a");
	printf("█                                                                            █\n");
	printf("█   \033[31mATENÇÃO!\033[0m Todos os CODIGOS dos PRODUTOS do sistema serão REORDENADOS...   █\n");
	printf("█                                                                            █\n");
	printf("██████████████████████████████████████████████████████████████████████████████\n\n");
	
	printf("Confirmar - 1 | Cancelar - 0\n");
	op = ObtemInteiroValidoEstoque(op);
	
	switch(op)
	{
		case 1:
			if(pont_arq != NULL)
			{
				pont_arq = fopen("estoque.txt","w");
				for(int i = 0; i < y; i++)
				{
					pnt_deposito[i].codigo = i + 1;
					fprintf(pont_arq,"%d\n%s\n%d\n%s\n%d\n%s\n%.2f\n%.2f\n",
									  pnt_deposito[i].codigo,
									  pnt_deposito[i].descricao,
									  pnt_deposito[i].numero,
									  pnt_deposito[i].categoria,
									  pnt_deposito[i].quantidade,
									  pnt_deposito[i].unidade,
									  pnt_deposito[i].custo,
									  pnt_deposito[i].preco);
				}
				
				fclose(pont_arq);
				
				printf("\n\nCODIGOS REORDENADOS\n\n");
				printf("\nAperte qualquer tecla para voltar ao MENU INICIAL ... \n\n");
				system("pause > nul");
				system("cls");
			}
			
			else
			{
				system("cls");
				printf("\n\nOs codigos dos produtos nao foram reordenados...\n\n");
				printf("ERRO ao acessar o arquivo! Contate o administrador do sistema\n\n");
			}
		break;
		case 0:
			printf("\n\nACAO CANCELADA\n\n");
			printf("\nAperte qualquer tecla para voltar ao MENU INICIAL ... \n\n");
			system("pause > nul");
			system("cls");
		break;	
		default:
			printf("\nDigite uma opcao valida\n\n");
	}
}

int ComparaPalavrasProduto(char *palavra1, char *palavra2)
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

void BubbleSortNumeroCategoria(Estoque * pnt_deposito, int opcao, int tamanho)
{
	
	Estoque aux;
	if(opcao == 1)
	{	
		for(int i = 0; i < tamanho; i++)
		{
			for(int k = 0; k < tamanho-1; k++)
			{
				if(pnt_deposito[i].numero < pnt_deposito[k].numero)
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
				if(pnt_deposito[i].numero > pnt_deposito[k].numero)
				{
					aux = pnt_deposito[i];
					pnt_deposito[i] = pnt_deposito[k];
					pnt_deposito[k] = aux;
				}
			}
		}
	}
}

void BubbleSortCodigoProduto(Estoque * pnt_deposito, int opcao, int tamanho)
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

void BubbleSortQuantidadeProduto(Estoque * pnt_deposito, int opcao, int tamanho)
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

void BubbleSortPrecoProduto(Estoque * pnt_deposito, int opcao, int tamanho)
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

void BubbleSortDescricaoProduto(Estoque * pnt_deposito, int opcao, int tamanho)
{
	Estoque aux;
	int troca = -1;

	for(int i = 0; i < tamanho; i++)
	{
		for(int k = 0; k < tamanho-1; k++)
		{
			if(opcao == 1)
			{
				troca = ComparaPalavrasProduto(pnt_deposito[i].descricao,pnt_deposito[k].descricao);
				if(!troca)
				{
					aux = pnt_deposito[i];
					pnt_deposito[i] = pnt_deposito[k];
					pnt_deposito[k] = aux;
				}
			}
			else
			{
				troca = ComparaPalavrasProduto(pnt_deposito[i].descricao,pnt_deposito[k].descricao);
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

void FiltraOrdenaProduto(Estoque  * pnt_deposito)
{
	FILE * pont_arq;
	int i = 0;
	int escolha = 0;
	
	system("cls");
	
	i = LeArquivoEstoque(pnt_deposito);
				
		do{
			FiltraProduto();
			//LimpaBufferEstoque();
			escolha = ObtemInteiroValidoEstoque(escolha);
			if(escolha < 0 || escolha > 4)
			{
				do{
					system("cls");
					FiltraProduto();
					printf("Escolha uma opcao valida no sistema!\a\n\n");
					//LimpaBufferEstoque();
					escolha = ObtemInteiroValidoEstoque(escolha);
				}while(escolha < 0 || escolha > 4);
			}
			system("cls");
			switch(escolha)
			{
				//Ordenar por Descrição do produto(s);
				case 1:
					OrdemProduto();
					//LimpaBufferEstoque();
					escolha = ObtemInteiroValidoEstoque(escolha);
					if(escolha < 1 || escolha > 2)
					{
						do{
							system("cls");
							OrdemProduto();
							printf("Escolha uma opcao valida no sistema!\a\n\n");
							//LimpaBufferEstoque();
							escolha = ObtemInteiroValidoEstoque(escolha);
						}while(escolha < 1 || escolha > 2);
					}
					switch(escolha)
					{
						//Crescente 
						case 1:
							BubbleSortDescricaoProduto(pnt_deposito, escolha, i);
							system("cls");
							printf("\n╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                                   **FILTRAGEM POR DESCRICAO - CRESCENTE**                                       ║\n");
							ImprimeProduto(pnt_deposito, i);
							printf("\nAperte qualquer tecla para voltar ao MENU... \n\n");
							system("pause > nul");
							system("cls");

							
						break;
						//Decrescente 
						case 2:
							BubbleSortDescricaoProduto(pnt_deposito, escolha, i);
							system("cls");
							printf("\n╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                                  **FILTRAGEM POR DESCRICAO - DECRESCENTE**                                      ║\n");
							ImprimeProduto(pnt_deposito, i);
							printf("\nAperte qualquer tecla para voltar ao MENU... \n\n");
							system("pause > nul");
							system("cls");
						break;
						
					}
				break;
				//Ordernar por Codigo do produto;
				case 2:
					OrdemProduto();
					//LimpaBufferEstoque();
					escolha = ObtemInteiroValidoEstoque(escolha);
					if(escolha < 1 || escolha > 2)
					{
						do{
							system("cls");
							OrdemProduto();
							printf("Escolha uma opcao valida no sistema!\a\n\n");
							escolha = ObtemInteiroValidoEstoque(escolha);
						}while(escolha < 1 || escolha > 2);
					}
					switch(escolha)
					{
						//Crescente 
						case 1:
							BubbleSortCodigoProduto(pnt_deposito, escolha, i);
							system("cls");
							printf("\n╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                                     **FILTRAGEM POR CODIGO - CRESCENTE**                                        ║\n");
							ImprimeProduto(pnt_deposito, i);
							printf("\nAperte qualquer tecla para voltar ao MENU... \n\n");
							system("pause > nul");
							system("cls");

						break;
						//Decrescente 
						case 2:
							BubbleSortCodigoProduto(pnt_deposito, escolha, i);
							system("cls");
							printf("\n╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                                    **FILTRAGEM POR CODIGO - DECRESCENTE**                                       ║\n");
							ImprimeProduto(pnt_deposito, i);
							printf("\nAperte qualquer tecla para voltar ao MENU... \n\n");
							system("pause > nul");
							system("cls");

						break;
					}
				break;
				//Ordernar por Quantidade de produtos no estoque;
				case 3:
					OrdemProduto();
					//LimpaBufferEstoque();
					escolha = ObtemInteiroValidoEstoque(escolha);
					if(escolha < 1 || escolha > 2)
					{
						do{
							system("cls");
							OrdemProduto();
							printf("Escolha uma opcao valida no sistema!\a\n\n");
							//LimpaBufferEstoque();
							escolha = ObtemInteiroValidoEstoque(escolha);
						}while(escolha < 1 || escolha > 2);
					}
					switch(escolha)
					{
						//Crescente 
						case 1:
							
							BubbleSortQuantidadeProduto(pnt_deposito, escolha, i);
							system("cls");
							printf("\n╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                                  **FILTRAGEM POR QUANTIDADE - CRESCENTE**                                       ║\n");
							ImprimeProduto(pnt_deposito, i);
							printf("\nAperte qualquer tecla para voltar ao MENU... \n\n");
							system("pause > nul");
							system("cls");

						break;
						//Decrescente
						case 2:
							BubbleSortQuantidadeProduto(pnt_deposito, escolha, i);
							system("cls");
							printf("\n╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                                 **FILTRAGEM POR QUANTIDADE - DECRESCENTE**                                      ║\n");
							ImprimeProduto(pnt_deposito, i);
							printf("\nAperte qualquer tecla para voltar ao MENU... \n\n");
							system("pause > nul");
							system("cls");

						break;
					}
				break;
				//Ordernar por Preco do Produto;
				case 4:
					OrdemProduto();
					//LimpaBufferEstoque();
					escolha = ObtemInteiroValidoEstoque(escolha);
					if(escolha < 1 || escolha > 2)
					{
						do{
							system("cls");
							OrdemProduto();
							printf("Escolha uma opcao valida no sistema!\a\n\n");
							//LimpaBufferEstoque();
							escolha = ObtemInteiroValidoEstoque(escolha);
						}while(escolha < 1 || escolha > 2);
					}
					switch(escolha)
					{
						//Crescente 
						case 1:
							BubbleSortPrecoProduto(pnt_deposito, escolha, i);
							system("cls");
							printf("\n╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                                    **FILTRAGEM POR PRECO - CRESCENTE**                                          ║\n");
							ImprimeProduto(pnt_deposito, i);
							printf("\nAperte qualquer tecla para voltar ao MENU... \n\n");
							system("pause > nul");
							system("cls");

						break;
						//Decrescente 
						case 2:
							BubbleSortPrecoProduto(pnt_deposito, escolha, i);
							system("cls");
							printf("\n╔═════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                                   **FILTRAGEM POR PRECO - DECRESCENTE**                                         ║\n");
							ImprimeProduto(pnt_deposito, i);
							printf("\nAperte qualquer tecla para voltar ao MENU... \n\n");
							system("pause > nul");
							system("cls");

						break;
					}	
				break;
				
				default:
					system("cls");
			}
		}while(escolha != 0);	
}

void ApagaDadosSistemaProduto(Estoque  * pnt_deposito)
{
	FILE * pont_arq;
	int op = -1;
	
	system("cls");
	
	printf("\n███████████████████████████████████████████████████████████████████████████\n\a");
	printf("█                                                                         █\n");
	printf("█   \033[31mATENÇÃO!\033[0m Todos os DADOS do ESTOQUE do sistema serão DELETADOS...      █\n");
	printf("█                                                                         █\n");
	printf("███████████████████████████████████████████████████████████████████████████\n\n");
	
	printf("Confirmar - 1 | Cancelar - 0\n");
	op = ObtemInteiroValidoEstoque(op);
	if(op < 0 || op > 1)
	{
		do{
			system("cls");
		
			printf("\n███████████████████████████████████████████████████████████████████████████\n\a");
			printf("█                                                                         █\n");
			printf("█   \033[31mATENÇÃO!\033[0m Todos os DADOS do ESTOQUE do sistema serão DELETADOS...      █\n");
			printf("█                                                                         █\n");
			printf("███████████████████████████████████████████████████████████████████████████\n\n");
			
			printf("Confirmar - 1 | Cancelar - 0\n");
			printf("\nDigite uma opcao valida!\n\n");
			op = ObtemInteiroValidoEstoque(op);
		}while(op < 0 || op > 1);
	}
	
	switch(op)
	{
		case 1:
			if(pont_arq != NULL)
			{
				pont_arq = fopen("estoque.txt","w");
				fprintf(pont_arq,"%s","");
				fclose(pont_arq);
				printf("\n\nDADOS REMOVIDOS\n\n");
				printf("\nAperte qualquer tecla para voltar ao MENU INICIAL...");
				system("pause > nul");
				system("cls");
			}	
			
			else
			{
				printf("\n\nOs dados do estoque nao foram apagados...\n\n");
				printf("ERRO ao acessar o arquivo! Contate o administrador do sistema\n\n");
			}
		break;
		case 0:
			printf("\n\nACAO CANCELADA\n\n");
			printf("\nAperte qualquer tecla para voltar ao MENU INICIAL...");
			system("pause > nul");
			system("cls");
	}
}

void LimpaStringEstoque(char *str)
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

void ConverteMaiusculaEstoque(char *str)
{
    while (*str)
	{
        *str = toupper((unsigned char)*str);
        str++;
    }
}

float ObtemFloatValidoEstoque()
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