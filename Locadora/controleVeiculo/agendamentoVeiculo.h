#ifndef AGENDAMENTO_VEICULO_H
#define AGENDAMENTO_VEICULO_H

int verificaPosicaoAgendamento();
int retornaPosicaoPessoa(int codigo);
void excluirAgendamento();

/*==================================================================================*/
/*								AGENDAMENTO DE VEICULO 								*/
/*==================================================================================*/
// inserir veiculo na lista
void inserirAgendamento(int OptMarca, int OptModelo){    
	limpaTela(); //limpa a tela
	char resp;
	int retorno, retPosVeic, posicao, codigoPosicao, posicaoLocacao, cliente;
	
	posicao = verificaPosicaoAgendamento();
	retPosVeic = retornaPosicaoVeiculoEscolhido(OptMarca - 1, OptModelo - 1 );
	posicaoLocacao = retornaPosicaoLocacao(OptMarca - 1, OptModelo - 1);

	retornaDataHoraAtual(posicao);
	
	tlAgendamentoVeiculo += 1;
	
		
	strcpy(agendamentoVeiculo[posicao].marca, cadVeiculo[retPosVeic].marca);
	strcpy(agendamentoVeiculo[posicao].modelo, cadVeiculo[retPosVeic].modeloVec);
	agendamentoVeiculo[posicao].posicaoMarcaVeiculo = OptMarca - 1;
	agendamentoVeiculo[posicao].posicaoModeloveiculo = OptModelo - 1;
	agendamentoVeiculo[posicao].ano = cadVeiculo[retPosVeic].ano;
	
	agendamentoVeiculo[posicao].status = 2;
	Locacao[posicaoLocacao].status = 2;
	cadVeiculo[retPosVeic].status = 2;
	
	strcpy(agendamentoVeiculo[posicao].placaVeiculo, cadVeiculo[retPosVeic].placaVeiculo);
	strcpy(agendamentoVeiculo[posicao].dataRetirar, Locacao[posicaoLocacao].dataFimLocacao);
	agendamentoVeiculo[posicao].vlrDiaria = cadVeiculo[retPosVeic].vlrDiaria;
	strcpy(agendamentoVeiculo[posicao].corVeiculo, cadVeiculo[retPosVeic].corVeiculo);
		
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                      Agendamento de Veículo                           *");
	printf("\n\t*****************************************************************************************\n");
	
	printf("\n\tCódigo do cadastro:  %d \n", tlAgendamentoVeiculo);
	agendamentoVeiculo[posicao].cod = tlAgendamentoVeiculo;
	
	consultaPessoa();
	printf("\n\tDigite o código do cliente: ");
	scanf("%d",&cliente);
	limparBuffer();
	limpaTela();
	
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                      Agendamento de Veículo                           *");
	printf("\n\t*****************************************************************************************\n");
	printf("\n\tMarca: %s", agendamentoVeiculo[posicao].marca);
		
	printf("\n\tModelo: %s", agendamentoVeiculo[posicao].modelo);
	
	printf("\tPlaca: %s", agendamentoVeiculo[posicao].placaVeiculo);
	
	printf("\n\tAno: %d", agendamentoVeiculo[posicao].ano );
		
	printf("\tCor: %s", agendamentoVeiculo[posicao].corVeiculo);
	printf("\tValor diaria: %3.2f", cadVeiculo[retPosVeic].vlrDiaria);
	
	printf("\n\tData agendamento: %s",agendamentoVeiculo[posicao].dataAgendamento);
	printf("\n\tData à retirar: %s", agendamentoVeiculo[posicao].dataRetirar);
	
	codigoPosicao = retornaPosicaoPessoa(cliente);
	
	if(codigoPosicao < 0){
		printf("\n\n\tCliente não cadastrado!!");
	}else{
	
		printf("\n\n\tNome: %s", pessoa[codigoPosicao].nome );
		
		strcpy(agendamentoVeiculo[posicao].nomeCliente, pessoa[codigoPosicao].nome);
		
		printf("\tCPF: %s\n", pessoa[codigoPosicao].cpf);
		
		strcpy(agendamentoVeiculo[posicao].cpf, pessoa[codigoPosicao].cpf);
		
		confirmarAgendamento:
		printf("\n\tConfirma agendamento? S/N ");
		fflush(stdin);
		scanf("%c", &resp);
		
		if ( ( resp == 'N' ) || ( resp == 'n' ) )
	    {
	    	agendamentoVeiculo[posicao].cod = 0;
			strcpy(agendamentoVeiculo[posicao].marca			, "");
			strcpy(agendamentoVeiculo[posicao].modelo			, "");
			agendamentoVeiculo[posicao].posicaoMarcaVeiculo 	= 0;
			agendamentoVeiculo[posicao].posicaoModeloveiculo 	= 0;
			agendamentoVeiculo[posicao].status 					= 0;
			strcpy(agendamentoVeiculo[posicao].placaVeiculo		, "");
			agendamentoVeiculo[posicao].ano 					= 0;
			strcpy(agendamentoVeiculo[posicao].marca			, "");
			strcpy(agendamentoVeiculo[posicao].dataAgendamento	, "");
			strcpy(agendamentoVeiculo[posicao].dataRetirar		, "");
			strcpy(agendamentoVeiculo[posicao].nomeCliente		, "");
			strcpy(agendamentoVeiculo[posicao].cpf				, "");
			agendamentoVeiculo[posicao].status 					= 0;
			cadVeiculo[retPosVeic].status 						= 1;
			printf("\n\tCancelado agendamento. ");
		}else if ( ( resp == 'S' ) || ( resp == 's' ) )
	    {
	    	limpaTela();
	    	printf("\n\n\t*****************************************************************************************\n");
			printf("\t*                                      Agendamento Concluído                            *");
			printf("\n\t*****************************************************************************************\n");
			printf("\n\t*****************************************************************************************\n");
			printf("\t*                                              RECIBO                                   *");
			printf("\n\t*****************************************************************************************\n");
			
			printf("\n\tCódigo do cadastro:  %d \n", tlAgendamentoVeiculo);
			
			printf("\n\tData agendamento: %s", agendamentoVeiculo[posicao].dataAgendamento);
			printf("\n\tData a retirar: %s", agendamentoVeiculo[posicao].dataRetirar);
			printf("\n\n\tNome Cliente: %s", agendamentoVeiculo[posicao].nomeCliente);
			printf("\tCPF: %s", agendamentoVeiculo[posicao].cpf);
			printf("\n\n\tMarca: %s", agendamentoVeiculo[posicao].marca);
			printf("\n\tModelo: %s", agendamentoVeiculo[posicao].modelo);
			printf("\tPlaca: %s", agendamentoVeiculo[posicao].placaVeiculo);
			printf("\n\tAno: %d", agendamentoVeiculo[posicao].ano );
			printf("\tCor: %s", agendamentoVeiculo[posicao].corVeiculo);
			printf("\tValor diária: %3.2f", cadVeiculo[retPosVeic].vlrDiaria);
			printf("\n\n\tConfirmado agendamento.");
		}else{
			goto confirmarAgendamento;
		}
	}
	printf("\n\n\tPressione entrer para continuar. ");
	limparBuffer();
}

void consultarAgendamento(){
	int contador = 0, codigo, retPosVeic;
	
	retPosVeic = retornaPosicaoVeiculoEscolhido(agendamentoVeiculo[contador].posicaoMarcaVeiculo, agendamentoVeiculo[contador].posicaoModeloveiculo );
	
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                    Consulta de Agendamento                            *");
	printf("\n\t*****************************************************************************************\n");
	printf("\n\tEntre com o código => ");
    scanf("%d",&codigo);
	limparBuffer();
	
	if (tlAgendamentoVeiculo > 0){
		while ( contador <= tlAgendamentoVeiculo ){

	        if (cadVeiculo[contador].cod == codigo)
	        {
	          	printf("\n\tCódigo: %d"				, agendamentoVeiculo[contador].cod);
	          	printf("\n\tNome: %s"				, agendamentoVeiculo[contador].nomeCliente);
	          	printf("\n\tCPF: %s"				, agendamentoVeiculo[contador].cpf);
				printf("\n\tMarca: %s"				, agendamentoVeiculo[contador].marca);
				printf("\n\tModelo: %s"				, agendamentoVeiculo[contador].modelo);
				printf("\n\tPlaca: %s"				, agendamentoVeiculo[contador].placaVeiculo);
				printf("\n\tAno: %d"				, agendamentoVeiculo[contador].ano);
				printf("\n\tCor: %s"				, agendamentoVeiculo[contador].corVeiculo);
				printf("\n\tValor: %3.2f\n"			, agendamentoVeiculo[contador].vlrDiaria);
				printf("\n\tData agendamento: %s"	, agendamentoVeiculo[contador].dataAgendamento);
				printf("\n\tData a retirar: %s"		, agendamentoVeiculo[contador].dataRetirar);
				
				if(cadVeiculo[retPosVeic].status == 0){
					printf("\n\tSituação: Livre\n\n");
				}else if(cadVeiculo[retPosVeic].status == 1){
					printf("\n\tSituação: Alugado\n\n");
				}else{
					printf("\n\tSituação: Agendado\n\n");
				}
			}
			contador++;
		}
		printf("\n\t================================== Fim de registro! =====================================\n\n");
	
	}else{
		printf("\n\t============================== Não existe registo cadastrado! ===========================\n\n");
	}
    
	printf("\n\tPressione entrer para continuar. ");
	limparBuffer();
}

void listarAgendamento(){
	int contador = 0, codigo, retPosVeic, contaLinha = 15;
	
	retPosVeic = retornaPosicaoVeiculoEscolhido(agendamentoVeiculo[contador].posicaoMarcaVeiculo, agendamentoVeiculo[contador].posicaoModeloveiculo );
	
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                    Lista  de Agendamento                              *");
	printf("\n\t*****************************************************************************************\n");
	
	if (tlAgendamentoVeiculo > 0){
		while ( contador <= tlAgendamentoVeiculo - 1 ){
	
          	printf("\n\tCódigo: %d",       agendamentoVeiculo[contador].cod);
          	printf("\n\tNome: %s",    	agendamentoVeiculo[contador].nomeCliente);
          	printf("\n\tCPF: %s",    	agendamentoVeiculo[contador].cpf);
			printf("\n\tMarca: %s",     agendamentoVeiculo[contador].marca);
			printf("\n\tModelo: %s",    agendamentoVeiculo[contador].modelo);
			printf("\n\tPlaca: %s",     agendamentoVeiculo[contador].placaVeiculo);
			printf("\n\tAno: %d",       agendamentoVeiculo[contador].ano);
			printf("\n\tCor: %s",       agendamentoVeiculo[contador].corVeiculo);
			printf("\n\tValor: %3.2f\n",agendamentoVeiculo[contador].vlrDiaria);
			printf("\n\tData agendamento: %s",     agendamentoVeiculo[contador].dataAgendamento);
			printf("\n\tData a retirar: %s"		, agendamentoVeiculo[contador].dataRetirar);
			
			if(cadVeiculo[retPosVeic].status == 0){
				printf("\n\tSituação: Livre\n");
			}else if(cadVeiculo[retPosVeic].status == 1){
				printf("\n\tSituação: Alugado\n");
			}else{
				printf("\n\tSituação: Agendado\n");
			}
			contador++;
			printf("\n\t================================== Fim de registro! =====================================\n");
			
			if(contaLinha == 45){
				printf("\n\tPressione entrer para continuar. ");
				limparBuffer();
				contaLinha = 15;
			}
			
			contaLinha += 15;
		}
	}
	printf("\n\t=============================== Fim de todos os registro! ===============================\n");
	printf("\n\tPressione entrer para continuar. ");
	limparBuffer();
}

void alterarAgendamento(){
	int opcao, contador = 0, codigo, retPosVeic;
	
	retPosVeic = retornaPosicaoVeiculoEscolhido(agendamentoVeiculo[contador].posicaoMarcaVeiculo, agendamentoVeiculo[contador].posicaoModeloveiculo );
	
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                      Alterar Agendamento                              *");
	printf("\n\t*****************************************************************************************\n");
	printf("\n\tEntre com o código a ser alterado => ");
    scanf("%d",&codigo);
	limparBuffer();
	
	if (tlAgendamentoVeiculo > 0){
		while ( contador <= tlAgendamentoVeiculo ){

	        if (agendamentoVeiculo[contador].cod == codigo)
	        {
	        	while(opcao != 11){
					
					limpaTela(); // limpa tela
					printf("\n\n\t*****************************************************************************************\n");
					printf("\t*                                      Alterar Agendamento                              *");
					printf("\n\t*****************************************************************************************\n");
					    
		          	printf("\n\t Códdigo: %d"				, agendamentoVeiculo[contador].cod);
		          	printf("\n\t[ 1] Nome: %s"				, agendamentoVeiculo[contador].nomeCliente);
		          	printf("\n\t[ 2] CPF: %s"				, agendamentoVeiculo[contador].cpf);
					printf("\n\t[ 3] Marca: %s"				, agendamentoVeiculo[contador].marca);
					printf("\n\t[ 4] Modelo: %s"			, agendamentoVeiculo[contador].modelo);
					printf("\n\t[ 5] Placa: %s"				, agendamentoVeiculo[contador].placaVeiculo);
					printf("\n\t[ 6] Ano: %d"				, agendamentoVeiculo[contador].ano);
					printf("\n\t[ 7] Cor: %s"				, agendamentoVeiculo[contador].corVeiculo);
					printf("\n\t[ 8] Valor: %3.2f"			, agendamentoVeiculo[contador].vlrDiaria);
					printf("\n\t[ 9] Data agendamento: %s"	, agendamentoVeiculo[contador].dataAgendamento);
					printf("\n\t[10] Data a retirar: %s"	, agendamentoVeiculo[contador].dataRetirar);
					
					if(cadVeiculo[retPosVeic].status == 0){
						printf("\n\t[  ] Situação: Livre\n\n");
					}else if(cadVeiculo[retPosVeic].status == 1){
						printf("\n\t[  ] Situação: Alugado\n\n");
					}else{
						printf("\n\t[  ] Situação: Agendado\n\n");
					}
					
					printf("\n\t[11] Sair e Salvar!");
					
					printf("\n\n\tQual campo deseja alterar? => ");
					fflush(stdin);
					scanf("%d" , &opcao);
					
					switch(opcao){
						case 1:
							printf("\n\tNome: " );
							fflush(stdin);
							gets(agendamentoVeiculo[contador].nomeCliente);
							break;
						case 2:
							printf("\n\tCPF: ");
							scanf("%s", &agendamentoVeiculo[contador].cpf);
							limparBuffer();
							break;
						case 3:
							printf("\n\tMarca: ");
							fflush(stdin);
							gets(agendamentoVeiculo[contador].marca);
							break;
						case 4:
							printf("\n\tModelo: ");
							fflush(stdin);
							gets( agendamentoVeiculo[contador].modelo);
							break;
							
						case 5:
							printf("\n\tPlaca: " );
							fflush(stdin);
							gets(agendamentoVeiculo[contador].placaVeiculo);
							break;
						case 6:
							printf("\n\tAno: " );
							scanf("%d" , &agendamentoVeiculo[contador].ano);
							limparBuffer();
							break;
						case 7:
							printf("\n\tCor: ");
							fflush(stdin);
							gets(agendamentoVeiculo[contador].corVeiculo);
							break;
						case 8:
							printf("\n\tValor diaria: ");
							scanf("%f", &agendamentoVeiculo[contador].vlrDiaria);
							limparBuffer();
							break;
						case 9:
							printf("\n\tData agendamento: ");
							fflush(stdin);
							gets(agendamentoVeiculo[contador].dataAgendamento);
							break;
						case 10:
							printf("\n\tData a retirar: ");
							fflush(stdin);
							gets(agendamentoVeiculo[contador].dataRetirar);
							break;
						case 11:
							printf("\n\tDados salvo com sucesso!");	
							sleep(1);
							break;
						default:
							opcaoInvalida();
							printf("\n\tOpção inválida!\n\n");
							sleep(1);
							break;
							
					}//fim do switch
				}// fim do while
			}// fim do if
			contador++;
		}// fim do segundo while
		printf("\n\t================================== Fim de registro! =====================================\n");
			
	}else{
		printf("\n\t=============================== Fim de todos os registro! ===============================\n");
	}
    
	printf("\n\tPressione entrer para continuar. ");
	limparBuffer();
}

void encerrarAgendamento(){
	int contador = 0, cod, retPosVeic;
	char locarAgendamento;
	
	retPosVeic = retornaPosicaoVeiculoEscolhido(agendamentoVeiculo[contador].posicaoMarcaVeiculo, agendamentoVeiculo[contador].posicaoModeloveiculo );
		
	limpaTela(); //limpa a tela
    
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                      Encerrar Agendamento                             *");
	printf("\n\t*****************************************************************************************\n");
	printf("\n\tEntre com o código => ");
    scanf("%d",&cod);
	limparBuffer();
	
	while ( contador <= tlAgendamentoVeiculo )
    {
    	if (agendamentoVeiculo[contador].cod == cod )
        {
	    	printf("\n\tCódigo: %d"				, agendamentoVeiculo[contador].cod);
          	printf("\n\tNome: %s"				, agendamentoVeiculo[contador].nomeCliente);
          	printf("\n\tCPF: %s"				, agendamentoVeiculo[contador].cpf);
			printf("\n\tMarca: %s"				, agendamentoVeiculo[contador].marca);
			printf("\n\tModelo: %s"				, agendamentoVeiculo[contador].modelo);
			printf("\n\tPlaca: %s"				, agendamentoVeiculo[contador].placaVeiculo);
			printf("\n\tAno: %d"				, agendamentoVeiculo[contador].ano);
			printf("\n\tCor: %s"				, agendamentoVeiculo[contador].corVeiculo);
			printf("\n\tValor: %3.2f\n"			, agendamentoVeiculo[contador].vlrDiaria);
			printf("\n\tData agendamento: %s"	, agendamentoVeiculo[contador].dataAgendamento);
			printf("\n\tData a retirar: %s"		, agendamentoVeiculo[contador].dataRetirar);
			
			if(cadVeiculo[retPosVeic].status == 0){
				printf("\n\tSituação: Livre\n\n");
			}else if(cadVeiculo[retPosVeic].status == 1){
				printf("\n\tSituação: Alugado\n\n");
			}else{
				printf("\n\tSituação: Agendado\n\n");
			}
			
			printf("\n\tLocar o veículo agendado: S/N "); 
			scanf("%c", &locarAgendamento );
			fflush(stdin);
			
			if ( ( locarAgendamento == 'S' ) || ( locarAgendamento == 's' ) ){
				limpaTela(); //limpa a tela
				agendamentoVeiculo[contador].status = 0;
				cadVeiculo[retPosVeic].status == 1;
				
				inserirLocacaoLista(agendamentoVeiculo[contador].posicaoMarcaVeiculo + 1, agendamentoVeiculo[contador].posicaoModeloveiculo + 1);
				
				limpaTela();
	
				printf("\n\n\t*****************************************************************************************\n");
				printf("\t*                                      Agendamento Finalizada                           *");
				printf("\n\t*****************************************************************************************\n");
				printf("\n\n\t*****************************************************************************************\n");
				printf("\t*                                      Recibo de Agendamento                            *");
				printf("\n\t*****************************************************************************************\n");
				
				printf("\n\tCódigo: %d"				, agendamentoVeiculo[contador].cod);
	          	printf("\n\tNome: %s"				, agendamentoVeiculo[contador].nomeCliente);
	          	printf("\n\tCPF: %s"				, agendamentoVeiculo[contador].cpf);
				printf("\n\tMarca: %s"				, agendamentoVeiculo[contador].marca);
				printf("\n\tModelo: %s"				, agendamentoVeiculo[contador].modelo);
				printf("\n\tPlaca: %s"				, agendamentoVeiculo[contador].placaVeiculo);
				printf("\n\tAno: %d"				, agendamentoVeiculo[contador].ano);
				printf("\n\tCor: %s"				, agendamentoVeiculo[contador].corVeiculo);
				printf("\n\tValor: %3.2f\n"			, agendamentoVeiculo[contador].vlrDiaria);
				printf("\n\tData agendamento: %s"	, agendamentoVeiculo[contador].dataAgendamento);
				printf("\n\tData a retirar: %s"		, agendamentoVeiculo[contador].dataRetirar);
			
				printf("\n\n\tO veiculo %s foi alugado com sucesso!\n\n", agendamentoVeiculo[contador].marca);
				
			}else{
				printf("\n\n\t*****************************************************************************************\n");
				printf("\t*                                      Agendamento Cancelada                            *");
				printf("\n\t*****************************************************************************************\n");
			}
			
		}
		contador++;
	}
	printf("\n\t================================== Fim de registro! =====================================\n");
		
	printf("\n\tPressione entrer para continuar. ");
	limparBuffer();
}

void excluirAgendamento(){
	int contador = 0, codigo, retPosVeic;
	
	retPosVeic = retornaPosicaoVeiculoEscolhido(agendamentoVeiculo[contador].posicaoMarcaVeiculo, agendamentoVeiculo[contador].posicaoModeloveiculo );
	char resp;
	
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                      Excluir de Agendamento                           *");
	printf("\n\t*****************************************************************************************\n");
	printf("\n\tEntre com o código => ");
    scanf("%d",&codigo);
	limparBuffer();
	
	if (tlAgendamentoVeiculo > 0){
		while ( contador <= tlAgendamentoVeiculo ){

	        if (cadVeiculo[contador].cod == codigo)
	        {
	          	printf("\n\tCódigo: %d"				, agendamentoVeiculo[contador].cod);
	          	printf("\n\tNome: %s"				, agendamentoVeiculo[contador].nomeCliente);
	          	printf("\n\tCPF: %s"				, agendamentoVeiculo[contador].cpf);
				printf("\n\tMarca: %s"				, agendamentoVeiculo[contador].marca);
				printf("\n\tModelo: %s"				, agendamentoVeiculo[contador].modelo);
				printf("\n\tPlaca: %s"				, agendamentoVeiculo[contador].placaVeiculo);
				printf("\n\tAno: %d"				, agendamentoVeiculo[contador].ano);
				printf("\n\tCor: %s"				, agendamentoVeiculo[contador].corVeiculo);
				printf("\n\tValor: %3.2f\n"			, agendamentoVeiculo[contador].vlrDiaria);
				printf("\n\tData agendamento: %s"	, agendamentoVeiculo[contador].dataAgendamento);
				printf("\n\tData a retirar: %s"		, agendamentoVeiculo[contador].dataRetirar);
					
				if(cadVeiculo[retPosVeic].status == 0){
					printf("\n\tSituação: Livre\n\n");
				}else if(cadVeiculo[retPosVeic].status == 1){
					printf("\n\tSituação: Alugado\n\n");
				}else{
					printf("\n\tSituação: Agendado\n\n");
				}
				
				printf("\n\tDeseja realmente excluir? s/n: ");
                scanf("%s",&resp);
				fflush(stdin);
				
				if ( ( resp == 'S' ) || ( resp == 's' ) )
                {
                	if( tlAgendamentoVeiculo -1 != 0){
	                     for(int i = contador; i <= tlAgendamentoVeiculo - 1; i++){
	                     	
	                     	agendamentoVeiculo[i].cod        		  		= agendamentoVeiculo[i + 1].cod;
							agendamentoVeiculo[i].ano        		  		= agendamentoVeiculo[i + 1].ano;
							strcpy(agendamentoVeiculo[i].nomeCliente		, agendamentoVeiculo[i + 1].nomeCliente);
							strcpy(agendamentoVeiculo[i].marca				, agendamentoVeiculo[i + 1].marca);
							strcpy(agendamentoVeiculo[i].modelo				, agendamentoVeiculo[i + 1].modelo);
							strcpy(agendamentoVeiculo[i].placaVeiculo		, agendamentoVeiculo[i + 1].placaVeiculo);
							strcpy(agendamentoVeiculo[i].corVeiculo			, agendamentoVeiculo[i + 1].corVeiculo);
							strcpy(agendamentoVeiculo[i].dataAgendamento	, agendamentoVeiculo[i + 1].dataAgendamento);
							strcpy(agendamentoVeiculo[i].dataRetirar		, agendamentoVeiculo[i + 1].dataRetirar);
							agendamentoVeiculo[i].vlrDiaria          		= agendamentoVeiculo[i + 1].vlrDiaria;
							agendamentoVeiculo[i].status	          		= agendamentoVeiculo[i + 1].status;
							cadVeiculo[retPosVeic].status					= 0;
						}
						tlAgendamentoVeiculo--;	
				   }else{
						for(int i = contador; i <= tlAgendamentoVeiculo - 1; i++){
	                     	
	                     	agendamentoVeiculo[i].cod        		  		= 0;
							strcpy(agendamentoVeiculo[i].nomeCliente		, "");
							strcpy(agendamentoVeiculo[i].marca				, "");
							strcpy(agendamentoVeiculo[i].modelo				, "");
							strcpy(agendamentoVeiculo[i].placaVeiculo		, "");
							agendamentoVeiculo[i].ano        		  		= 0;
							strcpy(agendamentoVeiculo[i].corVeiculo			, "");
							agendamentoVeiculo[i].vlrDiaria          		= 0;
							strcpy(agendamentoVeiculo[i].dataAgendamento	, "");
							strcpy(agendamentoVeiculo[i].dataRetirar		, "");
							agendamentoVeiculo[i].status	          		= 0;
							cadVeiculo[retPosVeic].status					= 0;
						
						}
						tlAgendamentoVeiculo--;
					}
				}
				contador++;
			}
		printf("\n\t================================== Fim de registro! =====================================\n");
	}
	}else{
		printf("\n\t============================= Não existe registo cadastrado! ============================\n");
	}
    
	printf("\n\tPressione entrer para continuar. ");
	limparBuffer();
}

int verificaPosicaoAgendamento(){
	int contador = 0;
	
    while ( contador <= SIZE )
    {

        if ( agendamentoVeiculo[contador].cod == 0 )
            return(contador);

        contador++;

    }

    return(-1);
}

// verificar se o veiculo foi agendado
int verificaPosicaoVeiculoAgendado(int OptMarca, int OptModelo){
	int contador = 0;
	
	for (int i = 0; i <= tlVeiculo - 1 ; i++)
    {
        if (  cadVeiculo[i].codMarca == OptMarca && cadVeiculo[i].codModelo == OptModelo ){
        	if(cadVeiculo[i].status == 0)
				return(2);
		}
        contador++;
    }
	contador = 0;
    while ( contador <= tlAgendamentoVeiculo - 1 )
    {
    	if ( agendamentoVeiculo[contador].posicaoMarcaVeiculo == OptMarca && agendamentoVeiculo[contador].posicaoModeloveiculo == OptModelo )
    		if(agendamentoVeiculo[contador].status == 0){
    			return(2);
            }else if(agendamentoVeiculo[contador].status == 2){
    			return(0);
            }
        contador++;
    }

    return(1);
}

/*==================================================================================*/
/*								AGENDAMENTO DE VEICULO	    						*/
/*==================================================================================*/

#endif
