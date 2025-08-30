#ifndef QUEUEPACKAGE_H_INCLUDED
#define QUEUEPACKAGE_H_INCLUDED
#include <stdlib.h>
#include "funcoes cubo magico.h"
#define NUM 10000
//Estrutura dos elementos da pilha
typedef struct no
{
    int movimentos[NUM];
    int ultimaPos;
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

void InsereFila(FILA* f, int indice, int movimento, int vetorMovimentos[NUM])
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

    printf("Movimento colocado = %d\n", novo->movimentos[indice]);
    novo->ultimaPos = indice;
    printf("indice = %d\n", novo->ultimaPos);
    novo->prox = NULL;

    if (!(f->INICIO == NULL))
        f->FIM->prox = novo;
    f->FIM = novo;

    if (f->INICIO == NULL)
        f->INICIO = f->FIM;
}

void funcaoSucessora(FILA* f, int indice, int movimentoDoPai, int vetorMovimentos[NUM])
{

    for(int i = 1; i<13; i++)
    {
        if(movimentoDoPai%2 == 0)
        {
            // garantindo que nao eh o mov contrario
            if(i != movimentoDoPai-1)
            {
                InsereFila(f, indice, i, vetorMovimentos);
            }
        }

        else
        {
            // garantindo que nao eh o mov contrario
            if(i != movimentoDoPai + 1)
            {
                InsereFila(f, indice, i, vetorMovimentos);
            }
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

void arrumaCubo(int cubo[][12], NO* primeiroDaLista)
{
    int indice = primeiroDaLista->ultimaPos;
    int movimento = primeiroDaLista->movimentos[indice];
    int movimentoAnterior;

    // se nao tiver montado, preciso voltar o cubo para como estava antes
    if(movimento != 0)
    {
        movimentoAnterior = primeiroDaLista->movimentos[indice - 1];

        if(movimento%2 == 0)
            realiza_mov(movimento - 1, cubo);

        else
            realiza_mov(movimento + 1, cubo);

        // vendo se preciso voltar mais uma vez
        if(movimentoAnterior != primeiroDaLista->prox->movimentos[indice - 1])
        {
            if(movimentoAnterior%2 == 0)
                realiza_mov(movimentoAnterior - 1, cubo);

            else
                realiza_mov(movimentoAnterior + 1, cubo);
        }
    }
}


int encontraPosicao(NO* primeiroDaLista)
{
    int indice = primeiroDaLista->ultimaPos;
    int movimentoAnterior;

    if(primeiroDaLista->movimentos[indice] != 0)
    {
        movimentoAnterior = primeiroDaLista->movimentos[indice - 1];

        // vendo se preciso voltar mais uma vez
        if(movimentoAnterior == primeiroDaLista->prox->movimentos[indice - 1])
        {
            return indice;
        }
        return indice+1;
    }

    return 0;

}

int vetor(FILA *f, int vetorMovimentos[NUM], int ultimaPosicao)
{
    NO* cubo = f->INICIO;
    ultimaPosicao = cubo->ultimaPos;

    for(int i = 0; i<ultimaPosicao+1; i++)
    {
        vetorMovimentos[i] = cubo->movimentos[i];
    }

    return ultimaPosicao;
}

int CuboMontado(FILA *f, int vetorMovimentos[NUM])
{
    int ultimaPosicao = vetor(f, vetorMovimentos, ultimaPosicao);
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
