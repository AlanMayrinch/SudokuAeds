#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include <sys/time.h>

//int bem_vindo();
int menu();
int menu_de_jogadas(int matriz[9][9]);
int imprime_sudoku(int matriz[9][9]);
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
int tempo(int matriz[9][9]);



int main(){
  printf("\n");
  //bem_vindo();
  menu();
  return 0;
}



    int menu(){
      //A Funçao menu, aparece apos a tela de bem vindo, ela mostra as regras do sudoku, e instruções para
      // o jogador, se ele quer um novo jogo, ou carregar um anterior que ele tenha salvo ou sair do jogo,
      //caso ele tenha desistido de jogar.
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
          printf("\t\t\tRegras do jogo\n");//printa a mensagem na tela.
          printf("\tO objetivo do Sudoku é preencher todos os espaços vazios\n");//printa a mensagem na tela.
          printf("\tcom numeros de 1 a 9. Porem o numero escolhido nao pode estar\n");//printa a mensagem na tela.
          printf("\tse repetindo na mesma coluna, linha e bloco.\n");//printa a mensagem na tela.
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

    //comeco da funcao imprime_sudoku
    int imprime_sudoku(int matriz[9][9]){
      /*Essa funçao simplesmente imprime na tela a matriz, escolhida pelo jogador na funçao novo_jogo,
      de um jeito parecido com um Sudoku.
      */
        int i, j, c = 1;
        system("clear||cls");
        printf("   1      2      3       4      5      6       7      8      9\n");

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
            printf(" %d", c++);
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

  // comeco da funcao adicionar_jogada
   int adicionar_jogada(int matriz[9][9]){
     /*esta funçao adciona um jogada, ela recebe matriz atraves do menu de jogadas, o jogador
     deve informa um posição que deseja realizar sua jogada, entao a funçao testa se a posição digitada é
     valida(para ser valido o valo da posiçao tem de ser iguall a 0)
     se nao for invalida entao o mostrado a posição que ele selecionou, e ele pode fazer uma jogada entre 1 e 9
     mas caso ele digite um valor diferente, o jogo volta ao menu de jogadas e aparece na tela uma mensagem que diz
     para fazer a jogada com numero entre 1 e 9*/
        int linha , coluna, jogada;
        printf("Informe a linha desejada: ");//printa a mensagem na tela.
        scanf("%d", &linha);
        printf("Informe a coluna desejada: ");//printa a mensagem na tela.
        scanf("%d",&coluna);
        if(matriz[linha-1][coluna-1] >= 1){

          printf("[%d][%d]Posicao Invalida,Digite outra Posicao:\n",linha,coluna);//printa a mensagem na tela.
          menu_de_jogadas(matriz);
        }
        else{
          printf("Linha %d Coluna %d\n",linha, coluna);
          printf("Faça sua jogada com numeros entre 1 e 9: ");//printa a mensagem na tela.
          scanf("%d", &jogada);
          if(jogada<1||jogada>9){
            printf("Faça sua jogada com numeros entre 1 e 9:");//printa a mensagem na tela.
          }
          else {
          matriz[linha-1][coluna-1]=jogada;
          system("clear||cls");
          imprime_sudoku(matriz);// a matriz é printada na tela(pela funçao imprime_matriz), porem modificada pelo jogador
          menu_de_jogadas(matriz);// o jogador sera levada de volta para o menu_de_jogadas.
          }
        }
  }

  //comeco da funcao remover_jogada
  int remover_jogada(int matriz[9][9]){
    /*Nessa função o jogador escolhe a posiçao na matriz(Sudoku) que ele deseja remover
    o numero que esta la, porem com algumas restriçoes: o jogador nao podera remover numeros
    em posições na matriz que foi sorteada no inicio do jogo; se o numero que esta na posiçao que ele escolher
    for igual a 0, ele nao podera altera - lo;
    */
    int linha ,coluna;
    int i,j,original[9][9];
      FILE *inalteravel=fopen("ultimojogo.txt","r");
      //matriz salva quando o jogador escolhe uma opcçao de dificuldade, seus valores difentetes de 0 nao podem ser alterados.
      if (inalteravel == NULL) {
        printf("\nERRO AO INICIAR.\n");
        exit(1);
      }
    for(i=0;i<9;i++){
      for(j=0;j<9;j++){
          fscanf(inalteravel,"%d",&original[i][j]);// lendo a matriz que esta salva no arquivo
      }
    }
    fclose(inalteravel);
        printf("Remova uma jogada:\n");//printa a mensagem na tela.
        printf("Informe a linha desejada: ");//printa a mensagem na tela.
        scanf("%d", &linha);
        printf("Informe a coluna desejada: ");//printa a mensagem na tela.
        scanf("%d",&coluna);
        if(original[linha-1][coluna-1]!=0){// restricao para nao remover numeros da matriz original
          printf("Posicao inalteravel!\n");//printa a mensagem na tela.
        }
        else{
        printf("Voce removeu a jogada da Linha %d Coluna %d\n",linha, coluna);//printa a mensagem na tela.
        matriz[linha-1][coluna-1]=0;
      }

        imprime_sudoku(matriz);// a matriz é printada na tela(pela funçao imprime_matriz), porem modificada pelo jogador
        menu_de_jogadas(matriz);// o jogador sera levada de volta para o menu_de_jogadas.
  }

  //comeco da funcao salvar_progresso
  int salvar_progresso(int matriz[9][9]){
    /* Essa função tem commo finalidade salvar o progresso do jogador. Quando o
    jogador escolher a opção de salvar o jogo, na funçao menu jogadas, essa funçao
    cria um arquivo e salva nele a matriz da mesma forma que o jogador parou de jogar.
    */

      FILE *save = fopen("save.txt","w");//abre o arquivo
    if(save == NULL) {//verificar houve erro ao salvar o arquivo
    printf("\nERRO SAVE COMRROPIDO.\n");
    exit(1);
    }
    int i,j;
    for(i=0;i<9;i++){// percorre a linha da matriz
      for(j=0;j<9;j++){//percorre a coluna da matriz
        fprintf(save,"%d ",matriz[i][j]);// salva a matriz no arquivo do ponto que o jogador parou de jogar
      }
      fprintf(save, "\n");
    }

    printf("Jogo Salvo Com Sucesso.\n");//printa a mensagem na tela.
    fclose(save);//fecha o arquivo

  }

  //comeco da funcao carregar_jogo
  int carregar_jogo(){
    /*Essa função carrega o jogo que foi salva pela função salvar_progresso
    lendo a matriz que esta contida no arquivo fazendo com que ela seja a matriz
    que vai ser lida pelo programa.
    */

    system("clear||cls");
    int i=0,j=0;
    int recebe[9][9];//matriz que foi salva pelo jogador
    FILE *save=fopen("save.txt","r");
    if (save == NULL) {
      printf("\nERRO SAVE COMRROPIDO.\n");
      exit(1);
    }
    printf("Jogo Carregado.\n");

     for(i=0;i<9;i++){
      for(j=0;j<9;j++){
          fscanf(save,"%d",&recebe[i][j]); // lendo a matriz do arquivo.
      }
    }
      fclose(save);
      imprime_sudoku(recebe);
      tempo(recebe);// o jogador sera levada de volta para o menu_de_jogadas.
  }

  //comeco da funcao bem_vindo
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

  //comeco da funcao menu_de_jogadas
  int menu_de_jogadas(int matriz [9][9]){
  /*A função menu de jogadas é simplismente a parte do codigo em que o jogador
   faz todas suas jogadas, chamando as outras funções: adcionar jogada, remover jogadas
  salvar progresso e a funçao verificar a soluçao. que so é chamada depois que todos os
  numeros da matriz forem preenchidos.*/

    int op,zero=0;
    printf("Digite sua opcao: \n");//printa a mensagem na tela.
    printf("\n");
    printf("1-Nova jogada.\n");//printa a mensagem na tela.
    printf("2-Excluir jogada.\n");//printa a mensagem na tela.
    printf("3-Salvar progresso e sair.\n");//printa a mensagem na tela.
    printf("4-Desistir.\n");//printa a mensagem na tela.
    printf("\n");
      for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
          if(matriz[i][j]==0){
            zero=1;
          }
        }
      }
    if(zero==0){
      printf("5-Verificar a solucao.\n");//printa a mensagem na tela.
      printf("\n");
      }

    printf("Opcao escolhida: ");//printa a mensagem na tela.
    scanf("%d",&op);
    printf("\n\n");

    switch (op) {
      case 1: imprime_sudoku(matriz);// a matriz é printada na tela(pela funçao imprime_matriz), porem modificada pelo jogador
              adicionar_jogada(matriz);
              break;
      case 2: imprime_sudoku(matriz);// a matriz é printada na tela(pela funçao imprime_matriz), porem modificada pelo jogador
              remover_jogada(matriz);
              break;
      case 3: salvar_progresso(matriz);
              break;
      case 4: printf("VC E FRACO LHE FALTA SODOKU\n\n");//printa a mensagem na tela.
              menu(); // chama a funçao menu, para que o usuario escolha um novo jogo,reniciando seu tempo, ou saia do jogo.
              return 0;
      case 5: verifica_resolucao(matriz);
              break;

      default: system("clear||cls");
               imprime_sudoku(matriz);
               printf("Opcao invalida\n");//printa a mensagem na tela.
               menu_de_jogadas(matriz);// o jogador sera levada de volta para o menu_de_jogadas.
    }
  }

  //comeco da funcao novo_jogo
  int novo_jogo(){
    // esta funçao é chamada na função menu, ela mostra os niveis do jogo, e permite ao usuario escolher um.
      int radom;
      int matriz[9][9];
      int i,j;
      int dificuldade;
      FILE *select;
      printf ("Escolha a dificuldade do jogo\n");//printa a mensagem na tela.
      printf("1 - Facil\n2 - Medio\n3 - Dificil\n");//printa a mensagem na tela.
      scanf("%d", &dificuldade);
      srand((unsigned)time(NULL));// sorteia um numero de um 1 a 5
      radom = (1 + rand()%5);
      system("cls||clear");
      //ler um arquivo, que possui uma matriz 9x9, aleatoriamente, atraves do numero sorteado de 1 a 5, pega umas das 5 matrizes da diculdade
      // que o usuario selecionar
      if(dificuldade==1){
       switch(4){
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
      printf("Jogo pronto\n");//printa a mensagem na tela.
    }

      for(i=0;i<9;i++){// passa o conteudo do arquivo para matriz do tipo inteiro 9x9.
        for(j=0;j<9;j++){
          fscanf(select,"%d ", &matriz[i][j]);
        }
      }
      fclose(select);

      FILE *original = fopen("ultimojogo.txt","w");// salva um copia que nao vai ser alterada toda vez que o usuaria iniciar o jogo.
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

      imprime_sudoku(matriz);// a matriz salva pelo jogador é printada na tela(pela funçao imprime_matriz).
      tempo(matriz);// a funcao tempo é chamada e começa a ser contado o tempo de execução a partir daqui.

      return 0;
    }

    //comeco da funcao verifica_coluna
  int verifica_coluna(int matriz[9][9]){
    /* esta funçao verifica as colunas, se ouver numeros iguais ela retorna 0, se não retorna 1
       atraves do laço e das variaves coluna e coluna2 que representao as linhas da matriz, ela compara os
       valores que estão no endereço de coluna e coluna2 quando os endereços de coluna e coluna2 forem diferentes
    */
  		int i,coluna2,coluna;
  		int contador=0;
      int reposta=0;
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
  	   return 0;
  		}
  		else
        return 1;
  	  }

    //comeco da funcao verifica_linha
  	int verifica_linha(int matriz[9][9]){
        /* esta funçao verifica as linhas, se ouver numeros iguais ela retorna 0, se não retorna 1
       atraves do laço e das variaves linha e linha2 que representao as linhas da matriz, ela compara os
       valores que estão no endereço de linha e linha2 quando os endereços de linha e linha 2 forem diferentes
       basimente ela faz a mesma coisa do verificar coluna, porem com as linhas da matriz.
       */
  		int i,linha,linha2;
  		int contador=0;
      int reposta=0;
  		for(i=0;i<9;i++){//
  			for(linha=0;linha<9;linha++){
  				for(linha2=0;linha2<9;linha2++){
  					if(matriz[linha][i]==matriz[linha2][i] && linha!=linha2){
  					contador++;
  					}
  				}
  			}
  		}
  		  if(contador!=0){
       return 0;
      }
      else
      return 1;
    }

    //comeco da funcao verifica_quadrado
    int verifica_quadrado(int matrizinha[3][3]){
      /*Essa funcao recebe as matrizes 3x3 que forem sendo divididos na funçao faz_0_quadradinho,
      percorrendo-as, e verificando se há algum numero de 1 a 9 que esta se repetindo. Caso nenhum
      numero da matriz 3x3 (quadrante 3x3 do sudoku) que ela ira receber repetir, o contador nao ira iterar, fazendo com que
      a funçao retorne 1 (verdadeiro), caso algum numero se repita, em alguma das matrizes 3x3 (quadrantes 3x3 do sudoku) que ela recebe,
      ira retornar 0 (falso);
      */
    			int i,j,contador=0;
    			int num,reposta=1;
    			for(num=1;num<=9;num++){// a variavel num vai de 1 ate 9, que sao os numeros que vao ser verificados.
    				for(i=0;i<3;i++){// percorre a linha da matriz.
    					for(j=0;j<3;j++){// percorre a coluna da matriz.
    						if(matrizinha[i][j]==num){// se a posiçao i j for igual ao num, contador itera.
    							contador++;
                }
              }
            }
    				if(contador>1){
              return 0;// se algum numero se repetir.
            }

    			  contador = 0;// zera o contador toda vez que uma nova matriz 3x3 (quadrante 3x3 do sudoku), é recebida.
    		  }
          if(contador = 0)
          return 1;// se nenhum numero se repetir.

    	}

        // começo da funcao faz_0_quadradinho
    		int faz_0_quadradinho(int matriz [9][9]){
          /*Essa função tem como finalidade separar a matriz 9x9 em  9 matrizes 3x3 (quadrantes 3x3 do sudoku),
          toda vez que a matriz 9x9 for separa, a funçao verifica_quadrado é chamada para fazer
          verificaçao da matriz 3x3 que foi criada, ate acabar todos os quadrantes 3x3 da matriz.
          */
    			int linha, coluna;// contadores
    			int linhazinha, coluninha;//contadores
    			int matrizinha[3][3];// matriz que ira receber os quadrantes 3x3 que forem sendo divididos da matriz 9x9.
    			for(linha=0;linha<9;linha+=3){//precorre as linhas da matriz 9x9, com iteraçao 3 em 3.
    				for(coluna=0;coluna<9;coluna+=3){// pecorre as colunas da matriz9x9, com iteraçao 3 em 3.
    					for(linhazinha=0;linhazinha<3;linhazinha++){// percorre as linhas da matriz 3x3, com iteraçao 1 em 1
    						for(coluninha=0;coluninha<3;coluninha++){// percorre as colunas da matriz 3x3, com iteração 1 em 1
    							matrizinha[linhazinha][coluninha]=matriz[linha+linhazinha][coluna+coluninha];
                  //a matriz 9x9 é separada quadrante por quadrante (3x3) e a matrizinha recebe essa separação,
                  //e todas as 9  vez que isso acontece, a funçao verifica_quadrado é chamada para fazer a verificação, validando esse quadrante,
                  //fazendo isso ate que toda a matriz seja percorrida.
    				    }
    			    }
    			   verifica_quadrado(matrizinha);// a funcao verifica_quadrado recebe todas as matrizez 3x3, uma por vez, que foi dividida na funçao faz_0_quadradinho,
                // e verifica se elas tem numeros repetidos ou nao.
    		    }
    	    }
    }

    // comeco da funcao verifica_resolucao
    int verifica_resolucao(int matriz[9][9]){
      /*Essa funcao tem a finalidade de chamar as outras tres funçoes que verifica: linha, coluna e quadrado.
      Caso todas essas tres funções retornem 1, a soluçao do jogador estara correta, caso elas retornem 0,
      a solução do jogador estara errada e ele tera a chance de voltar a jogar caso ele queira.
      */
      if(verifica_linha(matriz) && verifica_coluna(matriz) && faz_0_quadradinho(matriz)){
        system("clear||cls");
        printf("Solucao Correta,Parabens !\n");//printa a mensagem na tela.
      }
      else{
        printf("Que pena,solucao Incorreta.\n");//printa a mensagem na tela.
        menu_de_jogadas(matriz);
      }
    }

  //começo da funcao tempo
  int tempo(int matriz[9][9]){
    struct timeval tv0,tv1;
    double tempo_final, tempo_inicial, time;
    gettimeofday(&tv0, NULL);
    menu_de_jogadas(matriz);
    gettimeofday(&tv1, NULL);
    tempo_final = (double)(tv1.tv_sec) + (double)(tv1.tv_usec)/ 1000000.00;
    tempo_inicial = (double)(tv0.tv_sec) + (double)(tv0.tv_usec)/ 1000000.00;
    time = (tempo_final - tempo_inicial);
    int minutos, segundos;
    minutos = time/60;
    segundos = (int) time%60; //é importante fazer um cast, pra forçar uma conversão pra inteiro pois time é double
    int zero = 0;
    for(int i=0;i<9;i++){
      for(int j=0;j<9;j++){
        if(matriz[i][j]==0){
          zero=1;
        }
      }
    }
    if(zero==0){
      printf("TEMPO : (%f)\n",time);
      printf("\n");
      printf(" %d minutos %d segundos\n",minutos,segundos);
      printf("\n");
      double recordes[3],aux;
      FILE *openrecorde = fopen("recordes.txt","r");
      if(openrecorde==NULL){
        printf("Erro ao salvar o melhores tempos.\n");
      }
      for(int i=0;i<3;i++){
          fscanf(openrecorde, "%lf",(recordes+i)); // le o conteudo da do arquivo
      }
      fclose(openrecorde);

      if(time<recordes[0]){// organiza os tempos salvos, matendo sempre um top 3 de melhores tempo.
            aux=recordes[0];
            recordes[2]=recordes[1];
            recordes[1]=aux;
            recordes[0]=time;
      }
      else{
        if(time<recordes[1]){
          aux=recordes[1];
          recordes[2]=aux;
          recordes[1]=time;
        }
        else{
          if(time<recordes[2]){
            recordes[2]=time;
          }
        }
      }//fim da organização dos 3 melhores tempos
      int cont = 1;
      printf("     RECORDES\n\n");
      for(int i=0;i<3;i++){// mostras o top 3 dos melhores tempos
        printf("TOP %d: [%lf]\n",cont,recordes[i] );
        cont++;
      }
      FILE *arq = fopen("recordes.txt","w");//cria um arquivo para salvar os recordes
      if(arq==NULL){
        printf("Erro ao salvar o melhores tempos.\n");
      }
      for(int i=0;i<3;i++){
        fprintf(arq, "%lf\n",recordes[i] );
      }
      fclose(arq);
    }
  else{
    FILE *times = fopen("timesave.txt","w");//cria um arquivo para salvar os recordes
    if(times==NULL){
      printf("Erro ao salvar o melhores tempos.\n");
    }
    fprintf(times, "%lf", time);
    fclose(times);
  }
    return 0;
  }
