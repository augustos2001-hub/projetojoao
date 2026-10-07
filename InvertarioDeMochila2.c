#include <stdio.h>
#include <stdlib.h>

typedef struct Item{
    int peso;
    char nomeItem[50];
    struct Item* proximo;
    struct Item* anterior;
} Item;

typedef struct Mochila{
    int pesoMax;
    int pesoAtual;
    Item* inicio;
    Item* fim;
} Mochila;

void criarItem(Item** cabeca){
    Item* novo = (Item*) malloc(sizeof(Item));

    //printf("Digite o nome do item: ");
    //scanf("%49s", novo->nomeItem);
    printf("Digite o peso do item: ");
    scanf("%d", &novo->peso);

    novo->proximo = NULL;
    novo->anterior = NULL;

    if(*cabeca == NULL){
            printf("Teste");
        *cabeca = novo;
        return;
    }

    if(novo->peso <= (*cabeca)->peso){
        novo->proximo = *cabeca;
        (*cabeca)->anterior= novo;
        *cabeca = novo;
        return;
    }

    Item* atual = *cabeca;
    while(novo->peso > atual->peso && atual->proximo != NULL){
        atual = atual->proximo;
    }


    if(novo->peso > atual->peso){
        atual->proximo = novo;
        novo->anterior = atual;
        return;
    }
    novo->anterior = atual->anterior;
    novo->proximo = atual;
    atual->anterior->proximo = novo;
    atual->anterior = novo;

    printf("\n%d\n", atual->peso);
    return;
}

void listarItem(Item* cabeca){
    Item* atual = cabeca;
    while (atual != NULL){
        printf("%s: %d <-> ", atual->nomeItem, atual->peso);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

void main(){
    Item* Item;
    Mochila mochila;
    mochila.pesoMax = 100;
    mochila.pesoAtual = 0;
    mochila.inicio = NULL;
    mochila.fim = NULL;

    criarItem(&Item);
    criarItem(&Item);
    criarItem(&Item);
    criarItem(&Item);
    criarItem(&Item);
    listarItem(Item);
    criarItem(&Item);
    listarItem(Item);
}
