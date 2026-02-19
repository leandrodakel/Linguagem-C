void FiltroVarejo();
void OrdemVarejo();
void MenuBuscaPedido();
void MenuBalancoVarejo();
void LimpaBufferVarejo();
int ObtemInteiroValidoVarejo();
float ObtemFloatValidoVarejo();
void LimpaStringCliente(char *str);
void ConverteMaiusculaCliente(char *str);
int LeArquivoPedido(Pedido * pnt_recibo);
int LeArquivoEstoque(Estoque * pnt_deposito);
void ImprimeCabecalhoItensInicio();
void ImprimeCabecalhoItens();
void ImprimeVarejo(Pedido * pnt_recibo, int tam);
void RegistraVarejo(Cliente * pnt_cadastro, Estoque * pnt_deposito, Pedido * pnt_aux, Pedido * pnt_recibo);
void BuscaPedido(Pedido * pnt_recibo);
void ListaVarejo(Pedido * pnt_recibo);
void RemovePedido(Pedido * pnt_recibo);
void CalculaBalancoVarejo(Pedido * pnt_recibo, Estoque * pnt_deposito);
int ComparaPalavras(char *palavra1, char *palavra2);
void BubbleSortVarejo(Pedido * pnt_recibo, int opcao, int tamanho);
void FiltraOrdenaVarejo(Pedido  * pnt_recibo);
void ApagaDadosSistemaVarejo(Pedido  * pnt_recibo);
double arredonda(double v);

void MenuBuscaPedido()
{
	printf("\n");
	printf("╔═══════════════════════════════════════════════════╗\n");
	printf("║                    BUSCAR PEDIDO                  ║\n");
	printf("╠═══════════════════════════════════════════════════╣\n");
	printf("║                                                   ║\n");
	printf("║      Buscar por REGISTRO de Pedido ------- 1      ║\n");
	printf("║                                                   ║\n");
	printf("║      Buscar por ID de Cliente e DATA ----- 2      ║\n");
	printf("║      Buscar por NOME de Cliente e DATA --- 3      ║\n");
	printf("║                                                   ║\n");
	printf("║      Flitrar por ID de Cliente ----------- 4      ║\n");
	printf("║      Filtrar por NOME de Cliente --------- 5      ║\n");
	printf("║      Filtrar por DATA do Pedido ---------- 6      ║\n");
	printf("║                                                   ║\n");
	printf("║      Voltar ao MENU INICIAL -------------- 0      ║\n");
	printf("║                                                   ║\n");
	printf("╚═══════════════════════════════════════════════════╝\n\n");
}

void MenuBalancoVarejo()
{
	printf("\n");
	printf("╔════════════════════════════════════════════════════════╗\n");
	printf("║               CALCULAR BALANCO DO VAREJO               ║\n");
	printf("╠════════════════════════════════════════════════════════╣\n");
	printf("║                                                        ║\n");
	printf("║    Calcular BALANCO GERAL ----------------------- 1    ║\n");
	printf("║                                                        ║\n");
	printf("║    Calcular VENDA/LUCRO/QUANTIDADE (PRODUTO) ---- 2    ║\n");
	printf("║    Calcular VENDA/LUCRO (POR CATEGORIA) --------- 3    ║\n");
	printf("║    Calcular VENDA/LUCRO (POR CLIENTE) ----------- 4    ║\n");
	printf("║                                                        ║\n");
	printf("║    Calcular VENDA/LUCRO (POR DIA) --------------- 5    ║\n");
	printf("║    Calcular VENDA/LUCRO (POR MES) --------------- 6    ║\n");
	printf("║    Calcular VENDA/LUCRO (POR ANO) --------------- 7    ║\n");
	printf("║                                                        ║\n");
	printf("║    Voltar ao MENU INICIAL ----------------------- 0    ║\n");
	printf("║                                                        ║\n");
	printf("╚════════════════════════════════════════════════════════╝\n\n");
	
	//O BALANCO TERA:
	
	//BALANCO GERAL RESUMIDO
	  //QUAL O VALOR DE VENDA TOTAL
	  //QUAL O VALOR DE LUCRO TOTAL
	  //QUANTOS PEDIDOS REALIZADOS
	  
	  //BALANCO GERAL RESUMIDO
	  //QUAL O VALOR DE VENDA TOTAL
	  //QUAL O VALOR DE LUCRO TOTAL
	  //QUANTOS PRODUTOS VENDIDOS
	  //QUANTOS PEDIDOS REALIZADOS
	
	//BALANCO ESPECIFICO DETALHADO
		//QUAL O VALOR DE VENDA/LUCRO E QUANTIDADE (POR PRODUTO)
		//QUAL O VALOR DE VENDA/LUCRO (POR CATEGORIA)
		//QUAL O VALOR DE VENDA/LUCRO (POR CLIENTE)
		//QUAL O VALOR DE VENDA/LUCRO (POR DIA)
		//QUAL O VALOR DE VENDA/LUCRO (POR MES)
		//QUAL O VALOR DE VENDA/LUCRO (POR ANO)

		//QUANTOS PEDIDOS POR DIA/MES/ANO

}

void LimpaBufferVarejo()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // apenas descarta os caracteres restantes
    }
}

int ObtemInteiroValidoVarejo(int n)
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

float ObtemFloatValidoVarejo()
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

void LimpaStringVarejo(char *str)
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

void ConverteMaiusculaVarejo(char *str)
{
    while (*str)
	{
        *str = toupper((unsigned char)*str);
        str++;
    }
}

int LeArquivoPedido(Pedido * pnt_recibo)
{
	FILE *pont_pedido;
	int f = 0;
	pont_pedido = fopen("pedido.txt", "r");
	while(fscanf(pont_pedido,"%d\n%d\n%[^\n]\n%d\n%[^\n]\n%d\n%[^\n]\n%d\n%[^\n]\n%f\n%f\n%f\n%f\n%f\n%f\n%f\n%d\n%d\n%d\n%d\n%d\n%d\n%f\n%f\n%f\n",
									 &pnt_recibo[f].registro,
									 &pnt_recibo[f].id,
									 pnt_recibo[f].nome,
									 &pnt_recibo[f].codigo,
									 pnt_recibo[f].descricao,
									 &pnt_recibo[f].numero,
									 pnt_recibo[f].categoria,
									 &pnt_recibo[f].quantidade,
									 pnt_recibo[f].unidade,
									 &pnt_recibo[f].preco,
									 &pnt_recibo[f].desconto,
									 &pnt_recibo[f].preco_total,
									 &pnt_recibo[f].pagamento_cartao,
									 &pnt_recibo[f].pagamento_pix,
									 &pnt_recibo[f].pagamento_dinheiro,
									 &pnt_recibo[f].troco,
									 &pnt_recibo[f].data_hora_pedido.tm_mday,
									 &pnt_recibo[f].data_hora_pedido.tm_mon,
									 &pnt_recibo[f].data_hora_pedido.tm_year,
									 &pnt_recibo[f].data_hora_pedido.tm_hour,
									 &pnt_recibo[f].data_hora_pedido.tm_min,
									 &pnt_recibo[f].data_hora_pedido.tm_sec,
									 &pnt_recibo[f].preco_final_sem_desconto,
									 &pnt_recibo[f].preco_final_com_desconto,
									 &pnt_recibo[f].lucro) != EOF)
	{
		f++;
	}
	
	fclose(pont_pedido);
	return f;
}

/*int LeArquivoEstoque(Estoque * pnt_deposito)
{
	FILE *pont_estoque;
	int e = 0;
	pont_estoque = fopen("estoque.txt", "r");
	while(fscanf(pont_estoque,
					 "%d\n"
					 "%49[^\n]\n"
					 "%d\n"
					 "%49[^\n]\n"
					 "%d\n"
					 "%2[^\n]\n"
					 "%f\n"
					 "%f\n",
					 &pnt_deposito[e].codigo,
					 pnt_deposito[e].descricao,
					 &pnt_deposito[e].numero,
					 pnt_deposito[e].categoria,
					 &pnt_deposito[e].quantidade,
					 pnt_deposito[e].unidade,
					 &pnt_deposito[e].preco,
					 &pnt_deposito[e].custo) != EOF)
		{
			e++;
		}
	
	fclose(pont_estoque);
	return e;
}*/

void ImprimeCabecalhoItensInicio()
{
    printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║ ID  │              CLIENTE              │ COD │                  DESCRICAO                 │  QTDE │  UN  │  VALOR UNIT. │   VALOR TOTAL   ║\n");
    printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
}

void ImprimeCabecalhoItens()
{
	printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║ ID  │              CLIENTE              │ COD │                  DESCRICAO                 │  QTDE │  UN  │  VALOR UNIT. │   VALOR TOTAL   ║\n");
    printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
}

void ImprimeVarejo(Pedido * pnt_recibo, int tam)
{
	int i = 0;
    float soma_desconto_total_item = 0.0f;
	float soma_preco_final_sem_desconto = 0.0f;
    float soma_preco_total_item = 0.0f;
	
	ImprimeCabecalhoItensInicio();
    for (i = 0; i < tam; i++)
    {
		int fim_pedido;
        Pedido atual = pnt_recibo[i];
        Pedido anterior = (i > 0) ? pnt_recibo[i - 1] : atual;
        Pedido proximo = (i < tam - 1) ? pnt_recibo[i + 1] : atual;

        // Acumulações do pedido
        soma_preco_total_item += atual.preco_total;
        soma_desconto_total_item += atual.desconto * atual.quantidade;
		soma_preco_final_sem_desconto = soma_preco_total_item + soma_desconto_total_item;

        // --- Impressão dos itens ---
        if (i == 0)
        {
            //Primeiro pedido → imprime o NOME e o ID do cliente                                                                                                                                         ║\n");
			
			printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
            printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%35s\x1b[0m│%5d│%44s│%7d│%6s│%14.2f│%17.2f║\n",
                   atual.id, atual.nome, atual.codigo, atual.descricao,
                   atual.quantidade, atual.unidade,
                   atual.preco, atual.preco_total);
        }
		
		
		if (atual.registro > anterior.registro)
        {
            // Novo pedido → imprime o cabeçalho do item
			printf("\n");
			ImprimeCabecalhoItens();
			printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
            printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%35s\x1b[0m│%5d│%44s│%7d│%6s│%14.2f│%17.2f║\n",
                   atual.id, atual.nome, atual.codigo, atual.descricao,
                   atual.quantidade, atual.unidade,
                   atual.preco, atual.preco_total);
        }
        
		if(i > 0 && atual.registro == anterior.registro && anterior.registro != 0)
        {
            // Mesmo pedido → imprime sem cabeçalho
            printf("║     │                                   │%5d│%44s│%7d│%6s│%14.2f│%17.2f║\n",
                   atual.codigo, atual.descricao,
                   atual.quantidade, atual.unidade,
                   atual.preco, atual.preco_total);
        }

        // --- Detecta fim do pedido ---
        fim_pedido = (i == tam - 1) || (atual.registro < proximo.registro);

        if (fim_pedido)
        {
            printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
            printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");

            printf("║  REGISTRO  │    DATA    │   HORA   │  CARTAO TEF  │     PIX      │   DINHEIRO   │  VALOR TOTAL  │  DESCONTO  │   TROCO   │   VALOR FINAL   ║\n");
            printf("║────────────│────────────│──────────│──────────────│──────────────│──────────────│───────────────│────────────├───────────│─────────────────╢\n");

            printf("║      %06d│  %02d/%02d/%04d│  %02d:%02d:%02d│%14.2f│%14.2f│%14.2f│%15.2f│%12.2f│%11.2f│\x1b[36m%17.2f\x1b[0m║\n",
                   atual.registro,
                   atual.data_hora_pedido.tm_mday,
                   atual.data_hora_pedido.tm_mon,
                   atual.data_hora_pedido.tm_year,
                   atual.data_hora_pedido.tm_hour,
                   atual.data_hora_pedido.tm_min,
                   atual.data_hora_pedido.tm_sec,
                   atual.pagamento_cartao,
                   atual.pagamento_pix,
                   atual.pagamento_dinheiro,
				   atual.preco_final_sem_desconto,
                   soma_desconto_total_item,
                   atual.troco,
				   atual.preco_final_com_desconto);
			printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");	   
			printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
            // Zera acumuladores para o próximo pedido
            soma_desconto_total_item = 0.0f;
            soma_preco_total_item = 0.0f;

            // Pausa a cada 10 registros
            if (i < tam - 1 && atual.registro % 10 == 0)
            {
           		printf("\nAperte qualquer tecla para seguir a listagem de pedidos... \n\n");
                system("pause > nul");
            }
        }
    }

    printf("\nAperte qualquer tecla para continuar... \n");
    system("pause > nul");
	system("cls");
}

void RegistraVarejo(Cliente * pnt_cadastro, Estoque * pnt_deposito, Pedido * pnt_aux, Pedido * pnt_recibo)
{
	FILE *pont_cliente;
	FILE *pont_pedido;
	FILE *pont_estoque;
	FILE *pont_temp;
	
	DataHora data_hora_pedido;
	
	int id_cliente = 0;
	char nome_cliente[40];
	char descricao_produto[50];
	int numero_categoria;
	char nome_categoria[50];
	int cod_produto = 0;
	int quantidade_pedida = 0;
	float preco_unitario = 0.0;
	float preco_total_item = 0.0;
	char unidade_medida[3];
	char forma_pagamento[10];
	float valor_desconto = 0.0;
	int registro_pedido = 0;
	float cartao_pagamento = 0.0;
	float pix_pagamento = 0.0;
	float dinheiro_pagamento = 0.0;
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
	
	int cliente_encontrado = 0;
	int produto_encontrado = 0;
	int produto_esgotado = 0;
	int nova_busca = 0;
	int id = 0;
	int a = 0;
	int y = 0;
	int e = 0; 
	int p = 0;
	int r = 0;
	int w = 0;
	int f = 0;
	int q = 0;
	int j = 0;
	
	int op = 0;
	
	pont_cliente = fopen("cliente.txt","r");	
	
	while(fscanf(pont_cliente,"%d\n%[^\n]\n%[^\n]\n%[^\n]\n",
								&pnt_cadastro[y].id,
								pnt_cadastro[y].nome,
								pnt_cadastro[y].cpf,
								pnt_cadastro[y].telefone) != EOF)
		{
			if (pnt_cadastro[y].id == id_cliente)
			{
				strcpy(nome_cliente, pnt_cadastro[y].nome);
			}
			y++;
		}
		
		fclose(pont_cliente);
	
	do{
		
	
		system("cls");
		
		printf("\nREGISTRO DE PEDIDOS\n");
		printf("-------------------\n\n");
		
		
		printf("Informe o ID do cliente: ");
		id_cliente = ObtemInteiroValidoVarejo(id_cliente);
		
		if (pont_cliente == NULL)
		{
			strcpy(nome_cliente, "CLIENTE NAO IDENTIFICADO");
		}
			
		for(int i = 0; i < y; i++)
		{	
			if(pnt_cadastro[i].id == id_cliente)
			{
				printf("\n");
				printf("╔══════════════════════════════════════════════════════════════════╗\n");
				printf("║                        **DADOS DO CLIENTE**                      ║\n");
				printf("╠══════════════════════════════════════════════════════════════════╣\n");
				printf("║ COD │          NOME          │       CPF       │     TELEFONE    ║\n");
				printf("╟──────────────────────────────────────────────────────────────────╢\n");
				printf("║%5d│\x1b[32m%24s\x1b[0m│%17s│%17s║\n",
						 pnt_cadastro[i].id,
						 pnt_cadastro[i].nome,
						 pnt_cadastro[i].cpf,
						 pnt_cadastro[i].telefone);
				printf("╚══════════════════════════════════════════════════════════════════╝\n");
				
				printf("\nConfirmar cliente - 1\n");
				printf("Continuar busca - 2\n"); 
				printf("Cliente NAO IDENTIFICADO - 0\n\n");
				op = ObtemInteiroValidoVarejo(op);
			
				switch(op)
				{
					case 1:
						cliente_encontrado = 1;
						strcpy(nome_cliente, pnt_cadastro[i].nome);
					break;
					case 2:
						cliente_encontrado = 0;   // não encontrado AINDA, mas não é erro
						nova_busca = 1;
					continue;
					case 0:
						cliente_encontrado = 1;
						strcpy(nome_cliente, "CLIENTE NAO IDENTIFICADO");
						id_cliente = 0;						
					break;
					default:
						do{
							printf("\nDigite uma opcao valida!\n\n");
							printf("Confirmar Cliente - 1\n");
							printf("Continuar busca - 2\n"); 
							printf("Cliente NAO IDENTIFICADO - 0\n\n");
							op = ObtemInteiroValidoVarejo(op);
						}while(op < 0 || op > 2);
				}
			}
		}
		
		if(!cliente_encontrado && !nova_busca)
		{
			printf("\n██████████████████████████████\n\a");
			printf("█                            █\n");
			printf("█   CLIENTE NAO ENCONTRADO!  █\n");
			printf("█                            █\n");
			printf("██████████████████████████████\n\n");	
			
			printf("Confirmar CLIENTE NAO IDENTIFICADO - 1 | Continuar busca - 2 ");
			op = ObtemInteiroValidoVarejo(op);
	
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
						op = ObtemInteiroValidoVarejo(op);
					}while(op < 1 || op > 2);
			}
		}
	
	}while(!cliente_encontrado);
	
	op = 0;
    y = 0;
	
	fclose(pont_cliente);
	
	r = LeArquivoPedido(pnt_recibo);
	
	registro_pedido = pnt_recibo[r-1].registro + 1;
	
	do
	{
		w = 0;
		int busca_produto = 0;
		produto_encontrado = 0;
		cod_produto = 0;
		quantidade_pedida = 0;
		preco_unitario = 0.0;
		preco_total_item = 0.0;
		cartao_pagamento = 0.0;
		pix_pagamento = 0.0;
		dinheiro_pagamento = 0.0;
		troco_pago = 0.0;
		
		//Abrir arquivo de estoque para leitura e um temporário para escrita
		pont_temp = fopen("estoque.temp", "w");
		
		//Limpando variável para eventual nova leitura de estoque.txt
		e = 0;
		
		do{
			//produto_encontrado = -1;
			produto_encontrado = 0;
			produto_esgotado = 0;
			nova_busca = 0;
			q = 0;
			system("cls");
			
			printf("\nREGISTRO DE PEDIDOS\n");
			printf("-------------------\n\n");
			printf("Informe o CODIGO do produto: ");
			cod_produto = ObtemInteiroValidoVarejo(cod_produto);

			e = LeArquivoEstoque(pnt_deposito);
			
			for(int i = 0; i < e; i++)
			{	
				if(pnt_deposito[i].codigo == cod_produto)
				{
					system("cls");
					printf("\n");
					printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
					printf("║                                              **PRODUTO ENCONTRADO**                                            ║\n");
					printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
					printf("║ COD │                   DESCRICAO                 │ NUM │        CATEGORIA        │ QTDE │ UN │ VALOR UNITARIO ║\n");
					printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
					printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
					printf("║%5d│\033[32m%45s\033[0m│%5d│%25s│%6d│%4s│%16.2f║\n",
							 pnt_deposito[i].codigo,
							 pnt_deposito[i].descricao,
							 pnt_deposito[i].numero,
							 pnt_deposito[i].categoria,
							 pnt_deposito[i].quantidade,
							 pnt_deposito[i].unidade,
							 pnt_deposito[i].preco);
					printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
					printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
					
					printf("\nIncluir produto no pedido - 1 | Continuar busca - 2 ");
					op = ObtemInteiroValidoVarejo(op);
					switch(op)
					{
						case 1:
							if(pnt_deposito[i].quantidade >= quantidade_pedida)
							{
								produto_encontrado = 1;
								soma_custo += pnt_deposito[i].custo;
							}
							else
							{
								q = 1;
							}
						break;
						case 2:
							produto_encontrado = 0; // não encontrado AINDA, mas não é erro
							nova_busca = 1;
							q = 1;
						continue;
						default:
							do{
								printf("\nDigite uma opcao valida!\n\n");
								printf("\nIncluir produto no pedido - 1 | Continuar busca ");
								op = ObtemInteiroValidoVarejo(op);
							}while(op < 1 || op > 2);
					}

					if(pnt_deposito[i].quantidade == 0)
					{
						produto_esgotado = 1;
					}
				}	
			}
			
			if(!produto_encontrado && !nova_busca)
			{
				printf("\n████████████████████████████████\n\a");
				printf("█                              █\n");
				printf("█    PRODUTO NAO ENCONTRADO!   █\n");
				printf("█                              █\n");
				printf("████████████████████████████████\n\n");
						
				printf("Aperte qualquer tecla para continuar o pedido...\n\n");
				system("pause > nul");
				q = 1;
			}
			
			do{
				if(produto_esgotado == 1)
				{
					printf("\n██████████████████████████████████████████████\n\a");
					printf("█                                            █\n");
					printf("█        Produto ESGOTADO no estoque!        █\n");
					printf("█                                            █\n");
					printf("██████████████████████████████████████████████\n\n");
					produto_encontrado = -1;
					q = 1;
					printf("Aperte qualquer tecla para continuar o pedido...\n\n");
					system("pause > nul");
				}
				
				if(produto_encontrado == 1 && produto_esgotado == 0)
				{
				//Agregando quantidade ao pedido
					printf("\nInforme a quantidade do produto: ");
					quantidade_pedida = ObtemInteiroValidoVarejo(quantidade_pedida);
				
					for(int i = 0; i < e; i++)
					{
						if (pnt_deposito[i].codigo == cod_produto && produto_esgotado == 0)
						{
							if(pnt_deposito[i].quantidade < quantidade_pedida)
							{
								printf("\n██████████████████████████████████████████████\n\a");
								printf("█                                            █\n");
								printf("█    Estoque INSUFICIENTE para o produto!    █\n");
								printf("█                                            █\n");
								printf("██████████████████████████████████████████████\n\n");
								produto_encontrado = -1;
								q = 1;
								printf("Aperte qualquer tecla para continuar o pedido...\n\n");
								system("pause > nul");
								break;
							}
							
							else if(quantidade_pedida <= 0)
							{
								printf("\n██████████████████████████████████████████████\n\a");
								printf("█                                            █\n");
								printf("█       Digite uma QUANTIDADE válida!        █\n");
								printf("█                                            █\n");
								printf("██████████████████████████████████████████████\n\n");
								produto_encontrado = -1;
								q = 1;
								printf("Aperte qualquer tecla para continuar o pedido...\n\n");
								system("pause > nul");
								break;
							}
							
							else if (pnt_deposito[i].quantidade >= quantidade_pedida)
							{
								q = 2;
							}
						}
					}
				}
			}while(q < 1 || q > 2);
			
		}while(q != 2);
		
		
		//Procurar o produto e atualizar a quantidade no arquivo temporário
		for(int w = 0; w < e; w++)
		{
			if (pnt_deposito[w].codigo == cod_produto)
			{
				if (pnt_deposito[w].quantidade >= quantidade_pedida && pnt_deposito[w].quantidade > 0)
				{
					pnt_deposito[w].quantidade -= quantidade_pedida;
					
					printf("\nInforme a porcentagem de desconto\n");
					printf("\n5%% (Digite 5)");
					printf("\n10%% (Digite 10)");
					printf("\n15%% (Digite 15)");
					printf("\n20%% (Digite 20)");
					printf("\nSem desconto (Digite 0)\n");
					
					int valido = 0;

					do{
						scanf("%d", &op);
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
								printf("\nDigite um desconto valido!\n\n");
						}

					}while(!valido);
					
					//Calcula porcentagem corretamente
					double porcentagem = op / 100.0;

					//Calcula valores com double
					double preco        = pnt_deposito[w].preco;
					double desconto     = arredonda(preco * porcentagem);
					double preco_liq    = arredonda(preco - desconto);
					double total        = arredonda(preco_liq * quantidade_pedida);

					//Atribui no recibo
					pnt_recibo[a].codigo     = cod_produto;
					strcpy(pnt_recibo[a].descricao, pnt_deposito[w].descricao);
					pnt_recibo[a].numero     = pnt_deposito[w].numero;
					strcpy(pnt_recibo[a].categoria, pnt_deposito[w].categoria);
					pnt_recibo[a].quantidade = quantidade_pedida;
					strcpy(pnt_recibo[a].unidade, pnt_deposito[w].unidade);

					pnt_recibo[a].preco       = preco;
					pnt_recibo[a].desconto    = desconto;
					pnt_recibo[a].preco_total = total;
					
					//Validando forma de pagamento
					pnt_recibo[a].pagamento_cartao = 0.0f;
					pnt_recibo[a].pagamento_pix = 0.0f;
					pnt_recibo[a].pagamento_dinheiro = 0.0f;
					pnt_recibo[a].troco = 0.0f;
					
					//Zerando o preco final sem desconto e o lucro
					pnt_recibo[a].preco_final_sem_desconto = 0.0f;
					pnt_recibo[a].lucro = 0.0f;

					printf("\n");
				}
			}
			
			//Escrever no arquivo temporário (mesmo se não for o produto do pedido, ou com nova quantidade)
			fprintf(pont_temp,"%d\n%s\n%d\n%s\n%d\n%s\n%.2f\n%.2f\n",
								pnt_deposito[w].codigo,
								pnt_deposito[w].descricao,
								pnt_deposito[w].numero,
								pnt_deposito[w].categoria,
								pnt_deposito[w].quantidade,
								pnt_deposito[w].unidade,
								pnt_deposito[w].custo,
								pnt_deposito[w].preco);
		}
		
		fclose(pont_temp);
		
		//Substituir o arquivo de estoque original pelo temporário
		remove("estoque.txt");
		rename("estoque.temp", "estoque.txt");
			
		//Se o produto foi encontrado e tinha estoque, finalizar o pedido
		if (produto_encontrado && pnt_recibo[a].preco > 0.0f) 
		{
			//Limpando variavel para eventual nova contagem
			r = 0;
			
			time_t tempo_bruto; // Variável para armazenar o tempo em segundos
			struct tm *info_tempo; // Ponteiro para a estrutura que armazena data/hora detalhada

			//Obter o tempo bruto atual do sistema
			time(&tempo_bruto); // ou tempo_bruto = time(NULL);

			//Converter o tempo bruto para a hora local (localtime)
			info_tempo = localtime(&tempo_bruto);

			pnt_recibo[a].data_hora_pedido.tm_mday = info_tempo->tm_mday;
			pnt_recibo[a].data_hora_pedido.tm_mon = info_tempo->tm_mon + 1; // Meses são de 0 (janeiro) a 11 (dezembro)
			pnt_recibo[a].data_hora_pedido.tm_year = info_tempo->tm_year + 1900; // Anos são contados a partir de 1900
			pnt_recibo[a].data_hora_pedido.tm_hour = info_tempo->tm_hour;
			pnt_recibo[a].data_hora_pedido.tm_min = info_tempo->tm_min;
			pnt_recibo[a].data_hora_pedido.tm_sec = info_tempo->tm_sec;

			//Registrar o pedido no arquivo de pedidos
			pont_pedido = fopen("pedido.txt", "a");
			if (pont_pedido != NULL)
			{
				fprintf(pont_pedido,"%d\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%d\n%d\n%d\n%d\n%d\n%d\n%.2f\n%.2f\n%.2f\n",
									 registro_pedido,
									 id_cliente,
									 nome_cliente,
									 pnt_recibo[a].codigo,
									 pnt_recibo[a].descricao,
									 pnt_recibo[a].numero,
									 pnt_recibo[a].categoria,
									 pnt_recibo[a].quantidade,
									 pnt_recibo[a].unidade,
									 pnt_recibo[a].preco,
									 pnt_recibo[a].desconto,
									 pnt_recibo[a].preco_total,
									 pnt_recibo[a].pagamento_cartao,
									 pnt_recibo[a].pagamento_pix,
									 pnt_recibo[a].pagamento_dinheiro,
									 pnt_recibo[a].troco,
									 pnt_recibo[a].data_hora_pedido.tm_mday,
									 pnt_recibo[a].data_hora_pedido.tm_mon,
									 pnt_recibo[a].data_hora_pedido.tm_year,
									 pnt_recibo[a].data_hora_pedido.tm_hour,
									 pnt_recibo[a].data_hora_pedido.tm_min,
									 pnt_recibo[a].data_hora_pedido.tm_sec,
									 pnt_recibo[a].preco_final_sem_desconto,
									 pnt_recibo[a].preco_final_com_desconto,
									 pnt_recibo[a].lucro
									 );
									 
				fclose(pont_pedido);
				
				
				//Decremento de variavel de registro, mas manter os produtos do pedido com o mesmo registro
				r--;
			}
			else
			{
				printf("Erro ao registrar o pedido.\n");
			}
		}
		
		else
		{
			//Remover o arquivo temporário se o pedido falhou
			remove("estoque.temp");
			fclose(pont_estoque);
		}
		
		//Incrementando variavel de quantidade de itens do pedido
		a++;
		
		do
		{
			system("cls");
			printf("\nPedido registrado com sucesso.\n\n");
			printf("\nRegistrar outro produto - 1 | Encerrar pedido - 2\n");
			op = ObtemInteiroValidoVarejo(op);
		
			if(op < 1 || op > 2)
			{
				printf("Digite uma opcao valida!\n");
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
		soma_desconto_total_item += pnt_recibo[i].desconto * pnt_recibo[i].quantidade;
		
		//Transfomando em centavos, para evitar arredondamentos
		total_centavos += (int)round(pnt_recibo[i].preco_total * 100.0);
	}
	
	//Tranformando em reais o preco total com desconto
	soma_preco_total_item = total_centavos / 100.0f;
	
	//Calculando o preco total sem desconto para infornar no recibo
	soma_preco_final_sem_desconto = soma_preco_total_item + soma_desconto_total_item;
	
	//Calculando o lucro da total do pedido
	lucro_total = soma_preco_total_item - soma_custo;
	
	//Registrando a forma de pagamento e eventual troco no ultimo indice do pedido
	printf("\nVALOR A PAGAR: R$ \x1b[36m%.2f\x1b[0m\n\n",soma_preco_total_item);
	
	printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
	printf("║ PEDIDO REGISTRADO %04d Itens                                                                                                               ║\n", a);
	printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
	printf("║ ID  │              CLIENTE              │ COD │                  DESCRICAO                  │ QTDE │ UN │ VALOR UNITARIO │   VALOR TOTAL   ║\n");
	printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
	printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
	
	if(produto_encontrado = 1)
	{
		for(int i = 0; i < a; i++)
		{
			printf("║%5d│%35s│%5d│%45s│%6d│%4s│%16.2f│%17.2f║\n",
					 id_cliente,
					 nome_cliente,
					 pnt_recibo[i].codigo,
					 pnt_recibo[i].descricao,
					 pnt_recibo[i].quantidade,
					 pnt_recibo[i].unidade,
					 pnt_recibo[i].preco,
					 pnt_recibo[i].preco_total);
		}
	}
	printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
	printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
	printf("║  REGISTRO  │    DATA    │   HORA   │  CARTAO TEF  │     PIX      │   DINHEIRO   │  VALOR TOTAL  │  DESCONTO  │   TROCO   │   VALOR FINAL   ║\n");
    printf("║────────────│────────────│──────────│──────────────│──────────────│──────────────│───────────────│────────────├───────────│─────────────────╢\n");
	printf("║      %06d│  %02d/%02d/%04d│  %02d:%02d:%02d│%14.2f│%14.2f│%14.2f│%15.2f│%12.2f│%11.2f│\x1b[36m%17.2f\x1b[0m║\n",
																								
				registro_pedido,
				pnt_recibo[a-1].data_hora_pedido.tm_mday,
				pnt_recibo[a-1].data_hora_pedido.tm_mon,
				pnt_recibo[a-1].data_hora_pedido.tm_year,
				pnt_recibo[a-1].data_hora_pedido.tm_hour,
				pnt_recibo[a-1].data_hora_pedido.tm_min,
				pnt_recibo[a-1].data_hora_pedido.tm_sec,
				pnt_recibo[a-1].pagamento_cartao,
				pnt_recibo[a-1].pagamento_pix,
				pnt_recibo[a-1].pagamento_dinheiro,
				soma_preco_final_sem_desconto,
				soma_desconto_total_item,
				pnt_recibo[a-1].troco,
				soma_preco_total_item);
	printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
	
	do{
		printf("\nFORMA DE PAGAMENTO\n");
		printf("------------------\n");
		printf("\nCARTAO TEF - 1");
		printf("\nPIX - 2");
		printf("\nDINHEIRO - 3");
		printf("\n\nVALIDAR - 0\n\n");
		op = ObtemInteiroValidoVarejo(op);
		
		switch(op)
		{
			case 1:
				printf("Informe o valor (CARTAO TEF): ");
				scanf("%lld.%lld", &real, &centavos);
				cartao_cent = real * 100 + centavos;
				cartao_pagamento = cartao_cent / 100.0;
				pagamento_validado = 1;
			break;
			case 2:
				printf("Informe o valor (PIX): ");
				scanf("%lld.%lld", &real, &centavos);
				pix_cent = real * 100 + centavos;
				pix_pagamento = pix_cent / 100.0;
				pagamento_validado = 1;
			break;
			case 3:
				printf("Informe o valor (DINHEIRO): ");
				scanf("%lld.%lld", &real, &centavos);
				dinheiro_cent = real * 100 + centavos;
				dinheiro_pagamento = dinheiro_cent / 100.0;
				pagamento_validado = 1;
			break;
			case 0:
			
				//Verificando se o valor pago é correspondente ao valor da compra
				soma_pagamento_cent = cartao_cent + pix_cent + dinheiro_cent;
				
				if(pagamento_validado == 0)
				{
					printf("\nValide primeiro a compra escolhendo uma opcao de pagamento!\n\n");
				}
				else if(pagamento_validado == 1)
				{
					if(soma_pagamento_cent >= total_centavos)
					{
						pagamento_validado = 2;
						
						pnt_recibo[a-1].pagamento_cartao = cartao_pagamento;
						pnt_recibo[a-1].pagamento_pix = pix_pagamento;
						pnt_recibo[a-1].pagamento_dinheiro = dinheiro_pagamento;
						pnt_recibo[a-1].preco_final_com_desconto = soma_preco_total_item;
						total_pago = soma_pagamento_cent / 100.0f;
						pnt_recibo[a-1].troco = total_pago - soma_preco_total_item;
						troco_pago = pnt_recibo[a-1].troco;
						pnt_recibo[a-1].preco_final_sem_desconto = soma_preco_final_sem_desconto;
						
						//Registrando o lucro total do pedido
						pnt_recibo[a-1].lucro = lucro_total;
						
						system("cls");
						
						printf("\nPAGAMENTO VALIDADO\n");
						printf("------------------\n");
						printf("\nCARTAO TEF = %.2f",pnt_recibo[a-1].pagamento_cartao);
						printf("\nPIX = %.2f",pnt_recibo[a-1].pagamento_pix);
						printf("\nDINHEIRO = %.2f",pnt_recibo[a-1].pagamento_dinheiro);
						printf("\n\nTROCO = %.2f\n\n",pnt_recibo[a-1].troco);
					}
					else
					{
						printf("\nValor insuficiente! Informe novo valor\n\n");
					}
				}
			break;
			default:
				do{	
					if(op < 0 || op > 3)
					{
						printf("\nDigite uma opcao valida!\n\n");
						op = ObtemInteiroValidoVarejo(op);
					}
				}while(op < 0 || op > 3);
		}
	}while(pagamento_validado != 2);	
	
	
	printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
	printf("║ PEDIDO REGISTRADO %04d Itens                                                                                                               ║\n", a);
	printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
	printf("║ ID  │              CLIENTE              │ COD │                  DESCRICAO                  │ QTDE │ UN │ VALOR UNITARIO │   VALOR TOTAL   ║\n");
	printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
	printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
	if(produto_encontrado = 1)
	{
		for(int i = 0; i < a; i++)
		{
			printf("║%5d│%35s│%5d│%45s│%6d│%4s│%16.2f│%17.2f║\n",
					 id_cliente,
					 nome_cliente,
					 pnt_recibo[i].codigo,
					 pnt_recibo[i].descricao,
					 pnt_recibo[i].quantidade,
					 pnt_recibo[i].unidade,
					 pnt_recibo[i].preco,
					 pnt_recibo[i].preco_total);
		}
	}
	printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
	printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
	printf("║  REGISTRO  │    DATA    │   HORA   │  CARTAO TEF  │     PIX      │   DINHEIRO   │  VALOR TOTAL  │  DESCONTO  │   TROCO   │   VALOR FINAL   ║\n");
    printf("║────────────│────────────│──────────│──────────────│──────────────│──────────────│───────────────│────────────├───────────│─────────────────╢\n");
	printf("║      %06d│  %02d/%02d/%04d│  %02d:%02d:%02d│%14.2f│%14.2f│%14.2f│%15.2f│%12.2f│%11.2f│\x1b[36m%17.2f\x1b[0m║\n",
																								
				registro_pedido,
				pnt_recibo[a-1].data_hora_pedido.tm_mday,
				pnt_recibo[a-1].data_hora_pedido.tm_mon,
				pnt_recibo[a-1].data_hora_pedido.tm_year,
				pnt_recibo[a-1].data_hora_pedido.tm_hour,
				pnt_recibo[a-1].data_hora_pedido.tm_min,
				pnt_recibo[a-1].data_hora_pedido.tm_sec,
				pnt_recibo[a-1].pagamento_cartao,
				pnt_recibo[a-1].pagamento_pix,
				pnt_recibo[a-1].pagamento_dinheiro,
				soma_preco_final_sem_desconto,
				soma_desconto_total_item,
				pnt_recibo[a-1].troco,
				pnt_recibo[a-1].preco_final_com_desconto);
	printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
	
	f = LeArquivoPedido(pnt_recibo);
	
	pnt_recibo[f-1].pagamento_cartao = cartao_pagamento;
	pnt_recibo[f-1].pagamento_pix = pix_pagamento;
	pnt_recibo[f-1].pagamento_dinheiro = dinheiro_pagamento; 
	pnt_recibo[f-1].troco = troco_pago;
	pnt_recibo[f-1].preco_final_sem_desconto = soma_preco_final_sem_desconto;
	pnt_recibo[f-1].preco_final_com_desconto = soma_preco_total_item;	
	
	//Registrando o lucro total do pedido
	pnt_recibo[f-1].lucro = lucro_total;
	
	pont_pedido = fopen("pedido.txt","w");	
	for(int i = 0; i < f; i++)
	{
		fprintf(pont_pedido,"%d\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%d\n%d\n%d\n%d\n%d\n%d\n%.2f\n%.2f\n%.2f\n",
									 pnt_recibo[i].registro,
									 pnt_recibo[i].id,
									 pnt_recibo[i].nome,
									 pnt_recibo[i].codigo,
									 pnt_recibo[i].descricao,
									 pnt_recibo[i].numero,
									 pnt_recibo[i].categoria,
									 pnt_recibo[i].quantidade,
									 pnt_recibo[i].unidade,
									 pnt_recibo[i].preco,
									 pnt_recibo[i].desconto,
									 pnt_recibo[i].preco_total,
									 pnt_recibo[i].pagamento_cartao,
									 pnt_recibo[i].pagamento_pix,
									 pnt_recibo[i].pagamento_dinheiro,
									 pnt_recibo[i].troco,
									 pnt_recibo[i].data_hora_pedido.tm_mday,
									 pnt_recibo[i].data_hora_pedido.tm_mon,
									 pnt_recibo[i].data_hora_pedido.tm_year,
									 pnt_recibo[i].data_hora_pedido.tm_hour,
									 pnt_recibo[i].data_hora_pedido.tm_min,
									 pnt_recibo[i].data_hora_pedido.tm_sec,
									 pnt_recibo[i].preco_final_sem_desconto,
									 pnt_recibo[i].preco_final_com_desconto,
									 pnt_recibo[i].lucro);
	}
	
	fclose(pont_pedido);
	
	printf("\nAperte qualquer tecla para voltar ao MENU INICIAL... ");
	system("pause > nul");
	system("cls");
}
	
void ListaVarejo(Pedido * pnt_recibo)
{
	FILE *pont_pedido;
	int f = 0;
	
	f = LeArquivoPedido(pnt_recibo);
	
	system("cls");
	
	if(f > 0)
	{
		printf("\n");
		printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
		printf("║                                                            **LISTA DE PEDIDOS**                                                            ║\n");
		ImprimeVarejo(pnt_recibo, f);
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

void BuscaPedido(Pedido * pnt_recibo)
{
	FILE *pont_pedido;
	int menu_busca = 0;
	int y = 0;
	int t = 0;
	int op = 0;
	int registro_pedido = 0;
	int id_cliente = 0;
	int dia_pedido = 0;
	int mes_pedido = 0;
	int ano_pedido = 0;
	char nome_cliente[40];
	int pedidos_exibidos = 0;
	float soma_preco_total_item = 0.0;
    float soma_desconto_total_item = 0.0;
	float soma_preco_final_sem_desconto = 0.0f;
	int fim_pedido;
	int primeiro_item_cliente = 1;
	
	y = LeArquivoPedido(pnt_recibo);
	
	do{
		system("cls");
		MenuBuscaPedido();
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				do{
					system("cls");
					printf("\nBUSCA DE PEDIDO POR REGISTRO\n");
					printf("----------------------------\n\n");
					printf("Informe o REGISTRO do PEDIDO: ");
					registro_pedido = ObtemInteiroValidoVarejo(registro_pedido);
					
					primeiro_item_cliente = 1;
					t = 0;
					
					for(int i = 0; i < y; i++)
					{	
						if(pnt_recibo[i].registro == registro_pedido)
						{
							Pedido atual = pnt_recibo[i];
							Pedido anterior = (i > 0) ? pnt_recibo[i - 1] : atual;
							Pedido proximo = (i < y - 1) ? pnt_recibo[i + 1] : atual;

							// Acumulações do pedido
							soma_preco_total_item += atual.preco_total;
							soma_desconto_total_item += atual.desconto * atual.quantidade;
							soma_preco_final_sem_desconto = soma_preco_total_item + soma_desconto_total_item;
							
							// --- Impressão dos itens ---
							if (primeiro_item_cliente || atual.registro > anterior.registro)
							{
								// Novo pedido → imprime o cabeçalho do item
								printf("\n");
								ImprimeCabecalhoItens();
								printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%35s\x1b[0m│%5d│%44s│%7d│%6s│%14.2f│%17.2f║\n",
									   atual.id, atual.nome, atual.codigo, atual.descricao,
									   atual.quantidade, atual.unidade,
									   atual.preco, atual.preco_total);
								primeiro_item_cliente = 0;
							}
							
							else
							{
								// Mesmo pedido → imprime sem cabeçalho
								printf("║     │                                   │%5d│%44s│%7d│%6s│%14.2f│%17.2f║\n",
									   atual.codigo, atual.descricao,
									   atual.quantidade, atual.unidade,
									   atual.preco, atual.preco_total);
							}

							// --- Detecta fim do pedido ---
							fim_pedido = (i == y - 1) || (atual.registro < proximo.registro);

							if (fim_pedido)
							{
								printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");

								printf("║  REGISTRO  │    DATA    │   HORA   │  CARTAO TEF  │     PIX      │   DINHEIRO   │  VALOR TOTAL  │  DESCONTO  │   TROCO   │   VALOR FINAL   ║\n");
								printf("║────────────│────────────│──────────│──────────────│──────────────│──────────────│───────────────│────────────├───────────│─────────────────╢\n");

								printf("║      %06d│  %02d/%02d/%04d│  %02d:%02d:%02d│%14.2f│%14.2f│%14.2f│%15.2f│%12.2f│%11.2f│\x1b[36m%17.2f\x1b[0m║\n",
									   atual.registro,
									   atual.data_hora_pedido.tm_mday,
									   atual.data_hora_pedido.tm_mon,
									   atual.data_hora_pedido.tm_year,
									   atual.data_hora_pedido.tm_hour,
									   atual.data_hora_pedido.tm_min,
									   atual.data_hora_pedido.tm_sec,
									   atual.pagamento_cartao,
									   atual.pagamento_pix,
									   atual.pagamento_dinheiro,
									   atual.preco_final_sem_desconto,
									   soma_desconto_total_item,
									   atual.troco,
									   atual.preco_final_com_desconto);
								printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");	   
								printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
								// Zera acumuladores para o próximo pedido
								soma_desconto_total_item = 0.0f;
								soma_preco_total_item = 0.0f;
								soma_preco_final_sem_desconto = 0.0f;
						
						// Pausa a cada 10 registros
								if (i < y - 1 && atual.registro % 10 == 0)
								{
									printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
									printf("\nAperte qualquer tecla para seguir a listagem de pedidos... \n\n");
									system("pause > nul");
									ImprimeCabecalhoItens();
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
						printf("█        REGISTRO NAO ENCONTRADO!     █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n");	
					}
					printf("\nContinuar busca - 1 | Voltar ao menu - 2 ");
					menu_busca = ObtemInteiroValidoVarejo(menu_busca);
					do{
						if(menu_busca < 1 || menu_busca > 2)
						{
							printf("\nOpcao invalida!\n");
							printf("\nContinuar busca - 1 | Voltar ao menu - 2 ");
							menu_busca = ObtemInteiroValidoVarejo(menu_busca);
						}
					}while(menu_busca < 1 || menu_busca > 2);
					printf("\n");
					t = 0;
				}while(menu_busca != 2);
			break;
			case 2:
				do{
					system("cls");
					printf("\nBUSCA DE PEDIDO POR ID E DATA\n");
					printf("-----------------------------\n\n");
					printf("Informe o ID do CLIENTE: ");
					id_cliente = ObtemInteiroValidoVarejo(id_cliente);
					printf("\nInforme a DATA do PEDIDO\n");
					printf("DIA: ");
					dia_pedido = ObtemInteiroValidoVarejo(dia_pedido);
					printf("MES: ");
					mes_pedido = ObtemInteiroValidoVarejo(mes_pedido);
					printf("ANO: ");
					ano_pedido = ObtemInteiroValidoVarejo(ano_pedido);
					printf("\n");
					
					primeiro_item_cliente = 1;
					t = 0;
					
					for(int i = 0; i < y; i++)
					{	
						if(pnt_recibo[i].id == id_cliente
						&& pnt_recibo[i].data_hora_pedido.tm_mday == dia_pedido
						&& pnt_recibo[i].data_hora_pedido.tm_mon == mes_pedido
						&& pnt_recibo[i].data_hora_pedido.tm_year == ano_pedido)
						{
							//int fim_pedido;
							Pedido atual = pnt_recibo[i];
							Pedido anterior = (i > 0) ? pnt_recibo[i - 1] : atual;
							Pedido proximo = (i < y - 1) ? pnt_recibo[i + 1] : atual;

							// Acumulações do pedido
							soma_preco_total_item += atual.preco_total;
							soma_desconto_total_item += atual.desconto * atual.quantidade;
							soma_preco_final_sem_desconto = soma_preco_total_item + soma_desconto_total_item;

							// --- Impressão dos itens ---
							if (primeiro_item_cliente || atual.registro > anterior.registro)
							{
								// Novo pedido → imprime o cabeçalho do item
								printf("\n");
								ImprimeCabecalhoItens();
								printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%35s\x1b[0m│%5d│%44s│%7d│%6s│%14.2f│%17.2f║\n",
									   atual.id, atual.nome, atual.codigo, atual.descricao,
									   atual.quantidade, atual.unidade,
									   atual.preco, atual.preco_total);
								primeiro_item_cliente = 0;
							}
							else
							{
								// Mesmo pedido → imprime sem cabeçalho
								printf("║     │                                   │%5d│%44s│%7d│%6s│%14.2f│%17.2f║\n",
									   atual.codigo, atual.descricao,
									   atual.quantidade, atual.unidade,
									   atual.preco, atual.preco_total);
							}

							// --- Detecta fim do pedido ---
							fim_pedido = (i == y - 1) || (atual.registro < proximo.registro);

							if (fim_pedido)
							{
								printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");

								printf("║  REGISTRO  │    DATA    │   HORA   │  CARTAO TEF  │     PIX      │   DINHEIRO   │  VALOR TOTAL  │  DESCONTO  │   TROCO   │   VALOR FINAL   ║\n");
								printf("║────────────│────────────│──────────│──────────────│──────────────│──────────────│───────────────│────────────├───────────│─────────────────╢\n");

								printf("║      %06d│  %02d/%02d/%04d│  %02d:%02d:%02d│%14.2f│%14.2f│%14.2f│%15.2f│%12.2f│%11.2f│\x1b[36m%17.2f\x1b[0m║\n",
									   atual.registro,
									   atual.data_hora_pedido.tm_mday,
									   atual.data_hora_pedido.tm_mon,
									   atual.data_hora_pedido.tm_year,
									   atual.data_hora_pedido.tm_hour,
									   atual.data_hora_pedido.tm_min,
									   atual.data_hora_pedido.tm_sec,
									   atual.pagamento_cartao,
									   atual.pagamento_pix,
									   atual.pagamento_dinheiro,
									   atual.preco_final_sem_desconto,
									   soma_desconto_total_item,
									   atual.troco,
									   atual.preco_final_com_desconto);
								printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");	   
								printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
								// Zera acumuladores para o próximo pedido
								soma_desconto_total_item = 0.0f;
								soma_preco_total_item = 0.0f;

								// Pausa a cada 10 registros
								if (i < y - 1 && atual.registro % 10 == 0)
								{
									printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
									printf("\nAperte qualquer tecla para seguir a listagem de pedidos... \n\n");
									system("pause > nul");
									ImprimeCabecalhoItens();
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
						printf("█        REGISTRO NAO ENCONTRADO!     █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n");	
					}
					printf("\nContinuar busca - 1 | Voltar ao menu - 2 ");
					menu_busca = ObtemInteiroValidoVarejo(menu_busca);
					do{
						if(menu_busca < 1 || menu_busca > 2)
						{
							printf("\nOpcao invalida!\n");
							printf("\nContinuar busca - 1 | Voltar ao menu - 2 ");
							menu_busca = ObtemInteiroValidoVarejo(menu_busca);
						}
					}while(menu_busca < 1 || menu_busca > 2);
					printf("\n");
					t = 0;
				}while(menu_busca != 2);
			break;
			case 3:
				do{
					system("cls");
					printf("\nBUSCA DE PEDIDO POR NOME DE CLIENTE E DATA\n");
					printf("------------------------------------------\n\n");
					printf("Informe o NOME do CLIENTE: ");
					scanf(" %[^\n]",nome_cliente);
					LimpaStringVarejo(nome_cliente);
					ConverteMaiusculaVarejo(nome_cliente);
					printf("\nInforme a DATA do PEDIDO\n");
					printf("DIA: ");
					dia_pedido = ObtemInteiroValidoVarejo(dia_pedido);
					printf("MES: ");
					mes_pedido = ObtemInteiroValidoVarejo(mes_pedido);
					printf("ANO: ");
					ano_pedido = ObtemInteiroValidoVarejo(ano_pedido);
					printf("\n");
					
					primeiro_item_cliente = 1;
					t = 0;
					
					for(int i = 0; i < y; i++)
					{	
						if(strstr(pnt_recibo[i].nome, nome_cliente) != NULL 
						&& pnt_recibo[i].data_hora_pedido.tm_mday == dia_pedido
						&& pnt_recibo[i].data_hora_pedido.tm_mon == mes_pedido
						&& pnt_recibo[i].data_hora_pedido.tm_year == ano_pedido)
						{
							
							//int fim_pedido;
							Pedido atual = pnt_recibo[i];
							Pedido anterior = (i > 0) ? pnt_recibo[i - 1] : atual;
							Pedido proximo = (i < y - 1) ? pnt_recibo[i + 1] : atual;

							// Acumulações do pedido
							soma_preco_total_item += atual.preco_total;
							soma_desconto_total_item += atual.desconto * atual.quantidade;
							soma_preco_final_sem_desconto = soma_preco_total_item + soma_desconto_total_item;

							// --- Impressão dos itens ---
							if (primeiro_item_cliente || atual.registro > anterior.registro)
							{
								// Novo pedido → imprime o cabeçalho do item
								printf("\n");
								ImprimeCabecalhoItens();
								printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%35s\x1b[0m│%5d│%44s│%7d│%6s│%14.2f│%17.2f║\n",
									   atual.id, atual.nome, atual.codigo, atual.descricao,
									   atual.quantidade, atual.unidade,
									   atual.preco, atual.preco_total);
								primeiro_item_cliente = 0;
							}
							else
							{
								// Mesmo pedido → imprime sem cabeçalho
								printf("║     │                                   │%5d│%44s│%7d│%6s│%14.2f│%17.2f║\n",
									   atual.codigo, atual.descricao,
									   atual.quantidade, atual.unidade,
									   atual.preco, atual.preco_total);
							}

							// --- Detecta fim do pedido ---
							fim_pedido = (i == y - 1) || (atual.registro < proximo.registro);

							if (fim_pedido)
							{
								printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");

								printf("║  REGISTRO  │    DATA    │   HORA   │  CARTAO TEF  │     PIX      │   DINHEIRO   │  VALOR TOTAL  │  DESCONTO  │   TROCO   │   VALOR FINAL   ║\n");
								printf("║────────────│────────────│──────────│──────────────│──────────────│──────────────│───────────────│────────────├───────────│─────────────────╢\n");

								printf("║      %06d│  %02d/%02d/%04d│  %02d:%02d:%02d│%14.2f│%14.2f│%14.2f│%15.2f│%12.2f│%11.2f│\x1b[36m%17.2f\x1b[0m║\n",
									   atual.registro,
									   atual.data_hora_pedido.tm_mday,
									   atual.data_hora_pedido.tm_mon,
									   atual.data_hora_pedido.tm_year,
									   atual.data_hora_pedido.tm_hour,
									   atual.data_hora_pedido.tm_min,
									   atual.data_hora_pedido.tm_sec,
									   atual.pagamento_cartao,
									   atual.pagamento_pix,
									   atual.pagamento_dinheiro,
									   atual.preco_final_sem_desconto,
									   soma_desconto_total_item,
									   atual.troco,
									   atual.preco_final_com_desconto);
								printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");	   
								printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
								// Zera acumuladores para o próximo pedido
								soma_desconto_total_item = 0.0f;
								soma_preco_total_item = 0.0f;

								// Pausa a cada 10 registros
								if (i < y - 1 && atual.registro % 10 == 0)
								{
									printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
									printf("\nAperte qualquer tecla para seguir a listagem de pedidos... \n\n");
									system("pause > nul");
									ImprimeCabecalhoItens();
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
						printf("█        REGISTRO NAO ENCONTRADO!     █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n");	
					}
					printf("\nContinuar busca - 1 | Voltar ao menu - 2 ");
					menu_busca = ObtemInteiroValidoVarejo(menu_busca);
					do{
						if(menu_busca < 1 || menu_busca > 2)
						{
							printf("\nOpcao invalida!\n");
							printf("\nContinuar busca - 1 | Voltar ao menu - 2 ");
							menu_busca = ObtemInteiroValidoVarejo(menu_busca);
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
					printf("\nBUSCA DE PEDIDO POR ID DE CLIENTE\n");
					printf("---------------------------------\n\n");
					printf("Informe o ID do CLIENTE: ");
					id_cliente = ObtemInteiroValidoVarejo(id_cliente);
					
					primeiro_item_cliente = 1;
					t = 0;
					
					for(int i = 0; i < y; i++)
					{	
						if(pnt_recibo[i].id == id_cliente)
						{
							//int fim_pedido;
							Pedido atual = pnt_recibo[i];
							Pedido anterior = (i > 0) ? pnt_recibo[i - 1] : atual;
							Pedido proximo = (i < y - 1) ? pnt_recibo[i + 1] : atual;

							// Acumulações do pedido
							soma_preco_total_item += atual.preco_total;
							soma_desconto_total_item += atual.desconto * atual.quantidade;
							soma_preco_final_sem_desconto = soma_preco_total_item + soma_desconto_total_item;
							
							// --- Impressão dos itens ---
							
							if (primeiro_item_cliente || atual.registro > anterior.registro)
							{
								// Novo pedido → imprime o cabeçalho do item
								printf("\n");
								ImprimeCabecalhoItens();
								printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%35s\x1b[0m│%5d│%44s│%7d│%6s│%14.2f│%17.2f║\n",
									   atual.id, atual.nome, atual.codigo, atual.descricao,
									   atual.quantidade, atual.unidade,
									   atual.preco, atual.preco_total);
								primeiro_item_cliente = 0;
							}
							else
							{
								// Mesmo pedido → imprime sem cabeçalho
								printf("║     │                                   │%5d│%44s│%7d│%6s│%14.2f│%17.2f║\n",
									   atual.codigo, atual.descricao,
									   atual.quantidade, atual.unidade,
									   atual.preco, atual.preco_total);
							}

							// --- Detecta fim do pedido ---
							fim_pedido = (i == y - 1) || (atual.registro < proximo.registro);
							
							
							
							if (fim_pedido)
							{
								printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");

								printf("║  REGISTRO  │    DATA    │   HORA   │  CARTAO TEF  │     PIX      │   DINHEIRO   │  VALOR TOTAL  │  DESCONTO  │   TROCO   │   VALOR FINAL   ║\n");
								printf("║────────────│────────────│──────────│──────────────│──────────────│──────────────│───────────────│────────────├───────────│─────────────────╢\n");

								printf("║      %06d│  %02d/%02d/%04d│  %02d:%02d:%02d│%14.2f│%14.2f│%14.2f│%15.2f│%12.2f│%11.2f│\x1b[36m%17.2f\x1b[0m║\n",
									   atual.registro,
									   atual.data_hora_pedido.tm_mday,
									   atual.data_hora_pedido.tm_mon,
									   atual.data_hora_pedido.tm_year,
									   atual.data_hora_pedido.tm_hour,
									   atual.data_hora_pedido.tm_min,
									   atual.data_hora_pedido.tm_sec,
									   atual.pagamento_cartao,
									   atual.pagamento_pix,
									   atual.pagamento_dinheiro,
									   atual.preco_final_sem_desconto,
									   soma_desconto_total_item,
									   atual.troco,
									   atual.preco_final_com_desconto);
								printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");	   
								printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
								// Zera acumuladores para o próximo pedido
								soma_desconto_total_item = 0.0f;
								soma_preco_total_item = 0.0f;

								// Pausa a cada 10 registros
								if (i < y - 1 && atual.registro % 10 == 0)
								{
									printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
									printf("\nAperte qualquer tecla para seguir a listagem de pedidos... \n\n");
									system("pause > nul");
									ImprimeCabecalhoItens();
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
						printf("█        REGISTRO NAO ENCONTRADO!     █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n");	
					}
					printf("\nContinuar busca - 1 | Voltar ao menu - 2 ");
					menu_busca = ObtemInteiroValidoVarejo(menu_busca);
					do{
						if(menu_busca < 1 || menu_busca > 2)
						{
							printf("\nOpcao invalida!\n");
							printf("\nContinuar busca - 1 | Voltar ao menu - 2 ");
							menu_busca = ObtemInteiroValidoVarejo(menu_busca);
						}
					}while(menu_busca < 1 || menu_busca > 2);
					printf("\n");
					t = 0;
				}while(menu_busca != 2);
			break;
			case 5:
				do{
					system("cls");
					printf("\nBUSCA DE PEDIDO POR NOME DE CLIENTE\n");
					printf("-----------------------------------\n\n");
					printf("Informe o NOME do CLIENTE: ");
					scanf(" %[^\n]",nome_cliente);
					
					LimpaStringVarejo(nome_cliente);
					ConverteMaiusculaVarejo(nome_cliente);
					
					primeiro_item_cliente = 1;
					t = 0;
					
					for(int i = 0; i < y; i++)
					{	
						if(strstr(pnt_recibo[i].nome, nome_cliente) != NULL)
						{
							//int fim_pedido;
							Pedido atual = pnt_recibo[i];
							Pedido anterior = (i > 0) ? pnt_recibo[i - 1] : atual;
							Pedido proximo = (i < y - 1) ? pnt_recibo[i + 1] : atual;

							// Acumulações do pedido
							soma_preco_total_item += atual.preco_total;
							soma_desconto_total_item += atual.desconto * atual.quantidade;
							soma_preco_final_sem_desconto = soma_preco_total_item + soma_desconto_total_item;

							// --- Impressão dos itens ---
							if (primeiro_item_cliente || atual.registro > anterior.registro)
							{
								// Novo pedido → imprime o cabeçalho do item
								printf("\n");
								ImprimeCabecalhoItens();
								printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%35s\x1b[0m│%5d│%44s│%7d│%6s│%14.2f│%17.2f║\n",
									   atual.id, atual.nome, atual.codigo, atual.descricao,
									   atual.quantidade, atual.unidade,
									   atual.preco, atual.preco_total);
								primeiro_item_cliente = 0;
							}
							else
							{
								// Mesmo pedido → imprime sem cabeçalho
								printf("║     │                                   │%5d│%44s│%7d│%6s│%14.2f│%17.2f║\n",
									   atual.codigo, atual.descricao,
									   atual.quantidade, atual.unidade,
									   atual.preco, atual.preco_total);
							}

							// --- Detecta fim do pedido ---
							fim_pedido = (i == y - 1) || (atual.registro < proximo.registro);

							if (fim_pedido)
							{
								printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");

								printf("║  REGISTRO  │    DATA    │   HORA   │  CARTAO TEF  │     PIX      │   DINHEIRO   │  VALOR TOTAL  │  DESCONTO  │   TROCO   │   VALOR FINAL   ║\n");
								printf("║────────────│────────────│──────────│──────────────│──────────────│──────────────│───────────────│────────────├───────────│─────────────────╢\n");

								printf("║      %06d│  %02d/%02d/%04d│  %02d:%02d:%02d│%14.2f│%14.2f│%14.2f│%15.2f│%12.2f│%11.2f│\x1b[36m%17.2f\x1b[0m║\n",
									   atual.registro,
									   atual.data_hora_pedido.tm_mday,
									   atual.data_hora_pedido.tm_mon,
									   atual.data_hora_pedido.tm_year,
									   atual.data_hora_pedido.tm_hour,
									   atual.data_hora_pedido.tm_min,
									   atual.data_hora_pedido.tm_sec,
									   atual.pagamento_cartao,
									   atual.pagamento_pix,
									   atual.pagamento_dinheiro,
									   atual.preco_final_sem_desconto,
									   soma_desconto_total_item,
									   atual.troco,
									   atual.preco_final_com_desconto);
								printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");	   
								printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
								// Zera acumuladores para o próximo pedido
								soma_desconto_total_item = 0.0f;
								soma_preco_total_item = 0.0f;

								// Pausa a cada 10 registros
								if (i < y - 1 && atual.registro % 10 == 0)
								{
									printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
									printf("\nAperte qualquer tecla para seguir a listagem de pedidos... \n\n");
									system("pause > nul");
									ImprimeCabecalhoItens();
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
						printf("█        REGISTRO NAO ENCONTRADO!     █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n");	
					}
					printf("\nContinuar busca - 1 | Voltar ao menu - 2 ");
					menu_busca = ObtemInteiroValidoVarejo(menu_busca);
					do{
						if(menu_busca < 1 || menu_busca > 2)
						{
							printf("\nOpcao invalida!\n");
							printf("\nContinuar busca - 1 | Voltar ao menu - 2 ");
							menu_busca = ObtemInteiroValidoVarejo(menu_busca);
						}
					}while(menu_busca < 1 || menu_busca > 2);
					printf("\n");
					t = 0;
				}while(menu_busca != 2);
			break;
			case 6:
				do{
					system("cls");
					printf("\nBUSCA DE PEDIDO POR DATA\n");
					printf("------------------------\n\n");
					
					printf("Informe a DATA do PEDIDO\n");
					printf("DIA: ");
					dia_pedido = ObtemInteiroValidoVarejo(dia_pedido);
					printf("MES: ");
					mes_pedido = ObtemInteiroValidoVarejo(mes_pedido);
					printf("ANO: ");
					ano_pedido = ObtemInteiroValidoVarejo(ano_pedido);
					printf("\n");
					
					primeiro_item_cliente = 1;
					t = 0;
					
					for(int i = 0; i < y; i++)
					{	
						if(pnt_recibo[i].data_hora_pedido.tm_mday == dia_pedido
						&& pnt_recibo[i].data_hora_pedido.tm_mon == mes_pedido
						&& pnt_recibo[i].data_hora_pedido.tm_year == ano_pedido)
						{
							//int fim_pedido;
							Pedido atual = pnt_recibo[i];
							Pedido anterior = (i > 0) ? pnt_recibo[i - 1] : atual;
							Pedido proximo = (i < y - 1) ? pnt_recibo[i + 1] : atual;

							// Acumulações do pedido
							soma_preco_total_item += atual.preco_total;
							soma_desconto_total_item += atual.desconto * atual.quantidade;
							soma_preco_final_sem_desconto = soma_preco_total_item + soma_desconto_total_item;

							// --- Impressão dos itens ---
							if (primeiro_item_cliente || atual.registro > anterior.registro)
							{
								// Novo pedido → imprime o cabeçalho do item
								printf("\n");
								ImprimeCabecalhoItens();
								printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%35s\x1b[0m│%5d│%44s│%7d│%6s│%14.2f│%17.2f║\n",
									   atual.id, atual.nome, atual.codigo, atual.descricao,
									   atual.quantidade, atual.unidade,
									   atual.preco, atual.preco_total);
								primeiro_item_cliente = 0;
							}
							else
							{
								// Mesmo pedido → imprime sem cabeçalho
								printf("║     │                                   │%5d│%44s│%7d│%6s│%14.2f│%17.2f║\n",
									   atual.codigo, atual.descricao,
									   atual.quantidade, atual.unidade,
									   atual.preco, atual.preco_total);
							}

							// --- Detecta fim do pedido ---
							fim_pedido = (i == y - 1) || (atual.registro < proximo.registro);

							if (fim_pedido)
							{
								printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");

								printf("║  REGISTRO  │    DATA    │   HORA   │  CARTAO TEF  │     PIX      │   DINHEIRO   │  VALOR TOTAL  │  DESCONTO  │   TROCO   │   VALOR FINAL   ║\n");
								printf("║────────────│────────────│──────────│──────────────│──────────────│──────────────│───────────────│────────────├───────────│─────────────────╢\n");

								printf("║      %06d│  %02d/%02d/%04d│  %02d:%02d:%02d│%14.2f│%14.2f│%14.2f│%15.2f│%12.2f│%11.2f│\x1b[36m%17.2f\x1b[0m║\n",
									   atual.registro,
									   atual.data_hora_pedido.tm_mday,
									   atual.data_hora_pedido.tm_mon,
									   atual.data_hora_pedido.tm_year,
									   atual.data_hora_pedido.tm_hour,
									   atual.data_hora_pedido.tm_min,
									   atual.data_hora_pedido.tm_sec,
									   atual.pagamento_cartao,
									   atual.pagamento_pix,
									   atual.pagamento_dinheiro,
									   atual.preco_final_sem_desconto,
									   soma_desconto_total_item,
									   atual.troco,
									   atual.preco_final_com_desconto);
								printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");	   
								printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
								// Zera acumuladores para o próximo pedido
								soma_desconto_total_item = 0.0f;
								soma_preco_total_item = 0.0f;
      

								// Pausa a cada 10 registros
								if (i < y - 1 && atual.registro % 10 == 0)
								{
									printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
									printf("\nAperte qualquer tecla para seguir a listagem de pedidos... \n\n");
									system("pause > nul");
									ImprimeCabecalhoItens();
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
						printf("█        REGISTRO NAO ENCONTRADO!     █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n");	
					}
					printf("\nContinuar busca - 1 | Voltar ao menu - 2 ");
					menu_busca = ObtemInteiroValidoVarejo(menu_busca);
					do{
						if(menu_busca < 1 || menu_busca > 2)
						{
							printf("\nOpcao invalida!\n");
							printf("\nContinuar busca - 1 | Voltar ao menu - 2 ");
							menu_busca = ObtemInteiroValidoVarejo(menu_busca);
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
				op = ObtemInteiroValidoVarejo(op);
				}while(op < 0 || op > 5);
		}
	}while(op != 0);	
	system("cls");
}

void RemovePedido(Pedido * pnt_recibo)
{
	FILE *pont_pedido;
	int fim_pedido;
	int menu_remove = 0;
	int y = 0;
	int r = 0;
	int b = 0;
	int op = 0;
	int registro_pedido = 0;
	float soma_desconto_total_item = 0.0f;
	float soma_preco_final_sem_desconto = 0.0f;
    float soma_preco_total_item = 0.0f;
	int primeiro_item_cliente = 1;
	
	system("cls");
	
	do{
		r = 0;
		y = 0;
		
		y = LeArquivoPedido(pnt_recibo);
		
		printf("\nREMOVER PEDIDO\n");
		printf("--------------\n\n");
		printf("Informe o REGISTRO do pedido a ser removido: ");
		//LimpaBufferVarejo();
		registro_pedido = ObtemInteiroValidoVarejo(registro_pedido);
		printf("\n");
		
		for(int i = 0; i < y; i++)
		{
			if(pnt_recibo[i].registro == registro_pedido)
			{
				b = 1;
				break;
			}
		}
		if(b == 1)
		{
			printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
			printf("║                                                           **PEDIDO ENCONTRADO**                                                            ║\n");
		}
		
		for(int i = 0; i < y; i++)
		{
			if(pnt_recibo[i].registro == registro_pedido)
			{
				Pedido atual = pnt_recibo[i];
				Pedido anterior = (i > 0) ? pnt_recibo[i - 1] : atual;
				Pedido proximo = (i < y - 1) ? pnt_recibo[i + 1] : atual;
				// Acumulações do pedido
				soma_preco_total_item += atual.preco_total;
				soma_desconto_total_item += atual.desconto * atual.quantidade;
				soma_preco_final_sem_desconto = soma_preco_total_item + soma_desconto_total_item;
							
				//Impressão dos itens
				if (primeiro_item_cliente || atual.registro > anterior.registro)
				{
					// Novo pedido → imprime o cabeçalho do item
					ImprimeCabecalhoItensInicio();
					printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
					printf("║\033[31m%5d\033[0m│\033[31m%35s\033[0m│%5d│%44s│%7d│%6s│%14.2f│%17.2f║\n",
						   atual.id, atual.nome, atual.codigo, atual.descricao,
						   atual.quantidade, atual.unidade,
						   atual.preco, atual.preco_total);
					primeiro_item_cliente = 0;
				}
					
				else
				{
					// Mesmo pedido → imprime sem cabeçalho
					printf("║     │                                   │%5d│%44s│%7d│%6s│%14.2f│%17.2f║\n",
						   atual.codigo, atual.descricao,
						   atual.quantidade, atual.unidade,
						   atual.preco, atual.preco_total);
				}
				//Detecta fim do pedido
				fim_pedido = (i == y - 1) || (atual.registro < proximo.registro);

				if (fim_pedido)
				{
					printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
					printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
					printf("║  REGISTRO  │    DATA    │   HORA   │  CARTAO TEF  │     PIX      │   DINHEIRO   │  VALOR TOTAL  │  DESCONTO  │   TROCO   │   VALOR FINAL   ║\n");
					printf("║────────────│────────────│──────────│──────────────│──────────────│──────────────│───────────────│────────────├───────────│─────────────────╢\n");
					printf("║      \033[31m%06d\033[0m│  %02d/%02d/%04d│  %02d:%02d:%02d│%14.2f│%14.2f│%14.2f│%15.2f│%12.2f│%11.2f│\033[31m%17.2f\033[0m║\n",
									   atual.registro,
									   atual.data_hora_pedido.tm_mday,
									   atual.data_hora_pedido.tm_mon,
									   atual.data_hora_pedido.tm_year,
									   atual.data_hora_pedido.tm_hour,
									   atual.data_hora_pedido.tm_min,
									   atual.data_hora_pedido.tm_sec,
									   atual.pagamento_cartao,
									   atual.pagamento_pix,
									   atual.pagamento_dinheiro,
									   atual.preco_final_sem_desconto,
									   soma_desconto_total_item,
									   atual.troco,
									   atual.preco_final_com_desconto);
					printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");	   
					printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
					
					// Zera acumuladores para o próximo pedido
					soma_desconto_total_item = 0.0f;
					soma_preco_total_item = 0.0f;
					soma_preco_final_sem_desconto = 0.0f;
				}
				r = 1;
			}	
		}
		
		if(r == 1)
		{
			
			printf("\nRemover pedido - 1\n");
			printf("Cancelar remoção e continuar busca - 2\n");
			printf("Cancelar remoção e voltar ao MENU INICIAL - 0\n");
			menu_remove = ObtemInteiroValidoVarejo(menu_remove);
			
			switch (menu_remove)
			{
				case 1:
					pont_pedido = fopen("pedido.txt","w");
					
					for(int i = 0; i < y; i++)
					{
						if(pnt_recibo[i].registro != registro_pedido)
						{
							fprintf(pont_pedido,"%d\n%d\n%s\n%d\n%s\n%d\n%s\n%d\n%s\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%.2f\n%d\n%d\n%d\n%d\n%d\n%d\n%.2f\n%.2f\n%.2f\n",
									 pnt_recibo[i].registro,
									 pnt_recibo[i].id,
									 pnt_recibo[i].nome,
									 pnt_recibo[i].codigo,
									 pnt_recibo[i].descricao,
									 pnt_recibo[i].numero,
									 pnt_recibo[i].categoria,
									 pnt_recibo[i].quantidade,
									 pnt_recibo[i].unidade,
									 pnt_recibo[i].preco,
									 pnt_recibo[i].desconto,
									 pnt_recibo[i].preco_total,
									 pnt_recibo[i].pagamento_cartao,
									 pnt_recibo[i].pagamento_pix,
									 pnt_recibo[i].pagamento_dinheiro,
									 pnt_recibo[i].troco,
									 pnt_recibo[i].data_hora_pedido.tm_mday,
									 pnt_recibo[i].data_hora_pedido.tm_mon,
									 pnt_recibo[i].data_hora_pedido.tm_year,
									 pnt_recibo[i].data_hora_pedido.tm_hour,
									 pnt_recibo[i].data_hora_pedido.tm_min,
									 pnt_recibo[i].data_hora_pedido.tm_sec,
									 pnt_recibo[i].preco_final_sem_desconto,
									 pnt_recibo[i].preco_final_com_desconto,
									 pnt_recibo[i].lucro);
						}
					}
					
					fclose(pont_pedido);
					
					system("cls");
					printf("\n\nPEDIDO REMOVIDO\n\n");
					printf("Remover outro pedido - 1 | Voltar ao MENU INICIAL - 2\n");
					op = ObtemInteiroValidoVarejo(op);
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
								printf("Remover outro pedido - 1 | Voltar ao MENU INICIAL - 2\n");
								op = ObtemInteiroValidoVarejo(op);
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
						printf("\nRemover pedido - 1\n");
						printf("Cancelar remoção e continuar busca - 2\n");
						printf("Cancelar remoção e voltar ao MENU INICIAL - 0\n");
						menu_remove = ObtemInteiroValidoVarejo(menu_remove);
					}while(menu_remove < 0 || menu_remove > 2);
			}
		}
						
		if(r == 0)
		{
			printf("\n");
			printf("███████████████████████████████████████\n\a");
			printf("█                                     █\n");
			printf("█         PEDIDO NAO ENCONTRADO!      █\n");
			printf("█                                     █\n");
			printf("███████████████████████████████████████\n\n");
				
			printf("Continuar busca - 1 | Voltar ao MENU INICIAL - 0\n");
			
			menu_remove = ObtemInteiroValidoVarejo(menu_remove);
					
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
						
						menu_remove = ObtemInteiroValidoVarejo(menu_remove);
							
					}while(menu_remove < 0 || menu_remove > 1);
			}		
		}	
	}while(r != 2);
}

void CalculaBalancoVarejo(Pedido * pnt_recibo, Estoque * pnt_deposito)
{
	system("color 07");
	FILE *pont_pedido;
	FILE *pont_categoria;
	FILE *pont_deposito;
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
	int e = 0;
	int t = 0;
	int op = -1;
	
	system("cls");
	
	pont_categoria = fopen("categoria.txt","r");
	while(fscanf(pont_categoria,"%d\n%[^\n]\n",
							&pnt_deposito[c].numero,
							pnt_deposito[c].categoria) != EOF)
	{
		c++;
	}
	fclose(pont_categoria);
	
	y = LeArquivoPedido(pnt_recibo);

	e = LeArquivoEstoque(pnt_deposito);

	do{
		MenuBalancoVarejo();
		//scanf("%d",&op);
		op = ObtemInteiroValidoVarejo(op);
		
		switch(op)
		{
			case 1:
				do{
					system("cls");
					//printf("\nCALCULO BALANCO GERAL\n");
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
							venda_reais = venda_geral / 100;
							venda_centavos = llabs(venda_geral % 100);
							
							total_lucro_geral += pnt_recibo[i].lucro;
							total_lucro_geral *= 100;
							lucro_geral = (int)total_lucro_geral;
							lucro_reais = lucro_geral / 100;
							lucro_centavos = llabs(lucro_geral % 100);
					}
					
					printf("\n");
					printf("╔═════════════════════════════════════════════════════════════════════════════════════╗\n");
					printf("║                           **BALANÇO GERAL FINANCEIRO**                              ║\n");
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
				*/	
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
				
			break;*/
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

void ApagaDadosSistemaVarejo(Pedido  * pnt_recibo)
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

double arredonda(double v)
{
    return floor(v * 100.0 + 0.5) / 100.0;
}