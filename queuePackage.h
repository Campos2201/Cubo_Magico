#ifndef QUEUEPACKAGE_H_INCLUDED
#define QUEUEPACKAGE_H_INCLUDED
#include <stdlib.h>
#include "funcoes cubo magico.h"
#include "filaVisitados.h"
#define NUM 42

int num = 0;
//Estrutura dos elementos da fila
typedef struct no
{
    int movimentos[NUM];
    int ultimaPos;
    ESTADO *estadoNo;
    int num;
    struct no *prox;  //aponta para o próx elemento
} NO;

typedef struct Fila
{
    NO *INICIO;
    NO *FIM;
} FILA;

FILA* LimpaFila(FILA* f);

FILA* CriaFila()
{
    FILA *f;
    f = (FILA*) malloc(sizeof(FILA));
    f -> INICIO = NULL;
    f -> FIM = NULL;
    return f;
}

void InsereFila(FILA* f, int indice, int movimento, int vetorMovimentos[NUM], ESTADO* estado)
{
    NO* novo;
    novo = (NO*) malloc(sizeof(NO));

    if(indice>0)
    {
        for(int i = 0; i<indice; i++)
        {
            novo->movimentos[i] = vetorMovimentos[i];
        }
    }

    novo->movimentos[indice] = movimento;
    novo->estadoNo = estado;
    novo->num = num++;

   // printf("Movimento colocado = %d\n", novo->movimentos[indice]);
    novo->ultimaPos = indice;
    printf("indice = %d\n", novo->ultimaPos);
    novo->prox = NULL;

    if (!(f->INICIO == NULL))
        f->FIM->prox = novo;
    f->FIM = novo;

    if (f->INICIO == NULL)
        f->INICIO = f->FIM;
}

void funcaoSucessora(FILA* f, int indice, int movimentoDoPai, int vetorMovimentos[NUM], VISITADOS* v, int cubo_visitado[][12])
{
    int movimentoDoVo;
    int matriz[2][12];
    int podeInserir;

    int matrizAtual[2][12];

    if(indice>2)
    {
        movimentoDoVo = f->INICIO->prox->movimentos[indice-2];
    }

    for(int i = 1; i<13; i++)
    {
        copia(cubo_visitado, matriz);

        realiza_mov(i, matriz);
        //InsereFila(f, indice, i, vetorMovimentos, InsereVisitados(v, matriz));
        //printf("movimento inserido = %d\n", f->FIM->movimentos[indice]);

        podeInserir = 1;

        if(!buscaVisitados(v, matriz))
        {

            if(indice>2)
            {
                if(movimentoDoVo == movimentoDoPai && movimentoDoPai == i)
                {
                    podeInserir = 0;
                }
            }

            if(movimentoDoPai%2 == 0)
            {
                // garantindo que nao eh o mov contrario
                if(i == movimentoDoPai-1)
                    podeInserir = 0;

            }

            else
            {
                // garantindo que nao eh o mov contrario
                if(i == movimentoDoPai + 1)
                    podeInserir = 0;
            }

            // Garantindo que nao vai fazer mov esqCima e dirCima em seguida por exemplo
            if(movimentoDoPai%4 == 0 || movimentoDoPai%4 == 3)
            {
                if(i == movimentoDoPai - 2)
                    podeInserir = 0;
            }

            else
            {
                if(i == movimentoDoPai + 2)
                    podeInserir = 0;
            }

            if(podeInserir)
                InsereFila(f, indice, i, vetorMovimentos, InsereVisitados(v, matriz));
        }
    }

}

int visitaEstado(FILA* f, int cubo[][12])
{
    // visitando o primeiro da fila
    int ultimaPos = f->INICIO->ultimaPos;
    int movimento = f->INICIO->movimentos[ultimaPos];

    // montando o cubo desse estado
    realiza_mov(movimento, cubo);

    // checando se está montado
    if(funcao_avaliadora(cubo))
        return 1;
    return 0;
}

void arrumaCubo(int cubo_inicial[][12], int cubo[][12], NO* primeiroDaLista)
{
    int indice = primeiroDaLista->prox->ultimaPos;
    NO* prox = primeiroDaLista->prox;

    int aux[2][12];
    if(indice!=0)
    {
        copia(cubo_inicial, aux);

        for(int i=1; i<indice; i++)
        {
            realiza_mov(prox->movimentos[i], aux);
        }

        copia(aux, cubo);
    }


    // se nao tiver montado, preciso voltar o cubo para como estava antes
    /*if(movimento != 0)
    {
        if(movimento%2 == 0)
            realiza_mov(movimento - 1, cubo);

        else
            realiza_mov(movimento + 1, cubo);

        // vendo se preciso voltar mais uma vez
        if(indice < primeiroDaLista->prox->ultimaPos)
        {
            realiza_mov(primeiroDaLista->prox->movimentos[indice], cubo);
        }

        else if(indice > 1)
        {
            if(movimentoAnterior != primeiroDaLista->prox->movimentos[indice - 1])
            {
                if(movimentoAnterior%2 == 0)
                    realiza_mov(movimentoAnterior - 1, cubo);

                else
                    realiza_mov(movimentoAnterior + 1, cubo);

                realiza_mov(primeiroDaLista->prox->movimentos[indice - 1], cubo);
            }
        }
    }*/
}

int encontraPosicao(NO* primeiroDaLista)
{
    int indice = primeiroDaLista->ultimaPos;
    int movimentoAnterior;

    if(primeiroDaLista->movimentos[indice] != 0)
    {
        movimentoAnterior = primeiroDaLista->movimentos[indice - 1];

        // vendo se preciso voltar mais uma vez
        if(indice < primeiroDaLista->prox->ultimaPos)
        {
            return indice+1;
        }
        return indice;
    }

    return 1;

}

int vetor(FILA *f, int vetorMovimentos[NUM])
{
    NO* cubo = f->INICIO;
    int ultimaPosicao = cubo->ultimaPos;

    for(int i = 0; i<ultimaPosicao+1; i++)
    {
        vetorMovimentos[i] = cubo->movimentos[i];
    }

    return ultimaPosicao;
}

int CuboMontado(FILA *f, int vetorMovimentos[NUM])
{
    int ultimaPosicao = vetor(f, vetorMovimentos);
    f = LimpaFila(f);
    return ultimaPosicao;
}

void RemoveFila(FILA* f)
{
    int num;
    NO* aux = f -> INICIO;

    if (f -> INICIO == NULL)
    {
        printf("Fila vazia...");
        exit(1);
    }

    aux = aux -> prox;
    free(f->INICIO);
    f->INICIO = aux;

    if (aux == NULL)
    {
        f->FIM = NULL;
    }
}

void ImprimeFila(FILA* f)
{
    NO* aux;

    if (!(f -> INICIO))
        printf("Fila vazia!!");

    else
    {
        aux = f -> INICIO;

        while (aux)
        {
            //printf("%d ", aux -> valor);
            aux = aux -> prox;
        }
    }
}

FILA* LimpaFila(FILA* f)
{
    NO* recebida = f->INICIO;
    NO* aux = recebida;

    while (recebida)
    {
        aux = aux->prox;
        free(recebida);
        recebida = aux;
    }

    free(f);
    return NULL;
}


#endif // QUEUEPACKAGE_H_INCLUDED
