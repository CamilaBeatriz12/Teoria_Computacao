//Implementação feita individual
//Camila Beatriz da Silva, RA: 2103214
//link do vídeo: https://drive.google.com/file/d/1Mt2X-J0GFF2ifdhl0QgX2oofnH6AF7fJ/view?usp=sharing

//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//FUNÇÕES PARA A PILHA
typedef struct NoPilha *PtrNoPilha;

//definição da pilha
typedef struct NoPilha{
  char x;
  PtrNoPilha proximo;
}NoPilha;

typedef struct{
  PtrNoPilha topo;
  int qtdElementos;
}PilhaDinamica;

//função de inicialização da pilha
void inicia(PilhaDinamica *p){
  p -> topo = NULL;
  p -> qtdElementos = 0;
}

//função para verificar se a pilha está vazia
bool Vazia(PilhaDinamica *p){
  return(p -> topo == NULL);
}

//função para inserir na pilha
void insere(PilhaDinamica *p, char x){
  PtrNoPilha aux;
  aux = (PtrNoPilha)malloc(sizeof(NoPilha));
  aux -> x = x;
  aux -> proximo = p -> topo;
  p -> topo = aux;
  p -> qtdElementos++;
}

//função para imprimir na pilha
void imprime(PilhaDinamica *p){
  printf("Pilha: {");

  for(PtrNoPilha ptr = p -> topo; ptr != NULL; ptr = ptr -> proximo){
    printf("%c ", ptr -> x);
  }

  printf("}\n");
}

//função para remover da pilha
int remover(PilhaDinamica *p){
  int ret = -1;

  if(!Vazia(p)){
    PtrNoPilha aux = p -> topo;
    ret = aux -> x;
    p -> topo = p -> topo -> proximo;
    free(aux);
    p -> qtdElementos--;
  }
  else{
    printf("Vazia!\n");
  }

  return ret;
}

//função para retornar o topo da pilha
char topoPilha(PilhaDinamica *p){
  char ret;

  if(!Vazia(p)){
      ret = p -> topo -> x;
      return ret;
  }
}

//função para destruir a pilha
void destroiPilha(PilhaDinamica *p){
  printf("Pilha destruida!\n");
  PtrNoPilha aux;

  while(p -> topo != NULL){
    aux = p -> topo;
    p -> topo = p -> topo -> proximo;
    free(aux);
  }
}

void palavraRejeitada1(PilhaDinamica *p){ //função para printar apenas que a palavra não foi aceita pelo autômato
    printf("\nEsta palavra nao foi reconhecida pelo automato, pois nao chegou ao estado final!\n");
    destroiPilha(p);
    exit(1);
}

void palavraRejeitada2(PilhaDinamica *p){ //função para printar apenas que a palavra não foi aceita pelo autômato
    printf("\nEsta palavra nao foi reconhecida pelo automato, pelo topo nao ser o caracter correto para desempilhar!\n");
    destroiPilha(p);
    exit(1);
}

void palavraRejeitada3(PilhaDinamica *p){ //função para printar apenas que a palavra não foi aceita pelo autômato
    printf("\nEsta palavra nao foi reconhecida pelo automato, pois a pilha nao esta vazia!\n");
    destroiPilha(p);
    exit(1);
}

void palavraAceita(PilhaDinamica *p){ //função para printar apenas que a palavra foi aceita pelo autômato
    printf("\nEsta palavra foi reconhecida pelo automato!\n");
    destroiPilha(p);
    exit(1);
}

int main(){ //int main
    PilhaDinamica pilhas; //variável para a manipulação de pilhas
    inicia(&pilhas); //cria a pilha

    //variáveis usadas no código
    int estadoAtual = 1; //ao invés de mexer com comparação com char, decide fazer com int...
                        //representa o estado atual em que se encontra a palavra...
                        //1 representa o estado q1, 2 representa o estado q2
                        //3 representa o estado q3, e 4 representa o estado q4...
                        //no caso é iniciado com 1, pois é o estado inicial do autômato
    char palavra[100000]; //palavra em que o usuário irá escolher
    int cont = 0; //servirá para conseguir imprimir a palavra inteira no passo a passo da verificação

    //variáveis do tipo char para que consiga printar {q1, q2, q3, q4} ao invés de {1, 2, 3, 4}
    char indicador_1[5] = "[q1]";
    char indicador_2[5] = "[q2]";
    char indicador_3[5] = "[q3]";
    char indicador_4[5] = "[q4]";


    printf("Digite a palavra que deseja com os caracteres a e b: \n"); //pedido da palavra para o usuário
    scanf("%s", palavra); //armazena

    int tamanhoPalavra = strlen(palavra); //obtenho o tamanho da palavra

    if(estadoAtual == 1){ //verifica se está no estado q1, já que é o estado inicial
      printf("\n"); //quebra de linha
      printf("%s\n", indicador_1); //printo na tela em qual estado está

      printf("Nao le nada na palavra nem na pilha, porem empilha '$'\n"); //como possui uma passagem sem precisar ler nada, aqui explico oq acontece

      insere(&pilhas, '$'); //empilha $
      imprime(&pilhas); //imprime a pilha
      printf("Topo da pilha: %c\n", topoPilha(&pilhas)); //imprime o topo da pilha
      estadoAtual++; //incrementa o estado já que devido a essa passagem pode ir direto para o estado q2

      printf("\n---------------------------------------------------\n"); //usado para ficar mais visível a mudança de estado
    }

    for(int i = 0; i <= tamanhoPalavra + 1; i++){ //for que percorre a palavra
        if(estadoAtual == 2){ //verifica se, no momento, o estado atual é o q2
            printf("\n"); //quebra de linha
            printf("%s\n", indicador_2); //printo na tela em qual estado está

            if(palavra[i] == 'a'){ //caso o caracter da palavra seja 'a', ele continua no estado q2...
              for(int j = 0; j <= tamanhoPalavra; j++){ //faço um novo for para percorrer a palavra
                  if(cont == i){ //caso o contador, seja igual ao indice do for mais externo...
                    printf("[%c]", palavra[j]); //ele demarca em qual caracter da palavra estamos analisando no autômato
                  }
                  else{ //caso contrário, ou seja, caso não seja igual ao índice...
                    printf("%c", palavra[j]); //ele imprimi o caracter sem a delimitação
                  }

                  cont++; //incremento o contador para a análise caso for igual ou não ao índice
              }

              insere(&pilhas, '0'); //insere 0 na pilha
              printf("\n"); //quebra de linha
              imprime(&pilhas); //imprime a pilha
              printf("Topo da pilha: %c\n", topoPilha(&pilhas)); //imprime o topo da pilha

              printf("\n---------------------------------------------------\n"); //usado para ficar mais visível a mudança de estado
            }
            else{ //caso o caracter da palavra seja 'b', ele vai para o estado q3...
              for(int j = 0; j <= tamanhoPalavra; j++){ //faço um novo for para percorrer a palavra
                  if(cont == i){ //caso o contador, seja igual ao indice do for mais externo...
                    printf("[%c]", palavra[j]); //ele demarca em qual caracter da palavra estamos analisando no autômato
                  }
                  else{ //caso contrário, ou seja, caso não seja igual ao índice...
                    printf("%c", palavra[j]); //ele imprimi o caracter sem a delimitação
                  }

                  cont++; //incremento o contador para a análise caso for igual ou não ao índice
              }

              estadoAtual++; //incrementa o estado para ir para q3

              if(topoPilha(&pilhas) == '0'){ //verifica se o topo da pilha é 0
                remover(&pilhas); //neste caso, ele le da pilha um 0, então terá que remover do topo
                printf("\n"); //quebra de linha
                imprime(&pilhas); //imprime a pilha resultante da ação
              }
              else{ //else
                palavraRejeitada2(&pilhas); //caso contrário a palavra é rejeitada
              }

              printf("Topo da pilha: %c\n", topoPilha(&pilhas)); //imprime o topo da pilha

              printf("\n---------------------------------------------------\n"); //usado para ficar mais visível a mudança de estado
            }
        }

        else if(estadoAtual == 3){ //verifica se, no momento, o estado atual é o q3
            printf("\n"); //quebra de linha
            printf("%s\n", indicador_3); //printo na tela em qual estado está
            if(palavra[i] == 'b'){ //caso o caracter da palavra seja 'b', ele permanece no estado q3...
              for(int j = 0; j <= tamanhoPalavra; j++){ //faço um novo for para percorrer a palavra
                  if(cont == i){ //caso o contador, seja igual ao indice do for mais externo...
                    printf("[%c]", palavra[j]); //ele demarca em qual caracter da palavra estamos analisando no autômato
                  }
                  else{ //caso contrário, ou seja, caso não seja igual ao índice...
                    printf("%c", palavra[j]); //ele imprimi o caracter sem a delimitação
                  }

                  cont++; //incremento o contador para a análise caso for igual ou não ao índice
              }

              if(topoPilha(&pilhas) == '0'){ //verifica se o topo é 0
                remover(&pilhas); //neste caso, ele le da pilha um 0, então terá que remover do topo
                printf("\n"); //quebra de linha
                imprime(&pilhas); //imprime a pilha
              }
              else{ //else
                palavraRejeitada2(&pilhas); //caso contrário a palavra é rejeitada
              }

              printf("Topo da pilha: %c\n", topoPilha(&pilhas)); //imprime o topo da pilha

              printf("\n---------------------------------------------------\n"); //usado para ficar mais visível a mudança de estado
            }
            else{
              if(topoPilha(&pilhas) == '$'){ //verifica se o topo é '$'
                printf("Nao le nada na palavra nem empilha, porem desempilha '$'"); //devido a passagem sem ler nada da palavra e nem empilhar nada na pilha, explico q é necessário desempilhar $
                remover(&pilhas); //removo $
                printf("\n"); //quebra de linha
                imprime(&pilhas); //imprime a pilha
              }
              else{ //else
                palavraRejeitada2(&pilhas); //caso contrário a palavra é rejeitada
              }

              printf("Topo da pilha: %c\n", topoPilha(&pilhas)); //imprime o topo da pilha

              estadoAtual++; //incrementa o estado

              printf("\n---------------------------------------------------\n"); //usado para ficar mais visível a mudança de estado
            }
        }

        cont = 0; //reseta o contador para que seja possível demarcar e printar o caracter certo em cada interação que o for fizer
    }

    //serve para escrever o estado final da palavra bo autômato
    if(estadoAtual == 1){
      printf("%s\n", indicador_1);
    }
    else if(estadoAtual == 2){
      printf("%s\n", indicador_2);
    }
    else if(estadoAtual == 3){
      printf("%s\n", indicador_3);
    }
    else{
      printf("%s\n", indicador_4);
    }

    int estadoFinal = estadoAtual; //apenas por questão de entendimento, já que a palavra saiu do for, ou seja, chegou ao fim, ...
                                  //é possível ter seu estado final

    if(estadoFinal != 4){ //caso a palavra não chegue ao estado 4...
      palavraRejeitada1(&pilhas); //rejeitada
      if(!Vazia(&pilhas)){ //caso a pilha não esteja vazia...
        palavraRejeitada3(&pilhas); //rejeitada
      }
    }
    else{ //else
      palavraAceita(&pilhas); //diferente disso, a palavra é aceita pelo autômato
    }

    return 0; //return 0
} //end
