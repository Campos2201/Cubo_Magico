#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "funcoes cubo magico.h"
#include "queuePackage.h"
#include "filaVisitados.h"

int menu(int matriz[][12], FILA* f, int caminhoAteResposta[NUM]);
int opcoesJogador(int matriz[2][12]);
int aleatorio(int n_min, int n_max);
int cuboInicial(int matriz[][12]);
void realiza_mov(int mov, int matriz[][12]);
void loopIA(FILA *f, VISITADOS *v, int cubo[][12]);

int main() {
    srand(time(NULL)); // Inicializa o gerador com o tempo atual

    int cubo_magico[2][12];
    int opc, caminhoAteResposta[NUM];
    int ultimaPosicao = 0;

    FILA* f = CriaFila();
    VISITADOS* v = CriaVisitados();

    // iniciando como matriz resposta so para comparar:
    matrizResposta(cubo_magico);
    printf("\n\nCubo antes de embaralhar:\n");
    interfaceGrafica(cubo_magico);

    printf("\n\nCubo depois de embaralhar\n");
    cuboInicial(cubo_magico);
    interfaceGrafica(cubo_magico);

    printf("\n\npressione qualquer tecla...");
    getch();
    system("cls");



    printf("\n\n                     BEM VINDO AO PROGRAMA (...)\n\n\n"
           "                  Pressione qualquer tecla para iniciar...");
    getch();

    // por enquanto so temos a opcao 1
    do{
        //system("cls");
        printf("\n\n                    CUBO INICIAL\n\n");
        interfaceGrafica(cubo_magico);
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
            opc = opcoesJogador(cubo_magico);
            realiza_mov(opc, cubo_magico);
        }while(cubo_magico);
    }
    system("cls");

    if(opc == 2)
    {
        loopIA(f, v, cubo_magico);
        ultimaPosicao = CuboMontado(f, caminhoAteResposta);
        printf("Caminho ate a resposta: ");
        for(int i = 0; i<ultimaPosicao+1; i++)
        {
            printf("%d - ", caminhoAteResposta[i]);
        }
    }
    printf("\n\n         Voce venceu :) !\n");
    interfaceGrafica(cubo_magico);


    return 0;
}

int aleatorio(int n_min, int n_max)
{
    return rand() % (n_max - n_min + 1) + n_min;
}

// funcao que embaralha o cubo a partir da matriz resposta
int cuboInicial(int matriz[][12])
{
//    int anterior = 0, num;
//    int mov;
//
//    matrizResposta(matriz);
//    num = aleatorio(6,8);
//
//    while(num > 0)
//    {
//        mov = aleatorio(1,12);   // dps adicionar todos os 6 movimentos (por enquanto so temos esses)
//        if(mov != anterior)
//        {
//            realiza_mov(mov, matriz);
//            anterior = num;
//            num--;
//        }
//    }

    matrizResposta(matriz);
    realiza_mov(1, matriz);
    realiza_mov(8, matriz);
    realiza_mov(11, matriz);
    realiza_mov(5, matriz);
    //realiza_mov(1, matriz);
    //realiza_mov(3, matriz);
    //realiza_mov(6, matriz);
}

int menu(int matriz[][12], FILA* f, int caminhoAteResposta[NUM])
{

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
               "                  7. Rodar base no sentido anti-horario\n"
               "                  8. Rodar base no sentido horario\n"
               "                  9. Rodar parte da frente no sentido horario\n"
               "                  10. Rodar parte da frente no sentido anti-horario\n"
               "                  11. Rodar parte de tras no sentido horario\n"
               "                  12. Rodar parte de tras no sentido anti-horario\n"
               "                  13. Rotacionar cubo para cima\n"
               "                  14. Rotacionar cubo para baixo\n"
               "                  15. Rotacionar cubo no sentido anti-horario\n"
               "                  16. Rotacionar cubo no sentido horario\n"
               "                  17. Rotacionar frente no sentido anti-horario\n"
               "                  18. Rotacionar frente no sentido horario\n"
               "                  19. Quero que a IA resolva para mim\n"
               "                  0. Sair\n"
               "                  ");
               scanf("%d", &opc);

    }while(opc<0 || opc>19);

    return opc;
}

void loopIA(FILA *f, VISITADOS *v, int cubo[][12])
{
    int montado, mov;
    int posicao = 0;
    int proxIndice = 0;
    int vetorMovimentos[NUM];
    int cubo_visitado[2][12];
    ESTADO *estado = InsereVisitados(v, cubo);

    int cubo_inicial[2][12];
    copia(cubo, cubo_inicial);

    if(!estado)
        printf("NULO VISITADOS\n");

    InsereFila(f, 0, 0, vetorMovimentos, estado);
    if(!f->INICIO)
        printf("SEM INICIO\n");
    int i = 0;


    do
    {
            printf("\n\n\n\n ---------------- FILHO %d\n", f->INICIO->num);

        printf("\n\nVisitando indice = %d\n",proxIndice);
        mov = f->INICIO->movimentos[proxIndice];
        printf("\nMovimento: %d", mov);
        printf("\nAntes de movimentar:\n");
        imprime(cubo);
        montado = visitaEstado(f, cubo);
        printf("Depois de movimentar:\n");
        imprime(cubo);

        if(!montado)
        {
            printf("Depois de arrumar:\n");
            if(posicao >0)
            {
                arrumaCubo(cubo_inicial, cubo, f->INICIO);
            }
            imprime(cubo);
            posicao = f->INICIO->ultimaPos;
            vetor(f, vetorMovimentos);
            proxIndice = encontraPosicao(f->INICIO);
            copia(f->INICIO->estadoNo->matriz, cubo_visitado);
            RemoveFila(f);
            funcaoSucessora(f, posicao + 1, mov, vetorMovimentos, v, cubo_visitado);
            printf("ultima posicao: %d\n", f->INICIO->ultimaPos);
            //printf("ultimo mov: %d\n", f->INICIO->movimentos[f->INICIO->ultimaPos]);
        }
    } while(!montado);
}

