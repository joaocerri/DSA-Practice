#include <stdio.h>
#include <stdlib.h>

typedef struct ContaBancaria{
    int numero;
    double saldo;
}ContaBancaria;

void depositarValor(double v, ContaBancaria* conta){
    conta -> saldo += v;
};

void sacarValor(double v, ContaBancaria* conta){
    conta -> saldo -= v;
};

void imprimirSaldo(ContaBancaria conta){
    printf("\nSaldo: %.2lf", c.saldo);
};

int main()
{
    ContaBancaria c1;
    c1.numero = 20;
    c1.saldo = 20000.0;

    imprimirSaldo(c1);
    sacarValor(10000, &c1);
    depositarValor(9000, &c1);
    imprimirSaldo(c1);

    return 0;
}