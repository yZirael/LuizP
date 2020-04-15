#ifndef CONTROLE_Locacao_H
#define CONTROLE_Locacao_H

int verificaPosicaoLocacao(void);
int retornaPosicaoVeiculoEscolhido(int marca, int modelo);
int retornaPosicaoPessoa(int codigo);

// inserir Locacao na lista
void inserirLocacaoLista(int OptMarca, int OptModelo){    
		char resp, cpf;
		int retorno, auxQtdeDiaria = 0, retPosVeic, codigoPosicao,cliente;
		
		int posicao = verificaPosicaoLocacao();
		tlLocacao += 1;
		
		retPosVeic = retornaPosicaoVeiculoEscolhido(OptMarca - 1, OptModelo - 1 );
				
		strcpy(Locacao[posicao].veiculoEscolhido, cadVeiculo[retPosVeic].modeloVec);
		Locacao[posicao].posicaoMarcaVeiculo = OptMarca - 1;
		Locacao[posicao].posicaoModeloveiculo = OptModelo - 1;
		Locacao[posicao].status = 1;
		strcpy(Locacao[posicao].placaVeiculo, cadVeiculo[retPosVeic].placaVeiculo);
		
		char vecEscolido[20];
		strcpy(vecEscolido, Locacao[posicao].veiculoEscolhido);
		
		cadVeiculo[retPosVeic].status = 1;
		
		printf("\n\n\t*****************************************************************************************\n");
		printf("\t*                                        Cadastro de Locação                            *");
		printf("\n\t*****************************************************************************************\n");
		
		consultaPessoa();
		printf("\n\tDigite o código do cliente: ");
		scanf("%d",&cliente);
		limparBuffer();
		limpaTela();
		
		printf("\n\n\t*****************************************************************************************\n");
		printf("\t*                                        Cadastro de Locação                            *");
		printf("\n\t*****************************************************************************************\n");
		
		codigoPosicao = retornaPosicaoPessoa(cliente);
	
		if(codigoPosicao < 0){
			printf("\n\n\tCliente não cadastrado!!");
		}else{
			pontoNome:
			
			printf("\n\tCódigo do cadastro:  %d \n", tlLocacao);
			Locacao[posicao].vlrDiaria = cadVeiculo[retPosVeic].vlrDiaria;
			Locacao[posicao].cod = tlLocacao;
		
			printf("\n\tCarro: %s \tValor: %5.2f\n", Locacao[posicao].veiculoEscolhido, cadVeiculo[retPosVeic].vlrDiaria );
			valoresDiaria[OptMarca - 1][OptModelo - 1];
			printf("\n\tNome: %s\n", pessoa[codigoPosicao].nome);
			strcpy(Locacao[posicao].nome, pessoa[codigoPosicao].nome);
			
			printf("\n\tCPF: %s\n", pessoa[codigoPosicao].cpf);
			strcpy(Locacao[posicao].cpf, pessoa[codigoPosicao].cpf);
			
			pontoIdade:
			
			printf("\n\tIdade: %d\n", pessoa[codigoPosicao].idade);
			Locacao[posicao].idade = pessoa[codigoPosicao].idade;
					
			retorno = validaIdade(Locacao[posicao].idade);
			
			if(retorno == 1){
				opcaoInvalida();
				printf("\n\tIndade não pode ser menor que 18  ou maior que 120 !! Tente novamente!!\n");
				goto pontoIdade;
			
			}
			
			pontoParceiro:
			
			printf("\n\tÉ empresas parceira ? 1-Sim | 2-Nao : ");
			scanf("%d", &Locacao[posicao].parceiro);
			limparBuffer();	
					
			if((Locacao[posicao].parceiro < 1) || (Locacao[posicao].parceiro > 2)){
				opcaoInvalida();
				printf("\n\tPor favor, digite 1 ou 2!!\n");
				goto pontoParceiro;
			
			}
					
			pontoQtdDiaria:
			
			printf("\n\tQuantidade de diária de 1 a 10: ");
			scanf("%d", &Locacao[posicao].qtdDiaria);
			limparBuffer();	
					
			if((Locacao[posicao].qtdDiaria < 1) || (Locacao[posicao].qtdDiaria > 10)){
				opcaoInvalida();
				printf("\n\tNão pode ser menor que 0 ou maior que 10!! Tente novamente!!\n");
				goto pontoQtdDiaria;
			
			}else{
				if(Locacao[posicao].qtdDiaria > 4){
					printf("\n\tLocação com direito a uma diária extra!!\n");
					printf("\n\tDeseja utilizar a diária extra? S/N ");
					fflush(stdin);
					scanf("%c", &resp);
					
					if(resp == 's' || resp == 'S'){
						
						auxQtdeDiaria = Locacao[posicao].qtdDiaria + 1;
					}
				}
				
				limpaTela(); //limpa a tela
	
				printf("\n\n\t*****************************************************************************************\n");
				printf("\t*                                        Locação Concluída                              *");
				printf("\n\t*****************************************************************************************\n");
				printf("\n\n\t*****************************************************************************************\n");
				printf("\t*                                        Recibo de Locação                              *");
				printf("\n\t*****************************************************************************************\n");
				
				if (Locacao[posicao].idade >= 60) {
								
					Locacao[posicao].vlrDesconto = 10;
					
				}
				else if (Locacao[posicao].parceiro == 1 ) {
					
					Locacao[posicao].vlrDesconto = 5;
					
				}
					
				printf("\n\tCliente: %s. \tCPF: %s\n \n\tTotal a ser pago: R$ %5.2f\n", Locacao[posicao].nome, Locacao[posicao].cpf, descontoDiaria(Locacao[posicao].vlrDiaria * Locacao[posicao].qtdDiaria, Locacao[posicao].vlrDesconto));
				
				Locacao[posicao].valorTotal = descontoDiaria(Locacao[posicao].vlrDiaria * Locacao[posicao].qtdDiaria, Locacao[posicao].vlrDesconto);
			}
			
			if(auxQtdeDiaria > Locacao[posicao].qtdDiaria){
				Locacao[posicao].qtdDiaria = auxQtdeDiaria;
				auxQtdeDiaria = 0;
			}
			
			calculaDataDiaria(Locacao[posicao].qtdDiaria , posicao);
			
			printf("\n\tVeiculo: %s \tPlaca: %s\n", Locacao[posicao].veiculoEscolhido, Locacao[posicao].placaVeiculo );
			printf("\n\tData de locação : %s \n", Locacao[posicao].dataInicioLocacao);
			printf("\n\tData de entrega: %s \n", Locacao[posicao].dataFimLocacao);
			
			printf("\n\n\tO veiculo %s foi alugado com sucesso!\n\n", cadVeiculo[retPosVeic].modeloVec );
		}
		printf("\n\n\tPressione entrer para continuar. ");
		limparBuffer();getchar();
}

//conaultar alocao
void consultaLocacao(void){
	int contador = 0, codigo;
	char cpf[15];
	
	limpaTela(); //limpa a tela
    
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                        Consulta de Locão                              *");
	printf("\n\t*****************************************************************************************\n");
	printf("\n\tEntre com o código => ");
    scanf("%d",&codigo);
	limparBuffer();
	
	while ( contador <= tlLocacao )
    {
    	if (Locacao[contador].cod == codigo )
        {
	    	printf("\n\tCódigo: %d", Locacao[contador].cod);
        	printf("\n\tNome: %s", Locacao[contador].nome);
			printf("\n\tCPF: %s", Locacao[contador].cpf);
			printf("\n\tIdade: %d", Locacao[contador].idade);
			printf("\n\tDiária: %5.2f", Locacao[contador].vlrDiaria);
			printf("\n\tQtde Diária: %d", Locacao[contador].qtdDiaria);
			printf("\n\tT. Diária: %5.2f", Locacao[contador].valorTotal);
			
			if(Locacao[contador].parceiro == 1){
				printf("\n\tParceiro: Sim");
			}else {
				printf("\n\tParceiro: Nao");
			}
			
			printf("\n\tData retirada: %s", Locacao[contador].dataInicioLocacao);
			printf("\n\tData entrega : %s", Locacao[contador].dataFimLocacao);
			
			printf("\n\tMarca veículo: %s", marcas[Locacao[contador].posicaoMarcaVeiculo]);
			printf("\n\tVeiculo: %s \tPlaca: %s", Locacao[contador].veiculoEscolhido, Locacao[contador].placaVeiculo );
			
			if(Locacao[contador].status == 0){
				printf("\n\tSituação: Livre\n\n");
			}else if(Locacao[contador].status == 1){
				printf("\n\tSituação: Alugado\n\n");
			}else{
				printf("\n\tSituação: Agendado\n\n");
			}
			
			break;
		}
		contador++;
	}
	printf("\n\t================================== Fim de registro! =====================================\n\n");
		
	printf("\n\tPressione entrer para continuar. ");
	limparBuffer();

}

//Função para listar Locacao cadastrados    
void listarLocacao(){ 
   
	limpaTela();
    int retPosVeic, contaLinha = 16;
    
   	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                        Lista de Locação                               *");
	printf("\n\t*****************************************************************************************\n");
	
	for(int i = 0; i < tlLocacao; i++){
        
        retPosVeic = retornaPosicaoVeiculoEscolhido(Locacao[i].posicaoMarcaVeiculo, Locacao[i].posicaoModeloveiculo );
        
		printf("\n\tCódigo: %d", Locacao[i].cod);	
		printf("\n\tNome: %s", Locacao[i].nome);
		printf("\n\tCPF: %s", Locacao[i].cpf);
		printf("\n\tIdade: %d", Locacao[i].idade);
		printf("\n\tDiária: %5.2f", Locacao[i].vlrDiaria);
		printf("\n\tQtde Diária: %d", Locacao[i].qtdDiaria);
		printf("\n\tT. Diária: %5.2f", Locacao[i].valorTotal);
		
		if(Locacao[i].parceiro == 1){
			printf("\n\tParceiro: Sim");
		}else{
			printf("\n\tParceiro: Nao");
		}
		
		
		printf("\n\tData retirada: %s", Locacao[i].dataInicioLocacao);
		printf("\n\tData entrega : %s", Locacao[i].dataFimLocacao);
		printf("\n\tMarca veículo: %s", cadVeiculo[retPosVeic].modeloVec);
		printf("\tCor: %s", cadVeiculo[retPosVeic].corVeiculo);
		printf("\n\tVeículo: %s \tPlaca: %s", Locacao[i].veiculoEscolhido, Locacao[i].placaVeiculo);
		
		if(Locacao[i].status == 0){
			printf("\n\tSituação: Livre\n");
		}else if(Locacao[i].status == 1){
			printf("\n\tSituação: Alugado\n");
		}else{
			printf("\n\tSituação: Agendado\n");
		}
		printf("\n\t================================== Fim de registro! =====================================\n");
		if(contaLinha == 48){
			printf("\n\n\tPressione entrer para continuar. ");
			limparBuffer();
			contaLinha = 16;
		}
		
		contaLinha += 16;
	}
	printf("\n\t=========================  Qtde de Registros Cadastrados:  %d  ==========================\n", tlLocacao);
	printf("\n\t=============================== Fim de todos os registros! ==============================\n\n");
	printf("\n\tPressione entrer para continuar. ");
	limparBuffer();
}

// Função para alterar Locacao
void alterarLocacao(){
	int opcao, contador = 0, codigo;
	limpaTela();
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                        Alteração de Veículo                           *");
	printf("\n\t*****************************************************************************************\n");
	printf("\n\tEntre com o código a ser alterado => ");
    scanf("%d",&codigo);
	limparBuffer();
		
    int retorno = verificaPosicaoLocacao();
    
     if ( retorno > 0 ){
    	
		while ( contador < tlLocacao ){
	
	        if (Locacao[contador].cod == codigo)
	        {
	            while(opcao != 11){
				
					limpaTela(); // limpa tela
	            	
	            	printf("\n\n\t*****************************************************************************************\n");
					printf("\t*                                        Alteração de Locação                           *");
					printf("\n\t*****************************************************************************************\n");
					
				    if(Locacao[contador].status == 0){
						printf("\n\tSituação: Livre\n\n");
					}else if(Locacao[contador].status == 1){
						printf("\n\tSituação: Alugado\n\n");
					}else{
						printf("\n\tSituação: Agendado\n\n");
					}
		
				    printf("\n\tCódigo: %d\n", Locacao[contador].cod);
					printf("\n\t[ 1] Nome: %s", Locacao[contador].nome);
					printf("\n\t[ 2] CPF: %s", Locacao[contador].cpf);
					printf("\n\t[ 3] Idade: %d", Locacao[contador].idade);
					printf("\n\t[ 4] Diária: %5.2f", Locacao[contador].vlrDiaria);
					printf("\n\t[ 5] Qtde Diária: %d", Locacao[contador].qtdDiaria);
					printf("\n\t[ 6] T. Diária: %5.2f", Locacao[contador].valorTotal);
					printf("\n\t[ 7] Parceiro: 1-Sim 2-Nao : %d", Locacao[contador].parceiro);
					printf("\n\t[ 8] Data retirada: %s", Locacao[contador].dataInicioLocacao);
					printf("\n\t[ 9] Data entrega : %s", Locacao[contador].dataFimLocacao);
					printf("\n\t[10] Veículo: %s \tPlaca: %s\n", Locacao[contador].veiculoEscolhido, Locacao[contador].placaVeiculo);
					printf("\n\t[11] Sair e Salvar!");
					
					
					printf("\n\n\tQual campo deseja alterar? => ");
					fflush(stdin);
					scanf("%d" , &opcao);
					
								
					switch(opcao)
					{
						case 1:
							printf("\n\tNome: " );
							fflush(stdin);
							gets(Locacao[contador].nome);
							break;
							
						case 2:
							printf("\n\tCPF: ");
							scanf("%s", &Locacao[contador].cpf);
							limparBuffer();
							break;
						
						case 3:
							printf("\n\tIdade: ");
							scanf("%d", &Locacao[contador].idade);
							limparBuffer();
							break;
						
						case 4:
							printf("\n\tDiária: ");
							scanf("%f", &Locacao[contador].vlrDiaria);
							limparBuffer();
							break;
							
						case 5:
							printf("\n\tQtde Diária: ");
							scanf("%d", &Locacao[contador].qtdDiaria);
							limparBuffer();
							break;
							
						case 6:
							printf("\n\tValor total: ");
							scanf("%f", &Locacao[contador].valorTotal);
							limparBuffer();
							break;
							
						case 7:
							printf("\n\tParceiro: 1-Sim 2-Nao: " );
							scanf("%d", &Locacao[contador].parceiro);
							limparBuffer();
							break;
							
						case 8:
							printf("\n\tData Inicio: ");
							fflush(stdin);
							gets(Locacao[contador].dataInicioLocacao);
							break;
						
						case 9:
							printf("\n\tData Fim: ");
							fflush(stdin);
							gets(Locacao[contador].dataFimLocacao);
							break;
						
						case 10:
							printf("\n\tPlaca Veículo!");	
							limparBuffer();
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
					
					}// fim do switch
				} // fim do while
			}
			contador++;
		}
		printf("\n\t================================== Fim de registro! =====================================\n\n");
	
	}else{
		opcaoInvalida();
		printf("\n\tRegistro não encontrado!\n\n");
		sleep(1);
	}
	
	printf("\n\tPressione entrer para continuar. ");
	limparBuffer();
	
}

// devolucao de Locacao
void devolucaoLocacao(){
	int contador = 0, cod, posicao;
	char cpf[15], finalizaDevolucao;
	float multa;
	
	limpaTela(); //limpa a tela
    
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                        Devolução de Locação                           *");
	printf("\n\t*****************************************************************************************\n");
	printf("\n\tEntre com o código => ");
    scanf("%d",&cod);
	limparBuffer();
	
	while ( contador <= tlLocacao )
    {
    	if (Locacao[contador].cod == cod )
        {
	    	printf("\n\tCódigo: %d", Locacao[contador].cod);
        	printf("\n\tNome: %s", Locacao[contador].nome);
			printf("\n\tCPF: %s", Locacao[contador].cpf);
			printf("\n\tIdade: %d", Locacao[contador].idade);
			printf("\n\tDiária: %5.2f", Locacao[contador].vlrDiaria);
			printf("\n\tQtde Diária: %d", Locacao[contador].qtdDiaria);
			printf("\n\tT. Diária: %5.2f", Locacao[contador].valorTotal);
			
			if(Locacao[contador].parceiro == 1){
				printf("\n\tParceiro: Sim");
			}else{
				printf("\n\tParceiro: Nao");
			}
			
			printf("\n\tData retirada: %s", Locacao[contador].dataInicioLocacao);
			printf("\n\tData entrega : %s", Locacao[contador].dataFimLocacao);
			printf("\n\tMarca veículo: %s", marcas[Locacao[contador].posicaoMarcaVeiculo]);
			printf("\n\tVeículo: %s \tPlaca: %s", Locacao[contador].veiculoEscolhido, Locacao[contador].placaVeiculo );
			
			if(Locacao[contador].status == 0){
				printf("\n\tSituação: Livre\n\n");
			}else if(Locacao[contador].status == 1){
				printf("\n\tSituação: Alugado\n\n");
			}else{
				printf("\n\tSituação: Agendado\n\n");
			}
			
			int diasAtrazados = verificarAtrasoMulta(Locacao[contador].dataFimLocacao );
			
			if(diasAtrazados > 0){
				multa = calcularMulta(diasAtrazados, Locacao[contador].vlrDiaria );
			}
			
			printf("\n\tValor da multa %3.2f", multa);
			multa += Locacao[contador].valorTotal;
			printf("\n\tTotal com multa à ser pago: %4.2f \n", multa); 
			
			printf("\n\tFinalizar devoluão: S/N "); 
			scanf("%c", &finalizaDevolucao );
			fflush(stdin);
			
			if ( ( finalizaDevolucao == 'S' ) || ( finalizaDevolucao == 's' ) ){
				Locacao[contador].status = 0;
				
				int retPosVeic = retornaPosicaoVeiculoEscolhido(Locacao[contador].posicaoMarcaVeiculo, Locacao[contador].posicaoModeloveiculo);
		
				if(cadVeiculo[retPosVeic].status == 1){
					cadVeiculo[retPosVeic].status = 0;	
				}
				
				posicao = contador;
				
				limpaTela();
	
				printf("\n\n\t*****************************************************************************************\n");
				printf("\t*                                        Devolução Finalizada                           *");
				printf("\n\t*****************************************************************************************\n");
				printf("\n\n\t*****************************************************************************************\n");
				printf("\t*                                        Recibo de Locação                              *");
				printf("\n\t*****************************************************************************************\n");
				
				printf("\n\tNome: %s", Locacao[posicao].nome);
				printf("\tCPF: %s\n", Locacao[posicao].cpf);
				printf("\n\tVeículo: %s \tPlaca: %s\n", Locacao[posicao].veiculoEscolhido, cadVeiculo[Locacao[posicao].posicaoModeloveiculo].placaVeiculo );
				printf("\n\tData de entrega: %s \n", Locacao[posicao].dataFimLocacao);
				printf("\n\tTotal pago: %4.2f \n", multa);
				
				printf("\n\n\tO veículo %s foi devolvido com sucesso!\n\n", Locacao[posicao].veiculoEscolhido);
				printf("\n\t================================== Fim de registro! =====================================\n\n");
	
			}else{
				printf("\n\n\t*****************************************************************************************\n");
				printf("\t*                                        Devolução Cancelada                            *");
				printf("\n\t*****************************************************************************************\n");
			}
			
		}
		contador++;
	}
		
	printf("\n\tPressione entrer para continuar. ");
	limparBuffer();
}

//Função para excluir Funcionários
void excluirLocacao(void){
	
	limpaTela(); //limpa a tela
	int codigo, contador = 0;
    char resp;
    printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                    Excluir Cadastro de Locação                        *");
	printf("\n\t*****************************************************************************************\n");
	printf("\n\tDigite o código a ser excluir: ");
    scanf("%d", &codigo );
	limparBuffer();
	
	int returno = verificaPosicaoLocacao();
	
	if(returno <= tlLocacao){
	    while ( contador <= tlLocacao - 1 )
	    {
       		if ( Locacao[contador].cod == codigo )
	        {
	        	printf("\n\tCódigo: %d", Locacao[contador].cod);
	        	printf("\n\tNome: %s", Locacao[contador].nome);
				printf("\n\tCPF: %s", Locacao[contador].cpf);
				printf("\n\tIdade: %d", Locacao[contador].idade);
				printf("\n\tDiária: %5.2f", Locacao[contador].vlrDiaria);
				printf("\n\tQtde Diária: %d", Locacao[contador].qtdDiaria);
				printf("\n\tT. Diária: %5.2f", Locacao[contador].valorTotal);
				if(Locacao[contador].parceiro == 1){
					printf("\n\tParceiro: Sim");
				}else{
					printf("\n\tParceiro: Nao");
				}
				printf("\n\tData retirada: %s", Locacao[contador].dataInicioLocacao);
				printf("\n\tData entrega : %s", Locacao[contador].dataFimLocacao);
				printf("\n\tMarca veiculo: %s", marcas[Locacao[contador].posicaoMarcaVeiculo]);
				printf("\n\tVeículo: %s \tPlaca: %s", Locacao[contador].veiculoEscolhido, Locacao[contador].placaVeiculo);
				if(Locacao[contador].status == 0){
				printf("\n\tSituação: Livre\n\n");
				}else if(Locacao[contador].status == 1){
					printf("\n\tSituação: Alugado\n\n");
				}else{
					printf("\n\tSituação: Agendado\n\n");
				}
                printf("\n\tDeseja realmente excluir? s/n: ");
                scanf("%s",&resp);
				fflush(stdin);
				
                if ( ( resp == 'S' ) || ( resp == 's' ) )
                {
                	if(tlLocacao - 1 != 0){
					
	                    for(int i = contador; i <= tlLocacao - 1; i++){
	                     	
	                     	Locacao[i].cod                			= Locacao[i + 1].cod ;
							strcpy(Locacao[i].nome        			, Locacao[i + 1].nome );
							strcpy(Locacao[i].cpf         			, Locacao[i + 1].cpf );
							Locacao[i].idade              			= Locacao[i + 1].idade;
							Locacao[i].vlrDiaria          			= Locacao[i + 1].vlrDiaria;
							Locacao[i].qtdDiaria          			= Locacao[i + 1].qtdDiaria;
							Locacao[i].parceiro		   				= Locacao[i + 1].parceiro ;
							Locacao[i].valorTotal         			= Locacao[i + 1].valorTotal;
							Locacao[i].vlrDesconto        			= Locacao[i + 1].vlrDesconto ;
							strcpy(Locacao[i].veiculoEscolhido		, Locacao[i + 1].veiculoEscolhido);
							Locacao[i].posicaoMarcaVeiculo  		= Locacao[i + 1].posicaoMarcaVeiculo;
							Locacao[i].posicaoModeloveiculo 		= Locacao[i + 1].posicaoModeloveiculo;
							strcpy(Locacao[i].dataInicioLocacao		, Locacao[i + 1].dataInicioLocacao);
							strcpy(Locacao[i].dataFimLocacao		, Locacao[i + 1].dataFimLocacao);
							strcpy(Locacao[i].placaVeiculo			, Locacao[i + 1].placaVeiculo);
							Locacao[i].status						= Locacao[i + 1].status;
							
						}
					}else{
						for(int i = contador; i <= tlLocacao - 1; i++){
	                     	
	                     	Locacao[i].cod                			= 0 ;
							strcpy(Locacao[i].nome					, "");
							strcpy(Locacao[i].cpf                	, "");
							Locacao[i].idade              			= 0 ;
							Locacao[i].vlrDiaria          			= 0 ;
							Locacao[i].qtdDiaria          			= 0 ;
							Locacao[i].parceiro						= 0 ;
							Locacao[i].valorTotal         			= 0 ;
							Locacao[i].vlrDesconto        			= 0 ;
							strcpy(Locacao[i].veiculoEscolhido		, "");
							Locacao[i].posicaoMarcaVeiculo  		= 0 ;
							Locacao[i].posicaoModeloveiculo 		= 0 ;
							strcpy(Locacao[i].dataInicioLocacao		, "");
							strcpy(Locacao[i].dataFimLocacao		, "");
							strcpy(Locacao[i].placaVeiculo			, "");
							Locacao[i].status						= 0;
							
						}
					}
					tlLocacao--;	
					
					printf("\n\t============================= Exclusão feita com sucesso ================================\n");
					sleep(1);
                    break;
                }
                else
                {
                    if ( ( resp == 'N' ) || ( resp == 'n' ) )
                    {
                    	opcaoInvalida();
                        printf("\tExclusão cancelada!\n");
                        sleep(1);
                        break;
                    }
                }
			}
			contador++;
   		}
    }else{
		opcaoInvalida();
    	printf("\n\tCódigo não encontrado!!\n\n");
    	sleep(1);
    }
	
}

// verificar posicao da Locacao
int verificaPosicaoLocacao(void){
    int contador = 0;
	
    while ( contador <= SIZE )
    {

        if ( Locacao[contador].cod == 0 )
            return(contador);

        contador++;

    }

    return(-1);

}

// verificar se o veiculo foi alugado
int verificaPosicaoVeiculoAlugado( int OptMarca, int OptModelo ){
    int contador = 0;

    while ( contador <= tlLocacao - 1 )
    {
    	if ( Locacao[contador].posicaoMarcaVeiculo == OptMarca - 1 && Locacao[contador].posicaoModeloveiculo == OptModelo - 1 )
    		if(Locacao[contador].status == 1){
    			return(0);
            }else if( Locacao[contador].status == 2){
            	return(2);
			}
        contador++;
    }

    return(1);

}

// Retorna posicao da Locacao
int retornaPosicaoLocacao(int marca, int modelo){
	
	int contador = 0;
    for (int i = 0; i <= tlLocacao - 1 ; i++)
    {
        if (  Locacao[i].posicaoMarcaVeiculo == marca && Locacao[i].posicaoModeloveiculo == modelo ){
        	return(contador);
		}
        contador++;
    }
	
}
/*==================================================================================*/
/*								FIM CONTROLE DE Locacao    						*/
/*==================================================================================*/


#endif

