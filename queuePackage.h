#ifndef QUEUEPACKAGE_H_INCLUDED
#define QUEUEPACKAGE_H_INCLUDED
#include <stdlib.h>

//Estrutura dos elementos da pilha
typedef struct no
{
    int movimentos[50];
    int ultimaPos;
    struct no *prox;  //aponta para o próx elemento
} NO;

typedef struct Fila
{
    NO *INICIO;
    NO *FIM;
} FILA;

FILA* CriaFila()
{
    FILA *f;
    f = (FILA*) malloc(sizeof(FILA));
    f -> INICIO = NULL;
    f -> FIM = NULL;
    return f;
}

void funcaoSucessora(FILA* f, int indice, int movimentoDoPai)
{

    for(int i = 1; i<13; i++)
    {
        if(movimentoDoPai%2 == 0)
        {
            // garantindo que nao eh o mov contrario
            if(i != movimentoDoPai-1)
            {
                InsereFila(f, indice, i);
            }
        }

        else
        {
            // garantindo que nao eh o mov contrario
            if(i != movimentoDoPai + 1)
            {
                InsereFila(f, indice, i);
            }
        }
    }

}

void InsereFila(FILA* f, int indice, int movimento)
{
    NO* novo;
    novo = (NO*) malloc(sizeof(NO));
    novo->movimentos[indice] = movimento;
    novo->ultimaPos = indice;
    novo->prox = NULL;

    if (!(f->INICIO == NULL))
        f->FIM->prox = novo;
    f->FIM = novo;

    if (f->INICIO == NULL)
        f->INICIO = f->FIM;
}


int visitaEstado(FILA* f, int cubo[][12])
{
    // visitando o primeiro da fila
    int ultimaPos = f->INICIO->ultimaPos;
    int movimento = f->INICIO->movimentos[ultimaPos];

    // montando o cubo desse estado
    realiza_mov(cubo, movimento);

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
            realiza_mov(cubo, movimento - 1);

        else
            realiza_movimento(cubo, movimento + 1);

        // vendo se preciso voltar mais uma vez
        if(movimentoAnterior == primeiroDaLista->prox->movimentos[indice - 1])
        {
            if(movimento%2 == 0)
                realiza_mov(cubo, movimentoAnterior - 1);

            else
                realiza_movimento(cubo, movimentoAnterior + 1);
        }
    }
}


void CuboMontado(FILA *f, int vetorMovimentos[50], int ultimaPosicao)
{
    NO* cubo = f->INICIO;
    int *vetMovimentosCubo[50] = cubo->movimentos;
    ultimaPosicao = f->INICIO->ultimaPos;

    for(int i = 0; i<ultimaPosicao+1; i++)
    {
        vetorMovimentos[i] = vetMovimentosCubo[i];
    }

    LimpaFila(f);
}

int RemoveFila(FILA* f)
{
    int num;
    NO* aux = f -> INICIO;

    if (f -> INICIO == NULL)
    {
        printf("Fila vazia...");
        exit(1);
    }

    num = f -> INICIO -> valor;
    aux = aux -> prox;
    free(f -> INICIO);
    f -> INICIO = aux;

    if (aux == NULL)
    {
        f -> FIM = NULL;
    }

    return num;
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
            printf("%d ", aux -> valor);
            aux = aux -> prox;
        }
    }
}

FILA* LimpaFila(FILA* f)
{
    NO* recebida = f -> INICIO;
    NO* aux = recebida;

    while (recebida)
    {
        aux = aux -> prox;
        free(recebida);
        recebida = aux;
    }

    free(f);
    return NULL;
}

#endif // QUEUEPACKAGE_H_INCLUDED
