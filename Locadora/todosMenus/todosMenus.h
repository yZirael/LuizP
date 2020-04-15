#ifndef TODOS_MENUS_H
#define TODOS_MENUS_H

int incluirVeiculosDoArray();
int contaQtdeMarca(int marca);
int contaPosicaoMarca(int marca);
int retornaPosicaoLocacao(int marca, int modelo);

/*==================================================================================*/
/*							INICIO AREA DO MENU PRINCIPAL    						*/
/*==================================================================================*/
void carregarDados(){
	incluirVeiculosDoArray();
}

// Menu principal
void menuPrincipal() {
	carregarDados();
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                          Menu principal                               *");
	printf("\n\t*****************************************************************************************\n");
	printf("\t[1] Controle de Loca��o\n");
	printf("\t[2] Controle de Pessoas\n");
	printf("\t[3] Controle de Ve�culos\n");
	printf("\t[4] Controle de Agendamento\n");
	printf("\t[5] Sair\n");
	printf("\n\t*****************************************************************************************");
	printf ("\n\tEscolha uma op��o=> ");
	
	
}

/*==================================================================================*/
/*							INICIO AREA DO MENU SEGUNDARIO    						*/
/*==================================================================================*/

// Menu de alocao
void controleLocacao(){
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                       Controle de Loca��o                             *");
	printf("\n\t*****************************************************************************************\n");
	printf("\t[1] Cadastrar Loca��o\n");
	printf("\t[2] Consultar Loca��o\n");
	printf("\t[3] Listar Loca��o\n");
	printf("\t[4] Alterar Loca��o\n");
	printf("\t[5] Devolver Loca��o\n");
	printf("\t[6] Excluir Loca��o\n");
	printf("\t[7] Voltar\n");
	printf("\n\t*****************************************************************************************");
	printf ("\n\tEscolha uma op��o=> ");
	
}

// Menu dde pessoaa
void controlePessoa(){
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                       Controle de Pessoas                             *");
	printf("\n\t*****************************************************************************************\n");
	printf("\t[1] Cadastrar Pessoas\n");
	printf("\t[2] Consultar Pessoas por CPF\n");
	printf("\t[3] Listar Pessoas\n");
	printf("\t[4] Alterar Pessoas\n");
	printf("\t[5] Remover Pessoas\n");
	printf("\t[6] Voltar\n");
	printf("\n\t*****************************************************************************************");
	printf ("\n\tEscolha uma op��o=> ");
}

// Menu Controle veiculo
void controleVeiculo(){
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                       Controle de Ve�culo                             *");
	printf("\n\t*****************************************************************************************\n");
	printf("\t[1] Cadastrar Ve�culo\n");
	printf("\t[2] Consulta de Ve�culo\n");
	printf("\t[3] Listar Ve�culo\n");
	printf("\t[4] Alterar Ve�culo\n");
	printf("\t[5] Excluir Ve�culo\n");
	printf("\t[6] Voltar\n");
	printf("\n\t*****************************************************************************************");
	printf ("\n\tEscolha uma op��o=> ");
}

// Menu Agendar veiculo
void controleAgendamentoveiculo(){
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                            Controle de Agendamento de Ve�culo                         *");
	printf("\n\t*****************************************************************************************\n");
	printf("\t[1] Cadastrar agendamento\n");
	printf("\t[2] Consultar agendamento\n");
	printf("\t[3] Listar agendamento\n");
	printf("\t[4] Alterar agendamento\n");
	printf("\t[5] Encerrar agendamento\n");
	printf("\t[6] Excluir de agendamento\n");
	printf("\t[7] Voltar\n");
	printf("\n\t*****************************************************************************************");
	printf ("\n\tEscolha uma op��o=> ");
}

// Lista das marcas
void listaMarcas(void) {
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                    Lista de Marcas                                    *");
	printf("\n\t*****************************************************************************************\n");
	
	for (int i = 0; i <= 11; i++) {
		printf("\n\t[%d] %s ", i + 1, marcas[i]);
	}
	
	
	printf("\n\t[0] Voltar\n");
	printf("\n\t*****************************************************************************************");
	printf ("\n\tEscolha uma op��o=> ");
}

// Lista das marcas
void listaTodosVeiculos(void) {
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                  Lista Total de Ve�culos                              *");
	printf("\n\t*****************************************************************************************\n");
							
	int qtdeVecMarc, marcaVec = 0, posicaoLocacao;
	printf("\t    Marca  \tModelo \t\tValor \t\tSitua��o \tDt. Devolu��o");
	printf("\n\t*****************************************************************************************\n");
	for(int i = 0; i < tlVeiculo; i++){
		
		qtdeVecMarc = contaQtdeMarca(marcaVec);
		
			for (int j = 0; j < tlVeiculo; j++){
				
				if(marcaVec ==  cadVeiculo[j].codMarca){
					printf("\n\t[%d] %s %s \t  %5.2f ", i + 1, cadVeiculo[j].marca, cadVeiculo[j].modeloVec, cadVeiculo[j].vlrDiaria);
				 
					if(cadVeiculo[j].status == 0){
						printf("\tLivre   ");
					}else if(cadVeiculo[j].status == 1){
						printf("\tAlugado ");
					}else{
						printf("\tAgendado");
					}
					posicaoLocacao = retornaPosicaoLocacao(cadVeiculo[j].codMarca, cadVeiculo[j].codModelo);
					
					if(Locacao[posicaoLocacao].posicaoMarcaVeiculo == cadVeiculo[j].codMarca && Locacao[posicaoLocacao].posicaoModeloveiculo == cadVeiculo[j].codModelo){
						printf("\t%s", Locacao[posicaoLocacao].dataFimLocacao);
					}
					
					
				}
			}
		if( qtdeVecMarc != 0){	
			printf("\n");
		}
		marcaVec += 1;
		
	}
	
	printf("\n\t[0] Voltar\n");
	printf("\n\t*****************************************************************************************");
	printf ("\n\tEscolha uma op��o=> ");
}

//  Lista de veiculos e os valores para escolha
void listaVeiculo(int marcaVec){
	
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                                    Lista de Ve�culos                                  *");
	printf("\n\t*****************************************************************************************\n");
	
	int qtdeVecMarc, posicao = 0, posicaoLocacao;
	
	qtdeVecMarc = contaQtdeMarca(marcaVec);
	
	printf("\t    Marca  \tModelo \t\tValor \t\tSitua��o \tDt. Devolu��o");
	printf("\n\t*****************************************************************************************\n");
	if( qtdeVecMarc != 0){
	
		for (int j = 0; j < tlVeiculo; j++){
			
			if(marcaVec ==  cadVeiculo[j].codMarca){
				printf("\n\t[%d] %s %s \t  %5.2f ", posicao + 1, cadVeiculo[j].marca, cadVeiculo[j].modeloVec, cadVeiculo[j].vlrDiaria);
				
				if(cadVeiculo[j].status == 0){
					printf("\tLivre   ");
				}else if(cadVeiculo[j].status == 1){
					printf("\tAlugado ");
				}else{
					printf("\tAgendado");
				}
				posicaoLocacao = retornaPosicaoLocacao(cadVeiculo[j].codMarca, cadVeiculo[j].codModelo);
				
				if(Locacao[posicaoLocacao].posicaoMarcaVeiculo == cadVeiculo[j].codMarca && Locacao[posicaoLocacao].posicaoModeloveiculo == cadVeiculo[j].codModelo){
					printf("\t%s", Locacao[posicaoLocacao].dataFimLocacao);
				}	
				
				posicao++;
			}
		}
	}
		
	

	printf("\n\t[0] Digite zero para Voltar\n");
	printf("\n\t*****************************************************************************************");
	printf ("\n\tEscolha uma op��o=> ");
	
}

/*==================================================================================*/
/*								FIM AREA DO MENU SEGUNDARIO    						*/
/*==================================================================================*/

#endif 
