#include <stdio.h>
#include <stdlib.h>

typedef struct Conta{
    int Numero;
    double Saldo;
    struct Conta *prox;
}Conta;

Conta* criarConta(Conta *inicio, int numero, double saldo) {
    Conta *nova = (Conta*) malloc(sizeof(Conta));

    nova->Numero = numero;
    nova->Saldo = saldo;
    nova->prox = inicio;
    return nova;
}
void consultarSaldo(Conta *inicio, int numero) {
    Conta *atual = inicio;
    while (atual != NULL) {
        if (atual->Numero == numero) {
            printf("Conta %d | Saldo: R$ %.2f\n", atual->Numero, atual->Saldo);
            return;
        }
        atual = atual->prox;
    }
}

void despositar(Conta *inicio, int numero, double valor){
    Conta *atual = inicio;
    while(atual != NULL){
        if(atual -> Numero == numero){
            atual -> Saldo += valor;
            return;
        }
        atual = atual -> prox;
    }
}

void sacar(Conta *inicio, int numero, double valor){
    Conta *atual = inicio;

    if(valor <= 0){
        printf("Valor deve ser maior que zero!");
        return;
    }

    while(atual != NULL){
        if(atual -> Numero == numero){
            if(atual -> Saldo >= valor){
                atual -> Saldo -= valor;
                return;
            }
            else{
                 printf("Valor deve ser maior que o saldo. Saldo atual: %.2f", atual->Saldo);
                 return;
            }
        }
        atual = atual -> prox;
    }
}

Conta* removerConta(Conta *inicio, int numero) {
    Conta *atual = inicio, *anterior = NULL;

    while (atual->Numero != numero) {
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == NULL) inicio = atual->prox;
    else anterior->prox = atual->prox;

    free(atual);
    return inicio;
}

int main() {
    Conta *minhaLista = NULL;

    minhaLista = criarConta(minhaLista, 101, 500.00);
    minhaLista = criarConta(minhaLista, 102, 1200.00);

    consultarSaldo(minhaLista, 101);

    despositar(minhaLista, 101, 200.00);
    consultarSaldo(minhaLista, 101);

    sacar(minhaLista, 101, 100.00);
    consultarSaldo(minhaLista, 101);

    minhaLista = removerConta(minhaLista, 101);
    consultarSaldo(minhaLista, 101);

    return 0;
}