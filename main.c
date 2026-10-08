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
int calculaPeso(Mochila mAtual) {
    int pesoAtual = 0;
    Item* itemCheck = mAtual.inicio;
    while (itemCheck != NULL){
        pesoAtual += itemCheck->peso;
        itemCheck = itemCheck->proximo;
    }
    return pesoAtual;
}
int verificaEspaco(Item* novo, Mochila* mAtual) {
    int pesoAtual = 0;
    pesoAtual = calculaPeso(*mAtual);
    mAtual->pesoAtual = pesoAtual;
    if (mAtual->pesoMax >= (pesoAtual + novo->peso)) {

      return 0;
    } else {
        printf("Peso %d/%d \n", pesoAtual, mAtual->pesoMax);
        return 1;
    }

}

void criarItem(Item** cabeca, Mochila* mAtual){
    Item* novo = (Item*) malloc(sizeof(Item));

    printf("Digite o nome do item: ");
    scanf("%49s", novo->nomeItem);
    printf("Digite o peso do item: ");
    scanf("%d", &novo->peso);
    if (verificaEspaco(novo, mAtual)) {
        printf("Estourou o peso\n");
        return;
    };
    novo->proximo = NULL;
    novo->anterior = NULL;
    //se não exste um primeiro
    if(*cabeca == NULL){
        *cabeca = novo;
        mAtual->inicio = novo;
        printf("peso %d/%d \n", calculaPeso(*mAtual), mAtual->pesoMax);
        return;
    }
    //se é menor que o primeiro
    if(novo->peso < (*cabeca)->peso){
        novo->proximo = *cabeca;
        (*cabeca)->anterior= novo;
        *cabeca = novo;
        printf("Peso %d/%d \n", calculaPeso(*mAtual), mAtual->pesoMax);
        return;
    }
    Item* atual = *cabeca;
    //rodar até achar um maior que ele, ou o ultimo
    while(novo->peso >= atual->peso && atual->proximo != NULL){
        atual = atual->proximo;
    }

    if(novo->peso >= atual->peso){
        atual->proximo = novo;
        novo->anterior = atual;
        printf("Peso %d/%d \n", calculaPeso(*mAtual), mAtual->pesoMax);
        return;
    }
    novo->anterior = atual->anterior;
    novo->proximo = atual;
    atual->anterior->proximo = novo;
    atual->anterior = novo;
    printf("Peso %d/%d \n", calculaPeso(*mAtual), mAtual->pesoMax);

    return;
}



void listarItem(Item* cabeca){
    Item* atual = cabeca;
    while (atual != NULL){
        printf("%s: %d <-> ", atual->nomeItem, atual->peso);
        atual = atual->proximo;
    }
    printf("\n");
}
Mochila mochila;
Item* Objeto;
void main(){
    mochila.pesoMax = 100;
    mochila.pesoAtual = 0;
    mochila.inicio = NULL;
    mochila.fim = NULL;

    criarItem(&Objeto, &mochila);
    criarItem(&Objeto, &mochila);
    criarItem(&Objeto, &mochila);
    criarItem(&Objeto, &mochila);
    criarItem(&Objeto, &mochila);
    listarItem(Objeto);
    criarItem(&Objeto, &mochila);
    listarItem(Objeto);
}
