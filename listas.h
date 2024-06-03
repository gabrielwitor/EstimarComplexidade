//
// Created by GabrielAlmeida on 03/06/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct lista Lista;

struct lista{
    int data;
    Lista* prox;
};

Lista* cria_lista(void){
    return NULL;
}

Lista* cria_noLista(Lista* lst, int data){
    Lista* novo = (Lista*) malloc (sizeof(Lista));
    novo->data = data;
    novo->prox = lst;
    return novo;
}

Lista* insere_ordenado(Lista* lst){
    Lista* ordenada = cria_lista();
    for(Lista* aux = lst; aux != NULL; aux = aux -> prox){
        int maior = INT_MIN;
        for(Lista* aux2 = aux; aux2 != NULL; aux2 = aux2 -> prox){
            if(maior < aux2->data){
                maior = aux2->data;
            }
        }
        ordenada = cria_noLista(ordenada,maior);
    }
    return ordenada;
}

void imprime_lista(Lista* lst){
    for(Lista* aux = lst; aux != NULL; aux = aux -> prox){
        printf("Info: %d\n",aux->data);
    }
}

Lista* libera_lista(Lista* lst){
    Lista* aux = lst;
    Lista* lib;

    while(aux != NULL){
        lib = aux;
        aux = aux -> prox;
        free(lib);
    }

    return aux;
}

void verifica_vazia(Lista* lst){
    if (lst == NULL){
        printf("Vazia!\n");
    } else {
        printf("Nao vazia.\n");
    }
}