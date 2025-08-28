#include <stdio.h>
#include <stdlib.h>

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


int main() {

    int cubo_magico[2][12];

    int matriz_resposta[2][12];

    int i,j;

// construindo a matriz resposta

    matriz_resposta[0][0] = 1;
    matriz_resposta[0][1] = 2;
    matriz_resposta[0][2] = 5;
    matriz_resposta[0][3] = 6;
    matriz_resposta[0][4] = 9;
    matriz_resposta[0][5] = 10;
    matriz_resposta[0][6] = 13;
    matriz_resposta[0][7] = 14;
    matriz_resposta[0][8] = 17;
    matriz_resposta[0][9] = 18;
    matriz_resposta[0][10] = 21;
    matriz_resposta[0][11] = 22;
    matriz_resposta[1][0] = 3;
    matriz_resposta[1][1] = 4;
    matriz_resposta[1][2] = 7;
    matriz_resposta[1][3] = 8;
    matriz_resposta[1][4] = 11;
    matriz_resposta[1][5] = 12;
    matriz_resposta[1][6] = 15;
    matriz_resposta[1][7] = 16;
    matriz_resposta[1][8] = 19;
    matriz_resposta[1][9] = 20;
    matriz_resposta[1][10] = 23;
    matriz_resposta[1][11] = 24;

// copiando a matriz resposta no cubo magico, para testes

    for( i=0 ; i<2 ; i+=1 )
    {
        for( j=0 ; j<12 ; j+=1 )
        {
           cubo_magico[i][j] = matriz_resposta[i][j];
        }
    }


// imprimindo matriz resposta
    printf("Matriz resposta: \n");

    for( i=0 ; i<2 ; i+=1 )
    {
        for( j=0 ; j<12 ; j+=1 )
        {
            printf(" %d ",matriz_resposta[i][j]);
        }
    printf("\n");
    }
    printf("\n");




// roda_lado_direito_para_baixo(cubo_magico);


// imprimindo cubo magico

    printf("Cubo magico: \n");

    for( i=0 ; i<2 ; i+=1 )
    {
        for( j=0 ; j<12 ; j+=1 )
        {
            printf(" %d ",cubo_magico[i][j]);
        }
    printf("\n");
    }

    roda_lado_direito_para_cima(cubo_magico);

    return 0;
}


