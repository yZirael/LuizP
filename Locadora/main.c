#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <locale.h> //necessário para usar setlocale

#include "variasFuncoes/limpaTelaBufferOpcao.h"
#include "estruturaMatriz.h"
#include "calculoData/calculaDataDescontoValida.h"
#include "todosMenus/todosMenus.h"
#include "controlePessoa/controlePessoa.h"
#include "controleLocacao/controleLocacao.h"
#include "controleVeiculo/controleVeiculo.h"
#include "controleVeiculo/agendamentoVeiculo.h"

int retornaDataHoraAtual2(int *diaAtual,int *mesAtual,int *anoAtual, int *horaAtual, int *minutoAtual, int *segundoAtual);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	setlocale(LC_ALL,"");
	system("mode con:cols=110 lines=50");
	//limpaTela();//limpa a tela
					
	char resp;
	char dataHora;
		  
	int esc, opcaoMenu, OptMarca, OptModelo, posicao , retorno , codauxiliar;
	
	printf("\n\n\t*****************************************************************************************\n");
	printf("\t*                     Locadora de veículos!                     *");
	printf("\n\t*****************************************************************************************\n");
	
	menuPrincipal();
	scanf("%d", &esc); //recebe o valor escolhido do menu
	
	switch(esc) {
		case 1:
			
			while(opcaoMenu != 7){
				//Menu  Controle de Locacao
				pontoControleLocacao:		
				limpaTela();//limpa a tela
				
				controleLocacao();
				
				scanf("%d", &opcaoMenu);
				limparBuffer();
							
				switch(opcaoMenu) {
					
					case 1:
						
						pontoMarcaveiculo:
						
						limpaTela();//limpa a tela
						
						listaTodosVeiculos();
						
						scanf("%d", &OptMarca);
						limparBuffer();
						
						if(OptMarca == 0){
							goto pontoControleLocacao;
						}
						pontoModeloveiculo:
							
						limpaTela();//limpa a tela
							
						listaVeiculo(OptMarca-1);
						scanf("%d", &OptModelo);
						
						if(OptModelo < 0){
							opcaoInvalida();
							printf("\n\tOpção inválida! Tente novamente!\n\n");
							sleep(1);
							goto pontoModeloveiculo;
						}
						if(OptModelo == 0){
							goto pontoMarcaveiculo;
						}
						limparBuffer();
						limpaTela();//limpa a tela
								
						retorno = verificaPosicaoVeiculoAlugado(OptMarca, OptModelo);
	
					if(retorno == 1){
						
						inserirLocacaoLista(OptMarca, OptModelo);
						
					}else if(retorno == 2){
						
						opcaoInvalida();
						printf("\n\n\t*****************************************************************************************\n");
						printf("\t*                                       Aluguel de Veículo                                *");
						printf("\n\n\t*****************************************************************************************\n");
	
						printf("\n\tVeiculo esta agendado!");
						sleep(2);
						goto pontoModeloveiculo;
					}else{
						opcaoInvalida();
						printf("\n\n\t*****************************************************************************************\n");
						printf("\t*                                       Aluguel de Veículo                              *");
						printf("\n\t*****************************************************************************************\n");
						printf("\n\tVeículo já está alugado!");
						printf("\tSó pode ser agendado!");
						sleep(2);
						goto pontoModeloveiculo;
					}
					
						goto pontoControleLocacao;
						break;
						
					case 2:
						consultaLocacao();
						break;
					
					case 3:
						listarLocacao();
						break;
							
					case 4:
						alterarLocacao();
						break;
					case 5:
						devolucaoLocacao();
					 	break;
					case 6:
						excluirLocacao();
					 	break;
					case 7:
						return main();
						break;
					default:
						opcaoInvalida();
						printf("\n\tOpção inválida!\n\n");
						sleep(1);
						break;
				
				}// Fim do switch Controle de Alocação
			}// Fim do while Controle de Alocação
		
		case 2:
			
			while(opcaoMenu != 6){
				
				limpaTela();//limpa a tela
					
				controlePessoa();
				
				scanf("%d", &opcaoMenu);
				limparBuffer();
				limpaTela();//limpa a tela
			
				switch(opcaoMenu) {
					case 1:
						posicao = verificaPosicaoPessoa();
						
						if(posicao != -1)
						{
							codauxiliar = posicao + 1;
							
							inserirPessoaLista(codauxiliar);
							printf("\n\tDados cadastrados com sucesso!");
	    					break;
						}else{
							opcaoInvalida();
							printf("\n\tNão e possível realizar mais cadastros");
							sleep(1);
						}
						break;
					
					case 2:
						consultaPessoa();
						break;
	
					case 3:
						listarPessoa();
						break;
										
					case 4:
						alterarPessoa();
						break;
					
					case 5:
						excluirPessoa();
						break;
						
					case 6:
						return main();
					
					default:
						opcaoInvalida();
						printf("\n\tOpção inválida!\n\n");
						sleep(1);
						break;
				} // fim switch pessoa
					
			} // fim while pessoa	
			break;
			
		case 3:
			
			while(opcaoMenu != 6){
				
				pontoControleVeiculo:
				limpaTela(); //limpa a tela	
				controleVeiculo();
				
				scanf("%d", &opcaoMenu);
				limparBuffer();
				limpaTela(); //limpa a tela
				
				
				switch (opcaoMenu){
					case 1:
						listaMarcas();
						scanf("%d", &OptMarca);
						limparBuffer();
						
						if(OptMarca == 0){
							goto pontoControleVeiculo;
						}
						
						inserirVeiculoLista(OptMarca);
						break;
						
					case 2:
						consultarVeiculos();
						break;
						
					case 3:
						listarVeiculos();
						break;
						
					case 4:
						alterarVeiculo();
						break;
					case 5:
						excluirVeiculo();
						break;
					case 6:
						return main();
					
					default:
						opcaoInvalida();
						printf("\n\tOpção inválida!\n\n");
						sleep(1);
						break;
				}// fim switch veiculo
			}
			return main();
		
		case 4:
			
			while(opcaoMenu != 7){
			
				pontoAgendamento:
				limpaTela(); //limpa a tela	
				controleAgendamentoveiculo();
				
				scanf("%d", &opcaoMenu);
				limparBuffer();
				limpaTela();//limpa a tela
			
				switch(opcaoMenu){
					
					case 1:
							
						pontoModelo:
							
						limpaTela();//limpa a tela
						
						listaTodosVeiculos();
						
						scanf("%d", &OptMarca);
						
						limpaTela();//limpa a tela
						if(OptMarca == 0){
							goto pontoAgendamento;
						}
						listaVeiculo(OptMarca-1);
							scanf("%d", &OptModelo);
							
						if(OptModelo > 6){
							opcaoInvalida();
							printf("\n\tOpção inválida! Tente novamente!\n\n");
							sleep(1);
							goto pontoModelo;
						}
						if(OptModelo == 0){
							goto pontoAgendamento;
						}
						limparBuffer();
						limpaTela();//limpa a tela
						
						retorno = verificaPosicaoVeiculoAgendado(OptMarca - 1, OptModelo - 1);
		
						if(retorno == 1){
							
							inserirAgendamento(OptMarca, OptModelo);
							
						}else if(retorno == 0){
							
							opcaoInvalida();
							printf("\n\n\t*****************************************************************************************\n");
							printf("\t*                                   Agendamento de Veículo                              *");
							printf("\n\t*****************************************************************************************\n");
							printf("\n\tVeículo já esta agendado!");
							sleep(1);
							goto pontoModelo;
						}else{
							opcaoInvalida();
							printf("\n\n\t*****************************************************************************************\n");
							printf("\t*                                   Agendamento de Veículo                              *");
							printf("\n\t*****************************************************************************************\n");
							printf("\n\n\tSó pode agendar veículo alugado!");
							sleep(2);
							goto pontoModelo;
						}
						
						sleep(2);
						goto pontoAgendamento;
						break;
					case 2:
						consultarAgendamento();
						return main();
						break;
					case 3:
						listarAgendamento();
						break;
					case 4:
						alterarAgendamento();
						return main();
						break;
					case 5:
						encerrarAgendamento();
						break;
					case 6:
						excluirAgendamento();
						break;
					case 7:
						return main();
						break;
					default:
						opcaoInvalida();
						printf("\n\tOpção inválida!\n\n");
						sleep(1);
						break;
					
				} // fim do switch controle agendamento
			}// fim do while do agendamento
			
		case 5:
			exit(esc);
			
		default:
			return main();
	}// fim so switch Menu Principal

}

