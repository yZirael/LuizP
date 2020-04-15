#ifndef ESTRUTURA_MATRIZ_H
#define ESTRUTURA_MATRIZ_H

#define SIZE 100

int tlLocacao;
int tlPessoa;
int tlVeiculo;
int tlAgendamentoVeiculo;


/*================================= INICIO DAS ESTRUTURAS =============================*/
// estrutura de cadastro de funcionaios
struct cadastroPessoa{
	
	char nome [25];
	int cod;
	int idade;
	char rg[15] ;
	char cpf[15];
	char cargo [25];
	char sexo [1];
	float salario;
	int funcionario;	
};

// Estrutura da pessoa que irá alocar o veiculo
struct cadastroLocacao {
	
	int cod;
	char nome[256];
	char cpf[15];
	int idade;
	float vlrDiaria;
	int qtdDiaria;
	int parceiro;
	float valorTotal;
	float vlrDesconto;
	char veiculoEscolhido[20];
	int posicaoMarcaVeiculo;
	int posicaoModeloveiculo;
	char dataInicioLocacao[25];
	char dataFimLocacao[25];
	char placaVeiculo[10];
	int status;
	
};

// Estrutura de veiculo
struct cadastroVeiculo{
	int cod;
	int ano;
	char marca[20];
	char modeloVec[20];
	char placaVeiculo[10];
	char corVeiculo[20];
	float vlrDiaria;
	int status;
	int codMarca;
	int codModelo;
	int posicao;
};

// Estrutura de agendamento de veiculo
// Estrutura de veiculo
struct cadastroAgendamentoVeiculo{
	int cod;
	char nomeCliente[25];
	char cpf[15];
	char marca[20];
	char modelo[20];
	char placaVeiculo[10];
	char corVeiculo[20];
	int ano;
	float vlrDiaria;
	char dataAgendamento[25];
	char dataRetirar[25];
	int status;
	int posicaoMarcaVeiculo;
	int posicaoModeloveiculo;
	
};

	int tlLocacao;
	int tlPessoa;
	int tlVeiculo;
	//char sexo[1];
// Estrutura para cadastrar pessoa;
struct cadastroPessoa pessoa[SIZE];

// Estrutura para cadastrar Locacao
struct cadastroLocacao Locacao[SIZE];

// Estrutura para cadastrar veiculo
struct cadastroVeiculo cadVeiculo[SIZE];

// Estrutura de veiculo
struct cadastroAgendamentoVeiculo agendamentoVeiculo[SIZE];
/*============================== FIM INICIO DAS ESTRUTURAS =========================*/

// Matriz dos valores
float valoresDiaria[4][5] = {
	{105, 110, 108, 115, 110},
	{060, 055,  050, 070, 075},
	{055, 060, 065, 070, 065},
	{106, 110, 115, 113, 118}
};

//marcas
char marcas[12][20] = {"Chevrolet ","Fiat      ", "Volkswagen", "Hyundai   ", "Honda     ", "Mercedes  ", "BMW       ", "Toyota    ", "Nissan    ", "Mitsu     ", "Peugeot   ", "Renault   "} ;

// Matriz dos veiculos
char veiculos[4][5][20] = {
	/*"0"*/{"OnionJoy ", "PrismaJoy", "OnixLTZ  ", "OnixActive", "Prisma   "},
	/*"1"*/{"Mobi     ", "Palio    ", "Uno      ", "Argo     ", "Punto    "},
	/*"2"*/{"Gol      ", "Fox      ", "CrossFox ", "Golf     ", "Voyage   "},
	/*"3"*/{"Hyun i30 ", "Elantra  ", "Azera    ", "Tucson   ", "SantaFe  "}
};

// cores dos veiculos
char coresVeiculo[5][20] = {"Preto","Prata","Vermelho","Azul","Branco"};

// placa dos carros
char placaVeiculo[5][10] = {"BMX1545","FDS3542","JHG2564","DFG2544","TRD4565"};

// ano dos veiculos
int anoVeiculo[5] = { 2013, 2014, 2015, 2016, 2017};
#endif
