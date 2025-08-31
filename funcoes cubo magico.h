#ifndef FUNCOES_CUBO_MAGICO_H_INCLUDED
#define FUNCOES_CUBO_MAGICO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

// prototipos das funcoes
void matrizResposta(int antiga[2][12]);
void imprime(int matriz[2][12]);
void copia(int orig[2][12], int dest[2][12]);
void roda_lado_direito_para_cima(int matriz[2][12]);
void roda_lado_direito_para_baixo(int matriz[2][12]);
void roda_base_do_cubo_sentido_horario(int matriz[2][12]);
void roda_base_do_cubo_sentido_antihorario(int matriz[2][12]);
void roda_face_da_frente_do_cubo_sentido_horario(int matriz[2][12]);
void roda_face_da_frente_do_cubo_sentido_antihorario(int matriz[2][12]);
void roda_face_de_tras_do_cubo_sentido_horario(int matriz[2][12]);
void roda_face_de_tras_do_cubo_sentido_antihorario (int matriz[2][12]);
void roda_topo_do_cubo_sentido_horario (int matriz[2][12]);
void esqCima(int antiga[2][12]);
void cimaAntiHorario(int antiga[2][12]);
void esqCimaNovo(int m[2][12]);
void interfaceGrafica(int matriz[2][12]);
void rotacionarAntiHorario(int matriz[2][12]);
void rotacionarHorario(int matriz[2][12]);
void rotacionarCima(int matriz[2][12]);
void rotacionarBaixo(int matriz[2][12]);
void mudarFace(int matriz[][12], int nova[][12], int faceAtual, int faceNova);
void girarMatrizHorario(int matriz[][12], int faceAtual);
void girarMatrizAntiHorario(int matriz[][12], int faceAtual);
int face_montada(int matriz[][12], int face);
int funcao_avaliadora(int matriz[][12]);


void matrizResposta(int antiga[2][12])
{
    //int resposta[2][12] = {{1,2,5,6,9,10,13,14,17,18,21,22},
    //                       {3,4,7,8,11,12,15,16,19,20,23,24}};

   int resposta[2][12] = {{1,1,2,2,3,3,4,4,5,5,6,6},
                          {1,1,2,2,3,3,4,4,5,5,6,6}};

    //int resposta[2][12] = {{5,6,2,2,5,6,4,4,3,1,1,3},
    //                      {5,6,2,2,5,6,4,4,3,1,1,3}};

//int resposta[2][12] = {{5,3,2,2,1,6,4,4,3,6,1,5},
 //                          {5,3,2,2,1,6,4,4,3,6,1,5}};

    copia(resposta, antiga);
}

void imprime(int matriz[2][12])
{
    for(int i = 0; i<2; i++)
    {
        for(int j = 0; j<12; j++)
        {
            printf("%02d ", matriz[i][j]);
        }
        printf("\n");
    }

}

void copia(int orig[2][12], int dest[2][12])
{
  for(int i = 0; i < 2; i++)
  {
      for(int j = 0; j < 12; j++)
      {
          dest[i][j] = orig[i][j];
      }
  }
}

void roda_lado_direito_para_cima(int matriz[2][12])
{
    int aux1,aux2,aux3,aux4;

    aux1 = matriz[0][1];
    aux2 = matriz[1][1];
    matriz[0][1] = matriz[0][11];
    matriz[1][1] = matriz[1][11];
    aux3 = matriz[0][9];
    aux4 = matriz[1][9];
    matriz[0][9] = aux1;
    matriz[1][9] = aux2;
    aux1 = matriz[0][4];
    aux2 = matriz[1][4];
    matriz[0][4] = aux4;
    matriz[1][4] = aux3;
    matriz[0][11] = aux2;
    matriz[1][11] = aux1;
    aux1 = matriz[0][2];
    aux2 = matriz[0][3];
    aux3 = matriz[1][2];
    aux4 = matriz[1][3];
    matriz[0][2] = aux3;
    matriz[0][3] = aux1;
    matriz[1][2] = aux4;
    matriz[1][3] = aux2;

}

void roda_lado_direito_para_baixo(int matriz[2][12])
{
    int aux1,aux2,aux3,aux4;

    aux1 = matriz[0][1];
    aux2 = matriz[1][1];
    matriz[0][1] = matriz[0][9];
    matriz[1][1] = matriz[1][9];
    aux3 = matriz[0][11];
    aux4 = matriz[1][11];
    matriz[0][11] = aux1;
    matriz[1][11] = aux2;
    aux1 = matriz[0][4];
    aux2 = matriz[1][4];
    matriz[0][4] = aux4;
    matriz[1][4] = aux3;
    matriz[0][9] = aux2;
    matriz[1][9] = aux1;
    aux1 = matriz[0][3];
    aux2 = matriz[1][3];
    aux3 = matriz[0][2];
    aux4 = matriz[1][2];
    matriz[0][2] = aux1;
    matriz[0][3] = aux2;
    matriz[1][2] = aux3;
    matriz[1][3] = aux4;

}

void roda_base_do_cubo_sentido_horario(int matriz[2][12])
{
    int aux1,aux2,aux3,aux4;

    aux1 = matriz[0][10];
    aux2 = matriz[0][11];
    aux3 = matriz[1][10];
    aux4 = matriz[1][11];
    matriz[0][10] = aux2;
    matriz[0][11] = aux4;
    matriz[1][10] = aux1;
    matriz[1][11] = aux3;
    aux1 = matriz[1][0];
    aux2 = matriz[1][1];
    matriz[1][0] = matriz[1][2];
    matriz[1][1] = matriz[1][3];
    aux3 = matriz[1][6];
    aux4 = matriz[1][7];
    matriz[1][6] = aux1;
    matriz[1][7] = aux2;
    aux1 = matriz[1][4];
    aux2 = matriz[1][5];
    matriz[1][4] = aux3;
    matriz[1][5] = aux4;
    matriz[1][2] = aux1;
    matriz[1][3] = aux2;


}

void roda_base_do_cubo_sentido_antihorario(int matriz[2][12])
{
    int aux1,aux2,aux3,aux4;

    aux1 = matriz[1][0];
    aux2 = matriz[1][1];
    matriz[1][0] = matriz[1][6];
    matriz[1][1] = matriz[1][7];
    aux3 = matriz[1][2];
    aux4 = matriz[1][3];
    matriz[1][2] = aux1;
    matriz[1][3] = aux2;
    aux1 = matriz[1][4];
    aux2 = matriz[1][5];
    matriz[1][4] = aux3;
    matriz[1][5] = aux4;
    matriz[1][6] = aux1;
    matriz[1][7] = aux2;
    aux1 = matriz[0][10];
    aux2 = matriz[0][11];
    aux3 = matriz[1][10];
    aux4 = matriz[1][11];
    matriz[0][10] = aux3;
    matriz[0][11] = aux1;
    matriz[1][10] = aux4;
    matriz[1][11] = aux2;

}

void roda_face_da_frente_do_cubo_sentido_horario(int matriz[2][12])
{
    int aux1,aux2,aux3,aux4;

    aux1 = matriz[0][0];
    aux2 = matriz[0][1];
    aux3 = matriz[1][0];
    aux4 = matriz[1][1];
    matriz[0][0] = aux3;
    matriz[0][1] = aux1;
    matriz[1][0] = aux4;
    matriz[1][1] = aux2;
    aux1 = matriz[0][2];
    aux2 = matriz[1][2];
    matriz[0][2] = matriz[1][8];
    matriz[1][2] = matriz[1][9];
    aux3 = matriz[0][10];
    aux4 = matriz[0][11];
    matriz[0][10] = aux2;
    matriz[0][11] = aux1;
    aux1 = matriz[0][7];
    aux2 = matriz[1][7];
    matriz[0][7] = aux3;
    matriz[1][7] = aux4;
    matriz[1][8] = aux2;
    matriz[1][9] = aux1;

}

void roda_face_da_frente_do_cubo_sentido_antihorario(int matriz[2][12])
{
    int aux1,aux2,aux3,aux4;

    aux1 = matriz[0][0];
    aux2 = matriz[0][1];
    aux3 = matriz[1][0];
    aux4 = matriz[1][1];
    matriz[0][0] = aux2;
    matriz[0][1] = aux4;
    matriz[1][0] = aux1;
    matriz[1][1] = aux3;
    aux1 = matriz[0][2];
    aux2 = matriz[1][2];
    matriz[0][2] = matriz[0][11];
    matriz[1][2] = matriz[0][10];
    aux3 = matriz[1][8];
    aux4 = matriz[1][9];
    matriz[1][8] = aux1;
    matriz[1][9] = aux2;
    aux1 = matriz[0][7];
    aux2 = matriz[1][7];
    matriz[0][7] = aux4;
    matriz[1][7] = aux3;
    matriz[0][10] = aux1;
    matriz[0][11] = aux2;

}

void roda_face_de_tras_do_cubo_sentido_horario(int matriz[2][12])
{
    int aux1,aux2,aux3,aux4;

    aux1 = matriz[0][4];
    aux2 = matriz[0][5];
    aux3 = matriz[1][4];
    aux4 = matriz[1][5];
    matriz[0][4] = aux2;
    matriz[0][5] = aux4;
    matriz[1][4] = aux1;
    matriz[1][5] = aux3;
    aux1 = matriz[0][3];
    aux2 = matriz[1][3];
    matriz[0][3] = matriz[0][8];
    matriz[1][3] = matriz[0][9];
    aux3 = matriz[1][10];
    aux4 = matriz[1][11];
    matriz[1][10] = aux2;
    matriz[1][11] = aux1;
    aux1 = matriz[0][6];
    aux2 = matriz[1][6];
    matriz[0][6] = aux3;
    matriz[1][6] = aux4;
    matriz[0][8] = aux2;
    matriz[0][9] = aux1;

}
void roda_face_de_tras_do_cubo_sentido_antihorario (int matriz[2][12])
{
    int aux1,aux2,aux3,aux4;

    aux1 = matriz[0][4];
    aux2 = matriz[0][5];
    aux3 = matriz[1][4];
    aux4 = matriz[1][5];
    matriz[0][4] = aux3;
    matriz[0][5] = aux1;
    matriz[1][4] = aux4;
    matriz[1][5] = aux2;
    aux1 = matriz[1][10];
    aux2 = matriz[1][11];
    matriz[1][10] = matriz[0][6];
    matriz[1][11] = matriz[1][6];
    aux3 = matriz[0][3];
    aux4 = matriz[1][3];
    matriz[0][3] = aux2;
    matriz[1][3] = aux1;
    aux1 = matriz[0][8];
    aux2 = matriz[0][9];
    matriz[0][8] = aux3;
    matriz[0][9] = aux4;
    matriz[0][6] = aux2;
    matriz[1][6] = aux1;

}

void roda_topo_do_cubo_sentido_horario (int matriz[2][12])
{
    int aux1,aux2,aux3,aux4;

    aux1 = matriz[0][8];
    aux2 = matriz[0][9];
    aux3 = matriz[1][8];
    aux4 = matriz[1][9];
    matriz[0][8] = aux3;
    matriz[0][9] = aux1;
    matriz[1][8] = aux4;
    matriz[1][9] = aux2;
    aux1 = matriz[0][0];
    aux2 = matriz[0][1];
    matriz[0][0] = matriz[0][2];
    matriz[0][1] = matriz[0][3];
    aux3 = matriz[0][6];
    aux4 = matriz[0][7];
    matriz[0][6] = aux1;
    matriz[0][7] = aux2;
    aux1 = matriz[0][4];
    aux2 = matriz[0][5];
    matriz[0][4] = aux3;
    matriz[0][5] = aux4;
    matriz[0][2] = aux1;
    matriz[0][3] = aux2;

}
 // jeito diferente de implementar, acho q vou tirar dps
void esqCima(int antiga[2][12])
{
    int nova[2][12];
    copia(antiga, nova);

    nova[0][0] = antiga[0][10];
    nova[1][0] = antiga[1][10];

    nova[0][5] = antiga[1][8];
    nova[1][5] = antiga[0][8];

    nova[0][6] = antiga[0][7];
    nova[0][7] = antiga[1][7];

    nova[1][6] = antiga[0][6];
    nova[1][7] = antiga[1][6];

    nova[0][8] = antiga[0][0];
    nova[1][8] = antiga[1][0];

    nova[0][10] = antiga[1][5];
    nova[1][10] = antiga[0][5];

    copia(nova, antiga);
}

void esqBaixo(int antiga[2][12])
{
    int aux1, aux2, aux3, aux4;

    aux1 = antiga[0][0];
    aux2 = antiga[1][0];
    antiga[0][0] = antiga[0][8];
    antiga[1][0] = antiga[1][8];
    aux3 = antiga[0][10];
    aux4 = antiga[1][10];
    antiga[0][10] = aux1;
    antiga[1][10] = aux2;

    aux1 = antiga[0][5];
    aux2 = antiga[1][5];
    antiga[0][5] = aux4;
    antiga[1][5] = aux3;

    antiga[0][8] = aux2;
    antiga[1][8] = aux1;

    girarMatrizHorario(antiga,6);

}

void cimaAntiHorario(int antiga[2][12])
{
    int nova[2][12];
    copia(antiga, nova);

    nova[0][0] = antiga[0][6];
    nova[0][1] = antiga[0][7];

    nova[0][2] = antiga[0][0];
    nova[0][3] = antiga[0][1];

    nova[0][4] = antiga[0][2];
    nova[0][5] = antiga[0][3];

    nova[0][6] = antiga[0][4];
    nova[0][7] = antiga[0][5];

    nova[0][8] = antiga[0][9];
    nova[0][9] = antiga[1][9];

    nova[1][8] = antiga[0][8];
    nova[1][9] = antiga[1][8];

    copia(nova, antiga);
}

// movimento c base no jeito que o movimento oda_lado_direito_para_baixo foi implementado
void esqCimaNovo(int m[2][12])
{
    int aux1, aux2, aux3, aux4;

    aux1 = m[0][0];
    aux2 = m[1][0];
    m[0][0] = m[0][10];
    m[1][0] = m[1][10];
    aux3 = m[0][8];
    aux4 = m[1][8];
    m[0][8] = aux1;
    m[1][8] = aux2;
    aux1 = m[0][5];
    aux2 = m[1][5];
    m[0][5] = aux4;
    m[1][5] = aux3;
    m[0][10] = aux2;
    m[1][10] = aux1;
    aux1 = m[0][6];
    aux2 = m[0][7];
    aux3 = m[1][6];
    aux4 = m[1][7];
    m[0][6] = aux2;
    m[0][7] = aux4;
    m[1][6] = aux1;
    m[1][7] = aux3;
}

// Funcao que imprime o cubo para o jogador
void interfaceGrafica(int matriz[2][12])
{
    printf("                        +---------+ \n"
           "                       / %02d   %02d / |\n"
           "                      /         /%02d|\n"
           "                     / %02d   %02d /   |\n"
           "                    +---------+ %02d |\n"
           "                    | %02d   %02d |  %02d|\n"
           "                    |         |   /\n"
           "                    | %02d   %02d |%02d/\n"
           "                    +---------+ /\n",
           matriz[0][8], matriz[0][9],
           matriz[0][3], matriz[1][8],
           matriz[1][9], matriz[0][2],
           matriz[0][0], matriz[0][1],
           matriz[1][3], matriz[1][0],
           matriz[1][1], matriz[1][2]);
}

void rotacionarAntiHorario(int matriz[2][12])
{
    int nova[2][12];
    copia(matriz, nova);

    for(int i=0; i<6; i=i+2)
    {
        mudarFace(matriz,nova,i,2); // "shift-left"
    }

    mudarFace(matriz,nova,6,-6);
    copia(nova, matriz);

    girarMatrizAntiHorario(matriz, 8); // Face de cima
    girarMatrizHorario(matriz, 10); // Face de baixo

}

void rotacionarHorario(int matriz[2][12])
{
    int nova[2][12];
    copia(matriz, nova);

    mudarFace(matriz, nova, 2, -2);
    mudarFace(matriz, nova, 4, -2);
    mudarFace(matriz, nova, 6, -2);
    mudarFace(matriz, nova, 0, 6);

    girarMatrizHorario(nova, 8);
    girarMatrizAntiHorario(nova, 10);

    copia(nova, matriz);
}

void rotacionarCima(int matriz[2][12])
{
    int nova[2][12];
    copia(matriz, nova);

    mudarFace(matriz, nova, 10, -10);

    girarMatrizHorario(nova, 2);

    girarMatrizAntiHorario(matriz, 8);
    girarMatrizAntiHorario(matriz, 8);
    mudarFace(matriz, nova, 8, -4);

    girarMatrizAntiHorario(nova, 6);

    mudarFace(matriz, nova, 0, 8);

    girarMatrizHorario(matriz, 4);
    girarMatrizHorario(matriz, 4);
    mudarFace(matriz, nova, 4, 6);

    copia(nova, matriz);
}

void rotacionarBaixo(int matriz[2][12])
{
    int nova[2][12];
    copia(matriz, nova);

    mudarFace(matriz, nova,8, -8);

    girarMatrizAntiHorario(nova, 2);

    girarMatrizAntiHorario(matriz, 10);
    girarMatrizAntiHorario(matriz, 10);
    mudarFace(matriz, nova, 10, -6);

    girarMatrizHorario(nova, 6);

    girarMatrizHorario(matriz, 4);
    girarMatrizHorario(matriz, 4);
    mudarFace(matriz, nova, 4, 4);

    mudarFace(matriz, nova, 0, 10);

    copia(nova, matriz);
}

void rotacionarEixoY_SentidoHorario(int matriz[][12])
{
    int nova[2][12];
    copia(matriz, nova);

    girarMatrizHorario(nova, 0);

    girarMatrizHorario(matriz, 8);
    mudarFace(matriz, nova, 8, -6);

    girarMatrizAntiHorario(nova, 4);

    girarMatrizHorario(matriz, 10);
    mudarFace(matriz, nova, 10, -4);

    girarMatrizHorario(matriz, 6);
    mudarFace(matriz, nova, 6, 2);

    girarMatrizHorario(matriz, 2);
    mudarFace(matriz, nova, 2, 8);

    copia(nova, matriz);
}

void rotacionarEixoY_SentidoAntiHorario(int matriz[][12])
{
    int nova[2][12];
    copia(matriz, nova);

    girarMatrizAntiHorario(nova, 0);

    girarMatrizAntiHorario(matriz, 10);
    mudarFace(matriz, nova, 10, -8);

    girarMatrizHorario(nova, 4);

    girarMatrizAntiHorario(matriz, 8);
    mudarFace(matriz, nova, 8, -2);

    girarMatrizAntiHorario(matriz, 2);
    mudarFace(matriz, nova, 2, 6);

    girarMatrizAntiHorario(matriz, 6);
    mudarFace(matriz, nova, 6, 4);

    copia(nova, matriz);

}

void mudarFace(int matriz[][12], int nova[][12], int faceAtual, int faceNova)
{
    for(int i=0; i<2; i++)
    {
        for(int j=faceAtual; j<faceAtual+2; j++)
        {
            nova[i][j+faceNova] = matriz[i][j];
        }
    }
}

void girarMatrizAntiHorario(int matriz[][12], int faceAtual)
{
    int aux = matriz[0][faceAtual];
    matriz[0][faceAtual] = matriz[0][faceAtual+1];
    matriz[0][faceAtual+1] = matriz[1][faceAtual+1];
    matriz[1][faceAtual+1] = matriz[1][faceAtual];
    matriz[1][faceAtual] = aux;
}

void girarMatrizHorario(int matriz[][12], int faceAtual) // ver dps
{
    int aux = matriz[0][faceAtual];
    matriz[0][faceAtual] = matriz[1][faceAtual];
    matriz[1][faceAtual] = matriz[1][faceAtual + 1];
    matriz[1][faceAtual + 1] = matriz[0][faceAtual + 1];
    matriz[0][faceAtual + 1] = aux;
}

int face_montada(int matriz[][12], int face)
{
    if(matriz[0][face] != matriz[0][face+1])
        return 0;
    if(matriz[0][face+1] != matriz[1][face+1])
        return 0;
    if(matriz[1][face+1] != matriz[1][face])
        return 0;

    return 1;
}

int funcao_avaliadora(int matriz[][12])
{
    for(int i=0; i<10; i+=2)
    {
        // ja retorna caso ache uma face que nao esteja montada
        if(!face_montada(matriz,i))
            return 0;
    }

    return 1; // cubo montado
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
            roda_topo_do_cubo_sentido_horario(matriz);
            break;
        }

        case 7:
        {
            roda_base_do_cubo_sentido_antihorario(matriz);
            break;
        }

        // esses seriam só para o modo do jogador
        case 8:
        {
            roda_base_do_cubo_sentido_horario(matriz);
            break;
        }

        case 9:
        {
            roda_face_da_frente_do_cubo_sentido_horario(matriz);
            break;
        }

        case 10:
        {
            roda_face_da_frente_do_cubo_sentido_antihorario(matriz);
            break;
        }

        case 11:
        {
            roda_face_de_tras_do_cubo_sentido_horario(matriz);
            break;
        }

        case 12:
        {
            roda_face_de_tras_do_cubo_sentido_antihorario(matriz);
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
            rotacionarEixoY_SentidoAntiHorario(matriz);
            break;
        }

        case 18:
        {
            rotacionarEixoY_SentidoHorario(matriz);
            break;
        }

        case 19:
        {
            break;
        }

        case 0:
        {
            break;
        }
    }
}

#endif // FUNCOES_CUBO_MAGICO_H_INCLUDED
