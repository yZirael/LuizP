#include <unistd.h>


#ifndef CONTROLE_ALOCACAO_H
#define CONTROLE_ALOCACAO_H

#include "../calculoData/calculaDataDescontoValida.h"


int verificaPosicaoAlocacao(void);
int retornaPosicaoVeiculoEscolhido(int marca, int modelo);


// inserir Alocacao na lista
void inserirAlocacaoLista(int OptMarca, int OptModelo){    
		char resp, cpf;
		int retorno, auxQtdeDiaria, retPosVeic;
		
		int posicao = verificaPosicaoAlocacao();
		tlAlocacao += 1;
		
		retPosVeic = retornaPosicaoVeiculoEscolhido(OptMarca - 1, OptModelo - 1 );
				
		strcpy(alocacao[posicao].veiculoEscolhido, cadVeiculo[retPosVeic].modeloVec);
		alocacao[posicao].posicaoMarcaVeiculo = OptMarca - 1;
		alocacao[posicao].posicaoModeloveiculo = OptModelo - 1;
		alocacao[posicao].status = 1;
		strcpy(alocacao[posicao].placaVeiculo, cadVeiculo[retPosVeic].placaVeiculo);
		
		char vecEscolido[20];
		strcpy(vecEscolido, alocacao[posicao].veiculoEscolhido);
		
		cadVeiculo[retPosVeic].status = 1;
		
		printf("\n\n\t**********************************************\n");
		printf("\t*              Cadastro de Alocacao          *");
		printf("\n\t**********************************************\n");
		
		pontoNome:
		
		printf("\n\tCodigo do cadastro:  %d \n", tlAlocacao);
		alocacao[posicao].vlrDiaria = alocacao[posicao].cod = tlAlocacao;
	
		printf("\n\tCarro: %s \tValor: %5.2f\n", alocacao[posicao].veiculoEscolhido, cadVeiculo[retPosVeic].vlrDiaria );
		valoresDiaria[OptMarca - 1][OptModelo - 1];
		printf("\n\tNome: ");
		gets(alocacao[posicao].nome);
		fflush(stdin);
		
		pontoCPF:
		
		printf("\n\tCPF: ");
		scanf("%s", &alocacao[posicao].cpf);
		limparBuffer();
		
		pontoIdade:
		
		printf("\n\tIdade: ");
		scanf("%d", &alocacao[posicao].idade);
		limparBuffer();	
				
		retorno = validaIdade(alocacao[posicao].idade);
		
		if(retorno == 1){
			opcaoInvalida();
			printf("\n\tIndade nao pode ser menor que 18  ou maior que 120 !! Tente novamente!!\n");
			goto pontoIdade;
		
		}
		
		pontoParceiro:
		
		printf("\n\tEh empresas parceira ? 1-Sim | 2-Nao : ");
		scanf("%d", &alocacao[posicao].parceiro);
		limparBuffer();	
				
		if((alocacao[posicao].parceiro < 1) || (alocacao[posicao].parceiro > 2)){
			opcaoInvalida();
			printf("\n\tPor favor, digite 1 ou 2!!\n");
			goto pontoParceiro;
		
		}
				
		pontoQtdDiaria:
		
		printf("\n\tQuantidade de diaria de 1 a 10: ");
		scanf("%d", &alocacao[posicao].qtdDiaria);
		limparBuffer();	
				
		if((alocacao[posicao].qtdDiaria < 1) || (alocacao[posicao].qtdDiaria > 10)){
			opcaoInvalida();
			printf("\n\tNao pode ser menor que 0 ou maior que 10!! Tente novamente!!\n");
			goto pontoQtdDiaria;
		
		}else{
			if(alocacao[posicao].qtdDiaria > 4){
				printf("\n\tLocacao com direito a uma diaria extra!!\n");
				printf("\n\tDeseja utilizar a diaria extra? S/N ");
				fflush(stdin);
				scanf("%c", &resp);
				
				if(resp == 's' || resp == 'S'){
					
					auxQtdeDiaria = alocacao[posicao].qtdDiaria + 1;
				}
				
			}
			
			limpaTela(); //limpa a tela

			printf("\n\n\t*********************************************\n");
			printf("\t*             Alocacao Concluida            *");
			printf("\n\t*********************************************\n");
			
			if (alocacao[posicao].idade >= 60) {
							
				alocacao[posicao].vlrDesconto = 10;
				
			}
			else if (alocacao[posicao].parceiro == 1 ) {
				
				alocacao[posicao].vlrDesconto = 5;
				
			}
			
				
			printf("\n\tCliente: %s. \tCPF: %s\n \n\tTotal a ser pago: R$ %5.2f\n", alocacao[posicao].nome, alocacao[posicao].cpf, descontoDiaria(alocacao[posicao].vlrDiaria * alocacao[posicao].qtdDiaria, alocacao[posicao].vlrDesconto));
			
			
			alocacao[posicao].valorTotal = descontoDiaria(alocacao[posicao].vlrDiaria * alocacao[posicao].qtdDiaria, alocacao[posicao].vlrDesconto);
			
		}
		
		alocacao[posicao].qtdDiaria = auxQtdeDiaria;
		calculaDataDiaria(alocacao[posicao].qtdDiaria , posicao);
		
		printf("\n\tVeiculo: %s \tPlaca: %s\n", alocacao[posicao].veiculoEscolhido, alocacao[posicao].placaVeiculo );
		printf("\n\tData de alocao : %s \n", alocacao[posicao].dataInicioAlocacao);
		printf("\n\tData de entrega: %s \n", alocacao[posicao].dataFimAlocacao);
		
		printf("\n\n\tO veiculo %s foi alugado com sucesso!\n\n", cadVeiculo[retPosVeic].modeloVec );	
		getchar();
}

//conaultar alocao
void consultaAlocacao(void){
	int contador = 0, codigo;
	char cpf[15];
	
	limpaTela(); //limpa a tela
    
	printf("\n\n\t************************************************\n");
	printf("\t*               Consulta de Alocacao           *");
	printf("\n\t************************************************\n");
	printf("\n\tEntre com o codigo => ");
    scanf("%d",&codigo);
	limparBuffer();
	
	while ( contador <= tlAlocacao )
    {
    	if (alocacao[contador].cod == codigo )
        {
	    	printf("\n\tCodigo: %d", alocacao[contador].cod);
        	printf("\n\tNome: %s", alocacao[contador].nome);
			printf("\n\tCPF: %s", alocacao[contador].cpf);
			printf("\n\tIdade: %d", alocacao[contador].idade);
			printf("\n\tDiaria: %5.2f", alocacao[contador].vlrDiaria);
			printf("\n\tQtde Diaria: %d", alocacao[contador].qtdDiaria);
			printf("\n\tT. Diaria: %5.2f", alocacao[contador].valorTotal);
			
			if(alocacao[contador].parceiro == 1){
				printf("\n\tParceiro: Sim");
			}else {
				printf("\n\tParceiro: Nao");
			}
			
			printf("\n\tData retirada: %s", alocacao[contador].dataInicioAlocacao);
			printf("\n\tData entrega : %s", alocacao[contador].dataFimAlocacao);
			
			printf("\n\tMarca veiculo: %s", marcas[alocacao[contador].posicaoMarcaVeiculo]);
			printf("\n\tVeiculo: %s \tPlaca: %s", alocacao[contador].veiculoEscolhido, alocacao[contador].placaVeiculo );
			
			if(alocacao[contador].status == 0){
				printf("\n\tSituacao: Livre\n\n");
			}else if(alocacao[contador].status == 1){
				printf("\n\tSituacao: Alugado\n\n");
			}else{
				printf("\n\tSituacao: Agendado\n\n");
			}
			
			break;
		}
		contador++;
	}
	printf("\n\t============== Fim do Registro ==============\n\n");
		
	limparBuffer();

}

//Função para listar alocacao cadastrados    
void listarAlocacao(){ 
   
	limpaTela();
   
   	printf("\n\n\t*********************************************\n");
	printf("\t*               Lista de Alocacao           *");
	printf("\n\t*********************************************\n");
 	
	int i;   
    for(i = 0; i < tlAlocacao; i++){
        
		printf("\n\tCodigo: %d", alocacao[i].cod);	
		printf("\n\tNome: %s", alocacao[i].nome);
		printf("\n\tCPF: %s", alocacao[i].cpf);
		printf("\n\tIdade: %d", alocacao[i].idade);
		printf("\n\tDiaria: %5.2f", alocacao[i].vlrDiaria);
		printf("\n\tQtde Diaria: %d", alocacao[i].qtdDiaria);
		printf("\n\tT. Diaria: %5.2f", alocacao[i].valorTotal);
		
		if(alocacao[i].parceiro == 1){
			printf("\n\tParceiro: Sim");
		}else{
			printf("\n\tParceiro: Nao");
		}
		
		
		printf("\n\tData retirada: %s", alocacao[i].dataInicioAlocacao);
		printf("\n\tData entrega : %s", alocacao[i].dataFimAlocacao);
		
		printf("\n\tMarca veiculo: %s", marcas[alocacao[i].posicaoMarcaVeiculo]);
		printf("\n\tVeiculo: %s \tPlaca: %s\n\n", alocacao[i].veiculoEscolhido, alocacao[i].placaVeiculo);
		
		if(alocacao[i].status == 0){
			printf("\n\tSituacao: Livre\n\n");
		}else if(alocacao[i].status == 1){
			printf("\n\tSituacao: Alugado\n\n");
		}else{
			printf("\n\tSituacao: Agendado\n\n");
		}
		printf("\n\t============= Fim do registro! ==============\n\n");					
       	
	}
	printf("\n\n\t====  Qtde de Registros Cadastrados:  %d  ====\n", tlAlocacao);
	printf("\n\t======== Fim de todos os registros! =========\n\n");
	getchar();
}

// Função para alterar alocacao
void alterarAlocacao(){
	int opcao, contador = 0, codigo;
	limpaTela();
	printf("\n\n\t***********************************************\n");
	printf("\t*            Alteracao de Veiculo             *");
	printf("\n\t***********************************************\n");
    printf("\n\tEntre com o codigo a ser alteracao => ");
    scanf("%d",&codigo);
	limparBuffer();
		
    int retorno = verificaPosicaoAlocacao();
    
     if ( retorno > 0 ){
    	
		while ( contador < tlAlocacao ){
	
	        if (alocacao[contador].cod == codigo)
	        {
	            while(opcao != 11){
				
					limpaTela(); // limpa tela
	            	
	            	printf("\n\n\t************************************************\n");
					printf("\t*            Alteracao de Alocacao             *");
					printf("\n\t************************************************\n");
				    
				    if(alocacao[contador].status == 1){
						printf("\n\tSituacao alocacao: Alugado\n");
					}else{
						printf("\n\tSituacao alocacao: Livre\n");
					}
				    printf("\n\tCodigo: %d\n", alocacao[contador].cod);
					printf("\n\t[ 1] Nome: %s", alocacao[contador].nome);
					printf("\n\t[ 2] CPF: %s", alocacao[contador].cpf);
					printf("\n\t[ 3] Idade: %d", alocacao[contador].idade);
					printf("\n\t[ 4] Diaria: %5.2f", alocacao[contador].vlrDiaria);
					printf("\n\t[ 5] Qtde Diaria: %d", alocacao[contador].qtdDiaria);
					printf("\n\t[ 6] T. Diaria: %5.2f", alocacao[contador].valorTotal);
					printf("\n\t[ 7] Parceiro: 1-Sim 2-Nao : %d", alocacao[contador].parceiro);
					printf("\n\t[ 8] Data retirada: %s", alocacao[contador].dataInicioAlocacao);
					printf("\n\t[ 9] Data entrega : %s", alocacao[contador].dataFimAlocacao);
					printf("\n\t[10] Veiculo: %s \tPlaca: %s\n", alocacao[contador].veiculoEscolhido, alocacao[contador].placaVeiculo);
					printf("\n\t[11] Sair e Salvar!");
					
					
					printf("\n\n\tQual campo deseja alterar? => ");
					fflush(stdin);
					scanf("%d" , &opcao);
					
								
					switch(opcao)
					{
						case 1:
							printf("\n\tNome: " );
							fflush(stdin);
							gets(alocacao[contador].nome);
							break;
							
						case 2:
							printf("\n\tCPF: ");
							scanf("%s", &alocacao[contador].cpf);
							limparBuffer();
							break;
						
						case 3:
							printf("\n\tIdade: ");
							scanf("%d", &alocacao[contador].idade);
							limparBuffer();
							break;
						
						case 4:
							printf("\n\tDiaria: ");
							scanf("%f", &alocacao[contador].vlrDiaria);
							limparBuffer();
							break;
							
						case 5:
							printf("\n\tQtde Diaria: ");
							scanf("%d", &alocacao[contador].qtdDiaria);
							limparBuffer();
							break;
							
						case 6:
							printf("\n\tValor total: ");
							scanf("%f", &alocacao[contador].valorTotal);
							limparBuffer();
							break;
							
						case 7:
							printf("\n\tParceiro: 1-Sim 2-Nao: " );
							scanf("%d", &alocacao[contador].parceiro);
							limparBuffer();
							break;
							
						case 8:
							printf("\n\tData Inicio: ");
							fflush(stdin);
							gets(alocacao[contador].dataInicioAlocacao);
							break;
						
						case 9:
							printf("\n\tData Fim: ");
							fflush(stdin);
							gets(alocacao[contador].dataFimAlocacao);
							break;
						
						case 10:
							printf("\n\tPlaca Veiculo!");	
							limparBuffer();
							break;
						
						case 11:
							printf("\n\tDados salvo com sucesso!");	
							sleep(1);
							break;
							
						default:
							opcaoInvalida();
							printf("\n\tOpcao invalida!\n\n");
							sleep(1);
							break;
					
					}// fim do switch
				} // fim do while
			}
			contador++;
		}
		printf("\n\t================ Fim da Alteracao! =================\n\n");
	}else{
		opcaoInvalida();
		printf("\n\tRegistro nao encontrado!\n\n");
		sleep(1);
	}
	
	limparBuffer();
	
}

// devolucao de alocacao
void devolucaoAlocacao(){
	int contador = 0, cod, posicao;
	char cpf[15], finalizaDevolucao;
	float multa;
	
	limpaTela(); //limpa a tela
    
	printf("\n\n\t*************************************************\n");
	printf("\t*               Devolucao de Alocacao           *");
	printf("\n\t*************************************************\n");
	printf("\n\tEntre com o codigo => ");
    scanf("%d",&cod);
	limparBuffer();
	
	while ( contador <= tlAlocacao )
    {
    	if (alocacao[contador].cod == cod )
        {
	    	printf("\n\tCodigo: %d", alocacao[contador].cod);
        	printf("\n\tNome: %s", alocacao[contador].nome);
			printf("\n\tCPF: %s", alocacao[contador].cpf);
			printf("\n\tIdade: %d", alocacao[contador].idade);
			printf("\n\tDiaria: %5.2f", alocacao[contador].vlrDiaria);
			printf("\n\tQtde Diaria: %d", alocacao[contador].qtdDiaria);
			printf("\n\tT. Diaria: %5.2f", alocacao[contador].valorTotal);
			
			if(alocacao[contador].parceiro == 1){
				printf("\n\tParceiro: Sim");
			}else{
				printf("\n\tParceiro: Nao");
			}
			
			printf("\n\tData retirada: %s", alocacao[contador].dataInicioAlocacao);
			printf("\n\tData entrega : %s", alocacao[contador].dataFimAlocacao);
			printf("\n\tMarca veiculo: %s", marcas[alocacao[contador].posicaoMarcaVeiculo]);
			printf("\n\tveiculo: %s \tPlaca: %s", alocacao[contador].veiculoEscolhido, alocacao[contador].placaVeiculo );
			
			if(alocacao[contador].status == 0){
				printf("\n\tSituacao: Livre\n\n");
			}else if(alocacao[contador].status == 1){
				printf("\n\tSituacao: Alugado\n\n");
			}else{
				printf("\n\tSituacao: Agendado\n\n");
			}
			
			int diasAtrazados = verificarAtrasoMulta(alocacao[contador].dataFimAlocacao );
			
			if(diasAtrazados > 0){
				multa = calcularMulta(diasAtrazados, alocacao[contador].vlrDiaria );
			}
			
			printf("\n\tValor da multa %3.2f", multa);
			multa += alocacao[contador].valorTotal;
			printf("\n\tTotal com multa a se pago: %4.2f \n", multa); 
			
			printf("\n\tFinalizar devoluca: S/N "); 
			scanf("%c", &finalizaDevolucao );
			fflush(stdin);
			
			if ( ( finalizaDevolucao == 'S' ) || ( finalizaDevolucao == 's' ) ){
				alocacao[contador].status = 0;
				
				int retPosVeic = retornaPosicaoVeiculoEscolhido(alocacao[contador].posicaoMarcaVeiculo, alocacao[contador].posicaoModeloveiculo);
		
				cadVeiculo[retPosVeic].status = 0;
			}
			posicao = contador;
		}
		contador++;
	}
	printf("\n\t================ Fim do Registro ================\n\n");
	
	limpaTela();
	
	printf("\n\n\t*************************************************\n");
	printf("\t*                 Recibo de Alocacao            *");
	printf("\n\t*************************************************\n");
	
	printf("\n\tNome: %s", alocacao[posicao].nome);
	printf("\tCPF: %s\n", alocacao[posicao].cpf);
	printf("\n\tVeiculo: %s \tPlaca: %s\n", alocacao[posicao].veiculoEscolhido, cadVeiculo[alocacao[posicao].posicaoModeloveiculo].placaVeiculo );
	printf("\n\tData de entrega: %s \n", alocacao[posicao].dataFimAlocacao);
	printf("\n\tTotal pago: %4.2f \n", multa);
	
	printf("\n\n\tO veiculo %s foi devolvido com sucesso!\n\n", alocacao[posicao].veiculoEscolhido);	
	
		
	limparBuffer();
}

//Função para excluir Funcionários
void excluirAlocacao(void){
	
	limpaTela(); //limpa a tela
	int codigo, contador = 0;
    char resp;
    printf("\n\n\t*****************************************************\n");
	printf("\t*           Excluir Cadastro de Alocacao            *");
	printf("\n\t*****************************************************\n");
    printf("\n\tDigite o codigo a ser excluir: ");
    scanf("%d", &codigo );
	limparBuffer();
	
	int returno = verificaPosicaoAlocacao();
	
	if(returno <= tlAlocacao){
	    while ( contador <= tlAlocacao - 1 )
	    {
       		if ( alocacao[contador].cod == codigo )
	        {
	        	printf("\n\tCodigo: %d", alocacao[contador].cod);
	        	printf("\n\tNome: %s", alocacao[contador].nome);
				printf("\n\tCPF: %s", alocacao[contador].cpf);
				printf("\n\tIdade: %d", alocacao[contador].idade);
				printf("\n\tDiaria: %5.2f", alocacao[contador].vlrDiaria);
				printf("\n\tQtde Diaria: %d", alocacao[contador].qtdDiaria);
				printf("\n\tT. Diaria: %5.2f", alocacao[contador].valorTotal);
				if(alocacao[contador].parceiro == 1){
					printf("\n\tParceiro: Sim");
				}else{
					printf("\n\tParceiro: Nao");
				}
				printf("\n\tData retirada: %s", alocacao[contador].dataInicioAlocacao);
				printf("\n\tData entrega : %s", alocacao[contador].dataFimAlocacao);
				printf("\n\tMarca veiculo: %s", marcas[alocacao[contador].posicaoMarcaVeiculo]);
				printf("\n\tVeiculo: %s \tPlaca: %s", alocacao[contador].veiculoEscolhido, alocacao[contador].placaVeiculo);
				if(alocacao[contador].status == 0){
				printf("\n\tSituacao: Livre\n\n");
				}else if(alocacao[contador].status == 1){
					printf("\n\tSituacao: Alugado\n\n");
				}else{
					printf("\n\tSituacao: Agendado\n\n");
				}
                printf("\n\tDeseja realmente exlucir? s/n: ");
                scanf("%s",&resp);
				fflush(stdin);
				
                if ( ( resp == 'S' ) || ( resp == 's' ) )
                {
                	if(tlAlocacao - 1 != 0){
					
	                    for(int i = contador; i <= tlAlocacao - 1; i++){
	                     	
	                     	alocacao[i].cod                			= alocacao[i + 1].cod ;
							strcpy(alocacao[i].nome        			, alocacao[i + 1].nome );
							strcpy(alocacao[i].cpf         			, alocacao[i + 1].cpf );
							alocacao[i].idade              			= alocacao[i + 1].idade;
							alocacao[i].vlrDiaria          			= alocacao[i + 1].vlrDiaria;
							alocacao[i].qtdDiaria          			= alocacao[i + 1].qtdDiaria;
							alocacao[i].parceiro		   			= alocacao[i + 1].parceiro ;
							alocacao[i].valorTotal         			= alocacao[i + 1].valorTotal;
							alocacao[i].vlrDesconto        			= alocacao[i + 1].vlrDesconto ;
							strcpy(alocacao[i].veiculoEscolhido		, alocacao[i + 1].veiculoEscolhido);
							alocacao[i].posicaoMarcaVeiculo  		= alocacao[i + 1].posicaoMarcaVeiculo;
							alocacao[i].posicaoModeloveiculo 		= alocacao[i + 1].posicaoModeloveiculo;
							strcpy(alocacao[i].dataInicioAlocacao	, alocacao[i + 1].dataInicioAlocacao);
							strcpy(alocacao[i].dataFimAlocacao		, alocacao[i + 1].dataFimAlocacao);
							strcpy(alocacao[i].placaVeiculo			, alocacao[i + 1].placaVeiculo);
							alocacao[i].status						= alocacao[i + 1].status;
							
						}
					}else{
						for(int i = contador; i <= tlAlocacao - 1; i++){
	                     	
	                     	alocacao[i].cod                			= 0 ;
							strcpy(alocacao[i].nome					, "");
							strcpy(alocacao[i].cpf                	, "");
							alocacao[i].idade              			= 0 ;
							alocacao[i].vlrDiaria          			= 0 ;
							alocacao[i].qtdDiaria          			= 0 ;
							alocacao[i].parceiro					= 0 ;
							alocacao[i].valorTotal         			= 0 ;
							alocacao[i].vlrDesconto        			= 0 ;
							strcpy(alocacao[i].veiculoEscolhido		, "");
							alocacao[i].posicaoMarcaVeiculo  		= 0 ;
							alocacao[i].posicaoModeloveiculo 		= 0 ;
							strcpy(alocacao[i].dataInicioAlocacao	, "");
							strcpy(alocacao[i].dataFimAlocacao		, "");
							strcpy(alocacao[i].placaVeiculo			, "");
							alocacao[i].status						= 0;
							
						}
					}
					tlAlocacao--;	
					
					printf("\n\t======Exclusao feita com sucesso======\n");
					sleep(1);
                    break;
                }
                else
                {
                    if ( ( resp == 'N' ) || ( resp == 'n' ) )
                    {
                    	opcaoInvalida();
                        printf("\tExclusao cancelada!\n");
                        sleep(1);
                        break;
                    }
                }
			}
			contador++;
   		}
    }else{
		opcaoInvalida();
    	printf("\n\tCodigo nao encontrado!!\n\n");
    	sleep(1);
    }
	
}

// verificar posicao da alocacao
int verificaPosicaoAlocacao(void){
    int contador = 0;
	
    while ( contador <= SIZE )
    {

        if ( alocacao[contador].cod == 0 )
            return(contador);

        contador++;

    }

    return(-1);

}

// verificar se o veiculo foi alugado
int verificaPosicaoVeiculoAlugado( int OptMarca, int OptModelo ){
    int contador = 0;

    while ( contador <= tlAlocacao - 1 )
    {
    	if ( alocacao[contador].posicaoMarcaVeiculo == OptMarca - 1 && alocacao[contador].posicaoModeloveiculo == OptModelo - 1 )
    		if(alocacao[contador].status == 1){
    			return(0);
            }else if( alocacao[contador].status == 2){
            	return(2);
			}
        contador++;
    }

    return(1);

}

// Retorna posicao da alocacao
int retornaPosicaoAlocacao(int marca, int modelo){
	
	int contador = 0;
    for (int i = 0; i <= tlVeiculo - 1 ; i++)
    {
        if (  alocacao[i].posicaoMarcaVeiculo == marca && alocacao[i].posicaoModeloveiculo == modelo ){
        	return(contador);
		}
        contador++;
    }
	
}
/*==================================================================================*/
/*								FIM CONTROLE DE ALOCACAO    						*/
/*==================================================================================*/


#endif

