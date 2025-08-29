#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "funcoes cubo magico.h"

void menu(int matriz[][12]);
int opcoesJogador(int matriz[2][12]);
int aleatorio(int n_min, int n_max);
int cuboInicial(int matriz[][12]);
void realiza_mov(int mov, int matriz[][12]);

int main() {
    srand(time(NULL)); // Inicializa o gerador com o tempo atual

    int cubo_magico[2][12];

    // iniciando como matriz resposta so para comparar:
    matrizResposta(cubo_magico);
    printf("\n\nCubo antes de embaralhar:\n");
    interfaceGrafica(cubo_magico);

    //printf("\n\nCubo depois de embaralhar\n");
    //cuboInicial(cubo_magico);
    //interfaceGrafica(cubo_magico);

    printf("\n\npressione qualquer tecla...");
    getch();
    system("cls");

    menu(cubo_magico);
    printf("\n\n         Voce venceu :) !\n");
    interfaceGrafica(cubo_magico);

    /*int matriz_resposta[2][12];

    // construindo a matriz resposta
    matrizResposta(matriz_resposta);

    // copiando a matriz resposta no cubo magico, para testes
    copia(matriz_resposta, cubo_magico);


    // imprimindo matriz resposta
    printf("Matriz resposta: \n");
    imprime(matriz_resposta);
    printf("\n");

    roda_lado_direito_para_baixo(cubo_magico);

    // imprimindo cubo magico
    printf("Cubo magico: \n");
    imprime(cubo_magico);

    roda_lado_direito_para_cima(cubo_magico);

    // imprimindo cubo magico
    printf("Cubo magico: \n");
    imprime(cubo_magico);

    printf("Interface grafica do cubo atual:\n");
    interfaceGrafica(cubo_magico);
    */

    return 0;
}

int aleatorio(int n_min, int n_max)
{
    return rand() % (n_max - n_min + 1) + n_min;
}

// funcao que embaralha o cubo a partir da matriz resposta
int cuboInicial(int matriz[][12])
{
    int anterior = 0, num;
    int mov;

    matrizResposta(matriz);
    num = aleatorio(10,15);

    while(num > 0)
    {
        mov = aleatorio(1,3);   // dps adicionar todos os 6 movimentos (por enquanto so temos esses)
        if(mov != anterior)
        {
            realiza_mov(mov, matriz);
            if(mov > 6)
            {
                realiza_mov(mov-6, matriz);    // para poder embaralhar tbm com os movimentos "inversos"
                realiza_mov(mov-6, matriz);
                realiza_mov(mov-6, matriz);
            }
            anterior = num;
            num--;
        }
    }
}

void realiza_mov(int mov, int matriz[][12])
{
    switch(mov)
    {
        case 1:
        {
            roda_lado_direito_para_cima(matriz);
            break;
        }

        case 2:
        {
            roda_lado_direito_para_baixo(matriz);
            break;
        }

        case 3:
        {
            esqCimaNovo(matriz);
            break;
        }

        case 4:
        {
            esqBaixo(matriz);
            break;
        }

        case 5:
        {
            cimaAntiHorario(matriz);
            break;
        }

        case 6:
        {

            break;
        }

        case 7:
        {
            rotacionarCima(matriz);
            break;
        }

        // esses seriam só para o modo do jogador
        case 8:
        {
            rotacionarAntiHorario(matriz);
            break;
        }

        case 9:
        {
            break;
        }

        case 10:
        {
            break;
        }

        case 11:
        {
            break;
        }

        case 12:
        {
            break;
        }

        // esses seriam só para o modo do jogador
        case 13:
        {
            rotacionarCima(matriz);
            break;
        }

        case 14:
        {
            rotacionarBaixo(matriz);
            break;
        }

        case 15:
        {
            rotacionarAntiHorario(matriz);
            break;
        }

        case 16:
        {
            rotacionarHorario(matriz);
            break;
        }

        case 17:
        {
            break;
        }

        case 0:
        {
            exit(1);
        }
    }
}

void menu(int matriz[][12])
{
    int opc, opc2;
    printf("\n\n                     BEM VINDO AO PROGRAMA (...)\n\n\n"
           "                  Pressione qualquer tecla para iniciar...");
    getch();

    // por enquanto so temos a opcao 1
    do{
        //system("cls");
        printf("\n\n                    CUBO INICIAL\n\n");
        interfaceGrafica(matriz);
        printf("\n\n"
               "                  Selecione uma das opcoes: (so opcao 1 funciona)\n"
               "                  1. Quero eu mesmo(a) montar o cubo\n"
               "                  2. Quero que a IA resolva para mim\n"
               "                  ");
        scanf("%d", &opc);
    }while(opc!=1 && opc!=2);

    if(opc == 1)
    {

        do{
            opc = opcoesJogador(matriz);
            realiza_mov(opc, matriz);
        }while(!funcao_avaliadora(matriz));
    }

    system("cls");
}

int opcoesJogador(int matriz[2][12])
{
    int opc;
    do {
        system("cls");
        printf("\n\n                  Modo de jogo: LIVRE\n\n\n");
        printf("\n                  Cubo Atual\n");
        interfaceGrafica(matriz);
        printf("\n Matriz:\n");
        imprime(matriz);
        printf("\n\n                  Selecione uma das acoes abaixo: (apenas 3 a 5 e 13 a 16 implementadas!!)\n"
               "                  1. Rodar lado direito para cima\n"
               "                  2. Rodar lado direito para baixo\n"
               "                  3. Rodar lado esquerdo para cima\n"
               "                  4. Rodar lado esquerdo para baixo\n"
               "                  5. Rodar parte de cima no sentido anti-horario\n"
               "                  6. Rodar parte de cima no sentido horario\n"
               "                  7. Rodar parte de baixo no sentido anti-horario\n"
               "                  8. Rodar parte de baixo no sentido horario\n"
               "                  9. Rodar parte da frente no sentido horario\n"
               "                  10. Rodar parte da frente no sentido anti-horario\n"
               "                  11. Rodar parte de tras no sentido horario\n"
               "                  12. Rodar parte de tras no sentido anti-horario\n"
               "                  13. Rotacionar cubo para cima\n"
               "                  14. Rotacionar cubo para baixo\n"
               "                  15. Rotacionar cubo no sentido anti-horario\n"
               "                  16. Rotacionar cubo no sentido horario\n"
               "                  17. Quero que a IA resolva para mim\n"
               "                  0. Sair\n"
               "                  ");
               scanf("%d", &opc);

    }while(opc<0 || opc>17);

    return opc;
}

