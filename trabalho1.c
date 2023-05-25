//Implementação e trabalho escrito feito individual
//Camila Beatriz da Silva, RA: 2103214

//bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void palavraRejeitada(){ //função para printar apenas que a palavra não foi aceita pelo autômato
    printf("\nEsta palavra nao foi reconhecida pelo automato!\n");
    exit(1);
}

void palavraAceita(){ //função para printar apenas que a palavra foi aceita pelo autômato
    printf("\nEsta palavra foi reconhecida pelo automato!\n");
    exit(1);
}

int main(){ //int main
    //variáveis usadas no código
    int estadoAtual = 0; //ao invés de mexer com comparação com char, decide fazer com int...
                        //representa o estado atual em que se encontra a palavra...
                        //0 (zero) representa o estado q0, 1 representa o estado q1
                        //e 2 representa o estado q2...
                        //no caso é iniciado com 0, pois é o estado inicial do autômato
    char palavra[100000]; //palavra em que o usuário irá escolher
    int cont = 0; //servirá para conseguir imprimir a palavra inteira no passo a passo da verificação

    //variáveis do tipo char para que consiga printar {q0, q1 e q2} ao invés de {0, 1 e 2}
    char indicador_1[5] = "[q0]";
    char indicador_2[5] = "[q1]";
    char indicador_3[5] = "[q2]";


    printf("Digite a palavra que deseja com os caracteres 1 e 0: \n"); //pedido da palavra para o usuário
    scanf("%s", palavra);

    int tamanhoPalavra = strlen(palavra); //obtenho o tamanho da palavra

    for(int i = 0; i <= tamanhoPalavra; i++){ //for que percorre a palavra
        if(estadoAtual == 0){ //verifica se está no estado q0, já que é o estado inicial
          printf("\n"); //quebra de linha
          printf("%s\n", indicador_1); //printo na tela em qual estado está

            if(palavra[i] == '1'){ //caso o primeiro caracter da palavra seja 1, ele vai para estado q1...
                for(int j = 0; j <= tamanhoPalavra; j++){ //faço um novo for para percorrer a palavra
                    if(cont == i){ //caso o contador, que está em 0, seja igual ao indice do for mais externo, que também é 0...
                      printf("[%c]", palavra[j]); //ele demarca em qual caracter da palavra estamos analisando no autômato
                    }
                    else{ //caso contrário, ou seja, caso não seja igual ao índice...
                      printf("%c", palavra[j]); //ele imprimi o caracter sem a delimitação
                    }

                    cont++; //incremento o contador para a análise caso for igual ou não ao índice
                }
                printf("\n---------------------------------------------------\n"); //usado para ficar mais visível a mudança de estado
                estadoAtual++; //incrementa o estado pois o caracter lido é reconhecido pelo autômato e é possível passar para o próximo estado
            }
            else{
                palavraRejeitada(); //no autômato obtido, caso o caracter lido não seja 1, automaticamente a palavra não é reconhecida...
                                    //pois não existe entrada com 0 (zero) neste autômato.
            }
        }

        else if(estadoAtual == 1){ //verifica se, no momento, o estado atual é o q1
            printf("\n"); //quebra de linha
            printf("%s\n", indicador_2); //printo na tela em qual estado está

            if(palavra[i] == '0'){ //caso o caracter da palavra seja 0, ele vai para o estado q2...
              for(int j = 0; j <= tamanhoPalavra; j++){ //faço um novo for para percorrer a palavra
                  if(cont == i){ //caso o contador, seja igual ao indice do for mais externo...
                    printf("[%c]", palavra[j]); //ele demarca em qual caracter da palavra estamos analisando no autômato
                  }
                  else{ //caso contrário, ou seja, caso não seja igual ao índice...
                    printf("%c", palavra[j]); //ele imprimi o caracter sem a delimitação
                  }

                  cont++; //incremento o contador para a análise caso for igual ou não ao índice
              }
              printf("\n---------------------------------------------------\n"); //usado para ficar mais visível a mudança de estado
              estadoAtual++; //incrementa o estado pois o caracter lido é reconhecido pelo autômato e é possível passar para o próximo estado
            }
            else{ //caso o caracter da palavra seja 1, ele permanece no estado q1...
              for(int j = 0; j <= tamanhoPalavra; j++){ //faço um novo for para percorrer a palavra
                  if(cont == i){ //caso o contador, seja igual ao indice do for mais externo...
                    printf("[%c]", palavra[j]); //ele demarca em qual caracter da palavra estamos analisando no autômato
                  }
                  else{ //caso contrário, ou seja, caso não seja igual ao índice...
                    printf("%c", palavra[j]); //ele imprimi o caracter sem a delimitação
                  }

                  cont++; //incremento o contador para a análise caso for igual ou não ao índice
              }
              printf("\n---------------------------------------------------\n"); //usado para ficar mais visível a mudança de estado
            }
        }

        else if(estadoAtual == 2){ //verifica se, no momento, o estado atual é o q2
            printf("\n"); //quebra de linha
            printf("%s\n", indicador_3); //printo na tela em qual estado está
            if(palavra[i] == '0' || palavra[i] == '1'){ //caso o caracter da palavra seja 0 ou 1, ele permanece no estado q2 infinitamente...
              for(int j = 0; j <= tamanhoPalavra; j++){ //faço um novo for para percorrer a palavra
                  if(cont == i){ //caso o contador, seja igual ao indice do for mais externo...
                    printf("[%c]", palavra[j]); //ele demarca em qual caracter da palavra estamos analisando no autômato
                  }
                  else{ //caso contrário, ou seja, caso não seja igual ao índice...
                    printf("%c", palavra[j]); //ele imprimi o caracter sem a delimitação
                  }

                  cont++; //incremento o contador para a análise caso for igual ou não ao índice
              }
              printf("\n---------------------------------------------------\n"); //usado para ficar mais visível a mudança de estado
            }
        }

        cont = 0; //reseta o contador para que seja possível demarcar e printar o caracter certo em cada interação que o for fizer
    }

    int estadoFinal = estadoAtual; //apenas por questão de entendimento, já que a palavra saiu fo for, ou seja, chegou ao fim, ...
                                  //é possível ter seu estado final

    if(estadoFinal == 2){ //como no autômato o estado final é q2, este if tem a função de printar na tela que a palavra foi aceita
        palavraAceita(); //função implementada na linha 11
    }
    else{ //caso contrário, ou seja, o estado final não seja q2, printa na tela que a palavra não foi aceita
        palavraRejeitada(); //função implemnetada na linha 6
    }

    return 0; //return 0
} //end
