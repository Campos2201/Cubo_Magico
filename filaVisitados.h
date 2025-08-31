#ifndef FILAVISITADOS_H_INCLUDED
#define FILAVISITADOS_H_INCLUDED
#include "funcoes cubo magico.h"
#include "queuePackage.h"

//Estrutura dos elementos da fila
typedef struct estado
{
    int matriz[2][12];
    struct estado *prox;  //aponta para o próx elemento
} ESTADO;

typedef struct Visitados
{
    ESTADO *INICIO;
    ESTADO *FIM;
} VISITADOS;

VISITADOS* CriaVisitados()
{
    VISITADOS *v;
    v = (VISITADOS*) malloc(sizeof(VISITADOS));
    v -> INICIO = NULL;
    v -> FIM = NULL;
    return v;
}

int comparaMatriz(int m1[][12], int m2[][12]);

ESTADO* InsereVisitados(VISITADOS* v, int matriz[][12])
{
    ESTADO* novo;
    novo = (ESTADO*) malloc(sizeof(ESTADO));

    copia(matriz, novo->matriz);

    novo->prox = NULL;

    if (!(v->INICIO == NULL))
        v->FIM->prox = novo;
    v->FIM = novo;

    if (v->INICIO == NULL)
        v->INICIO = v->FIM;

    return novo;
}

void RemoveVisitados(VISITADOS* v)
{
    ESTADO* aux = v -> INICIO;

    if (v -> INICIO == NULL)
    {
        printf("Fila vazia...");
        exit(1);
    }

    aux = aux -> prox;
    free(v->INICIO);
    v->INICIO = aux;

    if (aux == NULL)
    {
        v->FIM = NULL;
    }
}

void ImprimeVisitados(VISITADOS* v)
{
    ESTADO* aux;

    if (!(v -> INICIO))
        printf("Fila vazia!!");

    else
    {
        aux = v -> INICIO;

        while (aux)
        {
            //printf("%d ", aux -> valor);
            aux = aux -> prox;
        }
    }
}

VISITADOS* LimpaVisitados(VISITADOS* v)
{
    ESTADO* recebida = v->INICIO;
    ESTADO* aux = recebida;

    while (recebida)
    {
        aux = aux->prox;
        free(recebida);
        recebida = aux;
    }

    free(v);
    return NULL;
}

int comparaRotacoesMatriz(int nova[][12], int visitada[][12])
{
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            rotacionarCima(nova);
            if(comparaMatriz(nova, visitada))
                return 1;
        }
        rotacionarCima(nova);
        rotacionarHorario(nova);
    }

    rotacionarHorario(nova);

    return 0;
}

int comparaMatriz(int m1[][12], int m2[][12])
{
    for(int i = 0; i<2; i++)
    {
        for(int j = 0; j<10; j++)
        {
            if(m1[i][j] != m2[i][j])
                return 0;
        }
    }

    return 1;
}

int buscaVisitados(VISITADOS* v, int matriz[][12])
{
    ESTADO* aux;

    if (!(v->INICIO))
        printf("Fila vazia!!");

    else
    {
        aux = v -> INICIO;

        while (aux)
        {
            if(comparaMatriz(aux->matriz, matriz))
                return 1;
            aux = aux -> prox;
        }
    }
    return 0;
}

#endif // FILAVISITADOS_H_INCLUDED
