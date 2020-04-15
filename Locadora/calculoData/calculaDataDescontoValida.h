#ifndef CALCULCA_DATA_DESCONTO_VALIDA_H
#define CALCULCA_DATA_DESCONTO_VALIDA_H


int totalMinuto(int hora, int minuto);
char retornaDataAtual();

// Valida Idade
int validaIdade(int idade){
	
	if(idade < 18 || idade > 120){
			
		return (1);
	
	}
	
	return (0);
}

// Funcao da data e horario
int calculaDataDiaria(int qtdeDiaria, int posicao) {

	time_t TempoAtual;
	time(&TempoAtual);
	char hora[15], dataAtual;
	
	struct tm *Tmp = localtime(&TempoAtual);
	
	int diaAtual, mesAtual, anoAtual;
	int diaPosterior, mesPosterior, anoPosterior;
	
	diaAtual = Tmp->tm_mday + qtdeDiaria;
	mesAtual = Tmp->tm_mon + 1;
	anoAtual = Tmp->tm_year + 1900;
	
	/*diaAtual = 28 + qtdeDiaria; // teste para verificar retorno de data
	mesAtual = 3;
	anoAtual = Tmp->tm_year + 1903;*/
	
	anoPosterior = anoAtual;
	mesPosterior = mesAtual;
	diaPosterior = diaAtual;
	
	if(diaAtual > 31){
	
		if((mesAtual == 1) || (mesAtual == 3) || (mesAtual == 5) || (mesAtual == 7) || (mesAtual == 8) || (mesAtual == 10) || (mesAtual == 12)){
			
			diaPosterior = diaAtual - 31;
			mesPosterior += 1 ;	
					
			if(mesPosterior > 12){
				mesPosterior = mesAtual - 11;
				anoPosterior = Tmp->tm_year + 1901;
			}
			
		}else if(mesAtual == 2){
			
			if(( anoAtual %4 == 0 ) && ( anoAtual %100 != 0 ) || ( anoAtual %400 == 0)){
				if(diaAtual > 29){
					diaPosterior = diaAtual - 29; 
					mesPosterior += 1;
				}
			}
			else{
				if(diaAtual > 28){
					diaPosterior = diaAtual - 28; 
					mesPosterior += 1;
				}
			}
		}else{
			if(diaAtual > 30){
				diaPosterior = diaAtual - 30; 
				mesPosterior += 1;
			}
		}
		
	} else{// fim do if > 31 primeiro
	
		if((mesAtual == 4) || (mesAtual == 6) || (mesAtual == 9) || (mesAtual == 11)){
			
			if(diaAtual > 30){
				diaPosterior = diaAtual - 30; 
			}
			
		}else if(mesAtual == 2){
			
			if(( anoAtual %4 == 0 ) && ( anoAtual %100 != 0 ) || ( anoAtual %400 == 0)){
				if(diaAtual > 29){
					diaPosterior = diaAtual - 29; 
					mesPosterior += 1;
				}
			}
			else{
				if(diaAtual > 28){
					diaPosterior = diaAtual - 28; 
					mesPosterior += 1;
				}
			}
		}
		
	}
	
	strftime(Locacao[posicao].dataInicioLocacao,25, "%d/%m/%Y %H:%M:%S", Tmp);
	
	strftime(hora,15,"%H:%M:%S", Tmp);
	
	if(diaPosterior < 10){
		if(mesPosterior < 10){
			sprintf(Locacao[posicao].dataFimLocacao, "0%d/0%d/%d %s", diaPosterior, mesPosterior, anoPosterior, hora);
		}else{
			sprintf(Locacao[posicao].dataFimLocacao, "0%d/%d/%d %s", diaPosterior, mesPosterior, anoPosterior, hora);	
		}
		
	}else{
		if(mesPosterior < 10){
			sprintf(Locacao[posicao].dataFimLocacao, "%d/0%d/%d %s", diaPosterior, mesPosterior, anoPosterior, hora);
		}else{
			sprintf(Locacao[posicao].dataFimLocacao, "%d/%d/%d %s", diaPosterior, mesPosterior, anoPosterior, hora);	
		}
	}
}

// Função para verificar se a devolucao esta atrasado
int verificarAtrasoMulta(char dataDevolucao[]){
	
	time_t TempoAtual;
	time(&TempoAtual);
	struct tm *Tmp = localtime(&TempoAtual);
	
	
	char data[25], horaChar[15], dataAtual[25];
	
	
	int multa, diaAtual, mesAtual, anoAtual, horaIntAtual, minutoAtual, segundoAtual;
	int diaDev, mesDev, anoDev, horaIntDev, minutoDev, segundoDev;
	
	int dia [2], mes [2], ano [2], hora[2], minuto[2], resultado[2];
	int totaldias, totalMin;
	int anot,mest,diat;
	
	strftime(dataAtual,25, "%d/%m/%Y %H:%M:%S", Tmp);
	strftime(horaChar,15,"%H:%M:%S", Tmp);
	
	sscanf( dataAtual, "%d/%d/%d %d:%d:%d",  &diaAtual, &mesAtual, &anoAtual, &horaIntAtual, &minutoAtual, &segundoAtual );
	sscanf( dataDevolucao, "%d/%d/%d %d:%d:%d",  &diaDev, &mesDev, &anoDev, &horaIntDev, &minutoDev, &segundoDev );

	dia [0] = diaDev ;
	mes [0] = mesDev;
	ano [0] = anoDev;
	
	dia [1] = diaAtual;
	mes [1] = mesAtual;
	ano [1] = anoAtual;
	
	hora[0] 	= horaIntDev;
	minuto[0] 	= minutoDev;
	hora[1] 	= horaIntAtual;
	minuto[1] 	= minutoAtual;
	
	if(mes[0] <= mes[1] ){
		
		for (int i = 0;i < 2; i++)
		{
			if ((mes[i] == 2 || mes[i] == 02) && ano[i] % 4 == 0)
			{
				mes[i] = mes[i] * 29;
			}
			
			if (ano[i] % 4 == 0)
			{
				ano[i] = ano[i] * 366;
			} else {
				ano[i] = ano[i] * 365;
			}
			if (mes[i] == 2 || mes[i] == 02)
			{
				mes[i] = mes[i] * 28;
			
			} else {
			
				mes[i] = mes[i] * 30;
			
			}
		
		}
		
		anot = ano[1] - ano[0];
		mest = mes[1] - mes[0];
		
		if(dia[0] > dia[1] ){
			
			diat = (dia[1] - dia[0]) + 1;// * (-1);
			
		}else{ // fim else do dia[0] > dia[1]	
			
			diat = (dia[1] - dia[0]);
		} // fim do dia[0] > dia[1]
		
		totaldias = anot + mest + diat;
			
		if(totaldias > 0){
			
			totaldias = totalMinuto(totaldias * 24, 0);
		}
		
		resultado[0] = totalMinuto(hora[0], minuto[0]);
		
		resultado[1] = totalMinuto(hora[1], minuto[1]);
		
		if( resultado[0] > resultado[1]){
			totalMin = (resultado[1] - resultado[0] )* (-1);
		}else{
			totalMin = resultado[1] - resultado[0];
		}
		
		if (totalMin < 0){
			totalMin +=1440; //calculo
			totalMin  + totaldias;
		} 
		else {
			totalMin  += totaldias;
		}
		
	}else{ // fim do mes[0] < mes[1]
		opcaoInvalida();
		printf("\n\tMês não confere!!");
	}
	return totalMin;	
}

// calcula a hora para minutos
int totalMinuto(int hora, int minuto) {
	int r = (hora*60) + minuto;
	return r;
}

// Função para calcular multa
int calcularMulta(int minuto, float vlrDiaria){
	
	float multa;
	multa = minuto * (vlrDiaria  / 1440) ; // divide por minuto
	return multa;
}

//Função para calcular o desconto total da alucação
float descontoDiaria(float vlrTotal, int taxa) {
	
	float resultado = vlrTotal - (vlrTotal / 100) * taxa;
	return resultado;
}

int retornaDataHoraAtual(int posicao){
	time_t TempoAtual;
	time(&TempoAtual);
	char hora[15], dataAtual[25];
	
	struct tm *Tmp = localtime(&TempoAtual);
	
	int diaAtual, mesAtual, anoAtual;
		
	strftime(agendamentoVeiculo[posicao].dataAgendamento,25, "%d/%m/%Y %H:%M:%S", Tmp);
	
}

#endif
