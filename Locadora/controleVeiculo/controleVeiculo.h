#ifndef CONTROLE_VEICULO_H
#define CONTROLE_VEICULO_H

int verificaPosicaoVeiculo(void);
	
/*==================================================================================*/
/*								INICIO CONTROLE DE VEICULO 							*/
/*==================================================================================*/

// inserir veiculo na lista
void inserirVeiculoLista(int optMenu){    
	int qtdeVecMarc;
	
	limpaTela();
	
	int posicao = verificaPosicaoVeiculo();
	
	tlVeiculo += 1;
	
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                        Cadastro de veículo                            *");
	printf("\n\t*****************************************************************************************\n");
	
	
	printf("\n\tCódigo do cadastro:  %d \n", tlVeiculo);
	cadVeiculo[posicao].cod = tlVeiculo;
	
	strcpy(cadVeiculo[posicao].marca, marcas[optMenu - 1]);
	cadVeiculo[posicao].codMarca = optMenu - 1;
	
	qtdeVecMarc = contaQtdeMarca(optMenu - 1); //conta 
	
	cadVeiculo[posicao].codModelo = qtdeVecMarc -1;
	
	printf("\n\tMarca: %s\n", cadVeiculo[posicao].marca);
	
	printf("\n\tAno: ");
	scanf("%d", &cadVeiculo[posicao].ano );
	limparBuffer();
		
	printf("\n\tCor: ");
	fflush(stdin);
	gets(cadVeiculo[posicao].corVeiculo);
	
	
	printf("\n\tModelo: ");
	fflush(stdin);
	gets( cadVeiculo[posicao].modeloVec);
	
	int len = strlen(cadVeiculo[posicao].modeloVec);
	
	if( len < 9){
		for(int i = len; i <=9; i++){
			strcat(cadVeiculo[posicao].modeloVec, " ");
		}
	}
   	
	printf("\n\tPlaca: " );
	fflush(stdin);
	gets(cadVeiculo[posicao].placaVeiculo);
	
	printf("\n\tvalor: ");
	scanf("%f", &cadVeiculo[posicao].vlrDiaria);
	limparBuffer();
	printf("\n\tPressione entrer para continuar. ");
	limparBuffer();
	
}

// listar veiculo
void consultarVeiculos(void){
	int contador = 0, codigo;
	
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                       Consulta de Veículo                             *");
	printf("\n\t*****************************************************************************************\n");
	printf("\n\tEntre com o código => ");
    scanf("%d",&codigo);
	limparBuffer();
	
    while ( contador <= tlVeiculo ){

        if (cadVeiculo[contador].cod == codigo)
        {
          	printf("\n\tCod: %d",       cadVeiculo[contador].cod);
			printf("\n\tAno: %d",       cadVeiculo[contador].ano);
			printf("\n\tCor: %s",       cadVeiculo[contador].corVeiculo);
			printf("\n\tMarca: %s",     cadVeiculo[contador].marca);
			printf("\n\tModelo: %s",    cadVeiculo[contador].modeloVec);
			printf("\n\tPlaca: %s",     cadVeiculo[contador].placaVeiculo);
			printf("\n\tValor: %3.2f\n",cadVeiculo[contador].vlrDiaria);
			
			if(cadVeiculo[contador].status == 0){
				printf("\n\tSituação: Livre\n\n");
			}else if(cadVeiculo[contador].status == 1){
				printf("\n\tSituação: Alugado\n\n");
			}else{
				printf("\n\tSituação: Agendado\n\n");
			}
		}
		contador++;
	}
	printf("\n\t================================== Fim de registro! =====================================\n\n");
		
	printf("\n\tPressione entrer para continuar. ");
	limparBuffer();
	
}

// listar veiculo
void listarVeiculos(void){
	
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                       Lista de Veículos                               *");
	printf("\n\t*****************************************************************************************\n");
	
	int contaLinha = 8;
	
	for(int i = 0; i < tlVeiculo; i++){
		
		printf("\n\tCod: %d",cadVeiculo[i].cod);
		printf("\tMarca: %s", cadVeiculo[i].marca);
		printf("\n\tModelo: %s", cadVeiculo[i].modeloVec);
		printf("\tPlaca: %s", cadVeiculo[i].placaVeiculo);
		printf("\tAno: %d",cadVeiculo[i].ano);
		printf("\n\tCor: %s", cadVeiculo[i].corVeiculo);
		printf("\n\tValor: %3.2f",cadVeiculo[i].vlrDiaria);
		printf("\tCodMarc: %d", cadVeiculo[i].codMarca);
		printf("\tCodVec: %d",cadVeiculo[i].codModelo);
		
		if(cadVeiculo[i].status == 0){
			printf("\n\tSituação: Livre\n");
		}else if(cadVeiculo[i].status == 1){
			printf("\n\tSituação: Alugado\n");
		}else{
			printf("\n\tSituação: Agendado\n");
		}
		
		printf("\n\t================================== Fim de registro! =====================================\n");
		
		if(contaLinha == 48){
			printf("\n\tPressione entrer para continuar. ");
			limparBuffer();
			contaLinha = 8;
		}
		
		contaLinha += 8;	
	}
	printf("\n\t=======================  Qtde de Registros Cadastrados: %d  =============================\n", tlVeiculo);
	printf("\n\t============================== Fim de todos Registro ====================================\n");
	printf("\n\tPressione entrer para continuar. ");
	limparBuffer();
}

// Função para alterar pessoa
void alterarVeiculo(void){
	int opcao, contador = 0, codigo;
	
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                     Alteração de Veículo                              *");
	printf("\n\t*****************************************************************************************\n");
	printf("\n\tEntre com o código a ser alteraão => ");
    scanf("%d",&codigo);
	limparBuffer();
		
    int retorno = verificaPosicaoVeiculo();
    
     if ( retorno > 0 ){
    	
		while ( contador < tlVeiculo ){
	
	        if (cadVeiculo[contador].cod == codigo)
	        {
	            pontoMenuOpcao:
            	limpaTela(); // limpa tela
            	
            	printf("\n\n\t*****************************************************************************************\n");
				printf("\t*                                     Alteraão de Veículo                               *");
				printf("\n\t*****************************************************************************************\n");
				
			    printf("\n\tCod: %d",cadVeiculo[contador].cod);
				printf("\n\t[1] Ano: %d",cadVeiculo[contador].ano);
				printf("\n\t[2] Cor: %s", cadVeiculo[contador].corVeiculo);
				printf("\n\t[3] Marca: %s", cadVeiculo[contador].marca);
				printf("\n\t[4] Modelo: %s", cadVeiculo[contador].modeloVec);
				printf("\n\t[5] Placa: %s", cadVeiculo[contador].placaVeiculo);
				printf("\n\t[6] Valor: %3.2f\n",cadVeiculo[contador].vlrDiaria);
				
				if(cadVeiculo[contador].status == 0){
					printf("\n\tSituação: Livre\n\n");
				}else if(cadVeiculo[contador].status == 1){
					printf("\n\tSituação: Alugado\n\n");
				}else{
					printf("\n\tSituação: Agendado\n\n");
				}
				printf("\n\t[8] Sair e Salvar!");
				
				pontoMenuVeiculo:
				
				printf("\n\n\tQual campo deseja alterar? => ");
				fflush(stdin);
				scanf("%d" , &opcao);
				
				switch(opcao)
				{
					case 1:
						printf("\n\tAno: " );
						scanf("%d" , &cadVeiculo[contador].ano);
						limparBuffer();
						goto pontoMenuOpcao;
						
					case 2:
						printf("\n\tCor: ");
						fflush(stdin);
						gets(cadVeiculo[contador].corVeiculo);
						goto pontoMenuOpcao;
						
					case 3:
						printf("\n\tMarca: ");
						fflush(stdin);
						gets(cadVeiculo[contador].marca);
						goto pontoMenuOpcao;
						
					case 4:
						printf("\n\tModelo: ");
						fflush(stdin);
						gets( cadVeiculo[contador].modeloVec);
						goto pontoMenuOpcao;
						
					case 5:
						printf("\n\tPlaca: " );
						fflush(stdin);
						gets(cadVeiculo[contador].placaVeiculo);
						goto pontoMenuOpcao;
						break;
					
					case 6:
						printf("\n\tValor diária: ");
						scanf("%f", &cadVeiculo[contador].vlrDiaria);
						limparBuffer();
							
						
					case 7:
						printf("\n\tSituação: ");
						scanf("%d", &cadVeiculo[contador].status);
						limparBuffer();	
						goto pontoMenuOpcao;
						break;
					case 8:
						printf("\n\tDados salvo com sucesso!");	
						sleep(1);
						break;
						
					default:
						opcaoInvalida();
						printf("\n\tOpão inválida!\n\n");
						sleep(1);
						goto pontoMenuVeiculo;
				}
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

//Função para excluir pessoa
void excluirVeiculo(void){
    int resp, codigo, contador = 0;
    
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                     Excluir de Veículo                                *");
	printf("\n\t*****************************************************************************************\n");
	printf("\n\tEntre com o código a ser excluído => ");
    scanf("%d",&codigo);
	limparBuffer();
	
	int returno = verificaPosicaoPessoa();
	
	if(returno <= tlVeiculo){
	    while ( contador <= tlVeiculo - 1 )
	    {
    		if ( cadVeiculo[contador].cod == codigo )
	        {
	        	pontoMenuOpcao:
            	limpaTela(); // limpa tela
            	
            	printf("\n\n\t*****************************************************************************************\n");
				printf("\t*                                     Excluir de Veículo                                *");
				printf("\n\t*****************************************************************************************\n");
				
			    printf("\n\tCod: %d",cadVeiculo[contador].cod);
				printf("\n\tAno: %d",cadVeiculo[contador].ano);
				printf("\n\tCor: %s", cadVeiculo[contador].corVeiculo);
				printf("\n\tMarca: %s", cadVeiculo[contador].marca);
				printf("\n\tModelo: %s", cadVeiculo[contador].modeloVec);
				printf("\n\tPlaca: %s", cadVeiculo[contador].placaVeiculo);
				printf("\n\tValor: %3.2f\n",cadVeiculo[contador].vlrDiaria);
				
				printf("\n\tDeseja realmente excluir? s/n: ");
                scanf("%s",&resp);
				fflush(stdin);
				
                if ( ( resp == 'S' ) || ( resp == 's' ) )
                {
                	if( tlVeiculo -1 != 0){
	                     for(int i = contador; i <= tlVeiculo - 1; i++){
	                     	
	                     	cadVeiculo[i].cod        		  	= cadVeiculo[i + 1].cod;
							cadVeiculo[i].ano        		  	= cadVeiculo[i + 1].ano;
							strcpy(cadVeiculo[i].corVeiculo		, cadVeiculo[i + 1].corVeiculo);
							strcpy(cadVeiculo[i].marca			, cadVeiculo[i + 1].marca);
							strcpy(cadVeiculo[i].modeloVec		, cadVeiculo[i + 1].modeloVec);
							strcpy(cadVeiculo[i].placaVeiculo	, cadVeiculo[i + 1].placaVeiculo);
							cadVeiculo[i].vlrDiaria          	= cadVeiculo[i + 1].vlrDiaria;
							cadVeiculo[i].status	          	= cadVeiculo[i + 1].status;
							cadVeiculo[i].codMarca	          	= cadVeiculo[i + 1].codMarca;
							cadVeiculo[i].codModelo	          	= cadVeiculo[i + 1].codModelo;
							cadVeiculo[i].posicao	          	= cadVeiculo[i + 1].posicao;
						
						}
						tlVeiculo--;	
				   }else{
						for(int i = contador; i <= tlVeiculo - 1; i++){
	                     	
	                     	cadVeiculo[i].cod        		   	= 0;
							cadVeiculo[i].ano         		   	= 0;
							strcpy(cadVeiculo[i].corVeiculo		, "");
							strcpy(cadVeiculo[i].marca			, "");
							strcpy(cadVeiculo[i].modeloVec		, "");
							strcpy(cadVeiculo[i].placaVeiculo	, "");
							cadVeiculo[i].vlrDiaria           	= 0;
							cadVeiculo[i].status	          	= 0;
							cadVeiculo[i].codMarca	          	= 0;
							cadVeiculo[i].codModelo	          	= 0;
							cadVeiculo[i].posicao	          	= 0;
						
						}
						tlVeiculo--;	
					}
					printf("\n\t=============================== Exclusão feita com sucesso ==============================\n");
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

//inclusao dos veiculos do array dentro da lista
int incluirVeiculosDoArray(void){
	int contador = 0, retPosVeic;
	
	retPosVeic = verificaPosicaoLocacao();
	
	if(retPosVeic == 0 ){
		tlVeiculo = 20;
		tlLocacao = 2;
		tlPessoa = 2;
	
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 5; j++){
				cadVeiculo[contador].cod = contador + 1;
				cadVeiculo[contador].ano = anoVeiculo[j];
				
				strcpy(cadVeiculo[contador].corVeiculo, coresVeiculo[j]);
				strcpy(cadVeiculo[contador].marca, marcas[i]);
				strcpy(cadVeiculo[contador].modeloVec, veiculos[i][j]);
				strcpy(cadVeiculo[contador].placaVeiculo, placaVeiculo[j]);
				
				cadVeiculo[contador].vlrDiaria = valoresDiaria[i][j];
				cadVeiculo[contador].codMarca  = i;
				cadVeiculo[contador].codModelo = j;
				cadVeiculo[contador].posicao = contador;
				contador++;
			}
		}
	
		
		contador = 0;
		retPosVeic = retornaPosicaoVeiculoEscolhido(2, 1);
				
		cadVeiculo[retPosVeic].status = 1;
		/*================================= teste Cadastro  Locacao ==================================*/
		Locacao[contador].cod                		= 1;
		strcpy(Locacao[contador].nome        		, "Pica Pau da Floresta" );
		strcpy(Locacao[contador].cpf         		, "123456" );
		Locacao[contador].idade              		= 33;
		Locacao[contador].vlrDiaria          		= cadVeiculo[retPosVeic].vlrDiaria;
		Locacao[contador].qtdDiaria          		= 4;
		Locacao[contador].parceiro		   			= 2 ;
		Locacao[contador].valorTotal         		= 260;
		Locacao[contador].vlrDesconto        		= 0 ;
		strcpy(Locacao[contador].veiculoEscolhido	, cadVeiculo[retPosVeic].modeloVec);
		Locacao[contador].posicaoMarcaVeiculo  		= cadVeiculo[retPosVeic].codMarca;
		Locacao[contador].posicaoModeloveiculo 		= cadVeiculo[retPosVeic].codModelo;
		strcpy(Locacao[contador].dataInicioLocacao	, "25/10/2017 08:20:34");
		strcpy(Locacao[contador].dataFimLocacao		, "06/11/2017 08:20:34");
		strcpy(Locacao[contador].placaVeiculo		, cadVeiculo[retPosVeic].placaVeiculo);
		Locacao[contador].status				 		= 1;
		
		retPosVeic = retornaPosicaoVeiculoEscolhido(3, 2);
				
		cadVeiculo[retPosVeic].status = 1;
		
		Locacao[contador + 1].cod                		= 2;
		strcpy(Locacao[contador + 1].nome        		, "Urso Polar" );
		strcpy(Locacao[contador + 1].cpf         		, "456789" );
		Locacao[contador + 1].idade              		= 35;
		Locacao[contador + 1].vlrDiaria          		= 65;
		Locacao[contador + 1].qtdDiaria          		= 4;
		Locacao[contador + 1].parceiro		   			= 2 ;
		Locacao[contador + 1].valorTotal         		= 260;
		Locacao[contador + 1].vlrDesconto        		= 0 ;
		strcpy(Locacao[contador + 1].veiculoEscolhido		, cadVeiculo[retPosVeic].modeloVec);
		Locacao[contador + 1].posicaoMarcaVeiculo  		= cadVeiculo[retPosVeic].codMarca;
		Locacao[contador + 1].posicaoModeloveiculo 		= cadVeiculo[retPosVeic].codModelo;
		strcpy(Locacao[contador + 1].dataInicioLocacao	, "25/10/2017 14:20:34");
		strcpy(Locacao[contador + 1].dataFimLocacao		, "31/10/2017 14:20:34");
		strcpy(Locacao[contador + 1].placaVeiculo		, cadVeiculo[retPosVeic].placaVeiculo);
		Locacao[contador + 1].status				 		= 1;
		
		/*=============================================================================================*/
		contador = 0;
		pessoa[contador].cod   				= 1 ;
		strcpy(pessoa[contador].nome		, "Paulo Coelho Orelhão");
		pessoa[contador].idade   			= 65;
		strcpy(pessoa[contador].rg      	, "123456");
		strcpy(pessoa[contador].cpf			, "145");
		strcpy(pessoa[contador].cargo		, "");
		pessoa[contador].salario 			= 0;
		strcpy(pessoa[contador].sexo 		, "M");
		pessoa[contador].funcionario		= 0;
		
		pessoa[contador + 1].cod   			= 2 ;
		strcpy(pessoa[contador + 1].nome	, "Julia Robert Martelão");
		pessoa[contador + 1].idade   		= 45;
		strcpy(pessoa[contador + 1].rg      , "321456");
		strcpy(pessoa[contador + 1].cpf		, "146");
		strcpy(pessoa[contador + 1].cargo	, "");
		pessoa[contador + 1].salario 		= 0;
		strcpy(pessoa[contador + 1].sexo 	, "F");
		pessoa[contador].funcionario		= 0;
	}
	
}

// verificar posicao do veiculo
int verificaPosicaoVeiculo(void){
    int contador = 0;
	
    while ( contador <= SIZE )
    {

        if ( cadVeiculo[contador].cod == 0 )
            return(contador);

        contador++;

    }

    return(-1);

}

// Retorna posicao do veiculo escolhirdo
int retornaPosicaoVeiculoEscolhido(int marca, int modelo){
	
	int contador = 0;
    for (int i = 0; i <= tlVeiculo - 1 ; i++)
    {
        if (  cadVeiculo[i].codMarca == marca && cadVeiculo[i].codModelo == modelo ){
        	return(contador);
		}
        contador++;
    }
	
}

// conta quantida de carros da mesma marca
int contaQtdeMarca(int marca){
	int qtdeMarca = 0, contador = 0;
	
    while ( contador <= tlVeiculo - 1 )
    {

        if ( cadVeiculo[contador].codMarca == marca ){
        	qtdeMarca++;
		}
        
        contador++;
	}

    return qtdeMarca;
}

// verfica a primeira posicao da marca
int contaPosicaoMarca(int marca){
	
	int contador = 0;
	
    while ( contador <= tlVeiculo - 1 )
    {

        if ( cadVeiculo[contador].codMarca == marca ){
        	return contador;
		}
        
        contador++;
	}
}
/*==================================================================================*/
/*								FIM CONTROLE DE VEICULO	    						*/
/*==================================================================================*/

#endif
