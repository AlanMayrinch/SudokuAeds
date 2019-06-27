#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

//int bem_vindo();
int menu();
int menu_de_jogadas(int matriz[9][9]);
int grid(int matriz[9][9]);
int adicionar_jogada(int matriz[9][9]);
int remover_jogada(int matriz[9][9]);
int salvar_progresso(int matriz [9][9]);
int carregar_jogo();
int novo_jogo();
int faz_0_quadradinho(int matriz [9][9]);
int verifica_quadrado(int matrizinha[3][3]);
int verifica_linha(int matriz[9][9]);
int verifica_coluna(int matriz[9][9]);
int verifica_resolucao(int matriz[9][9]);



int main(){
  printf("\n");
  //bem_vindo();
  menu();
  return 0;
}



    int menu(){
      int opcao;
      puts("\t\t  【M】【E】【N】【U】");
      puts("");
      printf("Digite sua opção\n");
      //puts("\t\t     1 -【Novo jogo】");
      //puts("\t\t     2 -【Carregar】");
      ///puts("\t\t     3 -【Sair】");
      printf("[1-Novo Jogo]\n[2-Carregar]\n[3-Sair]\n");
      scanf("%d",&opcao);
      system("clear||cls");
      switch(opcao){

        case 1:
          printf("\t\t\tRegras do jogo\n");
          printf("\tO objetivo do Sudoku é preencher todos os espaços vazios\n");
          printf("\tcom numeros de 1 a 9. Porem o numero escolhido nao pode estar\n");
          printf("\tse repetindo na mesma coluna, linha e bloco.\n");
          printf("\n\n");
          novo_jogo();
         break;
        case 2:
          carregar_jogo();
          break;
        default:
         return 0;
      }
    }
    int grid(int matriz[9][9]){
        int i, j;

        system("clear||cls");


        for (i = 0; i< 9; i++){
          for (j = 0; j < 9; j++){
            if (j == 3 || j == 6)
              printf(" ");
            if (i == 0 || i == 3 || i == 6){
              if (j == 0)
               printf(" _____  ");
              else
               printf("_____  ");
            }
          }
          printf("\n");
          for (j = 0; j < 9; j++){
              if (j == 3 || j == 6)
                printf(" ");
              printf("|     |");
            }
            printf("\n");
            for (j = 0; j < 9; j++){
              if (j == 3 || j == 6)
                printf(" ");
              if (matriz[i][j] == 0)
                printf("|     |");
              else
                printf("|  %d  |",matriz[i][j]);
            }
            printf("\n");
            for (j = 0; j< 9; j++){
                if (j == 3 || j == 6)
                  printf(" ");
                printf("|_____|");
            }
            if (i == 2 || i == 5)
              printf("\n");
        }
        printf("\n");
    }

   int adicionar_jogada(int matriz[9][9]){
    int linha , coluna, jogada;
      for(;;){
        printf("Informe a linha desejada: ");
        scanf("%d", &linha);
        printf("Informe a coluna desejada: ");
        scanf("%d",&coluna);
        if(matriz[linha-1][coluna-1] >= 1){
          printf("[%d][%d]Posicao Invalida,Digite outra Posicao:\n",linha,coluna);
          printf("%d\n", matriz[linha-1][coluna-1]);
        }
        else
          break;
}
          for(;;){
        printf("Linha %d Coluna %d\n",linha, coluna);
        printf("Faça sua jogada com numeros entre 1 e 9: ");
        scanf("%d", &jogada);
          if(jogada<1||jogada>9){
            printf("Faça sua jogada com numeros entre 1 e 9:");
          }
          else {
        matriz[linha-1][coluna-1]=jogada;
        system("clear||cls");
        break;
        }
      }
      grid(matriz);
      menu_de_jogadas(matriz);
  }


  int remover_jogada(int matriz[9][9]){
    int linha ,coluna;
    int i,j,original[9][9];
      FILE *inalteravel=fopen("ultimojogo.txt","r");
      if (inalteravel == NULL) {
        printf("\nERRO AO INICIAR.\n");
        exit(1);
    }
     for(i=0;i<9;i++){
      for(j=0;j<9;j++){
          fscanf(inalteravel,"%d",&original[i][j]);
      }
    }
      fclose(inalteravel);
        printf("Remova uma jogada:\n");
        printf("Informe a linha desejada: ");
        scanf("%d", &linha);
        printf("Informe a coluna desejada: ");
        scanf("%d",&coluna);
        if(original[linha-1][coluna-1]!=0){
          printf("Posicao inalteravel!\n");
        }
        else{
        printf("Voce removeu a jogada da Linha %d Coluna %d\n",linha, coluna);
        matriz[linha-1][coluna-1]=0;
      }

        grid(matriz);
        menu_de_jogadas(matriz);
  }
  int salvar_progresso(int matriz[9][9]){

      FILE *save = fopen("saved.txt","w");
    if (save == NULL) {
    printf("\nERRO SAVE COMRROPIDO.\n");
    exit(1);
    }
    int i,j;
    char resposta;
    for(i=0;i<9;i++){
      for(j=0;j<9;j++){
        fprintf(save,"%d ",matriz[i][j]);
      }
      fprintf(save, "\n");
    }

    printf("Jogo Salvo Com Sucesso.\n");
    menu_de_jogadas(matriz);
    fclose(save);

  }
  int carregar_jogo(){
    int matriz[9][9];
    system("clear||cls");
    int i=0,j=0;
    int recebe[9][9];
    FILE *save=fopen("saved.txt","r");
    if (save == NULL) {
      printf("\nERRO SAVE COMRROPIDO.\n");
      exit(1);
    }
    printf("Jogo Carregado.\n");

     for(i=0;i<9;i++){
      for(j=0;j<9;j++){
          fscanf(save,"%d",&matriz[i][j]);
      }
    }
      fclose(save);
      menu_de_jogadas(matriz);
  }

  int bem_vindo(){
    printf("\033[36m") ;
    printf("\033[1m");
    printf("\033[05m");
    printf("\t\t┏━━━┳┓1┏┳━━━┳━━━┳┓┏━┳┓3┏┓");
    printf("\t\t┃┏━┓┃┃9┃┣┓┏┓┃┏━┓┃┃┃┏┫┃7┃┃");
    printf("\t\t┃┗━━┫┃2┃┃┃┃┃┃┃0┃┃┗┛┛┃┃4┃┃");
    printf("\t\t┗━━┓┃┃8┃┃┃┃┃┃┃5┃┃┏┓┃┃┃6┃┃");
    printf("\t\t┃┗━┛┃┗━┛┣┛┗┛┃┗━┛┃┃┃┗┫┗━┛┃");
    printf("\t\t┗━━━┻━━━┻━━━┻━━━┻┛┗━┻━━━┛");
    printf("\n");

    printf("\t  ╭━━╮╭━━━┳━╮╭━╮╱╭╮╱╱╭┳━━┳━╮╱╭┳━━━┳━━━╮");
    printf("\t  ┃╭╮┃┃╭━━┫┃╰╯┃┃╱┃╰╮╭╯┣┫┣┫┃╰╮┃┣╮╭╮┃╭━╮┃");
    printf("\t  ┃╰╯╰┫╰━━┫╭╮╭╮┃╱╰╮┃┃╭╯┃┃┃╭╮╰╯┃┃┃┃┃┃╱┃┃");
    printf("\t  ┃╭━╮┃╭━━┫┃┃┃┃┣━━┫╰╯┃╱┃┃┃┃╰╮┃┃┃┃┃┃┃╱┃┃");
    printf("\t  ┃╰━╯┃╰━━┫┃┃┃┃┣━━┻╮╭╯╭┫┣┫┃╱┃┃┣╯╰╯┃╰━╯┃");
    printf("\t  ╰━━━┻━━━┻╯╰╯╰╯╱╱╱╰╯╱╰━━┻╯╱╰━┻━━━┻━━━╯");
  printf("");
}

  int menu_de_jogadas(int matriz [9][9]){
    int op;
  printf("Digite sua opcao: \n");
  printf("1-Nova jogada.\n");
  printf("2-Excluir jogada.\n");
  printf("3-Salvar progresso.\n");
  printf("4-Desistir.\n");
  printf("5 - Verificar a solucao.\n");
  printf("Opcao escolhida: ");
  scanf("%d",&op);

    switch (op) {
      case 1: grid(matriz);
              adicionar_jogada(matriz);
              break;
      case 2: grid(matriz);
              remover_jogada(matriz);
              break;
      case 3: salvar_progresso(matriz);
              break;
      case 4: printf("VC E FRACO LHE FALTA SODOKU");
              return 0;
      case 5: verifica_resolucao(matriz);
              break;

      default: system("clear||cls");
              grid(matriz);
              printf("Opcao invalida\n");
              menu_de_jogadas(matriz);
    }
  }
  int novo_jogo(){
      int radom;
      int matriz[9][9];
      int i,j;
      int dificuldade;
        FILE *select;
    printf ("Escolha a dificuldade do jogo\n");
    printf("1 - Facil\n2 - Medio\n3 - Dificil\n");
    scanf("%d", &dificuldade);
    srand((unsigned)time(NULL));
      radom = (1 + rand()%5);
      system("cls||clear");

   if(dificuldade==1){
       switch(radom){
        case 1:select=fopen("facil_1.txt","r");  break;
        case 2:select=fopen("facil_2.txt","r");  break;
        case 3:select=fopen("facil_3.txt","r");  break;
        case 4:select=fopen("facil_4.txt","r");  break;
        case 5:select=fopen("facil_5.txt","r");  break;
      }
    }
    if(dificuldade==2){
      switch(radom){
        case 1:select=fopen("medio_1.txt","r");  break;
        case 2:select=fopen("medio_2.txt","r");  break;
        case 3:select=fopen("medio_3.txt","r");  break;
        case 4:select=fopen("medio_4.txt","r");  break;
        case 5:select=fopen("medio_5.txt","r");  break;
      }
    }
     if(dificuldade==3){
        switch(radom){
          case 1:select=fopen("dificil_1.txt","r");  break;
          case 2:select=fopen("dificil_2.txt","r");  break;
          case 3:select=fopen("dificil_3.txt","r");  break;
          case 4:select=fopen("dificil_4.txt","r");  break;
          case 5:select=fopen("dificil_5.txt","r");  break;
        }
      }
  if(select == NULL) {
    printf("Erro ao abrir o arquivo!");
    return 0;
  }
  else{
    printf("Jogo pronto\n");
  }

  for(i=0;i<9;i++){
      for(j=0;j<9;j++){
          fscanf(select,"%d ", &matriz[i][j]);
      }
    }
    fclose(select);

    FILE *original = fopen("ultimojogo.txt","w");
    if (original == NULL) {
    printf("\nERRO AO ABRIR.\n");
    exit(1);
    }
    for(i=0;i<9;i++){
      for(j=0;j<9;j++){
        fprintf(original,"%d ",matriz[i][j]);
      }
      fprintf(original, "\n");
    }
    fclose(original);

    grid(matriz);
    menu_de_jogadas(matriz);

return 0;
  }

  int verifica_linha(int matriz[9][9]){
  		int i,coluna2,coluna;
  		int contador=0;
  		for(i=0;i<9;i++){
  			for(coluna=0;coluna<9;coluna++){
  				for(coluna2=0;coluna2<9;coluna2++){
  					if(matriz[i][coluna]==matriz[i][coluna2] && coluna!=coluna2){
  					contador++;
  					}
  				}
  			}
  		}
  		if(contador!=0){
  		printf("sudoku incorreto.\n");
  		}
  		else
      printf("SUDDOKU CORRETOOOOOOO\n");
  	}

  		int verifica_coluna(int matriz[9][9]){
  		int i,linha,linha2;
  		int contador=0;
  		for(i=0;i<9;i++){
  			for(linha=0;linha<9;linha++){
  				for(linha2=0;linha2<9;linha2++){
  					if(matriz[linha][i]==matriz[linha2][i] && linha!=linha2){
  					contador++;
  					}
  				}
  			}
  		}
  		if(contador!=0){
  		printf("sudoku incorreto.\n");
  		}
      else
  		  printf("SUdOKU CORRETOOOOOOO\n");
  	}

    int verifica_quadrado(int matrizinha[3][3]){
    			int i,j,contador=0;
    			int num;
    			for(num=1;num<=9;num++){
    				for(i=0;i<3;i++)
    					for(j=0;j<3;j++)
    						if(matrizinha[i][j]==num)
    							contador++;
    						if(contador>1){
    				printf("Sudoku incorreto %d\n",contador);
            return 0;
          }

    			contador = 0;
    		}
        if(contador = 0)
          printf("SUDOKU CORRETOOOOOOO\n");
    	}

    		int faz_0_quadradinho(int matriz [9][9]){
    			int linha, coluna;
    			int linhazinha, coluninha;
    			int matrizinha[3][3];
    			for(linha=0;linha<9;linha+=3){
    				for(coluna=0;coluna<9;coluna+=3){
    					for(linhazinha=0;linhazinha<3;linhazinha++){
    						for(coluninha=0;coluninha<3;coluninha++){
    							matrizinha[linhazinha][coluninha]=matriz[linha+linhazinha][coluna+coluninha];
    				}
    			}
    			verifica_quadrado(matrizinha);
    		}
    	}
    }

    int verifica_resolucao(int matriz[9][9]){
      verifica_linha(matriz);
      verifica_coluna(matriz);
      faz_0_quadradinho(matriz);
    }
