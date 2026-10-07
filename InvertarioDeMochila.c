#include <stdio.h>
#include <stdlib.h>
#define TAM 100;

typedef struct Item{
    int valor;
    char nome;
    struct Item* proximo;
    struct Item* anterior;
} Item;

void inserirInicio(Item** cabeca, int valor){

    Item* novo = (Item*) malloc(sizeof(Item));
    novo->valor = valor;
    novo->proximo = *cabeca;
    novo->anterior = NULL;

    if(*cabeca!= NULL){
        (*cabeca)->anterior = novo;
    }
    *cabeca = novo;
}

void imprimir(Item* cabeca){
    Item* atual = cabeca;
    while (atual != NULL){
        printf("%d <-> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

int main(){
    Item* mochila = NULL;
    inserirInicio(&mochila, 30);
    inserirInicio(&mochila, 20);

    imprimir(mochila);
    return 0;

}
