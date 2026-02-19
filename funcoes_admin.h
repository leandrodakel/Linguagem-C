//funcoes_admin

void MenuAdmin();
void ListaCategoria(Estoque  * pnt_deposito);
void ApagaDadosSistemaCategoria(Estoque  * pnt_deposito);

//void CalculaBalancoProduto(Estoque  * pnt_deposito);
//void CalculaBalancoVarejo(Pedido * pnt_recibo);

void MenuAdmin()
{
	system("chcp 65001 > nul");
	system("color 07");
	printf("\n");
	
	printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════╗ ╔═══════════════════════════════════════════════════╗\n");
	printf("║                                        *** B E M - V I N D O ***                                      ║ ║      SISTEMA DESENVOLVIDO POR LGR TECNOLOGIA      ║\n");
	printf("║                  S I S T E M A   D E   G E R E N C I A M E N T O   D E   E M P R E S A                ║ ║                    VERSAO 1.0                     ║\n");
	printf("╠═══════════════════════════════════════════════════╦═══════════════════════════════════════════════════╣ ╠═══════════════════════════════════════════════════╣\n");
	printf("║               CADASTRO DE CLIENTES                ║                REGISTRO DE PEDIDOS                ║ ║                                                   ║\n");
	printf("╠═══════════════════════════════════════════════════╬═══════════════════════════════════════════════════╣ ║      Este sistema garante uma VISAO GERENCIAL     ║\n");
	printf("║                                        *CONSULTAR ║                          *CONSULTAR E **REGISTRAR ║ ║      ampla dos processos de clientes, estoque     ║\n");
	printf("║                                                   ║                                                   ║ ║      e vendas.                                    ║\n");
	printf("║     Listar CLIENTES ----------------------- 1     ║     Listar PEDIDOS ------------------------ 15    ║ ║                                                   ║\n");
	printf("║     Filtrar e ordenar CLIENTES ------------ 2     ║	  Buscar PEDIDO ------------------------- 16    ║ ║      Abaixo, verifique as indicações de risco     ║\n");
	printf("║     Buscar CLIENTE ------------------------ 3     ║	  Registrar PEDIDO ---------------------- 17    ║ ║      no uso das funcionalidades da tabela:        ║\n");
	printf("║                                                   ║                                                   ║ ║                                                   ║\n");
	printf("╠═══════════════════════════════════════════════════╬═══════════════════════════════════════════════════╣ ║                                                   ║\n");
	printf("║                                        ***DELETAR ║                                        ***DELETAR ║ ║             * Consultas que NAO ALTERAM           ║\n");
	printf("║                                                   ║                                                   ║ ║               o banco de dados                    ║\n");
	printf("║     Remover CLIENTE ----------------------- 4     ║     Deletar PEDIDO ------------------------ 18    ║ ║                                                   ║\n");
	printf("║     Apagar TODOS os dados de CLIENTES ----- 5     ║     Apagar TODOS os PEDIDOS --------------- 19    ║ ║            ** Acoes que ALTERAM                   ║\n");
	printf("║                                                   ║                                                   ║ ║               o banco de dados                    ║\n");
	printf("╠═══════════════════════════════════════════════════╬═══════════════════════════════════════════════════╣ ║                                                   ║\n");
	printf("║               DEPOSITO DE ESTOQUE                 ║               GERENCIAMENTO INTEGRADO             ║ ║           *** Alteracoes IRREVERSIVEIS            ║\n");
	printf("╠═══════════════════════════════════════════════════╬═══════════════════════════════════════════════════╣ ║               no banco de dados                   ║\n");
	printf("║                                        *CONSULTAR ║                                       **CADASTRAR ║ ║                                                   ║\n");
	printf("║                                                   ║                                                   ║ ║                                                   ║\n");
	printf("║     Listar ESTOQUE ------------------------ 6     ║     Cadastrar CLIENTES -------------------- 20    ║ ║                                                   ║\n");
	printf("║     Filtrar e ordenar ESTOQUE ------------- 7     ║     Cadastrar PRODUTOS -------------------- 21    ║ ║                                                   ║\n");
	printf("║     Listar CATEGORIA ---------------------- 8     ║     Cadastrar CATEGORIAS ------------------ 22    ║ ║                                                   ║\n");
	printf("║                                                   ║     Atualizar CADASTRO DE CLIENTES -------- 23    ║ ║                                                   ║\n");
	printf("║     Buscar no ESTOQUE --------------------- 9     ║     Atualizar ESTOQUE DE PRODUTOS --------- 24    ║ ║                                                   ║\n");
	printf("║                                                   ║                                                   ║ ║                                                   ║\n");
	printf("╠═══════════════════════════════════════════════════╬═══════════════════════════════════════════════════╣ ║                                                   ║\n");
	printf("║                                        ***DELETAR ║                                         *CALCULAR ║ ║                                                   ║\n");
	printf("║                                                   ║                                                   ║ ║                                                   ║\n");
	printf("║     Remover PRODUTO ---------------------- 10     ║     Calcular BALANCO de PEDIDOS ----------- 25    ║ ║                                                   ║\n");
	printf("║     Remover CATEGORIA -------------------- 11     ║     Calcular BALANCO de ESTOQUE ----------- 26    ║ ║                                                   ║\n");
	printf("║     Reordenar CODIGOS de PRODUTOS -------- 12     ║                                                   ║ ║                                                   ║\n");
	printf("║     Apagar TODAS as CATEGORIAS ----------- 13     ║                                                   ║ ║                                                   ║\n");
	printf("║     Apagar TODOS os itens do ESTOQUE ----- 14     ║     Encerrar SISTEMA  ---------------------- 0    ║ ║                                                   ║\n");
	printf("║                                                   ║                                                   ║ ║                                                   ║\n");
	printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════╝ ╚═══════════════════════════════════════════════════╝\n\n");
}

void ListaCategoria(Estoque  * pnt_deposito)
{
	FILE *pont_categoria;
	int y = 0;
	int c = 0;
	int i_coluna = 0;
	int i_linha = 0;
	
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
}

void ApagaDadosSistemaCategoria(Estoque  * pnt_deposito)
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
			printf("█   \033[31mATENÇÃO!\033[0m Todos as CATEGORIAS do sistema serão DELETADAS...      █\n");
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
				pont_arq = fopen("categoria.txt","w");
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

/*
void CalculaBalancoVarejo(Pedido * pnt_recibo)
{
	system("color 07");
	FILE *pont_pedido;
	FILE *pont_categoria;
	int acumulador_quantidade = 0;
	
	float acumulador_venda = 0.0;
	int64_t venda_geral = 0;
	int64_t venda_reais = 0;
	int64_t venda_centavos = 0;
	float total_venda_geral = 0.0;
	
	float acumulador_lucro = 0.0;
	int64_t lucro_geral = 0;
	int64_t lucro_reais = 0;
	int64_t lucro_centavos = 0;
	float total_lucro_geral = 0.0;
	
	int pedido_inicial = 0;
	int pedido_final = 0;
	int mes_inicial = 0;
	int mes_final = 0;
	int ano_inicial = 0;
	int ano_final = 0;
	
	//int codigo = 0;
	int y = 0;
	int c = 0;
	//int t = 0;
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
	
	y = LeArquivoPedido(pnt_recibo);

	do{
		MenuBalancoEstoque();
		//scanf("%d",&op);
		op = ObtemInteiroValidoVarejo(op);
		
		switch(op)
		{
			case 1:
				do{
					system("cls");
					//printf("\nCALCULO TOTAL DE VENDAS E LUCROS\n");
					//printf("------------------------\n\n");
					//printf("Informe o CODIGO do produto: ");
					//codigo = ObtemInteiroValidoVarejo(codigo);
					printf("\n");
					
					//total_preco_produto = 0.0;
					t = 0;
					pedido_inicial = 0;
					pedido_final = y - 1;
					
					for(int i = 0; i < y; i++)
					{	
						//if(pnt_deposito[i].codigo == codigo)
						//{
						
						if(i == pedido_inicial)
						{
							mes_inicial = pnt_recibo[i].data_hora_pedido.tm_mon;
							ano_inicial = pnt_recibo[i].data_hora_pedido.tm_year;
						}
						if(i == pedido_final)
						{
							mes_final = pnt_recibo[i].data_hora_pedido.tm_mon;
							ano_final = pnt_recibo[i].data_hora_pedido.tm_year;
						}
					
							total_venda_geral += pnt_recibo[i].preco_final_com_desconto;
							total_venda_geral *= 100;
							venda_geral = (int)total_venda_geral;
							preco_reais = venda_geral / 100;
							preco_centavos = llabs(venda_geral % 100);
							
							total_lucro_geral += pnt_recibo[i].lucro;
							total_lucro_geral *= 100;
							lucro_geral = (int)total_lucro_geral;
							lucro_reais = lucro_geral / 100;
							lucro_centavos = llabs(lucro_geral % 100);
					}
					
					printf("\n");
					printf("╔═════════════════════════════════════════════════════════════════════════════════════╗\n");
					printf("║                           **BALANÇO FINAL FINANCEIRO**                              ║\n");
					printf("╠═════════════════════════════════════════════════════════════════════════════════════╣\n");
					printf("║ PERÍODO INICIAL │  PERÍODO FINAL  │         VENDAS         │         LUCROS         ║\n");
					printf("╟─────────────────────────────────────────────────────────────────────────────────────╢\n");
					printf("╟─────────────────────────────────────────────────────────────────────────────────────╢\n");
					printf("║        %02d/%04d│        %02d/%04d│\x1b[36m%13lld.%02lld\x1b[0m│\x1b[36m%13lld.%02lld\x1b[0m║\n",
									 mes_inicial,
									 ano_inicial,
									 mes_final,
									 ano_final,
									 (long long)venda_reais,
									 (long long)venda_centavos,
									 (long long)lucro_reais,
									 (long long)lucro_centavos);
					printf("╟───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
					printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
					printf("CALCULO CONCLUIDO\n\n");
					//t = 1;
						//}	
					//}
					
					/*if(t == 0)
					{
						printf("\n");
						printf("███████████████████████████████████████\n\a");
						printf("█                                     █\n");
						printf("█        PRODUTO NAO ENCONTRADO!      █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n\n\n");
					}*/
					
					/*total_preco_produto = 0.0;
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
			/*case 2:
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
	
	
	//GERAL
	//qual a venda total da empresa?
	//qual o lucro total da empresa?
	//quantos pedidos?
	//qual a categoria mais rentavel?
	
	//ESPECIFICO
	//qual a venda da empresa...
		//no ano
		//no mes
		//no dia
	//qual o lucro da empresa...
		//no ano
		//no mes
		//no dia
	//quantos pedidos...
		//no ano
		//no mes
		//no dia
	//venda total dos pedidos do cliente...
		//no ano
		//no mes
		//no dia
	//lucro total dos pedidos do cliente...
		//no ano
		//no mes
		//no dia
}
*/
/*
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
*/
/*void ApagaDadosSistemaVarejo(Pedido  * pnt_recibo)
{
	FILE * pont_pedido;
	int op = -1;
	
	system("cls");
	
	printf("\n███████████████████████████████████████████████████████████████████████████\n\a");
	printf("█                                                                         █\n");
	printf("█  \033[31mATENÇÃO!\033[0m Todos os DADOS dos PEDIDOS do sistema serão DELETADOS...      █\n");
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
			printf("█  \033[31mATENÇÃO!\033[0m Todos os DADOS dos PEDIDOS do sistema serão DELETADOS...      █\n");
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
			if(pont_pedido != NULL)
			{
				pont_pedido = fopen("pedido.txt","w");
				fprintf(pont_pedido,"%s","");
				fclose(pont_pedido);
				printf("\n\nDADOS REMOVIDOS\n\n");
				printf("\nAperte qualquer tecla para voltar ao MENU INICIAL...");
				system("pause > nul");
				system("cls");
				
			}	
			else
			{
				printf("\n\nOs dados dos pedidos nao foram apagados...\n\n");
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
*/

/*
double arredonda(double v)
{
    return floor(v * 100.0 + 0.5) / 100.0;
}
*/