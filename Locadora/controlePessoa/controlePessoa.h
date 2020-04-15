#ifndef CONTROLE_PESSOA_H
#define CONTROLE_PESSOA_H

char sexo[1];
int verificaPosicaoPessoa();
int verificaCodigoPessoa( char cpf[] );

/*==================================================================================*/
/*								INICIO CONTROLE DE PESSOA  							*/
/*==================================================================================*/
// inserir pessoa na lista
void inserirPessoaLista(int codigo){    
	char resp, cpf[15];
	int retorno;
	
	int posicao = codigo - 1;
	
	tlPessoa += 1;
	pontoCPF:
	limpaTela();
	
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                        Cadastro de pessoa                             *");
	printf("\n\t*****************************************************************************************\n");
	
	printf("\n\tCódigo do cadastro:  %d \n", codigo);
	pessoa[posicao].cod = codigo;
	
	
		
	printf("\n\tCPF: ");
	scanf("%s", &cpf);
	limparBuffer();
	
	retorno = verificaCodigoPessoa(cpf);
	if(retorno == 0){
		opcaoInvalida();
		printf("\n\tCPF já cadastrado!!\n");
		sleep(1);
		goto pontoCPF;
	}else{
		
		strcpy(pessoa[posicao].cpf, cpf);
		printf("\n\tNome: ");
		fflush(stdin);
		gets(pessoa[posicao].nome);
			
		pontoIdade:
			
		printf("\n\tIdade: ");
		scanf("%d", &pessoa[posicao].idade );
		limparBuffer();
		
		
		retorno = validaIdade(pessoa[posicao].idade);
			
		if(retorno == 1){
			opcaoInvalida();
			printf("\n\tIndade não pode ser menor que 18  ou maior que 120 !! Tente novamente!!\n");
			goto pontoIdade;
		
		}
		
		printf("\n\tRG: ");
		scanf("%s", &pessoa[posicao].rg);
		limparBuffer();
		
		printf("\n\tÉ funcionario? : S/N ");
		scanf("%s", &resp);
		limparBuffer();
		
		if ( ( resp == 'S' ) || ( resp == 's' ) ){
			
			pessoa[posicao].funcionario = 1;
			
			printf("\n\tCargo: ");
			fflush(stdin);
			gets(pessoa[posicao].cargo);
				
			printf("\n\tSalario: ");
			scanf("%f", &pessoa[posicao].salario);
			limparBuffer();
		}
	    
		pontoSexo:
			
		printf("\n\tSexo(M/F): ");
		fflush(stdin);
		scanf("%c", &sexo);
		
		for(int i = 0; i < 1; i++){
			if(sexo[i] != '\0'){
				if((sexo[i] == 'm') || (sexo[i] == 'M') || (sexo[i] == 'f') || (sexo[i] == 'F') ){
					strcpy(pessoa[posicao].sexo, sexo);
				}else{
					opcaoInvalida();
					printf("\n\tOpção inválida!! Tente novamente!!\n");
					sleep(1);
					goto pontoSexo;
				}		
			}else{
				opcaoInvalida();
				printf("\n\tOpção inválida!! Tente novamente!!\n");
				sleep(1);
				goto pontoSexo;
			}
		}	
	}

	
}

//conaultar pessoa
void consultaPessoa(){
	int contador = 0;
	char cpf[15];
	
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                        Consulta de pessoa                             *");
	printf("\n\t*****************************************************************************************\n");
	printf("\n\tEntre com o CPF => ");
    scanf("%s",&cpf);
	limparBuffer();
	
    while ( contador <= tlPessoa ){

        if (strcmp(pessoa[contador].cpf, cpf) == 0)
        {
          	printf("\n\tCódigo: %d" , pessoa[contador].cod);
        	printf("\n\tNome: %s", pessoa[contador].nome);
            printf("\n\tIdade: %d ", pessoa[contador].idade);
			printf("\n\tRG: %s", pessoa[contador].rg);
			printf("\n\tCPF: %s", pessoa[contador].cpf);
			
			if(pessoa[contador].funcionario == 1){
				printf("\n\tÉ funcionario? Sim");
				printf("\n\tCargo: %s" , pessoa[contador].cargo);
				printf("\n\tSalário: %5.2f", pessoa[contador].salario);
			}else{
				printf("\n\tEh funcionário? Nao");
			}
			printf("\n\tSexo: %s\n", pessoa[contador].sexo);
		}
		contador++;
	}
	printf("\n\t================================== Fim de registro! =====================================\n\n");
	
	printf("\n\tPressione entrer para continuar. ");
	limparBuffer();
}

//Função para listar pessoas cadastrados    
void listarPessoa(){ 
   
   int contaLinha = 12;
   	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                         Lista de Pessoa                               *");
	printf("\n\t*****************************************************************************************\n");
	
    for(int i = 0; i < tlPessoa; i++){
		printf("\n\tCódigo: %d" , pessoa[i].cod);
        printf("\n\tNome: %s", pessoa[i].nome);
        printf("\n\tIdade: %d ", pessoa[i].idade);
		printf("\n\tRG: %s", pessoa[i].rg);
		printf("\n\tCPF: %s", pessoa[i].cpf);
		if(pessoa[i].funcionario == 1){
			printf("\n\tÉ funcionário? Sim");
			printf("\n\tCargo: %s" , pessoa[i].cargo);
			printf("\n\tSalário: %5.2f", pessoa[i].salario);
		}else{
			printf("\n\tÉ funcionário? Não");
		}
		printf("\n\tSexo: %s\n", pessoa[i].sexo);
		
		printf("\n\t================================== Fim de registro! =====================================\n");
		
		if(contaLinha == 48){
			printf("\n\tPressione entrer para continuar. ");
			limparBuffer();
			contaLinha = 12;
		}
		
		contaLinha += 12;
	
	}
	printf("\n\n\t===========================  Qtde de Registros Cadastrados: %d ========================\n", tlPessoa);
	printf("\n\t============================== Fim de todos os registros! ===============================\n");
	
	printf("\n\tPressione entrer para continuar. ");
	limparBuffer();
	
}

// Função para alterar pessoa
void alterarPessoa(){
	int retornoIdade;
    int opcao, contador = 0;
	char cpf[15];
	
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                       Alteração de Pessoa                             *");
	printf("\n\t*****************************************************************************************\n");
	printf("\n\tEntre com o CPF a ser alteração => ");
    scanf("%s",&cpf);
	limparBuffer();
	
    int retorno = verificaPosicaoPessoa();
    
     if ( retorno > 0 ){
    	
		while ( contador < tlPessoa ){
	
	        if (strcmp(pessoa[contador].cpf, cpf) == 0)
	        {
	            if (pessoa[contador].cod == 1)
	            {
	            	
	            	while(opcao != 8){
		            	limpaTela(); // limpa tela
		            	
		            	printf("\n\n\t*****************************************************************************************\n");
						printf("\t*                                       Alteração de Pessoa                             *");
						printf("\n\t*****************************************************************************************\n");
						
						printf("\n\tCódigo: %d" , pessoa[contador].cod);
		            	printf("\n\t[1] Nome: %s", pessoa[contador].nome);
		                printf("\n\t[2] Idade: %d ", pessoa[contador].idade);
						printf("\n\t[3] RG: %s", pessoa[contador].rg);
						printf("\n\t[4] CPF: %s", pessoa[contador].cpf);
						printf("\n\t[5] Cargo: %s" , pessoa[contador].cargo);
						printf("\n\t[6] Salario: %5.2f", pessoa[contador].salario);
						printf("\n\t[7] Sexo: %s\n", pessoa[contador].sexo);
						printf("\n\t[8] Funcionário: %d\n", pessoa[contador].funcionario);
						printf("\n\t[9] Sair e Salvar!");
					
						printf("\n\n\tQual campo deseja alterar? => ");
						fflush(stdin);
						scanf("%d" , &opcao);
						
						switch(opcao)
						{
							case 1:
								printf("\n\tNome: ");
								limparBuffer();
								gets(pessoa[contador].nome);
								break;
							
							case 2:
								printf("\n\tIdade: ");
								scanf("%d" , &pessoa[contador].idade);
								limparBuffer();
								retornoIdade = validaIdade(pessoa[contador].idade);
			
								if(retornoIdade == 1){
										opcaoInvalida();
										printf("\n\tIndade não pode ser menor que 18  ou maior que 120 !! Tente novamente!!\n");
										break;
									
								}
								break;
							
							case 3:
								printf("\n\tRG: ");
								limparBuffer();
								scanf("%s",&pessoa[contador].rg);
								break;
							
							case 4:
								printf("\n\tCPF: ");
								limparBuffer();	
								gets(pessoa[contador].cpf);
								break;	
							
							case 5:
								printf("\n\tCargo: ");
								limparBuffer();	
								gets(pessoa[contador].cargo);
								break;
							
							case 6:
								printf("\n\tSalário: ");
								scanf("%f", &pessoa[contador].salario);
								limparBuffer();
								break;
							
							case 7:
								printf("\n\tSexo(M/F): ");
								scanf("%s", &sexo);
								
								if(sexo[0] != '\0'){
									if((sexo[0] == 'm') || (sexo[0] == 'M') || (sexo[0] == 'f') || (sexo[0] == 'F') ){
										strcpy(pessoa[contador].sexo, sexo);
										system("cls");
										break;
									}else{
										opcaoInvalida();
										printf("\n\tOpção inválida!! Tente novamente!!\n");
										sleep(1);
										break;
									}		
								}else{
									opcaoInvalida();
									printf("\n\tOpção inválida!! Tente novamente!!\n");
									sleep(1);
									break;
								}
									
								break;
							
							case 9:
								printf("\n\tFuncionário: S/N ");
								scanf("%c", &opcao);
								limparBuffer();
								
								if(opcao == 'S' || opcao == 's'){
									pessoa[contador].funcionario = 1;
								}else{
									pessoa[contador].funcionario = 0;
								}
								break;
							case 8:
								printf("\n\n\t============================= Dados salvo com sucesso! ================================\n");	
								printf("\n\t=================================== Fim da Alteração! ===================================\n");
								sleep(2);
								break;
							default:
								opcaoInvalida();
								printf("\n\tOpção inválida!\n");
								sleep(1);
								break;
							
						}
					}	
				
	            }
			}
			contador++;
		}
		
	}else{
		opcaoInvalida();
		printf("\n\tRegistro não encontrado!\n\n");
		sleep(1);
	}
	
	printf("\n\tPressione entrer para continuar. ");
	limparBuffer();
	
}

//Função para excluir pessoa
void excluirPessoa(){
    int codigo, contador = 0;
    char resp;
    printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                    Excluir Cadastro de Pessoa                         *");
	printf("\n\t*****************************************************************************************\n");
	printf("\n\tDigite o cádigo a ser excluir: ");
    scanf("%d", &codigo );
	limparBuffer();
	
	int returno = verificaPosicaoPessoa();
	
	if(returno <= tlPessoa){
		
	    while ( contador <= tlPessoa - 1 )
	    {
    		if ( pessoa[contador].cod == codigo )
	        {
	        	printf("\n\tCódigo: %d" ,    pessoa[contador].cod);
            	printf("\n\tNome: %s",       pessoa[contador].nome);
                printf("\n\tIdade: %d ",     pessoa[contador].idade);
				printf("\n\tRG: %s",         pessoa[contador].rg);
				printf("\n\tCPF: %s",         pessoa[contador].cpf);
				if(pessoa[contador].funcionario == 1){
					printf("\n\tÉ funcionário? Sim");
					printf("\n\tCargo: %s" , pessoa[contador].cargo);
					printf("\n\tSalario: %5.2f", pessoa[contador].salario);
				}else{
					printf("\n\tÉ funcionário? Não");
				}
				printf("\n\tSexo: %s\n",     pessoa[contador].sexo);
				
                printf("\n\tDeseja realmente excluir? s/n: ");
                scanf("%s",&resp);
				fflush(stdin);
				
                if ( ( resp == 'S' ) || ( resp == 's' ) )
                {
                	if( tlPessoa -1 != 0){
	                     for(int i = contador; i <= tlPessoa - 1; i++){
	                     	
	                     	pessoa[i].cod   		= pessoa[i + 1].cod;
							strcpy(pessoa[i].nome	, pessoa[i + 1].nome);
							pessoa[i].idade   		= pessoa[i + 1].idade;
							strcpy(pessoa[i].rg     , pessoa[i + 1].rg);
							strcpy(pessoa[i].cpf	, pessoa[i + 1].cpf);
							strcpy(pessoa[i].cargo	, pessoa[i + 1].cargo);
							pessoa[i].salario 		= pessoa[i + 1].salario;
							strcpy(pessoa[i].sexo 	, pessoa[i + 1].sexo);
							pessoa[i].funcionario 	, pessoa[i + 1].funcionario;						
						}
						tlPessoa--;	
						
					}else{
						for(int i = contador; i <= tlPessoa - 1; i++){
	                     	
	                     	pessoa[i].cod   			= 0 ;
							strcpy(pessoa[i].nome		, "");
							pessoa[i].idade   			= 0;
							strcpy(pessoa[i].rg      	, "");
							strcpy(pessoa[i].cpf		, "");
							strcpy(pessoa[i].cargo		, "");
							pessoa[i].salario 			= 0;
							strcpy(pessoa[i].sexo 		, "");
							pessoa[i].funcionario 		, 0;
						}
						tlPessoa--;	
					}
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
                printf("\n\t============================= Exclusão feita com sucesso! ===============================\n");
                sleep(1);
                break;
		    }
	    contador++;
   		}
	   
		if(tlPessoa <= 0){
			opcaoInvalida();
			printf("\n\tCdigo não encontrado!!\n\n");
			sleep(1);
		}		
		
	}else{
		opcaoInvalida();
    	printf("\n\tCódigo não encontrado!!\n\n");
    	sleep(1);
    }

}

// verificar posicao do pessoa
int verificaPosicaoPessoa(){
    int contador = 0;

	while ( contador <= SIZE )
    {
		
        if ( pessoa[contador].cod == 0 )
            return(contador);

        contador++;
	}

    return(-1);
}

// verificar se pessoa já foi cadastrado
int verificaCodigoPessoa( char cpf[] ){
    int contador = 0;

    while ( contador <= tlPessoa - 1 )
    {
        if ( strcmp(pessoa[contador].cpf, cpf) == 0 )
            return(0);

        contador++;
    }

    return(1);

}

// Retorna posicao da pessoa
int retornaPosicaoPessoa(int codigo){
	
	int contador = 0;
    for (int i = 0; i <= tlPessoa - 1 ; i++)
    {
        if (  pessoa[i].cod == codigo){
        	return(contador);
		}
        contador++;
    }
	return(-1);
}	
/*==================================================================================*/
/*								FIM CONTROLE DE PESSOA    							*/
/*==================================================================================*/


#endif
