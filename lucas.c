#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int bem_vindo();
int menu();
int menu_jogadas(int matriz[9][9]);
int grid(int matriz[9][9]);
int adicionar_jogada(int matriz[9][9]);
int remover_jogada(int matriz[9][9]);
int novo_jogo();
int salvar_progresso(int matriz[9][9]);
int carregar_jogo();

int main(){
  int matriz[9][9]={0};
  printf("\n");
  bem_vindo();
  menu();
}

int menu(){
  int opcao;
  puts("\t\t  【M】【E】【N】【U】");
  puts("");
  puts("\t\t     1 -【Novo jogo】");
  puts("\t\t     2 -【Carregar】");
    puts("\t\t     3 -【Sair】");
  printf("                     【Digite sua opcao】: ");
    scanf("%d",&opcao);
    system("clear");
    switch(opcao){

      case 1:
      printf("\t\t\tRegras do jogo\n");
      printf("\tO objetivo do Sudoku é preencher todos os espaços vazios\n");
      printf("\tcom numeros de 1 a 9. Porem o numero escolhido nao pode estar se\n");
      printf("\trepetindo na mesma coluna, linha e bloco.\n");
      printf("\n");
      novo_jogo();
      break;
      case 2: carregar_jogo();
                break;
      default:
        return 0;
      }
    }

      int grid(int matriz[9][9]){
        int i, j;
        //printf("\033[39m");
        system("clear");
        printf("\033[30m");
        printf("\033[1m");

        for (i = 0; i< 9; i++)
        {
          for (j = 0; j < 9; j++)
          {
            if (j == 3 || j == 6)
              printf(" ");
            if (i == 0 || i == 3 || i == 6)
            {
              if (j == 0)
               printf(" _____  ");
              else
               printf("_____  ");
             }
           }

            printf("\n");
            for (j = 0; j < 9; j++)
            {
              if (j == 3 || j == 6)
                printf(" ");
              if (matriz[i][j] == 0)
                printf("|     |");
              else
                printf("|  %d  |",matriz[i][j]);
            }
            printf("\n");
            for (j = 0; j< 9; j++)
            {
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
            printf("Faça sua jogada com numeros entre 1 e 9: \n");
          }
          else {
        matriz[linha-1][coluna-1]=jogada;
        system("clear");
        break;
        }
      }
      grid(matriz);
      menu_jogadas(matriz);
  }


  int remover_jogada(int matriz[9][9]){
  int linha , coluna;
        printf("Remova uma jogada:\n");
        printf("Informe a linha desejada: ");
        scanf("%d", &linha);
        printf("Informe a coluna desejada: ");
        scanf("%d",&coluna);
        printf("Vc removeu a jogada da Linha %d Coluna %d\n",linha, coluna);
        matriz[linha - 1][coluna - 1]=0;
        system("clear");
        grid(matriz);
        menu_jogadas(matriz);
  }

  int menu_jogadas(int matriz [9][9]){
    int op;

  printf("Digite sua opcao: \n");
  printf("1-Nova jogada.\n");
  printf("2-Excluir jogada.\n");
  printf("3-Salvar progresso.\n");
  printf("4-Desistir.\n");
  scanf("%d",&op);
    switch (op) {
      case 1: grid(matriz);
              adicionar_jogada(matriz);
              break;
      case 2: remover_jogada(matriz);
              grid(matriz);
              break;
      case 3: salvar_progresso(matriz);
              break;
      default: return 0;
    }
  }
  int bem_vindo(){
    printf("\033[36m") ;
    printf("\033[1m");
    printf("\033[05m");
    puts("\t\t┏━━━┳┓╋┏┳━━━┳━━━┳┓┏━┳┓╋┏┓");
    puts("\t\t┃┏━┓┃┃╋┃┣┓┏┓┃┏━┓┃┃┃┏┫┃╋┃┃");
    puts("\t\t┃┗━━┫┃╋┃┃┃┃┃┃┃╋┃┃┗┛┛┃┃╋┃┃");
    puts("\t\t┗━━┓┃┃╋┃┃┃┃┃┃┃╋┃┃┏┓┃┃┃╋┃┃");
    puts("\t\t┃┗━┛┃┗━┛┣┛┗┛┃┗━┛┃┃┃┗┫┗━┛┃");
    puts("\t\t┗━━━┻━━━┻━━━┻━━━┻┛┗━┻━━━┛");
    printf("\n");

    puts("\t  ╭━━╮╭━━━┳━╮╭━╮╱╭╮╱╱╭┳━━┳━╮╱╭┳━━━┳━━━╮");
    puts("\t  ┃╭╮┃┃╭━━┫┃╰╯┃┃╱┃╰╮╭╯┣┫┣┫┃╰╮┃┣╮╭╮┃╭━╮┃");
    puts("\t  ┃╰╯╰┫╰━━┫╭╮╭╮┃╱╰╮┃┃╭╯┃┃┃╭╮╰╯┃┃┃┃┃┃╱┃┃");
    puts("\t  ┃╭━╮┃╭━━┫┃┃┃┃┣━━┫╰╯┃╱┃┃┃┃╰╮┃┃┃┃┃┃┃╱┃┃");
    puts("\t  ┃╰━╯┃╰━━┫┃┃┃┃┣━━┻╮╭╯╭┫┣┫┃╱┃┃┣╯╰╯┃╰━╯┃");
    puts("\t  ╰━━━┻━━━┻╯╰╯╰╯╱╱╱╰╯╱╰━━┻╯╱╰━┻━━━┻━━━╯");
    puts("");
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
      system("clear");

    switch(dificuldade){

      case 1:
       switch(radom){
      case 1:select=fopen("facil_1.txt","r");  break;
      case 2:select=fopen("facil_2.txt","r");  break;
      case 3:select=fopen("facil_3.txt","r");  break;
      case 4:select=fopen("facil_4.txt","r");  break;
      case 5:select=fopen("facil_5.txt","r");  break;
      default: return 0;
      }
      break;

      case 2:
      switch(radom){

     case 1:select=fopen("medio_1.txt","r");  break;
     case 2:select=fopen("medio_2.txt","r");  break;
     case 3:select=fopen("medio_3.txt","r");  break;
     case 4:select=fopen("medio_4.txt","r");  break;
     case 5:select=fopen("medio_5.txt","r");  break;
       default:
         return 0;
     }
     break;

     case 3:
     switch(radom){
    case 1:select=fopen("dificil_1.txt","r");  break;
    case 2:select=fopen("dificil_2.txt","r");  break;
    case 3:select=fopen("dificil_3.txt","r");  break;
    case 4:select=fopen("dificil_4.txt","r");  break;
    case 5:select=fopen("dificil_5.txt","r");  break;
      default:
        return 0;
    }
    break;

    default: return 0;
  }
  printf("Jogo pronto\n");

  if(select == NULL) {
printf("Erro ao abrir o arquivo!");
return 0;
}

for(i=0;i<9;i++){
      for(j=0;j<9;j++){
          fscanf(select,"%d ", &matriz[i][j]);
}
}


    fclose(select);
    menu_jogadas(matriz);

return 0;
  }

  int salvar_progresso(int matriz[9][9]){

      FILE *save = fopen("saved.txt","w");
    if (save == NULL) {
    printf("\nERRO SAVE COMRROPIDO.\n");
    exit(1);
    }
    int i,j;
    for(i=0;i<9;i++){
      for(j=0;j<9;j++){
        fprintf(save,"%d ",matriz[i][j]);
      }
      fprintf(save, "\n");
    }

    printf("Jogo Salvo Com Sucesso.\n");
    fclose(save);
    menu_jogadas(matriz);
    }

    int carregar_jogo(){
      int matriz[9][9];
      system("cls");
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
        menu_jogadas(matriz);
    }
