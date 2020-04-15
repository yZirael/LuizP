#ifndef LIMPA_TELA_BUFFER_OPCAO_H
#define LIMPA_TELA_BUFFER_OPCAO_H

// Limpa a tela
void limpaTela(){
	system("cls");
};

// Limpar buffer
void limparBuffer(){
	
	char c;
	while((c = getchar()) != '\n' && (c != EOF));
};

// Bipe de erro
void opcaoInvalida(){
	printf("%C%C",007,007);
};

#endif
