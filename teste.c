#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
	
	int salvar_progresso(int matriz[9][9]){
			
			FILE* arq = fopen("C:\\Users\\Dilvonei Lacerda\\Desktop\\Arquivo\\Jogo_Salvo\\saved.txt","w");
		if (arq == NULL) {
		printf("\nERRO SAVE COMRROPIDO.\n");
		exit(1);
		}
		int i,j;
		for(i=0;i<9;i++){
			for(j=0;j<9;j++){
				fprintf(arq,"%d",matriz[i][j]);
			}
		}
		
		printf("Jogo Salvo Com Sucesso.\n");
		fclose(arq);
	}
	int carregar_jogo(){
		system("cls");
		int i=0,j=0;
		int recebe[9][9];
		FILE *save=fopen("C:\\Users\\Dilvonei Lacerda\\Desktop\\Arquivo\\Jogo_Salvo\\saved.bin","rb");
		if (save == NULL) {
			printf("\nERRO SAVE COMRROPIDO.\n");
			exit(1);
		}
		printf("Jogo Carregado.\n");

		 for(i=0;i<9;i++){
      for(j=0;j<9;j++){
          fscanf(select,"%d ", &matriz[i][j]);
      }
    }
		/*printf("recebe\n");
		for(i = 0; i < 9; i++){
            for(j = 0; j < 9; j++){
              printf(" %d ", recebe[i][j]);
            }
             printf("\n");
          }*/

			fclose(save);
			printf("\n\n");
	}
	int main(){
  int matriz[9][9]={0};
  printf("\n");
  //salvar_progresso(matriz);
  carregar_jogo();
}

