#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int bem_vindo();
int menu();
int novo_jogo(int matriz[9][9]);
int grid(int matriz[9][9]);
int adicionar_jogada(int matriz[9][9]);
int remover_jogada(int matriz[9][9]);

int main(){
  int matriz[9][9]={0, 6, 0, 1, 0, 4, 0, 5,  0,
                    0, 0, 8, 3, 0, 5, 6, 0, 0,
                    2, 0, 0, 0, 0, 0, 0, 0, 1,
                    8, 0, 0, 4, 0, 7, 0, 0, 6,
                    0, 0, 6, 0, 0, 0, 3, 0, 0,
                    7, 0, 0, 9, 0, 1, 0, 0, 4,
                    5, 0, 0, 0, 0, 0, 0, 0, 2,
                    0, 0, 7, 2, 0, 6, 9, 0, 0,
                    0, 4, 0, 5, 0, 8, 0, 7, 0};
  printf("\n");
  bem_vindo();
  menu();
  novo_jogo(matriz);
}

int menu(){
  int opcao;
  puts("\t\t  【M】【E】【N】【U】");
  puts("");
  puts("\t\t     1 -【Novo jogo】");
  puts("\t\t     2 -【Carregar】");
    puts("\t\t     3 -【Sair】");
  printf("                     4 -【Opcao】: ");
    scanf("%d",&opcao);
    system("clear");
    switch(opcao){

      case 1:
      printf("\t\t\tRegras do jogo\n");
      printf("\tO objetivo do Sudoku é preencher todos os espaços vazios\n");
      printf("\tcom numeros de 1 a 9. Porem o numero escolhido nao pode estar se\n");
      printf("\trepetindo na mesma coluna, linha e bloco.\n");

            break;
      case 2: //carreagar_jogo();
                break;
      default:
        return 0;
      }
    }

      int grid(int matriz[9][9]){
        int i, j;
        //printf("\033[39m");
        system("clear");
        printf("\033[34m");
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
              printf("|     |");
            }
            printf("\n");
            for (j = 0; j < 9; j++)
            {
              if (j == 3 || j == 6)
                printf(" ");
              if (matriz[i][j] == 0)
                printf("|     |");
              else
                printf("|  %i  |",matriz[i][j]);
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
        if(matriz[linha][coluna]>=1){
          printf("Posicao Invalida,Digite outra Posicao:\n");
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
        matriz[linha - 1][coluna - 1]=jogada;
        system("clear");
        break;
        }
      }
      grid(matriz);
      novo_jogo(matriz);
  }


  int remover_jogada(int matriz[9][9]){
  int linha , coluna;
        printf("Remova uma jogada:\n");
        printf("Informe a linha desejada: ");
        scanf("%d", &linha);
        printf("Informe a coluna desejada: ");
        scanf("%d",&coluna);
        printf("Vc removeu a jogada da Linha %d Coluna %d\n",linha, coluna);
        matriz[linha][coluna]=0;
        system("clear");
        grid(matriz);
        novo_jogo(matriz);
  }

  int novo_jogo(int matriz [9][9]){
    int op;
  printf("Digite sua opcao: \n");
  printf("1-Nova jogada.\n");
  printf("2-Excluir jogada.\n");
  printf("3-Salvar progresso.\n");
  printf("4-Desistir.\n");
  scanf("%d",&op);
    grid(matriz);
    switch (op) {
      case 1: adicionar_jogada(matriz);
              break;
      case 2: remover_jogada(matriz);
              break;
      /*case 3: salvar_progresso(nome);
              break;
      case 4: return 0;*/
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
