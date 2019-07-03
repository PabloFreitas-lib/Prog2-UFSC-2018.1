#include "lab4.h"

times_t *le_times (const char *arquivo, unsigned int *numero_de_times){
    if((numero_de_times == NULL) || (arquivo == NULL))return(NULL);

  int ctd = 0;
	FILE *f = abre_arquivo(arquivo);
	if(f == NULL)return(NULL);

  times_t *time = (times_t *)calloc(1,sizeof (times_t));

      while(fread(&time[ctd++],sizeof(times_t),1,f)==1){
    		time = (times_t *)realloc(time,(ctd+1)*sizeof(times_t));
    	}

	ctd--;

    if (ctd == 0){
  	   free(time);
  	   return(NULL);
  	}
	*numero_de_times = ctd;
	fecha_arquivo(f);
	return(time);
}

FILE *abre_arquivo (const char *arq){
  	if(arq==NULL)return(NULL);

  	FILE *arq_open = fopen(arq,"rb+");
  	if(arq_open==NULL)return(NULL);
  	return(arq_open);
}

int fecha_arquivo(FILE *arq_open){
    if(arq_open==NULL)return(1);
	if (fclose(arq_open)!=0){
		return(1);
	}else{
		return(0);
	}
}
// aux -----------------------------------------------------------------

void encontra_jogador_mais_agressivo (times_t *times, unsigned int num_times, jogador_t **jogador, times_t **time){
	if ((times==NULL)||(jogador==NULL)||(time==NULL))return;
	int bad=0,numero_max = 21;
	for (int i=0; i < num_times;i++){
		for (int j=0; j < NUM_JOGADORES;j++){
			if ((times[i].jogadores[j].cartoes_vermelhos)*(5)+(times[i].jogadores[j].cartoes_amarelos)+(times[i].jogadores[j].faltas_cometidas)*(0.2) >= bad){
				bad = (times[i].jogadores[j].cartoes_vermelhos)*(5)+(times[i].jogadores[j].cartoes_amarelos)+(times[i].jogadores[j].faltas_cometidas)*(0.2);
				*jogador = &times[i].jogadores[j];
				*time = &times[i];
			}

		}

	}
  //printf("teste\n\n");
}
// aux -----------------------------------------------------------------


// aux -----------------------------------------------------------------
void encontra_jogador_artilheiro(times_t *times, unsigned int num_times, jogador_t **jogador, times_t **time){
	if((times==NULL) || (jogador==NULL) || (time==NULL))return;
	int aux = 0,numero_max = 21;
	for(int i=0; i < num_times;i++){

		for(int j=0; j < NUM_JOGADORES;j++){

			if(times[i].jogadores[j].gols_marcados > aux){
				*jogador = &times[i].jogadores[j];
				*time = &times[i];
        gols=times[i].jogadores[j].gols_marcados;//GAP
			}

		}

	}
  //printf("teste\n\n");
}
// aux -----------------------------------------------------------------
void encontra_jogador_mais_eficiente(times_t *times, unsigned int num_times, jogador_t **jogador, times_t **time){
	if((times==NULL)||(jogador==NULL)||(time==NULL))return;
	float eficem = 0.0,numero_max = 21;
	for(int i=0;i < num_times;i++){
		for (int j=0; j<NUM_JOGADORES;j++){
			if (times[i].jogadores[j].numero_jogos != 0){
				if ((times[i].jogadores[j].gols_marcados)/((float)times[i].jogadores[j].numero_jogos) >= eficem){
					*jogador=&times[i].jogadores[j];
					*time=&times[i];
          eficiente = (times[i].jogadores[j].gols_marcados)/((float)times[i].jogadores[j].numero_jogos);
				}

			}

		}

	}
  //printf("teste\n\n");
}
// aux -----------------------------------------------------------------
void encontra_time_com_mais_titulos(times_t *times, unsigned int num_times, times_t **time){
  if((times==NULL)||(time==NULL))return;
  int ano,num;
	float feedback = 0.0;

	for (int i=0; i<num_times; i++){

	    if (times[i].ano != 0){
	        num = (times[i].numero_tit_brasileiros) + (times[i].numero_copas_brasil) + (times[i].numero_tit_libertadores) + (times[i].numero_tit_estadual);
	        ano = 2016 - (times[i].ano_fundacao);

	        if(num/((float)ano_fund) > result){
	            feedback = num/((float)ano_fund);
	            *time = &times[i];
	        }

      }

	}
   //printf("teste\n\n");
}
// aux -----------------------------------------------------------------
void encontra_goleiro_que_defendeu_mais_penaltis(times_t *times, unsigned int num_times, jogador_t **jogador, times_t **time){
    if(times==NULL || jogador==NULL || time==NULL)return;
	float defense = 0.0;
	for(int i=0;i < num_times;i++){

  		for(int j=0;j<NUM_JOGADORES;j++){

    			if ((times[i].jogadores[j].penalti_defendidos)/((float)times[i].jogadores[j].numero_jogos) > defesa){
    				*jogador=&times[i].jogadores[j];
    				*time=&times[i];
            defesa = (times[i].jogadores[j].penalti_defendidos)/((float)times[i].jogadores[j].numero_jogos); // GAP
    			}

  		}

	}
//printf("teste\n\n");
}

// aux -----------------------------------------------------------------
void encontra_jogador_cartao_vermelho_e_jogos(times_t *times, unsigned int num_times, jogador_t **jogador, times_t **time){
    if((times==NULL)||(jogador==NULL)||(time==NULL))return;
	float card=0;
  int numero_max = 21;
	for (int i=0; i<num_times; i++){

		for (int j=0;j < NUM_JOGADORES;j++){

			if (times[i].jogadores[j].numero_jogos != 0){

				if ((times[i].jogadores[j].cartoes_vermelhos)/((float)times[i].jogadores[j].numero_jogos) > card){
					*jogador = &times[i].jogadores[j];
					*time = &times[i];
          card = (times[i].jogadores[j].cartoes_vermelhos)/((float)times[i].jogadores[j].numero_jogos);// GAP
				}

			}

		}

	}
  //printf("teste\n\n");
}
