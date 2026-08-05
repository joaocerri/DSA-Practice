#include <stdio.h>
#include <stdlib.h>

typedef struct Conta{
    int Numero;
    double Saldo;
    struct Conta *prox;
}Conta;

Conta* criarConta(Conta *inicio, int numero, double saldo) {
    if(saldo <= 0 || numero <= 0){
        printf("\nO saldo e o numero para criar uma conta devem ser maior que ZERO!!");
        return NULL;
    }

    Conta *nova = (Conta*) malloc(sizeof(Conta));

    nova->Numero = numero;
    nova->Saldo = saldo;
    nova->prox = inicio;
    return nova;
}

void consultarContas(Conta *inicio){
    Conta *atual = inicio;
    while(atual != NULL){
        printf("\nConta %d - Saldo: R$ %.2f", atual->Numero, atual->Saldo);
        atual = atual->prox;
    }
}
void consultarSaldo(Conta *inicio, int numero) {
    Conta *atual = inicio;
    while (atual != NULL) {
        if (atual->Numero == numero) {
            printf("\nConta %d - Saldo: R$ %.2f", atual->Numero, atual->Saldo);
            return;
        }
        atual = atual->prox;
    }
    printf("\nA conta nao foi encontrada!!!");
}

void depositar(Conta *inicio, int numero, double valor){
    if(valor <= 0){
        printf("\nO valor de deposito deve ser maior que ZERO!!");
        return;
    }

    Conta *atual = inicio;
    while(atual != NULL){
        if(atual -> Numero == numero){
            atual -> Saldo += valor;
            return;
        }
        atual = atual -> prox;
    }
    printf("\nA conta nao foi encontrada!");
    return;
}

void sacar(Conta *inicio, int numero, double valor){
    Conta *atual = inicio;

    if(valor <= 0){
        printf("\nValor deve ser maior que zero!");
        return;
    }

    while(atual != NULL){
        if(atual -> Numero == numero){
            if(atual -> Saldo >= valor){
                atual -> Saldo -= valor;
                return;
            }
            else{
                 printf("\nValor deve ser maior que o saldo. Saldo atual: %.2f", atual->Saldo);
                 return;
            }
        }
        atual = atual -> prox;
    }
    printf("\nA conta nao foi encontrada!!");
    return;
}

Conta* removerConta(Conta *inicio, int numero) {
    Conta *atual = inicio, *anterior = NULL;

    while (atual != NULL && atual->Numero != numero) {
        anterior = atual;
        atual = atual->prox;
    }

    if(atual == NULL){
        printf("\nConta não encontrada!!");
        return inicio;
    }

    if(atual->Saldo != 0){
        printf("\nO saldo deve ser zero para excluir a conta! Saldo atual: %.2f", atual->Saldo);
        return inicio;
    }
    if (anterior == NULL) inicio = atual->prox;
    else anterior->prox = atual->prox;

    free(atual);
    printf("\nConta removida com sucesso!\n");
    return inicio;
}

int main() {
    Conta *minhaLista = NULL;

    minhaLista = criarConta(minhaLista, 101, 10.00);
    minhaLista = criarConta(minhaLista, 102, 1200.00);
    consultarContas(minhaLista);

    depositar(minhaLista, 101, 111.00);
    consultarSaldo(minhaLista, 101);
    minhaLista = removerConta(minhaLista, 101);

    consultarContas(minhaLista);
    sacar(minhaLista, 101, 121.00);
    consultarSaldo(minhaLista, 101);
    minhaLista = removerConta(minhaLista, 101);

    consultarSaldo(minhaLista, 101);

    return 0;
}
