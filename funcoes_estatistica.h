int anoBissextoEstatistica(int ano);
int dataValidaEstatistica(int dia, int mes, int ano);
int mesValidaEstatistica(int mes, int ano);
void LimpaBufferEstatistica();
int ObtemInteiroValidoEstatistica(int n);
float ObtemFloatValidoEstatistica();
void LimpaStringEstatistica(char *str);
void ConverteMaiusculaEstatistica(char *str);

void MenuBalancoGeralEstatistica();
void MenuBalancoGeralPorDataEstatistica();
void MenuBalancoGeralPorDataDiarioEstatistica();
void MenuBalancoGeralPorDataMensalEstatistica();
void MenuBalancoGeralPorDataAnualEstatistica();

void MenuBalancoEspecificoEstatistica();
void MenuBalancoEspecificoPorDataEstatistica();
void MenuBalancoEspecificoPessoaEstatistica();
void MenuBalancoEspecificoPessoaClienteEstatistica();
void MenuBalancoEspecificoPessoaBarberEstatistica();

void CalculaBalancoGeralEstatistica(Atendimento * pnt_recibo);
void CalculaBalancoGeralPorDataEstatistica(Atendimento * pnt_recibo);
void CalculaBalancoEspecificoEstatistica(Atendimento * pnt_recibo);
void CalculaBalancoEspecificoPessoaEstatistica(Atendimento * pnt_recibo);



int anoBissextoEstatistica(int ano)
{
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
        return 1;
    return 0;
}

int dataValidaEstatistica(int dia, int mes, int ano)
{
    if (ano <= 0)
        return 0;

    if (mes < 1 || mes > 12)
        return 0;

    if (dia < 1)
        return 0;

    int diasNoMes;

    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            diasNoMes = 31;
            break;

        case 4: case 6: case 9: case 11:
            diasNoMes = 30;
            break;

        case 2:
            if (anoBissextoEstatistica(ano))
                diasNoMes = 29;
            else
                diasNoMes = 28;
            break;
    }

    if (dia > diasNoMes)
        return 0;

    return 1;
}

int mesValidaEstatistica(int mes, int ano)
{
    if (ano <= 0)
        return 0;

    if (mes < 1 || mes > 12)
        return 0;

    return 1;
}

void LimpaBufferEstatistica()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // apenas descarta os caracteres restantes
    }
}

int ObtemInteiroValidoEstatistica(int n)
{
    //int n;
    int resultado;

    while (1) {
        resultado = scanf("%d", &n);

        if (resultado == 1) {
            LimpaBufferEstatistica(); // limpa o '\n' e o que sobrou
            return n;
        } else {
            printf("\nEntrada inválida!\a\n\n");
			printf("Tente novamente: ");
            LimpaBufferEstatistica(); // descarta entrada inválida
        }
    }
}

float ObtemFloatValidoEstatistica()
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

void LimpaStringEstatistica(char *str)
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

void ConverteMaiusculaEstatistica(char *str)
{
    while (*str)
	{
        *str = toupper((unsigned char)*str);
        str++;
    }
}


void MenuBalancoGeralEstatistica()
{
	printf("\n");
	printf("╔════════════════════════════════════════════════════════╗\n");
	printf("║                  CALCULAR BALANCO GERAL                ║\n");
	printf("╠════════════════════════════════════════════════════════╣\n");
	printf("║                                                        ║\n");
	printf("║    Calcular BALANCO GERAL ----------------------- 1    ║\n");
	printf("║    Calcular BALANCO POR SERVICO ----------------- 2    ║\n");
	printf("║                                                        ║\n");
	printf("║    Voltar ao MENU INICIAL ----------------------- 0    ║\n");
	printf("║                                                        ║\n");
	printf("╚════════════════════════════════════════════════════════╝\n\n");
}

void MenuBalancoGeralPorDataEstatistica()
{
	printf("\n");
	printf("╔════════════════════════════════════════════════════════╗\n");
	printf("║               CALCULAR BALANCO POR DATA                ║\n");
	printf("╠════════════════════════════════════════════════════════╣\n");
	printf("║                                                        ║\n");
	printf("║    Calcular BALANCO DIARIO ---------------------- 1    ║\n");
	printf("║    Calcular BALANCO MENSAL ---------------------- 2    ║\n");
	printf("║    Calcular BALANCO ANUAL ----------------------- 3    ║\n");
	printf("║                                                        ║\n");
	printf("║    Voltar ao MENU INICIAL ----------------------- 0    ║\n");
	printf("║                                                        ║\n");
	printf("╚════════════════════════════════════════════════════════╝\n\n");
}

void MenuBalancoGeralPorDataDiarioEstatistica()
{
	printf("\n");
	printf("╔════════════════════════════════════════════════════════╗\n");
	printf("║                 CALCULAR BALANCO DIARIO                ║\n");
	printf("╠════════════════════════════════════════════════════════╣\n");
	printf("║                                                        ║\n");
	printf("║    Calcular BALANCO GERAL ----------------------- 1    ║\n");
	printf("║    Calcular BALANCO POR CLIENTE ----------------- 2    ║\n");
	printf("║    Calcular BALANCO POR BARBER ------------------ 3    ║\n");
	printf("║                                                        ║\n");
	printf("║    Voltar ao MENU ------------------------------- 0    ║\n");
	printf("║                                                        ║\n");
	printf("╚════════════════════════════════════════════════════════╝\n\n");
}

void MenuBalancoGeralPorDataMensalEstatistica()
{
	printf("\n");
	printf("╔════════════════════════════════════════════════════════╗\n");
	printf("║                 CALCULAR BALANCO MENSAL                ║\n");
	printf("╠════════════════════════════════════════════════════════╣\n");
	printf("║                                                        ║\n");
	printf("║    Calcular BALANCO GERAL ----------------------- 1    ║\n");
	printf("║    Calcular BALANCO POR CLIENTE ----------------- 2    ║\n");
	printf("║    Calcular BALANCO POR BARBER ------------------ 3    ║\n");
	printf("║                                                        ║\n");
	printf("║    Voltar ao MENU ------------------------------- 0    ║\n");
	printf("║                                                        ║\n");
	printf("╚════════════════════════════════════════════════════════╝\n\n");
}

void MenuBalancoGeralPorDataAnualEstatistica()
{
	printf("\n");
	printf("╔════════════════════════════════════════════════════════╗\n");
	printf("║                  CALCULAR BALANCO ANUAL                ║\n");
	printf("╠════════════════════════════════════════════════════════╣\n");
	printf("║                                                        ║\n");
	printf("║    Calcular BALANCO GERAL ----------------------- 1    ║\n");
	printf("║    Calcular BALANCO POR CLIENTE ----------------- 2    ║\n");
	printf("║    Calcular BALANCO POR BARBER ------------------ 3    ║\n");
	printf("║                                                        ║\n");
	printf("║    Voltar ao MENU ------------------------------- 0    ║\n");
	printf("║                                                        ║\n");
	printf("╚════════════════════════════════════════════════════════╝\n\n");
}


void MenuBalancoEspecificoEstatistica()
{
	printf("\n");
	printf("╔════════════════════════════════════════════════════════╗\n");
	printf("║               CALCULAR BALANCO ESPECIFICO              ║\n");
	printf("╠════════════════════════════════════════════════════════╣\n");
	printf("║                                                        ║\n");
	printf("║    Calcular BALANCO ESPECIFICO ------------------ 1    ║\n");
	printf("║    Calcular BALANCO POR DATA -------------------- 2    ║\n");
	printf("║                                                        ║\n");
	printf("║    Voltar ao MENU INICIAL ----------------------- 0    ║\n");
	printf("║                                                        ║\n");
	printf("╚════════════════════════════════════════════════════════╝\n\n");
}

void MenuBalancoEspecificoPorDataEstatistica()
{
	printf("\n");
	printf("╔════════════════════════════════════════════════════════╗\n");
	printf("║               CALCULAR BALANCO POR DATA                ║\n");
	printf("╠════════════════════════════════════════════════════════╣\n");
	printf("║                                                        ║\n");
	printf("║    Calcular BALANCO DIARIO ---------------------- 1    ║\n");
	printf("║    Calcular BALANCO MENSAL ---------------------- 2    ║\n");
	printf("║    Calcular BALANCO ANUAL ----------------------- 3    ║\n");
	printf("║                                                        ║\n");
	printf("║    Voltar ao MENU  ------------------------------ 0    ║\n");
	printf("║                                                        ║\n");
	printf("╚════════════════════════════════════════════════════════╝\n\n");
}

void MenuBalancoEspecificoPessoaEstatistica()
{
	printf("\n");
	printf("╔════════════════════════════════════════════════════════╗\n");
	printf("║               CALCULAR BALANCO POR PESSOA              ║\n");
	printf("╠════════════════════════════════════════════════════════╣\n");
	printf("║                                                        ║\n");
	printf("║    Calcular BALANCO POR CLIENTE ----------------- 1    ║\n");
	printf("║    Calcular BALANCO POR BARBER ------------------ 2    ║\n");
	printf("║                                                        ║\n");
	printf("║    Voltar ao MENU ------------------------------- 0    ║\n");
	printf("║                                                        ║\n");
	printf("╚════════════════════════════════════════════════════════╝\n\n");
}

void MenuBalancoEspecificoPessoaClienteEstatistica()
{
	printf("\n");
	printf("╔════════════════════════════════════════════════════════╗\n");
	printf("║               CALCULAR BALANCO POR CLIENTE             ║\n");
	printf("╠════════════════════════════════════════════════════════╣\n");
	printf("║                                                        ║\n");
	printf("║    Calcular BALANCO ESPECIFICO ------------------ 1    ║\n");
	printf("║    Calcular BALANCO DIARIO ---------------------- 2    ║\n");
	printf("║    Calcular BALANCO MENSAL ---------------------- 3    ║\n");
	printf("║    Calcular BALANCO ANUAL ----------------------- 4    ║\n");
	printf("║                                                        ║\n");
	printf("║    Voltar ao MENU INICIAL ----------------------- 0    ║\n");
	printf("║                                                        ║\n");
	printf("╚════════════════════════════════════════════════════════╝\n\n");
}

void MenuBalancoEspecificoPessoaBarberEstatistica()
{
	printf("\n");
	printf("╔════════════════════════════════════════════════════════╗\n");
	printf("║               CALCULAR BALANCO POR BARBER              ║\n");
	printf("╠════════════════════════════════════════════════════════╣\n");
	printf("║                                                        ║\n");
	printf("║    Calcular BALANCO ESPECIFICO ------------------ 1    ║\n");
	printf("║    Calcular BALANCO DIARIO ---------------------- 2    ║\n");
	printf("║    Calcular BALANCO MENSAL ---------------------- 3    ║\n");
	printf("║    Calcular BALANCO ANUAL ----------------------- 4    ║\n");
	printf("║                                                        ║\n");
	printf("║    Voltar ao MENU INICIAL ----------------------- 0    ║\n");
	printf("║                                                        ║\n");
	printf("╚════════════════════════════════════════════════════════╝\n\n");
}


void CalculaBalancoGeralEstatistica(Atendimento * pnt_recibo)
{
	system("color 07");
	
	int acumulador_quantidade = 0;
	int quantidade_vendida = 0;
	
	float acumulador_preco = 0.0;
	int64_t acumulador_preco_total = 0;
	int64_t preco_reais = 0;
	int64_t preco_centavos = 0;
	float total_preco_produto = 0.0;
	
	float acumulador_venda = 0.0;
	int64_t venda_geral = 0;
	int64_t venda_reais = 0;
	int64_t venda_centavos = 0;
	float total_venda_geral = 0.0;
	
	int atendimento_inicial = 0;
	int atendimento_final = 0;
	int mes_inicial = 0;
	int mes_final = 0;
	int ano_inicial = 0;
	int ano_final = 0;
	
	int linha = 0;
	int encontrouMes = 0;
	int encontrouDia = 0;
	int mesAno = 12;
	int diaMes = 31;
	int dia = 0;
	int mes = 0;
	int ano = -1;
	int id = 0;
	char nome[50];
	char descricao[50];
	char categoria[50];
	int numero = 0;
	int codigo = 0;
	int y = 0;
	int c = 0;
	int e = 0;
	int t = 0;
	int op = -1;
	
	
	system("cls");
	
	y = LeArquivoAtendimento(pnt_recibo);

	do{
		venda_geral = 0;
		venda_reais = 0;
		venda_centavos = 0;
		
		MenuBalancoGeralEstatistica();
		op = ObtemInteiroValidoEstatistica(op);
		
		switch(op)
		{
			case 1:
				system("cls");
				printf("\n");
					
				t = 0;
				atendimento_inicial = 0;
				atendimento_final = y - 1;
				
				if (y == 0) {
					printf("Nenhum atendimento registrado.\n");
					break;
				}

				total_venda_geral = 0.0;
				
				for(int i = 0; i < y; i++)
				{	
					if(i == atendimento_inicial)
					{
						mes_inicial = pnt_recibo[i].data_hora_atendimento.tm_mon;
						ano_inicial = pnt_recibo[i].data_hora_atendimento.tm_year;
					}						
					if(i == atendimento_final)
					{
						mes_final = pnt_recibo[i].data_hora_atendimento.tm_mon;
						ano_final = pnt_recibo[i].data_hora_atendimento.tm_year;
					}					
					
					if(i == y-1 || pnt_recibo[i].registro != pnt_recibo[i+1].registro)
					{
						venda_geral += (int64_t) llround(pnt_recibo[i].preco_final_com_desconto * 100.0);
					}
					
				}
				
				//Convertendo valores float para centavos, para evitar falhas de arredondamento	
				venda_reais = venda_geral / 100;
				venda_centavos = llabs(venda_geral % 100);

				//lucro_reais = lucro_geral / 100;
				//lucro_centavos = llabs(lucro_geral % 100);	
					
				printf("\n");
				printf("╔════════════════════════════════════════════════════════════════╗\n");
				printf("║                   **BALANCO GERAL FINANCEIRO**                 ║\n");
				printf("╠════════════════════════════════════════════════════════════════╣\n");
				printf("║ PERIODO INICIAL │  PERIODO FINAL  │         VALOR FINAL        ║\n");
				printf("╟────────────────────────────────────────────────────────────────╢\n");
				printf("╟────────────────────────────────────────────────────────────────╢\n");
				printf("║          %02d/%04d│          %02d/%04d│            \x1b[36m%13lld.%02lld\x1b[0m║\n",
								 mes_inicial,
								 ano_inicial,
								 mes_final,
								 ano_final,
								 (long long)venda_reais,
								 (long long)venda_centavos);
								
				printf("╟────────────────────────────────────────────────────────────────╢\n"); /* \x1b[36m%13lld.%02lld\x1b[0m */
				printf("╚════════════════════════════════════════════════════════════════╝\n\n");
				printf("CALCULO CONCLUIDO\n\n");
					
				op = -1;
				
				printf("Aperte qualquer tecla para voltar ao MENU...\n\n");
				system("pause > nul");
				system("cls");	
			break;
			case 2:
				do{
					system("cls");	
					
					printf("\nBALANCO DE VENDAS POR SERVICO\n");
					printf("-----------------------------\n\n");
					printf("Informe o CODIGO do servico: ");
					codigo = ObtemInteiroValidoEstatistica(codigo);
					printf("\n");
					
					venda_geral = 0;
					venda_reais = 0;
					venda_centavos = 0;
					
					total_preco_produto = 0.0;
					acumulador_preco = 0.0;
					acumulador_preco_total = 0;
					acumulador_quantidade = 0;
					preco_reais = 0;
					preco_centavos = 0;
					
					quantidade_vendida = 0;
					
					t = 0;
					
					system("cls");
					
					for(int i = 0; i < y; i++)
					{
						if(y > 0 && pnt_recibo[i].codigo == codigo)
						{
							printf("\n");
							printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                         **BALANCO POR SERVICO**                                       ║\n");
							printf("╠═══════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
							printf("║ COD │                  DESCRICAO                 │   QTDE   │   PRECO TABELA    │     PRECO FINAL     ║\n");
							printf("╟───────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟───────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							t = 1;
							strcpy(descricao, pnt_recibo[i].descricao);
							break;
						}
					}		
							
					for(int i = 0; i < y; i++)
					{	
						if(y > 0 && pnt_recibo[i].codigo == codigo)
						{
							if(pnt_recibo[i].pagamento_fidelidade == 0)
							{
								venda_geral += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
								acumulador_preco += pnt_recibo[i].preco;
								quantidade_vendida += 1;
							}
						}
					}
					
					//Convertendo valores float para centavos, para evitar falhas de arredondamento	
					venda_reais = venda_geral / 100;
					venda_centavos = llabs(venda_geral % 100);
					
					acumulador_preco *= 100;
					acumulador_preco_total = (int)acumulador_preco;
					preco_reais = acumulador_preco_total / 100;
					preco_centavos = llabs(acumulador_preco_total % 100);
					
					if(t)
					{
							printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%44s\x1b[0m│\x1b[36m%10d\x1b[0m│\x1b[36m%16lld.%02lld\x1b[0m│\x1b[36m%18lld.%02lld\x1b[0m║\n",
									 codigo,
									 descricao,
									 quantidade_vendida,
									 (long long)preco_reais,
									 (long long)preco_centavos,
									 (long long)venda_reais,
									 (long long)venda_centavos);
									 
							printf("╟───────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟───────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╚═══════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
							printf("CALCULO CONCLUIDO\n\n");
					}
					
					if(!t)
					{
						printf("\n");
						printf("███████████████████████████████████████\n\a");
						printf("█                                     █\n");
						printf("█        SERVICO NAO ENCONTRADO!      █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n\n\n");
					}	
					
					if(y == 0)
					{
						printf("\nO arquivo atendimento esta vazio! Não há dados a serem exibidos\n");
					}			
					
					total_preco_produto = 0.0;
					acumulador_preco = 0.0;
					acumulador_preco_total = 0;
					
					venda_geral = 0;
					
					acumulador_quantidade = 0;
					quantidade_vendida = 0;
					
					printf("Realizar outro balanço - 1 | Voltar ao MENU - 2\n");
					op = ObtemInteiroValidoEstatistica(op);
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
								printf("Realizar outro balanço - 1 | Voltar ao MENU - 2\n");
								op = ObtemInteiroValidoEstatistica(op);
							}while(op < 1 || op > 2);
							system("cls");
					}
					
					
				}while(op != 2);
				op = -1;
				system("cls");
			break;
			
			/*
			case 3:
				do{
					system("cls");	
					
					printf("\nBALANÇO DE VENDAS POR CLIENTES\n");
					printf("-----------------------------\n\n");
					printf("Informe o ID do cliente: ");
					id = ObtemInteiroValidoEstoque(id);
					printf("\n");
					
					venda_geral = 0;
					venda_reais = 0;
					venda_centavos = 0;
					
					lucro_geral = 0;
					lucro_reais = 0;
					lucro_centavos = 0;
					
					int t = 0;
					
					system("cls");
					
					for(int i = 0; i < y; i++)
					{
						if(y > 0 && pnt_recibo[i].id == id)
						{
							printf("\n");
							printf("╔══════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                  **BALANCO POR CLIENTE**                                 ║\n");
							printf("╠══════════════════════════════════════════════════════════════════════════════════════════╣\n");
							printf("║ ID  │                   NOME DO                 │       VENDAS       │       LUCROS      ║\n");
							printf("║     │                   CLIENTE                 │                    │                   ║\n");
							printf("╟──────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟──────────────────────────────────────────────────────────────────────────────────────────╢\n");
							strcpy(nome, pnt_recibo[i].nome);
							t = 1;
							break;
						}
					}		
							
					for(int i = 0; i < y; i++)
					{	
						if(y > 0 && pnt_recibo[i].id == id)
						{	
							venda_geral += (int64_t) llround(pnt_recibo[i].preco_final_com_desconto * 100.0);
							lucro_geral += (int64_t) llround(pnt_recibo[i].lucro * 100.0);	
						}
					}
					
					//Convertendo valores float para centavos, para evitar falhas de arredondamento	
					venda_reais = venda_geral / 100;
					venda_centavos = llabs(venda_geral % 100);

					lucro_reais = lucro_geral / 100;
					lucro_centavos = llabs(lucro_geral % 100);	
					
					acumulador_custo *= 100;
					acumulador_custo_total = (int)acumulador_custo;
					custo_reais = acumulador_custo_total / 100;
					custo_centavos = llabs(acumulador_custo_total % 100);
					
					acumulador_preco *= 100;
					acumulador_preco_total = (int)acumulador_preco;
					preco_reais = acumulador_preco_total / 100;
					preco_centavos = llabs(acumulador_preco_total % 100);
					
					for(int i = 0; i < y; i++)
					{
						if(y > 0 && pnt_deposito[i].codigo == codigo)
						{
							printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%43s\x1b[0m│\x1b[36m%17lld.%02lld\x1b[0m│\x1b[36m%16lld.%02lld\x1b[0m║\n",
									 id,
									 nome,
									 
									 (long long)venda_reais,
									 (long long)venda_centavos,
									 
									 (long long)lucro_reais,
									 (long long)lucro_centavos);
									 
							printf("╟──────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟──────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╚══════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
							printf("CALCULO CONCLUIDO\n\n");
							t = 1;
						}
					}
					
					if(t == 0)
					{
						printf("\n");
						printf("███████████████████████████████████████\n\a");
						printf("█                                     █\n");
						printf("█        CLIENTE NAO ENCONTRADO!      █\n");
						printf("█                                     █\n");
						printf("███████████████████████████████████████\n\n\n");
					}	
					
					if(y == 0)
					{
						printf("\nO arquivo estoque esta vazio! Não há dados a serem exibidos\n");
					}			
					
					//total_preco_produto = 0.0;
					//acumulador_preco = 0.0;
					//acumulador_preco_total = 0;
					
					//total_custo_produto = 0.0;
					//acumulador_custo = 0.0;
					//acumulador_custo_total = 0;
					
					venda_geral = 0;
					lucro_geral = 0;
					
					//acumulador_quantidade = 0;
					
					printf("Realizar outro balanço - 1 | Voltar ao MENU - 2\n");
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
								printf("Realizar outro balanço - 1 | Voltar ao MENU - 2\n");
								op = ObtemInteiroValidoEstoque(op);
							}while(op < 1 || op > 2);
							system("cls");
					}
					
					
				}while(op != 2);
				op = -1;
				system("cls");
			break;
			case 5:
				system("cls");
				t = 0;
				printf("\nBALANÇO FINANCEIRO DIARIO\n");
				printf("-------------------------\n\n\n\n");
				
				do{
					
					printf("Informe a DATA do balanço: \n\n");
					printf("DIA: ");
					dia = ObtemInteiroValidoEstoque(dia);
					printf("MES: ");
					mes = ObtemInteiroValidoEstoque(mes);
					printf("ANO: ");
					ano = ObtemInteiroValidoEstoque(ano);
					printf("\n");
						
					if(!dataValida(dia, mes, ano))
					{
						system("cls");
						printf("\nBALANÇO FINANCEIRO DIARIO\n");
						printf("-------------------------\n\n");
						printf("\a\033[31mData invalida! Tente novamente.\033[0m\n\n");
					}

				}while(!dataValida(dia, mes, ano));
				
				
				for(int i = 0; i < y; i++)
				{	
					if(dia == pnt_recibo[i].data_hora_pedido.tm_mday 
					&& mes == pnt_recibo[i].data_hora_pedido.tm_mon
					&& ano == pnt_recibo[i].data_hora_pedido.tm_year
					&& dataValida(dia, mes, ano) == 1)
					{
						venda_geral += (int64_t) llround(pnt_recibo[i].preco_final_com_desconto * 100.0);
						lucro_geral += (int64_t) llround(pnt_recibo[i].lucro * 100.0);
						t = 1;
					}						
				}
				
				if(!t)
				{
					printf("\n");
					printf("███████████████████████████████████████\n\a");
					printf("█                                     █\n");
					printf("█     DATA SEM VENDAS REGISTRADAS!    █\n");
					printf("█                                     █\n");
					printf("███████████████████████████████████████\n\n\n");
				}
				
				//Convertendo valores float para centavos, para evitar falhas de arredondamento	
				venda_reais = venda_geral / 100;
				venda_centavos = llabs(venda_geral % 100);

				lucro_reais = lucro_geral / 100;
				lucro_centavos = llabs(lucro_geral % 100);	
				
				if(t == 1)
				{
					printf("\n");
					printf("╔═══════════════════════════════════════════════════════════════════════════════╗\n");
					printf("║                         **BALANÇO FINANCEIRO DIARIO**                         ║\n");
					printf("╠═══════════════════════════════════════════════════════════════════════════════╣\n");
					printf("║      DATA       │            VENDAS            │            LUCROS            ║\n");
					printf("╟───────────────────────────────────────────────────────────────────────────────╢\n");
					printf("╟───────────────────────────────────────────────────────────────────────────────╢\n");
					printf("║       %02d/%02d/%04d│              \x1b[36m%13lld.%02lld\x1b[0m│              \x1b[36m%13lld.%02lld\x1b[0m║\n",
									 dia,
									 mes,
									 ano,
									 (long long)venda_reais,
									 (long long)venda_centavos,
									 (long long)lucro_reais,
									 (long long)lucro_centavos);
					printf("╟───────────────────────────────────────────────────────────────────────────────╢\n");
					printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n\n");
					printf("CALCULO CONCLUIDO\n\n");
				}	
				op = -1;
				
				printf("Aperte qualquer tecla para voltar ao MENU...\n\n");
				system("pause > nul");
				system("cls");	
			break;
			case 6:
				system("cls");
				t = 0;
				printf("\nBALANÇO FINANCEIRO MENSAL\n");
				printf("-------------------------\n\n\n\n");
				
				do{
					
					printf("Informe o MES do balanço: \n\n");
				
					printf("MES: ");
					mes = ObtemInteiroValidoEstoque(mes);
					printf("ANO: ");
					ano = ObtemInteiroValidoEstoque(ano);
					printf("\n");
						
					if(!mesValida(mes, ano))
					{
						system("cls");
						printf("\nBALANÇO FINANCEIRO MENSAL\n");
						printf("-------------------------\n\n");
						printf("\a\033[31mMes invalido! Tente novamente.\033[0m\n\n");
					}

				}while(!mesValida(mes, ano));
				
				
				for(int i = 0; i < y; i++)
				{	
					if(mes == pnt_recibo[i].data_hora_pedido.tm_mon
					&& ano == pnt_recibo[i].data_hora_pedido.tm_year
					&& mesValida(mes, ano) == 1)
					{
						venda_geral += (int64_t) llround(pnt_recibo[i].preco_final_com_desconto * 100.0);
						lucro_geral += (int64_t) llround(pnt_recibo[i].lucro * 100.0);
						t = 1;
					}						
				}
				
				if(!t)
				{
					printf("\n");
					printf("███████████████████████████████████████\n\a");
					printf("█                                     █\n");
					printf("█     MES SEM VENDAS REGISTRADAS!     █\n");
					printf("█                                     █\n");
					printf("███████████████████████████████████████\n\n\n");
				}
				
				//Convertendo valores float para centavos, para evitar falhas de arredondamento	
				venda_reais = venda_geral / 100;
				venda_centavos = llabs(venda_geral % 100);

				lucro_reais = lucro_geral / 100;
				lucro_centavos = llabs(lucro_geral % 100);	
				
				if(t == 1)
				{
					printf("\n");
					printf("╔═══════════════════════════════════════════════════════════════════════════════╗\n");
					printf("║                         **BALANÇO FINANCEIRO MENSAL**                         ║\n");
					printf("╠═══════════════════════════════════════════════════════════════════════════════╣\n");
					printf("║       DATA      │            VENDAS            │            LUCROS            ║\n");
					printf("╟───────────────────────────────────────────────────────────────────────────────╢\n");
					printf("╟───────────────────────────────────────────────────────────────────────────────╢\n");
					printf("║          \033[32m%02d\033[0m/\033[32m%04d\033[0m│              \033[32m%13lld.%02lld\033[0m│              \033[32m%13lld.%02lld\033[0m║\n",
									 mes,
									 ano,
									 (long long)venda_reais,
									 (long long)venda_centavos,
									 (long long)lucro_reais,
									 (long long)lucro_centavos);
					printf("╟───────────────────────────────────────────────────────────────────────────────╢\n");
					printf("╠═══════════════════════════════════════════════════════════════════════════════╣\n");
					//printf("║                                                                               ║\n");
					//printf("CALCULO CONCLUIDO\n\n");
				}	
				op = -1;
				
				for (int d = 1; d <= diaMes; d++)
				{
					venda_geral = 0;
					lucro_geral = 0;
					encontrouDia = 0;
					
					for(int i = 0; i < y; i++)
					{	
						if(mes == pnt_recibo[i].data_hora_pedido.tm_mon
						&& ano == pnt_recibo[i].data_hora_pedido.tm_year
						&& mesValida(mes, ano) == 1
						&& pnt_recibo[i].data_hora_pedido.tm_mday == d)
						{
							venda_geral += (int64_t) llround(pnt_recibo[i].preco_final_com_desconto * 100.0);
							lucro_geral += (int64_t) llround(pnt_recibo[i].lucro * 100.0);
							encontrouDia = 1;
						}		
					}		
						
					if(encontrouDia)	
					{	
						//printf("\n");
						//Convertendo valores float para centavos, para evitar falhas de arredondamento	
						linha++;
						venda_reais = venda_geral / 100;
						venda_centavos = llabs(venda_geral % 100);

						lucro_reais = lucro_geral / 100;
						lucro_centavos = llabs(lucro_geral % 100);
						
						if(linha % 2 == 0)
						{
							//printf("╟───────────────────────────────────────────────────────────────────────────────╢\n");
							printf("║       \x1b[36m%02d\x1b[0m/\x1b[36m%02d\x1b[0m/\x1b[36m%04d\x1b[0m│              \x1b[36m%13lld.%02lld\x1b[0m│              \x1b[36m%13lld.%02lld\x1b[0m║\n",
											 d,
											 mes,
											 ano,
											 (long long)venda_reais,
											 (long long)venda_centavos,
											 (long long)lucro_reais,
											 (long long)lucro_centavos);
							//printf("╟───────────────────────────────────────────────────────────────────────────────╢\n");
						}
						else
						{
							//printf("╟───────────────────────────────────────────────────────────────────────────────╢\n");
							printf("║       %02d/%02d/%04d│              %13lld.%02lld│              %13lld.%02lld║\n",
											 d,
											 mes,
											 ano,
											 (long long)venda_reais,
											 (long long)venda_centavos,
											 (long long)lucro_reais,
											 (long long)lucro_centavos);
							//printf("╟───────────────────────────────────────────────────────────────────────────────╢\n");
						}
					}
						
				}
				
				printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
				printf("\nCALCULO CONCLUIDO\n\n");
				
				venda_geral = 0;
				lucro_geral = 0;
				linha = 0;
				
				printf("Aperte qualquer tecla para voltar ao MENU...\n\n");
				system("pause > nul");
				system("cls");	
			break;
			case 7:
				system("cls");
				t = 0;
				printf("\nBALANÇO FINANCEIRO ANUAL\n");
				printf("-------------------------\n\n\n\n");
				
				do{
					
					printf("Informe o ANO do balanço: \n\n");
				
					printf("ANO: ");
					ano = ObtemInteiroValidoEstoque(ano);
					printf("\n");
						
					if(ano < 0)
					{
						system("cls");
						printf("\nBALANÇO FINANCEIRO ANUAL\n");
						printf("------------------------\n\n");
						printf("\a\033[31mAno invalido! Tente novamente.\033[0m\n\n");
					}

				}while(ano < 0);
				
				
				for(int i = 0; i < y; i++)
				{	
					if(ano == pnt_recibo[i].data_hora_pedido.tm_year
					&& ano >= 0)
					{
						venda_geral += (int64_t) llround(pnt_recibo[i].preco_final_com_desconto * 100.0);
						lucro_geral += (int64_t) llround(pnt_recibo[i].lucro * 100.0);
						t = 1;
					}						
				}
				
				if(!t)
				{
					printf("\n");
					printf("███████████████████████████████████████\n\a");
					printf("█                                     █\n");
					printf("█     ANO SEM VENDAS REGISTRADAS!     █\n");
					printf("█                                     █\n");
					printf("███████████████████████████████████████\n\n\n");
				}
				
				//Convertendo valores float para centavos, para evitar falhas de arredondamento	
				venda_reais = venda_geral / 100;
				venda_centavos = llabs(venda_geral % 100);

				lucro_reais = lucro_geral / 100;
				lucro_centavos = llabs(lucro_geral % 100);	
				
				if(t == 1)
				{
					printf("\n");
					printf("╔═══════════════════════════════════════════════════════════════════════════════╗\n");
					printf("║                         **BALANÇO FINANCEIRO ANUAL**                          ║\n");
					printf("╠═══════════════════════════════════════════════════════════════════════════════╣\n");
					printf("║       ANO       │            VENDAS            │            LUCROS            ║\n");
					printf("╟───────────────────────────────────────────────────────────────────────────────╢\n");
					printf("╟───────────────────────────────────────────────────────────────────────────────╢\n");
					printf("║             \033[32m%04d\033[0m│              \033[32m%13lld.%02lld\033[0m│              \033[32m%13lld.%02lld\033[0m║\n",
									 ano,
									 (long long)venda_reais,
									 (long long)venda_centavos,
									 (long long)lucro_reais,
									 (long long)lucro_centavos);
					printf("╟───────────────────────────────────────────────────────────────────────────────╢\n");
					printf("╠═══════════════════════════════════════════════════════════════════════════════╣\n");
					//printf("CALCULO CONCLUIDO\n\n");	
				}	
				op = -1;
				
				for (int m = 1; m <= mesAno; m++)
				{
					venda_geral = 0;
					lucro_geral = 0;
					encontrouMes = 0;
					
					for(int i = 0; i < y; i++)
					{	
						if(ano == pnt_recibo[i].data_hora_pedido.tm_year
						&& pnt_recibo[i].data_hora_pedido.tm_mon == m)
						{
							venda_geral += (int64_t) llround(pnt_recibo[i].preco_final_com_desconto * 100.0);
							lucro_geral += (int64_t) llround(pnt_recibo[i].lucro * 100.0);
							encontrouMes = 1;
						}		
					}		
						
					if(encontrouMes)	
					{	
						//printf("\n");
						//Convertendo valores float para centavos, para evitar falhas de arredondamento	
						linha++;
						venda_reais = venda_geral / 100;
						venda_centavos = llabs(venda_geral % 100);

						lucro_reais = lucro_geral / 100;
						lucro_centavos = llabs(lucro_geral % 100);
						
						if(linha % 2 == 0)
						{
							//printf("╟───────────────────────────────────────────────────────────────────────────────╢\n");
							printf("║          \x1b[36m%02d\x1b[0m/\x1b[36m%04d\x1b[0m│              \x1b[36m%13lld.%02lld\x1b[0m│              \x1b[36m%13lld.%02lld\x1b[0m║\n",
											 m,
											 ano,
											 (long long)venda_reais,
											 (long long)venda_centavos,
											 (long long)lucro_reais,
											 (long long)lucro_centavos);
							//printf("╟───────────────────────────────────────────────────────────────────────────────╢\n");
						}
						else
						{
							//printf("╟───────────────────────────────────────────────────────────────────────────────╢\n");
							printf("║          %02d/%04d│              %13lld.%02lld│              %13lld.%02lld║\n",
											 m,
											 ano,
											 (long long)venda_reais,
											 (long long)venda_centavos,
											 (long long)lucro_reais,
											 (long long)lucro_centavos);
							//printf("╟───────────────────────────────────────────────────────────────────────────────╢\n");
						}
					}
						
				}
				
				printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
				printf("\nCALCULO CONCLUIDO\n\n");
				
				venda_geral = 0;
				lucro_geral = 0;
				linha = 0;
				
				printf("Aperte qualquer tecla para voltar ao MENU...\n\n");
				system("pause > nul");
				system("cls");		
			break;
			*/

			case 0:
				system("cls");
			break;
			default:
				printf("\nDigite uma opcao valida\n\n");
		}
	}while(op != 0);
	
	
}

void CalculaBalancoGeralPorDataEstatistica(Atendimento * pnt_recibo)
{
	system("color 07");
	
	int acumulador_quantidade = 0;
	int quantidade_vendida = 0;
	
	float acumulador_preco = 0.0;
	int64_t acumulador_preco_total = 0;
	int64_t preco_reais = 0;
	int64_t preco_centavos = 0;
	float total_preco_produto = 0.0;
	
	float acumulador_venda = 0.0;
	int64_t venda_geral = 0;
	int64_t venda_reais = 0;
	int64_t venda_centavos = 0;
	float total_venda_geral = 0.0;
	
	int atendimento_inicial = 0;
	int atendimento_final = 0;
	int mes_inicial = 0;
	int mes_final = 0;
	int ano_inicial = 0;
	int ano_final = 0;
	
	int linha = 0;
	int encontrouMes = 0;
	int encontrouDia = 0;
	int mesAno = 12;
	int diaMes = 31;
	int dia = 0;
	int mes = 0;
	int ano = -1;
	int id = 0;
	char nome[50];
	char descricao[50];
	int codigo = 0;
	int y = 0;
	int c = 0;
	int e = 0;
	int t = 0;
	int op = -1;
	int subOp_diario = -1;
	int subOp_mensal = -1;
	int subOp_anual = -1;
	
	system("cls");

	y = LeArquivoAtendimento(pnt_recibo);

	do{
		venda_geral = 0;
	
		venda_reais = 0;
		venda_centavos = 0;
	
		MenuBalancoGeralPorDataEstatistica();
		op = ObtemInteiroValidoEstatistica(op);
		
		switch(op)
		{
			case 1:
				system("cls");
				do {
					MenuBalancoGeralPorDataDiarioEstatistica();
					subOp_diario = ObtemInteiroValidoEstatistica(subOp_diario);
					switch(subOp_diario)
					{
						case 1:
							system("cls");
							t = 0;
							printf("\nBALANCO FINANCEIRO DIARIO\n");
							printf("-------------------------\n\n\n\n");
							
							do{
								acumulador_preco = 0.0;
								quantidade_vendida = 0;
								venda_geral = 0;

								system("cls");

								printf("Informe a DATA do balanço: \n\n");
								printf("DIA: ");
								dia = ObtemInteiroValidoEstatistica(dia);
								printf("MES: ");
								mes = ObtemInteiroValidoEstatistica(mes);
								printf("ANO: ");
								ano = ObtemInteiroValidoEstatistica(ano);
								printf("\n");
									
								if(!dataValidaEstatistica(dia, mes, ano))
								{
									system("cls");
									printf("\nBALANCO FINANCEIRO DIARIO\n");
									printf("-------------------------\n\n");
									printf("\a\033[31mData invalida! Tente novamente.\033[0m\n\n");
								}

							}while(!dataValidaEstatistica(dia, mes, ano));
							
							
							for(int i = 0; i < y; i++)
							{	
								if(dia == pnt_recibo[i].data_hora_atendimento.tm_mday 
								&& mes == pnt_recibo[i].data_hora_atendimento.tm_mon
								&& ano == pnt_recibo[i].data_hora_atendimento.tm_year
								&& dataValida(dia, mes, ano) == 1 && pnt_recibo[i].pagamento_fidelidade == 0)
								{
									venda_geral += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);

									acumulador_preco += pnt_recibo[i].preco;

									if(pnt_recibo[i].pagamento_fidelidade == 0)
										quantidade_vendida += 1;

									
									t = 1;
								}						
							}
							
							if(!t)
							{
								printf("\n");
								printf("████████████████████████████████████████████\n\a");
								printf("█                                         █\n");
								printf("█    DATA SEM ATENDIMENTOS REGISTRADOS!   █\n");
								printf("█                                         █\n");
								printf("███████████████████████████████████████████\n\n\n");
							}
							
							//Convertendo valores float para centavos, para evitar falhas de arredondamento	
							venda_reais = venda_geral / 100;
							venda_centavos = llabs(venda_geral % 100);

							acumulador_preco *= 100;
							acumulador_preco_total = (int)acumulador_preco;
							preco_reais = acumulador_preco_total / 100;
							preco_centavos = llabs(acumulador_preco_total % 100);
							
							if(t)
							{
								printf("\n");
								printf("╔═══════════════════════════════════════════════════════════════════════════════╗\n");
								printf("║                         **BALANCO FINANCEIRO DIARIO**                         ║\n");
								printf("╠═══════════════════════════════════════════════════════════════════════════════╣\n");
								printf("║      DATA       │   QTDE   │       PRECO TABELA       │      VALOR FINAL      ║\n");
								printf("╟───────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟───────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║       %02d/%02d/%04d│%10d│          \x1b[36m%13lld.%02lld\x1b[0m│       \x1b[36m%13lld.%02lld\x1b[0m║\n",
												dia,
												mes,
												ano,
												quantidade_vendida,
												
												(long long)preco_reais,
												(long long)preco_centavos,
												(long long)venda_reais,
												(long long)venda_centavos);
								printf("╟───────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n\n");
								printf("CALCULO CONCLUIDO\n\n");
							}	
							
							printf("Aperte qualquer tecla para voltar ao MENU...\n\n");
							system("pause > nul");
							system("cls");	
						break;
						case 2:
							system("cls");
							t = 0;
							printf("\nBALANCO DIARIO POR CLIENTE\n");
							printf("--------------------------\n\n\n\n");
							
							do{
								acumulador_preco = 0.0;
								quantidade_vendida = 0;
								venda_geral = 0;

								printf("Informe o ID do cliente: ");
								id = ObtemInteiroValidoEstatistica(id);

								printf("\nInforme a DATA do balanço: \n\n");
								printf("DIA: ");
								dia = ObtemInteiroValidoEstatistica(dia);
								printf("MES: ");
								mes = ObtemInteiroValidoEstatistica(mes);
								printf("ANO: ");
								ano = ObtemInteiroValidoEstatistica(ano);
								printf("\n");
									
								if(!dataValidaEstatistica(dia, mes, ano))
								{
									system("cls");
									printf("\nBALANCO DIARIO POR CLIENTE\n");
									printf("--------------------------\n\n");
									printf("\a\033[31mData invalida! Tente novamente.\033[0m\n\n");
								}

							}while(!dataValidaEstatistica(dia, mes, ano));
							
							
							for(int i = 0; i < y; i++)
							{	
								if(pnt_recibo[i].idCliente == id
								&& dia == pnt_recibo[i].data_hora_atendimento.tm_mday 
								&& mes == pnt_recibo[i].data_hora_atendimento.tm_mon
								&& ano == pnt_recibo[i].data_hora_atendimento.tm_year
								&& dataValidaEstatistica(dia, mes, ano) == 1
								&& pnt_recibo[i].pagamento_fidelidade == 0)
								{
									strcpy(nome, pnt_recibo[i].nomeCliente);

									venda_geral += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);

									acumulador_preco += pnt_recibo[i].preco/*_total*/;

									if(pnt_recibo[i].pagamento_fidelidade == 0)
										quantidade_vendida++;

									t = 1;
								}						
							}
							
							if(!t)
							{
								printf("\n");
								printf("████████████████████████████████████████████████████████████\n\a");
								printf("█                                                          █\n");
								printf("█     DATA SEM ATENDIMENTOS REGISTRAD0S PARA O CLIENTE!    █\n");
								printf("█                                                          █\n");
								printf("████████████████████████████████████████████████████████████\n\n\n");
							}
							
							//Convertendo valores float para centavos, para evitar falhas de arredondamento	
							venda_reais = venda_geral / 100;
							venda_centavos = llabs(venda_geral % 100);

							acumulador_preco *= 100;
							acumulador_preco_total = (int)acumulador_preco;
							preco_reais = acumulador_preco_total / 100;
							preco_centavos = llabs(acumulador_preco_total % 100);	
							
							if(t)
							{
								printf("\n");
								printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
								printf("║                                              **BALANCO DIARIO POR CLIENTE**                                              ║\n");
								printf("╠══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
								printf("║      DATA       │ ID  │           NOME DO CLIENTE          │   QTDE   │       PRECO TABELA       │      VALOR FINAL      ║\n");
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║       %02d/%02d/%04d│%5d│\x1b[36m%36s\x1b[0m│%10d│           \x1b[36m%12lld.%02lld\x1b[0m│       \x1b[36m%13lld.%02lld\x1b[0m║\n",
												dia,
												mes,
												ano,
												id,
												nome,
												quantidade_vendida,
												
												(long long)preco_reais,
												(long long)preco_centavos,
												(long long)venda_reais,
												(long long)venda_centavos);
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
								printf("CALCULO CONCLUIDO\n\n");
							}	
							
							printf("Aperte qualquer tecla para voltar ao MENU...\n\n");
							system("pause > nul");
							system("cls");	
						break;
						case 3:
							system("cls");
							t = 0;
							printf("\nBALANCO DIARIO POR BARBER\n");
							printf("-------------------------\n\n\n\n");
							
							do{
								acumulador_preco = 0.0;
								quantidade_vendida = 0;
								venda_geral = 0;

								printf("Informe o ID do barber: ");
								id = ObtemInteiroValidoEstatistica(id);

								printf("\nInforme a DATA do balanço: \n\n");
								printf("DIA: ");
								dia = ObtemInteiroValidoEstatistica(dia);
								printf("MES: ");
								mes = ObtemInteiroValidoEstatistica(mes);
								printf("ANO: ");
								ano = ObtemInteiroValidoEstatistica(ano);
								printf("\n");
									
								if(!dataValidaEstatistica(dia, mes, ano))
								{
									system("cls");
									printf("\nBALANCO DIARIO POR BARBER\n");
									printf("-------------------------\n\n");
									printf("\a\033[31mData invalida! Tente novamente.\033[0m\n\n");
								}

							}while(!dataValidaEstatistica(dia, mes, ano));
							
							
							for(int i = 0; i < y; i++)
							{	
								if(pnt_recibo[i].idBarber == id
								&& dia == pnt_recibo[i].data_hora_atendimento.tm_mday 
								&& mes == pnt_recibo[i].data_hora_atendimento.tm_mon
								&& ano == pnt_recibo[i].data_hora_atendimento.tm_year
								&& dataValidaEstatistica(dia, mes, ano) == 1
								&& pnt_recibo[i].pagamento_fidelidade == 0)
								{
									strcpy(nome, pnt_recibo[i].nomeBarber);

									venda_geral += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);

									acumulador_preco += pnt_recibo[i].preco/*_total*/;

									if(pnt_recibo[i].pagamento_fidelidade == 0)
										quantidade_vendida++;

									t = 1;
								}						
							}
							
							if(!t)
							{
								printf("\n");
								printf("█████████████████████████████████████████████████████\n\a");
								printf("█                                                   █\n");
								printf("█     DATA SEM VENDAS REGISTRADAS PARA O BARBER!    █\n");
								printf("█                                                   █\n");
								printf("█████████████████████████████████████████████████████\n\n\n");
							}
							
							//Convertendo valores float para centavos, para evitar falhas de arredondamento	
							venda_reais = venda_geral / 100;
							venda_centavos = llabs(venda_geral % 100);

							acumulador_preco *= 100;
							acumulador_preco_total = (int)acumulador_preco;
							preco_reais = acumulador_preco_total / 100;
							preco_centavos = llabs(acumulador_preco_total % 100);	
							
							if(t)
							{
								printf("\n");
								printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
								printf("║                                              **BALANCO DIARIO POR BARBER**                                               ║\n");
								printf("╠══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
								printf("║      DATA       │ ID  │           NOME DO BARBER           │   QTDE   │       PRECO TABELA       │      VALOR FINAL      ║\n");
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║       %02d/%02d/%04d│%5d│\x1b[36m%36s\x1b[0m│%10d│           \x1b[36m%12lld.%02lld\x1b[0m│       \x1b[36m%13lld.%02lld\x1b[0m║\n",
												dia,
												mes,
												ano,
												id,
												nome,
												quantidade_vendida,
												
												(long long)preco_reais,
												(long long)preco_centavos,
												(long long)venda_reais,
												(long long)venda_centavos);
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
								printf("CALCULO CONCLUIDO\n\n");
							}	
							
							
							printf("Aperte qualquer tecla para voltar ao MENU...\n\n");
							system("pause > nul");
							system("cls");	
						break;
						case 0:
							system("cls");
						break;
						default:
							printf("\nDigite uma opcao valida\n\n");
					}
				} while(subOp_diario != 0);	
			break;
			case 2:
				system("cls");
				do{
					MenuBalancoGeralPorDataMensalEstatistica();
					subOp_mensal = ObtemInteiroValidoEstatistica(subOp_mensal);
					switch(subOp_mensal)
					{
						case 1:
							system("cls");
							t = 0;
							printf("\nBALANCO FINANCEIRO MENSAL\n");
							printf("-------------------------\n\n\n\n");
							
							do{
								acumulador_preco = 0.0;
								quantidade_vendida = 0;
								venda_geral = 0;

								system("cls");

								printf("Informe o MES do balanço: \n\n");
								
								printf("MES: ");
								mes = ObtemInteiroValidoEstatistica(mes);
								printf("ANO: ");
								ano = ObtemInteiroValidoEstatistica(ano);
								printf("\n");
									
								if(!mesValidaEstatistica(mes, ano))
								{
									system("cls");
									printf("\nBALANCO FINANCEIRO MENSAL\n");
									printf("-------------------------\n\n");
									printf("\a\033[31mMes invalido! Tente novamente.\033[0m\n\n");
								}

							}while(!mesValidaEstatistica(mes, ano));
							
							
							for(int i = 0; i < y; i++)
							{	
								if(mes == pnt_recibo[i].data_hora_atendimento.tm_mon
								&& ano == pnt_recibo[i].data_hora_atendimento.tm_year
								&& mesValida(mes, ano) == 1 && pnt_recibo[i].pagamento_fidelidade == 0)
								{
									if(pnt_recibo[i].pagamento_fidelidade == 0)
									{
										venda_geral += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										acumulador_preco += pnt_recibo[i].preco;
										quantidade_vendida += 1;
									}

									t = 1;
								}						
							}
							
							if(!t)
							{
								printf("\n");
								printf("██████████████████████████████████████████\n\a");
								printf("█                                        █\n");
								printf("█    MES SEM ATENDIMENTOS REGISTRADOS!   █\n");
								printf("█                                        █\n");
								printf("██████████████████████████████████████████\n\n\n");
							}
							
							//Convertendo valores float para centavos, para evitar falhas de arredondamento	
							venda_reais = venda_geral / 100;
							venda_centavos = llabs(venda_geral % 100);

							acumulador_preco *= 100;
							acumulador_preco_total = (int)acumulador_preco;
							preco_reais = acumulador_preco_total / 100;
							preco_centavos = llabs(acumulador_preco_total % 100);
							
							if(t)
							{
								printf("\n");
								printf("╔═══════════════════════════════════════════════════════════════════════════════╗\n");
								printf("║                         **BALANCO FINANCEIRO MENSAL**                         ║\n");
								printf("╠═══════════════════════════════════════════════════════════════════════════════╣\n");
								printf("║     MES/ANO     │   QTDE   │       PRECO TABELA       │      VALOR FINAL      ║\n");
								printf("╟───────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟───────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║          %02d/%04d│%10d│          \x1b[36m%13lld.%02lld\x1b[0m│       \x1b[36m%13lld.%02lld\x1b[0m║\n",
												mes,
												ano,
												quantidade_vendida,
												
												(long long)preco_reais,
												(long long)preco_centavos,
												(long long)venda_reais,
												(long long)venda_centavos);
								printf("╟───────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n\n");
								printf("CALCULO CONCLUIDO\n\n");
							}	
							
							
							printf("Aperte qualquer tecla para voltar ao MENU...\n\n");
							system("pause > nul");
							system("cls");	
						break;
						case 2:
							system("cls");
							t = 0;
							printf("\nBALANÇO MENSAL POR CLIENTE\n");
							printf("--------------------------\n\n\n\n");
							
							do{
								acumulador_preco = 0.0;
								quantidade_vendida = 0;
								venda_geral = 0;

								printf("Informe o ID do cliente: ");
								id = ObtemInteiroValidoEstatistica(id);

								printf("\nInforme o MES do balanço: \n\n");
								
								printf("MES: ");
								mes = ObtemInteiroValidoEstatistica(mes);
								printf("ANO: ");
								ano = ObtemInteiroValidoEstatistica(ano);
								printf("\n");
									
								if(!mesValidaEstatistica(mes, ano))
								{
									system("cls");
									printf("\nBALANCO MENSAL POR CLIENTE\n");
									printf("--------------------------\n\n");
									printf("\a\033[31mMes invalido! Tente novamente.\033[0m\n\n");
								}

							}while(!mesValidaEstatistica(mes, ano));
							
							
							for(int i = 0; i < y; i++)
							{	
								if(pnt_recibo[i].idCliente == id
								&& mes == pnt_recibo[i].data_hora_atendimento.tm_mon
								&& ano == pnt_recibo[i].data_hora_atendimento.tm_year
								&& mesValidaEstatistica(mes, ano) == 1)
								{
									strcpy(nome, pnt_recibo[i].nomeCliente);
									if(pnt_recibo[i].pagamento_fidelidade == 0)
									{
										venda_geral += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										acumulador_preco += pnt_recibo[i].preco;
										quantidade_vendida++;
									}	

									t = 1;
								}						
							}
							
							if(!t)
							{
								printf("\n");
								printf("███████████████████████████████████████████████████████████\n\a");
								printf("█                                                         █\n");
								printf("█     MES SEM ATENDIMENTOS REGISTRADOS PARA O CLIENTE!    █\n");
								printf("█                                                         █\n");
								printf("████████████████████████████████████████████████████████████\n\n\n");
							}
							
							//Convertendo valores float para centavos, para evitar falhas de arredondamento	
							venda_reais = venda_geral / 100;
							venda_centavos = llabs(venda_geral % 100);

							acumulador_preco *= 100;
							acumulador_preco_total = (int)acumulador_preco;
							preco_reais = acumulador_preco_total / 100;
							preco_centavos = llabs(acumulador_preco_total % 100);	
							
							if(t)
							{
								printf("\n");
								printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
								printf("║                                              **BALANCO DIARIO POR CLIENTE**                                              ║\n");
								printf("╠══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
								printf("║     MES/ANO     │ ID  │           NOME DO CLIENTE          │   QTDE   │       PRECO TABELA       │      VALOR FINAL      ║\n");
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║          %02d/%04d│%5d│\x1b[36m%36s\x1b[0m│%10d│           \x1b[36m%12lld.%02lld\x1b[0m│       \x1b[36m%13lld.%02lld\x1b[0m║\n",
												mes,
												ano,
												id,
												nome,
												quantidade_vendida,
												
												(long long)preco_reais,
												(long long)preco_centavos,
												(long long)venda_reais,
												(long long)venda_centavos);
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
								printf("CALCULO CONCLUIDO\n\n");
							}	
							
							
							printf("Aperte qualquer tecla para voltar ao MENU...\n\n");
							system("pause > nul");
							system("cls");	
						break;
						case 3:
							system("cls");
							t = 0;
							printf("\nBALANCO MENSAL POR BARBER\n");
							printf("-------------------------\n\n\n\n");
							
							do{
								acumulador_preco = 0.0;
								quantidade_vendida = 0;
								venda_geral = 0;

								printf("Informe o ID do barber: ");
								id = ObtemInteiroValidoEstatistica(id);

								printf("\nInforme o MES do balanço: \n\n");
								
								printf("MES: ");
								mes = ObtemInteiroValidoEstatistica(mes);
								printf("ANO: ");
								ano = ObtemInteiroValidoEstatistica(ano);
								printf("\n");
									
								if(!mesValidaEstatistica(mes, ano))
								{
									system("cls");
									printf("\nBALANCO MENSAL POR BARBER\n");
									printf("-------------------------\n\n");
									printf("\a\033[31mMes invalido! Tente novamente.\033[0m\n\n");
								}

							}while(!mesValidaEstatistica(mes, ano));
							
							
							for(int i = 0; i < y; i++)
							{	
								if(pnt_recibo[i].idBarber == id
								&& mes == pnt_recibo[i].data_hora_atendimento.tm_mon
								&& ano == pnt_recibo[i].data_hora_atendimento.tm_year
								&& mesValidaEstatistica(mes, ano) == 1)
								{
									strcpy(nome, pnt_recibo[i].nomeBarber);

									if(pnt_recibo[i].pagamento_fidelidade == 0)
									{
										venda_geral += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										acumulador_preco += pnt_recibo[i].preco;
										quantidade_vendida++;
									}
									
									t = 1;
								}						
							}
							
							if(!t)
							{
								printf("\n");
								printf("███████████████████████████████████████████████████████████\n\a");
								printf("█                                                         █\n");
								printf("█     MES SEM ATENDIMENTOS REGISTRADOS PARA O BARBER!     █\n");
								printf("█                                                         █\n");
								printf("███████████████████████████████████████████████████████████\n\n\n");
							}
							
							//Convertendo valores float para centavos, para evitar falhas de arredondamento	
							venda_reais = venda_geral / 100;
							venda_centavos = llabs(venda_geral % 100);

							acumulador_preco *= 100;
							acumulador_preco_total = (int)acumulador_preco;
							preco_reais = acumulador_preco_total / 100;
							preco_centavos = llabs(acumulador_preco_total % 100);	
							
							if(t)
							{
								printf("\n");
								printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
								printf("║                                              **BALANCO MENSAL POR BARBER**                                               ║\n");
								printf("╠══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
								printf("║     MES/ANO     │ ID  │           NOME DO BARBER           │   QTDE   │       PRECO TABELA       │      VALOR FINAL      ║\n");
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║          %02d/%04d│%5d│\x1b[36m%36s\x1b[0m│%10d│           \x1b[36m%12lld.%02lld\x1b[0m│       \x1b[36m%13lld.%02lld\x1b[0m║\n",
												mes,
												ano,
												id,
												nome,
												quantidade_vendida,
												
												(long long)preco_reais,
												(long long)preco_centavos,
												(long long)venda_reais,
												(long long)venda_centavos);
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
								printf("CALCULO CONCLUIDO\n\n");
							}	
							
							
							printf("Aperte qualquer tecla para voltar ao MENU...\n\n");
							system("pause > nul");
							system("cls");	
						break;
						case 0:
							system("cls");
						break;
						default:
							printf("\nDigite uma opcao valida\n\n");
					}	
				} while(subOp_mensal != 0);
			break;
			case 3:
				system("cls");
				do{
					MenuBalancoGeralPorDataAnualEstatistica();
					subOp_anual = ObtemInteiroValidoEstatistica(subOp_anual);
					switch(subOp_anual)
					{
						case 1:
							system("cls");
							t = 0;
							printf("\nBALANCO FINANCEIRO ANUAL\n");
							printf("------------------------\n\n\n\n");
							
							do{
								acumulador_preco = 0.0;
								quantidade_vendida = 0;
								venda_geral = 0;

								system("cls");

								printf("Informe o ANO do balanço: \n\n");
								
								printf("ANO: ");
								ano = ObtemInteiroValidoEstatistica(ano);
								printf("\n");
									
								if(ano < 0)
								{
									system("cls");
									printf("\nBALANCO FINANCEIRO ANUAL\n");
									printf("------------------------\n\n");
									printf("\a\033[31mAno invalido! Tente novamente.\033[0m\n\n");
								}

							}while(ano < 0);
							
							
							for(int i = 0; i < y; i++)
							{	
								if(ano == pnt_recibo[i].data_hora_atendimento.tm_year)
								{
									if(pnt_recibo[i].pagamento_fidelidade == 0)
									{
										venda_geral += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										acumulador_preco += pnt_recibo[i].preco;
										quantidade_vendida += 1;
									}

									t = 1;
								}						
							}
							
							if(!t)
							{
								printf("\n");
								printf("██████████████████████████████████████████\n\a");
								printf("█                                        █\n");
								printf("█    ANO SEM ATENDIMENTOS REGISTRADOS!   █\n");
								printf("█                                        █\n");
								printf("██████████████████████████████████████████\n\n\n");
							}
							
							//Convertendo valores float para centavos, para evitar falhas de arredondamento	
							venda_reais = venda_geral / 100;
							venda_centavos = llabs(venda_geral % 100);

							acumulador_preco *= 100;
							acumulador_preco_total = (int)acumulador_preco;
							preco_reais = acumulador_preco_total / 100;
							preco_centavos = llabs(acumulador_preco_total % 100);
							
							if(t)
							{
								printf("\n");
								printf("╔═══════════════════════════════════════════════════════════════════════════════╗\n");
								printf("║                         **BALANCO FINANCEIRO ANUAL**                          ║\n");
								printf("╠═══════════════════════════════════════════════════════════════════════════════╣\n");
								printf("║       ANO       │   QTDE   │       PRECO TABELA       │      VALOR FINAL      ║\n");
								printf("╟───────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟───────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║             %04d│%10d│          \x1b[36m%13lld.%02lld\x1b[0m│       \x1b[36m%13lld.%02lld\x1b[0m║\n",
												ano,
												quantidade_vendida,
												
												(long long)preco_reais,
												(long long)preco_centavos,
												(long long)venda_reais,
												(long long)venda_centavos);
								printf("╟───────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n\n");
								printf("CALCULO CONCLUIDO\n\n");
							}	
							
							
							printf("Aperte qualquer tecla para voltar ao MENU...\n\n");
							system("pause > nul");
							system("cls");	
						break;
						case 2:
							system("cls");
							t = 0;
							printf("\nBALANCO ANUAL POR CLIENTE\n");
							printf("-------------------------\n\n\n\n");
							
							do{
								acumulador_preco = 0.0;
								quantidade_vendida = 0;
								venda_geral = 0;

								printf("Informe o ID do cliente: ");
								id = ObtemInteiroValidoEstatistica(id);

								printf("\nInforme o ANO do balanço: \n\n");
								
								printf("ANO: ");
								ano = ObtemInteiroValidoEstatistica(ano);
								printf("\n");
									
								if(ano < 0)
								{
									system("cls");
									printf("\nBALANCO ANUAL POR CLIENTE\n");
									printf("-------------------------\n\n");
									printf("\a\033[31mAno invalido! Tente novamente.\033[0m\n\n");
								}

							}while(ano < 0);
							
							
							for(int i = 0; i < y; i++)
							{	
								if(pnt_recibo[i].idCliente == id							
								&& ano == pnt_recibo[i].data_hora_atendimento.tm_year)
								{
									strcpy(nome, pnt_recibo[i].nomeCliente);
									if(pnt_recibo[i].pagamento_fidelidade == 0)
									{
										venda_geral += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										acumulador_preco += pnt_recibo[i].preco;
										quantidade_vendida++;
									}	

									t = 1;
								}						
							}
							
							if(!t)
							{
								printf("\n");
								printf("███████████████████████████████████████████████████████████\n\a");
								printf("█                                                         █\n");
								printf("█     ANO SEM ATENDIMENTOS REGISTRADOS PARA O CLIENTE!    █\n");
								printf("█                                                         █\n");
								printf("███████████████████████████████████████████████████████████\n\n\n");
							}
							
							//Convertendo valores float para centavos, para evitar falhas de arredondamento	
							venda_reais = venda_geral / 100;
							venda_centavos = llabs(venda_geral % 100);

							acumulador_preco *= 100;
							acumulador_preco_total = (int)acumulador_preco;
							preco_reais = acumulador_preco_total / 100;
							preco_centavos = llabs(acumulador_preco_total % 100);	
							
							if(t)
							{
								printf("\n");
								printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
								printf("║                                              **BALANCO ANUAL POR CLIENTE**                                               ║\n");
								printf("╠══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
								printf("║       ANO       │ ID  │           NOME DO CLIENTE          │   QTDE   │       PRECO TABELA       │      VALOR FINAL      ║\n");
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║             %04d│%5d│\x1b[36m%35s\x1b[0m│%10d│           \x1b[36m%13lld.%02lld\x1b[0m│       \x1b[36m%13lld.%02lld\x1b[0m║\n",											
												ano,
												id,
												nome,
												quantidade_vendida,
												
												(long long)preco_reais,
												(long long)preco_centavos,
												(long long)venda_reais,
												(long long)venda_centavos);
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
								printf("CALCULO CONCLUIDO\n\n");
							}	
							
							
							printf("Aperte qualquer tecla para voltar ao MENU...\n\n");
							system("pause > nul");
							system("cls");	
						break;
						case 3:
							system("cls");
							t = 0;
							printf("\nBALANCO ANUAL POR BARBER\n");
							printf("------------------------\n\n\n\n");
							
							do{
								acumulador_preco = 0.0;
								quantidade_vendida = 0;
								venda_geral = 0;

								printf("Informe o ID do barber: ");
								id = ObtemInteiroValidoEstatistica(id);

								printf("\nInforme o ANO do balanço: \n\n");
											
								printf("ANO: ");
								ano = ObtemInteiroValidoEstatistica(ano);
								printf("\n");
									
								if(ano < 0)
								{
									system("cls");
									printf("\nBALANCO ANUAL POR BARBER\n");
									printf("------------------------\n\n");
									printf("\a\033[31mAno invalido! Tente novamente.\033[0m\n\n");
								}

							}while(ano < 0);
							
							
							for(int i = 0; i < y; i++)
							{	
								if(pnt_recibo[i].idBarber == id							
								&& ano == pnt_recibo[i].data_hora_atendimento.tm_year)
								{
									strcpy(nome, pnt_recibo[i].nomeBarber);

									if(pnt_recibo[i].pagamento_fidelidade == 0)
									{
										venda_geral += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										acumulador_preco += pnt_recibo[i].preco;
										quantidade_vendida++;
									}
									
									t = 1;
								}						
							}
							
							if(!t)
							{
								printf("\n");
								printf("███████████████████████████████████████████████████████████\n\a");
								printf("█                                                         █\n");
								printf("█     ANO SEM ATENDIMENTOS REGISTRADOS PARA O BARBER!     █\n");
								printf("█                                                         █\n");
								printf("███████████████████████████████████████████████████████████\n\n\n");
							}
							
							//Convertendo valores float para centavos, para evitar falhas de arredondamento	
							venda_reais = venda_geral / 100;
							venda_centavos = llabs(venda_geral % 100);

							acumulador_preco *= 100;
							acumulador_preco_total = (int)acumulador_preco;
							preco_reais = acumulador_preco_total / 100;
							preco_centavos = llabs(acumulador_preco_total % 100);	
							
							if(t)
							{
								printf("\n");
								printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
								printf("║                                              **BALANCO ANUAL POR BARBER**                                                ║\n");
								printf("╠══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
								printf("║       ANO       │ ID  │           NOME DO BARBER           │   QTDE   │       PRECO TABELA       │      VALOR FINAL      ║\n");
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("║             %04d│%5d│\x1b[36m%35s\x1b[0m│%10d│           \x1b[36m%13lld.%02lld\x1b[0m│       \x1b[36m%13lld.%02lld\x1b[0m║\n",											
												ano,
												id,
												nome,
												quantidade_vendida,
												
												(long long)preco_reais,
												(long long)preco_centavos,
												(long long)venda_reais,
												(long long)venda_centavos);
								printf("╟──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
								printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
								printf("CALCULO CONCLUIDO\n\n");
							}	
							
							
							printf("Aperte qualquer tecla para voltar ao MENU...\n\n");
							system("pause > nul");
							system("cls");	
						break;
						case 0:
							system("cls");
						break;
						default:
							printf("\nDigite uma opcao valida\n\n");
					}
				} while(subOp_anual != 0);		
			break;	
			case 0:
				system("cls");
			break;
			default:
				printf("\nDigite uma opcao valida\n\n");
		}
	}while(op != 0);
}

void CalculaBalancoEspecificoEstatistica(Atendimento * pnt_recibo)
{
	system("color 07");
	
	int acumulador_quantidade = 0;
	int quantidade_vendida = 0;
	
	float acumulador_preco = 0.0;
	int64_t acumulador_preco_total = 0;
	int64_t preco_reais = 0;
	int64_t preco_centavos = 0;
	float total_preco_produto = 0.0;
	
	float acumulador_venda = 0.0;
	int64_t venda_geral = 0;
	int64_t venda_reais = 0;
	int64_t venda_centavos = 0;
	float total_venda_geral = 0.0;
	
	int atendimento_inicial = 0;
	int atendimento_final = 0;
	int mes_inicial = 0;
	int mes_final = 0;
	int ano_inicial = 0;
	int ano_final = 0;
	
	int linha = 0;
	int encontrouMes = 0;
	int encontrouDia = 0;
	int mesAno = 12;
	int diaMes = 31;
	int dia = 0;
	int mes = 0;
	int ano = -1;
	int id = 0;
	char nome[50];
	char descricao[50];
	int codigo = 0;
	int y = 0;
	int c = 0;
	int e = 0;
	int t = 0;
	int op = -1;
	int subOp = -1;
	
	// variáveis de serviço
	char corteSocial[50] = "CORTE SOCIAL";
	char corteDegrade[50] = "CORTE DEGRADE";
	char barba[50] = "BARBA";

	int qtdeCorteSocial = 0;
	int qtdeCorteDegrade = 0;
	int qtdeBarba = 0;

	int64_t acumulador_PrecoTotalCorteSocial = 0;
	int64_t acumulador_PrecoTotalCorteDegrade = 0;
	int64_t acumulador_PrecoTotalBarba = 0;

	int64_t precoTotalCorteSocial_reais = 0;
	int64_t precoTotalCorteDegrade_reais = 0;
	int64_t precoTotalBarba_reais = 0;

	int64_t precoTotalCorteSocial_centavos = 0;
	int64_t precoTotalCorteDegrade_centavos = 0;
	int64_t precoTotalBarba_centavos = 0;
	
	int codCorteSocial = 0;
	int codCorteDegrade = 0;
	int codBarba = 0;
	

	system("cls");
	
	y = LeArquivoAtendimento(pnt_recibo);

	do{
		venda_geral = 0;
		venda_reais = 0;
		venda_centavos = 0;
		
		MenuBalancoEspecificoEstatistica();
		op = ObtemInteiroValidoEstatistica(op);
		
		switch(op)
		{
			case 1:
				acumulador_PrecoTotalCorteSocial = 0;
				acumulador_PrecoTotalCorteDegrade = 0;
				acumulador_PrecoTotalBarba = 0;

				qtdeCorteSocial = 0;
				qtdeCorteDegrade = 0;
				qtdeBarba = 0;

				system("cls");
				printf("\n");
					
				t = 0;
				atendimento_inicial = 0;
				atendimento_final = y - 1;
				
				if (y == 0) {
					printf("Nenhum atendimento registrado.\n");
					break;
				}

				total_venda_geral = 0.0;
				
				for(int i = 0; i < y; i++)
				{	
					if(i == atendimento_inicial)
					{
						mes_inicial = pnt_recibo[i].data_hora_atendimento.tm_mon;
						ano_inicial = pnt_recibo[i].data_hora_atendimento.tm_year;
					}						
					
					else if(i == atendimento_final)
					{
						mes_final = pnt_recibo[i].data_hora_atendimento.tm_mon;
						ano_final = pnt_recibo[i].data_hora_atendimento.tm_year;
					}					
					
					if(pnt_recibo[i].pagamento_fidelidade != 1)	
					{							
						if(strcmp(corteSocial, pnt_recibo[i].descricao) == 0)
						{
							acumulador_PrecoTotalCorteSocial += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
							qtdeCorteSocial++;
							codCorteSocial = pnt_recibo[i].codigo;
						}
						else if(strcmp(corteDegrade, pnt_recibo[i].descricao) == 0)
						{
							acumulador_PrecoTotalCorteDegrade += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
							qtdeCorteDegrade++;
							codCorteDegrade = pnt_recibo[i].codigo;
						}
						else if(strcmp(barba, pnt_recibo[i].descricao) == 0)
						{
							acumulador_PrecoTotalBarba += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
							qtdeBarba++;
							codBarba = pnt_recibo[i].codigo;
						}
					}
				}
				
				//Convertendo valores float para centavos, para evitar falhas de arredondamento	
				precoTotalCorteSocial_reais = acumulador_PrecoTotalCorteSocial / 100;
				precoTotalCorteSocial_centavos = llabs(acumulador_PrecoTotalCorteSocial % 100);

				precoTotalCorteDegrade_reais = acumulador_PrecoTotalCorteDegrade / 100;
				precoTotalCorteDegrade_centavos = llabs(acumulador_PrecoTotalCorteDegrade % 100);

				precoTotalBarba_reais = acumulador_PrecoTotalBarba / 100;
				precoTotalBarba_centavos = llabs(acumulador_PrecoTotalBarba % 100);

				venda_reais = precoTotalCorteSocial_reais + precoTotalCorteDegrade_reais;
				venda_centavos = precoTotalCorteSocial_centavos + precoTotalCorteDegrade_centavos;
					
				printf("\n");
				printf("╔════════════════════════════════════════════════════════════════╗\n");
				printf("║                **BALANCO ESPECIFICO FINANCEIRO**               ║\n");
				printf("╠════════════════════════════════════════════════════════════════╣\n");
				printf("║ COD │       DESCRICAO DO SERVICO       │ QTDE │      VALOR     ║\n");
				printf("╟────────────────────────────────────────────────────────────────╢\n");
				printf("╟────────────────────────────────────────────────────────────────╢\n");
		
				printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%34s\x1b[0m│\x1b[36m%6d\x1b[0m│   \x1b[36m%10lld.%02lld\x1b[0m║\n",
							codCorteSocial,
							corteSocial,
							qtdeCorteSocial,
							(long long)precoTotalCorteSocial_reais,
							(long long)precoTotalCorteSocial_centavos);

				printf("║%5d│%34s│%6d│   %10lld.%02lld║\n",
							codCorteDegrade,
							corteDegrade,
							qtdeCorteDegrade, 
							(long long)precoTotalCorteDegrade_reais, 
							(long long)precoTotalCorteDegrade_centavos);

				printf("╟────────────────────────────────────────────────────────────────╢\n");
				printf("╟────────────────────────────────────────────────────────────────╢\n");
				printf("║ PERIODO INICIAL │  PERIODO FINAL  │         VALOR FINAL        ║\n");
				printf("╟────────────────────────────────────────────────────────────────╢\n");
				printf("╟────────────────────────────────────────────────────────────────╢\n");
				printf("║          %02d/%04d│          %02d/%04d│            \x1b[36m%13lld.%02lld\x1b[0m║\n",
								 mes_inicial,
								 ano_inicial,
								 mes_final,
								 ano_final,
								 (long long)venda_reais,
								 (long long)venda_centavos);
								
				printf("╟────────────────────────────────────────────────────────────────╢\n"); /* \x1b[36m%13lld.%02lld\x1b[0m */
				printf("╚════════════════════════════════════════════════════════════════╝\n\n");
				printf("CALCULO CONCLUIDO\n\n");
					
				op = -1;
				
				printf("Aperte qualquer tecla para voltar ao MENU...\n\n");
				system("pause > nul");
				system("cls");	
			break;
			case 2:
				do{
					system("cls");
					MenuBalancoEspecificoPorDataEstatistica();	
					subOp = ObtemInteiroValidoEstatistica(subOp);
		
					switch(subOp)
					{
						case 1:
							system("cls");
							t = 0;
							printf("\nBALANCO FINANCEIRO DIARIO\n");
							printf("-------------------------\n\n\n\n");
							
							do{
								acumulador_PrecoTotalCorteSocial = 0;
								acumulador_PrecoTotalCorteDegrade = 0;
								acumulador_PrecoTotalBarba = 0;

								qtdeCorteSocial = 0;
								qtdeCorteDegrade = 0;
								qtdeBarba = 0;

								acumulador_preco = 0.0;
								quantidade_vendida = 0;
								venda_geral = 0;

								system("cls");

								printf("Informe a DATA do balanço: \n\n");
								printf("DIA: ");
								dia = ObtemInteiroValidoEstatistica(dia);
								printf("MES: ");
								mes = ObtemInteiroValidoEstatistica(mes);
								printf("ANO: ");
								ano = ObtemInteiroValidoEstatistica(ano);
								printf("\n");
									
								if(!dataValidaEstatistica(dia, mes, ano))
								{
									system("cls");
									printf("\nBALANCO FINANCEIRO DIARIO\n");
									printf("-------------------------\n\n");
									printf("\a\033[31mData invalida! Tente novamente.\033[0m\n\n");
								}

							}while(!dataValidaEstatistica(dia, mes, ano));
							
							system("cls");
							printf("\n");
									
							t = 0;
								
								
							if (y == 0) {
								printf("Nenhum atendimento registrado.\n");
								break;
							}
							
							for(int i = 0; i < y; i++)
							{	
								if(dia == pnt_recibo[i].data_hora_atendimento.tm_mday 
								&& mes == pnt_recibo[i].data_hora_atendimento.tm_mon
								&& ano == pnt_recibo[i].data_hora_atendimento.tm_year
								&& dataValida(dia, mes, ano) == 1 && pnt_recibo[i].pagamento_fidelidade == 0)
								{
									if(pnt_recibo[i].pagamento_fidelidade != 1)	
									{												
										if(strcmp(corteSocial, pnt_recibo[i].descricao) == 0)
										{
											acumulador_PrecoTotalCorteSocial += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
											qtdeCorteSocial++;
											codCorteSocial = pnt_recibo[i].codigo;
										}
										else if(strcmp(corteDegrade, pnt_recibo[i].descricao) == 0)
										{
											acumulador_PrecoTotalCorteDegrade += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
											qtdeCorteDegrade++;
											codCorteDegrade = pnt_recibo[i].codigo;
										}
										else if(strcmp(barba, pnt_recibo[i].descricao) == 0)
										{
											acumulador_PrecoTotalBarba += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
											qtdeBarba++;
											codBarba = pnt_recibo[i].codigo;
										}
									}
								}	
							}
								
							//Convertendo valores float para centavos, para evitar falhas de arredondamento	
							precoTotalCorteSocial_reais = acumulador_PrecoTotalCorteSocial / 100;
							precoTotalCorteSocial_centavos = llabs(acumulador_PrecoTotalCorteSocial % 100);
							precoTotalCorteDegrade_reais = acumulador_PrecoTotalCorteDegrade / 100;
							precoTotalCorteDegrade_centavos = llabs(acumulador_PrecoTotalCorteDegrade % 100);

							precoTotalBarba_reais = acumulador_PrecoTotalBarba / 100;
							precoTotalBarba_centavos = llabs(acumulador_PrecoTotalBarba % 100);
							venda_reais = precoTotalCorteSocial_reais + precoTotalCorteDegrade_reais;
							venda_centavos = precoTotalCorteSocial_centavos + precoTotalCorteDegrade_centavos;
								
							printf("\n");
							printf("╔════════════════════════════════════════════════════════════════╗\n");
							printf("║                  **BALANCO ESPECIFICO DIARIO**                 ║\n");
							printf("╠════════════════════════════════════════════════════════════════╣\n");
							printf("║ COD │       DESCRICAO DO SERVICO       │ QTDE │      VALOR     ║\n");
							printf("╟────────────────────────────────────────────────────────────────╢\n");
							printf("╟────────────────────────────────────────────────────────────────╢\n");
					
							printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%34s\x1b[0m│\x1b[36m%6d\x1b[0m│   \x1b[36m%10lld.%02lld\x1b[0m║\n",
										codCorteSocial,
										corteSocial,
										qtdeCorteSocial,
										(long long)precoTotalCorteSocial_reais,
										(long long)precoTotalCorteSocial_centavos);
							printf("║%5d│%34s│%6d│   %10lld.%02lld║\n",
										codCorteDegrade,
										corteDegrade,
										qtdeCorteDegrade, 
										(long long)precoTotalCorteDegrade_reais, 
										(long long)precoTotalCorteDegrade_centavos);
							printf("╟────────────────────────────────────────────────────────────────╢\n");
							printf("╟────────────────────────────────────────────────────────────────╢\n");
							printf("║               │  DATA DO BALANCO  │         VALOR FINAL        ║\n");
							printf("╟────────────────────────────────────────────────────────────────╢\n");
							printf("╟────────────────────────────────────────────────────────────────╢\n");
							printf("║               │        %02d/%02d/%04d│             \x1b[36m%13lld.%02lld\x1b[0m║\n",
											dia,
											mes,
											ano,							
											(long long)venda_reais,
											(long long)venda_centavos);
											
							printf("╟────────────────────────────────────────────────────────────────╢\n"); /* \x1b[36m%13lld.%02lld\x1b[0m */
							printf("╚════════════════════════════════════════════════════════════════╝\n\n");
							printf("CALCULO CONCLUIDO\n\n");
								
							op = -1;
							
							printf("Aperte qualquer tecla para voltar ao MENU...\n\n");
							system("pause > nul");
					
							system("cls");
						break;
						case 2:
							system("cls");
							t = 0;
							printf("\nBALANCO FINANCEIRO MENSAL\n");
							printf("-------------------------\n\n\n\n");
							
							do{
								acumulador_PrecoTotalCorteSocial = 0;
								acumulador_PrecoTotalCorteDegrade = 0;
								acumulador_PrecoTotalBarba = 0;

								qtdeCorteSocial = 0;
								qtdeCorteDegrade = 0;
								qtdeBarba = 0;

								acumulador_preco = 0.0;
								quantidade_vendida = 0;
								venda_geral = 0;

								system("cls");

								printf("Informe o MES do balanço: \n\n");
								
								printf("MES: ");
								mes = ObtemInteiroValidoEstatistica(mes);
								printf("ANO: ");
								ano = ObtemInteiroValidoEstatistica(ano);
								printf("\n");
									
								if(!mesValidaEstatistica(mes, ano))
								{
									system("cls");
									printf("\nBALANCO FINANCEIRO MENSAL\n");
									printf("-------------------------\n\n");
									printf("\a\033[31mMes invalido! Tente novamente.\033[0m\n\n");
								}

							}while(!mesValidaEstatistica(mes, ano));
							

							system("cls");
							printf("\n");
								
							t = 0;
							
							
							if (y == 0) {
								printf("Nenhum atendimento registrado.\n");
								break;
							}
						
							for(int i = 0; i < y; i++)
							{	
								if(mes == pnt_recibo[i].data_hora_atendimento.tm_mon
								&& ano == pnt_recibo[i].data_hora_atendimento.tm_year
								&& mesValidaEstatistica(mes, ano) == 1 && pnt_recibo[i].pagamento_fidelidade == 0)
								{
									if(pnt_recibo[i].pagamento_fidelidade != 1)	
									{	
										if(strcmp(corteSocial, pnt_recibo[i].descricao) == 0)
										{
											acumulador_PrecoTotalCorteSocial += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
											qtdeCorteSocial++;
											codCorteSocial = pnt_recibo[i].codigo;
										}
										else if(strcmp(corteDegrade, pnt_recibo[i].descricao) == 0)
										{
											acumulador_PrecoTotalCorteDegrade += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
											qtdeCorteDegrade++;
											codCorteDegrade = pnt_recibo[i].codigo;
										}
										else if(strcmp(barba, pnt_recibo[i].descricao) == 0)
										{
											acumulador_PrecoTotalBarba += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
											qtdeBarba++;
											codBarba = pnt_recibo[i].codigo;
										}
									}
								}	
							}
							
							//Convertendo valores float para centavos, para evitar falhas de arredondamento	
							precoTotalCorteSocial_reais = acumulador_PrecoTotalCorteSocial / 100;
							precoTotalCorteSocial_centavos = llabs(acumulador_PrecoTotalCorteSocial % 100);
							precoTotalCorteDegrade_reais = acumulador_PrecoTotalCorteDegrade / 100;
							precoTotalCorteDegrade_centavos = llabs(acumulador_PrecoTotalCorteDegrade % 100);
							precoTotalBarba_reais = acumulador_PrecoTotalBarba / 100;
							precoTotalBarba_centavos = llabs(acumulador_PrecoTotalBarba % 100);
							venda_reais = precoTotalCorteSocial_reais + precoTotalCorteDegrade_reais;
							venda_centavos = precoTotalCorteSocial_centavos + precoTotalCorteDegrade_centavos;
								
							printf("\n");
							printf("╔════════════════════════════════════════════════════════════════╗\n");
							printf("║                  **BALANCO ESPECIFICO MENSAL**                 ║\n");
							printf("╠════════════════════════════════════════════════════════════════╣\n");
							printf("║ COD │       DESCRICAO DO SERVICO       │ QTDE │      VALOR     ║\n");
							printf("╟────────────────────────────────────────────────────────────────╢\n");
							printf("╟────────────────────────────────────────────────────────────────╢\n");
					
							printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%34s\x1b[0m│\x1b[36m%6d\x1b[0m│   \x1b[36m%10lld.%02lld\x1b[0m║\n",
										codCorteSocial,
										corteSocial,
										qtdeCorteSocial,
										(long long)precoTotalCorteSocial_reais,
										(long long)precoTotalCorteSocial_centavos);
							printf("║%5d│%34s│%6d│   %10lld.%02lld║\n",
										codCorteDegrade,
										corteDegrade,
										qtdeCorteDegrade,
										(long long)precoTotalCorteDegrade_reais, 
										(long long)precoTotalCorteDegrade_centavos);
							printf("╟────────────────────────────────────────────────────────────────╢\n");
							printf("╟────────────────────────────────────────────────────────────────╢\n");
							printf("║                │  MES DO BALANCO  │         VALOR FINAL        ║\n");
							printf("╟────────────────────────────────────────────────────────────────╢\n");
							printf("╟────────────────────────────────────────────────────────────────╢\n");
							printf("║                │           %02d/%04d│            \x1b[36m%13lld.%02lld\x1b[0m║\n",
											mes,
											ano,							
											(long long)venda_reais,
											(long long)venda_centavos);
											
							printf("╟────────────────────────────────────────────────────────────────╢\n"); /* \x1b[36m%13lld.%02lld\x1b[0m */
							printf("╚════════════════════════════════════════════════════════════════╝\n\n");
							printf("CALCULO CONCLUIDO\n\n");
								
							op = -1;
							
							printf("Aperte qualquer tecla para voltar ao MENU...\n\n");
							system("pause > nul");
					
							system("cls");
						break;
						case 3:
							system("cls");
							t = 0;
							printf("\nBALANCO FINANCEIRO ANUAL\n");
							printf("-------------------------\n\n\n\n");
							
							do{
								acumulador_PrecoTotalCorteSocial = 0;
								acumulador_PrecoTotalCorteDegrade = 0;
								acumulador_PrecoTotalBarba = 0;

								qtdeCorteSocial = 0;
								qtdeCorteDegrade = 0;
								qtdeBarba = 0;

								acumulador_preco = 0.0;
								quantidade_vendida = 0;
								venda_geral = 0;

								system("cls");

								printf("Informe o ANO do balanço: \n\n");
								
								printf("ANO: ");
								ano = ObtemInteiroValidoEstatistica(ano);
								printf("\n");
									
								if(ano < 0)
								{
									system("cls");
									printf("\nBALANCO FINANCEIRO ANUAL\n");
									printf("-------------------------\n\n");
									printf("\a\033[31mAno invalido! Tente novamente.\033[0m\n\n");
								}

							}while(ano < 0);

							system("cls");
							printf("\n");
								
							t = 0;
							
							
							if (y == 0) {
								printf("Nenhum atendimento registrado.\n");
								break;
							}
						
							for(int i = 0; i < y; i++)
							{	
								if(ano == pnt_recibo[i].data_hora_atendimento.tm_year
								&& pnt_recibo[i].pagamento_fidelidade == 0)
								{
									if(pnt_recibo[i].pagamento_fidelidade != 1)	
									{	
										
										if(strcmp(corteSocial, pnt_recibo[i].descricao) == 0)
										{
											acumulador_PrecoTotalCorteSocial += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
											qtdeCorteSocial++;
											codCorteSocial = pnt_recibo[i].codigo;
										}
										else if(strcmp(corteDegrade, pnt_recibo[i].descricao) == 0)
										{
											acumulador_PrecoTotalCorteDegrade += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
											qtdeCorteDegrade++;
											codCorteDegrade = pnt_recibo[i].codigo;
										}
										else if(strcmp(barba, pnt_recibo[i].descricao) == 0)
										{
											acumulador_PrecoTotalBarba += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
											qtdeBarba++;
											codBarba = pnt_recibo[i].codigo;
										}
									}
								}	
							}
							
							//Convertendo valores float para centavos, para evitar falhas de arredondamento	
							precoTotalCorteSocial_reais = acumulador_PrecoTotalCorteSocial / 100;
							precoTotalCorteSocial_centavos = llabs(acumulador_PrecoTotalCorteSocial % 100);
							precoTotalCorteDegrade_reais = acumulador_PrecoTotalCorteDegrade / 100;
							precoTotalCorteDegrade_centavos = llabs(acumulador_PrecoTotalCorteDegrade % 100);
							precoTotalBarba_reais = acumulador_PrecoTotalBarba / 100;
							precoTotalBarba_centavos = llabs(acumulador_PrecoTotalBarba % 100);

							venda_reais = precoTotalCorteSocial_reais + precoTotalCorteDegrade_reais;
							venda_centavos = precoTotalCorteSocial_centavos + precoTotalCorteDegrade_centavos;
									
							printf("\n");
							printf("╔════════════════════════════════════════════════════════════════╗\n");
							printf("║                  **BALANCO ESPECIFICO ANUAL**                  ║\n");
							printf("╠════════════════════════════════════════════════════════════════╣\n");
							printf("║ COD │       DESCRICAO DO SERVICO       │ QTDE │      VALOR     ║\n");
							printf("╟────────────────────────────────────────────────────────────────╢\n");
							printf("╟────────────────────────────────────────────────────────────────╢\n");
					
							printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%34s\x1b[0m│\x1b[36m%6d\x1b[0m│   \x1b[36m%10lld.%02lld\x1b[0m║\n",
										codCorteSocial,
										corteSocial,
										qtdeCorteSocial,
										(long long)precoTotalCorteSocial_reais,
										(long long)precoTotalCorteSocial_centavos);
							printf("║%5d│%34s│%6d│   %10lld.%02lld║\n",
										codCorteDegrade,
										corteDegrade,
										qtdeCorteDegrade,
										(long long)precoTotalCorteDegrade_reais, 
										(long long)precoTotalCorteDegrade_centavos);
							printf("╟────────────────────────────────────────────────────────────────╢\n");
							printf("╟────────────────────────────────────────────────────────────────╢\n");
							printf("║                │  ANO DO BALANCO  │         VALOR FINAL        ║\n");
							printf("╟────────────────────────────────────────────────────────────────╢\n");
							printf("╟────────────────────────────────────────────────────────────────╢\n");
							printf("║                │              %04d│            \x1b[36m%13lld.%02lld\x1b[0m║\n",
											ano,							
											(long long)venda_reais,
											(long long)venda_centavos);
							printf("╟────────────────────────────────────────────────────────────────╢\n"); /* \x1b[36m%13lld.%02lld\x1b[0m */
							printf("╚════════════════════════════════════════════════════════════════╝\n\n");
							printf("CALCULO CONCLUIDO\n\n");
								
							op = -1;
							
							printf("Aperte qualquer tecla para voltar ao MENU...\n\n");
							system("pause > nul");
					
							system("cls");
						break;
						case 0:
							system("cls");
						break;
						default:
							printf("\nDigite uma opcao valida\n\n");
					}				
				}while(subOp != 0);		
			break;
			case 0:
				system("cls");
			break;
			default:
				printf("\nDigite uma opcao valida\n\n");
		}
	}while(op != 0);
}

void CalculaBalancoEspecificoPessoaEstatistica(Atendimento * pnt_recibo)
{
	system("color 07");
	
	int acumulador_quantidade = 0;
	int quantidade_vendida = 0;
	
	float acumulador_preco = 0.0;
	int64_t acumulador_preco_total = 0;
	int64_t preco_reais = 0;
	int64_t preco_centavos = 0;
	float total_preco_produto = 0.0;
	
	float acumulador_venda = 0.0;
	int64_t venda_geral = 0;
	int64_t venda_reais = 0;
	int64_t venda_centavos = 0;
	float total_venda_geral = 0.0;
	
	int atendimento_inicial = 0;
	int atendimento_final = 0;
	int mes_inicial = 0;
	int mes_final = 0;
	int ano_inicial = 0;
	int ano_final = 0;
	
	int linha = 0;
	int encontrouMes = 0;
	int encontrouDia = 0;
	int mesAno = 12;
	int diaMes = 31;
	int dia = 0;
	int mes = 0;
	int ano = -1;
	int id = 0;
	char nome[50];
	char descricao[50];
	int codigo = 0;
	int y = 0;
	int c = 0;
	int e = 0;
	int t = 0;
	int op = -1;
	int subOpCliente = -1;
	int subOpBarber = -1;
	
	// variáveis de serviço
	char corteSocial[50] = "CORTE SOCIAL";
	char corteDegrade[50] = "CORTE DEGRADE";
	char barba[50] = "BARBA";

	int qtdeCorteSocial = 0;
	int qtdeCorteDegrade = 0;
	int qtdeBarba = 0;

	int64_t acumulador_PrecoTotalCorteSocial = 0;
	int64_t acumulador_PrecoTotalCorteDegrade = 0;
	int64_t acumulador_PrecoTotalBarba = 0;

	int64_t precoTotalCorteSocial_reais = 0;
	int64_t precoTotalCorteDegrade_reais = 0;
	int64_t precoTotalBarba_reais = 0;

	int64_t precoTotalCorteSocial_centavos = 0;
	int64_t precoTotalCorteDegrade_centavos = 0;
	int64_t precoTotalBarba_centavos = 0;
	
	int codCorteSocial = 0;
	int codCorteDegrade = 0;
	int codBarba = 0;
	

	system("cls");
	
	y = LeArquivoAtendimento(pnt_recibo);

	do{
		venda_geral = 0;
		venda_reais = 0;
		venda_centavos = 0;
		
		MenuBalancoEspecificoPessoaEstatistica();
		op = ObtemInteiroValidoEstatistica(op);
		
		switch(op)
		{

			case 1:
				system("cls");
				do {
					MenuBalancoEspecificoPessoaClienteEstatistica();
					subOpCliente = ObtemInteiroValidoEstatistica(subOpCliente);
					switch(subOpCliente)
					{
						case 1:
							system("cls");
							t = 0;
							printf("\nBALANCO FINANCEIRO DO CLIENTE\n");
							printf("-----------------------------\n\n\n\n");

							
							acumulador_PrecoTotalCorteSocial = 0;
							acumulador_PrecoTotalCorteDegrade = 0;
							acumulador_PrecoTotalBarba = 0;
							
							qtdeCorteSocial = 0;
							qtdeCorteDegrade = 0;
							qtdeBarba = 0;

							system("cls");
							printf("\n");
								
							printf("Informe o ID do cliente: ");	
							id = ObtemInteiroValidoEstatistica(id);

							t = 0;
							atendimento_inicial = 0;
							atendimento_final = y - 1;
								
							if (y == 0) {
								printf("Nenhum atendimento registrado.\n");
								break;
							}

							total_venda_geral = 0.0;
								
							for(int i = 0; i < y; i++)
							{	
								if(i == atendimento_inicial)
								{
									mes_inicial = pnt_recibo[i].data_hora_atendimento.tm_mon;
									ano_inicial = pnt_recibo[i].data_hora_atendimento.tm_year;
								}						
								
								else if(i == atendimento_final)
								{
									mes_final = pnt_recibo[i].data_hora_atendimento.tm_mon;
									ano_final = pnt_recibo[i].data_hora_atendimento.tm_year;
								}					
					
								if(id == pnt_recibo[i].idCliente
								&& pnt_recibo[i].pagamento_fidelidade != 1)	
								{		
									strcpy(nome, pnt_recibo[i].nomeCliente); 
									
									if(strcmp(corteSocial, pnt_recibo[i].descricao) == 0)
									{
										acumulador_PrecoTotalCorteSocial += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										qtdeCorteSocial++;
										codCorteSocial = pnt_recibo[i].codigo;
									}
									
									else if(strcmp(corteDegrade, pnt_recibo[i].descricao) == 0)
									{
										acumulador_PrecoTotalCorteDegrade += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										qtdeCorteDegrade++;
										codCorteDegrade = pnt_recibo[i].codigo;
									}
									
									else if(strcmp(barba, pnt_recibo[i].descricao) == 0)
									{
										acumulador_PrecoTotalBarba += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										qtdeBarba++;
										codBarba = pnt_recibo[i].codigo;
									}
								}
							}	
				
							//Convertendo valores float para centavos, para evitar falhas de arredondamento	
							precoTotalCorteSocial_reais = acumulador_PrecoTotalCorteSocial / 100;
							precoTotalCorteSocial_centavos = llabs(acumulador_PrecoTotalCorteSocial % 100);
			
							precoTotalCorteDegrade_reais = acumulador_PrecoTotalCorteDegrade / 100;
							precoTotalCorteDegrade_centavos = llabs(acumulador_PrecoTotalCorteDegrade % 100);

							precoTotalBarba_reais = acumulador_PrecoTotalBarba / 100;
							precoTotalBarba_centavos = llabs(acumulador_PrecoTotalBarba % 100);

							venda_reais = precoTotalCorteSocial_reais + precoTotalCorteDegrade_reais;
							venda_centavos = precoTotalCorteSocial_centavos + precoTotalCorteDegrade_centavos;
									
							printf("\n");
							printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                        **BALANCO ESPECIFICO POR CLIENTE**                                      ║\n");
							printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
							printf("║ ID  │             NOME DO CLIENTE             │ COD │       DESCRICAO DO SERVICO       │ QTDE │      VALOR     ║\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
						
							printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%41s\x1b[0m│\x1b[36m%5d\x1b[0m│\x1b[36m%34s\x1b[0m│\x1b[36m%6d\x1b[0m│   \x1b[36m%10lld.%02lld\x1b[0m║\n",
											id,
											nome,
											codCorteSocial,
											corteSocial,
											qtdeCorteSocial,
											(long long)precoTotalCorteSocial_reais,
											(long long)precoTotalCorteSocial_centavos);

							printf("║     │                                         │%5d│%34s│%6d│   %10lld.%02lld║\n",
											codCorteDegrade,
											corteDegrade,
											qtdeCorteDegrade, 
											(long long)precoTotalCorteDegrade_reais, 
											(long long)precoTotalCorteDegrade_centavos);

							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("║                                               │ PERIODO INICIAL │  PERIODO FINAL  │         VALOR FINAL        ║\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("║                                               │          %02d/%04d│          %02d/%04d│            \x1b[36m%13lld.%02lld\x1b[0m║\n",
												mes_inicial,
												ano_inicial,
												mes_final,
												ano_final,
												(long long)venda_reais,
												(long long)venda_centavos);
												
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
							printf("CALCULO CONCLUIDO\n\n");
									
							op = -1;
								
							printf("Aperte qualquer tecla para voltar ao MENU...\n\n");
							system("pause > nul");
							system("cls");	
								
						break;	
						case 2:
							system("cls");
							t = 0;
							printf("\nBALANCO DIARIO DO CLIENTE\n");
							printf("-------------------------\n\n\n\n");
							
							do{
								
								printf("Informe o ID do cliente: ");
								id = ObtemInteiroValidoEstatistica(dia);

								printf("\nInforme a DATA do balanco: \n\n");
								printf("DIA: ");
								dia = ObtemInteiroValidoEstatistica(dia);
								printf("MES: ");
								mes = ObtemInteiroValidoEstatistica(mes);
								printf("ANO: ");
								ano = ObtemInteiroValidoEstatistica(ano);
								printf("\n");
									
								if(!dataValida(dia, mes, ano))
								{
									system("cls");
									printf("\nBALANCO DIARIO DO CLIENTE\n");
									printf("-------------------------\n\n");
									printf("\a\033[31mData invalida! Tente novamente.\033[0m\n\n");
								}

							}while(!dataValidaEstatistica(dia, mes, ano));
							
							acumulador_PrecoTotalCorteSocial = 0;
							acumulador_PrecoTotalCorteDegrade = 0;
							acumulador_PrecoTotalBarba = 0;
							
							qtdeCorteSocial = 0;
							qtdeCorteDegrade = 0;
							qtdeBarba = 0;

							system("cls");
							printf("\n");

							t = 0;
								
							if (y == 0) {
								printf("Nenhum atendimento registrado.\n");
								break;
							}
								
							for(int i = 0; i < y; i++)
							{			
								if(id == pnt_recibo[i].idCliente
								&& dia == pnt_recibo[i].data_hora_atendimento.tm_mday 
								&& mes == pnt_recibo[i].data_hora_atendimento.tm_mon
								&& ano == pnt_recibo[i].data_hora_atendimento.tm_year
								&& dataValidaEstatistica(dia, mes, ano) == 1
								&& pnt_recibo[i].pagamento_fidelidade != 1)	
								{		
									strcpy(nome, pnt_recibo[i].nomeCliente); 
									
									if(strcmp(corteSocial, pnt_recibo[i].descricao) == 0)
									{
										acumulador_PrecoTotalCorteSocial += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										qtdeCorteSocial++;
										codCorteSocial = pnt_recibo[i].codigo;
									}
									
									else if(strcmp(corteDegrade, pnt_recibo[i].descricao) == 0)
									{
										acumulador_PrecoTotalCorteDegrade += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										qtdeCorteDegrade++;
										codCorteDegrade = pnt_recibo[i].codigo;
									}
									
									else if(strcmp(barba, pnt_recibo[i].descricao) == 0)
									{
										acumulador_PrecoTotalBarba += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										qtdeBarba++;
										codBarba = pnt_recibo[i].codigo;
									}
								}
							}	
				
							//Convertendo valores float para centavos, para evitar falhas de arredondamento	
							precoTotalCorteSocial_reais = acumulador_PrecoTotalCorteSocial / 100;
							precoTotalCorteSocial_centavos = llabs(acumulador_PrecoTotalCorteSocial % 100);
			
							precoTotalCorteDegrade_reais = acumulador_PrecoTotalCorteDegrade / 100;
							precoTotalCorteDegrade_centavos = llabs(acumulador_PrecoTotalCorteDegrade % 100);

							precoTotalBarba_reais = acumulador_PrecoTotalBarba / 100;
							precoTotalBarba_centavos = llabs(acumulador_PrecoTotalBarba % 100);

							venda_reais = precoTotalCorteSocial_reais + precoTotalCorteDegrade_reais;
							venda_centavos = precoTotalCorteSocial_centavos + precoTotalCorteDegrade_centavos;
									
							printf("\n");
							printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                          **BALANCO DIARIO POR CLIENTE**                                        ║\n");
							printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
							printf("║ ID  │             NOME DO CLIENTE             │ COD │       DESCRICAO DO SERVICO       │ QTDE │      VALOR     ║\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
						
							printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%41s\x1b[0m│\x1b[36m%5d\x1b[0m│\x1b[36m%34s\x1b[0m│\x1b[36m%6d\x1b[0m│   \x1b[36m%10lld.%02lld\x1b[0m║\n",
											id,
											nome,
											codCorteSocial,
											corteSocial,
											qtdeCorteSocial,
											(long long)precoTotalCorteSocial_reais,
											(long long)precoTotalCorteSocial_centavos);

							printf("║     │                                         │%5d│%34s│%6d│   %10lld.%02lld║\n",
											codCorteDegrade,
											corteDegrade,
											qtdeCorteDegrade, 
											(long long)precoTotalCorteDegrade_reais, 
											(long long)precoTotalCorteDegrade_centavos);

							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("║                                                                 │  DIA DO BALANCO │         VALOR FINAL        ║\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("║                                                                 │       %02d/%02d/%04d│            \x1b[36m%13lld.%02lld\x1b[0m║\n",
												dia,
												mes,
												ano,
												(long long)venda_reais,
												(long long)venda_centavos);
												
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
							printf("CALCULO CONCLUIDO\n\n");
									
							op = -1;
								
							printf("Aperte qualquer tecla para voltar ao MENU...\n\n");
							system("pause > nul");
							system("cls");	
								
						break;
						case 3:
							system("cls");
							t = 0;
							printf("\nBALANCO MENSAL DO CLIENTE\n");
							printf("-------------------------\n\n\n\n");
							
							do{
								
								printf("Informe o ID do cliente: ");
								id = ObtemInteiroValidoEstatistica(dia);

								printf("\nInforme o MES do balanco: \n\n");
								
								printf("MES: ");
								mes = ObtemInteiroValidoEstatistica(mes);
								printf("ANO: ");
								ano = ObtemInteiroValidoEstatistica(ano);
								printf("\n");
									
								if(!mesValidaEstatistica(mes, ano))
								{
									system("cls");
									printf("\nBALANCO MENSAL DO CLIENTE\n");
									printf("-------------------------\n\n");
									printf("\a\033[31mMes invalido! Tente novamente.\033[0m\n\n");
								}

							}while(!mesValidaEstatistica(mes, ano));
							
							acumulador_PrecoTotalCorteSocial = 0;
							acumulador_PrecoTotalCorteDegrade = 0;
							acumulador_PrecoTotalBarba = 0;
							
							qtdeCorteSocial = 0;
							qtdeCorteDegrade = 0;
							qtdeBarba = 0;

							system("cls");
							printf("\n");

							t = 0;
								
							if (y == 0) {
								printf("Nenhum atendimento registrado.\n");
								break;
							}
								
							for(int i = 0; i < y; i++)
							{			
								if(id == pnt_recibo[i].idCliente
								&& mes == pnt_recibo[i].data_hora_atendimento.tm_mon
								&& ano == pnt_recibo[i].data_hora_atendimento.tm_year
								&& mesValidaEstatistica(mes, ano) == 1
								&& pnt_recibo[i].pagamento_fidelidade != 1)	
								{		
									strcpy(nome, pnt_recibo[i].nomeCliente); 
									
									if(strcmp(corteSocial, pnt_recibo[i].descricao) == 0)
									{
										acumulador_PrecoTotalCorteSocial += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										qtdeCorteSocial++;
										codCorteSocial = pnt_recibo[i].codigo;
									}
									
									else if(strcmp(corteDegrade, pnt_recibo[i].descricao) == 0)
									{
										acumulador_PrecoTotalCorteDegrade += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										qtdeCorteDegrade++;
										codCorteDegrade = pnt_recibo[i].codigo;
									}
									
									else if(strcmp(barba, pnt_recibo[i].descricao) == 0)
									{
										acumulador_PrecoTotalBarba += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										qtdeBarba++;
										codBarba = pnt_recibo[i].codigo;
									}
								}
							}	
				
							//Convertendo valores float para centavos, para evitar falhas de arredondamento	
							precoTotalCorteSocial_reais = acumulador_PrecoTotalCorteSocial / 100;
							precoTotalCorteSocial_centavos = llabs(acumulador_PrecoTotalCorteSocial % 100);
			
							precoTotalCorteDegrade_reais = acumulador_PrecoTotalCorteDegrade / 100;
							precoTotalCorteDegrade_centavos = llabs(acumulador_PrecoTotalCorteDegrade % 100);

							precoTotalBarba_reais = acumulador_PrecoTotalBarba / 100;
							precoTotalBarba_centavos = llabs(acumulador_PrecoTotalBarba % 100);

							venda_reais = precoTotalCorteSocial_reais + precoTotalCorteDegrade_reais;
							venda_centavos = precoTotalCorteSocial_centavos + precoTotalCorteDegrade_centavos;
									
							printf("\n");
							printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                          **BALANCO MENSAL POR CLIENTE**                                        ║\n");
							printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
							printf("║ ID  │             NOME DO CLIENTE             │ COD │       DESCRICAO DO SERVICO       │ QTDE │      VALOR     ║\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
						
							printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%41s\x1b[0m│\x1b[36m%5d\x1b[0m│\x1b[36m%34s\x1b[0m│\x1b[36m%6d\x1b[0m│   \x1b[36m%10lld.%02lld\x1b[0m║\n",
											id,
											nome,
											codCorteSocial,
											corteSocial,
											qtdeCorteSocial,
											(long long)precoTotalCorteSocial_reais,
											(long long)precoTotalCorteSocial_centavos);

							printf("║     │                                         │%5d│%34s│%6d│   %10lld.%02lld║\n",
											codCorteDegrade,
											corteDegrade,
											qtdeCorteDegrade, 
											(long long)precoTotalCorteDegrade_reais, 
											(long long)precoTotalCorteDegrade_centavos);

							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("║                                                                 │  MES DO BALANCO │         VALOR FINAL        ║\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("║                                                                 │          %02d/%04d│            \x1b[36m%13lld.%02lld\x1b[0m║\n",
												
												mes,
												ano,
												(long long)venda_reais,
												(long long)venda_centavos);
												
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
							printf("CALCULO CONCLUIDO\n\n");
									
							op = -1;
								
							printf("Aperte qualquer tecla para voltar ao MENU...\n\n");
							system("pause > nul");
							system("cls");	
								
						break;
						case 4:
							system("cls");
							t = 0;
							printf("\nBALANCO ANUAL DO CLIENTE\n");
							printf("------------------------\n\n\n\n");
							
							do{
								
								printf("Informe o ID do cliente: ");
								id = ObtemInteiroValidoEstatistica(dia);

								printf("\nInforme o ANO do balanco: \n\n");
								
								printf("ANO: ");
								ano = ObtemInteiroValidoEstatistica(ano);
								printf("\n");
									
								if(ano < 0)
								{
									system("cls");
									printf("\nBALANCO ANUAL DO CLIENTE\n");
									printf("------------------------\n\n");
									printf("\a\033[31mAno invalido! Tente novamente.\033[0m\n\n");
								}

							}while(ano < 0);
							
							acumulador_PrecoTotalCorteSocial = 0;
							acumulador_PrecoTotalCorteDegrade = 0;
							acumulador_PrecoTotalBarba = 0;
							
							qtdeCorteSocial = 0;
							qtdeCorteDegrade = 0;
							qtdeBarba = 0;

							system("cls");
							printf("\n");

							t = 0;
								
							if (y == 0) {
								printf("Nenhum atendimento registrado.\n");
								break;
							}
								
							for(int i = 0; i < y; i++)
							{			
								if(id == pnt_recibo[i].idCliente
								&& ano == pnt_recibo[i].data_hora_atendimento.tm_year
								&& pnt_recibo[i].pagamento_fidelidade != 1)	
								{		
									strcpy(nome, pnt_recibo[i].nomeCliente); 
									
									if(strcmp(corteSocial, pnt_recibo[i].descricao) == 0)
									{
										acumulador_PrecoTotalCorteSocial += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										qtdeCorteSocial++;
										codCorteSocial = pnt_recibo[i].codigo;
									}
									
									else if(strcmp(corteDegrade, pnt_recibo[i].descricao) == 0)
									{
										acumulador_PrecoTotalCorteDegrade += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										qtdeCorteDegrade++;
										codCorteDegrade = pnt_recibo[i].codigo;
									}
									
									else if(strcmp(barba, pnt_recibo[i].descricao) == 0)
									{
										acumulador_PrecoTotalBarba += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										qtdeBarba++;
										codBarba = pnt_recibo[i].codigo;
									}
								}
							}	
				
							//Convertendo valores float para centavos, para evitar falhas de arredondamento	
							precoTotalCorteSocial_reais = acumulador_PrecoTotalCorteSocial / 100;
							precoTotalCorteSocial_centavos = llabs(acumulador_PrecoTotalCorteSocial % 100);
			
							precoTotalCorteDegrade_reais = acumulador_PrecoTotalCorteDegrade / 100;
							precoTotalCorteDegrade_centavos = llabs(acumulador_PrecoTotalCorteDegrade % 100);

							precoTotalBarba_reais = acumulador_PrecoTotalBarba / 100;
							precoTotalBarba_centavos = llabs(acumulador_PrecoTotalBarba % 100);

							venda_reais = precoTotalCorteSocial_reais + precoTotalCorteDegrade_reais;
							venda_centavos = precoTotalCorteSocial_centavos + precoTotalCorteDegrade_centavos;
									
							printf("\n");
							printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                           **BALANCO ANUAL POR CLIENTE**                                        ║\n");
							printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
							printf("║ ID  │             NOME DO CLIENTE             │ COD │       DESCRICAO DO SERVIÇO       │ QTDE │      VALOR     ║\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
						
							printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%41s\x1b[0m│\x1b[36m%5d\x1b[0m│\x1b[36m%34s\x1b[0m│\x1b[36m%6d\x1b[0m│   \x1b[36m%10lld.%02lld\x1b[0m║\n",
											id,
											nome,
											codCorteSocial,
											corteSocial,
											qtdeCorteSocial,
											(long long)precoTotalCorteSocial_reais,
											(long long)precoTotalCorteSocial_centavos);

							printf("║     │                                         │%5d│%34s│%6d│   %10lld.%02lld║\n",
											codCorteDegrade,
											corteDegrade,
											qtdeCorteDegrade, 
											(long long)precoTotalCorteDegrade_reais, 
											(long long)precoTotalCorteDegrade_centavos);

							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("║                                                                 │  ANO DO BALANCO │         VALOR FINAL        ║\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("║                                                                 │             %04d│            \x1b[36m%13lld.%02lld\x1b[0m║\n",
												ano,
												(long long)venda_reais,
												(long long)venda_centavos);
												
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
							printf("CALCULO CONCLUIDO\n\n");
									
							op = -1;
								
							printf("Aperte qualquer tecla para voltar ao MENU...\n\n");
							system("pause > nul");
							system("cls");	
								
						break;
						case 0:
							system("cls");
						break;
						default:
							printf("\nDigite uma opcao valida\n\n");						
					}	
				}while(subOpCliente != 0);			
			break;
			case 2:
				system("cls");
				do {
					MenuBalancoEspecificoPessoaBarberEstatistica();
					subOpBarber = ObtemInteiroValidoEstatistica(subOpBarber);
					switch(subOpBarber)
					{
						case 1:
							system("cls");
							t = 0;
							printf("\nBALANCO FINANCEIRO DO BARBER\n");
							printf("----------------------------\n\n\n\n");

							
							acumulador_PrecoTotalCorteSocial = 0;
							acumulador_PrecoTotalCorteDegrade = 0;
							acumulador_PrecoTotalBarba = 0;
							
							qtdeCorteSocial = 0;
							qtdeCorteDegrade = 0;
							qtdeBarba = 0;

							system("cls");
							printf("\n");
								
							printf("Informe o ID do barber: ");	
							id = ObtemInteiroValidoEstatistica(id);

							t = 0;
							atendimento_inicial = 0;
							atendimento_final = y - 1;
								
							if (y == 0) {
								printf("Nenhum atendimento registrado.\n");
								break;
							}

							total_venda_geral = 0.0;
								
							for(int i = 0; i < y; i++)
							{	
								if(i == atendimento_inicial)
								{
									mes_inicial = pnt_recibo[i].data_hora_atendimento.tm_mon;
									ano_inicial = pnt_recibo[i].data_hora_atendimento.tm_year;
								}						
								
								else if(i == atendimento_final)
								{
									mes_final = pnt_recibo[i].data_hora_atendimento.tm_mon;
									ano_final = pnt_recibo[i].data_hora_atendimento.tm_year;
								}					
					
								if(id == pnt_recibo[i].idBarber
								&& pnt_recibo[i].pagamento_fidelidade != 1)	
								{		
									strcpy(nome, pnt_recibo[i].nomeBarber); 
									
									if(strcmp(corteSocial, pnt_recibo[i].descricao) == 0)
									{
										acumulador_PrecoTotalCorteSocial += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										qtdeCorteSocial++;
										codCorteSocial = pnt_recibo[i].codigo;
									}
									
									else if(strcmp(corteDegrade, pnt_recibo[i].descricao) == 0)
									{
										acumulador_PrecoTotalCorteDegrade += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										qtdeCorteDegrade++;
										codCorteDegrade = pnt_recibo[i].codigo;
									}
									
									else if(strcmp(barba, pnt_recibo[i].descricao) == 0)
									{
										acumulador_PrecoTotalBarba += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										qtdeBarba++;
										codBarba = pnt_recibo[i].codigo;
									}
								}
							}	
				
							//Convertendo valores float para centavos, para evitar falhas de arredondamento	
							precoTotalCorteSocial_reais = acumulador_PrecoTotalCorteSocial / 100;
							precoTotalCorteSocial_centavos = llabs(acumulador_PrecoTotalCorteSocial % 100);
			
							precoTotalCorteDegrade_reais = acumulador_PrecoTotalCorteDegrade / 100;
							precoTotalCorteDegrade_centavos = llabs(acumulador_PrecoTotalCorteDegrade % 100);

							precoTotalBarba_reais = acumulador_PrecoTotalBarba / 100;
							precoTotalBarba_centavos = llabs(acumulador_PrecoTotalBarba % 100);

							venda_reais = precoTotalCorteSocial_reais + precoTotalCorteDegrade_reais;
							venda_centavos = precoTotalCorteSocial_centavos + precoTotalCorteDegrade_centavos;
									
							printf("\n");
							printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                        **BALANCO ESPECIFICO POR BARBER**                                       ║\n");
							printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
							printf("║ ID  │             NOME DO BARBER              │ COD │       DESCRICAO DO SERVIÇO       │ QTDE │      VALOR     ║\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
						
							printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%41s\x1b[0m│\x1b[36m%5d\x1b[0m│\x1b[36m%34s\x1b[0m│\x1b[36m%6d\x1b[0m│   \x1b[36m%10lld.%02lld\x1b[0m║\n",
											id,
											nome,
											codCorteSocial,
											corteSocial,
											qtdeCorteSocial,
											(long long)precoTotalCorteSocial_reais,
											(long long)precoTotalCorteSocial_centavos);

							printf("║     │                                         │%5d│%34s│%6d│   %10lld.%02lld║\n",
											codCorteDegrade,
											corteDegrade,
											qtdeCorteDegrade, 
											(long long)precoTotalCorteDegrade_reais, 
											(long long)precoTotalCorteDegrade_centavos);

							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("║                                               │ PERIODO INICIAL │  PERIODO FINAL  │         VALOR FINAL        ║\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("║                                               │          %02d/%04d│          %02d/%04d│            \x1b[36m%13lld.%02lld\x1b[0m║\n",
												mes_inicial,
												ano_inicial,
												mes_final,
												ano_final,
												(long long)venda_reais,
												(long long)venda_centavos);
												
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
							printf("CALCULO CONCLUIDO\n\n");
									
							op = -1;
								
							printf("Aperte qualquer tecla para voltar ao MENU...\n\n");
							system("pause > nul");
							system("cls");	
								
						break;	
						case 2:
							system("cls");
							t = 0;
							printf("\nBALANCO DIARIO DO BARBER\n");
							printf("------------------------\n\n\n\n");
							
							do{
								
								printf("Informe o ID do barber: ");
								id = ObtemInteiroValidoEstatistica(dia);

								printf("\nInforme a DATA do balanco: \n\n");
								printf("DIA: ");
								dia = ObtemInteiroValidoEstatistica(dia);
								printf("MES: ");
								mes = ObtemInteiroValidoEstatistica(mes);
								printf("ANO: ");
								ano = ObtemInteiroValidoEstatistica(ano);
								printf("\n");
									
								if(!dataValida(dia, mes, ano))
								{
									system("cls");
									printf("\nBALANCO DIARIO DO BARBER\n");
									printf("------------------------\n\n");
									printf("\a\033[31mData invalida! Tente novamente.\033[0m\n\n");
								}

							}while(!dataValidaEstatistica(dia, mes, ano));
							
							acumulador_PrecoTotalCorteSocial = 0;
							acumulador_PrecoTotalCorteDegrade = 0;
							acumulador_PrecoTotalBarba = 0;
							
							qtdeCorteSocial = 0;
							qtdeCorteDegrade = 0;
							qtdeBarba = 0;

							system("cls");
							printf("\n");

							t = 0;
								
							if (y == 0) {
								printf("Nenhum atendimento registrado.\n");
								break;
							}
								
							for(int i = 0; i < y; i++)
							{			
								if(id == pnt_recibo[i].idBarber
								&& dia == pnt_recibo[i].data_hora_atendimento.tm_mday 
								&& mes == pnt_recibo[i].data_hora_atendimento.tm_mon
								&& ano == pnt_recibo[i].data_hora_atendimento.tm_year
								&& dataValidaEstatistica(dia, mes, ano) == 1
								&& pnt_recibo[i].pagamento_fidelidade != 1)	
								{		
									strcpy(nome, pnt_recibo[i].nomeBarber); 
									
									if(strcmp(corteSocial, pnt_recibo[i].descricao) == 0)
									{
										acumulador_PrecoTotalCorteSocial += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										qtdeCorteSocial++;
										codCorteSocial = pnt_recibo[i].codigo;
									}
									
									else if(strcmp(corteDegrade, pnt_recibo[i].descricao) == 0)
									{
										acumulador_PrecoTotalCorteDegrade += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										qtdeCorteDegrade++;
										codCorteDegrade = pnt_recibo[i].codigo;
									}
									
									else if(strcmp(barba, pnt_recibo[i].descricao) == 0)
									{
										acumulador_PrecoTotalBarba += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										qtdeBarba++;
										codBarba = pnt_recibo[i].codigo;
									}
								}
							}	
				
							//Convertendo valores float para centavos, para evitar falhas de arredondamento	
							precoTotalCorteSocial_reais = acumulador_PrecoTotalCorteSocial / 100;
							precoTotalCorteSocial_centavos = llabs(acumulador_PrecoTotalCorteSocial % 100);
			
							precoTotalCorteDegrade_reais = acumulador_PrecoTotalCorteDegrade / 100;
							precoTotalCorteDegrade_centavos = llabs(acumulador_PrecoTotalCorteDegrade % 100);

							precoTotalBarba_reais = acumulador_PrecoTotalBarba / 100;
							precoTotalBarba_centavos = llabs(acumulador_PrecoTotalBarba % 100);

							venda_reais = precoTotalCorteSocial_reais + precoTotalCorteDegrade_reais;
							venda_centavos = precoTotalCorteSocial_centavos + precoTotalCorteDegrade_centavos;
									
							printf("\n");
							printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                          **BALANCO DIARIO POR BARBER**                                         ║\n");
							printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
							printf("║ ID  │             NOME DO BARBER              │ COD │       DESCRICAO DO SERVICO       │ QTDE │      VALOR     ║\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
						
							printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%41s\x1b[0m│\x1b[36m%5d\x1b[0m│\x1b[36m%34s\x1b[0m│\x1b[36m%6d\x1b[0m│   \x1b[36m%10lld.%02lld\x1b[0m║\n",
											id,
											nome,
											codCorteSocial,
											corteSocial,
											qtdeCorteSocial,
											(long long)precoTotalCorteSocial_reais,
											(long long)precoTotalCorteSocial_centavos);

							printf("║     │                                         │%5d│%34s│%6d│   %10lld.%02lld║\n",
											codCorteDegrade,
											corteDegrade,
											qtdeCorteDegrade, 
											(long long)precoTotalCorteDegrade_reais, 
											(long long)precoTotalCorteDegrade_centavos);

							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("║                                                                 │  DIA DO BALANCO │         VALOR FINAL        ║\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("║                                                                 │       %02d/%02d/%04d│            \x1b[36m%13lld.%02lld\x1b[0m║\n",
												dia,
												mes,
												ano,
												(long long)venda_reais,
												(long long)venda_centavos);
												
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
							printf("CALCULO CONCLUIDO\n\n");
									
							op = -1;
								
							printf("Aperte qualquer tecla para voltar ao MENU...\n\n");
							system("pause > nul");
							system("cls");	
								
						break;
						case 3:
							system("cls");
							t = 0;
							printf("\nBALANCO MENSAL DO BARBER\n");
							printf("------------------------\n\n\n\n");
							
							do{
								
								printf("Informe o ID do barber: ");
								id = ObtemInteiroValidoEstatistica(dia);

								printf("\nInforme o MES do balanco: \n\n");
								
								printf("MES: ");
								mes = ObtemInteiroValidoEstatistica(mes);
								printf("ANO: ");
								ano = ObtemInteiroValidoEstatistica(ano);
								printf("\n");
									
								if(!mesValidaEstatistica(mes, ano))
								{
									system("cls");
									printf("\nBALAnCO MENSAL DO BARBER\n");
									printf("------------------------\n\n");
									printf("\a\033[31mMes invalido! Tente novamente.\033[0m\n\n");
								}

							}while(!mesValidaEstatistica(mes, ano));
							
							acumulador_PrecoTotalCorteSocial = 0;
							acumulador_PrecoTotalCorteDegrade = 0;
							acumulador_PrecoTotalBarba = 0;
							
							qtdeCorteSocial = 0;
							qtdeCorteDegrade = 0;
							qtdeBarba = 0;

							system("cls");
							printf("\n");

							t = 0;
								
							if (y == 0) {
								printf("Nenhum atendimento registrado.\n");
								break;
							}
								
							for(int i = 0; i < y; i++)
							{			
								if(id == pnt_recibo[i].idBarber
								&& mes == pnt_recibo[i].data_hora_atendimento.tm_mon
								&& ano == pnt_recibo[i].data_hora_atendimento.tm_year
								&& mesValidaEstatistica(mes, ano) == 1
								&& pnt_recibo[i].pagamento_fidelidade != 1)	
								{		
									strcpy(nome, pnt_recibo[i].nomeBarber); 
									
									if(strcmp(corteSocial, pnt_recibo[i].descricao) == 0)
									{
										acumulador_PrecoTotalCorteSocial += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										qtdeCorteSocial++;
										codCorteSocial = pnt_recibo[i].codigo;
									}
									
									else if(strcmp(corteDegrade, pnt_recibo[i].descricao) == 0)
									{
										acumulador_PrecoTotalCorteDegrade += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										qtdeCorteDegrade++;
										codCorteDegrade = pnt_recibo[i].codigo;
									}
									
									else if(strcmp(barba, pnt_recibo[i].descricao) == 0)
									{
										acumulador_PrecoTotalBarba += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										qtdeBarba++;
										codBarba = pnt_recibo[i].codigo;
									}
								}
							}	
				
							//Convertendo valores float para centavos, para evitar falhas de arredondamento	
							precoTotalCorteSocial_reais = acumulador_PrecoTotalCorteSocial / 100;
							precoTotalCorteSocial_centavos = llabs(acumulador_PrecoTotalCorteSocial % 100);
			
							precoTotalCorteDegrade_reais = acumulador_PrecoTotalCorteDegrade / 100;
							precoTotalCorteDegrade_centavos = llabs(acumulador_PrecoTotalCorteDegrade % 100);

							precoTotalBarba_reais = acumulador_PrecoTotalBarba / 100;
							precoTotalBarba_centavos = llabs(acumulador_PrecoTotalBarba % 100);

							venda_reais = precoTotalCorteSocial_reais + precoTotalCorteDegrade_reais;
							venda_centavos = precoTotalCorteSocial_centavos + precoTotalCorteDegrade_centavos;
									
							printf("\n");
							printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                          **BALANCO MENSAL POR BARBER**                                         ║\n");
							printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
							printf("║ ID  │             NOME DO BARBER              │ COD │       DESCRICAO DO SERVICO       │ QTDE │      VALOR     ║\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
						
							printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%41s\x1b[0m│\x1b[36m%5d\x1b[0m│\x1b[36m%34s\x1b[0m│\x1b[36m%6d\x1b[0m│   \x1b[36m%10lld.%02lld\x1b[0m║\n",
											id,
											nome,
											codCorteSocial,
											corteSocial,
											qtdeCorteSocial,
											(long long)precoTotalCorteSocial_reais,
											(long long)precoTotalCorteSocial_centavos);

							printf("║     │                                         │%5d│%34s│%6d│   %10lld.%02lld║\n",
											codCorteDegrade,
											corteDegrade,
											qtdeCorteDegrade, 
											(long long)precoTotalCorteDegrade_reais, 
											(long long)precoTotalCorteDegrade_centavos);

							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("║                                                                 │  MES DO BALANCO │         VALOR FINAL        ║\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("║                                                                 │          %02d/%04d│            \x1b[36m%13lld.%02lld\x1b[0m║\n",
												
												mes,
												ano,
												(long long)venda_reais,
												(long long)venda_centavos);
												
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
							printf("CALCULO CONCLUIDO\n\n");
									
							op = -1;
								
							printf("Aperte qualquer tecla para voltar ao MENU...\n\n");
							system("pause > nul");
							system("cls");	
								
						break;
						case 4:
							system("cls");
							t = 0;
							printf("\nBALANCO ANUAL DO BARBER\n");
							printf("-----------------------\n\n\n\n");
							
							do{
								
								printf("Informe o ID do barber: ");
								id = ObtemInteiroValidoEstatistica(dia);

								printf("\nInforme o ANO do balanco: \n\n");
								
								printf("ANO: ");
								ano = ObtemInteiroValidoEstatistica(ano);
								printf("\n");
									
								if(ano < 0)
								{
									system("cls");
									printf("\nBALANCO ANUAL DO BARBER\n");
									printf("-----------------------\n\n");
									printf("\a\033[31mAno invalido! Tente novamente.\033[0m\n\n");
								}

							}while(ano < 0);
							
							acumulador_PrecoTotalCorteSocial = 0;
							acumulador_PrecoTotalCorteDegrade = 0;
							acumulador_PrecoTotalBarba = 0;
							
							qtdeCorteSocial = 0;
							qtdeCorteDegrade = 0;
							qtdeBarba = 0;

							system("cls");
							printf("\n");

							t = 0;
								
							if (y == 0) {
								printf("Nenhum atendimento registrado.\n");
								break;
							}
								
							for(int i = 0; i < y; i++)
							{			
								if(id == pnt_recibo[i].idBarber
								&& ano == pnt_recibo[i].data_hora_atendimento.tm_year
								&& pnt_recibo[i].pagamento_fidelidade != 1)	
								{		
									strcpy(nome, pnt_recibo[i].nomeBarber); 
									
									if(strcmp(corteSocial, pnt_recibo[i].descricao) == 0)
									{
										acumulador_PrecoTotalCorteSocial += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										qtdeCorteSocial++;
										codCorteSocial = pnt_recibo[i].codigo;
									}
									
									else if(strcmp(corteDegrade, pnt_recibo[i].descricao) == 0)
									{
										acumulador_PrecoTotalCorteDegrade += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										qtdeCorteDegrade++;
										codCorteDegrade = pnt_recibo[i].codigo;
									}
									
									else if(strcmp(barba, pnt_recibo[i].descricao) == 0)
									{
										acumulador_PrecoTotalBarba += (int64_t) llround(pnt_recibo[i].preco_total * 100.0);
										qtdeBarba++;
										codBarba = pnt_recibo[i].codigo;
									}
								}
							}	
				
							//Convertendo valores float para centavos, para evitar falhas de arredondamento	
							precoTotalCorteSocial_reais = acumulador_PrecoTotalCorteSocial / 100;
							precoTotalCorteSocial_centavos = llabs(acumulador_PrecoTotalCorteSocial % 100);
			
							precoTotalCorteDegrade_reais = acumulador_PrecoTotalCorteDegrade / 100;
							precoTotalCorteDegrade_centavos = llabs(acumulador_PrecoTotalCorteDegrade % 100);

							precoTotalBarba_reais = acumulador_PrecoTotalBarba / 100;
							precoTotalBarba_centavos = llabs(acumulador_PrecoTotalBarba % 100);

							venda_reais = precoTotalCorteSocial_reais + precoTotalCorteDegrade_reais;
							venda_centavos = precoTotalCorteSocial_centavos + precoTotalCorteDegrade_centavos;
									
							printf("\n");
							printf("╔════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
							printf("║                                           **BALANCO ANUAL POR BARBER**                                         ║\n");
							printf("╠════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
							printf("║ ID  │             NOME DO BARBER              │ COD │       DESCRICAO DO SERVICO       │ QTDE │      VALOR     ║\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
						
							printf("║\x1b[36m%5d\x1b[0m│\x1b[36m%41s\x1b[0m│\x1b[36m%5d\x1b[0m│\x1b[36m%34s\x1b[0m│\x1b[36m%6d\x1b[0m│   \x1b[36m%10lld.%02lld\x1b[0m║\n",
											id,
											nome,
											codCorteSocial,
											corteSocial,
											qtdeCorteSocial,
											(long long)precoTotalCorteSocial_reais,
											(long long)precoTotalCorteSocial_centavos);

							printf("║     │                                         │%5d│%34s│%6d│   %10lld.%02lld║\n",
											codCorteDegrade,
											corteDegrade,
											qtdeCorteDegrade, 
											(long long)precoTotalCorteDegrade_reais, 
											(long long)precoTotalCorteDegrade_centavos);

							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("║                                                                 │  ANO DO BALANCO │         VALOR FINAL        ║\n");
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("║                                                                 │             %04d│            \x1b[36m%13lld.%02lld\x1b[0m║\n",
												ano,
												(long long)venda_reais,
												(long long)venda_centavos);
												
							printf("╟────────────────────────────────────────────────────────────────────────────────────────────────────────────────╢\n");
							printf("╚════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");
							printf("CALCULO CONCLUIDO\n\n");
									
							op = -1;
								
							printf("Aperte qualquer tecla para voltar ao MENU...\n\n");
							system("pause > nul");
							system("cls");	
								
						break;
						case 0:
							system("cls");
						break;
						default:
							printf("\nDigite uma opcao valida\n\n");						
					}	
				}while(subOpBarber != 0);
			
			break;
			case 0:
				system("cls");
			break;
			default:
				printf("\nDigite uma opcao valida\n\n");	
		}		
	}while(op != 0);
}
